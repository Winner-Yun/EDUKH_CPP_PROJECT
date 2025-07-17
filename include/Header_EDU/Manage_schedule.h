#ifndef ___SUB_MENU_SCHEDULE_CPP_HEADER__
#define ___SUB_MENU_SCHEDULE_CPP_HEADER__

#include "../Header_School/ANTHinsyOOP"
#include "CustomHeader.h"
#include "Main_menu.h"
using namespace ANTHinsyOOP;
class Sub_ScheduleDesign{
    public:

        void Main_ScheduleSubMenu();  // main schedule Call

        static void Header();
        static void Menu_Body();
        static void Footer();
        static void LoadingHeader(int id);
};

void Sub_ScheduleDesign::Main_ScheduleSubMenu(){
   int option;
    do{

        Header();
        Menu_Body();
        Footer();

        int choice = 1;
        

        do{
            H::drawBoxDoubleLineWithBG(79,11,40,1,47);
            H::drawBoxDoubleLineWithBG(79,21,40,1,47);
            H::drawBoxDoubleLineWithBG(79,31,40,1,47);

            H::setcolor(2);
            H::gotoxy(80, 13);cout << "----------[   GRADE - 10   ]----------" << endl;
            H::gotoxy(80, 12);cout << "                                      " << endl;
            H::gotoxy(80, 23);cout << "----------[   GRADE - 11   ]----------" << endl;
            H::gotoxy(80, 22);cout << "                                      " << endl;
            H::gotoxy(80, 33);cout << "----------[   GRADE - 12   ]----------" << endl;
            H::gotoxy(80, 32);cout << "                                      " << endl;

            switch (choice) {
                case 1: {
                    H::drawBoxDoubleLineWithBG(79,11,40,1,2);
                    H::setcolor(7);
                    H::gotoxy(80, 13);cout << "-[            GRADE - 10            ]-" << endl;
                    H::gotoxy(80, 12);cout << "                                      " << endl;
                    break;
                }
                case 2: {
                    H::drawBoxDoubleLineWithBG(79,21,40,1,2);
                    H::setcolor(7);
                    H::gotoxy(80, 23);cout << "-[            GRADE - 11            ]-" << endl;
                    H::gotoxy(80, 22);cout << "                                      " << endl;
                    break;
                }
                case 3: {
                    H::drawBoxDoubleLineWithBG(79,31,40,1,2);
                    H::setcolor(7);
                    H::gotoxy(80, 33);cout << "-[            GRADE - 12            ]-" << endl;
                    H::gotoxy(80, 32);cout << "                                      " << endl;
                    break;
                }

            }

            option = getch();

            choice = EdumasterCustom::ArrowKeyConTrol(3,1,choice,option);    // usage here :)
            
        }while(option != 27 && option != 13);

        if(option==27){
            H::cls();
            LoadingHeader(1);
            EdumasterCustom::LoadingPage(30,30,135,20);
            system("cls");
        }

        if (option == 13) {
                switch (choice) {
                case 1:{
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,20);
                    system("cls");
                    cout << " Handle OPTION 1 ";
                    H::cls();
                    getch();
                    break;
                }

                case 2:{
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,20);
                    H::cls();
                    cout << " Handle OPTION 2 ";
                    H::cls();
                    getch();
                    break;
                }

                case 3:{
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,20);
                    H::cls();
                    cout << " Handle OPTION 3 ";
                    H::cls();
                    getch();
                    break;
                }


            }
        }
    }while(option != 27);
    
}

void Sub_ScheduleDesign::Header(){

    H::VLine(23,7,5,6,186);//chain
    H::VLine(175,7,5,6,186);//chain

    H::drawBoxDoubleLineWithBG(3,0,194,6,10);
    H::drawBoxSingleLineWithBG(3,5,48,1,7);
    H::drawBoxSingleLineWithBG(149,5,48,1,7); 
           
    H::setcolor(10);H::gotoxy(52,2);cout<<R"(                                                                                                )";
    H::setcolor(10);H::gotoxy(52,3);cout<<R"(     ______  ______  _____ ______  ______ ________            _______ ________________________  )";
    H::setcolor(10);H::gotoxy(52,4);cout<<R"( __  ____/__  / / /_  __ \_  __ \_  ___/__  ____/          __  ____/__  /___    |_  ___/_  ___/ )";
    H::setcolor(7);H::gotoxy(52,5);cout<<R"( _  /    __  /_/ /_  / / /  / / /____ \__  __/             _  /    __  / __  /| |____ \_____ \  )";
    H::setcolor(7);H::gotoxy(52,6);cout<<R"( / /___  _  __  / / /_/ // /_/ /____/ /_  /___             / /___  _  /___  ___ |___/ /____/ /  )";
    H::setcolor(7);H::gotoxy(52,7);cout<<R"( \____/  /_/ /_/  \____/ \____/ /____/ /_____/             \____/  /_____/_/  |_/____/ /____/   )";
    H::setcolor(2);H::gotoxy(52,8);cout<<R"(________________________________________________________________________________________________)";
    


}

