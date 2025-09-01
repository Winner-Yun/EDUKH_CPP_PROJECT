#ifndef ___INC_MANAGE_QUIZ_H___
#define ___INC_MANAGE_QUIZ_H___

#include "../Header_School/ANTHinsyOOP"
#include "QuizDesign.h"

using namespace ANTHinsyOOP;

QuizDesign quiz;

// One Question (page)
struct Question {
    char text[121];
    char answer1[81];        // Correct answer
    char answer2[81];        // Incorrect
    char answer3[81];        // Incorrect
    char answer4[81];        // Incorrect
    char correctAnswer[81];  // Always stores the correct one
    char score[4];           // Score for this question
    char timeQuiz[4];        // Time for this question (minutes)
};

class Quiz {
    private:
        char teacherID[20];
        char teacherName[25];     // From AssignClass
        char subject[20];         // From AssignClass
        char quizID[2];           // Quiz 1, 2, 3
        char className[3];        // From AssignClass (10,11,12)
        char deadline[11];        // due date
        char lastUpdateDate[11];  // last modified date 10/10/1010
        char publish[2];
        Question questions[10];   // fixed 10 pages

    public:
        static void CreateQuiz(const char* teacherID, const char* className, const char* quizID, const char* subject);
        static void UpdateQuiz(const char* teacherID, const char* className, const char* quizID);
        static void PublishQuiz(const char* teacherID, const char* className, const char* quizID);
        static void ReadQuiz(const char* teacherID, const char* className, const char* quizID);
        static const char* getFileName(const char* className);
        static bool isPublished(const char* teacherID, const char* className, const char* quizID);
        bool isComplete() const;

        // Getters
        const char* getClassName() const { return className; }
        const char* getSubject() const { return subject; }
        const char* getPublish() const { return publish; }
        const char* getQuizID() const { return quizID; }
        const char* getDeadline() const { return deadline; }
        const char* getlastUpdateDate() const { return lastUpdateDate; }

        // file I/O
        void saveToFile(ofstream& out) const {
            out.write((char*)this, sizeof(Quiz));
        }
        void loadFromFile(ifstream& in) {
            in.read((char*)this, sizeof(Quiz));
        }

        // getter (for student side)
        const Question& getQuestion(int i) const {
            return questions[i];
        }

        int getQuestionCount() const {
            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (strlen(questions[i].text) > 0) {
                    count++;
                }
            }
            return count;
        }
};

bool Quiz::isComplete() const {
    for (int i = 0; i < 10; i++) {
        if (strlen(questions[i].text) == 0) return false;
        if (strlen(questions[i].answer1) == 0) return false;
        if (strlen(questions[i].answer2) == 0) return false;
        if (strlen(questions[i].answer3) == 0) return false;
        if (strlen(questions[i].answer4) == 0) return false;
    }
    return true;
}

bool Quiz::isPublished(const char* teacherID, const char* className, const char* quizID) {
    const char* filename = getFileName(className);
    if (!filename) return false;

    ifstream in(filename, ios::binary);
    if (!in) return false;

    Quiz q;
    while (in.read((char*)&q, sizeof(Quiz))) {
        if (strcmp(q.teacherID, teacherID) == 0 && strcmp(q.quizID, quizID) == 0) {
            return strcmp(q.publish, "1") == 0; // "1" = published
        }
    }
    return false;
}

// ===================== Helper =====================
const char* Quiz::getFileName(const char* className) {
    if (strcmp(className, "10") == 0) return "../data/QuizGrade10.bin";
    if (strcmp(className, "11") == 0) return "../data/QuizGrade11.bin";
    if (strcmp(className, "12") == 0) return "../data/QuizGrade12.bin";
    return nullptr;
}

string getTodayDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char buffer[11]; // dd/mm/yyyy = 10 + '\0'
    sprintf(buffer, "%02d/%02d/%04d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);

    return string(buffer);
}

Quiz q;

