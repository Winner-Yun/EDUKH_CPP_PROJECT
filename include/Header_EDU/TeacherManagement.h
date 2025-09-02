#ifndef __TEACHERMANAGEMENT_H__
#define __TEACHERMANAGEMENT_H__

#include "../Header_School/ANTHinsyOOP"
#include "CustomHeader.h"

using namespace ANTHinsyOOP;

class Teacher{
	private: 
		static int lastId;    
		char teacherId[20], teacherName[20],gender[20],subject[20],phoneNumber[15],dateOfBirth[20],email[40],pw[20],academyYear[10];
	public:
		void generateTeacherID(); 
		const char* getTeacherId() const;
		const char* getTeacherName() const;
		const char* getSubject() const;
		const char* getYear() const;
		const char* getDateOfBirth() const;
		const char* getEmail() const;
		const char* getPhone() const;
		const char* getGender() const;
		const char* getPassword() const { return pw; }
		void setPassword(const char* newPw) { strcpy(pw, newPw); }
		bool verifyPassword(const char* currentPw) const {
        	return strcmp(pw, currentPw) == 0;
    	}

		void convertEmail();
		void input();
		void output(int y);
		void newInput();
};

class TeacherDesign{
	public:
		static bool isSorted;
		static void loading();
		static void allformForWrongInput(); // show when search or update but wrong input
		static void allformForInput();     // show when sort and update for input to update data or sort data
		static void increaseId();         //auto increase ID
		static void showTeacher(int pageindex);         // show teacher or read teacher From file 
		static void showdesign(int pageindex);			// show Teacher With Design 
		static void designTable();			// table storeData
		static void insertTeacher();		// write dataa to file
		static void System();				
		static void searchTeacher(int pageIndex);		// search by using arrow key
		static void updateTeacher(int pageIndex);		// update by using arrow key
		static void deletedTeacher(int pageIndex);		// delete by using arrow key
		static void sortTeacherByName(int pageIndex);	// sorting by name
		static void teacherManagement();		// menu arrow key and all method work here 
		static void asciiDelete();				// delete by using ascii code
		static void asciiTeacherNotFound();
		static void asciiSearchTeacher();
		static void sorting();					// sorting by using ascii code

		int getTotalTeachers();
		
};

bool TeacherDesign::isSorted = false;
Teacher t;
TeacherDesign td;
int Teacher::lastId = 0;

const char* Teacher::getTeacherId() const {
	return teacherId;
}

const char* Teacher::getTeacherName() const {
	return teacherName;
}

const char* Teacher::getGender() const {
	return gender;
}

const char* Teacher::getSubject() const {
	return subject;
}

const char* Teacher::getYear() const {
	return academyYear;
}

const char* Teacher::getDateOfBirth() const {
	return dateOfBirth;
}
const char* Teacher::getEmail() const {
	return email;
}
const char* Teacher::getPhone() const {
	return phoneNumber;
}

