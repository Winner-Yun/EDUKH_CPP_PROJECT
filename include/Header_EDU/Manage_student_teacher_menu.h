#ifndef ___MANAGE_STUDENT_TEACHER_MENU___
#define ___MANAGE_STUDENT_TEACHER_MENU___

#include "../Header_School/ANTHinsyOOP"
#include "CustomHeader.h"
#include "Main_menu.h"
#include "StudentManagerment.h"
#include "TeacherManagement.h"

using namespace ANTHinsyOOP;
class SubMENU_manage_stu_tech{
    public:

        void Main_SubMenuMangeStuTech();  // main schedule Call

        static void Header();
        static void Menu_Body();
        static void Footer();
        static void LoadingHeader(int id);
};

void SubMENU_manage_stu_tech::Main_SubMenuMangeStuTech(){
   int option;
   int choice = 1;
   
    do{

        Header();
        Menu_Body();
        Footer();        

        do{
            H::drawBoxDoubleLineWithBG(79,11,40,1,31);
            H::drawBoxDoubleLineWithBG(79,21,40,1,31);
            H::drawBoxDoubleLineWithBG(79,31,40,1,79);

            H::setcolor(1);
            H::gotoxy(80, 13);cout << "----------[ STUDENT MANAGE ]----------" << endl;
            H::gotoxy(80, 12);cout << "                                      " << endl;
            H::gotoxy(80, 23);cout << "----------[ TEACHER MANAGE ]----------" << endl;
            H::gotoxy(80, 22);cout << "                                      " << endl;
            H::setcolor(79);
            H::gotoxy(80, 33);cout << "----------[    <-- BACK    ]----------" << endl;
            H::gotoxy(80, 32);cout << "                                      " << endl;

            switch (choice) {
                case 1: {
                    H::drawBoxDoubleLineWithBG(79,11,40,1,1);
                    H::setcolor(7);
                    H::gotoxy(80, 13);cout << "-[          STUDENT MANAGE          ]-" << endl;
                    H::gotoxy(80, 12);cout << "                                      " << endl;
                    break;
                }
                case 2: {
                    H::drawBoxDoubleLineWithBG(79,21,40,1,1);
                    H::setcolor(7);
                    H::gotoxy(80, 23);cout << "-[          TEACHER MANAGE          ]-" << endl;
                    H::gotoxy(80, 22);cout << "                                      " << endl;
                    break;
                }
                case 3: {
                    H::drawBoxDoubleLineWithBG(79,31,40,1,4);
                    H::setcolor(7);
                    H::gotoxy(80, 33);cout << "-[    <----------- BACK             ]-" << endl;
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
                    s.Main_StudentManage();                 // student call
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,20);
                    H::cls();
                    break;
                }

                case 2:{
                    system("cls");
                    td.teacherManagement();
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,20);
                    H::cls();
                    break;
                }
                case 3:{
                    system("cls");
                    LoadingHeader(1);
                    EdumasterCustom::LoadingPage(30,30,135,20);
                    option = 27;
                    system("cls");
                    break;
                }


            }
        }
    }while(option != 27);
    
}

void SubMENU_manage_stu_tech::Header(){

    H::drawBoxDoubleLineWithBG(3,0,194,6,1);
    H::drawBoxSingleLineWithBG(3,5,48,1,7);
    H::drawBoxSingleLineWithBG(149,5,48,1,7); 
           
    H::setcolor(1);H::gotoxy(52,2);cout<<R"(                                                                                                )";
    H::setcolor(1);H::gotoxy(52,3);cout<<R"(     ______  ______  _____ ______  ______ ________       ______  ________________   ______  __  )";
    H::setcolor(1);H::gotoxy(52,4);cout<<R"( __  ____/__  / / /_  __ \_  __ \_  ___/__  ____/         ___   |/  /__  ____/__  | / /_  / / /  )";
    H::setcolor(7);H::gotoxy(52,5);cout<<R"( _  /    __  /_/ /_  / / /  / / /____ \__  __/            __  /|_/ /__  __/  __   |/ /_  / / /  )";
    H::setcolor(7);H::gotoxy(52,6);cout<<R"( / /___  _  __  / / /_/ // /_/ /____/ /_  /___            _  /  / / _  /___  _  /|  / / /_/ /   )";
    H::setcolor(7);H::gotoxy(52,7);cout<<R"( \____/  /_/ /_/  \____/ \____/ /____/ /_____/            /_/  /_/  /_____/  /_/ |_/  \____/    )";
    H::setcolor(2);H::gotoxy(52,8);cout<<R"(________________________________________________________________________________________________)";


}

void SubMENU_manage_stu_tech::Menu_Body(){
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
    
}

void SubMENU_manage_stu_tech::Footer(){
    
    H::drawBoxDoubleLineWithBG(3,37,194,6,7);
    H::drawBoxSingleLineWithBG(3,37,55,1,1); //bottom
    H::drawBoxSingleLineWithBG(142,37,55,1,1);

    H::setcolor(1);H::gotoxy(59,36);cout<<R"(  ------------------------------------------------------------------------------  )";
    H::setcolor(1);H::gotoxy(59,37);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,38);cout<<R"(  '                 [!] USE ALL ARROWS TO SELECT THE OPTIONS                   '  )";
    H::setcolor(1);H::gotoxy(59,39);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,40);cout<<R"(  '                     <------------------------------->                      '  )";
    H::setcolor(1);H::gotoxy(59,41);cout<<R"(  '                                                                            '  )";
    H::setcolor(1);H::gotoxy(59,42);cout<<R"(  ------------------------------------------------------------------------------  )";
}



void SubMENU_manage_stu_tech::LoadingHeader(int id){
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