#ifndef __ASSIGNHOMEWORK_PROCESS_H__
#define __ASSIGNHOMEWORK_PROCESS_H__
#include "../Header_School/ANTHinsyOOP"

using namespace ANTHinsyOOP;
class AssignHomeWorkProcess{
private:
    char teacherID[10];
    char teacherName[20];
    char grade[10];
    char homeWorkID[2];
    char homeworkDescription[123];
    char homeWorkNote[123];
    char deadLineDate[20];
    char date[20];        
    char createTime[20]; 
public:

    static void AssignHomeWorkMainDesign(const char* grade);
    const char* getnameFromFile(const char* id);
    const char* getDescriptionFromFile(const char* teacherID,const char* homeWorkID,const char* grade);
    const char* gethomeWorkNote(const char* teacherID,const char* homeWorkID,const char* grade);
    const char* getDateFromFile(const char* tID, const char* hwID, const char* g);
    const char* getDeadlineFromFile(const char* tID, const char* g, const char* hwID);

    void recreateHomework(const char* tID, const char* g, const char* hwID);

    void setAllData(const char* tID, const char* tName, const char* g,
                                       const char* hwID, const char* hwDesc,
                                       const char* hwNote, const char* dlDate);

    void clearHomework(const char* tID, const char* g, const char* hwID);
    void publishHomework(const char* tID, const char* g, const char* hwID);
    void unpublishHomework(const char* tID, const char* g, const char* hwID);

    bool checkExpire(const char* tID, const char* g, const char* hwID);
    bool canPublish(const char* tID, const char* g, const char* hwID);
    bool isPublished(const char* tID, const char* g, const char* hwID);

};
AssignHomeWorkProcess assH;
struct Teacher_form_usage{ 
    char teacherId[20], teacherName[20],gender[20],subject[20],phoneNumber[15],dateOfBirth[20],email[40],pw[20],academyYear[10];
    };
const char* AssignHomeWorkProcess::getnameFromFile(const char* id) {
    static char buffer[100];

    ifstream file("../data/Teacher_Data.bin", ios::binary);
    if (!file) {
        cout << "Failed to open file.\n";
        return "";
    }

    Teacher_form_usage t;
    while (file.read(reinterpret_cast<char*>(&t), sizeof(Teacher_form_usage))) {
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

const char* AssignHomeWorkProcess::getDateFromFile(const char* tID, const char* hwID, const char* g) {
    static char buffer[20];   // to return safely
    const char* filePath = "../data/AssignCHomeWork.bin";

    ifstream inFile(filePath, ios::binary);
    if (!inFile) {
        cout << "Failed to open file.\n";
        return "";
    }

    AssignHomeWorkProcess tmp;
    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) == 0 &&
            strcmp(tmp.grade, g) == 0 &&
            strcmp(tmp.homeWorkID, hwID) == 0) {
            strcpy(buffer, tmp.date);
            inFile.close();
            return buffer;
        }
    }

    inFile.close();
    return "NOT FOUND";
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

const char* AssignHomeWorkProcess::getDeadlineFromFile(const char* tID, const char* hwID, const char* g) {
    static char buffer[20];
    const char* filePath = "../data/AssignCHomeWork.bin";

    ifstream file(filePath, ios::binary);
    if (!file) {
        return "";
    }

    AssignHomeWorkProcess tmp;
    while (file.read(reinterpret_cast<char*>(&tmp), sizeof(AssignHomeWorkProcess))) {
        if (strcmp(tmp.teacherID, tID) == 0 &&
            strcmp(tmp.grade, g) == 0 &&
            strcmp(tmp.homeWorkID, hwID) == 0) {
            strcpy(buffer, tmp.deadLineDate);
            return buffer;
        }
    }

    return "None";
}


