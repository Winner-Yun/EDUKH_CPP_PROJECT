#ifndef __EDU_MASTER_MAIN_PAGE_H__
#define __EDU_MASTER_MAIN_PAGE_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/StudentManagerment.h"
#include "../Header_EDU/ScheduleForClass.h"
using namespace ANTHinsyOOP;

class MainHeadOF_ManageScore{
    private:
        char strname[20], strID[15], strgrade[3], assignBY[20],score_sch[30] , sc_q1[5], sc_q2[5], sc_q3[5], sc_h1[5], sc_h2[5], toalScore[15], avgScore[15], gr[2];
    public:

        void setData(const char* name   = "___",
                 const char* id     = "___",
                 const char* grade  = "___",
                 const char* teacherID = "___",
                 const char* sch    = "0",
                 const char* q1     = "0",
                 const char* q2     = "0",
                 const char* q3     = "0",
                 const char* h1     = "0",
                 const char* h2     = "0",
                 const char* total  = "00.00",
                 const char* avg    = "00.00",  
                 const char* gr     = "F");

        // File process
        void writeSetSchoolscore(const char* teacherID, const char* grade, const char* studentID, const char* newScore);
        void writeSetH1Score(const char* teacherID, const char* grade, const char* studentID, const char* newScore);
        void writeSetH2Score(const char* teacherID, const char* grade, const char* studentID, const char* newScore);
        void updateTotals();
        void searchRecords(const char* teacherID, const char* grade, const string& keyword);
        void readFile(const char* teacherID, const char* grade, int pageIndex, int rowsPerPage);
        void writeDatatoFile(const char* teacherID, const char* grade);
        int countRecords(const char* teacherID, const char* grade);
        void clearScore(const char* teacherID, const char* grade);
};
//Student Format
 struct Student_format {
        char id[6], name[19], gender[7], bdate[15], grade[3], tel[10], sYear[5], email[30], pw[19];
		int No;
        static int lastId;
};


MainHeadOF_ManageScore Mscore,scores[MAX];
int scoreCount = 0;

void MainHeadOF_ManageScore::setData(const char* name,
                                     const char* id,
                                     const char* grade,
                                     const char* teacherID,
                                     const char* sch,
                                     const char* q1,
                                     const char* q2,
                                     const char* q3,
                                     const char* h1,
                                     const char* h2,
                                     const char* total,
                                     const char* avg,
                                     const char* gr) 
{
    strcpy(strname, name);
    strcpy(strID, id);
    strcpy(strgrade, grade);
    strcpy(assignBY, teacherID);   // ✅ new line
    strcpy(score_sch, sch);
    strcpy(sc_q1, q1);
    strcpy(sc_q2, q2);
    strcpy(sc_q3, q3);
    strcpy(sc_h1, h1);
    strcpy(sc_h2, h2);
    strcpy(toalScore, total);
    strcpy(avgScore, avg);
    strcpy(this->gr, gr);
}


void MainHeadOF_ManageScore::updateTotals() {
    int q1 = atoi(sc_q1);
    int q2 = atoi(sc_q2);
    int q3 = atoi(sc_q3);
    int h1 = atoi(sc_h1);
    int h2 = atoi(sc_h2);
    int sch = atoi(score_sch);

    double total = q1 + q2 + q3 + h1 + h2 + sch;
    double avg   = total / 6.0;

    snprintf(toalScore, sizeof(toalScore), "%.2f", total);
    snprintf(avgScore, sizeof(avgScore), "%.2f", avg);

    if (avg >= 90) {
        strcpy(gr, "A");
    } else if (avg >= 80) {
        strcpy(gr, "B");
    } else if (avg >= 70) {
        strcpy(gr, "C");
    } else if (avg >= 60) {
        strcpy(gr, "D");
    } else {
        strcpy(gr, "F");
    }
}

