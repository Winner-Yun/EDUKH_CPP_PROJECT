#ifndef ___EDU_STUDENTMANAGERMENT_H___
#define ___EDU_STUDENTMANAGERMENT_H___

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;
class Student{
	private:
		char id[6], name[19], gender[7], bdate[11], grade[3], tel[10], sYear[5], email[30], pw[19];
		int No;
        static int lastId;
	public:
		void Main_StudentManage(); //Main
		
		//Student Management Design Method
        static void Menu(const string& titleType);
        static void Button();
        static void System();
        static void Found();
        static void NotFound();
        static void Delete_Loading();
        static void Search_Loading();
        static void Add_Loading();
        static void Sort_Loading();
        static void findStudentById(const string& searchId);
		static void showAllStudents();

        //Student Management Sub Method
		void Design_Input();
		void Design_Update();
		void Design_search();
		void InputData();
		void Search();
		void Update();
		void Delete();
		void Sort();
		void SaveToFile();
		void ArrowKey();
		void ShowTableData();
		void convertToEmail();
		void updateSharedFileFromStudentData();
};

//Global
Student s;
int Student::lastId = 0;

void Student::System(){
	// H::setConsoleTitle("<------------------------ STUDENT MANAGEMENT ------------------------>");
	H::setFixedScreenConsole(200, 50);
	for (int i = 8; i <= 120; i++) {
		H::foreColor(4);
		H::gotoxy(i - 3, 7);  cout << R"(  _____    _       )";
		H::gotoxy(i - 3, 8);  cout << R"( | ____|__| |_   _ )";
		H::gotoxy(i - 3, 9);  cout << R"( |  _| / _` | | | |)";
		H::gotoxy(i - 3, 10);  cout << R"( | |__| (_| | |_| |)";
		H::gotoxy(i - 3, 11);  cout << R"( |_____\__,_|\__,_|)";
		
		H::foreColor(1);
		H::gotoxy(70, 15);  cout << R"( __  __           _            _  ___   _ )";
		H::gotoxy(70, 16);  cout << R"(|  \/  | __ _ ___| |_ ___ _ __| |/ / | | |)";
		H::gotoxy(70, 17);  cout << R"(| |\/| |/ _` / __| __/ _ \ '__| ' /| |_| |)";
		H::gotoxy(70, 18);  cout << R"(| |  | | (_| \__ \ ||  __/ |  | . \|  _  |)";
		H::gotoxy(70, 19);  cout << R"(|_|  |_|\__,_|___/\__\___|_|  |_|\_\_| |_|)";
		
		H::foreColor(6);
		H::gotoxy(150 - i, 24); cout << R"( ____            _                     )";
		H::gotoxy(150 - i, 25); cout << R"(/ ___| _   _ ___| |_ ___ _ __ ___     )";
		H::gotoxy(150 - i, 26); cout << R"(\___ \| | | / __| __/ _ \ '_ ` _ \    )";
		H::gotoxy(150 - i, 27); cout << R"( ___) | |_| \__ \ ||  __/ | | | | |   )";
		H::gotoxy(150 - i, 28); cout << R"(|____/ \__, |___/\__\___|_| |_| |_|   )";
		H::gotoxy(150 - i, 29); cout << R"(        |___/                         )";
		
		H::delay(5);
	}
	
	H::delay(2);
	for (int i = 5; i <= 180; i++)
	{
	  H::HLine(14, 1, i, 34, ' ');       
	  H::HLine(12, 2, i, 31, ' ');       
	  H::HLine(10, 3, i, 204, ' ');      
	
	  H::HLine(196 - i, 37, 1, 204, ' '); 
	  H::HLine(194 - i, 38, 1, 31, ' ');  
	  H::HLine(192 - i, 39, 1, 34, ' ');  
	}
	
	for (int i = 5; i <= 30; i++){
	  H::VLine(5, 6, i - 3, 224, ' ');   
	  H::VLine(6, 6, i - 3, 224, ' ');   
	  H::VLine(7, 5, i - 1, 31, ' ');    
	  H::VLine(8, 5, i - 1, 31, ' ');    
	  H::VLine(9, 4, i + 1, 204, ' ');   
	  H::VLine(10, 4, i + 1, 204, ' ');   
	
	  H::VLine(191, 4, i + 1, 204, ' '); 
	  H::VLine(192, 4, i + 1, 204, ' '); 
	  H::VLine(193, 5, i - 1, 31, ' ');  
	  H::VLine(194, 5, i - 1, 31, ' ');  
	  H::VLine(195, 6, i - 3, 224, ' '); 
	  H::VLine(196, 6, i - 3, 224, ' '); 
	  
	}
	
	H::delay(500);
	H::cls();
	H::foreColor(0);
}

