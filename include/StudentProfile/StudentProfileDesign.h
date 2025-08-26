#ifndef STUDENT_PROFILE_DESIGN_H
#define STUDENT_PROFILE_DESIGN_H

#include "../Header_School/ANTHinsyOOP"
#include "../TeacherProfile/ConsoleColor.h"

using namespace ANTHinsyOOP;

class StudentProfileDesign {
    public:
        static void SchoolText(int x, int y);
        static void HeaderText(int x, int y);
        static void FooterText();
		// ===========================================
		static void ChangePasswordText(int x, int y);
		static void SnowText();
		static void BearBorder(int x, int y);
};

void StudentProfileDesign::ChangePasswordText(int x, int y)
{
	BearBorder(65,7);
	
    system("chcp 65001  > nul");
	H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(  ██████╗██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███████╗    ██████╗  █████╗ ███████╗███████╗██╗    ██╗ ██████╗ ██████╗ ██████╗ )";H::delay(30);
	H::setcolor(3); H::gotoxy(x,y+1); cout<<R"( ██╔════╝██║  ██║██╔══██╗████╗  ██║██╔════╝ ██╔════╝    ██╔══██╗██╔══██╗██╔════╝██╔════╝██║    ██║██╔═══██╗██╔══██╗██╔══██╗)";H::delay(30);
	H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( ██║     ███████║███████║██╔██╗ ██║██║  ███╗█████╗      ██████╔╝███████║███████╗███████╗██║ █╗ ██║██║   ██║██████╔╝██║  ██║)";H::delay(30);
	H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ██║     ██╔══██║██╔══██║██║╚██╗██║██║   ██║██╔══╝      ██╔═══╝ ██╔══██║╚════██║╚════██║██║███╗██║██║   ██║██╔══██╗██║  ██║)";H::delay(30);
	H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ╚██████╗██║  ██║██║  ██║██║ ╚████║╚██████╔╝███████╗    ██║     ██║  ██║███████║███████║╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝)";H::delay(30);
	H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝    ╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ )";H::delay(30);
    system("chcp 437  > nul");
    
	
	H::drawBoxDoubleLineWithBG(12,15,3,25,227);
	H::drawBoxDoubleLineWithBG(17,12,3,28,185);
	H::drawBoxDoubleLineWithBG(22,7,3,33,167);
	H::drawBoxDoubleLineWithBG(27,12,3,28,154);
	H::drawBoxDoubleLineWithBG(32,15,3,25,227);
	
	H::drawBoxDoubleLineWithBG(165,15,3,25,227);
	H::drawBoxDoubleLineWithBG(170,12,3,28,185);
	H::drawBoxDoubleLineWithBG(175,7,3,33,167);
	H::drawBoxDoubleLineWithBG(180,12,3,28,154);
	H::drawBoxDoubleLineWithBG(185,15,3,25,227);
	
	// Field
    H::drawBoxSingleLine(72,22,55,1,6);
    H::drawBoxSingleLine(72,25,55,1,6);
    H::drawBoxSingleLine(72,28,55,1,6);

	// Footer
	H::drawBoxDoubleLineWithBG(1,42,198,1,113);
	H::setcolor(242);

    H::gotoxy(35, 43); cout << "Tip: Press [Enter] to try again			Press [ESC] to go back			Press [Tab] for show or hide password";
	
	SnowText();
}

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
	H::gotoxy(81,10); cout<<"ID     : ";
	H::gotoxy(81,14); cout<<"GRADE  : ";
	H::gotoxy(81,17); cout<<"GENDER : ";
	H::gotoxy(81,20); cout<<"EMAIL  : ";
	H::gotoxy(119,10); cout<<"NAME          : ";
	H::gotoxy(119,14); cout<<"ACADEMIC YEAR : ";
	H::gotoxy(119,17); cout<<"BIRTH DATE    : ";
	H::gotoxy(119,20); cout<<"TELEPHONE     : ";
    // Data below
}

