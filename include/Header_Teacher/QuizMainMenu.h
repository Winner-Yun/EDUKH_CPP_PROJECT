#ifndef ___INC_QUIZ_MAIN_MENU_H___
#define ___INC_QUIZ_MAIN_MENU_H___

#include "../Header_School/ANTHinsyOOP"
#include "ManageQuiz.h"
#include "../Header_EDU/CustomHeader.h"

using namespace ANTHinsyOOP;

class QuizMenu {
    public:
        static void QuizGradeMenu(const char* teacherID, const char* subject);
        static void QuizChooseMenu(const char* teacherID, const char* className, const char* subject);
        static void QuizManageMenu(const char* teacherID, const char* className, const char* quizID, const char* subject);
        static void LoadingHeader(int id);
};

bool isTeacherAssignedToClass(const char* teacherID, const char* className) {
    ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "File not found", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    AssignClassForm ac;
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClassForm))) {
        if (strcmp(ac.teacherID, teacherID) == 0 && strcmp(ac.className, className) == 0) {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    return false;
}

void QuizMenu::QuizGradeMenu(const char* teacherID, const char* subject) {
    int option;
    int choice = 1;
    H::setcursor(false, 0);

    do {
        H::cls;
        QuizDesign::QuizMenu();
        do {
            QuizDesign::QuizGButton();
            switch (choice) {
                case 1: {
                    H::drawBoxSingleLineWithBG(16, 14, 40, 3, 1);
                    H::clearBox(16, 15, 40, 3, 151);
                    H::setcolor(151); H::gotoxy(27, 16); cout << "G R A D E    1 0";
                    QuizDesign::QuizGradeScreen();
                    break;
                }
                case 2: {
                    H::drawBoxSingleLineWithBG(16, 20, 40, 3, 1);
                    H::clearBox(16, 21, 40, 3, 151);
                    H::setcolor(151); H::gotoxy(27, 22); cout << "G R A D E    1 1";
                    QuizDesign::QuizGradeScreen();
                    break;
                }
                case 3: {
                    H::drawBoxSingleLineWithBG(16, 26, 40, 3, 1);
                    H::clearBox(16, 27, 40, 3, 151);
                    H::setcolor(151); H::gotoxy(27, 28); cout << "G R A D E    1 2";
                    QuizDesign::QuizGradeScreen();
                    break;
                }
                case 4: {
                    H::drawBoxSingleLineWithBG(16, 32, 40, 3, 1);
                    H::clearBox(16, 33, 40, 3, 199);
                    H::setcolor(199); H::gotoxy(31, 34); cout << "B A C K";
                    QuizDesign::QuizMenuScreen();
                    break;
                }
            }

            option = getch();
            choice = EdumasterCustom::ArrowKeyConTrol(4, 1, choice, option);

        } while(option != 27 && option != 13);

        if(option == 27) {
            H::cls();
            LoadingHeader(1);
            system("cls");
        }

        if (option == 13) {
            switch (choice) {
                case 1: {
                    if (isTeacherAssignedToClass(teacherID, "10")) {
                        H::setcolor(7);
                        system("cls");
                        QuizMenu::QuizChooseMenu(teacherID, "10", subject);
                        break;
                    } else {
                        MessageBoxA(NULL, "SORRY, YOU ARE NOT ASSIGNED TO GRADE 10.", "Notice", MB_OK | MB_ICONASTERISK);
                    }
                    break;
                }
                case 2: {
                    if (isTeacherAssignedToClass(teacherID, "11")) {
                        H::setcolor(7);
                        system("cls");
                        QuizMenu::QuizChooseMenu(teacherID, "11", subject);
                        break;
                    } else {
                        MessageBoxA(NULL, "SORRY, YOU ARE NOT ASSIGNED TO GRADE 11.", "Notice", MB_OK | MB_ICONASTERISK);
                    }
                    break;
                }
                case 3: {
                    if (isTeacherAssignedToClass(teacherID, "12")) {
                        H::setcolor(7);
                        system("cls");
                        QuizMenu::QuizChooseMenu(teacherID, "12", subject);
                        break;
                    } else {
                        MessageBoxA(NULL, "SORRY, YOU ARE NOT ASSIGNED TO GRADE 12.", "Notice", MB_OK | MB_ICONASTERISK);
                    }
                    break;
                }
                case 4: {
                    H::setcolor(7);
                    system("cls");
                    option = 27;
                    H::cls();
                    break;
                }
            }
        }
    } while(option != 27);
}

void QuizMenu::QuizChooseMenu(const char* teacherID, const char* className, const char* subject) {
    int option;
    int choice = 1;
    H::setcursor(false, 0);
    H::cls();
    system("chcp 65001 > nul");
    H::setcolor(3);H::gotoxy(56,3);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████       ██████  ██    ██ ██ ███████)";
    H::setcolor(3);H::gotoxy(56,4);cout<<R"( ██      ██   ██ ██    ██ ██    ██ ██      ██           ██    ██ ██    ██ ██    ███ )";
    H::setcolor(3);H::gotoxy(56,5);cout<<R"( ██      ███████ ██    ██ ██    ██ ███████ █████        ██    ██ ██    ██ ██   ███  )";
    H::setcolor(3);H::gotoxy(56,6);cout<<R"( ██      ██   ██ ██    ██ ██    ██      ██ ██           ██ ▄▄ ██ ██    ██ ██  ███   )";
    H::setcolor(3);H::gotoxy(56,7);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████       ██████   ██████  ██ ███████)";
    H::setcolor(3);H::gotoxy(56,8);cout<<R"(                                                            ▀▀                      )";
    system("chcp 437 >nul");
    H::HLine(7, 0, 186, 7, 228);
    H::HLine(7, 1, 186, 7, 219);
    H::HLine(7, 9, 186, 7, 219);
    
    H::drawBoxSingleLineWithBG(1, 0, 5, 43, 247);
	H::drawBoxSingleLineWithBG(194, 0, 5, 43, 247);
	H::drawBoxSingleLineWithBG(3, 0, 1, 43, 145);
	H::drawBoxSingleLineWithBG(196, 0, 1, 43, 145);

    H::drawBoxDoubleLineWithBG(12, 12, 4, 29, 198);
    H::drawBoxDoubleLineWithBG(16, 13, 4, 27, 151);
    H::drawBoxDoubleLineWithBG(20, 14, 4, 25, 219);

    H::drawBoxDoubleLineWithBG(184, 12, 4, 29, 198);
    H::drawBoxDoubleLineWithBG(180, 13, 4, 27, 151);
    H::drawBoxDoubleLineWithBG(176, 14, 4, 25, 219);

    H::drawBoxDoubleLineWithBG(36, 41, 130, 1, 173);
    H::drawBoxDoubleLineWithBG(39, 40, 124, 1, 4);
    H::gotoxy(68, 41); H::setcolor(6);  cout << "[Tip!]"; H::setcolor(7);  cout << " : Use Arrow "; H::setcolor(1);  cout << "[Up]"; H::setcolor(7);  cout << " - Arrow "; H::setcolor(4);  cout << "[Down]"; H::setcolor(7); cout << " to Move | "; H::setcolor(2); cout << "[Enter]"; H::setcolor(7); cout << " to Select.";

    H::drawBoxSingleLineWithBG(50, 10, 1, 28, 247);
    H::drawBoxSingleLineWithBG(150, 10, 1, 28, 247);

    H::HLine(7, 15, 4, 7, 219);
    H::HLine(7, 27, 4, 7, 219);
    H::HLine(7, 39, 4, 7, 219);

    H::HLine(189, 15, 4, 7, 219);
    H::HLine(189, 27, 4, 7, 219);
    H::HLine(189, 39, 4, 7, 219);

    do {
        H::drawBoxSingleLineWithBG(75, 12, 50, 3, 1);
        H::setcolor(2); H::gotoxy(94, 14); cout << "Q U I Z   1";

        H::drawBoxSingleLineWithBG(75, 18, 50, 3, 1);
        H::setcolor(2); H::gotoxy(94, 20); cout << "Q U I Z   2";

        H::drawBoxSingleLineWithBG(75, 24, 50, 3, 1);
        H::setcolor(2); H::gotoxy(94, 26); cout << "Q U I Z   3";

        H::drawBoxSingleLineWithBG(75, 30, 50, 3, 1);
        H::setcolor(4); H::gotoxy(96, 32); cout << "B A C K";

        switch (choice) {
            case 1:
                H::drawBoxSingleLineWithBG(75, 12, 50, 3, 153);
                H::clearBox(76, 14, 48, 1, 110);
                H::setcolor(111); H::gotoxy(94, 14); cout << "Q U I Z   1";
                H::setcolor(7);
                break;
            case 2:
                H::drawBoxSingleLineWithBG(75, 18, 50, 3, 153);
                H::clearBox(76, 20, 48, 1, 110);
                H::setcolor(111); H::gotoxy(94, 20); cout << "Q U I Z   2";
                H::setcolor(7);
                break;
            case 3:
                H::drawBoxSingleLineWithBG(75, 24, 50, 3, 153);
                H::clearBox(76, 26, 48, 1, 110);
                H::setcolor(111); H::gotoxy(94, 26); cout << "Q U I Z   3";
                H::setcolor(7);
                break;
            case 4:
                H::drawBoxSingleLineWithBG(75, 30, 50, 3, 153);
                H::clearBox(76, 32, 48, 1, 199);
                H::setcolor(199); H::gotoxy(96, 32); cout << "B A C K";
                H::setcolor(7);
                break;
        }

        option = getch();
        choice = EdumasterCustom::ArrowKeyConTrol(4, 1, choice, option); // 4 options total

    } while (option != 13 && option != 27);

    H::cls();

    if (option == 13) {
        switch (choice) {
            case 1: // Quiz 1
                QuizManageMenu(teacherID, className, "1", subject);
                break;
            case 2: // Quiz 2
                QuizManageMenu(teacherID, className, "2", subject);
                break;
            case 3: // Quiz 3
                QuizManageMenu(teacherID, className, "3", subject);
                break;
            case 4: // Back
                break;
        }
    }
}

