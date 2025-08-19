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
        static void MainProfile();
		static void MainAboutUs();
        static void TeamProfile();
        static void LetterFromUs();
        static void LittleSign(int x, int y, int c);
        static void VN(const string &str);
        
};

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
            EdumasterCustom::LoadingPage(30,30,135,5);
            system("cls");
            SubMENU_manage_stu_tech s;
            s.Main_SubMenuMangeStuTech();
            break;
        }

        case 1:{
            system("cls");
            LoadingHeader(2);
            EdumasterCustom::LoadingPage(30,30,135,5);
            H::cls();
		    int result = AssignClassDemo::AssignClassMenu();
		    if (result == 0) {
		        j = 0; 
		    }
            H::setcolor(7);
            H::cls();      
            LoadingHeader(3);
            EdumasterCustom::LoadingPage(30,30,135,5);
            H::cls();
            break;
        }

        case 2:{
                system("cls");
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30,30,135,5);
                H::cls();
                Sub_ScheduleDesign subMenu;
                subMenu.Main_ScheduleSubMenu();  
            break;
        }

        case 3:{
            system("cls");
            LoadingHeader(2);
            EdumasterCustom::LoadingPage(30,30,135,5);
            H::cls();
            MainAboutUs();
            H::cls();      
            LoadingHeader(3);
            EdumasterCustom::LoadingPage(30,30,135,5);
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
    EdumasterCustom::LoadingPage(30,30,135,5);
    H::cls();

}

