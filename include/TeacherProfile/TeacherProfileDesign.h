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
		static void SnowText();
		static void BearBorder(int x, int y);

};

void TeacherProfileDesign::ChangePasswordText(int x, int y)
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

void TeacherProfileDesign::SnowText()
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

void TeacherProfileDesign::BearBorder(int x, int y)
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

#endif