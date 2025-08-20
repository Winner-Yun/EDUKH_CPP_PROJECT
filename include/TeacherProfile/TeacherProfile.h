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
    	//
    	static int navigateMenu(); 
        static void drawMenu(int selected);
    	//
        void ProfileMenu();
        void display();
        void displayProfile();
        void displayAssignClass();
        // ---------------------------------------
        TeacherProfile() {}
        TeacherProfile(const Teacher& t);
        // ---------------------------------------
        void showAssignClass(int No, int y, const AssignClass& assign);
        void displayAssignClasses() const;
        void showAssignedClasses();
        // ---------------------------------------
        void showAssignedClassesPaginate();
        // ---------------------------------------
        void changePassword();

        const Teacher& getTeacher() const { return teacher; }
        const char* getTeacherId() const { return teacherId;} 
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
    fin.close();;
}

// ==========================================================================
// ---- ProfileMenu: call on *this* and use 0-based cases ----
void TeacherProfile::ProfileMenu() {
    while (true) {
        int choice = navigateMenu();
		H::setcolor(7);
        H::cls();
        if (choice == -1) {
        	H::setcolor(7);
        	H::cls();
            break;  
        }

        switch (choice) {
            case 0:{
                H::setcolor(7);
                H::cls();
                changePassword();
                break;
            }

            case 1: {
                H::setcolor(7);
                H::cls();
                TeacherProfileDesign::ViewAssignClassText(3, 1);
                showAssignedClassesPaginate();
                break;
            }
        }
    }
}


// ---- Display: call on *this* ----

void TeacherProfile::changePassword()
{
	H::setcursor(true,1);
    TeacherProfileDesign::ChangePasswordText(37, 1);
    char currentPw[20], newPw[20], confirmPw[20];

    H::gotoxy(74,13); cout << "Enter Current Password: ";
    H::inputAll(currentPw, 20); 

    fstream file("../data/Teacher_Data.bin", ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "Cannot open Teacher_Data.bin!" << endl;
        return;
    }

    Teacher temp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
        if (strcmp(temp.getTeacherId(), teacherId) == 0) {  // match current teacher
            found = true;
            if (!temp.verifyPassword(currentPw)) {
                H::gotoxy(76, 27); cout << "Incorrect password!";
                file.close();
                return;
            }


            // Ask for new password
            H::gotoxy(74,17); cout<<"Enter New Password     : ";
            H::inputAll(newPw, 20);
            H::gotoxy(74,21); cout<<"Enter Confirm Password : ";
            H::inputAll(confirmPw, 20);

            if (strcmp(newPw, confirmPw) != 0) {
                H::gotoxy(76, 26);
                cout << "Passwords do not match!";
                file.close();
                return;
            }

            // Update password in object
            temp.setPassword(newPw);

            // Move write pointer back to overwrite
            file.seekp(-static_cast<int>(sizeof(Teacher)), ios::cur);
            file.write(reinterpret_cast<char*>(&temp), sizeof(Teacher));
            file.close();

            H::gotoxy(50, 26); cout << "Password updated successfully!";
            return;
        }
    }

     if (!found) {
        H::gotoxy(76, 26);
        cout << "Teacher not found!";
        file.close();
    }
}

void TeacherProfile::showAssignedClassesPaginate()
{
	H::setcolor(3);
	H::gotoxy(25,12); cout<<"ID : ";
	H::setcolor(2); cout<<this->teacherId;
	H::setcolor(3); H::gotoxy(155,12); cout<<"Name : ";
	H::setcolor(2); cout<<this->teacherName;
	
    ifstream fin("../data/AssignClass_Data.bin", ios::binary);

    if (!fin) {
        cerr << "Error opening AssignClass_Data.bin" << endl;
        return;
    }

    // Load all assigned classes for this teacher into a vector
    vector<AssignClass> assignedClasses;
    AssignClass assign;
    while (fin.read((char*)&assign, sizeof(AssignClass))) {
        if (strcmp(assign.getTeacherID(), teacherId) == 0) {
            assignedClasses.push_back(assign);
        }
    }
    fin.close();

    if (assignedClasses.empty()) {
        H::gotoxy(90, 25);
        cout << "No assigned classes found!";
        return;
    }

    const int rowsPerPage = 10;  
    int currentPage = 0;
    int totalPages = (assignedClasses.size() + rowsPerPage - 1) / rowsPerPage;

    while (true) {
        // clear area (adjust height for your UI)
        for (int i = 19; i <= 38; i++) {
            H::gotoxy(70, i);
            cout << string(80, ' '); // clear 80 chars per row
        }
        
        H::drawBoxSingleLine(68, 16, 70, 1,6); //  Table Header
		H::drawBoxSingleLine(68, 16, 70, 21,3); // Table Body Design

        // show header
        H::gotoxy(73, 17); cout << "No";
        H::gotoxy(88, 17); cout << "Class";
        H::gotoxy(105, 17); cout << "Subject";
        H::gotoxy(128, 17); cout << "Year";

        // show rows
        int startIdx = currentPage * rowsPerPage;
        int endIdx = min((int)assignedClasses.size(), startIdx + rowsPerPage);

        int y = 19;
        int No = startIdx + 1;

        for (int i = startIdx; i < endIdx; i++) {
            showAssignClass(No, y, assignedClasses[i]);
            No++;
            y += 2;
        }

        // footer info
        H::gotoxy(98, 40);
        cout << "Page " << (currentPage + 1) << " / " << totalPages;

        // wait for key
        int ch = _getch();
        if (ch == 27){
        	H::setcolor(7);
        	H::cls();
        	this->displayProfile();
        	break;
		}                // ESC = exit
        if (ch == 75 && currentPage > 0) currentPage--;          // Left arrow
        else if (ch == 77 && currentPage < totalPages - 1) currentPage++; // Right arrow
    }
}



