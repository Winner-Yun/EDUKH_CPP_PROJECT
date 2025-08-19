#ifndef __ASSIGNHOMEWORK_PROCESS_H__
#define __ASSIGNHOMEWORK_PROCESS_H__
#include "../Header_School/ANTHinsyOOP"
#include "Teach_MainMenu.h"
using namespace ANTHinsyOOP;
class AssignHomeWorkProcess{
private:
    char teacherID[20];
    char teacherName[100];
    char grade[10];
    char homeWorkID[2];
    char homeworkDescription[130];
    char homeWorkNote[130];
    char date[20];        
    char createTime[20]; 
public:
    static void AssignHomeWorkMainDesign(const char* grade);
    const char* getnameFromFile(const char* id);
    const char* getDescriptionFromFile(const char* teacherID,const char* homeWorkID,const char* grade);
    const char* gethomeWorkNote(const char* teacherID,const char* homeWorkID,const char* grade);

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








#endif