#ifndef __MAIN_CONTROLLER__
#define __MAIN_CONTROLLER_

#include "../Header_School/ANTHinsyOOP"
#include"Login_Form.h"
#include"Main_menu.h"
using namespace ANTHinsyOOP;

class EDUSYSTEM{
	public:
		static void teamProfile();
		static void showWelcomeScreen();
		static void littleSign(int x, int y , int c);
		static void displayStartScreen();
		static void openAboutUsPage();

};
EDUSYSTEM abu;
Login_Design logD;

void EDUSYSTEM::openAboutUsPage(){
 	system("start /Website/htmlAboutUs/index.html");
}
void EDUSYSTEM::littleSign(int x, int y, int c){
	H::VLine(x,y,1,c,222);
}

void EDUSYSTEM::showWelcomeScreen(){
	int x = 80;
	int y = 10;

	H::setcolor(0);
	H::setcolor(4);H::gotoxy(108, 16); cout << R"(        _______________________________________________         )";
	H::setcolor(4);H::gotoxy(108, 17); cout << R"(       /|                                              |\       )";
	H::setcolor(4);H::gotoxy(108, 18); cout << R"(      /_|______________________________________________|_\      )";
	H::setcolor(14);H::gotoxy(108, 19); cout << R"(     |   _             S C H O O L    B U S             _| \    )";
	H::setcolor(14);H::gotoxy(108, 20); cout << R"(     |  | |    _                                __     | |  |     )";
	H::setcolor(14);H::gotoxy(108, 21); cout << R"(     |  |_|   |_|                              |__|    |_|  |_     )";
	H::setcolor(14);H::gotoxy(108, 22); cout << R"(     |         ___    ___     ___   ___    _          |       \ )";
	H::setcolor(14);H::gotoxy(108, 23); cout << R"(     |   ___  |___|  |___|   |___| |___|  | |   _     |        \ )";
	H::setcolor(14);H::gotoxy(108, 24); cout << R"(     |  |___|         |        |          | |  | |    |  ___    |)";
	H::setcolor(14);H::gotoxy(108, 25); cout << R"(     |_________________________  _______________|   |_|  |___|  |)";
	H::setcolor(14);H::gotoxy(108, 26); cout << R"(     |  ___    ___    ___    ___    ___    ___    ___    ___    |)";
	H::setcolor(14);H::gotoxy(108, 27); cout << R"(     | |___|  |___|  |___|  |___|  |___|  |___|  |___|  |___|   | )";
	H::setcolor(4 );H::gotoxy(108, 28); cout << R"(     |__________________________________________________________|  )";
	H::setcolor(0 );H::gotoxy(108, 29); cout << R"(        O       O                      O       O               )";
	H::setcolor(0) ;H::gotoxy(108, 30); cout << R"(       ( )     ( )                    ( )     ( )              )";
	
	
	
	H::foreColor(2);
	H::gotoxy(x + 15, y + 22);  cout << R"(       @@@   * *   @@@   * *   @@@   * *   @@@   * *   @@@   * *   @@@   * *   @@@   * *   )";
	H::gotoxy(x + 15, y + 23);  cout << R"(       \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   )";
	H::gotoxy(x + 15, y + 24);  cout << R"(        |     |     |     |     |     |     |     |     |     |     |     |     |     | )";
	H::gotoxy(x + 15, y + 25);  cout << R"(     \\\|///\|/// \\\|//\\|//\\\|/\\|/|\\|///\\\|//\\\|///\\|//\\\|//\\\\\|//\\\|\\|//|\\ )";
	H::gotoxy(x + 15, y + 26);  cout << R"(    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^)";


	

	H::gotoxy(x + 18, y + 8);  cout << R"(      @@@      )"; H::setcolor(2);
	H::gotoxy(x + 18, y + 9);  cout << R"(    @@@@@@@    )"; H::setcolor(2);
	H::gotoxy(x + 18, y + 10); cout << R"(   @@@@@@@@@   )"; H::setcolor(2);
	H::gotoxy(x + 18, y + 11); cout << R"(   @@@@ @@@@   )"; H::setcolor(2);
	H::gotoxy(x + 18, y + 12); cout << R"(   @@@@@@@@    )"; H::setcolor(2);
	H::gotoxy(x + 18, y + 13); cout << R"(    @@@@@@     )"; H::setcolor(2);
	H::gotoxy(x + 18, y + 14); cout << R"(      ||       )"; H::setcolor(6);
	H::gotoxy(x + 18, y + 15); cout << R"(      ||       )"; H::setcolor(6);
	H::gotoxy(x + 18, y + 16); cout << R"(     /||\      )"; H::setcolor(6);
	
	H::foreColor(2);
	H::gotoxy(x + 93, y + 8);  cout << R"(      @@@      )"; H::setcolor(2);
	H::gotoxy(x + 93, y + 9);  cout << R"(    @@@@@@@    )"; H::setcolor(2);
	H::gotoxy(x + 93, y + 10); cout << R"(   @@@@@@@@@   )"; H::setcolor(2);
	H::gotoxy(x + 93, y + 11); cout << R"(   @@@@ @@@@   )"; H::setcolor(2);
	H::gotoxy(x + 93, y + 12); cout << R"(   @@@@@@@@    )"; H::setcolor(2);
	H::gotoxy(x + 93, y + 13); cout << R"(    @@@@@@     )"; H::setcolor(2);
	H::gotoxy(x + 93, y + 14); cout << R"(      ||       )"; H::setcolor(6);
	H::gotoxy(x + 93, y + 15); cout << R"(      ||       )"; H::setcolor(6);
	H::gotoxy(x + 93, y + 16); cout << R"(     /||\      )"; H::setcolor(6);

	
	H::gotoxy(x + 90, y + 0);  std::cout << R"(     \  |  /     )"; H::setcolor(6);
	H::gotoxy(x + 90, y + 1);  std::cout << R"(   `. \ | /  .')"; H::setcolor(6);
	H::gotoxy(x + 90, y + 2);  std::cout << R"( --  o  o  o  -- )"; H::setcolor(14);
	H::gotoxy(x + 90, y + 3);  std::cout << R"(   ,  / | \  `. )"; H::setcolor(6);
	H::gotoxy(x + 90, y + 4);  std::cout << R"(     /  |  \     )"; H::setcolor(6);
	
	H::drawBoxDoubleLine(100,15,86,20,5);
	
	H::HLine(20,1,170,3,219);
	H::HLine(15,8,170,3,219);
	
	for(int i = 0; i < 5; i++) {
	    littleSign(15 + i, 5 - i,5);
	}
	for(int i = 0; i < 5; i++) {
	    littleSign(186 + i, 5 - i,5);
	}

	H::setcolor(3); H::gotoxy(41, 1); cout << R"( ________  ______   _____  _____  ____    ____       _       ______   _________  ________  _______        ___  ____   ____  ____  )";
	H::setcolor(4); H::gotoxy(41, 2); cout << R"(|_   __  ||_   _ `.|_   _||_   _||_   \  /   _|     / \    .' ____ \ |  _   _  ||_   __  ||_   __ \      |_  ||_  _| |_   ||   _| )";
	H::setcolor(5); H::gotoxy(41, 3); cout << R"(  | |_ \_|  | | `. \ | |    | |    |   \/   |      / _ \   | (___ \_||_/ | | \_|  | |_ \_|  | |__) |______ | |_/ /     | |__| |   )";
	H::setcolor(3); H::gotoxy(41, 4); cout << R"(  |  _| _   | |  | | | '    ' |    | |\  /| |     / ___ \   _.____`.     | |      |  _| _   |  __ /|______||  __'.     |  __  |   )";
	H::setcolor(4); H::gotoxy(41, 5); cout << R"( _| |__/ | _| |_.' /  \ \__/ /    _| |_\/_| |_  _/ /   \ \_| \____) |   _| |_    _| |__/ | _| |  \ \_     _| |  \ \_  _| |  | |_  )";
	H::setcolor(5); H::gotoxy(41, 6); cout << R"(|________||______.'    `.__.'    |_____||_____||____| |____|\______.'  |_____|  |________||____| |___|   |____||____||____||____| )";

	
	H::drawBoxDoubleLine(10,11,70,14,3); // outer box
	H::drawBoxDoubleLineWithBG(14,13,62,3,5); // INNER BOX
	H::foreColor(6); H::gotoxy(38,15);cout<<"ABOUT US";
	
	H::drawBoxDoubleLineWithBG(14,20,62,3,5); // INNER BOX
	H::foreColor(6); H::gotoxy(36,22);cout<<"GO TO LOGIN ";

	
	
	H::gotoxy(10, 28); H::setcolor(7); cout << R"(      __   _)"; H::delay(30);
	H::gotoxy(10, 29); H::setcolor(7); cout << R"(    _(  )_( )_)"; H::delay(30);
	H::gotoxy(10, 30); H::setcolor(7); cout << R"(   (_   _    _))"; H::delay(30);
	H::gotoxy(10, 31); H::setcolor(7); cout << R"(  / /(_) (__))"; H::delay(30);
	H::gotoxy(10, 32); H::setcolor(0); cout << R"( / / / / / /)"; H::delay(30);
	
	H::gotoxy(40, 28); H::setcolor(7); cout << R"(      __   _)"; H::delay(30);
	H::gotoxy(40, 29); H::setcolor(7); cout << R"(    _(  )_( )_)"; H::delay(30);
	H::gotoxy(40, 30); H::setcolor(7); cout << R"(   (_   _    _))"; H::delay(30);
	H::gotoxy(40, 31); H::setcolor(7); cout << R"(  / /(_) (__))"; H::delay(30);
	H::gotoxy(40, 32); H::setcolor(0); cout << R"( / / / / / /)"; H::delay(30);
	
	H::gotoxy(70, 28); H::setcolor(7); cout << R"(      __   _)"; H::delay(30);
	H::gotoxy(70, 29); H::setcolor(7); cout << R"(    _(  )_( )_)"; H::delay(30);
	H::gotoxy(70, 30); H::setcolor(7); cout << R"(   (_   _    _))"; H::delay(30);
	H::gotoxy(70, 31); H::setcolor(7); cout << R"(  / /(_) (__))"; H::delay(30);
	H::gotoxy(70, 32); H::setcolor(0); cout << R"( / / / / / /)"; H::delay(30);
	
	H::gotoxy(70, 28); H::setcolor(7); cout << R"(      __   _)"; H::delay(30);
	H::gotoxy(70, 29); H::setcolor(7); cout << R"(    _(  )_( )_)"; H::delay(30);
	H::gotoxy(70, 30); H::setcolor(7); cout << R"(   (_   _    _))"; H::delay(30);
	H::gotoxy(70, 31); H::setcolor(7); cout << R"(  / /(_) (__))"; H::delay(30);
	H::gotoxy(70, 32); H::setcolor(0); cout << R"( / / / / / /)"; H::delay(30);
	
//	H::setcursor(0,0);
	int n=1;
		H::gotoxy(13, 40); cout << R"(   |//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//  |//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|//  \\|//\\\|// \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|// )";
		H::gotoxy(13, 41); cout << R"(^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^)";

			for(int i=0;i<170;i++){
				int color;
				H::foreColor(color);
				color++;
				if(color>14){
					color=1;
			}
	
			H::setcolor(n);H::gotoxy(3+i,38);cout<<R"(               ((`\)";H::delay(2);
		    H::setcolor(color);H::gotoxy(3+i,39);cout<<R"(            ___ \\ '--._)";H::delay(2);
		    H::setcolor(color);H::gotoxy(3+i,40);cout<<R"(         .'`   `'    o  ))";H::delay(2);
		    H::setcolor(color);H::gotoxy(3+i,41);cout<<R"(        /    \   '. __.')";H::delay(2);
		    H::setcolor(color);H::gotoxy(3+i,42);cout<<R"(       _|    /_  \ \_\_)";H::delay(2);
		    H::setcolor(color);H::gotoxy(3+i,43);cout<<R"(      {_\______\-'\__\_\)";H::delay(2);

		}
		H::clearBox(9,29,80,16,0);
		H::drawBoxDoubleLine(18,27,52,1,4);
		H::gotoxy(21, 28);
		H::setcolor(7);
		cout << "PRESS ";
		
		H::setcolor(14);
		cout << "[UP] ";
		
		H::setcolor(7);
		cout << ", ";
		
		H::setcolor(14);
		cout << "[DOWN] ";
		
		H::setcolor(7);
		cout << "TO MOVE, ";
		
		H::setcolor(14);
		cout << "[ENTER] ";
		
		H::setcolor(7);
		cout << "TO SELECT";

		H::setcolor(0); H::gotoxy(10, 31); cout << R"(                                                       _____)"; H::delay(60);
		H::setcolor(0); H::gotoxy(10, 32); cout << R"(                                                     /'     `\)"; H::delay(60);
		H::setcolor(0); H::gotoxy(10, 33); cout << R"(  __                                            ___/'         `\)"; H::delay(60);
		H::setcolor(0); H::gotoxy(10, 34); cout << R"(/'  `\_                          _            /'                \)"; H::delay(60);
		H::setcolor(0); H::gotoxy(10, 35); cout << R"(       \________________________( )_________/'                   `\___________)"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 36); cout << R"(                             _  | |                _)"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 37); cout << R"(          _                 ( \ |  )  _           ( ) _)"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 38); cout << R"(       _ ( )                 \ `|  | ( )         _| |/ ))"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 39); cout << R"(      ( \| | _                `\,  |/'/'        ( \  /')"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 40); cout << R"(       \,. |/ )                 |   /'           \  |)"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 41); cout << R"(         |  /'                  |  |              | |)"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 42); cout << R"(         | |                                      | |)"; H::delay(60);
		H::setcolor(2); H::gotoxy(43, 34); cout << R"(_)"; H::delay(60);
		H::setcolor(2); H::gotoxy(41, 35); cout << R"( ( ) )"; H::delay(60);
	
		H::setcolor(0); H::gotoxy(85, 37); cout << R"(   \                                                       _____)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 38); cout << R"(    \                                                     /'     `\)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 39); cout << R"(     \__                                            ___/'         `\)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 40); cout << R"(        `\_                                       /'                \)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 41); cout << R"(           \____________________________________/'                   `\__________________)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 42); cout << R"(                                                                                         \)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 43); cout << R"(                                                                                          \)"; H::delay(60);
		H::setcolor(0); H::gotoxy(85, 44); cout << R"(                                                                                           \)"; H::delay(60);
	
		H::setcolor(2); H::gotoxy(10, 43); cout << R"(   v   v   v   v   v   v   v   v   v   v   v   v   v   v   v   v  v   v   v   v  v  v   v   v  )"; H::delay(60);
		H::setcolor(2); H::gotoxy(10, 44); cout << R"( \/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|)"; H::delay(60);
	
		H::setcolor(2); H::gotoxy(76, 43); cout << R"(   v   v   v   v   v   v   v   v   v   v   v   v   v   v   v   v  v   v   v   v v  v   v   v  v  v)"; H::delay(60);
		H::setcolor(2); H::gotoxy(76, 44); cout << R"( \/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|\/|)"; H::delay(60);

		H::setcolor(7); 
		char choice=getch();
	
	    switch (choice) {	
	        case '1':
	        	EDUSYSTEM::openAboutUsPage();
	            break;

	    }
}


void EDUSYSTEM::teamProfile(){
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
void EDUSYSTEM::displayStartScreen(){
	H::setcursor(false,0);
	H::setFixedScreenConsole(200,45);
//	Login_Design::loadingProcess();
	Login_Design::loadingProcess();
	do {
		showWelcomeScreen();
		int x = 0;  
		char op;
	    do {
	    	
	       	H::drawBoxDoubleLineWithBG(14,13,62,3,5);
			H::foreColor(6); H::gotoxy(38,15);cout<<"ABOUT US";
	
	        H::drawBoxDoubleLineWithBG(14,20,62,3,5); 
			H::foreColor(6); H::gotoxy(36,22);cout<<"GO TO LOGIN";



	        if (x == 0) {
	            H::drawBoxDoubleLineWithBG(14, 13, 62, 3, 2);
	            H::foreColor(15); H::gotoxy(38, 15); cout << "ABOUT US";
	        }
	        else if (x == 1) {
	            H::drawBoxDoubleLineWithBG(14,20 , 62, 3, 2);
	            H::foreColor(15); H::gotoxy(36, 22); cout << "GO TO LOGIN";
	        }
	
	        op = getch();
	
	        switch (op) {
	            case 72: 
	                x--;
	                if (x < 0) {
	                	x = 1; 
					} 
	            break;
	            case 80: 
	                x++;
	                if (x > 1){
	                	x = 0;  
					}
	            break;
	        }
	
	    } while (op != 13); 
	
	    H::cls();
	
	    if (x == 0) {
	    	teamProfile();
	    }
	    if(x==1){
	    	logD.MainLogin();
		}
		
	} while (true);
	
	H::cls();

	
}


#endif