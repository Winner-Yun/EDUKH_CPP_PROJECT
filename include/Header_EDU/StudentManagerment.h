#ifndef ___EDU_STUDENTMANAGERMENT_H___
#define ___EDU_STUDENTMANAGERMENT_H___

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;
class Student {
	private:
		char id[6], name[19], gender[7], bdate[15], grade[3], tel[10], sYear[5], email[30], pw[19];
		int No;
        static int lastId;
	public:
        // ============ Getter ============
        string getId() const { return id; }
        string getName() const { return name; }
        string getGender() const { return gender; }
        string getBdate() const { return bdate; }
        string getGrade() const { return grade; }
        string getTel() const { return tel; }
        string getYear() const { return sYear; }
        string getEmail() const { return email; }
        string getPw() const { return pw; }
        int getTotalStudents();
        
        void setPassword(const char* newPw) { strcpy(pw, newPw); }
		bool verifyPassword(const char* currentPw) const {
        	return strcmp(pw, currentPw) == 0;
    	}
        // ============ Constructor ============
        Student() {
	        strcpy(id, "");
	        strcpy(name, "");
	        strcpy(grade, "");
	        strcpy(sYear, "");
	        strcpy(gender, "");
	        strcpy(bdate, "");
	        strcpy(tel, "");
	        strcpy(email, "");
    	}
        //
		void Main_StudentManage(); //Main

		//Student Management Design Method
        static void Menu(const string& titleType,int pageIndex);
        static void Button();
        static void System();
        static void Found();
        static void NotFound();
        static void Delete_Loading();
        static void Search_Loading();
        static void Add_Loading();
        static void Sort_Loading();
        static void findStudentById(const string& searchId);
		static void showAllStudents(int pageIndex);
		static void Design_Input();
		static void Design_Update();
		static void Design_search();

        //Student Management Method
		void InputData(int pageIndex);
		void Search(int pageIndex);
		void Update(int pageIndex);
		void Delete(int pageIndex);
		void Sort(int pageIndex);
		void SaveToFile();
		void convertToEmail();
		void updateSharedFileFromStudentData();
};

//Global
Student s;
int Student::lastId = 0;
int sortMode = 0;

int Student::getTotalStudents() {
    ifstream file("../data/Student_Data.bin", ios::binary);
    int count = 0;
    Student temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) count++;
    file.close();
    if(count == 0){
        count = 1;
    }
    return count;
}