void Edu_Main_Menu::MainProfile(){
	
	
	H::HLine(18,1,168,3,219);
	H::HLine(13,8,168,3,219);
	
	for(int i = 0; i < 5; i++) {
	    LittleSign(14 + i, 5 - i,5);
	               
	}
	for(int i = 0; i < 5; i++) {
	    LittleSign(183 + i, 5 - i,5);
	}
	

	H::setcolor(3); H::gotoxy(41, 1); cout << R"(      _       ______   ____    ____  _____  ____  _____          _______  _______     ___   ________  _____  _____     ________ )";
	H::setcolor(4); H::gotoxy(41, 2); cout << R"(     / \     |_   _ `.|_   \  /   _||_   _||_   \|_   _|         |_   _ \ |_   __\  .'   `.|_   __  ||_   _||_   _|   |_   __  |)";
	H::setcolor(5); H::gotoxy(41, 3); cout << R"(    / _ \      | | `. \ |   \/   |    | |    |   \ | |    ______ | |__) | | |__) | /  .-.  \ | |_ \_|  | |    | |       | |_ \_|)";
	H::setcolor(3); H::gotoxy(41, 4); cout << R"(   / ___ \     | |  | | | |\  /| |    | |    | |\ \| |   |______||  ___/  |  __ /  | |   | | |  _|     | |    | |   _   |  _| _ )";
	H::setcolor(4); H::gotoxy(41, 5); cout << R"( _/ /   \ \_  _| |_.' /_| |_\/_| |_  _| |_  _| |_\   |_         _| |_    _| |  \ \_\  `-'  /_| |_     _| |_  _| |__/ | _| |__/ |)";
	H::setcolor(5); H::gotoxy(41, 6); cout << R"(|____| |____||______.'|_____||_____||_____||_____|\____|       |_____|  |____| |___|`.___.'|_____|   |_____||________||________|)";


	H::drawBoxDoubleLineWithBG(4,10,102,22,255);
	
	H::drawBoxDoubleLineWithBG(8,12,24,3,196);
	H::drawBoxDoubleLineWithBG(42,20,24,3,196);
	H::drawBoxDoubleLineWithBG(78,28,24,3,196);
	
	H::drawBoxDoubleLineWithBG(11,13,18,1,247);
	H::foreColor(249); H::gotoxy(15,14);cout<<"ABOUT US ";
	
	H::drawBoxDoubleLineWithBG(45,21,18,1,247);
	H::foreColor(249); H::gotoxy(47,22);cout<<"LETTER FROM US";
	
	H::drawBoxDoubleLineWithBG(81,29,18,1,247);
	H::foreColor(249); H::gotoxy(84,30);cout<<"BACK TO MENU";

	
	H::setcolor(2); H::gotoxy(1, 34); cout << R"(                                                                               )";
	H::setcolor(2); H::gotoxy(1, 35); cout << R"(                 _                                                            _)";
	H::setcolor(2); H::gotoxy(1, 36); cout << R"(               _(_)_                          wWWWw   _                     _(_)_                            wWWWw   _      wWWWw    @@@       _   _    wWWWw     _   _    wWWWw    _   _    wWWWw      )";
	H::setcolor(11); H::gotoxy(1, 37); cout << R"(   @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_       @@@@       (_)@(_)   vVVVv      _     @@@@  (___) _(_)_    (___)  (@@()@@)   (_)@(_)   vVVVv    (_)@(_)   vVVVv   (_)@(_)   vVVVv       )";
	H::setcolor(2); H::gotoxy(1, 38); cout << R"(  @@()@@ wWWWw  (_))\    (___)   _(_)_  @@()@@   Y  (_)_@(_)     @@()@@ wWWWw  (_))\    (___)  _(_)_  @@()@@   Y  (_)_@(_)    Y       @@@       (___)     `|/     (___)     `|/     (___)     `|/       )";
	H::setcolor(11); H::gotoxy(1, 39); cout << R"(   @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   ((_))\      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   ((_))\   \|/)      |         |         |         |         |         |     |       )";
	H::setcolor(0); H::gotoxy(1, 40); cout << R"(    /      Y       \|    \|/    /(_)    \|      |/      |        /      Y       \|    \|/    /(_)      \|      |/      |      |        |         |         |         |         |         |     |    )";
	H::setcolor(0); H::gotoxy(1, 41); cout << R"(  \|     \ |/       | / \ | /  \|/       |/    \|      \|/     \|     \ |/       | / \ | /  \|/         |/    \|      \|/    \|       \|/       \|/       \|/       \|/       \|/       \|/   \|/     )";
	H::setcolor(0); H::gotoxy(1, 42); cout << R"(   |//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//     |//   \\|///  \\\|//\\\|/// \|///    \\\|//  \\|//  \\\|//  \\|///\\  \|//\\\|///\|/// /\\\|///\|// \\\|// /\\\|///\|/ \\|// \\\|// )";
	H::setcolor(0); H::gotoxy(1, 43); cout << R"(^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^)";
	
    H::setcolor(248); H::gotoxy(124,10); cout << R"(|,---"-----------------------------"---------------------------,|)";
    H::setcolor(248); H::gotoxy(124,11); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,12); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,13); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,14); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,15); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,16); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,17); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,18); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,19); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,20); cout << R"(||                                                             ||)";
    H::setcolor(248); H::gotoxy(124,21); cout << R"(||-------------------------------------------------------------||)";
    
    H::foreColor(241);
    H::gotoxy(150,14);cout<<"EMIS#";
	H::gotoxy(150,15);cout<<"PROFESSIONAL";
	H::gotoxy(150,16);cout<<"SYSTEM#";
	
    H::setcolor(177); H::gotoxy(124,23); cout << R"(|,---"-----------------------------"---------------------------,|)";
	H::setcolor(177); H::gotoxy(124,24); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,25); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,26); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,27); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,28); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,29); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,30); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,31); cout << R"(||                                                             ||)";
    H::setcolor(177); H::gotoxy(124,32); cout << R"(||                                                             ||)";
    H::setcolor(177); H::gotoxy(124,33); cout << R"(||                                                             ||)";
	H::setcolor(177); H::gotoxy(124,34); cout << R"(||-------------------------------------------------------------||)";
	
	H::foreColor(177);
	H::gotoxy(150,28);cout<<"EMIS#";
	H::gotoxy(150,29);cout<<"FASTER SYSTEM";
	H::gotoxy(150,30);cout<<"AND MONDERN";
	
}