void MainHeadOF_ManageScore::searchRecords(const char* teacherID, const char* grade, const string& keyword) {
    ifstream inFile("../data/ManageScore_data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    vector<MainHeadOF_ManageScore> list;
    MainHeadOF_ManageScore s;

    string lowerKeyword = keyword;
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(MainHeadOF_ManageScore))) {
        // ✅ filter by grade + teacherID
        if (strcmp(s.strgrade, grade) == 0 && strcmp(s.assignBY, teacherID) == 0) {
            string name = s.strname;
            string id   = s.strID;

            string nameLower = name;
            string idLower   = id;
            transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            transform(idLower.begin(), idLower.end(), idLower.begin(), ::tolower);

            if (nameLower.find(lowerKeyword) != string::npos || idLower.find(lowerKeyword) != string::npos) {
                list.push_back(s);
            }
        }
    }
    inFile.close();

    if (list.empty()) {
        H::gotoxy(75, 20);
        cout << "NO RESULTS FOUND FOR '" << keyword << "'";
        return;
    }

    int row = 20;
    int maxResults = min((int)list.size(), 6);

    for (int i = 0; i < maxResults; i++, row += 3) {
        int color = (i % 2 == 0) ? 6 : 3;
        H::setcolor(color);

        H::gotoxy(18, row);
        cout << setw(2) << setfill('0') << i + 1;
        H::gotoxy(26, row);
        cout << list[i].strname;
        H::gotoxy(48, row);
        cout << list[i].strID;
        H::gotoxy(69, row);
        cout << list[i].score_sch;
        H::gotoxy(92, row);
        cout << list[i].sc_h1;
        H::gotoxy(104, row);
        cout << list[i].sc_h2;
        H::gotoxy(116, row);
        cout << list[i].sc_q1;
        H::gotoxy(127, row);
        cout << list[i].sc_q2;
        H::gotoxy(137, row);
        cout << list[i].sc_q3;
        H::gotoxy(149, row);
        cout << list[i].toalScore;
        H::gotoxy(165, row);
        cout << list[i].avgScore;
        H::gotoxy(179, row);
        cout << list[i].gr;
    }
}


void MainHeadOF_ManageScore::clearScore(const char* teacherID, const char* grade) {

    int choice = MessageBoxA(
        NULL,
        "Are you sure you want to clear ALL scores for this teacher and grade?",
        "Confirm Clear",
        MB_YESNO | MB_ICONQUESTION
    );

    if (choice != IDYES) {
        MessageBoxA(NULL, "Clear operation canceled.", "Canceled", MB_OK | MB_ICONINFORMATION);
        return; 
    }

    fstream file("../data/ManageScore_data.bin", ios::in | ios::out | ios::binary);
    if (!file) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK | MB_ICONERROR);
        return;
    }

    bool anyCleared = false;
    MainHeadOF_ManageScore s;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(MainHeadOF_ManageScore))) {

        if (strcmp(s.assignBY, teacherID) == 0 && strcmp(s.strgrade, grade) == 0) {

            s.setData(s.strname, s.strID, s.strgrade, s.assignBY);

            // move pointer back and overwrite
            file.seekp(-static_cast<int>(sizeof(MainHeadOF_ManageScore)), ios::cur);
            file.write(reinterpret_cast<char*>(&s), sizeof(MainHeadOF_ManageScore));
            file.flush();

            anyCleared = true;
        }
    }

    file.close();

    if (anyCleared) {
        MessageBoxA(NULL, "Scores cleared successfully.", "Success", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBoxA(NULL, "No matching records found for this teacher and grade.", "Info", MB_OK | MB_ICONINFORMATION);
    }
}



void MainHeadOF_ManageScore::writeSetSchoolscore(const char* teacherID, const char* grade, const char* studentID, const char* newScore) {
    int score = atoi(newScore);
    char normalized[8];
    snprintf(normalized, sizeof(normalized), "%d", score);

    fstream file("../data/ManageScore_data.bin", ios::in | ios::out | ios::binary);
    if (!file) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    bool found = false;
    MainHeadOF_ManageScore rec;

    while (file.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        // ✅ Match student ID + teacher ID + grade
        if (strcmp(rec.strID, studentID) == 0 &&
            strcmp(rec.assignBY, teacherID) == 0 &&
            strcmp(rec.strgrade, grade) == 0) 
        {
            strncpy(rec.score_sch, normalized, sizeof(rec.score_sch) - 1);
            rec.score_sch[sizeof(rec.score_sch) - 1] = '\0';

            rec.updateTotals();  // ✅ pass teacher + grade
            file.clear();
            file.seekp(-static_cast<streamoff>(sizeof(rec)), ios::cur);
            file.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            file.flush();
            found = true;
            break;
        }
    }

    if (!found) {
        MessageBoxA(NULL, "Error", "Student ID not found for this teacher and grade", MB_OK);
    }

    file.close();
}