void Sub_ScheduleDesign::Menu_Body(){

    //left
    H::drawBoxSingleLineWithBG(3, 11, 1, 21, 10);
    H::drawBoxSingleLineWithBG(42, 11, 1, 21, 10);

    H::drawBoxSingleLineWithBG(3, 11, 40, 3, 6);
    H::setcolor(2);H::gotoxy(8,12);cout<<"------------------->>>>>>>>>>>";
    H::setcolor(2);H::gotoxy(8,13);cout<<"ASSIGN SHCEDULE FOR EACH CLASS";
    H::setcolor(2);H::gotoxy(8,14);cout<<"___________________>>>>>>>>>>>";
    H::drawBoxSingleLineWithBG(3, 29, 40, 3, 10);

    H::setcolor(6); H::gotoxy(15, 24); cout << R"(      /\   |~\ )";
    H::setcolor(6); H::gotoxy(15, 25); cout << R"(    [__]---'__] )";
    H::setcolor(6); H::gotoxy(15, 26); cout << R"(    |""|'''|""| )";
    H::setcolor(6); H::gotoxy(15, 27); cout << R"(    |  | /^\  | )";
    H::setcolor(7); H::gotoxy(15, 28); cout << R"(   _|__|_I_|__|_ )";
    H::setcolor(8); H::gotoxy(15, 29); cout << R"(  /_____________\)";

    H::setcolor(6); H::gotoxy(8, 17);  cout << R"(     \  |  /     )";
    H::setcolor(6); H::gotoxy(8, 18);  cout << R"(      .---.      )";
    H::setcolor(6); H::gotoxy(8, 19);  cout << R"(  -- (     ) --   )";
    H::setcolor(6); H::gotoxy(8, 20);  cout << R"(      '---'      )";
    H::setcolor(6); H::gotoxy(8, 21);  cout << R"(     /  |  \     )";

    H::setcolor(7); H::gotoxy(16, 19); cout << R"(      .--.    )";
    H::setcolor(7); H::gotoxy(16, 20); cout << R"(   .-(    ).  )";
    H::setcolor(7); H::gotoxy(16, 21); cout << R"(  (___.__)__) )";


    //right
    H::drawBoxSingleLineWithBG(155, 11, 1, 21, 10);
    H::drawBoxSingleLineWithBG(194, 11, 1, 21, 10);

    H::drawBoxSingleLineWithBG(155, 11, 40, 3, 6);
    H::setcolor(2);H::gotoxy(160,12);cout<<"<<<<<<<<<<<-------------------";
    H::setcolor(2);H::gotoxy(160,13);cout<<"  CHOOSE ONE CLSSS TO ASSIGN  ";
    H::setcolor(2);H::gotoxy(160,14);cout<<"<<<<<<<<<<<___________________";
    H::drawBoxSingleLineWithBG(155, 29, 40, 3, 10);

    H::setcolor(6); H::gotoxy(167, 24); cout << R"(      /\   |~\ )";
    H::setcolor(6); H::gotoxy(167, 25); cout << R"(    [__]---'__] )";
    H::setcolor(6); H::gotoxy(167, 26); cout << R"(    |""|'''|""| )";
    H::setcolor(6); H::gotoxy(167, 27); cout << R"(    |  | /^\  | )";
    H::setcolor(7); H::gotoxy(167, 28); cout << R"(   _|__|_I_|__|_ )";
    H::setcolor(8); H::gotoxy(167, 29); cout << R"(  /_____________\)";

    H::setcolor(7); H::gotoxy(157, 16);  cout << R"(       _.._   )";
    H::setcolor(7); H::gotoxy(157, 17);  cout << R"(    .' .-'`   )";
    H::setcolor(7); H::gotoxy(157, 18);  cout << R"(   /  /       )";
    H::setcolor(7); H::gotoxy(157, 19);  cout << R"(  |  |        )";
    H::setcolor(7); H::gotoxy(157, 20);  cout << R"(   \  \       )";
    H::setcolor(7); H::gotoxy(157, 21);  cout << R"(    '._'-._   )";
    H::setcolor(7); H::gotoxy(157, 22);  cout << R"(       ```    )";

    H::setcolor(7); H::gotoxy(180, 17); cout << R"(*)";
    H::setcolor(7); H::gotoxy(175, 19); cout << R"(*)";
    H::setcolor(7); H::gotoxy(190, 19); cout << R"(*)";
    H::setcolor(7); H::gotoxy(185, 20); cout << R"(*)";

}

