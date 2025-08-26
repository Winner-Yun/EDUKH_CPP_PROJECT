#ifndef  __DO_QUIZ_H__
#define  __DO_QUIZ_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_Teacher/ManageQuiz.h"
#include "../Header_Teacher/HeaderOFManageScore.h"

#include <random>

using namespace ANTHinsyOOP;

class DoQuiz{
    public:
        static void MenuBySubject(const char* studentID, const char* grade);
        static void ViewHomeMain(const char* studentID, const char* grade);
        static void MenuByQuiz(const char* studentID, const char* className, const char* subject);
        static void StartQuiz(const char* studentID, const char* className, const char* subject, size_t quizIndex);
        static void MenuGradeDesignDesign();
        static void MenuQuizDesignDesign();
};

struct StudentQuizResult {
    char studentID[20];
    char className[20];
    char subject[30];
    char quizID[20];
    int totalScore;
};

bool isDeadlinePassed(const char* deadline) {
    int d, m, y;
    if (sscanf(deadline, "%d/%d/%d", &d, &m, &y) != 3) return false;

    // Get current date
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currDay = ltm->tm_mday;
    int currMonth = ltm->tm_mon + 1;
    int currYear = 1900 + ltm->tm_year;

    if (currYear > y) return true;
    if (currYear < y) return false;

    if (currMonth > m) return true;
    if (currMonth < m) return false;

    return currDay > d;
}

DoQuiz doQ;

void DoQuiz::MenuBySubject(const char* studentID, const char* grade){
    ViewHomeMain(studentID, grade);
}

void DoQuiz::ViewHomeMain(const char* studentID, const char* grade) {
    const int consoleWidth = 202;
    const int consoleHeight = 45;
    H::cls();

    // Use your helper to get the correct file name
    const char* filename = Quiz::getFileName(grade);
    if (!filename) {
        MessageBoxA(NULL, "Invalid class/grade!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(consoleWidth / 2 - 5, consoleHeight / 2);
        MessageBoxA(NULL, "No quiz file found for this grade", "File Error", MB_OK | MB_ICONERROR);
        return;
    }

    vector<string> subjects;
    Quiz q;

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&q), sizeof(Quiz))) {
        if (strcmp(q.getClassName(), grade) == 0 && strcmp(q.getPublish(), "1") == 0) { 
            if (find(subjects.begin(), subjects.end(), string(q.getSubject())) == subjects.end()) {
                subjects.push_back(string(q.getSubject()));
            }
            found = true;
        }
    }
    inFile.close();

    if (!found || subjects.empty()) {
        H::setcolor(14);
        H::gotoxy(consoleWidth / 2 - 10, consoleHeight / 2);
        MessageBoxA(NULL, "NO QUIZ AVAILABLE!", "Notice", MB_OK | MB_ICONASTERISK);
        return;
    }

    subjects.push_back("<| BACK");

    int boxWidth = 30, boxHeight = 3;
    int normalColor = 3, highlightColor = 31;

    int cols = 1, rows = subjects.size();
    if (subjects.size() > 4) {
        cols = 2;
        rows = (subjects.size() + 1) / 2;
        if (rows > 4) rows = 4;
    }

    int gridWidth = cols * (boxWidth + 4);
    int gridHeight = rows * (boxHeight + 4);
    int startX = (consoleWidth - gridWidth) / 2;
    int startY = (consoleHeight - gridHeight) / 2;

    int currentSelection = 0;
    bool running = true;
    MenuGradeDesignDesign();

    while (running) {
        for (size_t i = 0; i < subjects.size(); ++i) {
            int row = i / cols;
            int col = i % cols;
            int xBox = startX + col * (boxWidth + 4);
            int yBox = startY + row * (boxHeight + 4);

            string label = (subjects[i] == "<| BACK") ? subjects[i] : "SUBJECT: " + subjects[i];
            int textX = xBox + (boxWidth - static_cast<int>(label.size())) / 2;

            int color = (i == currentSelection) ? highlightColor : normalColor;
            if (subjects[i] == "<| BACK") color = (i == currentSelection) ? 79 : 4;

            H::clearBox(xBox, yBox, boxWidth, boxHeight, 7);
            H::drawBoxSingleLineWithBG(xBox, yBox, boxWidth, boxHeight, color);
            H::setcolor(color);

            H::gotoxy(textX, yBox + boxHeight / 2 + 1);
            cout << label;
        }

        int key = _getch();
        if (key == 224) { 
            key = _getch();
            if (key == 72) currentSelection = (currentSelection - cols + subjects.size()) % subjects.size();
            else if (key == 80) currentSelection = (currentSelection + cols) % subjects.size();
            else if (key == 75 && cols > 1) currentSelection = (currentSelection - 1 + subjects.size()) % subjects.size();
            else if (key == 77 && cols > 1) currentSelection = (currentSelection + 1) % subjects.size();
        } else if (key == 13) { // Enter
            if (subjects[currentSelection] == "<| BACK"){
                H::setcolor(7);
                running = false;
            } 
            else {
                system("cls");
                // Call your Quiz detail/view function here
                MenuByQuiz(studentID, grade, subjects[currentSelection].c_str());
                H::cls();
                running = false;
                ViewHomeMain(studentID, grade);
            }
        } else if (key == 27) running = false; // ESC
    }
}