void MainHeadOF_ManageScore::writeSetH1Score(const char* teacherID, const char* grade, const char* studentID, const char* newScore) {
    int score = atoi(newScore);

    char normalized[8];
    snprintf(normalized, sizeof(normalized), "%d", score);

    fstream file("../data/ManageScore_data.bin", ios::in | ios::out | ios::binary);
    if (!file) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    bool found = false;
    MainHeadOF_ManageScore rec;

    while (file.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        // ✅ check Student ID + Teacher ID + Grade
        if (strcmp(rec.strID, studentID) == 0 &&
            strcmp(rec.assignBY, teacherID) == 0 &&
            strcmp(rec.strgrade, grade) == 0) 
        {
            strncpy(rec.sc_h1, normalized, sizeof(rec.sc_h1) - 1);
            rec.sc_h1[sizeof(rec.sc_h1) - 1] = '\0';

            rec.updateTotals();  // ✅ recalc totals with teacher+grade
            file.clear();
            file.seekp(-static_cast<streamoff>(sizeof(rec)), ios::cur);
            file.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            file.flush();
            found = true;
            break;
        }
    }

    if (!found) {
        MessageBoxA(NULL, "Error", "Student ID not found for this teacher and grade", MB_OK);
    }

    file.close();
}


void MainHeadOF_ManageScore::writeSetH2Score(const char* teacherID, const char* grade, const char* studentID, const char* newScore) {
    int score = atoi(newScore);

    // Normalize score into string
    char normalized[8];
    snprintf(normalized, sizeof(normalized), "%d", score);

    fstream file("../data/ManageScore_data.bin", ios::in | ios::out | ios::binary);
    if (!file) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    bool found = false;
    MainHeadOF_ManageScore rec;

    while (file.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        // Check teacher, grade, and student
        if (strcmp(rec.assignBY, teacherID) == 0 &&
            strcmp(rec.strgrade, grade) == 0 &&
            strcmp(rec.strID, studentID) == 0) {

            // Update H2 score safely
            strncpy(rec.sc_h2, normalized, sizeof(rec.sc_h2) - 1);
            rec.sc_h2[sizeof(rec.sc_h2) - 1] = '\0';

            // Recalculate totals
            rec.updateTotals();

            // Move back and overwrite record
            file.clear();
            file.seekp(-static_cast<streamoff>(sizeof(rec)), ios::cur);
            file.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            file.flush();

            found = true;
            break;
        }
    }

    if (!found) {
        MessageBoxA(NULL, "Error", "Matching record not found (Teacher, Grade, or StudentID mismatch)", MB_OK | MB_ICONERROR);
    }

    file.close();
}

 
void MainHeadOF_ManageScore::writeDatatoFile(const char* teacherID, const char* grade) {

    // 1. Load all students from this grade
    vector<Student_format> students;
    {
        ifstream inFile("../data/Student_Data.bin", ios::binary);
        if (!inFile) {
            MessageBoxA(NULL, "Error", "Student_Data.bin not found", MB_OK);
            return;
        }

        Student_format s;
        while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student_format))) {
            if (strcmp(s.grade, grade) == 0) {
                students.push_back(s);
            }
        }
        inFile.close();
    }

    if (students.empty()) {
        MessageBoxA(NULL, "No matching students found", "Info", MB_OK);
        return;
    }

    // 2. Load existing ManageScore_data.bin records
    vector<MainHeadOF_ManageScore> scoresExisting;
    {
        ifstream inFile("../data/ManageScore_data.bin", ios::binary);
        if (inFile) {
            MainHeadOF_ManageScore temp;
            while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(MainHeadOF_ManageScore))) {
                // Only load records for this teacher + grade
                if (strcmp(temp.assignBY, teacherID) == 0 &&
                    strcmp(temp.strgrade, grade) == 0) {
                    scoresExisting.push_back(temp);
                }
            }
            inFile.close();
        }
    }

    // 3. Create a new synced list (for this teacher + grade)
    vector<MainHeadOF_ManageScore> newScores;
    for (auto &s : students) {
        bool found = false;
        for (auto &old : scoresExisting) {
            if (strcmp(old.strID, s.id) == 0) {
                newScores.push_back(old); 
                found = true;
                break;
            }
        }

        if (!found) {
            MainHeadOF_ManageScore fresh;
            fresh.setData(s.name, s.id, s.grade,teacherID); // add teacher ID here
            newScores.push_back(fresh);
        }
    }

    // 4. Merge back into full file (preserve other teachers/grades)
    {
        vector<MainHeadOF_ManageScore> allRecords;
        ifstream inFile("../data/ManageScore_data.bin", ios::binary);
        if (inFile) {
            MainHeadOF_ManageScore temp;
            while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(MainHeadOF_ManageScore))) {
                // keep other teacher/grade combos
                if (!(strcmp(temp.assignBY, teacherID) == 0 &&
                      strcmp(temp.strgrade, grade) == 0)) {
                    allRecords.push_back(temp);
                }
            }
            inFile.close();
        }

        // then add the updated grade data for this teacher
        allRecords.insert(allRecords.end(), newScores.begin(), newScores.end());

        // overwrite file with merged data
        ofstream outFile("../data/ManageScore_data.bin", ios::binary | ios::trunc);
        if (!outFile) {
            MessageBoxA(NULL, "Error", "Cannot create ManageScore_data", MB_OK);
            return;
        }
        outFile.write(reinterpret_cast<char*>(allRecords.data()), sizeof(MainHeadOF_ManageScore) * allRecords.size());
        outFile.close();
    }
}