void Student::System(){
    H::setcursor(false, 0);
	for (int i = 8; i <= 120; i++) {
		H::foreColor(4);
		H::gotoxy(i - 3, 13);  cout << R"(  _____    _       )";
		H::gotoxy(i - 3, 14);  cout << R"( | ____|__| |_   _ )";
		H::gotoxy(i - 3, 15);  cout << R"( |  _| / _` | | | |)";
		H::gotoxy(i - 3, 16);  cout << R"( | |__| (_| | |_| |)";
		H::gotoxy(i - 3, 17);  cout << R"( |_____\__,_|\__,_|)";
		
		H::foreColor(1);
		H::gotoxy(70, 20);  cout << R"( __  __           _            _  ___   _ )";
		H::gotoxy(70, 21);  cout << R"(|  \/  | __ _ ___| |_ ___ _ __| |/ / | | |)";
		H::gotoxy(70, 22);  cout << R"(| |\/| |/ _` / __| __/ _ \ '__| ' /| |_| |)";
		H::gotoxy(70, 23);  cout << R"(| |  | | (_| \__ \ ||  __/ |  | . \|  _  |)";
		H::gotoxy(70, 24);  cout << R"(|_|  |_|\__,_|___/\__\___|_|  |_|\_\_| |_|)";
		
		H::foreColor(6);
		H::gotoxy(150 - i, 27); cout << R"( ____            _                     )";
		H::gotoxy(150 - i, 28); cout << R"(/ ___| _   _ ___| |_ ___ _ __ ___     )";
		H::gotoxy(150 - i, 29); cout << R"(\___ \| | | / __| __/ _ \ '_ ` _ \    )";
		H::gotoxy(150 - i, 30); cout << R"( ___) | |_| \__ \ ||  __/ | | | | |   )";
		H::gotoxy(150 - i, 31); cout << R"(|____/ \__, |___/\__\___|_| |_| |_|   )";
		H::gotoxy(150 - i, 32); cout << R"(        |___/                         )";
		
		H::delay(5);
	}
	
	H::delay(2);
	for (int i = 5; i <= 180; i++)
	{
	  H::HLine(14, 1, i, 34, ' ');
	  H::HLine(12, 2, i, 31, ' ');
	  H::HLine(10, 3, i, 204, ' ');
	
	  H::HLine(196 - i, 41, 1, 204, ' ');
	  H::HLine(194 - i, 42, 1, 31, ' ');
	  H::HLine(192 - i, 43, 1, 34, ' ');
	}
	
	for (int i = 5; i <= 34; i++) {
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
    H::setcursor(true, 1);
	H::foreColor(0);
}

void Student::Menu(const string& titleType, int pageIndex) {
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
        H::setcolor(2); H::gotoxy(63, 3); cout << R"( ____             _      ____  _             _            _   )";
        H::setcolor(2); H::gotoxy(63, 4); cout << R"(/ ___|  ___  _ __| |_   / ___|| |_ _   _  __| | ___ _ __ | |_ )";
        H::setcolor(3); H::gotoxy(63, 5); cout << R"(\___ \ / _ \| '__| __|  \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
        H::setcolor(4); H::gotoxy(63, 6); cout << R"( ___) | (_) | |  | |_    ___) | |_| |_| | (_| |  __/ | | | |_ )";
        H::setcolor(5); H::gotoxy(63, 7); cout << R"(|____/ \___/|_|   \__|  |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
        H::HLine(61, 9, 65, 5, 223);
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
	
	for (int i = 10; i <= 36; ++i) {
	    H::gotoxy(0, i); cout << R"(   | | | |)";
	    H::gotoxy(x+2, i); cout << R"(   | | | |)";
	}
	
	H::gotoxy(0, 37); cout << R"(  /_______\)";       H::gotoxy(x, 37); cout << R"(    /_______\)";
	H::gotoxy(0, 38); cout << R"(  |       |)";       H::gotoxy(x, 38); cout << R"(    |       |)";
	H::gotoxy(0, 39); cout << R"(  |_______|)";       H::gotoxy(x, 39); cout << R"(    |_______|)";
	H::gotoxy(0, 40); cout << R"(  |_______|)";       H::gotoxy(x, 40); cout << R"(    |_______|)";
	H::gotoxy(0, 41); cout << R"( /-_-_-_-_-\)";      H::gotoxy(x, 41); cout << R"(   /-_-_-_-_-\)";
	H::gotoxy(0, 42); cout << R"(/___________\)";     H::gotoxy(x, 42); cout << R"(  /___________\)";
	
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
	
	// H::setcolor(159); H::gotoxy(14, 44); cout << "<---"; H::setcolor(103); H::gotoxy(20, 44); cout << "[Previous Page]";
	// H::setcolor(159); H::gotoxy(182, 44); cout << "--->";  H::setcolor(103); H::gotoxy(165, 44); cout << "[Previous Page]";
	
	// //Bottom
	H::HLine(0, 42, 200, 6, 223);
	
    H::gotoxy(55, 43);
    system("chcp 65001 > nul");
	H::setcolor(7);  cout << "Use ";
	H::setcolor(7);  cout << "[";
	H::setcolor(10); cout << "▲";
	H::setcolor(7);  cout << "] ";
	H::setcolor(10); cout << "Show Previous Page     "; 

	H::setcolor(7);  cout << "Use ";
	H::setcolor(7);  cout << "[";
	H::setcolor(11); cout << "▼";
	H::setcolor(7);  cout << "] ";
    H::setcolor(11); cout << "Show Next Page         ";
    system("chcp 437 > nul");

    

	H::setcolor(7);  cout << "Use ";
	H::setcolor(7);  cout << "[";
	H::setcolor(14); cout << "Enter";
	H::setcolor(7);  cout << "] ";
	H::setcolor(14); cout << "to Select";

	H::HLine(0, 44, 200, 6, 220);
	showAllStudents(pageIndex);
}

void Student::NotFound() {
    H::setcursor(false, 0);
	H::gotoxy(52, 26); H::setcolor(4); cout << R"( ____  _             _            _      _   _       _      _____                     _   _ _ _ )";
    H::gotoxy(52, 27); H::setcolor(4); cout << R"(/ ___|| |_ _   _  __| | ___ _ __ | |_   | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |)";
    H::gotoxy(52, 28); H::setcolor(4); cout << R"(\___ \| __| | | |/ _` |/ _ \ '_ \| __|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |)";
    H::gotoxy(52, 29); H::setcolor(4); cout << R"( ___) | |_| |_| | (_| |  __/ | | | |_   | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|)";
    H::gotoxy(52, 30); H::setcolor(4); cout << R"(|____/ \__|\__,_|\__,_|\___|_| |_|\__|  |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_))";
}

void Student::Found() {
    H::setcursor(false, 0);
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
    H::cls();
    int w = 200;
    int h = 49;
    int formW = 161;
    int formH = 40;
    int startX = (w - formW) / 2;
    int startY = 2;

    H::drawBoxDoubleLine(startX, startY, formW, formH, 255);
    H::HLine(startX + 1, startY + 3, formW - 2, 255, ' ');
    system("chcp 65001 > nul");
  
    H::foreColor(252); H::gotoxy(startX + 3, startY);
    cout << "◄◆►  POWER BY EDUMASTER-KH  ◄◆►";

    for (int i = 0; i < 10; ++i) {
        H::delay(20); H::foreColor(252);
        H::gotoxy(startX + 21, startY + 1 + i);
        if(i==0) cout << R"(     ███████╗███╗   ██╗████████╗███████╗██████╗     ████████╗██╗  ██╗███████╗    ██████╗  █████╗ ████████╗ █████╗      )";
        if(i==1) cout << R"(     ██╔════╝████╗  ██║╚══██╔══╝██╔════╝██╔══██╗    ╚══██╔══╝██║  ██║██╔════╝    ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗     )";
        if(i==2) cout << R"(     █████╗  ██╔██╗ ██║   ██║   █████╗  ██████╔╝       ██║   ███████║█████╗      ██║  ██║███████║   ██║   ███████║     )";
        if(i==3) cout << R"(     ██╔══╝  ██║╚██╗██║   ██║   ██╔══╝  ██╔══██╗       ██║   ██╔══██║██╔══╝      ██║  ██║██╔══██║   ██║   ██╔══██║     )";
        if(i==4) cout << R"(     ███████╗██║ ╚████║   ██║   ███████╗██║  ██║       ██║   ██║  ██║███████╗    ██████╔╝██║  ██║   ██║   ██║  ██║     )";
        if(i==5) cout << R"(     ╚══════╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝╚═╝  ╚═╝       ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝     )";                                                                                                                        
    }
    system("chcp 437 > nul");
    H::HLine(startX + 1, startY + 6, formW - 2, 255, ' ');
    H::HLine(startX + 1, startY + 7, formW - 2, 255, ' ');
    H::HLine(startX + 1, startY + 8, formW - 2, 255, ' ');
    H::foreColor(6); 
    int boxX = startX + 10, boxY = startY + 12;
    H::drawBoxDoubleLine(boxX, boxY, formW - 20, 22, 255);

    system("chcp 65001 > nul");
    string labels[6] = {
        "STUDENT ID      :",
        "STUDENT NAME    :",
        "GENDER (▲▼)     :",
        "DATE OF BIRTH DD/MM/YY  :",
        "GRADE (▲▼)              :",
        "PHONE NUMBER            :"
    };

    int offsets[6][2] = {
        {5, 2}, {5, 5}, {5, 8}, {90, 2}, {90, 5}, {90, 8}
    };

    for(int i=0;i<6;i++){
        H::foreColor(7);
        H::gotoxy(boxX + offsets[i][0], boxY + offsets[i][1]);
        cout << labels[i];
    }
    system("chcp 437 > nul");
    H::drawBoxDoubleLine(boxX, boxY + 20, formW - 20, 6, 7);
    system("chcp 65001 > nul");
    H::foreColor(3); H::gotoxy(boxX + 2, boxY + 16); cout << "▲▼ Use Arrow Keys to Select Gender and Grade";
    H::foreColor(3); H::gotoxy(boxX + 2, boxY + 18); cout << "-> Press Enter to Confirm";
    H::foreColor(2); H::gotoxy(boxX + 2, boxY + 20); cout << " [ ✨ Enter details in fields above ✨  ] ";
    system("chcp 437 > nul");
}



void Student::Design_Update() {
	H::drawBoxSingleLine(50, 5, 100, 7, 153);
    H::foreColor(154); H::gotoxy(49, 5); cout << "><";
    H::delay(50); H::foreColor(3); H::gotoxy(63, 6);  cout << R"( _   _           _       _          ____  _             _            _   )";
    H::delay(50); H::foreColor(4); H::gotoxy(63, 7);  cout << R"(| | | |_ __   __| | __ _| |_ ___   / ___|| |_ _   _  __| | ___ _ __ | |_ )";
    H::delay(50); H::foreColor(5); H::gotoxy(63, 8);  cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \  \___ \| __| | | |/ _` |/ _ \ '_ \| __|)";
    H::delay(50); H::foreColor(6); H::gotoxy(63, 9);  cout << R"(| |_| | |_) | (_| | (_| | ||  __/   ___) | |_| |_| | (_| |  __/ | | | |_ )";
    H::delay(50); H::foreColor(7); H::gotoxy(63, 10); cout << R"( \___/| .__/ \__,_|\__,_|\__\___|  |____/ \__|\__,_|\__,_|\___|_| |_|\__|)";
    H::delay(50); H::foreColor(7); H::gotoxy(63, 11); cout << R"(      |_|                        )";

	H::delay(10); H::foreColor(3); H::gotoxy(10, 1); cout << R"(   __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(10, 2); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(10, 3); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(10, 4); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(10, 5); cout << R"(  / |  | \)";
    
    H::delay(10); H::foreColor(3); H::gotoxy(33, 7); cout << R"(   __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(33, 8); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(33, 9); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(33, 10); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(33, 11); cout << R"(  / |  | \)";
    
    H::delay(10); H::foreColor(3); H::gotoxy(180, 1); cout << R"(   __   _)";
    H::delay(10); H::foreColor(4); H::gotoxy(180, 2); cout << R"( _(  )_( )_)";
    H::delay(10); H::foreColor(5); H::gotoxy(180, 3); cout << R"((_   _    _))";
    H::delay(10); H::foreColor(6); H::gotoxy(180, 4); cout << R"(  (_) (__))";
    H::delay(10); H::foreColor(7); H::gotoxy(180, 5); cout << R"(  / |  | \)";
    
    H::delay(10); H::foreColor(3); H::gotoxy(155, 7); cout << R"(   __   _)";
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
    
    H::drawBoxSingleLineWithBG(35,22,50,1,0);
    H::drawBoxSingleLineWithBG(35,28,50,1,0);
    H::drawBoxSingleLineWithBG(35,34,50,1,0);
    
    H::drawBoxSingleLineWithBG(115,22,50,1,0);
    H::drawBoxSingleLineWithBG(115,28,50,1,0);
    H::drawBoxSingleLineWithBG(115,34,50,1,0);
    
    H::gotoxy(33, 23);  H::foreColor(6); cout << "Student ID      :";
    H::gotoxy(33, 29);  H::foreColor(6); cout << "Student Name    :";
    H::gotoxy(33, 35);  H::foreColor(6); cout << "Gender          :";
    H::gotoxy(116, 23); H::foreColor(6); cout << "Date of Birth   :";
    H::gotoxy(116, 29); H::foreColor(6); cout << "Grade (10-12)   :";
    H::gotoxy(116, 35); H::foreColor(6); cout << "Phone Number    :";
}

void Student::Delete_Loading() {
    H::setcursor(false, 0);
	H::foreColor(3); H::gotoxy(60, 9); cout << R"( ______   ________  _____     ________  _________   _____  ____  _____    ______  )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"(|_   _ `.|_   __  ||_   _|   |_   __  ||  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(  | | `. \ | |_ \_|  | |       | |_ \_||_/ | | \_|  | |    |   \ | |  / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"(  | |  | | |  _| _   | |   _   |  _| _     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"( _| |_.' /_| |__/ | _| |__/ | _| |__/ |   _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"(|______.'|________||________||________|  |_____|  |_____||_____|\____| `._____.' )";	
	H::setcolor(7); H::gotoxy(47, 23); cout << "Deleting...";
    H::drawBoxSingleLineWithBG(47,24,105,1,15);
    for (int i = 47; i <= 147; i++) {
        H::HLine(i, 25, 1, 15, 177);
        cout << i - 47 << "%";
        H::delay(15);
    }
}

void Student::Search_Loading() {
    H::setcursor(false, 0);
	H::foreColor(3); H::gotoxy(52, 9); cout << R"(  ______   ________       _       _______      ______  ____  ____  _____  ____  _____   ______  )";
	H::foreColor(3); H::gotoxy(52, 10); cout << R"(.' ____ \ |_   __  |     / \     |_   __ \   .' ___  ||_   ||   _||_   _||_   \|_   _|.' ___  | )";
	H::foreColor(3); H::gotoxy(52, 11); cout << R"(| (___ \_|  | |_ \_|    / _ \      | |__) | / .'   \_|  | |__| |    | |    |   \ | | / .'   \_| )";
	H::foreColor(3); H::gotoxy(52, 12); cout << R"( _.____`.   |  _| _    / ___ \     |  __ /  | |         |  __  |    | |    | |\ \| | | |   ____ )";
	H::foreColor(3); H::gotoxy(52, 13); cout << R"(| \____) | _| |__/ | _/ /   \ \_  _| |  \ \_\ `.___.'\ _| |  | |_  _| |_  _| |_\   |_\ `.___]  |)";
	H::foreColor(7); H::gotoxy(52, 14); cout << R"( \______.'|________||____| |____||____| |___|`.____ .'|____||____||_____||_____|\____|`._____.' )";
	H::setcolor(7); H::gotoxy(47, 23); cout << "Searching...";
    H::drawBoxSingleLineWithBG(47,24,105,1,15);
    for (int i = 47; i <= 147; i++) {
        H::HLine(i, 25, 1, 15, 177);
        cout << i - 47 << "%";
        H::delay(15);
    }
}

void Student::Add_Loading() {
    H::setcursor(false, 0);
	H::foreColor(3); H::gotoxy(60, 9);  cout << R"(   ______  _______     ________       _     _________  _____  ____  _____    ______ )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"( .' ___  ||_   __ \   |_   __  |     / \   |  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(/ .'   \_|  | |__) |    | |_ \_|    / _ \  |_/ | | \_|  | |    |   \ | |  / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"(| |         |  __ /     |  _| _    / ___ \     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"(\ `.___.'\ _| |  \ \_  _| |__/ | _/ /   \ \_  _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"( `.____ .'|____| |___||________||____| |____||_____|  |_____||_____|\____| `._____.')";
	H::setcolor(7); H::gotoxy(47, 23); cout << "Loading...";
    H::drawBoxSingleLineWithBG(47, 24, 105, 1, 15);
    for (int i = 47; i <= 147; i++) {
        H::HLine(i, 25, 1, 15, 177);
        cout << i - 47 << "%";
        H::delay(15);
    }
}

void Student::Sort_Loading() {
    H::setcursor(false, 0);
	H::foreColor(3); H::gotoxy(60, 9);  cout << R"(  ______     ___   _______   _________  _____  ____  _____   ______  )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"(.' ____ \  .'   `.|_   __ \ |  _   _  ||_   _||_   \|_   _|.' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(| (___ \_|/  .-.  \ | |__) ||_/ | | \_|  | |    |   \ | | / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"( _.____`. | |   | | |  __ /     | |      | |    | |\ \| | | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"(| \____) |\  `-'  /_| |  \ \_  _| |_    _| |_  _| |_\   |_\ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"( \______.' `.___.'|____| |___||_____|  |_____||_____|\____|`._____.' )";
}
void formatName(char *name) {
    bool newWord = true;

    for (size_t i = 0; i < std::strlen(name); ++i) {
        if (name[i] == ' ') {
            newWord = true;
        } else {
            if (newWord) {
                name[i] = toupper(name[i]);
                newWord = false;
            } else {
                name[i] = tolower(name[i]);
            }
        }
    }
}

void Student::InputData(int pageIndex) {
    int w = 200;
    int h = 49;
    int formW = 161;
    int formH = 40;
    int startXF = (w - formW) / 2;
    int startYF = 2;
    int footerX = startXF + 20;
    int footerY = startYF + formH - 6;
    system("chcp 65001 > nul");
    H::foreColor(6); H::gotoxy(footerX, footerY); cout << R"(╔════════════════════════════════════════════════════════════════╗)";
    H::foreColor(7); H::gotoxy(footerX, footerY + 1); cout << R"(║               ✦ WELCOME TO STUDENT REGISTRATION ✦              ║)";
    H::foreColor(6); H::gotoxy(footerX, footerY + 2); cout << R"(╚════════════════════════════════════════════════════════════════╝)";
    system("chcp 437 > nul");
    if (lastId == 0) {
        ifstream file("../data/Student_Data.bin", ios::binary);
        while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            int num = atoi(s.id + 2);
            if (num > lastId) lastId = num;
        }
        file.close();
    }

    lastId++;
    sprintf(id, "S-%03d", lastId);

    int startX = (200 - 161) / 2 + 30; // boxX from Design_Input
    int startY = 2 + 12;               // boxY from Design_Input

    // ------------------ Student ID ------------------
    H::gotoxy(startX + 5, startY + 2);
    H::setcolor(6);
    cout << this->id;

    // ------------------ Student Name ------------------
    while(true){
        H::gotoxy(startX + 5, startY + 5);
        H::inputLetter(this->name, 18);
        if(strlen(this->name)<5){
            H::gotoxy(startX + 5, startY + 5);cout<<"      ";
        } else {
            formatName(this->name);
            break;
        } 
    }
    // ------------------ Gender Selection ------------------
    H::setcursor(false, 0);
    const char* genders[] = {"Male", "Female"};
    int gIndex = 0;  
    while (true) {
        H::gotoxy(startX + 5, startY + 8);
        cout << "       "; 
        H::gotoxy(startX + 5, startY + 8);
        H::setcolor(6);
        cout << genders[gIndex];

        int key = _getch();
        if (key == 224) { 
            key = _getch();
            if (key == 72 || key == 75) gIndex = (gIndex - 1 + 2) % 2;
            else if (key == 80 || key == 77) gIndex = (gIndex + 1) % 2;
        } else if (key == 13) {
            strcpy(this->gender, genders[gIndex]);
            break;
        }
    }
    H::setcursor(true, 1);

    // ------------------ Date of Birth ------------------
    EdumasterCustom::inputDate(startX + 98, startY + 2,this->bdate, false);

    // ------------------ Grade Selection ------------------
    const char* grades[] = {"10", "11", "12"};
    int gradeIndex = 0;
    H::setcursor(false, 0);
    while (true) {
        H::gotoxy(startX + 98, startY + 5);
        cout << "     "; 
        H::gotoxy(startX + 98, startY + 5);
        H::setcolor(6);
        cout << grades[gradeIndex];

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 || key == 75) gradeIndex = (gradeIndex - 1 + 3) % 3;
            else if (key == 80 || key == 77) gradeIndex = (gradeIndex + 1) % 3;
        } else if (key == 13) {
            strcpy(this->grade, grades[gradeIndex]);
            break;
        }
    }
    H::setcursor(true, 1);

    // ------------------ Phone Number ------------------
    H::gotoxy(startX + 98, startY + 8);
    H::input4Tel(this->tel, 10);

    // ------------------ Default Year and Password ------------------
    strcpy(sYear, "2025");
    H::setcolor(1);
    strcpy(pw, "123");

    H::cls();
    Add_Loading();
}


void Student::convertToEmail() {
    string n;
    // Build lowercase name without spaces
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] != ' ') {
            n += tolower(name[i]);
        }
    }
    string em = "stu." + n + "@gmail.com";
    strncpy(email, em.c_str(), sizeof(email) - 1);
    email[sizeof(email) - 1] = '\0';
}

void Student::SaveToFile() {
    ofstream file1("../data/Student_Data.bin", ios::binary | ios::app);

    if (file1.is_open()) {
        file1.write(reinterpret_cast<char*>(this), sizeof(Student));
        file1.close();
    } else {
        H::setcolor(74); H::gotoxy(92, 48); cout << "Unable to open one or both files";
    }
}


void Student::showAllStudents(int pageIndex) {
    ifstream file("../data/Student_Data.bin", ios::binary);

    const int MAX_STUDENTS = 1000;
    Student students[MAX_STUDENTS];
    int count = 0;

    int row = 18;
    int colorCodes[] = {9, 10, 7, 11, 14};
    int colorIndex = 0;

    if (!file.is_open()) {
        H::gotoxy(90, 25); H::setcolor(4); cout << "Unable to open Student_Data.bin";
        return;
    }
    memset(&s, 0, sizeof(Student));
    while (file.read(reinterpret_cast<char*>(&students[count]), sizeof(Student)) && count < MAX_STUDENTS) {
        count++;
    }
    file.close();

    if (sortMode == 0) {
        H::drawBoxDoubleLineWithBG(15,5,18,1,47);
        H::gotoxy(16, 6); H::setcolor(47); cout << "MOD: SIMPLE LIST";
    }
    else if (sortMode == 1) {
        H::drawBoxDoubleLineWithBG(15,5,23,1,111);
        H::gotoxy(16, 6); H::setcolor(111); cout << "MOD: SORT BY NAME A-Z";
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (strcmp(students[j].name, students[j + 1].name) > 0) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    } else if (sortMode == 2) {
        H::drawBoxDoubleLineWithBG(15,5,26,1,95);
        H::gotoxy(16, 6); H::setcolor(95); cout<< "MOD: SORT BY GRADE 10-12";
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                int grade1 = atoi(students[j].grade);
                int grade2 = atoi(students[j + 1].grade);
                if (grade1 > grade2) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    int startIndex = pageIndex * 11;
    int endIndex = min(startIndex + 11, count);

    for (int i = startIndex; i < endIndex; ++i) {
        int color = colorCodes[colorIndex % 5];
        H::setcolor(color);

        H::gotoxy(19, row + 1);  cout << setw(10) << left << string(students[i].id);
        H::gotoxy(34, row + 1);  cout << setw(24) << left << string(students[i].name);
        H::gotoxy(60, row + 1);  cout << setw(12) << left << string(students[i].gender);
        H::gotoxy(78, row + 1);  cout << setw(18) << left << string(students[i].bdate);
        H::gotoxy(101, row + 1); cout << setw(14) << left << string(students[i].grade);
        H::gotoxy(116, row + 1); cout << setw(16) << left << string(students[i].tel);
        H::gotoxy(138, row + 1); cout << setw(22) << left << string(students[i].sYear);
        H::gotoxy(153, row + 1); cout << setw(30) << left << string(students[i].email);

        row += 2;
        colorIndex++;
    }

    if(count == 0){
        count = 1;
    }
    H::gotoxy(73, 11);
    H::setcolor(7);
    cout << "PAGE " << (pageIndex + 1) << " OF " << ((count + 10) / 11);
}



void Student::Update(int pageIndex) {
    char updateId[10];
    int w = 200;
    int h = 49;
    int formW = 161;
    int formH = 40;
    int startXF = (w - formW) / 2;
    int startYF = 2;
    int footerX = startXF + 20;
    int footerY = startYF + formH - 6;
    H::cls();
    Menu("UPDATE",pageIndex);
    H::gotoxy(73, 11);cout<< "              ";
    H::drawBoxDoubleLine(84, 10, 35, 1, 3);
    H::gotoxy(85, 11); H::setcolor(7); 
    cout << "ENTER STUDENT ID TO UPDATE: S-";
    H::inputUNumber(updateId, 4);

    ifstream file("../data/Student_Data.bin", ios::binary);
    ofstream temp("../data/Temp.bin", ios::binary);
    bool updated = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (strcmp(s.id + 2, updateId) == 0) {
            updated = true;
            H::cls();
            s.Design_Input();
            system("chcp 65001 > nul");
            H::foreColor(6); H::gotoxy(footerX, footerY); cout << R"(╔════════════════════════════════════════════════════════════════╗)";
            H::foreColor(7); H::gotoxy(footerX, footerY + 1); cout << R"(║               ✦ WELCOME TO STUDENT DATA UPDATE ✦               ║)";
            H::foreColor(6); H::gotoxy(footerX, footerY + 2); cout << R"(╚════════════════════════════════════════════════════════════════╝)";
            system("chcp 437 > nul");

            int startX = (200 - 161) / 2 + 30; // boxX from Design_Input
            int startY = 2 + 12;               // boxY from Design_Input

            // ------------------ Student ID ------------------
            H::gotoxy(startX + 5, startY + 2);
            H::setcolor(6);
            cout << this->id;

            // ------------------ Student Name ------------------
            while(true){
                H::gotoxy(startX + 5, startY + 5);
                H::inputLetter(this->name, 18);
                if(strlen(this->name)<5){
                    H::gotoxy(startX + 5, startY + 5);cout<<"      ";
                } else {
                    formatName(this->name);
                    break;
                } 
            }

            // ------------------ Gender Selection ------------------
            H::setcursor(false, 0);
            const char* genders[] = {"Male", "Female"};
            int gIndex = (strcmp(this->gender, "Female") == 0) ? 1 : 0;
            while (true) {
                H::gotoxy(startX + 5, startY + 8);
                cout << "       ";
                H::gotoxy(startX + 5, startY + 8);
                H::setcolor(6);
                cout << genders[gIndex];

                int key = _getch();
                if (key == 224) {
                    key = _getch();
                    if (key == 72 || key == 75) gIndex = (gIndex - 1 + 2) % 2;
                    else if (key == 80 || key == 77) gIndex = (gIndex + 1) % 2;
                } else if (key == 13) {
                    strcpy(this->gender, genders[gIndex]);
                    break;
                }
            }
            H::setcursor(true, 1);

            // ------------------ Date of Birth ------------------
        
            EdumasterCustom::inputDate(startX + 98, startY + 2,this->bdate, false);

            // ------------------ Grade Selection ------------------
            const char* grades[] = {"10", "11", "12"};
            int gradeIndex = 0;
            if (strcmp(this->grade, "11") == 0) gradeIndex = 1;
            else if (strcmp(this->grade, "12") == 0) gradeIndex = 2;

            H::setcursor(false, 0);
            while (true) {
                H::gotoxy(startX + 98, startY + 5);
                cout << "     ";
                H::gotoxy(startX + 98, startY + 5);
                H::setcolor(6);
                cout << grades[gradeIndex];

                int key = _getch();
                if (key == 224) {
                    key = _getch();
                    if (key == 72 || key == 75) gradeIndex = (gradeIndex - 1 + 3) % 3;
                    else if (key == 80 || key == 77) gradeIndex = (gradeIndex + 1) % 3;
                } else if (key == 13) {
                    strcpy(this->grade, grades[gradeIndex]);
                    break;
                }
            }
            H::setcursor(true, 1);

            // ------------------ Phone Number ------------------
            H::gotoxy(startX + 98, startY + 8);
            H::input4Tel(this->tel, 10);

            s.convertToEmail();
        }
        temp.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    file.close();
    temp.close();
    remove("../data/Student_Data.bin");
    rename("../data/Temp.bin", "../data/Student_Data.bin");

    if (updated) {
        H::cls();
        Add_Loading();
    } else {
        H::clearBox(16, 19, 168, 22, 3);
        s.NotFound();
        getch();
    }
}


void Student::Delete(int pageIndex) {
    char deleteId[10];
    H::cls();
    Menu("DELETE",pageIndex);
    H::gotoxy(73, 11);cout<< "              ";
    H::drawBoxDoubleLine(84, 10, 36, 1, 3);
    H::gotoxy(85, 11); H::setcolor(7); cout << "ENTER TEACHER ID TO DELETE: S-";
    H::inputUNumber(deleteId, 4);

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
    } else {
    	H::clearBox(16, 19, 168, 22, 3);
        s.NotFound();
        getch();
    }

}
string toUpperr(const char* str) {
    std::string result;
    for (int i = 0; str[i] != '\0'; ++i)
        result += toupper(str[i]);
    return result;
}

void Student::Search(int pageIndex) {
    char key;
    do {
        char searchName[30];
        H::cls();
        Menu("SEARCH",pageIndex);
        H::gotoxy(73, 11);cout<< "              ";
        H::setcursor(true, 1);
        H::drawBoxDoubleLine(73, 10, 53, 1, 3);
        H::gotoxy(75, 11); H::setcolor(7);
        cout << "ENTER STUDENT NAME FOR SEARCH: ";
        H::inputLetter(searchName, 20);

        H::cls();
        H::cls();
        Menu("SEARCH",pageIndex);
        H::gotoxy(73, 11);cout<< "              ";

        ifstream file("../data/Student_Data.bin", ios::binary);
        vector<Student> results;
        string searchNameUpper = toUpperr(searchName);
        while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            string studentNameUpper = toUpperr(s.name);
			if (studentNameUpper.find(searchNameUpper) != string::npos) {
				results.push_back(s);
			}
        }
        file.close();

        int total = results.size();
        if (total == 0) {
            H::gotoxy(85, 20);
            H::setcolor(4);
            cout << "NO STUDENT FOUND.";
        } else {
            int page = 0;
                H::clearBox(16, 19, 168, 22, 3);
                int start = page * 10;
                int end = min(start + 10, total);
                int row = 18;

                for (int i = start; i < end; i++) {
                    H::drawBoxDoubleLine(17, row + 1, 166, 1, 9);
                    H::setcolor(7);
                    H::gotoxy(19, row + 2);  cout << setw(10) << left << string(results[i].id);
                    H::gotoxy(34, row + 2);  cout << setw(24) << left << string(results[i].name);
                    H::gotoxy(60, row + 2);  cout << setw(12) << left << string(results[i].gender);
                    H::gotoxy(78, row + 2);  cout << setw(18) << left << string(results[i].bdate);
                    H::gotoxy(101, row + 2); cout << setw(14) << left << string(results[i].grade);
                    H::gotoxy(116, row + 2); cout << setw(16) << left << string(results[i].tel);
                    H::gotoxy(138, row + 2); cout << setw(22) << left << string(results[i].sYear);
                    H::gotoxy(153, row + 2); cout << setw(30) << left << string(results[i].email);
                    row += 2;
                }

                H::foreColor(4);
                H::drawBoxDoubleLine(17, 19, 166, 1, 9);
                H::clearBox(0, 44, 200, -1, 7);
                H::foreColor(1); H::gotoxy(65, 43);
                cout << "PAGE " << (page + 1) << " OF " << ((total + 9) / 10);
                H::gotoxy(72, 45);
                cout << "PRESS ";
                H::foreColor(4); cout << "[ENTER]";
                H::foreColor(1); cout << " FOR NEXT PAGE, ";
                H::foreColor(4); cout << "[ESC]";
                H::foreColor(1); cout << " TO GO BACK.";
        }

        H::foreColor(4);
        H::drawBoxDoubleLine(17, 19, 166, 1, 9);
        H::clearBox(0, 44, 200, -1, 7);
        H::foreColor(1); H::gotoxy(72, 43);
        cout << "PRESS ";
        H::foreColor(4); cout << "[ENTER]";
        H::foreColor(1); cout << " TO SEARCH AGAIN OR ";
        H::foreColor(4); cout << "[ESC]";
        H::foreColor(1); cout << " TO GO BACK TO MENU.";

        while (true) {
            key = getch();
            if (key == 13) {
                break;
            } else if (key == 27) {
                return;
            }
        }
    } while (true);
}


void Student::Sort(int pageIndex) {
	H::setcursor(false, 1);
    H::clearBox(16, 19, 168, 22, 3);
    sortMode = (sortMode + 1) % 3;
    showAllStudents(pageIndex);
}

void Student::Main_StudentManage() {
	int x = 0;
    bool loop = true;
    int pageIndex = 0;
    int totalStudents = s.getTotalStudents();
    int maxPage = (totalStudents + 10) / 11 - 1;
    char option;
    // Student::System();
    H::cls();
    s.Menu("DEFAULT",pageIndex);
    while(loop) {
        H::setcursor(false, 1);
        s.Button();
        H::foreColor(7);
        s.showAllStudents(pageIndex);
        switch(x) {
            case 0: H::drawBoxSingleLine(15, 10, 8, 1, 4); H::gotoxy(15, 11); cout << "  BACK  "; break;
            case 1: H::drawBoxSingleLine(35, 10, 9, 1, 1); H::gotoxy(35, 11); cout << "   SORT  "; break;
            case 2: H::drawBoxSingleLine(115, 10, 9, 1, 1); H::gotoxy(115, 11); cout << "   ADD   "; break;
            case 3: H::drawBoxSingleLine(135, 10, 10, 1, 1); H::gotoxy(135, 11); cout << "  UPDATE  "; break;
            case 4: H::drawBoxSingleLine(155, 10, 10, 1, 1); H::gotoxy(155, 11); cout << "  DELETE  "; break;
            case 5: H::drawBoxSingleLine(175, 10, 10, 1, 1); H::gotoxy(175, 11); cout << "  SEARCH  "; break;
        }
        option = getch();
        switch(option) {
            case 72: 
                H::clearBox(20,20,160,20,7);
                if (pageIndex > 0) pageIndex--;
                break;
            case 80:
                H::clearBox(20,20,160,20,7);
                if (pageIndex < maxPage) pageIndex++;
                break;
            case 75: // Left arrow
                x--;
                if (x < 0) x = 5;
                break;
            case 77: // Right arrow
                x++;
                if (x > 5) x = 0;
                break;
            case 27:
            	loop = false;
            case 13:
                H::setcolor(1);
                H::setcursor(true, 1);
                switch(x) {
                    case 0: // BACK
                        loop = false;
                        break;
                    case 1: // SORT
                        s.Sort(pageIndex);
                        break;

                    case 2: // ADD
                            H::cls();
                            s.Design_Input();
                            s.InputData(pageIndex);
                            s.convertToEmail();
                            s.SaveToFile();
                        break;

                    case 3: // UPDATE
                        H::cls();
                        s.Update(pageIndex);
                        break;

                    case 4: // DELETE
                        if(MessageBoxA(GetConsoleWindow(), "Do you really want to delete?", "Confirm", MB_ICONQUESTION | MB_YESNO) == IDYES) {
                            s.Delete(pageIndex);
                        }
                        break;

                    case 5: // SEARCH
                        s.Search(pageIndex);
                        break;

                }
				H::setcolor(1);
                H::cls();
                s.Menu("DEFAULT",pageIndex);
                break;
        }
    }
    H::cls();
}

#endif