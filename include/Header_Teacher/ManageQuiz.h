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
    void inputQuiz() {
        cin.ignore();
        cout << "Enter question: ";
        getline(cin, question);

        cout << "Enter correct answer: ";
        getline(cin, correctAnswer);

        for (int i = 0; i < 3; i++) {
            cout << "Enter wrong answer " << (i + 1) << ": ";
            getline(cin, wrongAnswers[i]);
        }
    }

    void displayQuiz() const {
        cout << "Question: " << question << endl;
        cout << "Correct answer: " << correctAnswer << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Wrong answer " << (i + 1) << ": " << wrongAnswers[i] << endl;
        }
    }

    void saveToFile(ofstream &out) const {
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

    void loadFromFile(ifstream &in) {
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
};

class QuizManager {
private:
    string filename;

public:
    QuizManager(int grade) {
        filename = "grade" + to_string(grade) + ".bin";
    }

    void createQuiz() {
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
            cin.ignore();
        } while (choice == 'y' || choice == 'Y');

        out.close();
    }

    void updateQuiz() {
        ifstream in(filename, ios::binary);
        if (!in) {
            cerr << "Error opening file for reading.\n";
            return;
        }

        vector<Quiz> quizzes;
        Quiz q;

        // Load all quizzes
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
            cin.ignore();

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

        // Save updated quizzes back to file
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

    void deleteQuiz() {
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

        int delIndex;
        cout << "Enter quiz number to delete (1-" << quizzes.size() << "): ";
        cin >> delIndex;
        cin.ignore();

        if (delIndex > 0 && delIndex <= (int)quizzes.size()) {
            quizzes.erase(quizzes.begin() + delIndex - 1);
            ofstream out(filename, ios::binary | ios::trunc);
            if (!out) {
                cerr << "Error opening file for writing.\n";
                return;
            }
            for (const auto& quiz : quizzes) {
                quiz.saveToFile(out);
            }
            out.close();
            cout << "Quiz deleted successfully.\n";
        } else {
            cout << "Invalid quiz number.\n";
        }
    }
};

#endif