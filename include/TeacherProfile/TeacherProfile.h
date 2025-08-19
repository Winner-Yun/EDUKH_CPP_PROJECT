#ifndef __INC_TEACHERPROFILE__
#define __INC_TEACHERPROFILE__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/TeacherManagement.h"
#include "../AssignClass/AssignClass.h"
#include "TeacherProfileDesign.h"
#include "ConsoleColor.h"
#include <fstream>
#include <windows.h>
using namespace ANTHinsyOOP;

class TeacherProfile
{
    private:
        char teacherId[20];
        char teacherName[20];
        char gender[20];
        char subject[20];
        char dateOfBirth[20];
        char academyYear[10];
        char email[40];
        char phoneNumber[15];
        // ---------------------------------------
        Teacher teacher;
    public:
        static void ProfileMenu();
        void display();
        void displayAssignClass();
        // ---------------------------------------
        TeacherProfile() {}
        TeacherProfile(const Teacher& t);
        // ---------------------------------------
        void displayAssignClasses() const;
        // ---------------------------------------
        //TeacherProfile() {}
        //TeacherProfile(const Teacher& t) : teacher(t) {}

        const Teacher& getTeacher() const { return teacher; }
};

TeacherProfile::TeacherProfile(const Teacher& t) {
    strcpy(teacherId, t.getTeacherId());
    strcpy(teacherName, t.getTeacherName());
    strcpy(gender, t.getGender());
    strcpy(subject, t.getSubject());
    strcpy(dateOfBirth, t.getDateOfBirth());
    strcpy(academyYear, t.getYear());
    strcpy(email, t.getEmail());
    strcpy(phoneNumber, t.getPhone());
}

void getTeacherProfileByEmail(const char* emailToFind, TeacherProfile& profile) {
	
    ifstream fin("../data/Teacher_Data.bin", ios::binary);
    Teacher teacher;

    if (!fin) {
        cerr << "Error opening Teacher_Data.bin" << endl;
        return;
    }

    while (fin.read((char*)&teacher, sizeof(Teacher))) {
        if (strcmp(teacher.getEmail(), emailToFind) == 0) {
            profile = TeacherProfile(teacher);
            break;
        }
    }
    fin.close();
}

// ==========================================================================
void TeacherProfile::ProfileMenu()
{
	TeacherProfile tp;
	tp.displayAssignClasses();
    int choice = TeacherProfileDesign::navigateMenu();
    switch (choice){
        case 1:{
            // Change Password
            break;
        }
        case 2:{
            // View Assign Class
            break;
        }
    }
}

void TeacherProfile::displayAssignClasses() const {
    ifstream checkFile("../data/AssignClass_Data.bin", ios::binary);
    if (!checkFile) {
        cout << "Cannot open AssignClass_Data.bin\n";
        return;
    }

    vector<AssignClass> classes;
    AssignClass c;

    // Load only records that match this teacher
    while (checkFile.read(reinterpret_cast<char*>(&c), sizeof(AssignClass))) {
        if (strcmp(c.getTeacherID(), this->teacher.getTeacherId()) == 0) {
            classes.push_back(c);
        }
    }
    checkFile.close();

    if (classes.empty()) {
        cout << "No assigned classes found for this teacher.\n";
        return;
    }

    // Sort by studyYear descending
    sort(classes.begin(), classes.end(), [](const AssignClass& a, const AssignClass& b) {
        return string(a.getStudyYear()) > string(b.getStudyYear());
    });

    // Start row position
    int y = 25;
    int No = 1;

    TeacherProfileDesign::TeacherProfileTable(71,22);

    // Display only last 8
    int count = 0;
    for (auto& cls : classes) {
        if (count >= 8) break;

        H::gotoxy(73, y);  cout << No++;
        H::gotoxy(88, y);  cout << cls.getGrade();
        H::gotoxy(105, y); cout << cls.getSubject();
        H::gotoxy(128, y); cout << cls.getStudyYear();

        y += 2;
        ++count;
    }
}




void TeacherProfile::display()
{
	H::setcursor(false,0);
	TeacherProfileDesign::TeacherProfileText(42, 2);

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
	
    H::setcolor(233); H::gotoxy(36,24); cout << "ID : "; 
    H::setcolor(234); cout << teacherId;
    H::setcolor(233); H::gotoxy(21,26); cout << "Name : "; 
    H::setcolor(234); cout << teacherName;
    H::setcolor(233); H::gotoxy(46,26); cout << "Gender : "; 
    H::setcolor(234); cout << gender;

    H::setcolor(233); H::gotoxy(22,30); cout << "Subject       : ";
    H::setcolor(234); cout << subject;
    H::setcolor(233); H::gotoxy(22,32); cout << "Date Of Birth : ";
    H::setcolor(234); cout << dateOfBirth;
    H::setcolor(233); H::gotoxy(22,34); cout << "Study Year    : "; 
    H::setcolor(234); cout << academyYear;
    H::setcolor(233); H::gotoxy(22,36); cout << "Email         : "; 
    H::setcolor(234); cout << email;
    H::setcolor(233); H::gotoxy(22,38); cout << "Phone         : "; 
    H::setcolor(234); cout << phoneNumber;

    H::drawBoxSingleLineWithBG(71, 18, 70, 1,196); //  Table Bar
	H::setcolor(199);
	system("chcp 65001 > nul");
	H::gotoxy(82,19); cout<<"]|I{•------» RESPONSIBILITY CLASSES «------•}I|[";
	system("chcp 437 > nul");
	// Table
	TeacherProfileDesign::TeacherProfileTable(71,22);
	
	TeacherProfileDesign::bus(112,10);
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
	
	ProfileMenu();
}

#endif
