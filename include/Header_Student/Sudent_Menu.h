#ifndef __EDU_STUDENT_MAIN_MENU__
#define __EDU_STUDENT_MAIN_MENU__
#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/CustomHeader.h"
#include "../Header_EDU/Login_Form.h"
#include "../Header_EDU/Main_menu.h"
#include "DisplaySchedule.h"
#include "Seft_Schedule.h"
#include "DisplayViewHomeWork.h"

class Student_MainMenu{

public:
    static void Main(const char* email);
    static void Header(const char* email);
    static void Menu();
    static void Footer();
    static void ReadData(const char* email);
    static void drawTime(int x, int y);
    static void LoadingHeader(int id);
};

char studentName[40] = "Unknown";
char studentID[15] = "Unknown";
char grade[5] = "None";

void Student_MainMenu::Main(const char* email){
    int option;
    int choice = 1;
    H::setcursor(false,0);
    do{

        Header(email);
        Footer();        

        do{
            H::drawBoxDoubleLineWithBG(43,17,40,1,31);
            H::drawBoxDoubleLineWithBG(43,21,40,1,31);
            H::drawBoxDoubleLineWithBG(43,25,40,1,31);
            H::drawBoxDoubleLineWithBG(43,29,40,1,31);
            H::drawBoxDoubleLineWithBG(43,33,40,1,31);
            H::drawBoxDoubleLineWithBG(43,37,40,1,31);
            H::drawBoxDoubleLineWithBG(108,37,40,1,79);

            H::setcolor(7);
            H::gotoxy(43, 18);cout << "-------[         PROFILE        ]------" << endl;
            H::gotoxy(50, 17);cout << "--------------------------" << endl;
            H::gotoxy(50, 19);cout << "--------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(43, 22);cout << "-------[  VIEW  CLASS SCHEDULE  ]------" << endl;
            H::gotoxy(50, 21);cout << "--------------------------" << endl;
            H::gotoxy(50, 23);cout << "--------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(43, 26);cout << "-------[     VIEW  HOMEWORK     ]------" << endl;
            H::gotoxy(50, 25);cout << "--------------------------" << endl;
            H::gotoxy(50, 27);cout << "--------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(43, 30);cout << "-------[    VIEW  /  DO QUIZ    ]------" << endl;
            H::gotoxy(50, 29);cout << "--------------------------" << endl;
            H::gotoxy(50, 31);cout << "--------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(43, 34);cout << "-------[  CREATE SELF SCHEDULE  ]------" << endl;
            H::gotoxy(50, 33);cout << "--------------------------" << endl;
            H::gotoxy(50, 35);cout << "--------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(44, 38);cout << "---------[ ABOUT US/SCHOOL ]----------" << endl;
            H::gotoxy(53, 37);cout << "-------------------" << endl;
            H::gotoxy(53, 39);cout << "-------------------" << endl;

            H::setcolor(7);
            H::gotoxy(109, 38);cout << "----------[     LOGOUT     ]----------" << endl;
            H::setcolor(4);
            H::gotoxy(119, 37);cout << R"(\----------------/)"<< endl;
            H::gotoxy(119, 39);cout << "__________________" << endl;
           

            switch (choice) {
                case 1: {
                    H::drawBoxDoubleLineWithBG(43,17,40,1,249);
                    H::setcolor(1);
                    H::gotoxy(43, 18);cout << "-------[         PROFILE        ]------" << endl;
                    H::gotoxy(50, 17);cout << "--------------------------" << endl;
                    H::gotoxy(50, 19);cout << "--------------------------" << endl;
                    drawTime(160, 18);
                    break;
                }
                case 2: {
                    H::drawBoxDoubleLineWithBG(43,21,40,1,249);
                    H::setcolor(1);
                    H::gotoxy(43, 22);cout << "-------[  VIEW  CLASS SCHEDULE  ]------" << endl;
                    H::gotoxy(50, 21);cout << "--------------------------" << endl;
                    H::gotoxy(50, 23);cout << "--------------------------" << endl;
                    drawTime(160, 18);
                    break;
                }
                case 3: {
                    H::drawBoxDoubleLineWithBG(43,25,40,1,249);
                    H::setcolor(1);
                    H::gotoxy(43, 26);cout << "-------[     VIEW  HOMEWORK     ]------" << endl;
                    H::gotoxy(50, 25);cout << "--------------------------" << endl;
                    H::gotoxy(50, 27);cout << "--------------------------" << endl;
                    drawTime(160, 18);
                    break;
                }
                case 4: {
                    H::drawBoxDoubleLineWithBG(43,29,40,1,249);
                    H::setcolor(1);
                    H::gotoxy(43, 30);cout << "-------[    VIEW  /  DO QUIZ    ]------" << endl;
                    H::gotoxy(50, 29);cout << "--------------------------" << endl;
                    H::gotoxy(50, 31);cout << "--------------------------" << endl;
                    drawTime(160, 18);
                    break;
                }
                case 5: {
                    H::drawBoxDoubleLineWithBG(43,33,40,1,249);;
                    H::setcolor(1);
                    H::gotoxy(43, 34);cout << "-------[  CREATE SELF SCHEDULE  ]------" << endl;
                    H::gotoxy(50, 33);cout << "--------------------------" << endl;
                    H::gotoxy(50, 35);cout << "--------------------------" << endl;
                    drawTime(160, 18);
                    break;
                }
                case 6: {
                    H::drawBoxDoubleLineWithBG(43,37,40,1,249);
                    H::setcolor(1);
                    H::gotoxy(44, 38);cout << "---------[ ABOUT US/SCHOOL ]----------" << endl;
                    H::gotoxy(53, 37);cout << "-------------------" << endl;
                    H::gotoxy(53, 39);cout << "-------------------" << endl;
                    drawTime(160, 18);
                    break;
                }
                case 7: {
                    H::drawBoxDoubleLineWithBG(108,37,40,1,252);
                    H::setcolor(4);
                    H::gotoxy(109, 38);cout << "----------[     LOGOUT     ]----------" << endl;
                    H::setcolor(4);
                    H::gotoxy(119, 37);cout << R"(\----------------/)"<< endl;
                    H::gotoxy(119, 39);cout << "__________________" << endl;
                    drawTime(160, 18);
                    break;
                }

            }

            option = getch();

            choice = EdumasterCustom::ArrowKeyConTrol(7,1,choice,option);    // usage here :)
            
        }while(option != 27 && option != 13);

        if (option == 13) {
                switch (choice) {
                case 1:{
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                   
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }

                case 2:{
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();
                    DisplaySchedule::DesignMain(grade);
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();
                    break;
                }

                case 3:{
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();

                   ViewHomeWork::ViewHomeMain(grade);

                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }
                case 4:{
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();

                   

                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }
                case 5:{
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();

                   Schedule_Management_Seft::DesignMain(studentID);
                    
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }
                case 6:{
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();

                    Edu_Main_Menu::MainAboutUs();
                    
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }
                case 7:{
                    if (MessageBoxA(NULL, "Do you want to Logout?", "Confirmation", MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
                        {
                            H::setcolor(7);
                            system("cls");
                            option = 0;
                            LoadingHeader(1);
                            EdumasterCustom::LoadingPage(30, 30, 135, 5);
                            H::cls();
                        }
                        break;
                }


            }
        }
    }while(option != 0);
}

void Student_MainMenu::drawTime(int x, int y) {
    time_t now = time(0);
    tm* local = localtime(&now);

    int hour = local->tm_hour;
    int minute = local->tm_min;
    string period = (hour >= 12) ? "PM " : "AM";

    int hour12 = hour % 12;
    if (hour12 == 0) hour12 = 12;

    H::setcolor(95);
    H::gotoxy(x, y);
    if (hour12 < 10){
        cout<<" 0";
        cout << hour12 << ":";
    }
    else{
        cout <<" "<< hour12 << ":";
    }
    if (minute < 10) cout << "0";
    cout << minute << " " << period << " ";
}


void Student_MainMenu::Header(const char* email){

    H::VLine(20,0,43,6,221);
    H::VLine(180,0,43,3,221);

    //top banner
    H::drawBoxSingleLineWithBG(4,0,192,2,1);

    //bottom banner
    H::drawBoxSingleLineWithBG(4,41,192,2,2);

    H::HLine(30,15,67,7,220);
    H::VLine(34,15,25,7,221);
    H::VLine(94,15,20,7,221);

    H::VLine(48,15,25,7,221);
    H::VLine(80,15,25,7,221);

    H::HLine(90,35,7,7,220);

    H::setcolor(7);H::gotoxy(86,38);cout<<"------------------>";


    H::setcolor(3);H::gotoxy(0,6);cout<<R"(   _ _         _ _    )";
    H::setcolor(3);H::gotoxy(0,7);cout<<R"(  ( ' )  _ _  ( ' )   )";
    H::setcolor(3);H::gotoxy(0,8);cout<<R"( (_{;}_)( ' )(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,9);cout<<R"(  (_,_)(_{;}_)(_,_)   )";
    H::setcolor(3);H::gotoxy(0,10);cout<<R"(        (_,_)         )";
    H::setcolor(3);H::gotoxy(0,11);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,12);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,13);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,14);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,15);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,16);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,17);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,18);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,19);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,20);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,21);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,22);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,23);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,24);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,25);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,26);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,27);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,28);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,29);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,30);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,31);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,32);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,33);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,34);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,35);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,36);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,37);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,38);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,39);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,40);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,11);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,12);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,13);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,14);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,15);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(0,11);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(0,12);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(0,13);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(0,14);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(0,15);cout<<R"(         (_,_)   )";

    H::setcolor(3);H::gotoxy(178,6);cout<<R"(   _ _         _ _    )";
    H::setcolor(3);H::gotoxy(178,7);cout<<R"(  ( ' )  _ _  ( ' )   )";
    H::setcolor(3);H::gotoxy(178,8);cout<<R"( (_{;}_)( ' )(_{;}_)  )";
    H::setcolor(3);H::gotoxy(178,9);cout<<R"(  (_,_)(_{;}_)(_,_)   )";
    H::setcolor(3);H::gotoxy(178,10);cout<<R"(        (_,_)         )";
    H::setcolor(3);H::gotoxy(182,11);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,12);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,13);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,14);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,15);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,16);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,17);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,18);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,19);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,20);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,21);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,22);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,23);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,24);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,25);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,26);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,27);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,28);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,29);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,30);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,31);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,32);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,33);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,34);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,35);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,36);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,37);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,38);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,39);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,40);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,11);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,12);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,13);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,14);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,15);cout<<R"(         (_,_)   )";
    H::setcolor(3);H::gotoxy(182,11);cout<<R"(    _ _          )";
    H::setcolor(3);H::gotoxy(182,12);cout<<R"(   ( ' )  _ _    )";
    H::setcolor(3);H::gotoxy(182,13);cout<<R"(  (_{;}_)( ' )   )";
    H::setcolor(3);H::gotoxy(182,14);cout<<R"(   (_,_)(_{;}_)  )";
    H::setcolor(3);H::gotoxy(182,15);cout<<R"(         (_,_)   )";
                        
                          

   

    //style
    system("chcp 65001 > nul");

    H::setcolor(6);H::gotoxy(3,1);cout<<R"( ███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗ )";
    H::setcolor(7);H::gotoxy(3,2);cout<<R"( ╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝ )";
    H::setcolor(3);H::gotoxy(3,42);cout<<R"( ███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗███████╗ )";
    H::setcolor(7);H::gotoxy(3,43);cout<<R"( ╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝ )";



    
    H::setcolor(3);H::gotoxy(20,4);cout<<R"(                 .--.    )";
    H::setcolor(3);H::gotoxy(20,5);cout<<R"(                 / ,-'   )";
    H::setcolor(3);H::gotoxy(20,6);cout<<R"(                /_/      )";
    H::setcolor(3);H::gotoxy(20,7);cout<<R"(  _ _    _ _  _( )_       )";        
    H::setcolor(3);H::gotoxy(20,8);cout<<R"( ( ' )--( ' )(_ o _)     )";        
    H::setcolor(3);H::gotoxy(20,9);cout<<R"( (_{;}_)(_{;}_)(_,_)     )"; 
    H::setcolor(3);H::gotoxy(20,10);cout<<R"( (_,_)--(_,_)  \ \       )";
    H::setcolor(3);H::gotoxy(20,11);cout<<R"(                \ `-.   )"; 
    H::setcolor(3);H::gotoxy(20,12);cout<<R"(                 `--'    )";

    
    H::setcolor(3);H::gotoxy(156,4);cout<<R"( .--.                  )";
    H::setcolor(3);H::gotoxy(156,5);cout<<R"( `-. \                 )";
    H::setcolor(3);H::gotoxy(156,6);cout<<R"(    \_\                )";
    H::setcolor(3);H::gotoxy(156,7);cout<<R"(   _( )_  _ _    _ _   )";
    H::setcolor(3);H::gotoxy(156,8);cout<<R"(  (_ o _)( ' )--( ' )  )";
    H::setcolor(3);H::gotoxy(156,9);cout<<R"(   (_,_)(_{;}_)(_{;}_) )";
    H::setcolor(3);H::gotoxy(156,10);cout<<R"(    / /  (_,_)--(_,_)  )";
    H::setcolor(3);H::gotoxy(156,11);cout<<R"( .-' /                 )";
    H::setcolor(3);H::gotoxy(156,12);cout<<R"( `--'                  )";
                      

    H::setcolor(6);H::gotoxy(48,5);cout<<R"(  ▄▄▄▄███▄▄▄▄      ▄████████  ▄█  ███▄▄▄▄           ▄▄▄▄███▄▄▄▄      ▄████████ ███▄▄▄▄    ███     █▄  )";
    H::setcolor(6);H::gotoxy(48,6);cout<<R"( ▄██▀▀▀███▀▀▀██▄   ███    ███ ███  ███▀▀▀██▄       ▄██▀▀▀███▀▀▀██▄   ███    ███ ███▀▀▀██▄ ███    ███  )";
    H::setcolor(6);H::gotoxy(48,7);cout<<R"( ███   ███   ███   ███    ███ ███▌ ███   ███       ███   ███   ███   ███    █▀  ███   ███ ███    ███  )";
    H::setcolor(6);H::gotoxy(48,8);cout<<R"( ███   ███   ███   ███    ███ ███▌ ███   ███       ███   ███   ███  ▄███▄▄▄     ███   ███ ███    ███  )";
    H::setcolor(6);H::gotoxy(48,9);cout<<R"( ███   ███   ███ ▀███████████ ███▌ ███   ███       ███   ███   ███ ▀▀███▀▀▀     ███   ███ ███    ███  )";
    H::setcolor(6);H::gotoxy(48,10);cout<<R"( ███   ███   ███   ███    ███ ███  ███   ███       ███   ███   ███   ███    █▄  ███   ███ ███    ███  )";
    H::setcolor(6);H::gotoxy(48,11);cout<<R"( ███   ███   ███   ███    ███ ███  ███   ███       ███   ███   ███   ███    ███ ███   ███ ███    ███  )";
    H::setcolor(3);H::gotoxy(48,12);cout<<R"(  ▀█   ███   █▀    ███    █▀  █▀    ▀█   █▀         ▀█   ███   █▀    ██████████  ▀█   █▀  ████████▀   )";

    system("chcp 437 >nul");

    H::HLine(20,14,79,3,198);
    H::HLine(99,14,79,6,198);

    H::drawBoxSingleLine(108,17,66,1,7);
    H::drawBoxSingleLine(108,21,66,5,7);
    H::setcolor(7);H::gotoxy(110,23);cout<<"PRESS ~             ~ ARROWS TO GO UP AND DOWN.";
    H::setcolor(111);H::gotoxy(118 ,23);cout<<"UP AND DOWN";
    H::setcolor(7);H::gotoxy(110,25);cout<<"PRESS ~                ~ ARROWS TO GO LEFT AND RIGH.";
    H::setcolor(63);H::gotoxy(118 ,25);cout<<"LEFT AND RIGHT";
    H::drawBoxSingleLine(108,29,66,3,7);
    H::setcolor(7);H::gotoxy(108,31);cout<<" DEVELOPED  BY:           ,            ,            ,             ";
    H::setcolor(111);H::gotoxy(124,31);cout<<"YUN WINNER";
    H::setcolor(31);H::gotoxy(136,31);cout<<"RY KIMCHHAY";
    H::setcolor(223);H::gotoxy(149,31);cout<<"VANNA NICHH";
    H::setcolor(47);H::gotoxy(162,31);cout<<"SLES ROFATH";


    ReadData(email);


}

