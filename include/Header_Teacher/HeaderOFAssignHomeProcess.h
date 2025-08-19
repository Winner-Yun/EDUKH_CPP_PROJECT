#ifndef __ASSIGNHOMEWORK_PROCESS_H__
#define __ASSIGNHOMEWORK_PROCESS_H__
#include "../Header_School/ANTHinsyOOP"
#include "Teach_MainMenu.h"
using namespace ANTHinsyOOP;
class AssignHomeWorkProcess{
private:
    char teacherID[10];
    char teacherName[100];
    char grade[10];
    char homeWorkID[2];
    char homeworkDescription[154];
    char homeWorkNote[154];
    char date[20];        
    char createTime[20]; 
public:
    static void AssignHomeWorkMainDesign(const char* grade);
    const char* getnameFromFile(const char* id);
    const char* getDescriptionFromFile(const char* teacherID,const char* homeWorkID,const char* grade);
    const char* gethomeWorkNote(const char* teacherID,const char* homeWorkID,const char* grade);
    void recreateHomework(const char* tID, const char* g, const char* hwID);

    void setAllData(const char* tID, const char* tName, const char* g,
                    const char* hwID, const char* hwDesc);
};
AssignHomeWorkProcess assH;

const char* AssignHomeWorkProcess::getnameFromFile(const char* id) {
    static char buffer[100];

    ifstream file("../data/Teacher_Data.bin", ios::binary);
    if (!file) {
        cout << "Failed to open file.\n";
        return "";
    }

    Teacher_formm t;
    while (file.read(reinterpret_cast<char*>(&t), sizeof(Teacher_formm))) {
        if (strcmp(t.teacherId, id) == 0) {
            strcpy(buffer, t.teacherName);

            for (int i = 0; buffer[i]; i++) {
                buffer[i] = toupper(buffer[i]);
            }

            return buffer;
        }
    }

    return " ";
}

const char* AssignHomeWorkProcess::getDescriptionFromFile(
    const char* teacherIDParam, 
    const char* homeWorkIDParam, 
    const char* gradeParam
) {
    static char buffer[256];  

    std::ifstream file("../data/AssignCHomeWork.bin", std::ios::binary);
    if (!file) {
        std::cout << "Failed to open file.\n";
        return "";
    }

    AssignHomeWorkProcess hw; 

    while (file.read(reinterpret_cast<char*>(&hw), sizeof(AssignHomeWorkProcess))) {
        if (strcmp(hw.teacherID, teacherIDParam) == 0 &&
            strcmp(hw.homeWorkID, homeWorkIDParam) == 0 &&
            strcmp(hw.grade, gradeParam) == 0) 
        {
            strcpy(buffer, hw.homeworkDescription);
            return buffer;
        }
    }

    return "None";  
}

const char* AssignHomeWorkProcess::gethomeWorkNote(
    const char* teacherIDParam, 
    const char* homeWorkIDParam, 
    const char* gradeParam
) {
    static char buffer[256];  

    std::ifstream file("../data/AssignCHomeWork.bin", std::ios::binary);
    if (!file) {
        std::cout << "Failed to open file.\n";
        return "";
    }

    AssignHomeWorkProcess hw; 

    while (file.read(reinterpret_cast<char*>(&hw), sizeof(AssignHomeWorkProcess))) {
        if (strcmp(hw.teacherID, teacherIDParam) == 0 &&
            strcmp(hw.homeWorkID, homeWorkIDParam) == 0 &&
            strcmp(hw.grade, gradeParam) == 0) 
        {
            strcpy(buffer, hw.homeWorkNote);
            return buffer;
        }
    }

    return "None";  
}


void AssignHomeWorkProcess::setAllData(
    const char* tID = "0000",
    const char* tName = "Unknown",
    const char* g = "N/A",
    const char* hwID = "0",
    const char* hwDesc = "No description"
) {
    strcpy(teacherID, tID);
    strcpy(teacherName, tName);
    strcpy(grade, g);
    strcpy(homeWorkID, hwID);
    strcpy(homeworkDescription, hwDesc);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    sprintf(date, "%02d/%02d/%04d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
    sprintf(createTime, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
}

void AssignHomeWorkProcess::recreateHomework(const char* tID, const char* g, const char* hwID) {
    const char* filePath = "../data/AssignCHomeWork.bin";

    // Copy parameters into object data members
    strcpy(teacherID, tID);
    strcpy(grade, g);
    strcpy(homeWorkID, hwID);

    // 1️⃣ Get user input for homework description and note
    H::setcolor(2);H::gotoxy(22,22);cout << ">> ";
    H::gotoxy(25, 22);H::setcolor(7);
    cout << "                                                                                                                                                       ";
    H::setcolor(2);H::gotoxy(25,22);H::inputAll(homeworkDescription, sizeof(homeworkDescription) - 1);  // no manual line breaks
    H::setcolor(6);H::gotoxy(22, 26); cout << ">> ";
    H::gotoxy(25, 26);H::setcolor(7);
    cout << "                                                                                                                                                       ";
    H::setcolor(6);H::gotoxy(25,26);H::inputAll(homeWorkNote, sizeof(homeWorkNote) - 1);  // no manual line breaks

    // 2️⃣ Set current date and time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(createTime, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    sprintf(date, "%02d/%02d/%d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);

    // 3️⃣ Remove old record if it exists
    ifstream inFile(filePath, ios::binary);
    ofstream tempFile("temp.bin", ios::binary);
    AssignHomeWorkProcess tmp;

    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) != 0 ||
            strcmp(tmp.grade, g) != 0 ||
            strcmp(tmp.homeWorkID, hwID) != 0) {
            tempFile.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        }
    }
    inFile.close();

    // 4️⃣ Write the new or updated record
    tempFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    tempFile.close();

    // 5️⃣ Replace original file
    remove(filePath);
    rename("temp.bin", filePath);

    cout << "\nHomework RE/CREATED successfully.\n";
}










#endif