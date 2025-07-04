#ifndef ___MAIN_MENU_CPP_HEADER__
#define ___MAIN_MENU_CPP_HEADER__

#include "../Header_School/ANTHinsyOOP"
#include "Login_Form.h"
using namespace ANTHinsyOOP;

class MenuDsign{
    public:
        static void designPage(); // sub design
        void Main_menu(); // main menu
};

void MenuDsign::Main_menu(){

    designPage();  // call design

    
    int j = 0;
    int option;
    clock_t escStart = 0;
    bool escHeld = false;

    do {
        H::drawBoxDoubleLineWithBG(59,11,40,1,31);
        H::drawBoxDoubleLineWithBG(99,16,40,1,31);
        H::drawBoxDoubleLineWithBG(59,21,40,1,31);
        H::drawBoxDoubleLineWithBG(99,26,40,1,31);
        H::drawBoxDoubleLineWithBG(59,31,40,1,31);

        //Stick

        H::HLine(100,12,40,1,205);
        H::HLine(58,17,40,1,205);
        H::HLine(100,22,40,1,205);
        H::HLine(58,27,40,1,205);
        H::HLine(100,32,40,1,205);

        H::setcolor(1);

        H::gotoxy(60, 13);cout << "    I - MANAGE TEACHET AND STUDENT    " << endl;
        H::gotoxy(60, 12);cout << "                                      " << endl;

        
        H::gotoxy(100, 17);cout << "                                      " << endl;
        H::gotoxy(100, 18);cout << "  II - ASSIGN TEACHER TO EACH CLASS   " << endl;

   
        H::gotoxy(60, 22);cout << "                                      " << endl;
        H::gotoxy(60, 23);cout << "       III - MANAGE ATTENDANCE        " << endl;
        // H::gotoxy(60, 22);cout << "                                      " << endl;


        H::gotoxy(100, 27);cout << "                                      " << endl;
        H::gotoxy(100, 28);cout << " IV - CRRATE  SCHEDULE FOR EACH CLASS " << endl;

        H::gotoxy(60, 32);cout << "                                      " << endl;
        H::gotoxy(60, 33);cout << "        V - ABOUT US / SCHOOL         " << endl;

        if (j == 0) {
            H::HLine(100,12,40,2,205);
            H::drawBoxDoubleLineWithBG(59,11,40,1,47);
            H::setcolor(2);
            
            H::gotoxy(60, 11);cout << "    I - MANAGE TEACHET AND STUDENT    " << endl;
            H::gotoxy(60, 12);cout << "                                      " << endl;
        }
        if (j == 1) {
            H::HLine(58,17,40,2,205);
            H::drawBoxDoubleLineWithBG(99,16,40,1,47);
            H::setcolor(2);
            H::gotoxy(100, 17);cout << "                                      " << endl;
            H::gotoxy(100, 16);cout << "  II - ASSIGN TEACHER TO EACH CLASS   " << endl;
        }
        if (j == 2) {
            H::HLine(100,22,40,2,205);
            H::drawBoxDoubleLineWithBG(59,21,40,1,47);
            H::setcolor(2);
            H::gotoxy(60, 22);cout << "                                      " << endl;
            H::gotoxy(60, 21);cout << "       III - MANAGE ATTENDANCE        " << endl;
        }
        if (j == 3) {
            H::HLine(58,27,40,2,205);
            H::drawBoxDoubleLineWithBG(99,26,40,1,47);
            H::setcolor(2);

            H::gotoxy(100, 27);cout << "                                      " << endl;
            H::gotoxy(100, 26);cout << " IV - CRRATE  SCHEDULE FOR EACH CLASS " << endl;
        }
        if (j == 4) {
            H::HLine(100,32,40,2,205);
            H::drawBoxDoubleLineWithBG(59,31,40,1,47);
            H::setcolor(2);
            H::gotoxy(60, 32);cout << "                                      " << endl;
            H::gotoxy(60, 31);cout << "        V - ABOUT US / SCHOOL         " << endl;
        }

        option = getch();
        switch (option) {
            case 80: j++; if (j > 4) j = 0; break;
            case 72: j--; if (j < 0) j = 4; break;
        }


        // ESC Hold Logic (start/stop timer based on key)
        if (option == 27) { 
            if (!escHeld) {
                escStart = clock();
                escHeld = true;
            }
        } else {
            escHeld = false;
            escStart = 0;
        }

        // Check if ESC has been held for 3 seconds
        if (escHeld && ((clock() - escStart) / CLOCKS_PER_SEC >= 3)) {
            system("cls");
            j = 5; 
            break;
        }

    } while (option != 13);

    //declare class
    Login_Design logD;

    switch (j) {
        case 0:{
            system("cls");
            H::drawBoxSingleLineWithBG(47,20,105,1,15);
            for (int i = 47; i <= 147; i++) {
                H::HLine(i, 21, 1, 15, 177);
                cout<<i-47<<"%";
                H::delay(10);
            }
            system("cls");
            cout << " Handle OPTION 1 ";
            getch();
            break;
        }

        case 1:{
            system("cls");
            H::drawBoxSingleLineWithBG(47,20,105,1,15);
            for (int i = 47; i <= 147; i++) {
                H::HLine(i, 21, 1, 15, 177);
                cout<<i-47<<"%";
                H::delay(10);
            }
            H::cls();
            cout << " Handle OPTION 2 ";
            getch();
            break;
        }

        case 2:{
            system("cls");
            H::drawBoxSingleLineWithBG(47,20,105,1,15);
            for (int i = 47; i <= 147; i++) {
                H::HLine(i, 21, 1, 15, 177);
                cout<<i-47<<"%";
                H::delay(10);
            }
            H::cls();
            cout << " Handle OPTION 3 ";
            getch();
            break;
        }

        case 3:{
            system("cls");
            H::drawBoxSingleLineWithBG(47,20,105,1,15);
            for (int i = 47; i <= 147; i++) {
                H::HLine(i, 21, 1, 15, 177);
                cout<<i-47<<"%";
                H::delay(20);
            }
            H::cls();
            cout << " Handle OPTION 3 ";
            getch();
            break;
        }

        case 4:{
            system("cls");
            H::drawBoxSingleLineWithBG(47,20,105,1,15);
            for (int i = 47; i <= 147; i++) {
                H::HLine(i, 21, 1, 15, 177);
                cout<<i-47<<"%";
                H::delay(10);
            }
            H::cls();
            cout << " Handle OPTION 5 ";
            getch();
            break;
        }
        case 5:{
            system("cls");
            H::drawBoxSingleLineWithBG(47,20,105,1,15);
            for (int i = 47; i <= 147; i++) {
                H::HLine(i, 21, 1, 15, 177);
                cout<<i-47<<"%";
                H::delay(10);
            }
            H::cls();
            logD.MainLogin_NoLoading();
            break;
        }

    }
}