void Student::Menu(const string& titleType) {
    H::setFixedScreenConsole(200, 50);
    H::cls();
    
    if (titleType == "DELETE") {
        H::setcolor(2); H::gotoxy(67, 3); cout << R"( ____       _      _           ____  _             _            _   )";
        H::setcolor(2); H::gotoxy(67, 4); cout << R"(|  _ \  ___| | ___| |_ ___    / ___|| |_ _   _  __| | ___ _ __ | |_ )";
        H::setcolor(3); H::gotoxy(67, 5); cout << R"(| | | |/ _ \ |/ _ \ __/ _ \   \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
        H::setcolor(4); H::gotoxy(67, 6); cout << R"(| |_| |  __/ |  __/ ||  __/    ___) | |_| |_| | (_| |  __/ | | | |_ )";
        H::setcolor(5); H::gotoxy(67, 7); cout << R"(|____/ \___|_|\___|\__\___|   |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
        H::HLine(64, 9, 73, 5, 223);
    }
    else if (titleType == "SORT"){
        H::setcolor(2); H::gotoxy(50, 3); cout << R"( ____             _     ____  _             _            _   )";
        H::setcolor(2); H::gotoxy(50, 4); cout << R"(/ ___|  ___  _ __| |_  / ___|| |_ _   _  __| | ___ _ __ | |_ )";
        H::setcolor(3); H::gotoxy(50, 5); cout << R"(\___ \ / _ \| '__| __| \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
        H::setcolor(4); H::gotoxy(50, 6); cout << R"( ___) | (_) | |  | |_   ___) | |_| |_| | (_| |  __/ | | | |_ )";
        H::setcolor(5); H::gotoxy(50, 7); cout << R"(|____/ \___/|_|   \__| |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
        H::HLine(48, 9, 105, 5, 223);
    }

    else if (titleType == "UPDATE") {
        H::setcolor(2); H::gotoxy(65, 3); cout << R"( _   _           _       _          ____  _             _            _   )";
        H::setcolor(2); H::gotoxy(65, 4); cout << R"(| | | |_ __   __| | __ _| |_ ___   / ___|| |_ _   _  __| | ___ _ __ | |_ )";
        H::setcolor(3); H::gotoxy(65, 5); cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \  \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
        H::setcolor(4); H::gotoxy(65, 6); cout << R"(| |_| | |_) | (_| | (_| | ||  __/   ___) | |_| |_| | (_| |  __/ | | | |_ )";
        H::setcolor(5); H::gotoxy(65, 7); cout << R"( \___/| .__/ \__,_|\__,_|\__\___|  |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
        H::setcolor(5); H::gotoxy(65, 8); cout << R"(      |_|                        )";
        H::HLine(63, 9, 77, 5, 223);
    }
    else if (titleType == "SEARCH") {
        H::setcolor(2); H::gotoxy(65, 3); cout << R"( ____                      _        ____  _             _            _   )";
        H::setcolor(2); H::gotoxy(65, 4); cout << R"(/ ___|  ___  __ _ _ __ ___| |__    / ___|| |_ _   _  __| | ___ _ __ | |_ )";
        H::setcolor(3); H::gotoxy(65, 5); cout << R"(\___ \ / _ \/ _` | '__/ __| '_ \   \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
        H::setcolor(4); H::gotoxy(65, 6); cout << R"( ___) |  __/ (_| | | | (__| | | |   ___) | |_| |_| | (_| |  __/ | | | |_ )";
        H::setcolor(5); H::gotoxy(65, 7); cout << R"(|____/ \___|\__,_|_|  \___|_| |_|  |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
        H::HLine(63, 9, 77, 5, 223);
    }
    else if (titleType == "DEFAULT"){
        H::setcolor(2); H::gotoxy(50, 3); cout << R"( ____  _             _            _       ___        __                            _   _             )";
        H::setcolor(2); H::gotoxy(50, 4); cout << R"(/ ___|| |_ _   _  __| | ___ _ __ | |_    |_ _|_ __  / _| ___  _ __ _ __ ___   __ _| |_(_) ___  _ __  )";
        H::setcolor(3); H::gotoxy(50, 5); cout << R"(\___ \| __| | | |/ _` |/ _ \ '_ \| __|    | || '_ \| |_ / _ \| '__| '_ ` _ \ / _` | __| |/ _ \| '_ \ )";
        H::setcolor(4); H::gotoxy(50, 6); cout << R"( ___) | |_| |_| | (_| |  __/ | | | |_     | || | | |  _| (_) | |  | | | | | | (_| | |_| | (_) | | | |)";
        H::setcolor(5); H::gotoxy(50, 7); cout << R"(|____/ \__|\__,_|\__,_|\___|_| |_|\__|   |___|_| |_|_|  \___/|_|  |_| |_| |_|\__,_|\__|_|\___/|_| |_|)";
        H::HLine(48, 9, 105, 5, 223);
    }
    
	
	int x = 185;
	H::setcolor(3);
	H::gotoxy(0, 0);  cout << R"(             _|)";   H::gotoxy(x, 0);  cout << R"(|_             )";
	H::gotoxy(0, 1);  cout << R"(\_-_-_-_-_-_/)";     H::gotoxy(x, 1);  cout << R"(  \_-_-_-_-_-_/)";
	H::gotoxy(0, 2);  cout << R"( \ _______ /)";      H::gotoxy(x, 2);  cout << R"(   \ _______ /)";
	H::gotoxy(0, 3);  cout << R"(  |_______|)";       H::gotoxy(x, 3);  cout << R"(    |_______|)";
	H::gotoxy(0, 4);  cout << R"(  |       |)";       H::gotoxy(x, 4);  cout << R"(    |       |)";
	H::gotoxy(0, 5);  cout << R"(  |_______|)";       H::gotoxy(x, 5);  cout << R"(    |_______|)";
	H::gotoxy(0, 6);  cout << R"(  \       /)";       H::gotoxy(x, 6);  cout << R"(    \       /)";
	H::gotoxy(0, 7);  cout << R"(   | | | |)";        H::gotoxy(x, 7);  cout << R"(     | | | |)";
	H::gotoxy(0, 8);  cout << R"(   | | | |)";        H::gotoxy(x, 8);  cout << R"(     | | | |)";
	H::gotoxy(0, 9);  cout << R"(   | | | |)";        H::gotoxy(x, 9);  cout << R"(     | | | |)";
	
	for (int i = 10; i <= 40; ++i) {
	    H::gotoxy(0, i); cout << R"(   | | | |)";
	    H::gotoxy(x+2, i); cout << R"(   | | | |)";
	}
	
	H::gotoxy(0, 41); cout << R"(  /_______\)";       H::gotoxy(x, 41); cout << R"(    /_______\)";
	H::gotoxy(0, 42); cout << R"(  |       |)";       H::gotoxy(x, 42); cout << R"(    |       |)";
	H::gotoxy(0, 43); cout << R"(  |_______|)";       H::gotoxy(x, 43); cout << R"(    |_______|)";
	H::gotoxy(0, 44); cout << R"(  |_______|)";       H::gotoxy(x, 44); cout << R"(    |_______|)";
	H::gotoxy(0, 45); cout << R"( /-_-_-_-_-\)";      H::gotoxy(x, 45); cout << R"(   /-_-_-_-_-\)";
	H::gotoxy(0, 46); cout << R"(/___________\)";     H::gotoxy(x, 46); cout << R"(  /___________\)";
	
	H::setcolor(4);
    H::gotoxy(15, 0); cout << R"( | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |)";
    H::gotoxy(13, 1); cout << R"(_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|)";
	H::gotoxy(12, 2); cout << R"(UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU)";

	//Table
	H::drawBoxDoubleLine(15, 14, 170, 1, 2);
	H::drawBoxDoubleLine(15, 17, 170, 24, 3);
	H::setcolor(6);
	H::gotoxy(20,15); cout << "ID";
	H::gotoxy(36,15); cout << "NAME";
	H::gotoxy(60,15); cout << "GENDER";
	H::gotoxy(77,15); cout << "DATE OF BIRTH";
	H::gotoxy(100,15); cout << "GRADE";
	H::gotoxy(119,15); cout << "TEL";
	H::gotoxy(134,15); cout << "ACADEMIC YEAR";
	H::gotoxy(162,15); cout << "EMAIL";
	
	H::setcolor(159); H::gotoxy(14, 44); cout << "<---"; H::setcolor(103); H::gotoxy(20, 44); cout << "[Previous Page]";
	H::setcolor(159); H::gotoxy(182, 44); cout << "--->";  H::setcolor(103); H::gotoxy(165, 44); cout << "[Previous Page]";
	
	//Bottom
	H::HLine(0, 47, 200, 6, 223);
	H::gotoxy(58, 48); H::setcolor(10); cout << "[Right Arrow] Back        [Left Arrow] Next       [Enter] Select       [ESC] Exit";
	H::HLine(0, 49, 200, 6, 220);
	showAllStudents();
}