void Student_MainMenu::ReadData(const char* email){
    

    ifstream file("../data/Student_Data.bin", ios::binary);
    if (!file) {
        cout << "Failed to open file.\n";
    }

    Student_form s;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student_form))) {
        if (strcmp(s.email, email) == 0) {
            strcpy(studentName , s.name);
            strcpy(studentID , s.id);
            strcpy(grade , s.grade);
        }
    }
    H::setcolor(7);
    H::gotoxy(110, 18);
    cout << "HELLO....! :                        ID :";

    char upperName[40];
    strcpy(upperName, studentName);
    for (int i = 0; upperName[i]; ++i) {
        upperName[i] = toupper(static_cast<unsigned char>(upperName[i]));
    }

    H::setcolor(2);
    int nameX = 121;
    H::gotoxy(nameX, 18);
    cout << upperName;

    int nameLength = strlen(upperName);
    int idX = nameX + nameLength + 19;

    H::setcolor(3);
    H::gotoxy(idX, 18);
    cout <<" ~ "<< studentID;

}

void Student_MainMenu::Footer(){
 
}
  
void Student_MainMenu::LoadingHeader(int id){
    if(id == 1){
         H::setcolor(4);H::gotoxy(70,16);cout << R"( ____   ____________________________________              )";
         H::setcolor(4);H::gotoxy(70,17);cout << R"( 7  7   7     77     77     77  7  77      7              )";
         H::setcolor(4);H::gotoxy(70,18);cout << R"( |  |   |  7  ||   __!|  7  ||  |  |!__  __!              )";
         H::setcolor(4);H::gotoxy(70,19);cout << R"( |  !___|  |  ||  !  7|  |  ||  |  |  7  7                )";
         H::setcolor(7);H::gotoxy(70,20);cout << R"( |     7|  !  ||     ||  !  ||  !  |  |  |  ____________  )";
         H::setcolor(7);H::gotoxy(70,21);cout << R"( !_____!!_____!!_____!!_____!!_____!  !__!  7__77__77__7  )";
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