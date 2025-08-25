#ifndef __MAIN_CONTROLLER__
#define __MAIN_CONTROLLER_

#include "../Header_School/ANTHinsyOOP"
#include"Login_Form.h"
using namespace ANTHinsyOOP;

class EDUSYSTEM{
	public:
		static void TeamProfile();
		static void ShowWelcomeScreen();
		static void LittleSign(int x, int y , int c);
		static void OpenAboutUsPage();
		static void MainProfile();
		static void MainAboutUs();
		static void LetterFromUs();
		static void VN(const string &str);
		static void DisplayStartScreen();


};
EDUSYSTEM abu;
Login_Design logD;
bool notLoadingYet = true;

void EDUSYSTEM::OpenAboutUsPage(){
 	system("start /Website/htmlAboutUs/index.html");
}
void EDUSYSTEM::LittleSign(int x, int y, int c){
	H::VLine(x,y,1,c,222);
}
// update about us from this
void EDUSYSTEM::VN(const string &str){ 
	 int j = 1; 
	 for(int i = 0;i<str.length();i++) 
	 { 
	  cout << str[i];H::delay(5); 
	  j++; 
	 } 
}

void EDUSYSTEM::LetterFromUs(){

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
void EDUSYSTEM::MainProfile(){
	
	
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
// main function abbout us

void EDUSYSTEM::MainAboutUs(){
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
			EDUSYSTEM::TeamProfile();
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
		    EDUSYSTEM::DisplayStartScreen();
		}
	H::foreColor(0);

	
	}while(true);
}
void EDUSYSTEM::ShowWelcomeScreen(){
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
	    LittleSign(15 + i, 5 - i,5);
	}
	for(int i = 0; i < 5; i++) {
	    LittleSign(186 + i, 5 - i,5);
	}

	H::setcolor(3); H::gotoxy(41, 1); cout << R"( ________  ______   _____  _____  ____    ____       _       ______   _________  ________  _______        ___  ____   ____  ____  )";
	H::setcolor(4); H::gotoxy(41, 2); cout << R"(|_   __  ||_   _ `.|_   _||_   _||_   \  /   _|     / \    .' ____ \ |  _   _  ||_   __  ||_   __ \      |_  ||_  _| |_   ||   _| )";
	H::setcolor(5); H::gotoxy(41, 3); cout << R"(  | |_ \_|  | | `. \ | |    | |    |   \/   |      / _ \   | (___ \_||_/ | | \_|  | |_ \_|  | |__) |______ | |_/ /     | |__| |   )";
	H::setcolor(3); H::gotoxy(41, 4); cout << R"(  |  _| _   | |  | | | '    ' |    | |\  /| |     / ___ \   _.____`.     | |      |  _| _   |  __ /|______||  __'.     |  __  |   )";
	H::setcolor(4); H::gotoxy(41, 5); cout << R"( _| |__/ | _| |_.' /  \ \__/ /    _| |_\/_| |_  _/ /   \ \_| \____) |   _| |_    _| |__/ | _| |  \ \_     _| |  \ \_  _| |  | |_  )";
	H::setcolor(5); H::gotoxy(41, 6); cout << R"(|________||______.'    `.__.'    |_____||_____||____| |____|\______.'  |_____|  |________||____| |___|   |____||____||____||____| )";

	
	H::drawBoxDoubleLine(10,11,70,14,3); // outer box
	H::drawBoxDoubleLineWithBG(14,13,62,3,5); // INNER BOX
	H::foreColor(6); H::gotoxy(37,15);cout<<"ADMIN DETAILS";
	
	H::drawBoxDoubleLineWithBG(14,20,62,3,5); // INNER BOX
	H::foreColor(6); H::gotoxy(37,22);cout<<"GO TO LOGIN ";
	
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
	        	EDUSYSTEM::OpenAboutUsPage();
	            break;

	    }
}


void EDUSYSTEM::TeamProfile(){
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
	H::gotoxy(82,18);H::foreColor(199);cout<<"MENTOR NAME : RUN LIHOU";
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

void EDUSYSTEM::DisplayStartScreen(){
	H::setcursor(false,0);
	H::setFixedScreenConsole(200,45);
	if(notLoadingYet){
		Login_Design::loadingProcess();
		notLoadingYet = false;
	}
	do {
		ShowWelcomeScreen();
		int x = 0;  
		char op;
	    do {
	    	
	       	H::drawBoxDoubleLineWithBG(14,13,62,3,5); // INNER BOX
			H::foreColor(6); H::gotoxy(37,15);cout<<"ADMIN DETAILS";
	
	        H::drawBoxDoubleLineWithBG(14,20,62,3,5); 
			H::foreColor(6); H::gotoxy(37,22);cout<<"GO TO LOGIN";



	        if (x == 0) {
	            H::drawBoxDoubleLineWithBG(14, 13, 62, 3, 2);
	            H::foreColor(15); H::gotoxy(37, 15); cout << "ADMIN DETAILS";
	        }
	        else if (x == 1) {
	            H::drawBoxDoubleLineWithBG(14,20 , 62, 3, 2);
	            H::foreColor(15); H::gotoxy(37, 22); cout << "GO TO LOGIN";
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
	    	MainAboutUs();
	    }
	    if(x==1){
	    	logD.MainLogin();
		}
		
	} while (true);
	
	H::cls();
}
#endif