void StudentProfileDesign::FooterText()
{
	// Footer
	H::drawBoxDoubleLineWithBG(60,32,10,8,162);
	H::drawBoxDoubleLineWithBG(130,32,10,8,162);
	H::drawBoxDoubleLineWithBG(55,42,20,1,179);
	H::drawBoxDoubleLineWithBG(125,42,20,1,179);
	//
	H::drawBoxDoubleLineWithBG(75,36,50,1,1); // For Tip
	setConsoleColor(7, 0);
	H::gotoxy(77,37); cout<<"Tip: Use arrow key [Left] & [Right} for move!";
	// Left
	H::drawBoxDoubleLineWithBG(38,7,5,24,162);
	H::drawBoxDoubleLineWithBG(31,9,5,20,145);
	H::drawBoxDoubleLineWithBG(24,11,5,16,187);
	H::drawBoxDoubleLineWithBG(17,13,5,12,196);
	H::drawBoxDoubleLineWithBG(10,15,5,8,247);
	H::drawBoxDoubleLineWithBG(3,17,5,4,230);
	// Right
	H::drawBoxDoubleLineWithBG(157,7,5,24,162);
	H::drawBoxDoubleLineWithBG(164,9,5,20,145);
	H::drawBoxDoubleLineWithBG(171,11,5,16,187);
	H::drawBoxDoubleLineWithBG(178,13,5,12,196);
	H::drawBoxDoubleLineWithBG(185,15,5,8,247);
	H::drawBoxDoubleLineWithBG(192,17,5,4,230);
	
    SchoolText(1,35);
    SchoolText(153,35);
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

void StudentProfileDesign::SnowText()
{
    int delay = 80, totalLines = 9;;

    for (int line = 0; line < totalLines; line++){
        int x = 40, y=8;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x,y+0); cout<<R"(       ..    ..    )";break;
            case 1: H::setcolor(2); H::gotoxy(x,y+1); cout<<R"(       '\    /'    )";break;
            case 2: H::setcolor(3); H::gotoxy(x,y+2); cout<<R"(         \\//      )";break;
            case 3: H::setcolor(4); H::gotoxy(x,y+3); cout<<R"(    _.__\\\///__._ )";break;
            case 4: H::setcolor(5); H::gotoxy(x,y+4); cout<<R"(     '  ///\\\  '  )";break;
            case 5: H::setcolor(6); H::gotoxy(x,y+5); cout<<R"(         //\\      )";break;
            case 6: H::setcolor(7); H::gotoxy(x,y+6); cout<<R"(       ./    \.    )";break;
            case 7: H::setcolor(8); H::gotoxy(x,y+7); cout<<R"(       ''    ''    )";break;
        }

        int x1=141, y1=8;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x1,y1+0); cout<<R"(     *  .  *   )";break;
            case 1: H::setcolor(2); H::gotoxy(x1,y1+1); cout<<R"(   . _\/ \/_ . )";break;
            case 2: H::setcolor(3); H::gotoxy(x1,y1+2); cout<<R"(    \  \ /  /  )";break;
            case 3: H::setcolor(4); H::gotoxy(x1,y1+3); cout<<R"(  -==>: X :<==-)";break;
            case 4: H::setcolor(5); H::gotoxy(x1,y1+4); cout<<R"(    / _/ \_ \  )";break;           
            case 5: H::setcolor(6); H::gotoxy(x1,y1+5); cout<<R"(   '  /\ /\  ' )";break;        
            case 6: H::setcolor(7); H::gotoxy(x1,y1+6); cout<<R"(     *  '  *   )";break;
        }
        

        
        int x2=40,y2=17;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x2,y2+0); cout<<R"(       _\/  \/_   )";break;
            case 1: H::setcolor(2); H::gotoxy(x2,y2+1); cout<<R"(        _\/\/_	   )";break;
            case 2: H::setcolor(3); H::gotoxy(x2,y2+2); cout<<R"(    _\_\_\/\/_/_/_)";break;
            case 3: H::setcolor(4); H::gotoxy(x2,y2+3); cout<<R"(     / /_/\/\_\ \ )";break;
            case 4: H::setcolor(5); H::gotoxy(x2,y2+4); cout<<R"(        _/\/\_    )";break;
            case 5: H::setcolor(6); H::gotoxy(x2,y2+5); cout<<R"(        /\  /\    )";break;
        }

        int x3=141, y3=17;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x3,y3+0); cout<<R"(      _    _   )";break;   
            case 1: H::setcolor(2); H::gotoxy(x3,y3+1); cout<<R"(     /_/  \_\  )";break;   
            case 2: H::setcolor(3); H::gotoxy(x3,y3+2); cout<<R"(       \\//    )";break;   
            case 3: H::setcolor(4); H::gotoxy(x3,y3+3); cout<<R"(   /\_\\><\\_\/)";break;
            case 4: H::setcolor(5); H::gotoxy(x3,y3+4); cout<<R"(      _//\\_   )";break;
            case 5: H::setcolor(6); H::gotoxy(x3,y3+5); cout<<R"(     \_\  /_/  )";break;
        }

        
        int x4=43, y4=24;
        switch(line){
            case 1: H::setcolor(6); H::gotoxy(x4,y4+0); cout<<R"(    ._    _.   )";break;    
            case 2: H::setcolor(5); H::gotoxy(x4,y4+1); cout<<R"(    (_)  (_)   )";break;               
            case 3: H::setcolor(4); H::gotoxy(x4,y4+2); cout<<R"(     .\::/.    )";break;               
            case 4: H::setcolor(7); H::gotoxy(x4,y4+3); cout<<R"( _.=._\\//_.=._)";break;                 
            case 5: H::setcolor(3); H::gotoxy(x4,y4+4); cout<<R"(  '=' //\\ '=' )";break;            
            case 6: H::setcolor(2); H::gotoxy(x4,y4+5); cout<<R"(     '/::\'    )";break;           
            case 7: H::setcolor(1); H::gotoxy(x4,y4+6); cout<<R"(    (_)  (_)   )";break;   
            case 8: H::setcolor(8); H::gotoxy(x4,y4+7); cout<<R"(    '      '   )";break;
        }

        
        int x5 =142, y5=24;
        switch(line){
            case 0: H::setcolor(7); H::gotoxy(x5,y5+0); cout<<R"(        .       )";break;      
            case 1: H::setcolor(6); H::gotoxy(x5,y5+1); cout<<R"(        :       )";break;        
            case 2: H::setcolor(5); H::gotoxy(x5,y5+2); cout<<R"(  '.___/*\___.' )";break;         
            case 3: H::setcolor(4); H::gotoxy(x5,y5+3); cout<<R"(    \* \ / */   )";break;            
            case 4: H::setcolor(3); H::gotoxy(x5,y5+4); cout<<R"(     >--X--<    )";break;
            case 5: H::setcolor(2); H::gotoxy(x5,y5+5); cout<<R"(    /*_/ \_*\   )";break;
            case 6: H::setcolor(1); H::gotoxy(x5,y5+6); cout<<R"(  .'   \*/   '. )";break;
            case 7: H::setcolor(8); H::gotoxy(x5,y5+7); cout<<R"(        :       )";break;
            case 8: H::setcolor(9); H::gotoxy(x5,y5+8); cout<<R"(        '       )";break;
        }

        
        int x6=43, y6=33;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x6,y6+0); cout<<R"(       o     )";break;         
            case 1: H::setcolor(2); H::gotoxy(x6,y6+1); cout<<R"(  o    :    o)";break;         
            case 2: H::setcolor(3); H::gotoxy(x6,y6+2); cout<<R"(    '.\'/.'  )";break;              
            case 3: H::setcolor(4); H::gotoxy(x6,y6+3); cout<<R"(    :->@<-:  )";break;       
            case 4: H::setcolor(5); H::gotoxy(x6,y6+4); cout<<R"(    .'/.\'.  )";break;         
            case 5: H::setcolor(6); H::gotoxy(x6,y6+5); cout<<R"(  o    :    o)";break;           
            case 6: H::setcolor(7); H::gotoxy(x6,y6+6); cout<<R"(       o     )";break;
        }

        
        int x7 =141, y7=33;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x7,y7+0); cout<<R"(        \o/      )";break;
            case 1: H::setcolor(2); H::gotoxy(x7,y7+1); cout<<R"(    _o/.:|:.\o_  )";break;
            case 2: H::setcolor(3); H::gotoxy(x7,y7+2); cout<<R"(      .\:|:/.    )";break;
            case 3: H::setcolor(4); H::gotoxy(x7,y7+3); cout<<R"(  -=>>::>o<::<<=-)";break;
            case 4: H::setcolor(5); H::gotoxy(x7,y7+4); cout<<R"(    _ '/:|:\' _  )";break;
            case 5: H::setcolor(6); H::gotoxy(x7,y7+5); cout<<R"(     o\':|:'/o   )";break;
            case 6: H::setcolor(7); H::gotoxy(x7,y7+6); cout<<R"(        /o\      )";break;
        }

        
        int x8 =2, y8=1;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x8,y8+0); cout<<R"(    <> \  / <>   )";break;
            case 1: H::setcolor(2); H::gotoxy(x8,y8+1); cout<<R"(    \_\/  \/_/   )";break;
            case 2: H::setcolor(3); H::gotoxy(x8,y8+2); cout<<R"(       \\//	  )";break;
            case 3: H::setcolor(4); H::gotoxy(x8,y8+3); cout<<R"( _<>_\_\<>/_/_<>_)";break;
            case 4: H::setcolor(5); H::gotoxy(x8,y8+4); cout<<R"(  <> / /<>\ \ <> )";break;
            case 5: H::setcolor(6); H::gotoxy(x8,y8+5); cout<<R"(     _ //\\ _    )";break;
            case 6: H::setcolor(7); H::gotoxy(x8,y8+6); cout<<R"(    / /\  /\ \   )";break;
            case 7: H::setcolor(8); H::gotoxy(x8,y8+7); cout<<R"(    <> /  \ <>   )";break;
        }

        
        x8 =180, y8=1;
        switch(line){
            case 0: H::setcolor(1); H::gotoxy(x8,y8+0); cout<<R"(    <> \  / <>   )";break;
            case 1: H::setcolor(2); H::gotoxy(x8,y8+1); cout<<R"(    \_\/  \/_/   )";break;
            case 2: H::setcolor(3); H::gotoxy(x8,y8+2); cout<<R"(       \\//	  )";break;
            case 3: H::setcolor(4); H::gotoxy(x8,y8+3); cout<<R"( _<>_\_\<>/_/_<>_)";break;
            case 4: H::setcolor(5); H::gotoxy(x8,y8+4); cout<<R"(  <> / /<>\ \ <> )";break;
            case 5: H::setcolor(6); H::gotoxy(x8,y8+5); cout<<R"(     _ //\\ _    )";break;
            case 6: H::setcolor(7); H::gotoxy(x8,y8+6); cout<<R"(    / /\  /\ \   )";break;
            case 7: H::setcolor(8); H::gotoxy(x8,y8+7); cout<<R"(    <> /  \ <>   )";break;
        }
        H::delay(delay);
    }
}

