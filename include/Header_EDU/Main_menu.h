#ifndef ___MAIN_MENU_CPP_HEADER__
#define ___MAIN_MENU_CPP_HEADER__

#include "../Header_School/ANTHinsyOOP"
#include "CustomHeader.h"
#include "Manage_schedule.h"
#include "Manage_student_teacher_menu.h"
#include <chrono>
#include <ctime>
#include <thread>
#include "../AssignClass/AssignClassDemo.h"

using namespace ANTHinsyOOP;

class Edu_Main_Menu{
    public:
        void Main_menu(); // main menu
        static void LoadingHeader(int id);
        static void designPage(); // sub design
        static void ourProfile();
        static void littleSign(int x , int y , int c);
        
};
void Edu_Main_Menu::littleSign(int x , int y , int c){
	H::VLine(x,y,1,c,222);
}
void Edu_Main_Menu::ourProfile(){
	H::HLine(55,1,100,1,219);
	H::HLine(50,8,100,1,219);
	
	H::drawBoxDoubleLine(10,4,30,1,2);
	H::drawBoxDoubleLine(162,4,30,1,2);
	H::gotoxy(11,5);
	H::setcolor(15); 
    cout << "[!] PRESS [";
    H::setcolor(10); 
    cout << "ESC";
    H::setcolor(15);
    cout << "] FOR ";
    H::setcolor(10);
    cout << "EXIT";
    H::setcolor(15);
    cout << "..!";
    H::setcolor(15);
    
    H::gotoxy(163,5);
	H::setcolor(15); 
    cout << "[!] PRESS [";
    H::setcolor(10); 
    cout << "ESC";
    H::setcolor(15);
    cout << "] FOR ";
    H::setcolor(10);
    cout << "EXIT";
    H::setcolor(15);
    cout << "..!";
    H::setcolor(15);
	
	H::setcolor(3); H::gotoxy(81, 1); cout << R"(    ___    ____  ____  __  ________   __  _______)";
	H::setcolor(4); H::gotoxy(81, 2); cout << R"(   /   |  / __ )/ __ \/ / / /_  __/  / / / / ___/ )";
	H::setcolor(5); H::gotoxy(81, 3); cout << R"(  / /| | / __  / / / / / / / / /    / / / /\__ \  )";
	H::setcolor(3); H::gotoxy(81, 4); cout << R"( / ___ |/ /_/ / /_/ / /_/ / / /    / /_/ /___/ /  )";
	H::setcolor(4); H::gotoxy(81, 5); cout << R"(/_/  |_/_____/\____/\____/ /_/     \____//____/   )";
	H::setcolor(5); H::gotoxy(81, 6); cout << R"(                                                  )";
		
	for(int i = 0; i < 5; i++) {
	    littleSign(50 + i, 5 - i,4);
	}
	for(int i = 0; i < 5; i++) {
	    littleSign(151 + i, 5 - i,4);
	}
	
	
	H::foreColor(6); H::gotoxy(70,10);cout<<">>>>> Professor of C++ Object-Oriented Design <<<<<<";
	H::drawBoxDoubleLineWithBG(80,12,30,1,196);
	H::gotoxy(82,13);H::foreColor(199);cout<<"TEACHER NAME :UON HINSY";
	
	H::VLine(94,14,3,7,186);
	
	H::drawBoxDoubleLineWithBG(80,17,30,1,196);
	H::gotoxy(82,18);H::foreColor(199);cout<<"MENTER NAME :RUN LIHOU";
	H::VLine(94,19,2,7,186);
	H::HLine(15,22,170,7,223);
	
	//member
	H::VLine(16,21,10,7,186);
	H::drawBoxDoubleLineWithBG(1,32,28,1,153);
	H::gotoxy(5,33);H::foreColor(159);cout<<"LEADER :YUN WINNER";
	
	H::VLine(76,21,10,7,186);
	H::drawBoxDoubleLineWithBG(59,32,30,1,153);
	H::gotoxy(65,33);H::foreColor(159);cout<<"MEMBER :RY KIMCHHAY";
	
	H::VLine(136,21,10,7,186);
	H::drawBoxDoubleLineWithBG(120,32,30,1,153);
	H::gotoxy(125,33);H::foreColor(159);cout<<"MEMBER :VANNA NICH";
	
	H::VLine(185,21,10,7,186);
	H::drawBoxDoubleLineWithBG(170,32,28,1,153);
	H::gotoxy(175,33);H::foreColor(159);cout<<"MEMBER :SLESS ROFATH";
		
	int x = 0, y = 37;
	
	H::setcolor(3); H::gotoxy(x + 25, y);     cout << R"(          \    |    /                 \    |    /                 \    |    /                 \    |    /                 \    |    /            )";
	H::setcolor(3); H::gotoxy(x + 25, y + 1); cout << R"(        --- (  *  )    ---     ---      (  *  )    ---     ---      (  *  )    ---     ---      (  *  )    ---     ---      (  *  )    ---      )";
	H::setcolor(3); H::gotoxy(x + 25, y + 2); cout << R"(          /    |    \                 /    |    \                 /    |    \                 /    |    \                 /    |    \            )";
		
	H::setcolor(6); H::gotoxy(x + 3, y + 3); cout << R"(    +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+   )";
	H::setcolor(6); H::gotoxy(x + 3, y + 4); cout << R"(    |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |  |  ######  |    )";
	H::setcolor(6); H::gotoxy(x + 3, y + 5); cout << R"(    +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+  +----------+   )";
	
	H::setcolor(2); H::gotoxy(x + 3, y + 6); cout << R"(      /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\        /\/\/\   )";
	H::setcolor(2); H::gotoxy(x + 3, y + 7); cout << R"(     /      \      /      \      /      \      /      \      /      \      /      \      /      \      /      \      /      \      /      \      /      \      /      \      /      \ )";


	int baseY = 9;     
	int startX = 0; 
	int endX = 20;    
	int delayTime = 50; 

	for (int x = startX; x <= endX; ++x) {
		H::setcolor(1); H::gotoxy(x + 13, baseY);     cout << R"(       \ ^ / )"; 
		H::setcolor(1); H::gotoxy(x + 13, baseY + 1); cout << R"(      -- @ -- )"; 
		H::setcolor(1); H::gotoxy(x + 13, baseY + 2); cout << R"(       / v \ )"; 
		H::setcolor(1); H::gotoxy(x + 3, baseY + 3); cout << R"(  ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~ )"; 
		H::setcolor(1); H::gotoxy(x + 3, baseY + 4); cout << R"( ///\\\///\\\///\\\///\\\///\\\///\\\///\\\ )"; 
		H::setcolor(1); H::gotoxy(x + 3, baseY + 5); cout << R"(  |=|    |=|    |=|    |=|    |=|    |=| )"; 
		H::setcolor(1); H::gotoxy(x + 3, baseY + 6); cout << R"(  /_\    /_\    /_\    /_\    /_\    /_\ )";
		
		H::setcolor(1); H::gotoxy(x + 132, baseY);     cout << R"(       \ ^ / )"; 
		H::setcolor(1); H::gotoxy(x + 132, baseY + 1); cout << R"(      -- @ -- )"; 
		H::setcolor(1); H::gotoxy(x + 132, baseY + 2); cout << R"(       / v \ )"; 
		H::setcolor(1); H::gotoxy(x + 123, baseY + 3); cout << R"( ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~ )"; 
		H::setcolor(1); H::gotoxy(x + 123, baseY + 4); cout << R"( ///\\\///\\\///\\\///\\\///\\\///\\\///\\\ )"; 
		H::setcolor(1); H::gotoxy(x + 123, baseY + 5); cout << R"(  |=|    |=|    |=|    |=|    |=|    |=| )"; 
		H::setcolor(1); H::gotoxy(x + 123, baseY + 6); cout << R"(  /_\    /_\    /_\    /_\    /_\    /_\ )";

	
	    H::delay(delayTime);
	}
	
	for (int x = endX; x >= startX; --x) {
		H::setcolor(6); H::gotoxy(x + 13, baseY);     cout << R"(       \ ^ / )"; 
		H::setcolor(6); H::gotoxy(x + 13, baseY + 1); cout << R"(      -- @ -- )"; 
		H::setcolor(6); H::gotoxy(x + 13, baseY + 2); cout << R"(       / v \ )"; 
		H::setcolor(6); H::gotoxy(x + 3, baseY + 3); cout << R"( ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~ )"; 
		H::setcolor(6); H::gotoxy(x + 3, baseY + 4); cout << R"( ///\\\///\\\///\\\///\\\///\\\///\\\///\\\ )"; 
		H::setcolor(6); H::gotoxy(x + 3, baseY + 5); cout << R"(  |=|    |=|    |=|    |=|    |=|    |=| )"; 
		H::setcolor(6); H::gotoxy(x + 3, baseY + 6); cout << R"(  /_\    /_\    /_\    /_\    /_\    /_\ )";
		
		H::setcolor(6); H::gotoxy(x + 132, baseY);     cout << R"(       \ ^ / )"; 
		H::setcolor(6); H::gotoxy(x + 132, baseY + 1); cout << R"(      -- @ -- )"; 
		H::setcolor(6); H::gotoxy(x + 132, baseY + 2); cout << R"(       / v \ )"; 
		H::setcolor(6); H::gotoxy(x + 123, baseY + 3); cout << R"( ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~  ~~~~~ )"; 
		H::setcolor(6); H::gotoxy(x + 123, baseY + 4); cout << R"( ///\\\///\\\///\\\///\\\///\\\///\\\///\\\ )"; 
		H::setcolor(6); H::gotoxy(x + 123, baseY + 5); cout << R"(  |=|    |=|    |=|    |=|    |=|    |=| )"; 
		H::setcolor(6); H::gotoxy(x + 123, baseY + 6); cout << R"(  /_\    /_\    /_\    /_\    /_\    /_\ )";
		
	    H::delay(delayTime);
	}
	H::gotoxy(5,18); 
	H::setcolor(7);
	cout << "TO VIEW A COMPREHENSIVE SUMMARY AND DETAILED INFORMATION ";
	
	H::gotoxy(125,18); 
	cout << "PLEASE ";
	
	H::foreColor(2); 
	cout << "PRESS ";
	
	H::foreColor(7); 
	cout << "THE NUMBER ";
	
	H::foreColor(2);
	cout << "1 "; 

	H::setcolor(6); 
	cout << "ACCESS ";
	
	H::setcolor(2);
	cout << "INFORMATION";
	
	H::setcolor(7); 
	
		char choice=getch();

    switch (choice) {
        case '1':
			system("start ../Website/htmlAboutUs/index.html"); 
            break;
       
    }
    H::cls();
}