void DoQuiz::MenuByQuiz(const char* studentID, const char* className, const char* subject) {
    const int consoleWidth = 202;
    const int consoleHeight = 45;
    H::cls();

    const char* filename = Quiz::getFileName(className);
    if (!filename) {
        MessageBoxA(NULL, "Invalid class/grade!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Quiz file not found", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    vector<Quiz> quizzes;
    Quiz q;

    while (inFile.read(reinterpret_cast<char*>(&q), sizeof(Quiz))) {
        if (strcmp(q.getClassName(), className) == 0 && strcmp(q.getSubject(), subject) == 0 && strcmp(q.getPublish(), "1") == 0) 
        {
            quizzes.push_back(q);
        }
    }
    inFile.close();

    if (quizzes.empty()) {
        MessageBoxA(NULL, "No quizzes found for this subject!", "Notice", MB_OK | MB_ICONASTERISK);
        return;
    }

    // Prepare quiz menu
    vector<string> quizMenu;
    for (size_t i = 0; i < quizzes.size(); i++) {
        quizMenu.push_back("QUIZ " + to_string(i + 1));
    }
    quizMenu.push_back("<| BACK");

    int boxWidth = 30, boxHeight = 3;
    int normalColor = 3, highlightColor = 31;

    int cols = 1, rows = quizMenu.size();
    if (quizMenu.size() > 6) {
        cols = 2;
        rows = (quizMenu.size() + 1) / 2;
        if (rows > 6) rows = 6;
    }

    int gridWidth = cols * (boxWidth + 4);
    int gridHeight = rows * (boxHeight + 4);
    int startX = (consoleWidth - gridWidth) / 2;
    int startY = (consoleHeight - gridHeight) / 2;

    int currentSelection = 0;
    bool running = true;
    MenuQuizDesignDesign();

    while (running) {
        for (size_t i = 0; i < quizMenu.size(); ++i) {
            int row = i / cols;
            int col = i % cols;
            int xBox = startX + col * (boxWidth + 4);
            int yBox = startY + row * (boxHeight + 4);

            int color = (i == currentSelection) ? highlightColor : normalColor;
            if (quizMenu[i] == "<| BACK") color = (i == currentSelection) ? 79 : 4;

            H::clearBox(xBox, yBox, boxWidth, boxHeight, 7);
            H::drawBoxSingleLineWithBG(xBox, yBox, boxWidth, boxHeight, color);
            H::setcolor(color);

            int textX = xBox + (boxWidth - static_cast<int>(quizMenu[i].size())) / 2;
            H::gotoxy(textX, yBox + boxHeight / 2 + 1);
            cout << quizMenu[i];
        }

        int key = _getch();
        if (key == 224) { 
            key = _getch();
            if (key == 72) currentSelection = (currentSelection - cols + quizMenu.size()) % quizMenu.size();
            else if (key == 80) currentSelection = (currentSelection + cols) % quizMenu.size();
            else if (key == 75 && cols > 1) currentSelection = (currentSelection - 1 + quizMenu.size()) % quizMenu.size();
            else if (key == 77 && cols > 1) currentSelection = (currentSelection + 1) % quizMenu.size();
        } else if (key == 13) { // Enter
            if (quizMenu[currentSelection] == "<| BACK") {
                H::setcolor(7);
                running = false; // go back to subject menu
            } else {
                size_t quizIndex = currentSelection;
                system("cls");
                doQ.StartQuiz(studentID, className, subject, quizIndex);
                H::cls();
                running = false;
                MenuByQuiz(studentID, className, subject);
            }
        } else if (key == 27) running = false; // ESC
    }
}

#include <algorithm>
#include <random>

void DoQuiz::StartQuiz(const char* studentID, const char* className, const char* subject, size_t quizIndex) {
    const char* filename = Quiz::getFileName(className);
    if (!filename) {
        MessageBoxA(NULL, "Invalid class/grade!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Quiz file not found", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    vector<Quiz> quizzes;
    Quiz q;
    while (inFile.read((char*)&q, sizeof(Quiz))) {
        if (strcmp(q.getClassName(), className) == 0 && strcmp(q.getSubject(), subject) == 0 && strcmp(q.getPublish(), "1") == 0) 
        {
            quizzes.push_back(q);
        }
    }
    inFile.close();

    if (quizzes.empty()) {
        MessageBoxA(NULL, "No published quiz found for this subject!", "Notice", MB_OK | MB_ICONASTERISK);
        return;
    }

    if (quizIndex >= quizzes.size()) return;
    q = quizzes[quizIndex];

    if (isDeadlinePassed(q.getDeadline())) {
        MessageBoxA(NULL, "This quiz is past the deadline and cannot be taken.", "Deadline Passed", MB_OK | MB_ICONWARNING);
        return;
    }

    // --- Check if student already completed this quiz ---
    ifstream resultFile("../data/StudentQuizResults.dat", ios::binary);
    if (resultFile) {
        StudentQuizResult existing;
        while (resultFile.read((char*)&existing, sizeof(existing))) {
            if (strcmp(existing.studentID, studentID) == 0 && strcmp(existing.quizID, q.getQuizID()) == 0) 
            {
                MessageBoxA(NULL, "You have already completed this quiz!", "Notice", MB_OK | MB_ICONINFORMATION);
                resultFile.close();
                return; // prevent retake
            }
        }
        resultFile.close();
    }

    int totalQuestions = q.getQuestionCount();
    if (totalQuestions == 0) {
        MessageBoxA(NULL, "Quiz has no questions!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    // Randomize question order
    vector<int> questionOrder(totalQuestions);
    for (int i = 0; i < totalQuestions; i++) questionOrder[i] = i;
    random_device rd;
    mt19937 g(rd());
    shuffle(questionOrder.begin(), questionOrder.end(), g);

    int totalScore = 0;

    for (int i = 0; i < totalQuestions; i++) {
        int idx = questionOrder[i];
        const Question& ques = q.getQuestion(idx);

        vector<string> answers = { ques.answer1, ques.answer2, ques.answer3, ques.answer4 };
        string correct = ques.correctAnswer;
        shuffle(answers.begin(), answers.end(), g);

        int correctIndex = -1;
        for (int j = 0; j < 4; j++) {
            if (answers[j] == correct) {
                correctIndex = j;
                break;
            }
        }

        int option;
        int choice = 1; // start at first answer
        QuizDesign::DesginDoQuizPage(className, q.getQuizID());
        H::setcolor(7); H::gotoxy(171, 22); cout << q.getlastUpdateDate();
        H::setcolor(7); H::gotoxy(165, 12); cout << "10";
        H::setcolor(7); H::gotoxy(165, 14); cout << "60";
        H::setcolor(7); H::gotoxy(171, 24); cout << q.getDeadline();
        H::setcolor(7); H::gotoxy(50, 42); cout << "PRESS "; H::setcolor(151); cout << "[Left]"; H::setcolor(7); cout << " | "; H::setcolor(151); cout << "[Right]"; H::setcolor(7); cout << " TO MOVE, PRESS "; H::setcolor(167); cout << "[ENTER]"; H::setcolor(7); cout << " TO CHOOSE THE ANSWER";

        do {
            H::setcolor(7); H::gotoxy(173, 9); cout << setw(2) << setfill('0') << (i + 1) << " / " << totalQuestions;
            H::setcolor(7); H::gotoxy(20, 11); cout << ques.text;

            // Draw answer boxes and highlight current choice
            for (int j = 1; j <= 4; j++) {
                int y = 15 + (j-1)*6;
                H::drawBoxSingleLineWithBG(38, y, 84, 3, 7); // normal box
                if (choice == j) {
                    H::drawBoxSingleLine(38, y, 84, 3, 2); // highlighted border
                } else {
                    H::drawBoxSingleLine(38, y, 84, 3, 1); // normal border
                }
                H::setcolor(7);
                H::gotoxy(40, y + 2);
                cout << answers[j-1];
            }

            option = _getch();
            choice = EdumasterCustom::ArrowKeyConTrol(4, 1, choice, option);

        } while (option != 13 && option != 27); // Enter or ESC

        if (option == 13) {
            // Check if the chosen answer is correct
            if (choice-1 == correctIndex) {
                totalScore += atoi(ques.score);
                H::setcolor(7); H::gotoxy(50, 42); cout << "                                                                                  ";
                H::setcolor(7); H::gotoxy(65, 42);
                H::setcolor(39);
                cout << "Correct! +" << ques.score << " points\n";
            } else {
                H::setcolor(7); H::gotoxy(50, 42); cout << "                                                                                  ";
                H::setcolor(7); H::gotoxy(56, 42);
                H::setcolor(4);
                cout << "Wrong! No points.    "; H::setcolor(39); cout << " Correct answer: " << ques.correctAnswer;
            }
            H::setcolor(7);
            H::delay(1000);
            H::cls();
        }
    }

    // Store the result once all questions are done
    StudentQuizResult result;
    strcpy(result.studentID, studentID);
    strcpy(result.className, className);
    strcpy(result.subject, subject);
    strcpy(result.quizID, q.getQuizID());
    result.totalScore = totalScore;

    H::cls();
    system("chcp 65001 > nul");
	H::setcolor(2); H::gotoxy(44, 10); cout << R"( ██████╗ ██╗   ██╗██╗███████╗    ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗     ███████╗████████╗███████╗██████╗   ██╗)";
	H::setcolor(2); H::gotoxy(44, 11); cout << R"(██╔═══██╗██║   ██║██║╚══███╔╝   ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║     ██╔════╝╚══██╔══╝██╔════╝██╔══██╗  ██║)";
	H::setcolor(2); H::gotoxy(44, 12); cout << R"(██║   ██║██║   ██║██║  ███╔╝    ██║     ██║   ██║██╔████╔██║██████╔╝██║     █████╗     ██║   █████╗  ██║  ██║  ██║)";
	H::setcolor(2); H::gotoxy(44, 13); cout << R"(██║▄▄ ██║██║   ██║██║ ███╔╝     ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝     ██║   ██╔══╝  ██║  ██║  ╚═╝)";
	H::setcolor(2); H::gotoxy(44, 14); cout << R"(╚██████╔╝╚██████╔╝██║███████╗   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ███████╗███████╗   ██║   ███████╗██████╔╝  ██╗)";
	H::setcolor(2); H::gotoxy(44, 15); cout << R"( ╚══▀▀═╝  ╚═════╝ ╚═╝╚══════╝    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═════╝   ╚═╝)";
	system("chcp 437 >nul");
    if (totalScore >= 100) {
        system("chcp 65001 > nul");
        H::setcolor(2); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗              ██╗ ██████╗  ██████╗ )";
        H::setcolor(2); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ███║██╔═████╗██╔═████╗)";
        H::setcolor(2); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ╚██║██║██╔██║██║██╔██║)";
        H::setcolor(2); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗      ██║████╔╝██║████╔╝██║)";
        H::setcolor(2); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝      ██║╚██████╔╝╚██████╔╝)";
        H::setcolor(2); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝              ╚═╝ ╚═════╝  ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 90) {
        system("chcp 65001 > nul");
        H::setcolor(2); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗              █████╗  ██████╗ )";
        H::setcolor(2); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ██╔══██╗██╔═████╗)";
        H::setcolor(2); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ╚██████║██║██╔██║)";
        H::setcolor(2); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗      ╚═══██║████╔╝██║)";
        H::setcolor(2); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝      █████╔╝╚██████╔╝)";
        H::setcolor(2); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝              ╚════╝  ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 80) {
        system("chcp 65001 > nul");
        H::setcolor(2); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗              █████╗  ██████╗ )";
        H::setcolor(2); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ██╔══██╗██╔═████╗)";
        H::setcolor(2); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ╚█████╔╝██║██╔██║)";
        H::setcolor(2); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗     ██╔══██╗████╔╝██║)";
        H::setcolor(2); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝     ╚█████╔╝╚██████╔╝)";
        H::setcolor(2); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝              ╚════╝  ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 70) {
        system("chcp 65001 > nul");
        H::setcolor(2); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗             ███████╗ ██████╗ )";
        H::setcolor(2); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ╚════██║██╔═████╗)";
        H::setcolor(2); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝         ██╔╝██║██╔██║)";
        H::setcolor(2); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗        ██╔╝ ████╔╝██║)";
        H::setcolor(2); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝        ██║  ╚██████╔╝)";
        H::setcolor(2); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝                ╚═╝   ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 60) {
        system("chcp 65001 > nul");
        H::setcolor(6); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗              ██████╗  ██████╗ )";
        H::setcolor(6); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ██╔════╝ ██╔═████╗)";
        H::setcolor(6); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ███████╗ ██║██╔██║)";
        H::setcolor(6); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗     ██╔═══██╗████╔╝██║)";
        H::setcolor(6); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝     ╚██████╔╝╚██████╔╝)";
        H::setcolor(6); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝              ╚═════╝  ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 50) {
        system("chcp 65001 > nul");
        H::setcolor(6); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗             ███████╗ ██████╗ )";
        H::setcolor(6); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ██╔════╝██╔═████╗)";
        H::setcolor(6); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ███████╗██║██╔██║)";
        H::setcolor(6); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗     ╚════██║████╔╝██║)";
        H::setcolor(6); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝     ███████║╚██████╔╝)";
        H::setcolor(6); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝             ╚══════╝ ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 40) {
        system("chcp 65001 > nul");
        H::setcolor(4); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗             ██╗  ██╗ ██████╗ )";
        H::setcolor(4); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ██║  ██║██╔═████╗)";
        H::setcolor(4); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ███████║██║██╔██║)";
        H::setcolor(4); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗     ╚════██║████╔╝██║)";
        H::setcolor(4); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝          ██║╚██████╔╝)";
        H::setcolor(4); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝                  ╚═╝ ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 30) {
        system("chcp 65001 > nul");
        H::setcolor(4); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗             ██████╗  ██████╗ )";
        H::setcolor(4); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ╚════██╗██╔═████╗)";
        H::setcolor(4); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝      █████╔╝██║██╔██║)";
        H::setcolor(4); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗      ╚═══██╗████╔╝██║)";
        H::setcolor(4); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝     ██████╔╝╚██████╔╝)";
        H::setcolor(4); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝             ╚═════╝  ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 20) {
        system("chcp 65001 > nul");
        H::setcolor(4); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗             ██████╗  ██████╗ )";
        H::setcolor(4); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ╚════██╗██╔═████╗)";
        H::setcolor(4); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝      █████╔╝██║██╔██║)";
        H::setcolor(4); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗     ██╔═══╝ ████╔╝██║)";
        H::setcolor(4); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝     ███████╗╚██████╔╝)";
        H::setcolor(4); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝             ╚══════╝ ╚═════╝ )";
        system("chcp 437 >nul");
    } else if (totalScore >= 10) {
        system("chcp 65001 > nul");
        H::setcolor(4); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗              ██╗ ██████╗ )";
        H::setcolor(4); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ███║██╔═████╗)";
        H::setcolor(4); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ╚██║██║██╔██║)";
        H::setcolor(4); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗      ██║████╔╝██║)";
        H::setcolor(4); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝      ██║╚██████╔╝)";
        H::setcolor(4); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝              ╚═╝ ╚═════╝ )";
        system("chcp 437 >nul");
    } else{
        system("chcp 65001 > nul");
        H::setcolor(4); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗              ██████╗ )";
        H::setcolor(4); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗     ██╔═████╗)";
        H::setcolor(4); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝     ██║██╔██║)";
        H::setcolor(4); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗     ████╔╝██║)";
        H::setcolor(4); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝     ╚██████╔╝)";
        H::setcolor(4); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝              ╚═════╝ )";
        system("chcp 437 >nul");
    }
	system("chcp 65001 > nul");
	H::setcolor(3); H::gotoxy(40, 20); cout << R"(██╗   ██╗ ██████╗ ██╗   ██╗██████╗     ███████╗ ██████╗ ██████╗ ██████╗ ███████╗        )";
	H::setcolor(3); H::gotoxy(40, 21); cout << R"(╚██╗ ██╔╝██╔═══██╗██║   ██║██╔══██╗    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝     ██╗)";
	H::setcolor(3); H::gotoxy(40, 22); cout << R"( ╚████╔╝ ██║   ██║██║   ██║██████╔╝    ███████╗██║     ██║   ██║██████╔╝█████╗       ╚═╝)";
	H::setcolor(3); H::gotoxy(40, 23); cout << R"(  ╚██╔╝  ██║   ██║██║   ██║██╔══██╗    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝       ██╗)";
	H::setcolor(3); H::gotoxy(40, 24); cout << R"(   ██║   ╚██████╔╝╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗     ╚═╝)";
	H::setcolor(3); H::gotoxy(40, 25); cout << R"(   ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝        )";
	system("chcp 437 >nul");

    H::gotoxy(0, 45);
    getch();

    ofstream outFile("../data/StudentQuizResults.dat", ios::binary | ios::app);
    if (outFile) {
        outFile.write(reinterpret_cast<char*>(&result), sizeof(result));
        outFile.close();
        MessageBoxA(NULL, "Your quiz result has been saved!", "Success", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBoxA(NULL, "Failed to save result!", "Error", MB_OK | MB_ICONERROR);
    }
}