void AssignHomeWorkProcess::setAllData(const char* tID, const char* tName, const char* g,
                                       const char* hwID, const char* hwDesc,
                                       const char* hwNote, const char* dlDate ) {
    strcpy(teacherID, tID);
    strcpy(teacherName, tName);
    strcpy(grade, g);
    strcpy(homeWorkID, hwID);
    strcpy(homeworkDescription, hwDesc);
    strcpy(homeWorkNote, hwNote);
    strcpy(deadLineDate, dlDate);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(createTime, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    sprintf(date, "%02d/%02d/%d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
}


void AssignHomeWorkProcess::recreateHomework(const char* tID, const char* g, const char* hwID) {
    const char* filePath = "../data/AssignCHomeWork.bin";
    const char* tempFilePath = "../data/temp.bin";

    // Lambda to clean temp file
    auto cleanupTemp = [&]() {
        if (ifstream(tempFilePath)) remove(tempFilePath);
    };

    strcpy(teacherID, tID);
    strcpy(grade, g);
    strcpy(homeWorkID, hwID);

    // Clear previous UI fields
    H::setcolor(7); H::gotoxy(25, 22); cout << string(122, ' ');
    H::setcolor(7); H::gotoxy(25, 26); cout << string(122, ' ');
    H::setcolor(7); H::gotoxy(155, 22); cout << string(23, ' ');

    // Input description
    H::setcolor(7); H::gotoxy(22,22); cout << ">>> ";
    H::gotoxy(26,22); H::setcolor(2);
    H::inputAll(homeworkDescription, sizeof(homeworkDescription) - 1);

    // Input note
    H::setcolor(7); H::gotoxy(22,26); cout << ">>> ";
    H::gotoxy(26,26); H::setcolor(6);
    H::inputAll(homeWorkNote, sizeof(homeWorkNote) - 1);

    // Input valid deadline
    bool validDeadline = false;
    while (!validDeadline) {
        H::setcolor(7); H::gotoxy(152,22); cout << string(24, ' ');
        H::setcolor(7); H::gotoxy(152,22); cout << ">>> ";
        H::setcolor(1); H::gotoxy(156,22);
        H::inputDate(deadLineDate, true);

        int d, m, y;
        if (sscanf(deadLineDate, "%d/%d/%d", &d, &m, &y) == 3) {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            tm deadline = {};
            deadline.tm_mday = d;
            deadline.tm_mon = m - 1;
            deadline.tm_year = y - 1900;
            time_t deadlineTime = mktime(&deadline);

            tm today = {};
            today.tm_mday = ltm->tm_mday;
            today.tm_mon = ltm->tm_mon;
            today.tm_year = ltm->tm_year;
            time_t todayTime = mktime(&today);

            if (deadlineTime > todayTime) {
                validDeadline = true;
            }
        }

        if (!validDeadline) {
            H::setcolor(12);
            H::gotoxy(151,23); cout << "MUST BE TOMORROW OR LATER.";
            H::delay(2000);
            H::gotoxy(151,23); cout << string(26, ' ');
        }
    }

    // Record creation time and date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(createTime, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    sprintf(date, "%02d/%02d/%d", ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);

    // Copy all other homework entries to temp
    ifstream inFile(filePath, ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Cannot open AssignCHomeWork.bin!", "Error", MB_ICONERROR);
        cleanupTemp();
        return;
    }

    ofstream tempFile(tempFilePath, ios::binary);
    if (!tempFile) {
        MessageBoxA(NULL, "Cannot create temp file!", "Error", MB_ICONERROR);
        inFile.close();
        cleanupTemp();
        return;
    }

    AssignHomeWorkProcess tmp;
    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) != 0 ||
            strcmp(tmp.grade, g) != 0 ||
            strcmp(tmp.homeWorkID, hwID) != 0) {
            tempFile.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        }
    }

    // Write updated homework
    tempFile.write(reinterpret_cast<char*>(this), sizeof(*this));

    inFile.close();
    tempFile.close();

    // Replace original file
    remove(filePath);
    if (rename(tempFilePath, filePath) != 0) {
        MessageBoxA(NULL, "Error updating homework file!", "Error", MB_ICONERROR);
        cleanupTemp();
    }
}