void Sub_ScheduleDesign::Footer(){
    
    H::drawBoxDoubleLineWithBG(3,37,194,6,7);
    H::drawBoxSingleLineWithBG(3,37,55,1,2); //bottom
    H::drawBoxSingleLineWithBG(142,37,55,1,2);

    H::setcolor(2);H::gotoxy(59,36);cout<<R"(  ------------------------------------------------------------------------------  )";
    H::setcolor(2);H::gotoxy(59,37);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,38);cout<<R"(  '                  [!] USE ALL ARROWS TO SELCT THE OPTIONS                   '  )";
    H::setcolor(2);H::gotoxy(59,39);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,40);cout<<R"(  '                    USE [ESC] KEY TO BACK TO MAIN MENU                      '  )";
    H::setcolor(2);H::gotoxy(59,41);cout<<R"(  '                                                                            '  )";
    H::setcolor(2);H::gotoxy(59,42);cout<<R"(  ------------------------------------------------------------------------------  )";
}



void Sub_ScheduleDesign::LoadingHeader(int id){
    if(id == 1){
        H::setcolor(1);H::gotoxy(38,12);cout << R"( ____________________________     _______________     ____________________________     _______________________________ )";
        H::setcolor(1);H::gotoxy(38,13);cout << R"( 7  _  77     77     77  7  7     7      77     7     7        77  _  77  77     7     7        77     77     77  7  7 )";
        H::setcolor(1);H::gotoxy(38,14);cout << R"( |   __||  ___!|  ___!|   __!     !__  __!|  7  |     |  _  _  ||  _  ||  ||  _  |     |  _  _  ||  ___!|  _  ||  |  | )";
        H::setcolor(1);H::gotoxy(38,15);cout << R"( |  _  ||  __|_|  7___|     |       7  7  |  |  |     |  7  7  ||  7  ||  ||  7  |     |  7  7  ||  __|_|  7  ||  |  | )";
        H::setcolor(7);H::gotoxy(38,16);cout << R"( |  7  ||     7|     7|  7  |       |  |  |  !  |     |  |  |  ||  |  ||  ||  |  |     |  |  |  ||     7|  |  ||  !  | )";
        H::setcolor(7);H::gotoxy(38,17);cout << R"( !_____!!_____!!_____!!__!__!       !__!  !_____!     !__!__!__!!__!__!!__!!__!__!     !__!__!__!!_____!!__!__!!_____! )";
    }
    else if(id == 2){
        H::setcolor(2);H::gotoxy(48,12);cout << R"( ______________     ___________________________________________________________________                    )";
        H::setcolor(2);H::gotoxy(48,13);cout << R"( 7     77     7     7     77  _  77     77     77     77     77     77  77     77     7                    )";
        H::setcolor(2);H::gotoxy(48,14);cout << R"( |  7  ||  _  |     |  -  ||    _||  7  ||  ___!|  ___!|  ___!|  ___!|  ||  _  ||   __!                    )";
        H::setcolor(2);H::gotoxy(48,15);cout << R"( |  |  ||  7  |     |  ___!|  _ \ |  |  ||  7___|  __|_!__   7!__   7|  ||  7  ||  !  7                    )";
        H::setcolor(7);H::gotoxy(48,16);cout << R"( |  !  ||  |  |     |  7   |  7  ||  !  ||     7|     77     |7     ||  ||  |  ||     |     ____________   )";
        H::setcolor(7);H::gotoxy(48,17);cout << R"( !_____!!__!__!     !__!   !__!__!!_____!!_____!!_____!!_____!!_____!!__!!__!__!!_____!     7__77__77__7   )";
    }

}




#endif