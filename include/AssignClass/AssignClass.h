#ifndef __INC_ASSIGNCLASS__
#define __INC_ASSIGNCLASS__

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
        void DisplayAll(const char* className, int page=0, int sortMethod=0) const;
		void display(int index, int y);
        void DeleteClass(const char* className);
		void SearchClass(const char* className, string& keyword) const;
		//
		int CountRecords(const char* className) const;
		const char* formatTitleName(const char* name, const char* gender);
		static const char* stripTitlePrefix(const char* name);
};


// vector<AssignClass> records;

int AssignClass::idCounter = 1;

void AssignClass::SearchClass(const char* className, string& keyword) const
{
	ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
	    if (!inFile) {
        MessageBoxA(NULL, "Error", "File not found", MB_OK);
        return;
    }

	const int maxResults = 10;  // limit to 10 matches
    int count = 0;
    int y = 20;
    int displayIndex = 1;
    bool foundAny = false;

	// Lowercase keyword for case-insensitive match
	string lowerKeyword = keyword;
	transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

	AssignClass ac;
	while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClass)) && count < maxResults) {
        if (strcmp(ac.className, className) == 0) {
            string teacher = ac.teacherName;
            transform(teacher.begin(), teacher.end(), teacher.begin(), ::tolower);

            if (teacher.find(lowerKeyword) != string::npos) {
                foundAny = true;
				AssignClassDesign::SearchTable();
				H::setcolor(3);
                ac.display(displayIndex++, y);
                y += 2;
                count++;
            }
        }
    }

	if (!foundAny) {
		AssignClassDesign::SearchNotFound(32,25);
    }

    inFile.close();
}

void AssignClass::DeleteClass(const char* className) 
{
	H::setcursor(true,1);

	AssignClassDesign::DeleteClassDesign();

	char gradeID[20];
	char inputNumber[20];
	
	H::setcolor(151);
	H::setcolor(3); H::gotoxy(72,23); cout<<"Enter Grade ID To Delete: G"; H::inputNumber(inputNumber,20); 
	sprintf(gradeID, "G%s", inputNumber);

	
    ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "File not found", MB_OK);
        return;
    }

	ofstream outFile("../data/temp.bin", ios::binary);
    if (!outFile) {
        MessageBoxA(NULL, "Error", "Cannot create temp file", MB_OK);
        inFile.close();
        return;
    }

	AssignClass ac;
    bool deleted = false;

	while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClass))) {
        if (strcmp(ac.className, className) == 0 && strcmp(ac.gradeID, gradeID) == 0) {
            deleted = true; // Found and skip writing
            continue;
        }
        outFile.write(reinterpret_cast<const char*>(&ac), sizeof(AssignClass));
    }

	inFile.close();
    outFile.close();

	remove("../data/AssignClass_Data.bin");
    rename("../data/temp.bin", "../data/AssignClass_Data.bin");

	if (deleted) {
        //MessageBox(NULL, "Teacher deleted successfully", "Success", MB_OK);
		H::setcolor(2); H::gotoxy(86,38); cout<<"Teacher deleted successfully";
	} else {
        //MessageBox(NULL, "Teacher not found", "Info", MB_OK);
		H::setcolor(4); H::gotoxy(90,38); cout<<"Teacher not found";
    }
}

void AssignClass::DisplayAll(const char* className, int page, int sortMethod) const {
	ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
	    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(70, 37);
        //cout << "Cannot open data file.";
		MessageBoxA(NULL,"Error", "File not found", MB_OK);
        return;
    }

	vector<AssignClass> records;
	AssignClass ac;

	while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClass))) {
        if (strcmp(ac.className, className) == 0) {
            records.push_back(ac);
        }
    }
    inFile.close();

	// Sort according to sortMethod
    switch (sortMethod) {
        case 0: // GradeID small→big
            sort(records.begin(), records.end(), [](const AssignClass &a, const AssignClass &b){
                return strcmp(a.gradeID, b.gradeID) < 0;
            });
            break;
        case 1: // GradeID big→small
            sort(records.begin(), records.end(), [](const AssignClass &a, const AssignClass &b){
                return strcmp(a.gradeID, b.gradeID) > 0;
            });
            break;
        case 2: // Teacher name A→Z
            sort(records.begin(), records.end(), [](const AssignClass &a, const AssignClass &b){
                return strcmp(AssignClass::stripTitlePrefix(a.teacherName), AssignClass::stripTitlePrefix(b.teacherName)) < 0;
            });
            break;
        case 3: // Teacher name Z→A
            sort(records.begin(), records.end(), [](const AssignClass &a, const AssignClass &b){
                return strcmp(AssignClass::stripTitlePrefix(a.teacherName), AssignClass::stripTitlePrefix(b.teacherName)) > 0;
            });
            break;
    }

	const int recordsPerPage = 10;
	int startIndex = page * recordsPerPage;
	int endIndex = min(startIndex + recordsPerPage, (int)records.size());

	int y = 18;
	int displayIndex = startIndex + 1;

	for (int i = startIndex; i < endIndex; ++i) {
        records[i].display(displayIndex++, y);
        y += 2;
    }

    int totalPages = (records.size() + recordsPerPage - 1) / recordsPerPage;
    H::gotoxy(99,40);
    cout << (page + 1) << " / " << totalPages;
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
	char inputNumber[20];
	H::setcolor(151);
	H::gotoxy(72,16); cout << "Enter Teacher's ID: T-"; H::inputNumber(inputNumber,20); 
	sprintf(inputTeacherID, "T-%s", inputNumber);

	// Check Teacher existence
	ifstream fin("../data/Teacher_Data.bin", ios::binary);
	if(!fin){
		H::setcolor(250);
    	H::gotoxy(86,37);
		MessageBoxA(NULL,"Error", "File not found", MB_OK);
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
// ============================================== 

int AssignClass::CountRecords(const char* className) const {
    ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) return 0;

    int count = 0;
    AssignClass ac;

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClass))) {
        if (strcmp(ac.className, className) == 0) {
            count++;
        }
    }
    inFile.close();
    return count;
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

// Helper function to get the name part after "Mr. " or "Ms. "
const char* AssignClass::stripTitlePrefix(const char* name) {
    if (strncmp(name, "Mr. ", 4) == 0) {
        return name + 4; // skip "Mr. "
    } else if (strncmp(name, "Ms. ", 4) == 0) {
        return name + 4; // skip "Ms. "
    }
    return name;
}


#endif // ASSIGNCLASS_H