void Edu_Main_Menu::LittleSign(int x, int y, int c){
	H::VLine(x,y,1,c,222);
}
void Edu_Main_Menu::MainAboutUs(){
    bool isWork = true;
	do{
		MainProfile();
		int x = 0;
		char op;
		
		do {
		    H::drawBoxDoubleLineWithBG(11,13,18,1,247);
		    H::foreColor(249); H::gotoxy(15,14); cout<<"ABOUT US ";
		
		    H::drawBoxDoubleLineWithBG(45,21,18,1,247);
		    H::foreColor(249); H::gotoxy(47,22); cout<<"LETTER FROM US";
		
		    H::drawBoxDoubleLineWithBG(81,29,18,1,247);
		    H::foreColor(249); H::gotoxy(84,30); cout<<"BACK TO MENU";
		
		    if(x==0){
			 H::gotoxy(15,14); H::foreColor(244); cout<<"ABOUT US "; 
			}
		    if(x==1){
			 H::gotoxy(47,22); H::foreColor(244); cout<<"LETTER FROM US"; 
			}
		    if(x==2){
			 H::gotoxy(84,30); H::foreColor(244); cout<<"BACK TO MENU"; 
			}
		
		    op = getch();
		    switch(op){
		        case 75:  
		            x--;
		            if(x < 0) x = 2; 
		            break;
		
		        case 77:  
		            x++;
		            if(x > 2) x = 0;   
		            break;
		    }
		} while(op != 13);
		H::cls();
		H::foreColor(0);
		if(x==0){
			H::cls();
			H::foreColor(0);
			TeamProfile();
		}
		
		if(x==1){
			H::cls();
			H::foreColor(0);
		    LetterFromUs();
			getch();
			H::cls();
		}
		if(x==2){
			H::cls();
			H::foreColor(0);
		    isWork= false;
		}
	H::foreColor(0);

	
	}while(isWork);
}

void Edu_Main_Menu::TeamProfile(){
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
	    LittleSign(50 + i, 5 - i,4);
	}
	for(int i = 0; i < 5; i++) {
	    LittleSign(151 + i, 5 - i,4);
	}
	
	
	H::foreColor(6); H::gotoxy(70,10);cout<<">>>>> Professor of C++ Object-Oriented Design <<<<<<";
	H::drawBoxDoubleLineWithBG(80,12,30,1,196);
	H::gotoxy(82,13);H::foreColor(199);cout<<"TEACHER NAME : UON HINSY";
	
	H::VLine(94,14,3,7,186);
	
	H::drawBoxDoubleLineWithBG(80,17,30,1,196);
	H::gotoxy(82,18);H::foreColor(199);cout<<"MENTER NAME : RUN LIHOU";
	H::VLine(94,19,2,7,186);
	H::HLine(15,22,170,7,223);
	
	//member
	H::VLine(16,21,10,7,186);
	H::drawBoxDoubleLineWithBG(1,32,28,1,153);
	H::gotoxy(5,33);H::foreColor(159);cout<<"LEADER : YUN WINNER";
	
	H::VLine(76,21,10,7,186);
	H::drawBoxDoubleLineWithBG(59,32,30,1,153);
	H::gotoxy(65,33);H::foreColor(159);cout<<"MEMBER : RY KIMCHHAY";
	
	H::VLine(136,21,10,7,186);
	H::drawBoxDoubleLineWithBG(120,32,30,1,153);
	H::gotoxy(125,33);H::foreColor(159);cout<<"MEMBER : VANNA NICH";
	
	H::VLine(185,21,10,7,186);
	H::drawBoxDoubleLineWithBG(170,32,28,1,153);
	H::gotoxy(175,33);H::foreColor(159);cout<<"MEMBER : SLESS ROFATH";
		
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

