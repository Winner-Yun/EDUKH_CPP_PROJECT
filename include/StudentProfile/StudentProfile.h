#ifndef __STUDENTPROFILE_H__
#define __STUDENTPROFILE_H__

#include "../Header_EDU/StudentManagerment.h"
#include "../Header_EDU/ManageScoreHeader.h"
#include "../Header_School/ANTHinsyOOP"
#include "StudentProfileDesign.h"
using namespace ANTHinsyOOP;

const string STUDENT_DATA_FILE = "../data/Student_Data.bin";

class StudentProfile
{
    private:
        char id[6];
        char name[50];
        char grade[3];
        char academicYear[5];
        char gender[10];
        char birthDate[15];
        char email[30];
        char telephone[15];
        //
        static constexpr const char* SCORE_FILE = "../data/ManageScoreBYAdmin.bin";
    public:
    	// ================ Constructor ===================
    	StudentProfile() {
	        strcpy(id, "");
	        strcpy(name, "");
	        strcpy(grade, "");
	        strcpy(academicYear, "");
	        strcpy(gender, "");
	        strcpy(birthDate, "");
	        strcpy(telephone, "");
	        strcpy(email, "");
    	}
    	// ==================================================
        void loadFromStruct(const Student& s);
        void displayRow();
        //
        int StudentProfileMenu();
        //
        void displayByEmail(const char* email);
        void changePasswordForm(); 
        void inputPasswordMask(int x, int y, char* password, int maxLen);
};

struct ManagementAdminGetAVG{
    int pageIndex = 0;  
    int totalPages = 1;  
    char studentID[15];
    char studentName[20];
    char grade[3];
    char AvgScore[20];
    char rank[2];
};

void StudentProfile::loadFromStruct(const Student& s) 
{
        strcpy(id, s.getId().c_str());
        strcpy(name, s.getName().c_str());
        strcpy(grade, s.getGrade().c_str());
        strcpy(academicYear, s.getYear().c_str());
        strcpy(gender, s.getGender().c_str());
        strcpy(birthDate, s.getBdate().c_str());
        strcpy(telephone, s.getTel().c_str());
        strcpy(email, s.getEmail().c_str());
}

void StudentProfile::displayRow() 
{
    char avgStr[10] = "-";
    char rankStr[5] = "-";

    // === Load score data from ManageScoreBYAdmin.bin ===
    ifstream file(SCORE_FILE, std::ios::binary);
    if (file) {
        ManagementAdminGetAVG ms;
        while (file.read(reinterpret_cast<char*>(&ms), sizeof(ManagementAdminGetAVG))) {
            if (strcmp(ms.studentID, id) == 0) {
                strcpy(avgStr, ms.AvgScore);
                strcpy(rankStr, ms.rank);
                break;
            }
        }
    }

    StudentProfileDesign::HeaderText(1,1);

    setConsoleColor(0, 11);
    H::gotoxy(82,10); cout  << id;
    H::gotoxy(82,14);cout << grade;
    H::gotoxy(82,17);cout << gender;
    H::gotoxy(82,20); cout << email ;
    H::gotoxy(137,10);cout << name;
    H::gotoxy(137,14);cout << academicYear;
    H::gotoxy(137,17);cout << birthDate;
    H::gotoxy(137,20);cout << telephone;
    setConsoleColor(GRAY, 14);
	H::gotoxy(69,27); cout<<"AVERAGE : ";
	H::gotoxy(114,27); cout<<"GRADE LETTER : ";
	setConsoleColor(BLACK, 14);	
    H::gotoxy(79,27);cout << avgStr;
    H::gotoxy(129,27);cout << rankStr;


    StudentProfileDesign::FooterText();
    
	H::setcursor(false,0);
    while (true) {
        int choice = StudentProfileMenu();
        switch (choice) {
            case 0: // Change Password
            	H::setcolor(2);
            	H::cls();
                changePasswordForm();
                H::setcolor(7);
                H::cls();
                return displayRow();
                //continue;
            case 1: // BackToMainMenu
                H::setcolor(2);
                system("cls");
                return; // exit OR jump to your main menu function
        }
    }
}