void Edu_Main_Menu::Main_menu(){
    bool work = true;
    int j = 0;
    int option;
    H::setcursor(false,0);
    
    while (work){
        designPage();  // call design

    

    clock_t escStart = 0;
    bool escHeld = false;

    do {
        H::drawBoxDoubleLineWithBG(59,11,40,1,31);
        H::drawBoxDoubleLineWithBG(99,16,40,1,31);
        H::drawBoxDoubleLineWithBG(99,26,40,1,31);
        H::drawBoxDoubleLineWithBG(59,31,40,1,31);

        //Stick

        H::HLine(100,12,40,1,205);
        H::HLine(58,17,40,1,205);
        H::HLine(58,22,82,7,178);
        H::setcolor(7);H::gotoxy(71,22);cout<<"-[                                                   ]-";
        H::HLine(58,27,40,1,205); 
        H::HLine(100,32,40,1,205);

        H::setcolor(1);

        H::gotoxy(60, 13);cout << "[   I - MANAGE TEACHER AND STUDENT   ]" << endl;
        H::gotoxy(60, 12);cout << "                                      " << endl;

        
        H::gotoxy(100, 17);cout << "                                      " << endl;
        H::gotoxy(100, 18);cout << "[ II - ASSIGN TEACHER TO EACH CLASS  ]" << endl;


        H::gotoxy(100, 27);cout << "                                      " << endl;
        H::gotoxy(100, 28);cout << "[ III CREATE SCHEDULE FOR EACH CLASS ]" << endl;

        H::gotoxy(60, 32);cout << "                                      " << endl;
        H::gotoxy(60, 33);cout << "[       IV - ABOUT US / SCHOOL       ]" << endl;

        if (j == 0) {
            H::HLine(100,12,40,7,205);
            H::drawBoxDoubleLineWithBG(59,11,40,1,2);
            H::setcolor(7);
            H::gotoxy(60, 13);cout << "[   I - MANAGE TEACHER AND STUDENT   ]" << endl;
            H::gotoxy(60, 12);cout << "--------------------------------------" << endl;
        }
        if (j == 1) {
            H::HLine(58,17,40,7,205);
            H::drawBoxDoubleLineWithBG(99,16,40,1,2);
            H::setcolor(7);
            H::gotoxy(100, 17);cout << "--------------------------------------" << endl;
            H::gotoxy(100, 18);cout << "[ II - ASSIGN TEACHER TO EACH CLASS  ]" << endl;
        }
        if (j == 2) {
            H::HLine(58,27,40,7,205);
            H::drawBoxDoubleLineWithBG(99,26,40,1,2);
            H::setcolor(7);
            H::gotoxy(100, 27);cout << "--------------------------------------" << endl;
            H::gotoxy(100, 28);cout << "[ III CREATE SCHEDULE FOR EACH CLASS ]" << endl;
        }
        if (j == 3) {
            H::HLine(100,32,40,7,205);
            H::drawBoxDoubleLineWithBG(59,31,40,1,2);
            H::setcolor(7);
            H::gotoxy(60, 32);cout << "--------------------------------------" << endl;
            H::gotoxy(60, 33);cout << "[       IV - ABOUT US / SCHOOL       ]" << endl;
        }

        option = getch();
        switch (option) {
            case 80: j++; if (j > 3) j = 0; break;
            case 72: j--; if (j < 0) j = 3; break;
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
            j = 4; 
            break;
        }

    } while (option != 13);

    switch (j) {
        case 0:{
            system("cls");
            LoadingHeader(2);
            EdumasterCustom::LoadingPage(30,30,135,20);
            system("cls");
            SubMENU_manage_stu_tech s;
            s.Main_SubMenuMangeStuTech();
            break;
        }

        case 1:{
            system("cls");
            LoadingHeader(2);
            EdumasterCustom::LoadingPage(30,30,135,20);
            H::cls();
		    int result = AssignClassDemo::AssignClassMenu();
		    if (result == 0) {
		        j = 0; 
		    }
            H::setcolor(7);
            H::cls();      
            LoadingHeader(3);
            EdumasterCustom::LoadingPage(30,30,135,20);
            H::cls();
            break;
        }

        case 2:{
                system("cls");
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30,30,135,20);
                H::cls();
                Sub_ScheduleDesign subMenu;
                subMenu.Main_ScheduleSubMenu();  
            break;
        }

        case 3:{
            system("cls");
            LoadingHeader(2);
            EdumasterCustom::LoadingPage(30,30,135,20);
            H::cls();
            ourProfile();
            H::cls();      
            LoadingHeader(3);
            EdumasterCustom::LoadingPage(30,30,135,20);
            H::cls();
            break;
        }
        
        case 4:{
            work = false;
            break;
        }

    }
    }
    
    //exit loop

    system("cls");
    LoadingHeader(1);
    EdumasterCustom::LoadingPage(30,30,135,20);
    H::cls();

}


