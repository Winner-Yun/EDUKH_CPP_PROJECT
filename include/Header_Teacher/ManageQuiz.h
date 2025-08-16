#ifndef ___INC_MANAGE_QUIZ_H___
#define ___INC_MANAGE_QUIZ_H___

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class Quiz {
private:
    string question;
    string correctAnswer;
    string wrongAnswers[3];

public:
    void inputQuiz();
    void displayQuiz() const;
    void saveToFile(ofstream &out) const;
    void loadFromFile(ifstream &in);
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
    cin.clear();
    fflush(stdin);

    cout << "Enter question: ";
    H::inputAll(question, 100); cout << endl;

    cout << "Enter correct answer: ";
    H::inputAll(correctAnswer, 100);

    for (int i = 0; i < 3; i++) {
        cout << "Enter wrong answer " << (i + 1) << ": ";
        H::inputAll(wrongAnswers[i], 100);
    }
}

void Quiz::displayQuiz() const {
    cout << "Question: " << question << "\n";
    cout << "Correct answer: " << correctAnswer << "\n";
    for (int i = 0; i < 3; i++) {
        cout << "Wrong answer " << (i + 1) << ": " << wrongAnswers[i] << "\n";
    }
}

void Quiz::saveToFile(ofstream &out) const {
    auto writeString = [&](const string &s) {
        size_t len = s.size();
        out.write(reinterpret_cast<const char*>(&len), sizeof(len));
        out.write(s.c_str(), len);
    };

    writeString(question);
    writeString(correctAnswer);
    for (int i = 0; i < 3; i++)
        writeString(wrongAnswers[i]);
}

void Quiz::loadFromFile(ifstream &in) {
    auto readString = [&](string &s) {
        size_t len;
        in.read(reinterpret_cast<char*>(&len), sizeof(len));
        s.resize(len);
        in.read(&s[0], len);
    };

    readString(question);
    readString(correctAnswer);
    for (int i = 0; i < 3; i++)
        readString(wrongAnswers[i]);
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
    do {
        Quiz q;
        q.inputQuiz();
        q.saveToFile(out);
        cout << "Add another question? (y/n): ";
        cin >> choice;
        cin.clear();
        fflush(stdin);
    } while (choice == 'y' || choice == 'Y');

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

    // Save remaining quizzes
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