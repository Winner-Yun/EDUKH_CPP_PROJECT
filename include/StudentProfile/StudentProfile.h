#ifndef __STUDENTPROFILE_H__
#define __STUDENTPROFILE_H__

#include "../Header_EDU/StudentManagerment.h"
#include "../Header_School/ANTHinsyOOP"
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
    	
        void loadFromStruct(const Student& s);
        void displayRow() const;
        //
        void displayByEmail(const char* email);
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

void StudentProfile::displayRow() const 
{
    cout << left << setw(6)  << id
            << setw(20) << name
            << setw(8)  << grade
            << setw(6)  << academicYear
            << setw(8)  << gender
            << setw(12) << birthDate
            << setw(12) << telephone
            << setw(25) << email << endl;
}

// ================ Get Data From File ================

void StudentProfile::displayByEmail(const char* email)
{
    ifstream file(STUDENT_DATA_FILE, ios::binary);
    if (!file) {
        MessageBoxA(NULL, "Cannot open student data file!", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    cout << "========================= Student Profile by Email =========================\n";
    cout << left << setw(6)  << "ID"
         << setw(20) << "Name"
         << setw(8)  << "Grade"
         << setw(6)  << "Year"
         << setw(8)  << "Gender"
         << setw(12) << "BirthDate"
         << setw(12) << "Tel"
         << setw(25) << "Email" << endl;
    cout << string(100, '-') << endl;

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

#endif