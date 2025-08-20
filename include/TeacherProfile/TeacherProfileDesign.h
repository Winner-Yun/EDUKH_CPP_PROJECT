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
		//
		static void ViewAssignClassText(int x, int y);
		// 
		static void ChangePasswordText(int x, int y);

};

void TeacherProfileDesign::ChangePasswordText(int x, int y)
{
    system("chcp 65001  > nul");
	H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(  ██████╗██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███████╗    ██████╗  █████╗ ███████╗███████╗██╗    ██╗ ██████╗ ██████╗ ██████╗ )";
	H::setcolor(3); H::gotoxy(x,y+1); cout<<R"( ██╔════╝██║  ██║██╔══██╗████╗  ██║██╔════╝ ██╔════╝    ██╔══██╗██╔══██╗██╔════╝██╔════╝██║    ██║██╔═══██╗██╔══██╗██╔══██╗)";
	H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( ██║     ███████║███████║██╔██╗ ██║██║  ███╗█████╗      ██████╔╝███████║███████╗███████╗██║ █╗ ██║██║   ██║██████╔╝██║  ██║)";
	H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ██║     ██╔══██║██╔══██║██║╚██╗██║██║   ██║██╔══╝      ██╔═══╝ ██╔══██║╚════██║╚════██║██║███╗██║██║   ██║██╔══██╗██║  ██║)";
	H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ╚██████╗██║  ██║██║  ██║██║ ╚████║╚██████╔╝███████╗    ██║     ██║  ██║███████║███████║╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝)";
	H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝    ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ )";
    system("chcp 437  > nul");
    
    H::drawBoxDoubleLine(70,10,60,20);
    // Field
    H::drawBoxSingleLine(72,12,56,1,6);
    H::drawBoxSingleLine(72,16,56,1,6);
    H::drawBoxSingleLine(72,20,56,1,6);
    
//    H::gotoxy(74,13); cout<<"Enter Current Password : ";
//    H::gotoxy(74,17); cout<<"Enter New Password     : ";
//    H::gotoxy(74,21); cout<<"Enter Confirm Password : ";
    
}

void TeacherProfileDesign::ViewAssignClassText(int x, int y)
{
    system("chcp 65001  > nul");
	H::setcolor(1); H::gotoxy(x,y+0); cout<<R"(  █████   █████ █████ ██████████ █████   ███   █████      █████████    █████████   █████████  █████   █████████  ██████   █████      █████████  █████         █████████    █████████   █████████ )";
	H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ░░███   ░░███ ░░███ ░░███░░░░░█░░███   ░███  ░░███      ███░░░░░███  ███░░░░░███ ███░░░░░███░░███   ███░░░░░███░░██████ ░░███      ███░░░░░███░░███         ███░░░░░███  ███░░░░░███ ███░░░░░███)";
	H::setcolor(1); H::gotoxy(x,y+2); cout<<R"(  ░███    ░███  ░███  ░███  █ ░  ░███   ░███   ░███     ░███    ░███ ░███    ░░░ ░███    ░░░  ░███  ███     ░░░  ░███░███ ░███     ███     ░░░  ░███        ░███    ░███ ░███    ░░░ ░███    ░░░ )";
	H::setcolor(1); H::gotoxy(x,y+3); cout<<R"(  ░███    ░███  ░███  ░██████    ░███   ░███   ░███     ░███████████ ░░█████████ ░░█████████  ░███ ░███          ░███░░███░███    ░███          ░███        ░███████████ ░░█████████ ░░█████████ )";
	H::setcolor(3); H::gotoxy(x,y+4); cout<<R"(  ░░███   ███   ░███  ░███░░█    ░░███  █████  ███      ░███░░░░░███  ░░░░░░░░███ ░░░░░░░░███ ░███ ░███    █████ ░███ ░░██████    ░███          ░███        ░███░░░░░███  ░░░░░░░░███ ░░░░░░░░███)";
	H::setcolor(4); H::gotoxy(x,y+5); cout<<R"(   ░░░█████░    ░███  ░███ ░   █  ░░░█████░█████░       ░███    ░███  ███    ░███ ███    ░███ ░███ ░░███  ░░███  ░███  ░░█████    ░░███     ███ ░███      █ ░███    ░███  ███    ░███ ███    ░███)";
	H::setcolor(4); H::gotoxy(x,y+6); cout<<R"(     ░░███      █████ ██████████    ░░███ ░░███         █████   █████░░█████████ ░░█████████  █████ ░░█████████  █████  ░░█████    ░░█████████  ███████████ █████   █████░░█████████ ░░█████████ )";
	H::setcolor(4); H::gotoxy(x,y+7); cout<<R"(      ░░░      ░░░░░ ░░░░░░░░░░      ░░░   ░░░         ░░░░░   ░░░░░  ░░░░░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░░░░░  ░░░░░    ░░░░░      ░░░░░░░░░  ░░░░░░░░░░░ ░░░░░   ░░░░░  ░░░░░░░░░   ░░░░░░░░░  )";
    system("chcp 437  > nul");
    //
    H::HLine(3,10,194,189,234);
    for(int i=11;i<43;i++){
    	H::HLine(20,i,2,233,233);
    	H::HLine(180,i,2,233,233);
	}
	H::HLine(20,43,10,233,234);
	H::HLine(172,43,10,233,234);
	H::drawBoxSingleLineWithBG(31,42,140,1,234);
	//
	H::HLine(22,14,30,233,233);
	H::HLine(150,14,30,233,233);
	for(int i=11;i<15;i++)
	{
		H::HLine(50,i,2,233,233);
		H::HLine(150,i,2,233,233);
	}
//	H::setcolor(2);
//	H::gotoxy(25,12); cout<<"ID: T-001";
//	H::gotoxy(155,12); cout<<"Name: Sles Rofath";
	
    H::drawBoxSingleLine(68, 16, 70, 1,6); //  Table Header
	H::drawBoxSingleLine(68, 16, 70, 21,3); // Table Body Design
	
	// Paginate
	H::drawBoxDoubleLine(98,39,11,1,2);
	system("chcp 65001 > nul");
	H::setcolor(234);
	H::gotoxy(86,43); cout << "[← Prev]   [→ Next]   [ESC Exit]";
	system("chcp 437 > nul");
}

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