// ===================== CREATE / RESUME WITH PAGE-LEVEL SCORE/TIME =====================
void Quiz::CreateQuiz(const char* teacherID, const char* className, const char* quizID, const char* subject) {
    if (Quiz::isPublished(teacherID, className, quizID)) {
        CustomMessageBox(80, 20, 60, "ALERT", "Cannot edit a published quiz!", ICON_WARNING);
        return;
    }

    const char* filename = getFileName(className);
    if (!filename) {
        H::setcolor(7); H::gotoxy(40, 43); cout << "Invalid class name.";
        return;
    }

    bool partialFound = false;
    vector<Quiz> quizzes;

    // Load existing quizzes
    ifstream in(filename, ios::binary);
    while (in.read((char*)&q, sizeof(Quiz))) {
        quizzes.push_back(q);
    }
    in.close();

    // Check if this quizID exists
    int quizIndex = -1;
    for (int i = 0; i < quizzes.size(); i++) {
        if (strcmp(quizzes[i].teacherID, teacherID) == 0 && strcmp(quizzes[i].quizID, quizID) == 0) {
            partialFound = true;
            quizIndex = i;
            q = quizzes[i]; // load existing quiz
            break;
        }
    }

    if (!partialFound) {
        strcpy(q.teacherID, teacherID);
        strcpy(q.className, className);
        strcpy(q.quizID, quizID);
        strcpy(q.publish, "2");
        strcpy(q.subject, subject);

        // Initialize all questions as empty
        for (int i = 0; i < 10; i++) {
            q.questions[i].text[0] = '\0';
            q.questions[i].answer1[0] = '\0';
            q.questions[i].answer2[0] = '\0';
            q.questions[i].answer3[0] = '\0';
            q.questions[i].answer4[0] = '\0';
            q.questions[i].correctAnswer[0] = '\0';
            q.questions[i].score[0] = '\0';  
            q.questions[i].timeQuiz[0] = '\0'; 
        }
    }

    // Resume from next empty page
    int page = 0;
    for (; page < 10; page++) {
        if (strlen(q.questions[page].text) == 0) break; // empty page
    }

    // Check if all 10 questions are already filled
    if (page == 10) {
        int overwriteChoice = MessageBoxA(
            GetConsoleWindow(), "All 10 questions already exist. Do you want to Re-Create and start over?", "Re-Create Quiz?", MB_YESNO | MB_ICONQUESTION
        );
        if (overwriteChoice == IDYES) {
            for (int i = 0; i < 10; i++) {
                q.questions[i].text[0] = '\0';
                q.questions[i].answer1[0] = '\0';
                q.questions[i].answer2[0] = '\0';
                q.questions[i].answer3[0] = '\0';
                q.questions[i].answer4[0] = '\0';
                q.questions[i].correctAnswer[0] = '\0';
                q.questions[i].score[0] = '\0';  
                q.questions[i].timeQuiz[0] = '\0';
            }
            q.deadline[0] = '\0';
            page = 0;
        }
    }

    char choice;
    string today = getTodayDate();
    strcpy(q.lastUpdateDate, today.c_str());

    bool deadlineSet = (strlen(q.deadline) > 0);

    while (page < 10) {
        system("cls");
        QuizDesign::DesginQuizPage(className, quizID);
        H::setcursor(true, 1);
        H::setcolor(7); H::gotoxy(165, 12); cout << "10";
        H::setcolor(7); H::gotoxy(165, 14); cout << "60";
        H::setcolor(7); H::gotoxy(171, 22); cout << q.lastUpdateDate;
        H::setcolor(7); H::gotoxy(171, 24); cout << q.deadline;

        H::setcolor(7); H::gotoxy(173, 9); cout << setw(2) << setfill('0') << (page + 1) << " / 10";

        // Input page-level score and time
        strcpy(q.questions[page].score, "10");
        strcpy(q.questions[page].timeQuiz, "60");

        if (!deadlineSet) {
            H::setcolor(7); H::gotoxy(171, 24); H::inputDate(q.deadline, true);
            deadlineSet = true;
        } else {
            H::setcolor(7); H::gotoxy(171, 24); cout << q.deadline;
        }

        H::setcolor(7); H::gotoxy(20, 11); H::inputAll(q.questions[page].text, 121);

        H::setcolor(7); H::gotoxy(40, 17); H::inputAll(q.questions[page].answer1, 81);

        H::setcolor(7); H::gotoxy(40, 23); H::inputAll(q.questions[page].answer2, 81);

        H::setcolor(7); H::gotoxy(40, 29); H::inputAll(q.questions[page].answer3, 81);

        H::setcolor(7); H::gotoxy(40, 35); H::inputAll(q.questions[page].answer4, 81);

        strcpy(q.questions[page].correctAnswer, q.questions[page].answer1);

        // Save after each page to prevent data loss
        if (partialFound) {
            quizzes[quizIndex] = q; // update existing quiz
        } else {
            quizzes.push_back(q);
            partialFound = true;
            quizIndex = quizzes.size() - 1;
        }

        ofstream out(filename, ios::binary | ios::trunc);
        for (auto &quizItem : quizzes) {
            out.write((char*)&quizItem, sizeof(Quiz));
        }
        out.close();

        page++;
        if (page < 10) {
            H::setcursor(false, 0);
            H::setcolor(7); 
            H::gotoxy(55, 42);
            cout << "PRESS "; H::setcolor(167); cout << "[ ENTER / Y ]"; H::setcolor(7); cout << " TO INPUT NEXT PAGE    |    PRESS "; H::setcolor(199); cout << "[ ESC / N ]";
            H::setcolor(7);
            bool waiting = true;
            while (waiting) {
                int key = _getch(); // get key press without Enter
                if (key == 13 || key == 'Y' || key == 'y') { // Enter or Y/y
                    waiting = false; // continue to next page
                } else if (key == 27 || key == 'N' || key == 'n') { // ESC or N/n
                    H::setcursor(false, 0); 
                    H::setcolor(7); H::gotoxy(40, 43); cout << "Progress saved! You can resume later.";
                    return; // exit function
                }
                // any other key is ignored
            }
        }

    }

    H::setcolor(7); H::gotoxy(10, 43); cout << "Quiz completed successfully for Class " << q.className << " (" << q.quizID << ") on " << q.lastUpdateDate;
}
// MessageBoxA( NULL, "You have not yet created the quiz!", "Error", MB_OK | MB_ICONERROR);
// ===================== UPDATE =====================
void Quiz::UpdateQuiz(const char* teacherID, const char* className, const char* quizID) {
    if (Quiz::isPublished(teacherID, className, quizID)) {
        CustomMessageBox(80, 20, 60, "ALERT", "Cannot edit a published quiz!", ICON_WARNING);
        return;
    }
    const char* filename = getFileName(className);
    if (!filename) return;

    ifstream in(filename, ios::binary);
    if (!in) {
        MessageBoxA(GetConsoleWindow(), "No quiz file found for this class!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    vector<Quiz> quizzes;
    Quiz q;
    while (in.read((char*)&q, sizeof(Quiz))) quizzes.push_back(q);
    in.close();

    int quizIndex = -1;
    for (int i = 0; i < quizzes.size(); i++) {
        if (strcmp(quizzes[i].teacherID, teacherID) == 0 && strcmp(quizzes[i].quizID, quizID) == 0) {
            quizIndex = i;
            q = quizzes[i];
            break;
        }
    }

    if (quizIndex == -1) {
        CustomMessageBox(80, 20, 60, "ALERT", "You have not yet created the quiz!", ICON_WARNING);
        return;
    }

    int page = 0;
    bool deadlineShown = false;
    H::cls();
    QuizDesign::DesginQuizPage(className, quizID);
    H::setcursor(false, 0);
    while (true) {
        H::setcursor(false, 0);
        // Show last update and deadline
        H::setcolor(7); H::gotoxy(171, 22); cout << q.lastUpdateDate;
        H::setcolor(7); H::gotoxy(171, 24); cout << q.deadline;

        H::setcolor(7); H::gotoxy(173, 9); cout << setw(2) << setfill('0') << (page + 1) << " / 10";

        // Show existing page data
        H::setcolor(7); H::gotoxy(165, 12); cout << "    ";
        H::setcolor(7); H::gotoxy(165, 12); cout << q.questions[page].score;
        H::setcolor(7); H::gotoxy(165, 14); cout << "     ";
        H::setcolor(7); H::gotoxy(165, 14); cout << q.questions[page].timeQuiz;
        H::setcolor(7); H::gotoxy(20, 11); cout << "                                                                                                                        ";
        H::setcolor(7); H::gotoxy(20, 11); cout << q.questions[page].text;
        H::setcolor(7); H::gotoxy(40, 17); cout << "                                                                                ";
        H::setcolor(7); H::gotoxy(40, 17); cout << q.questions[page].answer1;
        H::setcolor(7); H::gotoxy(40, 23); cout << "                                                                                ";
        H::setcolor(7); H::gotoxy(40, 23); cout << q.questions[page].answer2;
        H::setcolor(7); H::gotoxy(40, 29); cout << "                                                                                ";
        H::setcolor(7); H::gotoxy(40, 29); cout << q.questions[page].answer3;
        H::setcolor(7); H::gotoxy(40, 35); cout << "                                                                                ";
        H::setcolor(7); H::gotoxy(40, 35); cout << q.questions[page].answer4;

        H::setcolor(7); H::gotoxy(30, 42); cout << "PRESS "; H::setcolor(151); cout << "[Left]"; H::setcolor(7); cout << " | "; H::setcolor(151); cout << "[Right]"; H::setcolor(7); cout << " TO MOVE,      "; H::setcolor(167); cout << "[ENTER]"; H::setcolor(7); cout << " TO UPDATE PAGE,      "; H::setcolor(103); cout << "[D]"; H::setcolor(7); cout << " TO CHANGE DEADLINE,      "; H::setcolor(199); cout << "[ESC]"; H::setcolor(7); cout << " TO EXIT";

        int ch = getch();

        if (ch == 224) {  // arrow key
            ch = getch(); // get actual arrow code
            if (ch == 75 && page > 0) page--;   // left arrow
            else if (ch == 77 && page < 9) page++; // right arrow
        }
        else if (ch == 'D' || ch == 'd') { // 🔹 Update deadline
            H::setcursor(true, 1);
            H::setcolor(7); H::gotoxy(171, 24); cout << "          ";
            H::setcolor(7); H::gotoxy(171, 24); H::inputDate(q.deadline, true);

            // Save immediately
            quizzes[quizIndex] = q;
            ofstream out(filename, ios::binary | ios::trunc);
            for (auto &quizItem : quizzes) out.write((char*)&quizItem, sizeof(Quiz));
            out.close();

            MessageBoxA(GetConsoleWindow(), "Deadline updated successfully!", "Info", MB_OK | MB_ICONINFORMATION);
            QuizDesign::DesginQuizPage(className, quizID);
        }
        else if (ch == 13) { // ENTER to edit page
            H::setcursor(true, 1);
            strcpy(q.questions[page].score, "10");
            strcpy(q.questions[page].timeQuiz, "60");

            H::setcolor(7); H::gotoxy(20, 11); cout << "                                                                                                                        ";
            H::setcolor(7); H::gotoxy(20, 11); H::inputAll(q.questions[page].text, 121);

            H::setcolor(7); H::gotoxy(40, 17); cout << "                                                                                ";
            H::setcolor(7); H::gotoxy(40, 17); H::inputAll(q.questions[page].answer1, 81);

            H::setcolor(7); H::gotoxy(40, 23); cout << "                                                                                ";
            H::setcolor(7); H::gotoxy(40, 23); H::inputAll(q.questions[page].answer2, 81);

            H::setcolor(7); H::gotoxy(40, 29); cout << "                                                                                ";
            H::setcolor(7); H::gotoxy(40, 29); H::inputAll(q.questions[page].answer3, 81);

            H::setcolor(7); H::gotoxy(40, 35); cout << "                                                                                ";
            H::setcolor(7); H::gotoxy(40, 35); H::inputAll(q.questions[page].answer4, 81);
            H::setcursor(false, 0);
            strcpy(q.questions[page].correctAnswer, q.questions[page].answer1);

            // Save immediately
            quizzes[quizIndex] = q;
            ofstream out(filename, ios::binary | ios::trunc);
            for (auto &quizItem : quizzes) out.write((char*)&quizItem, sizeof(Quiz));
            out.close();
            
            const int CONSOLE_W = 200;
            const int FINAL_X   = 170;   // where the box ends up
            const int Y         = 37;
            const int HGT       = 1;
            const int FINAL_W   = 30;
            const int BOX_COLOR = 247;
            const int TEXT_Y    = 38;
            const int TEXT_COLOR= 250;

            const char* msg = "UPDATED SUCCESSFULLY";
            int msgLen = (int)strlen(msg);

            for (int w = 1; w <= FINAL_W; ++w) {
                int x = CONSOLE_W - w; // 199 → 170

                // draw growing box: (199,1)->(198,2)->…->(170,30)
                H::drawBoxSingleLineWithBG(x, Y, w, HGT, BOX_COLOR);

                // clear the text strip under the box so old chars don't linger
                H::setcolor(TEXT_COLOR);
                H::gotoxy(FINAL_X, TEXT_Y);
                cout << string(FINAL_W + 1, ' '); // clear cols 170..200

                // show message inside as space appears (5-char left padding)
                int cap = w - 5;                  // how many message chars fit now
                if (cap > 0) {
                    if (cap > msgLen) cap = msgLen;
                    int startX = x + 5;           // text starts 5 cols inside the box

                    // never write past the right edge (col 200)
                    if (startX + cap - 1 > CONSOLE_W) cap = CONSOLE_W - startX + 1;

                    if (cap > 0) {
                        H::gotoxy(startX, TEXT_Y);
                        cout.write(msg, cap);     // prints "U", then "UP", … progressively
                    }
                }
                Sleep(12); // animation speed
            }

            // final stable frame
            H::drawBoxSingleLineWithBG(FINAL_X, Y, FINAL_W, HGT, BOX_COLOR);
            H::setcolor(TEXT_COLOR);
            H::gotoxy(FINAL_X + 5, TEXT_Y);
            cout << msg;
            
            H::setcolor(7);

            // Final stable message
            H::drawBoxSingleLineWithBG(170, 37, 30, 1, 247);
            H::setcolor(250); 
            H::gotoxy(175, 38); 
            cout << msg;
            getch();
            H::setcolor(7);
            system("cls");
            QuizDesign::DesginQuizPage(className, quizID);
        }
        else if (ch == 27) { // ESC to exit
            break;
        }
    }
}

// ===================== SUBMIT QUIZ =====================
void Quiz::PublishQuiz(const char* teacherID, const char* className, const char* quizID) {
    const char* filename = getFileName(className);
    if (!filename) return;

    ifstream in(filename, ios::binary);
    if (!in) {
        MessageBoxA(GetConsoleWindow(), "No quiz file found!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    vector<Quiz> quizzes;
    Quiz q;
    while (in.read((char*)&q, sizeof(Quiz))) quizzes.push_back(q);
    in.close();

    int quizIndex = -1;
    for (int i = 0; i < quizzes.size(); i++) {
        if (strcmp(quizzes[i].teacherID, teacherID) == 0 && strcmp(quizzes[i].quizID, quizID) == 0) {
            quizIndex = i;
            q = quizzes[i];
            break;
        }
    }

    if (quizIndex == -1) {
        CustomMessageBox(80, 18, 60, "ALERT", "You have not yet created the quiz!", ICON_WARNING);
        return;
    }
    // Toggle publish/unpublish
    if (strcmp(q.publish, "1") == 0) {
    // Published → unpublish
        strcpy(q.publish, "0");
        CustomMessageBox(80, 20, 60, "UNPUBLISED", "Quiz unpublished successfully!", ICON_INFO);
    } else {
        if (!q.isComplete()) {
            CustomMessageBox(80, 20, 60, "ALERT", "Cannot publish! All 10 pages must be fully created.", ICON_WARNING);
            return;
        }
        strcpy(q.publish, "1"); // published
        CustomMessageBox(80, 20, 60, "PUBLISED", "Quiz published successfully!", ICON_INFO);
    }

    quizzes[quizIndex] = q;
    ofstream out(filename, ios::binary | ios::trunc);
    for (auto &quizItem : quizzes) out.write((char*)&quizItem, sizeof(Quiz));
    out.close();
}

#endif