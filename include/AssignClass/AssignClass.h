#include "../Header_School/ANTHinsyOOP"
#include "AssignClassDesign.h"
#include "../Header_EDU/TeacherManagement.h"
using namespace ANTHinsyOOP;

class AssignClass{
	private:
		char gradeID[10]; // G1001, G1101, G1201
		char className[5]; // 10, 11, 12
		char teacherName[30];
		char teacherID[20];
		char subject[20];
		char academicYear[12];
		char phoneNumber[15]; // 091234567890
		char createAt[11]; // 07-03-2025
		static int idCounter;
    public:
        void InputClass(const char* className); // classname = 10, 11, 12
        void DisplayAll(const char* className) const;
		void display(int index, int y);
        void DeleteClass(const char* className);
		//
		const char* formatTitleName(const char* name, const char* gender);
};

// vector<AssignClass> records;

int AssignClass::idCounter = 1;

void AssignClass::DisplayAll(const char* className) const {
	ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
	    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(70, 37);
        //cout << "Cannot open data file.";
		MessageBox(NULL,"Error", "File not found", MB_OK);
        return;
    }

    AssignClass ac;
	
	int y = 18; // start Y position for rows
    int index = 1;  // No. column

	bool found = false;

	while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClass)))
	{
		if(strcmp(ac.className, className) == 0) 
		{
			found = true;

			ac.display(index++, y);
			y += 2;
		}
	}

	if (!found) {
        H::setcolor(12);
        H::gotoxy(70, 23);
        //cout << "No records found for class " << className << ".";
    }

    inFile.close();
	
}

void AssignClass::display(int index, int y) 
{
	H::setcolor(10);
	H::gotoxy(35,y); cout<<index;
	H::gotoxy(45,y); cout<<gradeID;
	H::gotoxy(65,y); cout<<teacherID;
	H::gotoxy(85,y); cout<<teacherName;
	H::gotoxy(110,y); cout<<subject;
	H::gotoxy(130,y); cout<<academicYear;
	H::gotoxy(150,y); cout<<phoneNumber;
}

void AssignClass::InputClass(const char* className) 
{
	H::setcursor(true, 1);

	// Design
	AssignClassDesign::AssignTeacherDesign();
	// AssignClassDesign::G10(0, 15);
    // AssignClassDesign::G10(159, 15);

	char inputTeacherID[20];
	H::setcolor(151);
	H::gotoxy(72,16); cout<<"Enter Teacher's ID: "; H::inputAll(inputTeacherID,20); 

	// Check Teacher existence
	ifstream fin("../data/Teacher_Data.bin", ios::binary);
	if(!fin){
		H::setcolor(250);
    	H::gotoxy(86,37);
		cerr << "Teacher data file not found.";
		return;
	}

	Teacher t;
	bool found = false;
	while (fin.read(reinterpret_cast<char*>(&t), sizeof(Teacher)))
	{
		if (strcmp(t.getTeacherId(), inputTeacherID) == 0)
		{
			found = true;

			// Failed to open Teacher_Data.bin
			ifstream checkFile("../data/AssignClass_Data.bin", ios::binary);
			AssignClass existing;

			while (checkFile.read(reinterpret_cast<char*>(&existing), sizeof(AssignClass)))
			{
				if (strcmp(existing.teacherID, inputTeacherID) == 0 && strcmp(existing.className, className) == 0) {
					H::setcolor(250);
					H::gotoxy(75,37);
					cout << "This teacher is already assigned to grade " << className << ".";
					checkFile.close();
					fin.close();
					return;
				}
			}
			checkFile.close();
			// Find the highest existing ID in AssignClass_Data.bin
			ifstream readMax("../data/AssignClass_Data.bin", ios::binary);
			AssignClass temp;
			int maxId = 0;
 
			while (readMax.read(reinterpret_cast<char*>(&temp), sizeof(AssignClass))) {
				int id = 0;
				string prefix = "G" + string(className);
				if (strncmp(temp.gradeID, prefix.c_str(), prefix.length()) == 0) {
					sscanf(temp.gradeID + prefix.length(), "%d", &id); // Extract numeric part
					if (id > maxId) maxId = id;
				}
			}

			readMax.close();
			idCounter = maxId + 1;
			// Display and assign
			sprintf(this->gradeID, "G%s%03d", className, idCounter++);
			const char* displayName = formatTitleName(t.getTeacherName(), t.getGender());


			H::setcolor(188);
			H::gotoxy(92,23); cout<<"GradeID: "<<this->gradeID;
			H::gotoxy(61,27); cout<<"Teacher Name: "<<displayName;
			H::gotoxy(103,27); cout<<"Subject: "<<t.getSubject();
			H::gotoxy(61,31); cout<<"Academic Year: "<<t.getYear();
			H::gotoxy(103,31); cout<<"Phone Number: "<<t.getPhone();
			
			strcpy(this->className, className);
			strcpy(this->teacherID, t.getTeacherId());
			strcpy(this->teacherName, displayName);
			strcpy(this->subject, t.getSubject());
			strcpy(this->academicYear, t.getYear());
			strcpy(this->phoneNumber, t.getPhone());

			ofstream fout("../data/AssignClass_Data.bin", ios::binary | ios::app);
			if(!fout){
				H::setcolor(250);
    			H::gotoxy(86,37);
				cerr << "AssignClass data file not found.";
                return;
			}
			fout.write(reinterpret_cast<char*>(this), sizeof(AssignClass));
			fout.close();

			H::setcolor(250);
    		H::gotoxy(86,37); cout << "Class assigned successfully!";
			break;
		}
		
	}
	fin.close();
	if (!found) {
		H::setcolor(252);
        H::gotoxy(69,37); cout << "Teacher not found.";
    }

}

const char* AssignClass::formatTitleName(const char* name, const char* gender) {
    static char result[50]; // Use static to return pointer safely
    if (strcmp(gender, "Male") == 0) {
        sprintf(result, "Mr. %s", name);
    } else if (strcmp(gender, "Female") == 0) {
        sprintf(result, "Ms. %s", name); // or "Mrs."
    } else {
        strcpy(result, name);
    }
    return result;
}