#include <windows.h>
#include <conio.h>
#include <iostream>
#include "../include/Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

//Welcome Loading Page
void Title_Function() {
    H::setcolor(5);
    H::gotoxy(55,8);cout<<R"(  _____                                                                         _____  )";
    H::gotoxy(55,9);cout<<R"( ( ___ )                                                                       ( ___ ) )";
    H::setcolor(6);
    H::gotoxy(55,10);cout<<R"(  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |  )";
    H::gotoxy(55,11);cout<<R"(  |   |                                                                         |   |  )";
    H::gotoxy(55,12);cout<<R"(  |   |                                                                         |   |  )";
    H::gotoxy(55,13);cout<<R"(  |   |                                                                         |   |  )";
    H::gotoxy(55,14);cout<<R"(  |   |                                                                         |   |  )";
    H::gotoxy(55,15);cout<<R"(  |   |                                                                         |   |  )"; 
    H::gotoxy(55,16);cout<<R"(  |   |                                                                         |   |  )"; 
    H::gotoxy(55,17);cout<<R"(  |   |                                                                         |   |  )"; 
    H::gotoxy(55,18);cout<<R"(  |   |                                                                         |   |  )"; 
    H::gotoxy(55,19);cout<<R"(  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|  )"; 
    H::setcolor(5);
    H::gotoxy(55,20);cout<<R"( (_____)                                                                       (_____) )";

    string flameLines[] = {
        R"(      (                *             (                (          )    )  )",
        R"(      )\ )           (  `     (      )\ )  *   )      )\ )    ( /( ( /(  )",
        R"(  (  (()/(      (    )\))(    )\    (()/(` )  /( (   (()/(    )\()))\()) )",
        R"(  )\  /(_)) )(  )\  ((_)()\((((_)(   /(_))( )(_)))\  /(_))  ((_)\((_)_)  )",
        R"( ((_)(_))_ (_) ((_) (_()((_))\ _ )  (_)) (_(_())((_) (_))   (_((_)_((_)  )"
    };

    int fireColors[] = {4, 6, 12, 14};

    int a = 5, b = 6;
    srand((unsigned)time(0));
    H::drawBoxSingleLine(54, 24, 89, 2);
    H::gotoxy(55,25);cout<<"LOADING...";
    
    for (int i = 55; i <= 175; i++) {
        for (int l = 0; l < 5; l++) {
            H::gotoxy(62, 11 + l);
            for (char ch : flameLines[l]) {
                if (ch == ' ') {
                    cout << ' ';
                } else {
                    H::setcolor(fireColors[rand() % 4]);
                    cout << ch;
                }
            }
        }

        H::setcolor(5);
        H::gotoxy(62,16); cout<<R"( | __||   \ | | | | |  \/  |  /_\   / __||_   _|| __|| _ \  | |/ /| || | )"; 
        H::gotoxy(62,17); cout<<R"( | _| | |) || |_| | | |\/| | / _ \  \__ \  | |  | _| |   /  | ' < | __ | )"; 
        H::gotoxy(62,18); cout<<R"( |___||___/  \___/  |_|  |_|/_/ \_\ |___/  |_|  |___||_|_\  |_|\_\|_||_| )"; 

        if(i<140){
            H::HLine(i, 26, 1, 15, 177);
            cout<<i-40<<"%";
        }
    
        H::delay(60);
    }
    system("cls");
}


int main() {
    H::DisableScreenResize();
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45);
    Title_Function();
    getch();
    return 0;
}