void TeacherProfile::showAssignedClasses()
{
    ifstream fin("../data/AssignClass_Data.bin", ios::binary);

    if (!fin) {
        cerr << "Error opening AssignClass_Data.bin" << endl;
        return;
    }

    AssignClass assign;
    int No=1;
    int y=25;

    while (fin.read((char*)&assign, sizeof(AssignClass)))
    {
        // check if teacherID matches current profile
        if(strcmp(assign.getTeacherID(), teacherId)==0){
            showAssignClass(No, y, assign);
            No++;
            y += 2;
        }
    }
    fin.close();    
}

void TeacherProfile::showAssignClass(int No, int y, const AssignClass& assign) {
	H::setcolor(2);
    H::gotoxy(73, y);  cout << No;
    H::gotoxy(88, y);  cout << assign.getClassName();     // not getGrade
    H::gotoxy(105, y); cout << assign.getSubject();
    H::gotoxy(128, y); cout << assign.getAcademicYear();  // not getStudyYear
}


void TeacherProfile::display()
{
	H::setcolor(233); H::gotoxy(36,24); cout << "ID : "; 
    H::setcolor(234); cout << getTeacherId();
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
    
    //
}

void TeacherProfile::displayProfile()
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
	
	// display
	display();
    
    H::drawBoxSingleLineWithBG(71, 18, 70, 1,196); //  Table Bar
	H::setcolor(199);
	system("chcp 65001 > nul");
	H::gotoxy(82,19); cout<<"]|I{•------» RESPONSIBILITY CLASSES «------•}I|[";
	system("chcp 437 > nul");
	// Table
	TeacherProfileDesign::TeacherProfileTable(71,22);

    showAssignedClasses();
    
	
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
	H::gotoxy(45,43);
	setConsoleColor(BLACK, WHITE); 
	cout<<"Tips: [Use Arrow Up/Down to move]		[Press Enter to select]		[Press ESC to go back]";
	ProfileMenu();
	
}

// ========================== Draw Menu ==========================

const int SIZES = 2;
string settingMenu[SIZES] = {
    "1. Change Password",
    "2. View Assigned Classes"
};
int menuX = 151;
int menuY[SIZES] = {23, 28};

// Draw menu with arrow highlighting
void TeacherProfile::drawMenu(int selected) {
    for (int i = 0; i < SIZES; i++) {
        H::gotoxy(menuX, menuY[i]);
        if (i == selected) {
        	H::setcolor(234);
            cout << "-> " << settingMenu[i]; // highlight with arrow
        } else {
        	H::setcolor(233);
            cout << "   " << settingMenu[i];
        }
    }
}

// Function to navigate menu and return choice
int TeacherProfile::navigateMenu() {
    int selected = 0;
    drawMenu(selected);
    while (true) {
        int ch = _getch();

        if (ch == 0 || ch == 224) { // arrow keys
            ch = _getch();
            if (ch == 72) { // UP
                selected--;
                if (selected < 0) selected = SIZES - 1;
            } else if (ch == 80) { // DOWN
                selected++;
                if (selected >= SIZES) selected = 0;
            }
            drawMenu(selected);
        } else if (ch == 13) { // ENTER
            return selected; // return the selected menu item
        } else if (ch == 27) { // ESC key
        	H::setcolor(7);
        	H::cls();
            return -1; // special value to indicate "back to main menu"
        }
    }
}

#endif