void Student::NotFound() {
	H::gotoxy(52, 26); H::setcolor(4); cout << R"( ____  _             _            _      _   _       _      _____                     _   _ _ _ )";
    H::gotoxy(52, 27); H::setcolor(4); cout << R"(/ ___|| |_ _   _  __| | ___ _ __ | |_   | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |)";
    H::gotoxy(52, 28); H::setcolor(4); cout << R"(\___ \| __| | | |/ _` |/ _ \ '_ \| __|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |)";
    H::gotoxy(52, 29); H::setcolor(4); cout << R"( ___) | |_| |_| | (_| |  __/ | | | |_   | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|)";
    H::gotoxy(52, 30); H::setcolor(4); cout << R"(|____/ \__|\__,_|\__,_|\___|_| |_|\__|  |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_))";
}

void Student::Found() {
	H::gotoxy(60, 27); H::setcolor(2); cout << R"( ____  _             _            _      _____                     _   _ _ _ )";
    H::gotoxy(60, 28); H::setcolor(2); cout << R"(/ ___|| |_ _   _  __| | ___ _ __ | |_   |  ___|__  _   _ _ __   __| | | | | |)";
    H::gotoxy(60, 29); H::setcolor(2); cout << R"(\___ \| __| | | |/ _` |/ _ \ '_ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |)";
    H::gotoxy(60, 30); H::setcolor(2); cout << R"( ___) | |_| |_| | (_| |  __/ | | | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|)";
    H::gotoxy(60, 31); H::setcolor(2); cout << R"(|____/ \__|\__,_|\__,_|\___|_| |_|\__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_))";
}