void AssignHomeWorkProcess::clearHomework(const char* tID, const char* g, const char* hwID) {
    const char* filePath = "../data/AssignCHomeWork.bin";
    const char* tempFilePath = "../data/temp.bin";

    // Lambda to clean temp file if needed
    auto cleanupTemp = [&]() {
        if (ifstream(tempFilePath)) remove(tempFilePath);
    };

    // Reset the homework data but keep IDs
    setAllData(tID, assH.getnameFromFile(tID), g, hwID, "None", "None", "None");

    ifstream inFile(filePath, ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Cannot open AssignCHomeWork.bin!", "Error", MB_ICONERROR);
        cleanupTemp();
        return;
    }

    ofstream tempFile(tempFilePath, ios::binary);
    if (!tempFile) {
        MessageBoxA(NULL, "Cannot create temp file!", "Error", MB_ICONERROR);
        inFile.close();
        cleanupTemp();
        return;
    }

    AssignHomeWorkProcess tmp;
    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) != 0 ||
            strcmp(tmp.grade, g) != 0 ||
            strcmp(tmp.homeWorkID, hwID) != 0) {
            tempFile.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        }
    }

    // Write the cleared homework record
    tempFile.write(reinterpret_cast<char*>(this), sizeof(*this));

    inFile.close();
    tempFile.close();

    // Replace original file
    remove(filePath);
    if (rename(tempFilePath, filePath) != 0) {
        MessageBoxA(NULL, "Error updating homework file!", "Error", MB_ICONERROR);
        cleanupTemp();
    }
}



bool AssignHomeWorkProcess::isPublished(const char* tID, const char* g, const char* hwID) {
    const char* filePath = "../data/AssignCHomeWorkPUBLISH.bin";
    ifstream inFile(filePath, ios::binary);
    AssignHomeWorkProcess tmp;
    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) == 0 &&
            strcmp(tmp.grade, g) == 0 &&
            strcmp(tmp.homeWorkID, hwID) == 0) {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    return false;
}

bool AssignHomeWorkProcess::checkExpire(const char* tID, const char* g, const char* hwID) {
    ifstream inFile("../data/AssignCHomeWork.bin", ios::binary);
    if (!inFile) return false;

    AssignHomeWorkProcess tmp;
    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) == 0 &&
            strcmp(tmp.grade, g) == 0 &&
            strcmp(tmp.homeWorkID, hwID) == 0) {

            // Check if deadline is set
            if (strcmp(tmp.deadLineDate, "None") == 0) {
                inFile.close();
                return false; // No deadline, not expired
            }

            // Parse deadline
            int d, m, y;
            sscanf(tmp.deadLineDate, "%d/%d/%d", &d, &m, &y);

            // Get current date
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int curDay = ltm->tm_mday;
            int curMonth = ltm->tm_mon + 1;
            int curYear = 1900 + ltm->tm_year;

            // If deadline is today or earlier, it is expired
            if (y < curYear || 
               (y == curYear && m < curMonth) ||
               (y == curYear && m == curMonth && d <= curDay)) {
                inFile.close();
                return true;
            } else {
                inFile.close();
                return false;
            }
        }
    }

    inFile.close();
    return false;
}