void QuizMenu::QuizManageMenu(const char* teacherID, const char* className, const char* quizID, const char* subject) {
    int option;
    int choice = 1; // start at CREATE
    bool published = Quiz::isPublished(teacherID, className, quizID);
    H::cls();
    QuizDesign::QuizMenu();

    QuizDesign design;
    design.gradeTitle(className);

    do {
        H::setcursor(false, 0);
        QuizDesign::QuizButton();
        if (published) {
            H::drawBoxSingleLineWithBG(16, 26, 40, 3, 5);
            H::setcolor(7); H::gotoxy(26, 28); cout << "U N P U B L I S H";
        } else {
            H::drawBoxSingleLineWithBG(16, 26, 40, 3, 5);
            H::setcolor(7); H::gotoxy(28, 28); cout << "P U B L I S H";
        }
        // Highlight menu options
        switch (choice) {
            case 1: {
                H::clearBox(16, 15, 40, 3, 215);
                H::setcolor(215); H::gotoxy(24, 16); cout << "C R E A T E   Q U I Z";
                QuizDesign::QuizCreateButton();
                break;
            }
            case 2: {
                H::clearBox(16, 21, 40, 3, 215);
                H::setcolor(215); H::gotoxy(24, 22); cout << "U P D A T E   Q U I Z";
                QuizDesign::QuizUpdateButton();
                break;
            }
            case 3: {
                if (published) {
                    H::clearBox(16, 27, 40, 3, 215);
                    H::setcolor(215); H::gotoxy(26, 28); cout << "U N P U B L I S H";
                    QuizDesign::QuizDeleteButton("1");
                } else {
                    H::clearBox(16, 27, 40, 3, 215);
                    H::setcolor(215); H::gotoxy(28, 28); cout << "P U B L I S H";
                    QuizDesign::QuizDeleteButton("2");
                }
                break;
            }
            case 4: {
                H::clearBox(16, 33, 40, 3, 199);
                H::setcolor(199); H::gotoxy(31, 34); cout << "B A C K";
                QuizDesign::QuizMenuScreen();
                break;
            }
        }

        option = getch();
        choice = EdumasterCustom::ArrowKeyConTrol(4, 1, choice, option); // 4 options

    } while (option != 13 && option != 27) ;

    H::setcursor(true, 1);

    if (option == 13) {
        switch (choice) {
            case 1: // CREATE
                Quiz::CreateQuiz(teacherID, className, quizID, subject);
                QuizManageMenu(teacherID, className, quizID, subject);
                break;
            case 2: // UPDATE
                Quiz::UpdateQuiz(teacherID, className, quizID);
                QuizManageMenu(teacherID, className, quizID, subject);
                break;
            case 3: // DELETE
                Quiz::PublishQuiz(teacherID, className, quizID);
                QuizManageMenu(teacherID, className, quizID, subject);
                break;
            case 4: // BACK
                QuizMenu::QuizChooseMenu(teacherID, className, subject);
                break;
        }
    } else if (option == 27) {
        QuizMenu::QuizChooseMenu(teacherID, className, subject);
    }
}

