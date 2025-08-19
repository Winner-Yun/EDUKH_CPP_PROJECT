#ifndef __INC_TEACHERPOFILEDESIGN__
#define __INC_TEACHERPOFILEDESIGN__

#include "../Header_School/ANTHinsyOOP"
#include "ConsoleColor.h"
using namespace ANTHinsyOOP;


class TeacherProfileDesign
{
    public: 
        static int navigateMenu(); 
        static void drawMenu(int selected);
        //=============================
        static void TeacherProfileText(int x, int y);
        static void bus(int x, int y);
        static void TeacherProfileTable(int x, int y);
        static void ProfileDesign();

};

void TeacherProfileDesign::TeacherProfileTable(int x, int y)
{
	// Table
  	H::drawBoxSingleLine(x, y, 70, 1,6); //  Table Header
	H::drawBoxSingleLine(x, y, 70, 17,3); // Table Body Design
	
	//	H::setcolor(3);
		H::gotoxy(73,23); cout<<"No.";
		H::gotoxy(88,23); cout<<"Grade";
		H::gotoxy(105,23); cout<<"Subject";
		H::gotoxy(128,23); cout<<"Year";
	//
}
                                                                                                                

void TeacherProfileDesign::ProfileDesign()
{
	H::setcursor(false,0);
	TeacherProfileText(42, 2);
	
	for(int i=0;i<9;i++){
		H::HLine(40,i,2,3,219);
		H::HLine(158,i,2,3,219);
	} 
	
	H::HLine(40,0,40,3,219);
	H::HLine(40,9,40,3,219);
	
	H::HLine(118,0,40,3,219);
	H::HLine(118,9,42,3,219);
	
	H::drawBoxSingleLineWithBG(1,4,38,1,196);
	H::drawBoxSingleLineWithBG(161,4,38,1,196);
	
	for(int i=7;i<42;i++){
		H::HLine(10,i,2,9,178);
		H::HLine(188,i,2,9,178);
	}
	
	// Profile Box
	H::drawBoxSingleLineWithBG(16,11,50,28,179);
	
	// image profile
	H::drawBoxDoubleLineWithBG(26,12,30,8,119);
	H::drawBoxDoubleLineWithBG(36,13,10,2,145);
	H::drawBoxDoubleLineWithBG(28,18,26,2,145);
	//
	H::drawBoxDoubleLineWithBG(21,23,40,3,230);
	H::drawBoxDoubleLineWithBG(21,29,40,9,230);
	// Ex: Data
	// H::setcolor(233);
	// H::gotoxy(36,24); cout<<"ID: T-001";
	// H::gotoxy(21,26); cout<<"Name : Mr. Sles Rofath";
	// H::setcolor(234); H::gotoxy(44,26); cout<<"|";
	// H::setcolor(233);
	// H::gotoxy(46,26); cout<<"Gender : Female";
	// H::gotoxy(22,30); cout<<"Subject : Mathematics";
	// H::gotoxy(22,32); cout<<"Birth Date : 22-03-2000";
	// H::gotoxy(22,34); cout<<"Study Year : 2010";
	// H::gotoxy(22,36); cout<<"Email : slesrofath@gmail.com";
	// H::gotoxy(22,38); cout<<"Phone Number : 09397477373";
	
	//
	H::drawBoxSingleLineWithBG(71, 18, 70, 1,196); //  Table Bar
	H::setcolor(199);
	system("chcp 65001 > nul");
	H::gotoxy(82,19); cout<<"]|I{•------» RESPONSIBILITY CLASSES «------•}I|[";
	system("chcp 437 > nul");
	// Table
	TeacherProfileTable(71,22);
	
	bus(112,10);
	H::drawBoxSingleLineWithBG(71,12,40,2,179);
		
	// Setting Menu
	system("chcp 65001 > nul");
	H::gotoxy(149,12); cout<<" «-(¯`v´¯)-« Setting »-(¯`v´¯)-» ";
	system("chcp 437 > nul");
	H::drawBoxSingleLineWithBG(146, 11, 38, 1,247); 
	H::drawBoxSingleLineWithBG(146, 14, 38, 25,145);
	H::drawBoxSingleLineWithBG(146, 38, 38, 1,247); 
	//
	for(int i=14;i<20;i++)
	{
		H::HLine(164,i,2,247,177);
	}
	H::HLine(145,20,40,247,177);
	for(int i=32;i<38;i++)
	{
		H::HLine(164,i,2,247,177);
	}
	H::HLine(145,31,40,247,177);

	//
	H::drawBoxSingleLineWithBG(149,22,32,1,233);
	H::drawBoxSingleLineWithBG(149,27,32,1,233);
	
	
	// Footer
	H::drawBoxSingleLineWithBG(0,42,199,1,247);
	H::gotoxy(38,43);
	setConsoleColor(BLACK, WHITE); 
	cout<<"Tips: [Use Arrow Up/Down to move]			[Press Enter to select]				[Press ESC to go back]";
	
	//int choice = navigateMenu();
}