void MainHeadOF_ManageScore::readFile(const char* teacherID, const char* grade, int pageIndex, int rowsPerPage) {
    ifstream inFile("../data/ManageScore_data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    vector<MainHeadOF_ManageScore> list;
    MainHeadOF_ManageScore s;

    // ✅ Load only records for this teacher and grade
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(MainHeadOF_ManageScore))) {
        if (strcmp(s.strgrade, grade) == 0 && strcmp(s.assignBY, teacherID) == 0) {
            list.push_back(s);
        }
    }
    inFile.close();

    int totalStudents = list.size();
    if (totalStudents == 0) {
        H::gotoxy(75, 20);
        cout << "No students to show.";
        return;
    }

    int totalPages = (totalStudents + rowsPerPage - 1) / rowsPerPage;
    if (totalPages == 0) totalPages = 1;

    if (pageIndex < 0) pageIndex = 0;
    if (pageIndex >= totalPages) pageIndex = totalPages - 1;

    int start = pageIndex * rowsPerPage;
    int end   = min(start + rowsPerPage, totalStudents);
    int row   = 20;

    for (int i = start; i < end; i++, row += 3) {
        int color = (i % 2 == 0) ? 6 : 3;
        H::setcolor(color);

        H::gotoxy(18, row);
        cout << setw(2) << setfill('0') << i + 1;
        H::gotoxy(26, row);
        cout << list[i].strname;
        H::gotoxy(48, row);
        cout << list[i].strID;
        H::gotoxy(75, row);
        cout << " " << list[i].score_sch << " ";
        H::gotoxy(91, row);
        cout << " " << list[i].sc_h1  << " ";
        H::gotoxy(103, row);
        cout << " " << list[i].sc_h2  << " ";
        H::gotoxy(116, row);
        cout << list[i].sc_q1;
        H::gotoxy(127, row);
        cout << list[i].sc_q2;
        H::gotoxy(137, row);
        cout << list[i].sc_q3;
        H::gotoxy(149, row);
        cout << list[i].toalScore;
        H::gotoxy(165, row);
        cout << list[i].avgScore;
        H::gotoxy(179, row);
        cout << list[i].gr;
    }

    // Page info
    H::setcolor(6);
    H::gotoxy(92, 39);
    cout << "PAGE: " << pageIndex + 1 << " / " << totalPages;
}


int MainHeadOF_ManageScore::countRecords(const char* teacherID, const char* grade) {
    ifstream inFile("../data/ManageScore_data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return 0;
    }

    int count = 0;
    MainHeadOF_ManageScore temp;

    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(MainHeadOF_ManageScore))) {
        if (strcmp(temp.strgrade, grade) == 0 && strcmp(temp.assignBY, teacherID) == 0) {
            count++;
        }
    }

    inFile.close();
    return count;
}


#endif