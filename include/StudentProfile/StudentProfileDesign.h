#ifndef STUDENT_PROFILE_DESIGN_H
#define STUDENT_PROFILE_DESIGN_H

#include "../Header_School/ANTHinsyOOP.h"
#include "../TeacherProfile/ConsoleColor.h"

using namespace ANTHinsyOOP;

class StudentProfileDesign {
    public:
        static void SchoolText(int x, int y);
        static void HeaderText(int x, int y);
        static void FooterText();
};

void StudentProfileDesign::HeaderText(int x, int y)
{
    H::drawBoxDoubleLineWithBG(0,0,199,5,247);   
    system("chcp 65001  > nul");
    H::setcolor(249); H::gotoxy(x,y+0); cout<<R"( ███████ ████████ ██    ██ ██████  ███████ ███    ██ ████████     ██████  ██████   ██████  ███████ ██ ██      ███████)";     
    H::setcolor(249); H::gotoxy(x,y+1); cout<<R"( ██         ██    ██    ██ ██   ██ ██      ████   ██    ██        ██   ██ ██   ██ ██    ██ ██      ██ ██      ██     )";  
    H::setcolor(249); H::gotoxy(x,y+2); cout<<R"( ███████    ██    ██    ██ ██   ██ █████   ██ ██  ██    ██        ██████  ██████  ██    ██ █████   ██ ██      █████  )";  
    H::setcolor(249); H::gotoxy(x,y+3); cout<<R"(      ██    ██    ██    ██ ██   ██ ██      ██  ██ ██    ██        ██      ██   ██ ██    ██ ██      ██ ██      ██     )";  
    H::setcolor(249); H::gotoxy(x,y+4); cout<<R"( ███████    ██     ██████  ██████  ███████ ██   ████    ██        ██      ██   ██  ██████  ██      ██ ███████ ███████)";  
    system("chcp 437  > nul");
	
	// Profile
	H::drawBoxSingleLineWithBG(45,8,110,22,179);
	H::HLine(44,8,112,178,223);
	//
	H::drawBoxDoubleLineWithBG(46,9,30,11,119);
	H::drawBoxDoubleLineWithBG(56,10,10,2,145);
	H::drawBoxDoubleLineWithBG(49,15,24,5,145);
	// Field
	H::drawBoxDoubleLineWithBG(80,9,35,1,185); // ID
	H::drawBoxDoubleLineWithBG(118,9,35,1,185); // Name
	H::HLine(79,12,75,183,205);
	H::drawBoxDoubleLineWithBG(80,13,35,1,185); // Grade
	H::drawBoxDoubleLineWithBG(118,13,35,1,185); // Academic Year
	H::drawBoxDoubleLineWithBG(80,16,35,1,185); // Gender
	H::drawBoxDoubleLineWithBG(118,16,35,1,185); // Birth Date
	H::drawBoxDoubleLineWithBG(80,19,35,1,185); // Email
	H::drawBoxDoubleLineWithBG(118,19,35,1,185); // Tel
	
	H::HLine(44,23,112,178,223);
	
	H::drawBoxDoubleLineWithBG(60,26,35,1,230);
	H::drawBoxDoubleLineWithBG(105,26,35,1,230);
	
	setConsoleColor(8, 11);
	H::gotoxy(82,10); cout<<"ID     : ";
	H::gotoxy(82,14); cout<<"GRADE  : ";
	H::gotoxy(82,17); cout<<"GENDER : ";
	H::gotoxy(82,20); cout<<"EMAIL  : ";
	H::gotoxy(120,10); cout<<"NAME          : ";
	H::gotoxy(120,14); cout<<"ACADEMIC YEAR : ";
	H::gotoxy(120,17); cout<<"BIRTH DATE    : ";
	H::gotoxy(120,20); cout<<"TELEPHONE     : ";
    // Data below
}

void StudentProfileDesign::SchoolText(int x, int y)
{
    H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(                 _ _.-'`-._ _                 )";
    H::setcolor(3); H::gotoxy(x,y+1); cout<<R"(                ;.'________'.;                )";
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"(     _________n.[____________].n_________     )";
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"(    |""_""_""_""||==||==||==||""_""_""_""]    )";
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"(    |"""""""""""||..||..||..||"""""""""""|    )";
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(    |LI LI LI LI||LI||LI||LI||LI LI LI LI|    )";
    H::setcolor(3); H::gotoxy(x,y+6); cout<<R"(    |.. .. .. ..||..||..||..||.. .. .. ..|    )";
    H::setcolor(3); H::gotoxy(x,y+7); cout<<R"(    |LI LI LI LI||LI||LI||LI||LI LI LI LI|    )";
    H::setcolor(3); H::gotoxy(x,y+8); cout<<R"( ,,;;,;;;,;;;,;;;,;;;,;;;,;;;,;;,;;;,;;;,;;,, )";
    H::setcolor(3); H::gotoxy(x,y+9); cout<<R"(;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;)";
}

#endif // STUDENT_PROFILE_DESIGN_H