void Teacher::convertEmail(){
	char cleanedName[30];
    int j = 0;
    for (int i = 0; teacherName[i] != '\0'; i++) {
        if (teacherName[i] != ' ') {
            cleanedName[j++] = tolower(teacherName[i]);
        }
    }
    cleanedName[j] = '\0';
    strcpy(email, "te.");
    strcat(email, cleanedName);
    strcat(email, "@gmail.com");
}
void formattName(char *name) {
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
void  Teacher::input(){
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
        "TEACHER ID      :",
        "TEACHER NAME    :",
        "GENDER (▲▼)     :",
        "DATE OF BIRTH DD/MM/YY  :",
        "SUBJECT                 :",
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
    H::foreColor(3); H::gotoxy(boxX + 2, boxY + 16); cout << "▲▼ Use Arrow Keys to Select Gender and Subject";
    H::foreColor(3); H::gotoxy(boxX + 2, boxY + 18); cout << "-> Press Enter to Confirm";
    H::foreColor(2); H::gotoxy(boxX + 2, boxY + 20); cout << " [ ✨ Enter details in fields above ✨  ] ";
    system("chcp 437 > nul");
	
	if (lastId == 0) {
        ifstream file("../data/Teacher_Data.bin", ios::binary); //open file
        Teacher temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
            int num = atoi(temp.getTeacherId() + 2);
            if (num > lastId) lastId = num;
        }
        file.close();
    }

    int startXF = (w - formW) / 2;
    int startYF = 2;
    int footerX = startXF + 20;
    int footerY = startYF + formH - 6;
    system("chcp 65001 > nul");
    H::foreColor(6); H::gotoxy(footerX, footerY); cout << R"(╔════════════════════════════════════════════════════════════════╗)";
    H::foreColor(7); H::gotoxy(footerX, footerY + 1); cout << R"(║               ✦ WELCOME TO TEACHER REGISTRATION ✦              ║)";
    H::foreColor(6); H::gotoxy(footerX, footerY + 2); cout << R"(╚════════════════════════════════════════════════════════════════╝)";
    system("chcp 437 > nul");
    if (lastId == 0) {
        ifstream file("../data/Teacher_Data.bin", ios::binary);
        while (file.read(reinterpret_cast<char*>(&t), sizeof(Teacher))) {
            int num = atoi(t.teacherId + 2);
            if (num > lastId) lastId = num;
        }
        file.close();
    }

    lastId++;
    sprintf(teacherId, "T-%03d", lastId);

    startX = (200 - 161) / 2 + 30; // boxX from Design_Input
    startY = 2 + 12;               // boxY from Design_Input

    // ------------------ Student ID ------------------
    H::gotoxy(startX + 5, startY + 2);
    H::setcolor(6);
    cout << this->teacherId;

    // ------------------ Student Name ------------------
    while(true){
        H::gotoxy(startX + 5, startY + 5);
        H::inputLetter(this->teacherName, 18);
        if(strlen(this->teacherName)<5){
            H::gotoxy(startX + 5, startY + 5);cout<<"      ";
        } else {
            formattName(this->teacherName);
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
    EdumasterCustom::inputDate(startX + 98, startY + 2,this->dateOfBirth, false);

    // ------------------ Subject ------------------
	H::setcursor(false, 0);
    const char* subjects[] = {
        "KHMER",
        "MATHEMATICS",
        "PHYSICS",
        "CHEMISTRY",
        "BIOLOGY",
        "COMPUTER",
        "HISTORY",
        "GEOGRAPHY",
        "ENGLISH"
    };
    int sIndex = 0;  
    int totalSubjects = sizeof(subjects) / sizeof(subjects[0]);
    while (true) {
        H::gotoxy(startX + 98, startY + 5);
        cout << "                  ";
        H::gotoxy(startX + 98, startY + 5);
        H::setcolor(6);
        cout << subjects[sIndex];
        int key = _getch();
        if (key == 224) { 
            key = _getch();
            if (key == 72 || key == 75)
                sIndex = (sIndex - 1 + totalSubjects) % totalSubjects;
            else if (key == 80 || key == 77)
                sIndex = (sIndex + 1) % totalSubjects;
        } else if (key == 13) {
            strcpy(this->subject, subjects[sIndex]);
            break;
        }
    }
     H::setcursor(true, 1);
    // ------------------ Phone Number ------------------
    H::gotoxy(startX + 98, startY + 8);
    H::input4Tel(this->phoneNumber, 10);

    // ------------------ Default Year and Password ------------------
    strcpy(academyYear, "2025");
    H::setcolor(1);
    strcpy(pw, "123");

    H::cls();

    
    Teacher::convertEmail();
}

void Teacher::output(int y) {
    H::gotoxy(25, y+1);  cout << teacherId;
    H::gotoxy(41, y+1);  cout << teacherName;
    H::gotoxy(65, y+1);  cout << gender;
    H::gotoxy(82, y+1);  cout << subject;
    H::gotoxy(105, y+1); cout << dateOfBirth;
    H::gotoxy(124, y+1); cout << phoneNumber;
    H::gotoxy(141, y+1); cout << email;         
    H::gotoxy(169, y+1); cout << academyYear;
}

void Teacher::newInput(){
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
        "TEACHER ID      :",
        "TEACHER NAME    :",
        "GENDER (▲▼)     :",
        "DATE OF BIRTH DD/MM/YY  :",
        "SUBJECT (▲▼)            :",
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
    H::foreColor(3); H::gotoxy(boxX + 2, boxY + 16); cout << "▲▼ Use Arrow Keys to Select Gender and Subject";
    H::foreColor(3); H::gotoxy(boxX + 2, boxY + 18); cout << "-> Press Enter to Confirm";
    H::foreColor(2); H::gotoxy(boxX + 2, boxY + 20); cout << " [ ✨ Enter details in fields above ✨  ] ";
    system("chcp 437 > nul");
	
	if (lastId == 0) {
        ifstream file("../data/Teacher_Data.bin", ios::binary); //open file
        Teacher temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
            int num = atoi(temp.getTeacherId() + 2);
            if (num > lastId) lastId = num;
        }
        file.close();
    }

    int startXF = (w - formW) / 2;
    int startYF = 2;
    int footerX = startXF + 20;
    int footerY = startYF + formH - 6;
    system("chcp 65001 > nul");
    H::foreColor(6); H::gotoxy(footerX, footerY); cout << R"(╔════════════════════════════════════════════════════════════════╗)";
    H::foreColor(7); H::gotoxy(footerX, footerY + 1); cout << R"(║               ✦ WELCOME TO TEACHER REGISTRATION ✦              ║)";
    H::foreColor(6); H::gotoxy(footerX, footerY + 2); cout << R"(╚════════════════════════════════════════════════════════════════╝)";
    system("chcp 437 > nul");

    startX = (200 - 161) / 2 + 30; // boxX from Design_Input
    startY = 2 + 12;               // boxY from Design_Input

    // ------------------ Student ID ------------------
    H::gotoxy(startX + 5, startY + 2);
    H::setcolor(6);
    cout << this->teacherId;

    // ------------------ Student Name ------------------
    while(true){
        H::gotoxy(startX + 5, startY + 5);
        H::inputLetter(this->teacherName, 18);
        if(strlen(this->teacherName)<5){
            H::gotoxy(startX + 5, startY + 5);cout<<"      ";
        } else {
            formattName(this->teacherName);
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
    EdumasterCustom::inputDate(startX + 98, startY + 2,this->dateOfBirth, false);

    // ------------------ Subject Selection ------------------
	H::setcursor(false, 0);
    const char* subjects[] = {
        "KHMER",
        "MATHEMATICS",
        "PHYSICS",
        "CHEMISTRY",
        "BIOLOGY",
        "COMPUTER",
        "HISTORY",
        "GEOGRAPHY",
        "ENGLISH"
    };
    int sIndex = 0;  
    int totalSubjects = sizeof(subjects) / sizeof(subjects[0]);
    while (true) {
        H::gotoxy(startX + 98, startY + 5);
        cout << "                  ";
        H::gotoxy(startX + 98, startY + 5);
        H::setcolor(6);
        cout << subjects[sIndex];
        int key = _getch();
        if (key == 224) { 
            key = _getch();
            if (key == 72 || key == 75)
                sIndex = (sIndex - 1 + totalSubjects) % totalSubjects;
            else if (key == 80 || key == 77)
                sIndex = (sIndex + 1) % totalSubjects;
        } else if (key == 13) {
            strcpy(this->subject, subjects[sIndex]);
            break;
        }
    }
     H::setcursor(true, 1);

    // ------------------ Phone Number ------------------
    H::gotoxy(startX + 98, startY + 8);
    H::input4Tel(this->phoneNumber, 10);

    // ------------------ Default Year and Password ------------------
    strcpy(academyYear, "2025");
    H::setcolor(1);
    strcpy(pw, "123");

    H::cls();

    
    Teacher::convertEmail();
}

void TeacherDesign::loading(){
	H::drawBoxSingleLineWithBG(47,24,105,1,15);
		
    for (int i = 47; i <= 147; i++) {
        H::HLine(i, 25, 1, 15, 177);
        cout<<i-47<<"%";
        H::delay(10);
    }
}

void TeacherDesign::allformForWrongInput(){
	H::setFixedScreenConsole(200,45);
	int i = 90;
    H::foreColor(1); H::delay(50); H::gotoxy(i - 63, 2); std::cout << R"(    _______   )";
    H::foreColor(2); H::delay(50); H::gotoxy(i - 63, 3); std::cout << R"(   /      /,  )";
    H::foreColor(3); H::delay(50); H::gotoxy(i - 63, 4); std::cout << R"(  /      //   )";
    H::foreColor(4); H::delay(50); H::gotoxy(i - 63, 5); std::cout << R"( /______//    )";
    H::foreColor(5); H::delay(200); H::gotoxy(i - 63, 6); std::cout << R"((______(/     )";

    H::delay(50); H::foreColor(1); H::gotoxy(i - 0, 1);  std::cout << R"(      _ _                  )";
    H::delay(50); H::foreColor(2); H::gotoxy(i - 10, 2); std::cout << R"( .-. | | |                 )";
    H::delay(50); H::foreColor(3); H::gotoxy(i - 10, 3); std::cout << R"( |M|_|A|N|                  )";
    H::delay(50); H::foreColor(4); H::gotoxy(i - 10, 4); std::cout << R"( |A|a|.|.|<\                )";
    H::delay(50); H::foreColor(5); H::gotoxy(i - 10, 5); std::cout << R"( |T|r| | | \\               )";
    H::delay(50); H::foreColor(1); H::gotoxy(i - 10, 6); std::cout << R"( |H|t|M|Z|  \\             )";
    H::delay(50); H::foreColor(7); H::gotoxy(i - 10, 7); std::cout << R"( | |!| | |   \>            )";
    H::delay(50); H::foreColor(8); H::gotoxy(i - 10, 8); std::cout << R"( """""""""""""""""""       )";

    H::delay(10); H::foreColor(3); H::gotoxy(155, 1);  cout << R"((\         )";
	H::delay(10); H::foreColor(4); H::gotoxy(155, 2);  cout << R"('\'\       )";
	H::delay(10); H::foreColor(5); H::gotoxy(155, 3);  cout << R"( \'\     __________  )";
	H::delay(10); H::foreColor(6); H::gotoxy(155, 4); cout << R"( / '|   ()_________))";
	H::delay(10); H::foreColor(7); H::gotoxy(155, 5); cout << R"( \ '/    \ ~~~~~~~~ \)";
	H::delay(10); H::foreColor(8); H::gotoxy(155, 6); cout << R"(   \       \ ~~~~~~   \)";
	H::delay(10); H::foreColor(9); H::gotoxy(155, 7); cout << R"(   ==).      \__________\)";
	H::delay(10); H::foreColor(10);H::gotoxy(155, 8); cout << R"(  (__)       ()__________))";
	
	
	H::delay(10); H::foreColor(1); H::gotoxy(5, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2); H::gotoxy(5, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3); H::gotoxy(5, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4); H::gotoxy(5, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5); H::gotoxy(5, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6); H::gotoxy(5, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7); H::gotoxy(5, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8); H::gotoxy(5, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9); H::gotoxy(5, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(5, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";

	H::delay(10); H::foreColor(1);  H::gotoxy(155, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2);  H::gotoxy(155, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3);  H::gotoxy(155, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4);  H::gotoxy(155, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5);  H::gotoxy(155, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6);  H::gotoxy(155, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7);  H::gotoxy(155, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8);  H::gotoxy(155, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9);  H::gotoxy(155, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(155, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";

    H::drawBoxDoubleLineWithBG(50, 15, 90, 20, 153);
    H::drawBoxDoubleLineWithBG(55, 17, 80, 16, 170);
    H::drawBoxSingleLineWithBG(60, 19, 70, 12, 213);
    H::drawBoxSingleLineWithBG(65, 21, 60, 8, 0);
}

void TeacherDesign::allformForInput(){
	H::setFixedScreenConsole(200,45);
	H::drawBoxDoubleLineWithBG(50, 16, 100, 20, 153);  // Outer box
	H::drawBoxDoubleLineWithBG(55, 18, 90, 16, 2);   // Inner background
	H::drawBoxSingleLineWithBG(60, 20, 80, 12, 170);   // Input container
	H::drawBoxSingleLineWithBG(65, 22, 70, 8,2);

	
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


	H::delay(10); H::foreColor(1); H::gotoxy(5, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2); H::gotoxy(5, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3); H::gotoxy(5, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4); H::gotoxy(5, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5); H::gotoxy(5, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6); H::gotoxy(5, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7); H::gotoxy(5, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8); H::gotoxy(5, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9); H::gotoxy(5, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(5, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";

	H::delay(10); H::foreColor(1);  H::gotoxy(155, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2);  H::gotoxy(155, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3);  H::gotoxy(155, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4);  H::gotoxy(155, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5);  H::gotoxy(155, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6);  H::gotoxy(155, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7);  H::gotoxy(155, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8);  H::gotoxy(155, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9);  H::gotoxy(155, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(155, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";
	
	H::foreColor(0);
	H::gotoxy(62, 19);
}

fstream teachF; 

void TeacherDesign::insertTeacher(){
	H::cls();
	Teacher t;
	
		fstream file("../data/Teacher_Data.bin", ios::binary | ios::app); // create file
	if (!file) {
	    H::gotoxy(70, 25); H::setcolor(4);
	    cout << "Error can not open file !";
	    getch();
	    return;
	}
	t.input();
	file.write((char*)&t, sizeof(t)); //write data to file
	file.close();
	H::setFixedScreenConsole(200,45);
	H::cls();
	H::foreColor(3); H::gotoxy(60, 9);  cout << R"(   ______  _______     ________       _     _________  _____  ____  _____    ______ )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"( .' ___  ||_   __ \   |_   __  |     / \   |  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(/ .'   \_|  | |__) |    | |_ \_|    / _ \  |_/ | | \_|  | |    |   \ | |  / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"(| |         |  __ /     |  _| _    / ___ \     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"(\ `.___.'\ _| |  \ \_  _| |__/ | _/ /   \ \_  _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"( `.____ .'|____| |___||________||____| |____||_____|  |_____||_____|\____| `._____.')";

	TeacherDesign::loading();

} 

void TeacherDesign::showTeacher(int pageIndex) {
    ifstream file("../data/Teacher_Data.bin", ios::binary);
    if (!file) {
        H::gotoxy(90, 25); 
        H::setcolor(4); 
        cout << "Unable to open Teacher_Data.bin";
        return;
    }

    const int MAX_TEACHERS = 1000;
    Teacher teachers[MAX_TEACHERS];
    int count = 0;

    while (file.read((char*)&teachers[count], sizeof(Teacher)) && count < MAX_TEACHERS) {
        count++;
    }
    file.close();

    if (isSorted) {
        H::drawBoxDoubleLineWithBG(15, 5, 23, 1, 111);
        H::gotoxy(16, 6); 
        H::setcolor(111); 
        cout << "MOD: SORT BY NAME A-Z";

        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (strcmp(teachers[j].getTeacherName(), teachers[j + 1].getTeacherName()) > 0) {
                    Teacher temp = teachers[j];
                    teachers[j] = teachers[j + 1];
                    teachers[j + 1] = temp;
                }
            }
        }
    } else {
        H::drawBoxDoubleLineWithBG(15, 5, 18, 1, 47);
        H::gotoxy(16, 6); 
        H::setcolor(47); 
        cout << "MOD: SIMPLE LIST";
    }

    int startIndex = pageIndex * 11;
    int endIndex   = min(startIndex + 11, count);

    int colors[] = {9, 10, 7, 11, 14};
    int colorCount = sizeof(colors) / sizeof(colors[0]);

    H::clearBox(16, 19, 168, 22, 3);  // clear data area

    int y = 18;
    int row = 0;

    for (int i = startIndex; i < endIndex; i++) {
        H::setcolor(colors[row % colorCount]);
        teachers[i].output(y);
        y += 2;
        row++;
    }
	if(count ==0){
		count = 1;
	}
    H::gotoxy(73, 11);
    H::setcolor(7);
    cout << "PAGE " << (pageIndex + 1) << " OF " << ((count + 10) / 11);
}


void TeacherDesign::designTable(){
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
	
	H::drawBoxDoubleLine(15, 14, 170, 1, 2);
	H::drawBoxDoubleLine(15, 17, 170, 24, 3);
	H::setcolor(6);
	H::gotoxy(26, 15); cout << "ID";
	H::gotoxy(42, 15); cout << "NAME";
	H::gotoxy(65, 15); cout << "GENDER";
	H::gotoxy(82, 15); cout << "SUBJECT";
	H::gotoxy(105, 15); cout << "BIRTHOFDATE";
	H::gotoxy(127, 15); cout << "TEL";
	H::gotoxy(144, 15); cout << "EMAIL";
	H::gotoxy(167, 15); cout << "STUDY YEAR";
	
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
}

void TeacherDesign::showdesign(int pageindex){
	H::setFixedScreenConsole(200, 45);
	H::setcolor(2); H::gotoxy(50, 3);  cout << R"(  _____               _                  )";
	H::setcolor(2); H::gotoxy(50, 4);  cout << R"( |_   _|__  __ _  ___| |__   ___ _ __    )";
	H::setcolor(2); H::gotoxy(50, 5);  cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|   )";
	H::setcolor(3); H::gotoxy(50, 6);  cout << R"(   | |  __/ (_| | (__| | | |  __/ |      )";
	H::setcolor(5); H::gotoxy(50, 7);  cout << R"(   |_|\___|\__,_|\___|_| |_|\___|_|      )";
	
	H::setcolor(2); H::gotoxy(90, 3);  cout << R"(   ___       __                             _   _             )";
	H::setcolor(2); H::gotoxy(90, 4);  cout << R"(  |_ _|_ __ / _| ___  _ __ _ __ ___    __ _| |_(_) ___  _ __  )";
	H::setcolor(3); H::gotoxy(90, 5);  cout << R"(   | || '_ \| |_ / _ \| '__| '_ ` _ \ / _` | __| |/ _ \| '_ \ )";
	H::setcolor(4); H::gotoxy(90, 6);  cout << R"(   | || | | |  _| (_) | |  | | | | | | (_| | |_| | (_) | | | |)";
	H::setcolor(5); H::gotoxy(90, 7);  cout << R"(  |___|_| |_|_|  \___/|_|  |_| |_| |_|\__,_|\__|_|\___/|_| |_|)";
	
	H::HLine(50, 9, 105, 5, 223);
	
	TeacherDesign::designTable();
	TeacherDesign::showTeacher(pageindex);
}

void TeacherDesign::asciiDelete(){
		H::delay(10); H::foreColor(3); H::gotoxy(69, 3);  cout << R"( ____       _      _         _____               _                )";
		H::delay(10); H::foreColor(4); H::gotoxy(69, 4);  cout << R"(|  _ \  ___| | ___| |_ ___  |_   _|__  __ _  ___| |__   ___ _ __ )";
		H::delay(10); H::foreColor(5); H::gotoxy(69, 5);  cout << R"(| | | |/ _ \ |/ _ \ __/ _ \   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
		H::delay(10); H::foreColor(6); H::gotoxy(69, 6);  cout << R"(| |_| |  __/ |  __/ ||  __/   | |  __/ (_| | (__| | | |  __/ |   )";
		H::delay(10); H::foreColor(7); H::gotoxy(69, 7);  cout << R"(|____/ \___|_|\___|\__\___|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
		H::HLine(69, 9, 65, 5, 223);
}

void TeacherDesign::asciiTeacherNotFound(){
	 	H::gotoxy(52, 26); H::setcolor(4); cout << R"(  _____               _                  _   _       _      _____                     _   _ _ _   )";
		H::gotoxy(52, 27); H::setcolor(4); cout << R"( |_   _|__  __ _  ___| |__   ____ __    | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |  )";
		H::gotoxy(52, 28); H::setcolor(4); cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |  )";
		H::gotoxy(52, 29); H::setcolor(4); cout << R"(   | |  __/ (_| | (__| | | |  __/ |     | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|  )";
		H::gotoxy(52, 30); H::setcolor(4); cout << R"(   |_|\___|\__,_|\___|_| |_|\___| |_|   |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_)  )";
}

void TeacherDesign::asciiSearchTeacher(){
		H::delay(50); H::foreColor(3); H::gotoxy(68, 3); cout << R"( ____                      _       _____               _               )";
		H::delay(50); H::foreColor(4); H::gotoxy(68, 4); cout << R"(/ ___|  ___  __ _ _ __ ___| |__   |_   _|__  __ _  ___| |__   ___ _ __ )";
		H::delay(50); H::foreColor(5); H::gotoxy(68, 5); cout << R"(\___ \ / _ \/ _` | '__/ __| '_ \    | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
		H::delay(50); H::foreColor(6); H::gotoxy(68, 6); cout << R"( ___) |  __/ (_| | | | (__| | | |   | |  __/ (_| | (__| | | |  __/ |   )";
		H::delay(50); H::foreColor(7); H::gotoxy(68, 7); cout << R"(|____/ \___|\__,_|_|  \___|_| |_|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
		H::HLine(68, 9, 71, 5, 223);
}

void TeacherDesign::sorting(){
	H::foreColor(3); H::gotoxy(62, 9);  cout << R"(  ______     ___   _______   _________  _____  ____  _____   ______  )";
	H::foreColor(3); H::gotoxy(62, 10); cout << R"(.' ____ \  .'   `.|_   __ \ |  _   _  ||_   _||_   \|_   _|.' ___  | )";
	H::foreColor(3); H::gotoxy(62, 11); cout << R"(| (___ \_|/  .-.  \ | |__) ||_/ | | \_|  | |    |   \ | | / .'   \_| )";
	H::foreColor(3); H::gotoxy(62, 12); cout << R"( _.____`. | |   | | |  __ /     | |      | |    | |\ \| | | |   ____ )";
	H::foreColor(3); H::gotoxy(62, 13); cout << R"(| \____) |\  `-'  /_| |  \ \_  _| |_    _| |_  _| |_\   |_\ `.___]  |)";
	H::foreColor(7); H::gotoxy(62, 14); cout << R"( \______.' `.___.'|____| |___||_____|  |_____||_____|\____|`._____.' )";
	
}

void TeacherDesign::System(){
	H::setFixedScreenConsole(200,45);
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

string toUpper(const char* str) {
    std::string result;
    for (int i = 0; str[i] != '\0'; ++i)
        result += toupper(str[i]);
    return result;
}

void TeacherDesign::searchTeacher(int pageIndex) {
    char key;
    do {
        char searchName[30];
        H::cls();
        TeacherDesign::asciiSearchTeacher();
        TeacherDesign::designTable();
        TeacherDesign::showTeacher(pageIndex);
        H::gotoxy(73, 11);cout<< "              ";
        H::setcursor(true, 1);
		H::gotoxy(73, 11);cout<< "              ";
        H::drawBoxDoubleLine(73, 10, 61, 1, 3);
        H::gotoxy(75, 11); H::setcolor(7);
        cout << "ENTER TEACHER NAME FOR SEARCH : ";
        H::inputLetter(searchName, 20);

        H::cls();
        TeacherDesign::asciiSearchTeacher();
        TeacherDesign::designTable();
        TeacherDesign::showTeacher(pageIndex);
        H::gotoxy(73, 11);cout<< "              ";

		vector<Teacher> results;
		string searchNameUpper = toUpper(searchName);
        ifstream file("../data/Teacher_Data.bin", ios::binary);
        while (file.read(reinterpret_cast<char*>(&t), sizeof(Teacher))) {
			string teacherNameUpper = toUpper(t.getTeacherName());
			if (teacherNameUpper.find(searchNameUpper) != std::string::npos) {
				results.push_back(t);
			}
		}

        file.close();

        int total = results.size();
        if (total == 0) {
            H::gotoxy(97, 20);
            H::setcolor(4);
            cout << "NO TEACHER FOUND.";
        } else {
            int page = 0;
                H::clearBox(16, 19, 168, 22, 3);
                int start = page * 10;
                int end = min(start + 10, total);
                int row = 18;

                for (int i = start; i < end; i++) {
                    H::drawBoxDoubleLine(17, row + 1, 166, 1, 9);
                    H::setcolor(7);
                    H::gotoxy(19, row + 2);  cout << setw(10) << left << results[i].getTeacherId();
                    H::gotoxy(34, row + 2);  cout << setw(24) << left << results[i].getTeacherName();
                    H::gotoxy(60, row + 2);  cout << setw(12) << left << results[i].getGender();
                    H::gotoxy(78, row + 2);  cout << setw(18) << left << results[i].getSubject();
                    H::gotoxy(101, row + 2); cout << setw(14) << left << results[i].getDateOfBirth();
                    H::gotoxy(116, row + 2); cout << setw(16) << left << results[i].getPhone();
                    H::gotoxy(138, row + 2); cout << setw(22) << left << results[i].getYear();
                    H::gotoxy(153, row + 2); cout << setw(30) << left << results[i].getEmail();
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

void TeacherDesign::updateTeacher(int pageindex) {
    int x;	
		char updateId[20];
		bool isUpdate = false;
		TeacherDesign::designTable();
		TeacherDesign::showTeacher(pageindex);
		H::delay(10); H::foreColor(2); H::gotoxy(63, 3);  cout << R"( _   _           _       _                 _____               _               )";
		H::delay(10); H::foreColor(2); H::gotoxy(63, 4);  cout << R"(| | | |_ __   __| | __ _| |_ ___ 	 |_   _|__  __ _  ___| |__   ___ _ __ )";
		H::delay(10); H::foreColor(3); H::gotoxy(63, 5);  cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \	   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
		H::delay(10); H::foreColor(2); H::gotoxy(63, 6);  cout << R"(| |_| | |_) | (_| | (_| | ||  __/	   | |  __/ (_| | (__| | | |  __/ |   )";
		H::delay(10); H::foreColor(5); H::gotoxy(63, 7); cout << R"( \___/| .__/ \__,_|\__,_|\__\___| 	   |_|\___|\__,_|\___|_| |_|\___|_|   )";
		H::delay(10); H::foreColor(5); H::gotoxy(63, 8); cout << R"(      |_|                                                                 )";
		H::HLine(50, 9, 105, 5, 223);
		H::gotoxy(73, 11);cout<< "              ";
		H::drawBoxDoubleLine(84, 10, 35, 1, 3);
		H::gotoxy(85, 11); H::setcolor(7); 
		cout << "ENTER TEACHER ID TO UPDATE: T-";
		H::inputNumber(updateId, 4);

		fstream teachF("../data/Teacher_Data.bin", ios::in | ios::out | ios::binary); // open file
		if (!teachF) {
			H::gotoxy(63, 28); cout << "Cannot open file!";
		}

		while (teachF.read((char*)&t, sizeof(t))) { // read data from file
			if (strcmp(t.getTeacherId() + 2, updateId) == 0) {
				isUpdate = true;
				t.newInput();
				H::foreColor(0);
				teachF.seekp((int)teachF.tellg() - sizeof(t));
				teachF.write((char*)&t, sizeof(t));
				break;
			}
		}
		teachF.close();

		if (isUpdate) {
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
		} else {
			H::clearBox(16, 19, 168, 22, 3);
			H::setcursor(false, 0);
			H::gotoxy(52, 26); H::setcolor(4); cout << R"( _____               _                   _   _       _      _____                     _   _ _ _ )";
			H::gotoxy(52, 27); H::setcolor(4); cout << R"(|_   _|             | |                 | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |)";
			H::gotoxy(52, 28); H::setcolor(4); cout << R"(	| | ___  __ _  ___| |__   ___ _ __    |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |)";
			H::gotoxy(52, 29); H::setcolor(4); cout << R"(	| |/ _ \/ _` |/ __| '_ \ / _ \ '__|   | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|)";
			H::gotoxy(52, 30); H::setcolor(4); cout << R"(	\_/\___|\__,_|\___|_| |_|\___|_|      |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_))";
			getch();												
                                     
		}

	H::cls();
	H::foreColor(0);
}

fstream backup;
void TeacherDesign::deletedTeacher(int pageIndex) {
    H::cls();
    H::foreColor(3); H::gotoxy(60, 9); cout << R"( ______   ________  _____     ________  _________   _____  ____  _____    ______  )";
    H::foreColor(3); H::gotoxy(60, 10); cout << R"(|_   _ `.|_   __  ||_   _|   |_   __  ||  _   _  ||_   _||_   \|_   _| .' ___  | )";
    H::foreColor(3); H::gotoxy(60, 11); cout << R"(  | | `. \ | |_ \_|  | |       | |_ \_||_/ | | \_|  | |    |   \ | |  / .'   \_| )";
    H::foreColor(3); H::gotoxy(60, 12); cout << R"(  | |  | | |  _| _   | |   _   |  _| _     | |      | |    | |\ \| |  | |   ____ )";
    H::foreColor(3); H::gotoxy(60, 13); cout << R"( _| |_.' /_| |__/ | _| |__/ | _| |__/ |   _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
    H::foreColor(7); H::gotoxy(60, 14); cout << R"(|______.'|________||________||________|  |_____|  |_____||_____|\____| `._____.' )";
    TeacherDesign::loading();
    H::cls();

    do {
        bool isDeleted = false;
        char deleteId[20];
        H::setcolor(4);
        TeacherDesign::designTable();
        TeacherDesign::showTeacher(pageIndex);
        TeacherDesign::asciiDelete();
        H::gotoxy(73, 11); cout << "              ";
        H::drawBoxDoubleLine(84, 10, 36, 1, 3);
        H::setcolor(7); H::gotoxy(85, 11); cout << "ENTER TEACHER ID TO DELETE : T-";
        H::setcursor(true, 1);
        H::inputUNumber(deleteId, 4);

        fstream backup("../data/backup_data.bin", ios::out | ios::binary);
        fstream teachF("../data/Teacher_Data.bin", ios::in | ios::binary);

        if (!teachF) {
            H::gotoxy(75, 28);
            cout << "Cannot open file!";
            break;
        }

        while (teachF.read((char*)&t, sizeof(t))) {
            if (strcmp(t.getTeacherId() + 2, deleteId) == 0) {
                int confirm = MessageBoxA(GetConsoleWindow(),
                                          "Do you really want to delete this Teacher?",
                                          "Confirm Delete", MB_YESNO | MB_ICONQUESTION);
                if (confirm == IDYES) {
                    isDeleted = true;
                    continue; 
                }
            }
            backup.write((char*)&t, sizeof(t));
        }

        teachF.close();
        backup.close();

        remove("../data/Teacher_Data.bin");
        rename("../data/backup_data.bin", "../data/Teacher_Data.bin");

        if (isDeleted) {
            H::foreColor(2);
            TeacherDesign::designTable();
            TeacherDesign::showTeacher(pageIndex);
            TeacherDesign::asciiDelete();
            H::gotoxy(73, 11); cout << "              ";
            H::drawBoxDoubleLine(84, 10, 36, 1, 3);
            H::setcolor(7); H::gotoxy(85, 11); cout << "ENTER";
            H::clearBox(0, 44, 200, -1, 7);
            H::setcursor(false, 0);
            H::foreColor(2); H::gotoxy(84, 43);
            cout << "TEACHER ID " << deleteId << " DELETE SUCCESSFULLY!";
            break;
        } else {
            // ❌ Teacher not found animation
            H::cls();
            H::setcolor(4);
            cout << R"( | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |)";
            H::gotoxy(13, 2); cout << R"(_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|)";
            H::gotoxy(12, 3); cout << R"(UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU)";
            
            H::setcursor(false, 0);
            H::delay(10); H::foreColor(3); H::gotoxy(63, 4);  cout << R"( ____       _      _         _____               _                )";
            H::delay(10); H::foreColor(4); H::gotoxy(63, 5);  cout << R"(|  _ \  ___| | ___| |_ ___  |_   _|__  __ _  ___| |__   ___ _ __ )";
            H::delay(10); H::foreColor(5); H::gotoxy(63, 6);  cout << R"(| | | |/ _ \ |/ _ \ __/ _ \   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
            H::delay(10); H::foreColor(6); H::gotoxy(63, 7);  cout << R"(| |_| |  __/ |  __/ ||  __/   | |  __/ (_| | (__| | | |  __/ |   )";
            H::delay(10); H::foreColor(7); H::gotoxy(63, 8);  cout << R"(|____/ \___|_|\___|\__\___|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
            H::HLine(63, 10, 66, 5, 223);

            TeacherDesign::designTable();
            H::setcursor(false, 0);
            H::gotoxy(52, 26); H::setcolor(4); cout << R"(  _____               _                  _   _       _      _____                     _   _ _ _   )";
            H::gotoxy(52, 27); H::setcolor(4); cout << R"( |_   _|__  __ _  ___| |__   ____ __    | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |  )";
            H::gotoxy(52, 28); H::setcolor(4); cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |  )";
            H::gotoxy(52, 29); H::setcolor(4); cout << R"(   | |  __/ (_| | (__| | | |  __/ |     | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|  )";
            H::gotoxy(52, 30); H::setcolor(4); cout << R"(   |_|\___|\__,_|\___|_| |_|\___|_|     |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_)  )";
            break;
        }
    } while (true);

    getch();
    H::cls();
}


void TeacherDesign::sortTeacherByName(int pageIndex) {
    isSorted = !isSorted;  // toggle sorting mode
    showTeacher(pageIndex);
}
int TeacherDesign::getTotalTeachers() {
    ifstream file("../data/Teacher_Data.bin", ios::binary);
    if (!file) return 0;

    int count = 0;
    Teacher temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
        count++;
    }
	file.close();
    return count;
}

void TeacherDesign::teacherManagement() {
	H::setFixedScreenConsole(200, 45);
	TeacherDesign::System();
	H::cls();
	H::foreColor(0);
	char option;
	int x = 0;
	int pageIndex = 0;
    int totalStudents = td.getTotalTeachers();
    int maxPage = (totalStudents + 10) / 11 - 1;

	do{
		TeacherDesign::showdesign(pageIndex);
		H::drawBoxSingleLine(15, 10, 8, 1, 206); H::gotoxy(15, 11); cout << "  BACK  ";
		H::drawBoxSingleLine(35, 10, 9, 1, 158); H::gotoxy(35, 11); cout << "   SORT  ";
		H::drawBoxSingleLine(115, 10, 9, 1, 158); H::gotoxy(115, 11); cout << "   ADD   ";
		H::drawBoxSingleLine(135, 10, 10, 1, 158); H::gotoxy(135, 11); cout << "  UPDATE  ";
		H::drawBoxSingleLine(155, 10, 10, 1, 158); H::gotoxy(155, 11); cout << "  DELETE  ";
		H::drawBoxSingleLine(175, 10, 10, 1, 158); H::gotoxy(175, 11); cout << "  SEARCH  ";


		do{
			H::setcursor(false, 0);
			H::drawBoxSingleLine(15, 10, 8, 1, 206); H::gotoxy(15, 11); cout << "  BACK  ";
			H::drawBoxSingleLine(35, 10, 9, 1, 158); H::gotoxy(35, 11); cout << "   SORT  ";
			H::drawBoxSingleLine(115, 10, 9, 1, 158); H::gotoxy(115, 11); cout << "   ADD   ";
			H::drawBoxSingleLine(135, 10, 10, 1, 158); H::gotoxy(135, 11); cout << "  UPDATE  ";
			H::drawBoxSingleLine(155, 10, 10, 1, 158); H::gotoxy(155, 11); cout << "  DELETE  ";
			H::drawBoxSingleLine(175, 10, 10, 1, 158); H::gotoxy(175, 11); cout << "  SEARCH  ";
			
			if(x==0){
				H::drawBoxSingleLine(15, 10, 8, 1, 4); H::gotoxy(15, 11); cout << "  BACK  ";
			}
			if(x==1){
				 H::drawBoxSingleLine(35, 10, 9, 1, 1); H::gotoxy(35, 11); cout << "   SORT  ";
			}
			if(x==2){
				H::drawBoxSingleLine(115, 10, 9, 1, 1); H::gotoxy(115, 11); cout << "   ADD   ";
	
			}
			if(x==3){
				H::drawBoxSingleLine(135, 10, 10, 1, 1); H::gotoxy(135, 11); cout << "  UPDATE  ";
			
			}
			if(x==4){
				 H::drawBoxSingleLine(155, 10, 10, 1, 1); H::gotoxy(155, 11); cout << "  DELETE  ";

			}
			if(x==5){
				H::drawBoxSingleLine(175, 10, 10, 1, 1); H::gotoxy(175, 11); cout << "  SEARCH  ";
			}
			option=getch();
			switch(option){
				case 72: 
					H::clearBox(20,20,160,20,7);
					if (pageIndex > 0) pageIndex--;
					TeacherDesign::showdesign(pageIndex);
               		break;
				case 80:
					H::clearBox(20,20,160,20,7);
					if (pageIndex < maxPage) pageIndex++;
					TeacherDesign::showdesign(pageIndex);
					break;
				case 75:{ // left
					x--;
					if(x<0){
						x=5;
					}
					break;
				}case 77:{ // right
					x++;
					if(x>5){
						x=0;
					}
					break;
				}
			}
    	} while(option!=13);	
		H::setcursor(true, 1);
		if (x == 0) {
			H::cls();
			break;
		}
		if (x == 1) {
			H::foreColor(0);
			TeacherDesign::sortTeacherByName(pageIndex);
		}
		if (x == 2) { // ADD
				H::cls();
				H::foreColor(0);
				TeacherDesign::insertTeacher();
		}
		if (x == 3) { // UPDATE
			H::cls();
			H::foreColor(0);
			TeacherDesign::updateTeacher(pageIndex);
		}
		if (x == 4) { // DELETE
				H::cls();
				H::foreColor(0);
				TeacherDesign::deletedTeacher(pageIndex);
		}
		if (x == 5) {
			H::cls();
			H::foreColor(0);
			TeacherDesign::searchTeacher(pageIndex);
		}

		H::cls();
	} while(true);
}

#endif