void AssignHomeWorkProcess::publishHomework(const char* tID, const char* g, const char* hwID) {
    const char* filePath = "../data/AssignCHomeWorkPUBLISH.bin";
    const char* tempFilePath = "../data/temp.bin"; // temp in data folder

    AssignHomeWorkProcess tmp;
    bool found = false;
    bool alreadyPublished = false;

    // Lambda to clean temp file
    auto cleanupTemp = [&]() {
        if (ifstream(tempFilePath)) remove(tempFilePath);
    };

    // Step 1: Check if already published and handle unpublish
    ifstream pubFile(filePath, ios::binary);
    ofstream tempPub(tempFilePath, ios::binary);

    while (pubFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) == 0 &&
            strcmp(tmp.grade, g) == 0 &&
            strcmp(tmp.homeWorkID, hwID) == 0) {
            alreadyPublished = true; 
            continue; // skip writing to temp, effectively deleting entry
        }
        tempPub.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
    }

    pubFile.close();
    tempPub.close();

    if (alreadyPublished) { 
        remove(filePath);
        rename(tempFilePath, filePath);
        MessageBoxA(NULL, "Homework unpublished successfully!", "Unpublish", MB_ICONINFORMATION);
        return; // done, temp already renamed, no cleanup needed
    }

    // Step 2: Check fields and deadline for publishing
    ifstream inFile("../data/AssignCHomeWork.bin", ios::binary);
    bool canPublishFlag = false;

    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) == 0 &&
            strcmp(tmp.grade, g) == 0 &&
            strcmp(tmp.homeWorkID, hwID) == 0) {

            found = true;

            // Validate required fields
            if (strcmp(tmp.homeworkDescription, "None") == 0 ||
                strcmp(tmp.homeWorkNote, "None") == 0 ||
                strcmp(tmp.deadLineDate, "None") == 0) {
                MessageBoxA(NULL, "Cannot publish: Description, Note, or Deadline is empty!", "Publish Error", MB_ICONERROR);
                inFile.close();
                cleanupTemp();
                return;
            }

            // Check deadline
            if (!tmp.canPublish(tID, g, hwID)) {
                MessageBoxA(NULL, "Cannot publish: Deadline expired!", "Publish Error", MB_ICONERROR);
                inFile.close();
                cleanupTemp();
                return;
            }

            // Publish homework
            canPublishFlag = true;
            ofstream outFile(filePath, ios::binary | ios::app);
            outFile.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
            outFile.close();

            MessageBoxA(NULL, "Homework published successfully!", "Publish", MB_ICONINFORMATION);
            break;
        }
    }

    if (!found) {
        MessageBoxA(NULL, "Cannot publish: Description, Note, or Deadline is empty!", "Publish Error", MB_ICONERROR);
    }

    inFile.close();

    // Cleanup temp file if it still exists
    cleanupTemp();
}




// Unpublish homework
void AssignHomeWorkProcess::unpublishHomework(const char* tID, const char* g, const char* hwID) {
    const char* filePath = "../data/AssignCHomeWorkPUBLISH.bin";
    const char* tempPath = "../data/temp_unpublish.bin"; // temporary file

    ifstream inFile(filePath, ios::binary);
    ofstream tempFile(tempPath, ios::binary);
    AssignHomeWorkProcess tmp;

    while (inFile.read(reinterpret_cast<char*>(&tmp), sizeof(tmp))) {
        if (strcmp(tmp.teacherID, tID) != 0 ||
            strcmp(tmp.grade, g) != 0 ||
            strcmp(tmp.homeWorkID, hwID) != 0) {
            tempFile.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        }
    }

    inFile.close();
    tempFile.close();

    remove(filePath);           // delete original
    rename(tempPath, filePath); // replace with updated
}



bool AssignHomeWorkProcess::canPublish(const char* tID, const char* g, const char* hwID) {
    
    if (strcmp(teacherID, tID) != 0 ||
        strcmp(grade, g) != 0 ||
        strcmp(homeWorkID, hwID) != 0) {
        return false;
    }

    if (strcmp(deadLineDate, "None") == 0) return false;

    int d, m, y;
    sscanf(deadLineDate, "%d/%d/%d", &d, &m, &y);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int curDay = ltm->tm_mday;
    int curMonth = ltm->tm_mon + 1;
    int curYear = 1900 + ltm->tm_year;

    if (y < curYear) return false;
    if (y == curYear && m < curMonth) return false;
    if (y == curYear && m == curMonth && d <= curDay) return false;

    return true;
}




#endif