void Student::Button() {
	H::drawBoxSingleLine(15, 10, 8, 1, 206); H::gotoxy(15, 11); cout << "  BACK  ";
	H::drawBoxSingleLine(35, 10, 9, 1, 158); H::gotoxy(35, 11); cout << "   SORT  ";
	H::drawBoxSingleLine(115, 10, 9, 1, 158); H::gotoxy(115, 11); cout << "   ADD   ";
	H::drawBoxSingleLine(135, 10, 10, 1, 158); H::gotoxy(135, 11); cout << "  UPDATE  ";
	H::drawBoxSingleLine(155, 10, 10, 1, 158); H::gotoxy(155, 11); cout << "  DELETE  ";
	H::drawBoxSingleLine(175, 10, 10, 1, 158); H::gotoxy(175, 11); cout << "  SEARCH  ";
}

void Student::Design_Input() {
	H::drawBoxSingleLine(50, 5, 100, 7, 153);
    H::foreColor(154); H::gotoxy(49, 5); cout << "><";
    H::delay(50); H::foreColor(3); H::gotoxy(63, 6); cout << R"(   ___                   _       ____  _             _            _   )";
    H::delay(50); H::foreColor(4); H::gotoxy(63, 7); cout << R"(  |_ _|_ __  _ __  _   _| |_    / ___|| |_ _   _  __| | ___ _ __ | |_ )";
    H::delay(50); H::foreColor(5); H::gotoxy(63, 8); cout << R"(   | || '_ \| '_ \| | | | __|   \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
    H::delay(50); H::foreColor(6); H::gotoxy(63, 9); cout << R"(   | || | | | |_) | |_| | |_     ___) | |_| |_| | (_| |  __/ | | | |_ )";
    H::delay(50); H::foreColor(7); H::gotoxy(63, 10); cout << R"(  |___|_| |_| .__/ \__,_|\__|   |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
    H::delay(50); H::foreColor(7); H::gotoxy(63, 11); cout << R"(            |_|                                                      )";
    
	H::delay(10); H::foreColor(3); H::gotoxy(10, 1); cout << R"(  __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(10, 2); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(10, 3); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(10, 4); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(10, 5); cout << R"(  / |  | \)";
    
    H::delay(10); H::foreColor(3); H::gotoxy(33, 7); cout << R"(  __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(33, 8); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(33, 9); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(33, 10); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(33, 11); cout << R"(  / |  | \)";
    
    H::delay(10); H::foreColor(3); H::gotoxy(180, 1); cout << R"(  __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(180, 2); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(180, 3); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(180, 4); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(180, 5); cout << R"(  / |  | \)";
    
    H::delay(10); H::foreColor(3); H::gotoxy(155, 7); cout << R"(  __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(155, 8); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(155, 9); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(155, 10); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(155, 11); cout << R"(  / |  | \)";
	
	H::drawBoxDoubleLineWithBG(25, 18, 150, 25, 0);
    H::drawBoxDoubleLineWithBG(30, 20, 140, 21, 145);
    
    H::VLine(85,14,1,7,186);
    H::VLine(85,15,1,7,186);
    H::VLine(85,16,1,7,186);
    H::VLine(85,13,1,7,186);
    
    H::VLine(105,14,1,7,186);
    H::VLine(105,15,1,7,186);
    H::VLine(105,16,1,7,186);
    H::VLine(105,13,1,7,186);
    
    H::drawBoxSingleLineWithBG(32,22,50,1,213);
    H::drawBoxSingleLineWithBG(32,28,50,1,213);
    H::drawBoxSingleLineWithBG(32,34,50,1,213);
    
    H::drawBoxSingleLineWithBG(115,22,50,1,213);
    H::drawBoxSingleLineWithBG(115,28,50,1,213);
    H::drawBoxSingleLineWithBG(115,34,50,1,213);
    
    H::drawBoxSingleLineWithBG(75,39,50,1,213);
    
    H::gotoxy(33, 23);  H::foreColor(215); cout << "Student ID      :";
    H::gotoxy(33, 29);  H::foreColor(215); cout << "Student Name    :";
    H::gotoxy(33, 35);  H::foreColor(215); cout << "Gender          :";
    H::gotoxy(116, 23); H::foreColor(215); cout << "Date of Birth   :";
    H::gotoxy(116, 29); H::foreColor(215); cout << "Grade           :";
    H::gotoxy(116, 35); H::foreColor(215); cout << "Phone Number    :";
    H::gotoxy(76, 40);  H::foreColor(215); cout << "Academic Year   :";
}