void QuizMenu::LoadingHeader(int id) {
    if(id == 1){
        H::setcolor(1);H::gotoxy(48,15);cout << R"(   __   ____  __________  __  ___   ____  ___   ___  __  ________  __ )";
        H::setcolor(1);H::gotoxy(48,16);cout << R"(  / /  / __ \/ ___/  _/ |/ / / _ | / __/ / _ | / _ \/  |/  /  _/ |/ / )";
        H::setcolor(1);H::gotoxy(48,17);cout << R"( / /__/ /_/ / (_ // //    / / __ |_\ \  / __ |/ // / /|_/ // //    /  )";
        H::setcolor(7);H::gotoxy(48,18);cout << R"(/____/\____/\___/___/_/|_/ /_/ |_/___/ /_/ |_/____/_/  /_/___/_/|_/   )";
    }
    else if(id == 2){
        H::setcolor(2);H::gotoxy(49,12);cout << R"( ______________     ___________________________________________________________________                    )";
        H::setcolor(2);H::gotoxy(49,13);cout << R"( 7     77     7     7     77  _  77     77     77     77     77     77  77     77     7                    )";
        H::setcolor(2);H::gotoxy(49,14);cout << R"( |  7  ||  _  |     |  -  ||    _||  7  ||  ___!|  ___!|  ___!|  ___!|  ||  _  ||   __!                    )";
        H::setcolor(2);H::gotoxy(49,15);cout << R"( |  |  ||  7  |     |  ___!|  _ \ |  |  ||  7___|  __|_!__   7!__   7|  ||  7  ||  !  7                    )";
        H::setcolor(7);H::gotoxy(49,16);cout << R"( |  !  ||  |  |     |  7   |  7  ||  !  ||     7|     77     |7     ||  ||  |  ||     |     ____________   )";
        H::setcolor(7);H::gotoxy(49,17);cout << R"( !_____!!__!__!     !__!   !__!__!!_____!!_____!!_____!!_____!!_____!!__!!__!__!!_____!     7__77__77__7   )";
    }
}

#endif