void Edu_Main_Menu::designPage(){

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

    H::drawBoxDoubleLineWithBG(142,1,54,2,2);
    H::setcolor(2);H::gotoxy(145,2);cout<<"USER: ";
    H::setcolor(4);H::gotoxy(153,2);cout<<"Admin";
    H::setcolor(2);H::gotoxy(161,2);cout<<"|";
    H::setcolor(2);H::gotoxy(165,2);cout<<"BY: ";
    H::setcolor(3);H::gotoxy(170,2);cout<<"EDU MASTER KH";
    H::setcolor(2);H::gotoxy(185,2);cout<<"|";
    H::setcolor(7);H::gotoxy(188,2);cout<<"2025";
    H::setcolor(7);H::gotoxy(145,3);cout<<"________________________________________________";

    

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

void Edu_Main_Menu::LoadingHeader(int id){
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
    else if(id == 3){
        H::setcolor(1);H::gotoxy(38,12);cout << R"( ____________________________     _______________     ____________________________     _______________________________ )";
        H::setcolor(1);H::gotoxy(38,13);cout << R"( 7  _  77     77     77  7  7     7      77     7     7        77  _  77  77     7     7        77     77     77  7  7 )";
        H::setcolor(1);H::gotoxy(38,14);cout << R"( |   __||  ___!|  ___!|   __!     !__  __!|  7  |     |  _  _  ||  _  ||  ||  _  |     |  _  _  ||  ___!|  _  ||  |  | )";
        H::setcolor(1);H::gotoxy(38,15);cout << R"( |  _  ||  __|_|  7___|     |       7  7  |  |  |     |  7  7  ||  7  ||  ||  7  |     |  7  7  ||  __|_|  7  ||  |  | )";
        H::setcolor(7);H::gotoxy(38,16);cout << R"( |  7  ||     7|     7|  7  |       |  |  |  !  |     |  |  |  ||  |  ||  ||  |  |     |  |  |  ||     7|  |  ||  !  | )";
        H::setcolor(7);H::gotoxy(38,17);cout << R"( !_____!!_____!!_____!!__!__!       !__!  !_____!     !__!__!__!!__!__!!__!!__!__!     !__!__!__!!_____!!__!__!!_____! )";
    }

}

#endif