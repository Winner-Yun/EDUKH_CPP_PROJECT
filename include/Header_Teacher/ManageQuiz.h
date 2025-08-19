#ifndef ___INC_MANAGE_QUIZ_H___
#define ___INC_MANAGE_QUIZ_H___

#include "../Header_School/ANTHinsyOOP"
#include "../Header_Teacher/QuizDesign.h"
#include "QuizDesign.h"

using namespace ANTHinsyOOP;

class Quiz {
private:
    char question[100];
    char answers[4][50];     // 4 possible answers
    char correctIndex[5];     // store as char array "1","2","3","4"
    int points;               // each question worth 10

public:
    Quiz() : points(10) {
        correctIndex[0] = '1'; // default "1"
        correctIndex[1] = '\0';
    }

    void inputQuiz();
    void displayQuiz() const;
    void saveToFile(ofstream &out) const;
    void loadFromFile(ifstream &in);

    int getCorrectIndex() const {   // convert to int
        return atoi(correctIndex) - 1;  // 0-based
    }
};

class QuizManager {
private:
    string filename;

public:
    QuizManager(int grade);
    void createQuiz();
    void updateQuiz();
    void deleteQuiz();
};

// ====================== Quiz Method Definitions ======================

void Quiz::inputQuiz() {
    H::setcolor(7); H::gotoxy(17, 18); H::inputAll(question, 100);

    // Answer 1
    H::setcolor(7); H::gotoxy(17, 28);  H::inputAll(answers[0], 50);

    // Answer 2
    H::setcolor(7); H::gotoxy(107, 28); H::inputAll(answers[1], 50);

    // Answer 3
    H::setcolor(7); H::gotoxy(17, 36); H::inputAll(answers[2], 50);

    // Answer 4
    H::setcolor(7); H::gotoxy(107, 36); H::inputAll(answers[3], 50);

    do {
        H::setcolor(7); H::gotoxy(80, 43); cout << "Which answer is correct? (1-4): ";
        H::inputNumber(correctIndex, 2);
    } while (atoi(correctIndex) < 1 || atoi(correctIndex) > 4);
    int choice = atoi(correctIndex);

    switch (choice) {
        case 1:
            H::drawBoxSingleLineWithBG(15, 26, 80, 3, 2);
            H::setcolor(7); H::gotoxy(17, 28); cout << answers[0];
            break;
        case 2:
            H::drawBoxSingleLineWithBG(105, 26, 80, 3, 2);
            H::setcolor(7); H::gotoxy(107, 28); cout << answers[1];
            break;
        case 3:
            H::drawBoxSingleLineWithBG(15, 34, 80, 3, 2);
            H::setcolor(7); H::gotoxy(17, 36); cout << answers[2];
            break;
        case 4:
            H::drawBoxSingleLineWithBG(105, 34, 80, 3, 2);
            H::setcolor(7); H::gotoxy(107, 36); cout << answers[3];
            break;
    }
    points = 10;
}

void Quiz::displayQuiz() const {
    cout << "Question: " << question << "\n";
    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ") " << answers[i];
        if (i == getCorrectIndex()) cout << "  <-- Correct";
        cout << "\n";
    }
    cout << "Points: " << points << "\n";
}

void Quiz::saveToFile(ofstream &out) const {
    out.write(reinterpret_cast<const char*>(question), sizeof(question));
    for (int i = 0; i < 4; i++)
        out.write(reinterpret_cast<const char*>(answers[i]), sizeof(answers[i]));
    out.write(reinterpret_cast<const char*>(correctIndex), sizeof(correctIndex));
    out.write(reinterpret_cast<const char*>(&points), sizeof(points));
}

void Quiz::loadFromFile(ifstream &in) {
    in.read(reinterpret_cast<char*>(question), sizeof(question));
    for (int i = 0; i < 4; i++)
        in.read(reinterpret_cast<char*>(answers[i]), sizeof(answers[i]));
    in.read(reinterpret_cast<char*>(correctIndex), sizeof(correctIndex));
    in.read(reinterpret_cast<char*>(&points), sizeof(points));
}

// ====================== QuizManager Method Definitions ======================

QuizManager::QuizManager(int grade) {
    filename = "grade" + to_string(grade) + ".bin";
}

void QuizManager::createQuiz() {
    ofstream out(filename, ios::binary | ios::app);
    if (!out) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    char choice;
    int count = 0;
    do {
        H::cls();
        QuizDesign::QuizScreen();
        Quiz q;
        cout << "Creating Question #" << (count + 1) << "\n\n";
        q.inputQuiz();
        q.saveToFile(out);

        count++;
        if (count >= 10) {
            cout << "Maximum of 10 questions reached.\n";
            break;
        }

        cout << "Add another question? (y/n): ";
        cin >> choice;
        cin.clear();
        fflush(stdin);
    } while ((choice == 'y' || choice == 'Y') && count < 10);

    out.close();
}


void QuizManager::updateQuiz() {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    vector<Quiz> quizzes;
    Quiz q;

    while (in.peek() != EOF) {
        q.loadFromFile(in);
        quizzes.push_back(q);
    }
    in.close();

    if (quizzes.empty()) {
        cout << "No quizzes found to update.\n";
        return;
    }

    int index = 0;
    char choice;
    while (true) {
        cout << "\nQuiz #" << (index + 1) << ":\n";
        quizzes[index].displayQuiz();
        cout << "[u]pdate, [n]ext, [p]revious, [e]xit: ";
        cin >> choice;
        cin.clear();
        fflush(stdin);

        if (choice == 'u') {
            cout << "Updating quiz #" << (index + 1) << "...\n";
            quizzes[index].inputQuiz();
        }
        else if (choice == 'n') {
            if (index < (int)quizzes.size() - 1) index++;
            else cout << "Already at last quiz.\n";
        }
        else if (choice == 'p') {
            if (index > 0) index--;
            else cout << "Already at first quiz.\n";
        }
        else if (choice == 'e') {
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    ofstream out(filename, ios::binary | ios::trunc);
    if (!out) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& quiz : quizzes) {
        quiz.saveToFile(out);
    }
    out.close();
}

void QuizManager::deleteQuiz() {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    vector<Quiz> quizzes;
    Quiz q;

    while (in.peek() != EOF) {
        q.loadFromFile(in);
        quizzes.push_back(q);
    }
    in.close();

    if (quizzes.empty()) {
        cout << "No quizzes found to delete.\n";
        return;
    }

    int index = 0;
    char choice;
    while (true) {
        cout << "\nQuiz #" << (index + 1) << ":\n";
        quizzes[index].displayQuiz();
        cout << "[d]elete, [n]ext, [p]revious, [e]xit: ";
        cin >> choice;
        cin.clear();
        fflush(stdin);

        if (choice == 'd') {
            cout << "Deleting quiz #" << (index + 1) << "...\n";
            quizzes.erase(quizzes.begin() + index);

            if (quizzes.empty()) {
                cout << "All quizzes deleted.\n";
                break;
            }

            if (index >= (int)quizzes.size()) index = quizzes.size() - 1;
        }
        else if (choice == 'n') {
            if (index < (int)quizzes.size() - 1) index++;
            else cout << "Already at last quiz.\n";
        }
        else if (choice == 'p') {
            if (index > 0) index--;
            else cout << "Already at first quiz.\n";
        }
        else if (choice == 'e') {
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    ofstream out(filename, ios::binary | ios::trunc);
    if (!out) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& quiz : quizzes) {
        quiz.saveToFile(out);
    }
    out.close();

    cout << "Changes saved.\n";
}

#endif