void DoQuiz::MenuGradeDesignDesign(){
    H::HLine(14,3,34,1,254);
    H::HLine(150,3,35,1,254);

    H::HLine(14,41,34,1,254);
    H::HLine(150,41,35,1,254);

    H::drawBoxSingleLineWithBG(41,0,118,5,47);
    H::drawBoxSingleLineWithBG(41,38,118,5,47);

    H::drawBoxSingleLineWithBG(2,1,11,41,31);
    H::drawBoxSingleLineWithBG(186,1,11,41,31);
    
    H::HLine(14,19,45,3,254);
    H::HLine(14,25,45,3,254);

    H::HLine(140,19,45,3,254);
    H::HLine(140,25,45,3,254);

    H::HLine(58,10,20,3,254);
    H::HLine(58,34,20,3,254);

    H::HLine(120,10,20,3,254);
    H::HLine(120,34,20,3,254);

    H::VLine(59,10,23,3,219);
    H::VLine(140,10,23,3,219);

    H::gotoxy(52,40);H::setcolor(47);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.    ";
    H::gotoxy(102,40);H::setcolor(47);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
    H::gotoxy(52,42);H::setcolor(47);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.       ";
    H::gotoxy(102,42);H::setcolor(47);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.   ";

    system("chcp 65001 > nul");
    H::setcolor(47);H::gotoxy(43,1);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████      ███████ ██    ██ ██████       ██ ███████  ██████ ████████  )";
    H::setcolor(47);H::gotoxy(43,2);cout<<R"( ██      ██   ██ ██    ██ ██    ██ ██      ██           ██      ██    ██ ██   ██      ██ ██      ██         ██     )";
    H::setcolor(47);H::gotoxy(43,3);cout<<R"( ██      ███████ ██    ██ ██    ██ ███████ █████        ███████ ██    ██ ██████       ██ █████   ██         ██     )";
    H::setcolor(47);H::gotoxy(43,4);cout<<R"( ██      ██   ██ ██    ██ ██    ██      ██ ██                ██ ██    ██ ██   ██ ██   ██ ██      ██         ██     )";
    H::setcolor(47);H::gotoxy(43,5);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████      ███████  ██████  ██████   █████  ███████  ██████    ██     )";
    system("chcp 437 >nul");
}