void Student::Delete_Loading() {
	H::foreColor(3); H::gotoxy(60, 9); cout << R"( ______   ________  _____     ________  _________   _____  ____  _____    ______  )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"(|_   _ `.|_   __  ||_   _|   |_   __  ||  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(  | | `. \ | |_ \_|  | |       | |_ \_||_/ | | \_|  | |    |   \ | |  / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"(  | |  | | |  _| _   | |   _   |  _| _     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"( _| |_.' /_| |__/ | _| |__/ | _| |__/ |   _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"(|______.'|________||________||________|  |_____|  |_____||_____|\____| `._____.' )";	
}

void Student::Search_Loading() {
	H::foreColor(3); H::gotoxy(55, 9); cout << R"(  ______   ________       _       _______      ______  ____  ____  _____  ____  _____   ______  )";
	H::foreColor(3); H::gotoxy(55, 10); cout << R"(.' ____ \ |_   __  |     / \     |_   __ \   .' ___  ||_   ||   _||_   _||_   \|_   _|.' ___  | )";
	H::foreColor(3); H::gotoxy(55, 11); cout << R"(| (___ \_|  | |_ \_|    / _ \      | |__) | / .'   \_|  | |__| |    | |    |   \ | | / .'   \_| )";
	H::foreColor(3); H::gotoxy(55, 12); cout << R"( _.____`.   |  _| _    / ___ \     |  __ /  | |         |  __  |    | |    | |\ \| | | |   ____ )";
	H::foreColor(3); H::gotoxy(55, 13); cout << R"(| \____) | _| |__/ | _/ /   \ \_  _| |  \ \_\ `.___.'\ _| |  | |_  _| |_  _| |_\   |_\ `.___]  |)";
	H::foreColor(7); H::gotoxy(55, 14); cout << R"( \______.'|________||____| |____||____| |___|`.____ .'|____||____||_____||_____|\____|`._____.' )";
}

void Student::Add_Loading() {
	H::foreColor(3); H::gotoxy(60, 9);  cout << R"(   ______  _______     ________       _     _________  _____  ____  _____    ______ )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"( .' ___  ||_   __ \   |_   __  |     / \   |  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(/ .'   \_|  | |__) |    | |_ \_|    / _ \  |_/ | | \_|  | |    |   \ | |  / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"(| |         |  __ /     |  _| _    / ___ \     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"(\ `.___.'\ _| |  \ \_  _| |__/ | _/ /   \ \_  _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"( `.____ .'|____| |___||________||____| |____||_____|  |_____||_____|\____| `._____.')";
}

void Student::Sort_Loading() {
	H::foreColor(3); H::gotoxy(60, 9);  cout << R"(  ______     ___   _______   _________  _____  ____  _____   ______  )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"(.' ____ \  .'   `.|_   __ \ |  _   _  ||_   _||_   \|_   _|.' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(| (___ \_|/  .-.  \ | |__) ||_/ | | \_|  | |    |   \ | | / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"( _.____`. | |   | | |  __ /     | |      | |    | |\ \| | | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"(| \____) |\  `-'  /_| |  \ \_  _| |_    _| |_  _| |_\   |_\ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"( \______.' `.___.'|____| |___||_____|  |_____||_____|\____|`._____.' )";
}
                                                            
void Student::InputData() {
    if (lastId == 0) {
        ifstream file("../data/Student_Data.bin", ios::binary);
        while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            int num = atoi(s.id + 2);
            if (num > lastId) {
                lastId = num;
            }
        }
        file.close();
    }

    lastId++;
    sprintf(id, "S-%03d", lastId);

    H::gotoxy(56, 23); cout << id;
    H::gotoxy(56, 29); H::inputLetter(name, 16);
    H::gotoxy(56, 35); H::inputLetter(gender, 7);
    H::gotoxy(139, 23); H::inputDate(bdate, true);
    H::gotoxy(139, 29); H::inputNumber(grade, 3);
    H::gotoxy(139, 35); H::input4Tel(tel, 10);
    H::gotoxy(99, 40); H::inputNumber(sYear, 5);
    H::setcolor(1);
    strcpy(pw, "123");
    
    H::cls();
    Add_Loading();
    H::setcolor(7); H::gotoxy(47, 23); cout << "Loading...";
    H::drawBoxSingleLineWithBG(47,24,105,1,15);
    for (int i = 47; i <= 147; i++) {
        H::HLine(i, 25, 1, 15, 177);
        cout << i - 47 << "%";
        H::delay(15);
    }
}


void Student::convertToEmail() {
	string n(name);
	for (int i = 0; i < n.length(); i++) {
        if (n[i] == ' ') n[i] = '.';
    }
	string em = "stu." + n + "@gmail.com";
	strncpy(email, em.c_str(), sizeof(email) - 1);
	email[sizeof(email) - 1] = '\0';
}

void Student::SaveToFile() {
    ofstream file1("../data/Student_Data.bin", ios::binary | ios::app);
    ofstream file2("../data/TeacherAndStudent_data.bin", ios::binary | ios::app);

    if (file1.is_open() && file2.is_open()) {
        file1.write(reinterpret_cast<char*>(this), sizeof(Student));
        file2.write(reinterpret_cast<char*>(this), sizeof(Student));
        file1.close();
        file2.close();
    } else {
        H::setcolor(74); H::gotoxy(92, 48); cout << "Unable to open one or both files";
    }
}

void Student::updateSharedFileFromStudentData() {
    ifstream in("../data/Student_Data.bin", ios::binary);
    ofstream out("../data/TeacherAndStudent_data.bin", ios::binary);

    Student temp;
    while (in.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        out.write(reinterpret_cast<char*>(&temp), sizeof(Student));
    }
    in.close();
    out.close();
}

void Student::showAllStudents() {
    ifstream file("../data/Student_Data.bin", ios::binary);
    int row = 18;
    int colorCodes[] = {9, 10, 7, 11, 14};
    int colorIndex = 0;

    if (!file.is_open()) {
        H::gotoxy(90, 20); H::setcolor(4); cout << "Unable to open Student_Data.bin";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        int color = colorCodes[colorIndex % 5];
        H::setcolor(color);
        H::gotoxy(19, row + 1);  cout << setw(10) << left << s.id;
        H::gotoxy(34, row + 1);  cout << setw(24) << left << s.name;
        H::gotoxy(60, row + 1);  cout << setw(12) << left << s.gender;
        H::gotoxy(78, row + 1);  cout << setw(18) << left << s.bdate;
        H::gotoxy(101, row + 1); cout << setw(14) << left << s.grade;
        H::gotoxy(116, row + 1); cout << setw(16) << left << s.tel;
        H::gotoxy(138, row + 1); cout << setw(22) << left << s.sYear;
        H::gotoxy(153, row + 1); cout << setw(30) << left << s.email;
        row += 3;
        colorIndex++;
    }
    file.close();
}

void Student::Update() {
    char updateId[10];
    H::cls();
    Menu("UPDATE");
    H::gotoxy(82, 44); H::setcolor(11); cout << "Enter Student ID to Update: ";
    H::inputUNumber(updateId, 10);

    ifstream file("../data/Student_Data.bin", ios::binary);
    ofstream temp("../data/Temp.bin", ios::binary);
    bool updated = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (strcmp(s.id + 2, updateId) == 0) {
            updated = true;
            H::cls();
            s.Design_Input();
            H::gotoxy(56, 23); cout << s.id;
            H::gotoxy(56, 29); H::inputLetter(s.name, 18);
            H::gotoxy(56, 35); H::inputLetter(s.gender, 7);
            H::gotoxy(139, 23); H::inputDate(s.bdate, true);
            H::gotoxy(139, 29); H::inputNumber(s.grade, 3);
            H::gotoxy(139, 35); H::input4Tel(s.tel, 10);
            H::gotoxy(99, 40); H::inputNumber(s.sYear, 5);
            strcpy(s.pw, "123");
            s.convertToEmail();
        }
        temp.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    file.close();
    temp.close();
    remove("../data/Student_Data.bin");
    rename("../data/Temp.bin", "../data/Student_Data.bin");

    if (updated) {
        H::gotoxy(85, 44); H::setcolor(10); cout << "Student updated successfully!";
    } else {
        H::gotoxy(85, 44); H::setcolor(4); cout << "Student ID not found!";
    }
	updateSharedFileFromStudentData();
    getch();
}

void Student::Delete() {
    char deleteId[10];
    H::cls();
    Menu("DELETE");
    H::gotoxy(82, 44); H::setcolor(7); cout << "Enter Student ID to Delete: ";
    H::inputUNumber(deleteId, 10);

    ifstream file("../data/Student_Data.bin", ios::binary);
    ofstream temp("../data/Temp.bin", ios::binary);
    bool deleted = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (strcmp(s.id + 2, deleteId) == 0) {
            deleted = true;
        } else {
            temp.write(reinterpret_cast<char*>(&s), sizeof(Student));
        }
    }

    file.close();
    temp.close();
    remove("../data/Student_Data.bin");
    rename("../data/Temp.bin", "../data/Student_Data.bin");

    if (deleted) {
        H::cls();
        Delete_Loading();
        H::setcolor(7); H::gotoxy(47, 23); cout << "Loading...";
        H::drawBoxSingleLineWithBG(47,24,105,1,15);
        for (int i = 47; i <= 147; i++) {
            H::HLine(i, 25, 1, 15, 177);
            cout << i - 47 << "%";
            H::delay(15);
        }
    } else {
        s.NotFound();
        getch();
    }
    updateSharedFileFromStudentData();
}

void Student::Search() {
    char searchId[10];
    H::cls();
    Menu("SEARCH");
    H::gotoxy(70, 44); H::setcolor(11); cout << "Enter Student ID to Search: ";
    H::inputUNumber(searchId, 5);

    ifstream file("../data/Student_Data.bin", ios::binary);
    bool found = false;
    int row = 18;
	H::clearBox(16, 19, 168, 22, 3);
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (strcmp(s.id + 2, searchId) == 0) {
            found = true;
            H::drawBoxDoubleLine(17, row+1, 166, 1, 9);
            H::setcolor(7);
            H::gotoxy(19, row+2);  cout << setw(10) << left << s.id;
            H::gotoxy(34, row+2);  cout << setw(24) << left << s.name;
            H::gotoxy(60, row+2);  cout << setw(12) << left << s.gender;
            H::gotoxy(78, row+2);  cout << setw(18) << left << s.bdate;
            H::gotoxy(101, row+2); cout << setw(14) << left << s.grade;
            H::gotoxy(116, row+2); cout << setw(16) << left << s.tel;
            H::gotoxy(138, row+2); cout << setw(22) << left << s.sYear;
            H::gotoxy(153, row+2); cout << setw(30) << left << s.email;
            break;
        }
    }
    file.close();
    if (!found) s.NotFound();
    else s.Found();
    getch();
}

void Student::Sort() {
    H::cls();
    Menu("SORT BY NAME");
    Sort_Loading();

    const int MAX_STUDENTS = 1000;
    Student students[MAX_STUDENTS];
    int count = 0;

    ifstream file("../data/Student_Data.bin", ios::binary);
    if (!file.is_open()) {
        H::gotoxy(80, 20); H::setcolor(4); cout << "Unable to open Student_Data.bin";
        getch();
        return;
    }

    while (file.read(reinterpret_cast<char*>(&students[count]), sizeof(Student)) && count < MAX_STUDENTS) {
        count++;
    }
    file.close();

    if (count == 0) {
        H::gotoxy(85, 22); H::setcolor(4); cout << "No student data found!";
        getch();
        return;
    }

    // Step 2: Bubble sort by name (A-Z)
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Step 3: Draw table header
    H::drawBoxDoubleLine(17, 15, 166, 1, 9);
    H::setcolor(15);
    H::gotoxy(19, 16);  cout << setw(10) << left << "ID";
    H::gotoxy(34, 16);  cout << setw(24) << left << "Name";
    H::gotoxy(60, 16);  cout << setw(12) << left << "Gender";
    H::gotoxy(78, 16);  cout << setw(18) << left << "Birthdate";
    H::gotoxy(101, 16); cout << setw(14) << left << "Grade";
    H::gotoxy(116, 16); cout << setw(16) << left << "Tel";
    H::gotoxy(138, 16); cout << setw(22) << left << "Acad. Year";
    H::gotoxy(153, 16); cout << setw(30) << left << "Email";

    // Step 4: Display sorted students
    int row = 18;
    int colorCodes[] = {9, 10, 7, 11, 14};
    int colorIndex = 0;

    for (int i = 0; i < count; ++i) {
        int color = colorCodes[colorIndex % 5];
        H::setcolor(color);
        H::gotoxy(19, row);   cout << setw(10) << left << students[i].id;
        H::gotoxy(34, row);   cout << setw(24) << left << students[i].name;
        H::gotoxy(60, row);   cout << setw(12) << left << students[i].gender;
        H::gotoxy(78, row);   cout << setw(18) << left << students[i].bdate;
        H::gotoxy(101, row);  cout << setw(14) << left << students[i].grade;
        H::gotoxy(116, row);  cout << setw(16) << left << students[i].tel;
        H::gotoxy(138, row);  cout << setw(22) << left << students[i].sYear;
        H::gotoxy(153, row);  cout << setw(30) << left << students[i].email;
        row += 2;
        colorIndex++;
    }
    getch();
}


void Student::Main_StudentManage() {
	int x = 0;
    char option;
    H::cls();
    s.System();
    s.Menu("DEFAULT");
    do {
        H::setcursor(false, 1);
        s.Button();
        H::foreColor(7);
        switch(x) {
            case 0: H::drawBoxSingleLine(15, 10, 8, 1, 78); H::gotoxy(15, 11); cout << "  BACK  "; break;
            case 1: H::drawBoxSingleLine(35, 10, 9, 1, 30); H::gotoxy(35, 11); cout << "   SORT  "; break;
            case 2: H::drawBoxSingleLine(115, 10, 9, 1, 30); H::gotoxy(115, 11); cout << "   ADD   "; break;
            case 3: H::drawBoxSingleLine(135, 10, 10, 1, 30); H::gotoxy(135, 11); cout << "  UPDATE  "; break;
            case 4: H::drawBoxSingleLine(155, 10, 10, 1, 30); H::gotoxy(155, 11); cout << "  DELETE  "; break;
            case 5: H::drawBoxSingleLine(175, 10, 10, 1, 30); H::gotoxy(175, 11); cout << "  SEARCH  "; break;
        }
        option = getch();
        switch(option) {
            case 75: // Left arrow
                x--;
                if (x < 0) x = 5;
                break;
            case 77: // Right arrow
                x++;
                if (x > 5) x = 0;
                break;
            case 27:
            	exit(0);
            case 13:
                H::setcolor(1);
                H::setcursor(true, 1);
                H::cls();
                switch(x) {
                    case 0: // BACK
                        exit(0);
                    case 1:
                    	s.Sort();
                    	break;
                    case 2: // ADD
                        s.Design_Input();
                        s.InputData();
                        s.convertToEmail();
                        s.SaveToFile();
                        break;
                    case 3: // UPDATE
                        s.Update();
                        break;
                    case 4: // DELETE
                        s.Delete();
                        break;
                    case 5: // SEARCH
                        s.Search();
                        break;
                }
				H::setcolor(1);
                H::cls();
                s.Menu("DEFAULT");
                break;
        }
    } while(true);
}


#endif