void Edu_Main_Menu::LetterFromUs(){

	H::HLine(18,1,168,3,219);
	H::HLine(13,8,168,3,219);
	
	for(int i = 0; i < 5; i++) {
	    LittleSign(14 + i, 5 - i,5);
	               
	}
	for(int i = 0; i < 5; i++) {
	    LittleSign(183 + i, 5 - i,5);
	}
	H::setcolor(3); H::gotoxy(33, 1); cout << R"( _____     ________  _________  _________  ________  _______         ________  _______      ___   ____    ____   _____  _____   ______  )";
	H::setcolor(4); H::gotoxy(33, 2); cout << R"(|_   _|   |_   __  ||  _   _  ||  _   _  ||_   __  ||_   __ \       |_   __  ||_   __ \   .'   `.|_   \  /   _| |_   _||_   _|.' ____ \ )";
	H::setcolor(5); H::gotoxy(33, 3); cout << R"(  | |       | |_ \_||_/ | | \_||_/ | | \_|  | |_ \_|  | |__) |        | |_ \_|  | |__) | /  .-.  \ |   \/   |     | |    | |  | (___ \_|)";
	H::setcolor(3); H::gotoxy(33, 4); cout << R"(  | |   _   |  _| _     | |        | |      |  _| _   |  __ /         |  _|     |  __ /  | |   | | | |\  /| |     | '    ' |   _.____`. )";
	H::setcolor(4); H::gotoxy(33, 5); cout << R"( _| |__/ | _| |__/ |   _| |_      _| |_    _| |__/ | _| |  \ \_      _| |_     _| |  \ \_\  `-'  /_| |_\/_| |_     \ \__/ /   | \____) |)";
	H::setcolor(5); H::gotoxy(33, 6); cout << R"(|________||________|  |_____|    |_____|  |________||____| |___|    |_____|   |____| |___|`.___.'|_____||_____|     `.__.'     \______.' )";
	
	//hline
	for(int i = 0; i < 143; i++) {
	    H::gotoxy(25 + i, 10);  
	    H::foreColor(7);      
	    cout << char(205);      
	    H::delay(1);            
	}
	H::gotoxy(25,10);cout<<char(201);
	
	//vline
	for(int i = 0; i < 22; i++) {
	    H::gotoxy(25, 11 + i);   
	    H::foreColor(7);         
	    cout << char(186);       
	    H::delay(1);   
		          
	}
	for(int i = 0; i < 144; i++) {
	    H::gotoxy(25 + i, 32);  
	    H::foreColor(7);        
	    cout << char(205);       
	    H::delay(1);        
	}	
	H::gotoxy(25,32);cout<<char(200);
		
	
	//vline
	for(int i = 0; i < 21; i++) {
	    H::gotoxy(168, 11 + i); 
	    H::foreColor(7);
	    cout << char(186);
	    H::delay(1);
	}	
	H::gotoxy(168	,10);cout<<char(187);
	
	
	H::drawBoxDoubleLine(27,37,40,1,2);
	H::drawBoxDoubleLine(127,37,40,1,2);
	
	H::gotoxy(131, 38);H::foreColor(7);
	cout << "PRESS ";
	H::setcolor(4); 
	cout << "[ESC]";
	H::setcolor(7); 
	cout << " FOR BACK TO ";
	H::setcolor(4);
	cout << "MENU";
	H::setcolor(7); 
	cout << " ..!";
	
	H::gotoxy(31, 38);H::foreColor(7);
	cout << "PRESS ";
	H::setcolor(4);
	cout << "[ESC]";
	H::setcolor(7); 
	cout << " FOR BACK TO ";
	H::setcolor(4);
	cout << "MENU";
	H::setcolor(7); 
	cout << " ..!";

	H::foreColor(7); H::gotoxy(38,13); 
	VN("We are "); 
	
	H::foreColor(4); H::foreColor(199); 
	VN("Generation 2 scholarship students");
	
	H::foreColor(7); 
	VN(" at ANT Technology Training Center, learning ");  // normal part
	
	H::foreColor(23);  
	VN("Mobile Application development (Flutter)");
	
	H::foreColor(3);  

	H::foreColor(11); H::gotoxy(58,17);
	H::foreColor(7); 
	VN("The program runs 13 months, from ");  
	
	H::foreColor(23);  
	VN("16 June 2025");
	
	H::foreColor(7);
	VN(" to ");
	
	H::foreColor(23);  
	VN("17 July 2026");
	
	H::foreColor(7);
	VN(".");

	
	H::foreColor(7); H::gotoxy(38,21);
	VN("With the support of the Ministry of Post and Telecommunications, we have the chance to gain skills in mobile app development");
	
	H::foreColor(23); H::gotoxy(38,25);
	VN("and prepare for future tech careers. We sincerely thank the Ministry of Post and Telecommunications for this opportunity.");
	
	H::foreColor(199); H::gotoxy(58,29);
	VN("and wish the Ministry continued success and growth in all its endeavors.");
	H::foreColor(0);

}

void Edu_Main_Menu::VN(const string &str){ 
	 int j = 1; 
	 for(int i = 0;i<str.length();i++) 
	 { 
	  cout << str[i];H::delay(5); 
	  j++; 
	 } 
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