// ========================== Draw Menu ==========================

const int MENU_SIZE = 2;
string settingMenu[MENU_SIZE] = {
    "1. Change Password",
    "2. View Assigned Classes"
};
int menuX = 153;
int menuY[MENU_SIZE] = {22, 27};

// Draw menu with arrow highlighting
void TeacherProfileDesign::drawMenu(int selected) {
    for (int i = 0; i < MENU_SIZE; i++) {
        H::gotoxy(menuX, menuY[i]);
        if (i == selected) {
        	H::setcolor(234);
            cout << "-> " << settingMenu[i]; // highlight with arrow
        } else {
        	H::setcolor(233);
            cout << "   " << settingMenu[i];
        }
    }
}

// Function to navigate menu and return choice
int TeacherProfileDesign::navigateMenu() {
    int selected = 0;
    drawMenu(selected);

    while (true) {
        int ch = _getch();

        if (ch == 0 || ch == 224) { // arrow keys
            ch = _getch();
            if (ch == 72) { // UP
                selected--;
                if (selected < 0) selected = MENU_SIZE - 1;
            } else if (ch == 80) { // DOWN
                selected++;
                if (selected >= MENU_SIZE) selected = 0;
            }
            drawMenu(selected);
        } else if (ch == 13) { // ENTER
            return selected; // return the selected menu item
        } else if (ch == 27) { // ESC key
        	H::setcolor(7);
        	H::cls();
            return -1; // special value to indicate "back to main menu"
        }
    }
}

// ==============================================================================

void TeacherProfileDesign::TeacherProfileText(int x, int y)
{
    system("chcp 65001 > nul");
    
    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ████████╗███████╗ █████╗  ██████╗██╗  ██╗███████╗██████╗      ██████╗ ██████╗  ██████╗ ███████╗██╗██╗     ███████╗)";   
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ╚══██╔══╝██╔════╝██╔══██╗██╔════╝██║  ██║██╔════╝██╔══██╗     ██╔══██╗██╔══██╗██╔═══██╗██╔════╝██║██║     ██╔════╝)"; 
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"(    ██║   █████╗  ███████║██║     ███████║█████╗  ██████╔╝     ██████╔╝██████╔╝██║   ██║█████╗  ██║██║     █████╗  )"; 
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"(    ██║   ██╔══╝  ██╔══██║██║     ██╔══██║██╔══╝  ██╔══██╗     ██╔═══╝ ██╔══██╗██║   ██║██╔══╝  ██║██║     ██╔══╝  )"; 
    H::setcolor(6); H::gotoxy(x,y+4); cout<<R"(    ██║   ███████╗██║  ██║╚██████╗██║  ██║███████╗██║  ██║     ██║     ██║  ██║╚██████╔╝██║     ██║███████╗███████╗)";  
    H::setcolor(6); H::gotoxy(x,y+5); cout<<R"(    ╚═╝   ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝     ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝╚══════╝)"; 
                                                                                                                                                                                                                                
    system("chcp 437 > nul");
}

void TeacherProfileDesign::bus(int x, int y){
	H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(  __                          )";
	H::setcolor(3); H::gotoxy(x,y+1); cout<<R"( |  '-----------------------. )";	
	H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( |.---. .---. .---. .---. _ |\)";
	H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ||___| |___| |___| |___||||j|)";
	H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( |=======================|||=|)";
	H::setcolor(3); H::gotoxy(x,y+5); cout<<R"( [___/(O)|__________/(O)||j|_])";
}

#endif