void MenuDsign::designPage(){

    H::drawBoxDoubleLineWithBG(3,0,194,6,31); //top

    H::drawBoxDoubleLineWithBG(3,37,194,6,47); // bottom

    H::drawBoxSingleLineWithBG(3,5,55,1,1); //top
    H::drawBoxSingleLineWithBG(142,5,55,1,1); 

    H::drawBoxSingleLineWithBG(3,37,55,1,2); //bottom
    H::drawBoxSingleLineWithBG(142,37,55,1,2); 

    H::setcolor(1);H::gotoxy(59,2);cout<<R"(                                                                                  )";
    H::setcolor(1);H::gotoxy(59,3);cout<<R"(        _________________   ___              ______  _____________  __  ______    )";
    H::setcolor(1);H::gotoxy(59,4);cout<<R"(    ___  ____/__  __ \_  / / /          ___   |/  /__  ____/__  | / /_  / / /     )";
    H::setcolor(1);H::gotoxy(59,5);cout<<R"(    __  __/  __  / / /  / / /           __  /|_/ /__  __/  __   |/ /_  / / /      )";
    H::setcolor(1);H::gotoxy(59,6);cout<<R"(    _  /___  _  /_/ // /_/ /            _  /  / / _  /___  _  /|  / / /_/ /       )";
    H::setcolor(15);H::gotoxy(59,7);cout<<R"(    /_____/  /_____/ \____/             /_/  /_/  /_____/  /_/ |_/  \____/        )";
    H::setcolor(1);H::gotoxy(59,8);cout<<R"(                                                                                  )";


    H::drawBoxDoubleLineWithBG(4,1,54,2,4);
    H::setcolor(4);H::gotoxy(12,2);cout<<"[!] HOLD ESC KEY FOR 3 SEC FOR LOGOUT";

    H::setcolor(2);H::gotoxy(59,36);cout<<R"(  ------------------------------------------------------------------------------  )";
    H::setcolor(2);H::gotoxy(59,37);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,38);cout<<R"(  '                     [!] USE UP ARROW TO MOVE UP                            '  )";
    H::setcolor(2);H::gotoxy(59,39);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,40);cout<<R"(  '                     [!] USE DOWN ARROW TO MOVE DOWN                        '  )";
    H::setcolor(2);H::gotoxy(59,41);cout<<R"(  '                                                                            '  )";
    H::setcolor(2);H::gotoxy(59,42);cout<<R"(  ------------------------------------------------------------------------------  )";


    H::drawBoxSingleLine(3,10,0,23,10);//left
    H::drawBoxSingleLine(4,12,0,19,15);
    H::drawBoxSingleLine(5,10,0,23,10);
    H::drawBoxSingleLine(6,12,0,19,15);
    H::drawBoxSingleLine(5,10,0,23,10);
    H::drawBoxSingleLine(6,12,0,19,15);
    H::drawBoxSingleLine(7,10,0,23,10);
    H::drawBoxSingleLine(8,12,0,19,15);
    H::drawBoxSingleLine(9,10,0,23,10);
    H::drawBoxSingleLine(10,12,0,19,15);
    H::drawBoxSingleLine(11,10,0,23,10);
    H::drawBoxSingleLine(12,12,0,19,15);
    H::drawBoxSingleLine(13,10,0,23,10);
    H::drawBoxSingleLine(14,12,0,19,15);
    H::drawBoxSingleLine(15,10,0,23,10);
    H::drawBoxSingleLine(16,12,0,19,15);
    H::drawBoxSingleLine(17,10,0,23,10);
    H::drawBoxSingleLine(18,12,0,19,15);
    H::drawBoxSingleLine(19,10,0,23,10);
    H::drawBoxSingleLine(20,12,0,19,15);

    H::drawBoxSingleLine(21,14,0,15,15);
    H::drawBoxSingleLine(22,14,0,15,15);
    H::drawBoxSingleLine(23,14,0,15,15);
    H::drawBoxSingleLine(24,16,0,11,15);
    H::drawBoxSingleLine(25,16,0,11,15);
    H::drawBoxSingleLine(26,16,0,11,15);
    H::drawBoxSingleLine(27,16,0,11,15);
    H::drawBoxSingleLine(28,16,0,11,15);
    H::drawBoxSingleLine(29,16,0,11,15);
    H::drawBoxSingleLine(30,16,0,11,15);



    H::drawBoxSingleLine(197,10,0,23,1); //right
    H::drawBoxSingleLine(196,12,0,19,15);
    H::drawBoxSingleLine(195,10,0,23,1);
    H::drawBoxSingleLine(194,12,0,19,15);
    H::drawBoxSingleLine(195,10,0,23,1);
    H::drawBoxSingleLine(194,12,0,19,15);
    H::drawBoxSingleLine(193,10,0,23,1);
    H::drawBoxSingleLine(192,12,0,19,15);
    H::drawBoxSingleLine(191,10,0,23,1);
    H::drawBoxSingleLine(190,12,0,19,15);
    H::drawBoxSingleLine(191,10,0,23,1);
    H::drawBoxSingleLine(190,12,0,19,15);
    H::drawBoxSingleLine(189,10,0,23,1);
    H::drawBoxSingleLine(188,12,0,19,15);
    H::drawBoxSingleLine(187,10,0,23,1);
    H::drawBoxSingleLine(186,12,0,19,15);
    H::drawBoxSingleLine(185,10,0,23,1);
    H::drawBoxSingleLine(184,12,0,19,15);
    H::drawBoxSingleLine(183,10,0,23,1);
    H::drawBoxSingleLine(182,12,0,19,15);

    H::drawBoxSingleLine(181,14,0,15,15);
    H::drawBoxSingleLine(180,14,0,15,15);
    H::drawBoxSingleLine(179,14,0,15,15);
    H::drawBoxSingleLine(178,16,0,11,15);
    H::drawBoxSingleLine(177,16,0,11,15);
    H::drawBoxSingleLine(176,16,0,11,15);
    H::drawBoxSingleLine(175,16,0,11,15);
    H::drawBoxSingleLine(174,16,0,11,15);
    H::drawBoxSingleLine(173,16,0,11,15);
    H::drawBoxSingleLine(171,16,0,11,15);
        
};

#endif