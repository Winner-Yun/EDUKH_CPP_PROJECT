#ifndef __INC_TEACHERPROFILE__
#define __INC_TEACHERPROFILE__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/TeacherManagement.h"
#include "../AssignClass/AssignClass.h"
#include "TeacherProfileDesign.h"
#include "ConsoleColor.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <conio.h>
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
        bool ProfileMenu(bool& shouldExit); // Add overloaded version
        void display();
        void displayProfile();
        void displayAssignClass();
        void ProfileDesign();
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
        void inputPasswordMask(int x, int y, char* password, int maxLen);
        // ---------------------------------------
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
    bool shouldExit = false;
    ProfileMenu(shouldExit);
}

bool TeacherProfile::ProfileMenu(bool& shouldExit) {
    while (true) {
        int choice = navigateMenu();
        if (choice == -1) {
            // ESC was pressed, just return to main profile display
            return false; // Return false to indicate ESC was pressed
        }

        // Clear screen for menu options
        H::setcolor(7);
        H::cls();
        
        switch (choice) {
            case 0:{
                changePassword();
                H::setcolor(7);
                H::cls();
                ProfileDesign();
                break;
            }
            case 1: {
                TeacherProfileDesign::ViewAssignClassText(3, 1);
                showAssignedClassesPaginate();
                H::setcolor(7);
                H::cls();
                ProfileDesign();
                break;
            }
        }
    }
    return true; // This line should never be reached, but added for completeness
}


// ---- Display: call on *this* ----

void TeacherProfile::changePassword()
{
	H::setcursor(true,1);
    char currentPw[20], newPw[20], confirmPw[20];
    bool passwordCorrect = false;
    
    while (!passwordCorrect) {
        // Draw the change password interface
        TeacherProfileDesign::ChangePasswordText(37, 1);
        
        // Ask for current password
        H::gotoxy(74,23); cout<<"Enter Current Password : ";
        H::gotoxy(74,26); cout<<"Enter New Password     : ";
        H::gotoxy(74,29); cout<<"Enter Confirm Password : ";
        
        inputPasswordMask(99, 23, currentPw, 20);
        
        // Verify the password
        fstream file("../data/Teacher_Data.bin", ios::binary | ios::in | ios::out);
        if (!file) {
            MessageBoxA(NULL, "Cannot open Teacher_Data.bin!", "File Error", MB_OK | MB_ICONERROR);
            return;
        }

        Teacher temp;
        bool found = false;
        bool verified = false;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
            if (strcmp(temp.getTeacherId(), teacherId) == 0) {  // match current teacher
                found = true;
                if (temp.verifyPassword(currentPw)) {
                    verified = true;
                    passwordCorrect = true;
                }
                break;
            }
        }
        file.close();
        
        if (!found) {
            MessageBoxA(NULL, "Teacher not found!", "Error", MB_OK | MB_ICONERROR);
            return;
        }
        
        if (!verified) {
            H::setcolor(228); H::gotoxy(89, 32); cout << " Incorrect password! ";
            
            // Wait for user input
            int ch = _getch();
            if (ch == 27) { // ESC key
                return; // Go back to profile
            } else if (ch == 13) { // Enter key
                H::setcolor(7);
                H::cls();
                // Continue the loop to ask for password again
                continue;
            }
            return; // Default case, go back
        }
    }
    
    // Now ask for new password
   	
    inputPasswordMask(99, 26, newPw, 20);
    inputPasswordMask(99, 29, confirmPw, 20);

    if (strcmp(newPw, confirmPw) != 0) {
        H::setcolor(228);
        H::gotoxy(88,32); cout << " Passwords do not match! ";
        
        // Wait for user input
        int ch = _getch();
        if (ch == 27) { // ESC key
            return; // Go back to profile
        } else if (ch == 13) { // Enter key
            H::setcolor(7);
            H::cls();
            // Call changePassword again to restart the process
            changePassword();
            return;
        }
        return; // Default case, go back
    }

    // Update password in object
    fstream file("../data/Teacher_Data.bin", ios::binary | ios::in | ios::out);
    if (!file) {
        MessageBoxA(NULL, "Cannot open Teacher_Data.bin!", "File Error", MB_OK | MB_ICONERROR);
        return;
    }

    Teacher temp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
        if (strcmp(temp.getTeacherId(), teacherId) == 0) {  // match current teacher
            found = true;
            // Update password in object
            temp.setPassword(newPw);

            // Move write pointer back to overwrite
            file.seekp(-static_cast<int>(sizeof(Teacher)), ios::cur);
            file.write(reinterpret_cast<char*>(&temp), sizeof(Teacher));
            file.close();

            H::setcolor(18);
	        H::gotoxy(78, 32); cout << " Teacher's password updated successfully! ";
	        getch();
            return;
        }
    }

    if (!found) {
        MessageBoxA(NULL, "Teacher not found!", "Error", MB_OK | MB_ICONERROR);
        file.close();
    }
}

void TeacherProfile::inputPasswordMask(int x, int y, char* password, int maxLen) {
    int i = 0;
    bool showPassword = false;  // start hidden
    char ch;

    auto drawPassword = [&]() {
        H::gotoxy(x, y);
        for (int j = 0; j < i; j++) {
            cout << (showPassword ? password[j] : '*');
        }
        cout << string(maxLen - i, ' '); // clear rest
        // draw visibility text
        H::setcolor(1);
        H::gotoxy(x + maxLen + 1, y);
        cout << (showPassword ? "[Show]" : "[Hide]");
        H::gotoxy(x + i, y); // move cursor back
    };

    drawPassword();

    while (true) {
        ch = _getch();

        if (ch == 13) { // Enter
            password[i] = '\0';
            break;
        } else if (ch == 8) { // Backspace
            if (i > 0) {
                i--;
                password[i] = '\0';
                drawPassword();
            }
        } else if (ch == 9) { // TAB to toggle visibility
            showPassword = !showPassword;
            drawPassword();
        } else if (i < maxLen - 1 && isprint(ch)) {
            password[i++] = ch;
            password[i] = '\0';
            drawPassword();
        }
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
        MessageBoxA(NULL, "Error opening AssignClass_Data.bin!", "File Error", MB_OK | MB_ICONERROR);
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
        MessageBoxA(NULL, "No assigned classes found!", "Information", MB_OK | MB_ICONINFORMATION);
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
        	// ESC pressed, clear screen and return to ProfileMenu
        	H::setcolor(7);
        	H::cls();
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
        MessageBoxA(NULL, "Error opening AssignClass_Data.bin!", "File Error", MB_OK | MB_ICONERROR);
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
	H::setcolor(233); H::gotoxy(35,24); cout << "ID : "; 
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
	ProfileDesign();

	// Call ProfileMenu and check if ESC was pressed
	bool shouldExit = false;
	if (!ProfileMenu(shouldExit)) {
		// ESC was pressed, exit the profile view entirely
		H::setcolor(7);
		H::cls();
		return;
	}
}

void TeacherProfile::ProfileDesign()
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
	setConsoleColor(BLACK, WHITE);
	H::gotoxy(50,43); 
	H::gotoxy(50,43); cout<<" Tips: [Use Arrow Up/Down to move] ";
	H::gotoxy(95,43); cout<<" [Press Enter to select] ";
	H::gotoxy(130,43); cout<<" [Press ESC to go back] ";
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
            return -1; // special value to indicate "back to main menu"
        }
    }
}

#endif