void DoQuiz::MenuQuizDesignDesign(){
    H::HLine(14,3,34,1,254);
    H::HLine(150,3,35,1,254);

    H::HLine(14,41,34,1,254);
    H::HLine(150,41,35,1,254);

    H::drawBoxSingleLineWithBG(41,0,118,5,47);
    H::drawBoxSingleLineWithBG(41,38,118,5,47);

    H::drawBoxSingleLineWithBG(2,1,11,41,31);
    H::drawBoxSingleLineWithBG(186,1,11,41,31);
    
    H::HLine(14,19,45,3,254);
    H::HLine(14,25,45,3,254);

    H::HLine(140,19,45,3,254);
    H::HLine(140,25,45,3,254);

    H::HLine(58,10,20,3,254);
    H::HLine(58,34,20,3,254);

    H::HLine(120,10,20,3,254);
    H::HLine(120,34,20,3,254);

    H::VLine(59,10,23,3,219);
    H::VLine(140,10,23,3,219);

    H::gotoxy(52,40);H::setcolor(47);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.    ";
    H::gotoxy(102,40);H::setcolor(47);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
    H::gotoxy(52,42);H::setcolor(47);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.       ";
    H::gotoxy(102,42);H::setcolor(47);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.   ";

    system("chcp 65001 > nul");
    H::setcolor(47);H::gotoxy(56,1);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████       ██████  ██    ██ ██ ███████)";
    H::setcolor(47);H::gotoxy(56,2);cout<<R"( ██      ██   ██ ██    ██ ██    ██ ██      ██           ██    ██ ██    ██ ██    ███ )";
    H::setcolor(47);H::gotoxy(56,3);cout<<R"( ██      ███████ ██    ██ ██    ██ ███████ █████        ██    ██ ██    ██ ██   ███  )";
    H::setcolor(47);H::gotoxy(56,4);cout<<R"( ██      ██   ██ ██    ██ ██    ██      ██ ██           ██ ▄▄ ██ ██    ██ ██  ███   )";
    H::setcolor(47);H::gotoxy(56,5);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████       ██████   ██████  ██ ███████)";
    H::setcolor(47);H::gotoxy(56,6);cout<<R"(                                                            ▀▀                      )";
    system("chcp 437 >nul");
}

#endif