// ================ Get Data From File ================

void StudentProfile::changePasswordForm()
{
	H::setcursor(true,1);
    char currentPw[20], newPw[20], confirmPw[20];
    bool passwordCorrect = false;
    
    while (!passwordCorrect) {
        // Draw the change password interface
      StudentProfileDesign::ChangePasswordText(37, 1);

        // Ask for current password
        H::gotoxy(74,23); cout<<"Enter Current Password : ";
        H::gotoxy(74,26); cout<<"Enter New Password     : ";
        H::gotoxy(74,29); cout<<"Enter Confirm Password : ";
        
        inputPasswordMask(99, 23, currentPw, 20);
        
        // Verify the password
        fstream file(STUDENT_DATA_FILE, ios::binary | ios::in | ios::out);
        if (!file) {
            MessageBoxA(GetConsoleWindow(), "Cannot open Student_Data.bin!", "File Error", MB_OK | MB_ICONERROR);
            return;
        }

        Student temp;
        bool found = false;
        bool verified = false;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
            if (strcmp(temp.getId().c_str(), id) == 0) {  // match current student
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
            MessageBoxA(GetConsoleWindow(), "Student not found!", "Error", MB_OK | MB_ICONERROR);
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
            changePasswordForm();
            return;
        }
        return; // Default case, go back
    }

    // Update password in object
    fstream file(STUDENT_DATA_FILE, ios::binary | ios::in | ios::out);
    if (!file) {
        MessageBoxA(GetConsoleWindow(), "Cannot open Student_Data.bin!", "File Error", MB_OK | MB_ICONERROR);
        return;
    }

    Student temp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        if (strcmp(temp.getId().c_str(), id) == 0) {  // match current student
            found = true;
            // Update password in object
            temp.setPassword(newPw);

            // Move write pointer back to overwrite
            file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);
            file.write(reinterpret_cast<char*>(&temp), sizeof(Student));
            file.close();

            H::setcolor(18);
	        H::gotoxy(78, 32); cout << " Student's password updated successfully! ";
	        getch();
            return;
        }
    }

    if (!found) {
        MessageBoxA(GetConsoleWindow(), "Student not found!", "Error", MB_OK | MB_ICONERROR);
        file.close();
    }
}

void StudentProfile::inputPasswordMask(int x, int y, char* password, int maxLen) {
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

void StudentProfile::displayByEmail(const char* email)
{
    ifstream file(STUDENT_DATA_FILE, ios::binary);
    if (!file) {
        MessageBoxA(GetConsoleWindow(), "Cannot open student data file!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    Student s;
    StudentProfile profile;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        profile.loadFromStruct(s);
        if (strcmp(profile.email, email) == 0) {
            profile.displayRow();
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with email: " << email << endl;
    }

    file.close();
}

int StudentProfile::StudentProfileMenu() {
    const int menuCount = 2;
    string menu[menuCount] = {"CHANGE PASSWORD", "BACK"};
    int current = 0; 

    while (true) {
        // Clear area first
        //system("cls");

        // Title bar
        H::drawBoxDoubleLineWithBG(140, 2, 25, 1, 151);
        H::gotoxy(143, 3);
        H::setcolor(151);
        if (current == 0) {
            H::setcolor(180); // highlighted
            cout << "> " << menu[0] << " <";
        } else {
            H::setcolor(151); // normal
            cout << "  " << menu[0] << "  ";
        }

        H::drawBoxDoubleLineWithBG(170, 2, 25, 1, 151);
        H::gotoxy(179, 3);
        if (current == 1) {
            H::setcolor(180); // highlighted
            cout << "> " << menu[1] << " <";
        } else {
            H::setcolor(151); // normal
            cout << "  " << menu[1] << "  ";
        }

        // Input
        int ch = _getch();
        if (ch == 0 || ch == 224) { // special key
            ch = _getch();
            if (ch == 75) { // left arrow
                current = (current - 1 + menuCount) % menuCount;
            } else if (ch == 77) { // right arrow
                current = (current + 1) % menuCount;
            }
        } else if (ch == 13) { // Enter
            return current; // 0 = change password, 1 = back
        }
    }
}


#endif