void StudentProfileDesign::BearBorder(int x, int y)
{
	H::setcolor(9);
  H::setcolor(1); H::gotoxy(x,y+1); cout<<R"(                      ,---.           ,---.                          )";
  H::setcolor(1); H::gotoxy(x,y+2); cout<<R"(                     / /"`.\.--"""--./,'"\ \                         )";
  H::setcolor(1); H::gotoxy(x,y+3); cout<<R"(                     \ \    _       _    / /                         )";
  H::setcolor(1); H::gotoxy(x,y+4); cout<<R"(                      `./  / __   __ \  \,'                          )";
  H::setcolor(1); H::gotoxy(x,y+5); cout<<R"(                       /    /_O)_(_O\    \                           )";
  H::setcolor(1); H::gotoxy(x,y+6); cout<<R"(                       |  .-'  ___  `-.  |                           )";
  H::setcolor(1); H::gotoxy(x,y+7); cout<<R"(                    .--|       \_/       |--.                        )";
  H::setcolor(1); H::gotoxy(x,y+8); cout<<R"(                  ,'    \   \   |   /   /    `.                      )";
  H::setcolor(1); H::gotoxy(x,y+9); cout<<R"(                 /       `.  `--^--'  ,'       \                     )";
  H::setcolor(1); H::gotoxy(x,y+10); cout<<R"(              .-"""""-.    `--.___.--'     .-"""""-.                )";
  H::setcolor(4); H::gotoxy(x,y+11); cout<<R"( .-----------/         \------------------/         \--------------.)";
  H::setcolor(4); H::gotoxy(x,y+12); cout<<R"( | .---------\         /------------------\         /------------. |)";
  H::setcolor(1); H::gotoxy(x,y+13); cout<<R"( | |          `-`--`--'                    `--'--'-'             | |)";
  H::setcolor(1); H::gotoxy(x,y+14); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+15); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+16); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+17); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+18); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+19); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+20); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+21); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+22); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+23); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+24); cout<<R"( | |                                                             | |)";
  H::setcolor(1); H::gotoxy(x,y+25); cout<<R"( | |                                                             | |)";
  H::setcolor(4); H::gotoxy(x,y+26); cout<<R"( | |_____________________________________________________________| |)";
  H::setcolor(4); H::gotoxy(x,y+27); cout<<R"( |_________________________________________________________________|)";
  H::setcolor(1); H::gotoxy(x,y+28); cout<<R"(                    )__________|__|__________(                      )";
  H::setcolor(1); H::gotoxy(x,y+29); cout<<R"(                   |            ||            |                     )";
  H::setcolor(1); H::gotoxy(x,y+30); cout<<R"(                   |____________||____________|                     )";
  H::setcolor(1); H::gotoxy(x,y+31); cout<<R"(                     ),-----.(      ),-----.(                       )";
  H::setcolor(1); H::gotoxy(x,y+32); cout<<R"(                   ,'   ==.   \    /  .==    `.                     )";
  H::setcolor(1); H::gotoxy(x,y+33); cout<<R"(                  /            )  (            \                    )";
  H::setcolor(1); H::gotoxy(x,y+34); cout<<R"(                  `==========='    `==========='                    )";
}


#endif // STUDENT_PROFILE_DESIGN_H