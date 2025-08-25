#ifndef __MANAGE_SCORE_HEADER_EDU__
#define __MANAGE_SCORE_HEADER_EDU__

#include "../Header_School/ANTHinsyOOP"
#include "ScheduleForClass.h"
#include "CustomHeader.h"

using namespace ANTHinsyOOP;
class MainManageScore{
    private:
        int pageIndex = 0;  
        int totalPages = 1;  
        char studentID[15];
        char studentName[20];
        char grade[3];
        char AvgScore[20];
        char rank[2];
    public:
        static void ManageScoreProcess();
        static void MenuGradeChoice();
        static void Header();
        static void Menu_Body();
        static void Footer();
        static void LoadingHeader(int id);
        static void ManageScoreDesign(const char* grade);
        static void HeaderMenuSelect(const char* grade);
        static void WriteSummaryToFile(const MainManageScore& data);
        static void ClearSummaryFile();
        bool IsPublished(const char* grade);
        void ReadAVGScore(const char* grade);
        void MainControlScore(const char* grade);
        // Getter ================
        const char* getStudentID() const { return studentID; }
        const char* getAvgScore() const { return AvgScore; }
        const char* getRank() const { return rank; }
};
struct ManageScore {
    char strname[20], strID[15], strgrade[3], assignBY[20],atSubject[20],score_sch[30] , sc_q1[5], sc_q2[5], sc_q3[5], sc_h1[5], sc_h2[5], toalScore[15], avgScore[15], gr[2];  
};

// *********************************************************** BODY OF THE PROGRAM *****************************************************************

vector<string> subjects;
MainManageScore manageScore, manageScores[100];
int manageScoreCount = 0;

void MainManageScore::ManageScoreProcess(){
    MenuGradeChoice();
}

void MainManageScore::MenuGradeChoice(){
     int option;
    int choice = 1;
    do{

        Header();
        Menu_Body();
        Footer();

        

        do{
            H::drawBoxDoubleLineWithBG(79,11,40,1,111);
            H::drawBoxDoubleLineWithBG(79,21,40,1,111);
            H::drawBoxDoubleLineWithBG(79,31,40,1,111);

            H::setcolor(6);
            H::gotoxy(80, 13);cout << "----------[   GRADE - 10   ]----------" << endl;
            H::gotoxy(80, 12);cout << "                                      " << endl;
            H::gotoxy(80, 23);cout << "----------[   GRADE - 11   ]----------" << endl;
            H::gotoxy(80, 22);cout << "                                      " << endl;
            H::gotoxy(80, 33);cout << "----------[   GRADE - 12   ]----------" << endl;
            H::gotoxy(80, 32);cout << "                                      " << endl;

            switch (choice) {
                case 1: {
                    H::drawBoxDoubleLineWithBG(79,11,40,1,2);
                    H::setcolor(7);
                    H::gotoxy(80, 13);cout << "-[            GRADE - 10            ]-" << endl;
                    H::gotoxy(80, 12);cout << "                                      " << endl;
                    break;
                }
                case 2: {
                    H::drawBoxDoubleLineWithBG(79,21,40,1,2);
                    H::setcolor(7);
                    H::gotoxy(80, 23);cout << "-[            GRADE - 11            ]-" << endl;
                    H::gotoxy(80, 22);cout << "                                      " << endl;
                    break;
                }
                case 3: {
                    H::drawBoxDoubleLineWithBG(79,31,40,1,2);
                    H::setcolor(7);
                    H::gotoxy(80, 33);cout << "-[            GRADE - 12            ]-" << endl;
                    H::gotoxy(80, 32);cout << "                                      " << endl;
                    break;
                }

            }

            option = getch();

            choice = EdumasterCustom::ArrowKeyConTrol(3,1,choice,option);    // usage here :)
            
        }while(option != 27 && option != 13);

        if(option==27){
            H::cls();
            LoadingHeader(1);
            EdumasterCustom::LoadingPage(30,30,135,5);
            system("cls");
        }

        if (option == 13) {
                switch (choice) {
                case 1:{
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    manageScore.MainControlScore("10");
                    H::cls();
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }

                case 2:{
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();
                    manageScore.MainControlScore("11");
                    H::cls();
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }

                case 3:{
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    H::cls();
                    manageScore.MainControlScore("12");
                    H::cls();
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30,30,135,5);
                    system("cls");
                    break;
                }


            }
        }
    }while(option != 27);
}

void MainManageScore::WriteSummaryToFile(const MainManageScore& data) {
    ofstream outFile("../data/ManageScoreBYAdmin.bin", ios::binary | ios::app);
    if (!outFile) {
        MessageBoxA(NULL, "Error", "Cannot open file", MB_OK);
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&data), sizeof(MainManageScore));
    outFile.close();
}

void MainManageScore::ClearSummaryFile() {
    ofstream outFile("../data/ManageScoreBYAdmin.bin", ios::binary | ios::trunc);
    if (!outFile) {
        MessageBoxA(NULL, "Error", "Cannot clear file", MB_OK);
        return;
    }
    outFile.close();
}


void MainManageScore::MainControlScore(const char* grade) {
    bool work = true;
    pageIndex = 0;          // reset page

    ManageScoreDesign(grade);

    while (work) {
        H::clearBox(4, 20, 190, 16, 7);
        ReadAVGScore(grade);
        if(!IsPublished(grade)) {
            H::setcolor(4);
            H::drawBoxSingleLineWithBG(2, 39, 20, 2, 4);
            H::gotoxy(5, 40); cout << " UNPUBLISHED ";
            H::setcolor(2);
        } else {
            H::setcolor(2);
            H::drawBoxSingleLineWithBG(2, 39, 20, 2, 6);
            H::gotoxy(7, 40); cout << " PUBLISHED ";
            H::setcolor(4);
        }
        H::VLine(193, 19, 16, 2, 179);
        H::VLine(179, 19, 16, 6, 179);

        int key = getch();

        if (key == 27) { // ESC
            work = false;
            H::cls();
        }
        else if (key == 75) { // LEFT arrow
            if (pageIndex > 0) pageIndex--;
        }
        else if (key == 77) { // RIGHT arrow
            if (pageIndex < totalPages - 1) pageIndex++;
        }
        else if (key == 'P' || key == 'p') {
            if (!IsPublished(grade)) {
                int result = MessageBoxA(
                    NULL,
                    "Do you really want to publish the scores?",
                    "Confirm Publish",
                    MB_YESNO | MB_ICONQUESTION
                );

                if (result == IDYES) {
                    for (int i = 0; i < manageScoreCount; i++) {
                        WriteSummaryToFile(manageScores[i]);
                    }
                    MessageBoxA(NULL, "Scores have been published.", "Success", MB_OK | MB_ICONINFORMATION);
                }
            } else {
                int result = MessageBoxA(
                    NULL,
                    "Scores are already published. Do you want to unpublish them?",
                    "Confirm Unpublish",
                    MB_YESNO | MB_ICONQUESTION
                );

                if (result == IDYES) {
                    ClearSummaryFile();
                    MessageBoxA(NULL, "Scores have been unpublish.", "Unpublished", MB_OK | MB_ICONINFORMATION);
                }
            }
    }

    }
}


void MainManageScore::ManageScoreDesign(const char* grade) {
    H::setcolor(0);
    H::cls();
    H::HLine(1,0,198,1,239);
    HeaderMenuSelect(grade);

    H::drawBoxSingleLineWithBG(157,2,41,3,153);
    H::setcolor(31);
    H::gotoxy(158, 3); cout << "  USER NAME       : " << "ADMIN              ";
    H::gotoxy(158, 4); cout << "  SYSTEM NAME     : " << "EMIS               ";
    H::gotoxy(158, 5); cout << "  VERSION         : " << "1.0.0              ";
    H::gotoxy(158, 6); cout << "  GRADE SELECTED  : " << grade << "                 ";

    H::drawBoxSingleLine(2,2,40,3,4);
    H::gotoxy(10,4); cout<<"PRESS ESC KEY TO BACK !!";

    H::HLine(10,8,180,7,205);
    H::setcolor(6); H::gotoxy(12,9);  cout << "GRADE SCALE: A: 90-100, B: 80-89, C: 70-79, D: 60-69, F: 0-59";
    H::setcolor(6); H::gotoxy(12,11); cout << "NOTE: GRADES ARE BASED ON THE AVERAGE SCORE (AVG).";

    H::setcolor(6); H::gotoxy(124,9); cout << " [ TIP ] ~ LEFT AND RIGHT ARROWS KEYS ~ TO SHOW PREVIOUS OR NEXT.";
    H::setcolor(4); H::gotoxy(124,11); cout << " CLICK ~ P ~ TO PUBLISH/UNPUBLISH THE AVG SCORE AND GRADE TO STUDENT.";

     // Load subjects for the selected grade

    H::drawBoxSingleLine(1,13,198,3,7);
    H::gotoxy(3,15); H::setcolor(1); cout<<"NO";
    H::gotoxy(11,15); H::setcolor(2); cout<<"NAME";
    H::gotoxy(34,15); H::setcolor(3); cout<<"ID";

    ifstream inFile("../data/ManageScore_data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    ManageScore record;

    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(ManageScore))) {
    if (strcmp(record.strgrade, grade) == 0) {
        string sub = record.atSubject;

        // convert to uppercase
        transform(sub.begin(), sub.end(), sub.begin(), ::toupper);

        // skip table header columns
        if (sub == "NO" || sub == "NAME" || sub == "ID" || sub.empty()) {
            continue;
        }

        // avoid duplicates
        if (find(subjects.begin(), subjects.end(), sub) == subjects.end()) {
            subjects.push_back(sub);
        }
    }
}
inFile.close();

    inFile.close();

    // Display subjects
    int startX = 45;   
    int y = 15;        
    int gapX = 10;     
    int colorIndex = 7; 

    for (size_t i = 0; i < subjects.size(); i++) {
        H::setcolor(colorIndex);
        H::gotoxy(startX + i * gapX, y);
        cout << subjects[i];
    }

    if (subjects.empty()) {
        H::setcolor(4);
        H::gotoxy(12, 20);
        cout << "No subjects found for the selected grade.";
    }

    H::gotoxy(178,15); H::setcolor(6); cout<<"|  TOTAL AVG";
    H::gotoxy(192,15); H::setcolor(2); cout<<"|  GR";

    H::drawBoxSingleLine(1,18,198,18,3);
}

void MainManageScore::ReadAVGScore(const char* grade) {
    ifstream inFile("../data/ManageScore_data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "ManageScore_data.bin not found", MB_OK);
        return;
    }

    struct StudentData {
        string name;
        string id;
        vector<pair<string, double>> subjectScores;
    };

    map<string, StudentData> students;
    ManageScore record;

    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(ManageScore))) {
        if (strcmp(record.strgrade, grade) == 0) {
            string id   = record.strID;
            string name = record.strname;
            string sub  = record.atSubject;
            double avg  = atof(record.avgScore);

            if (students.find(id) == students.end()) {
                students[id] = {name, id, {}};
            }
            students[id].subjectScores.push_back({sub, avg});
        }
    }
    inFile.close();

    vector<StudentData> list;
    for (auto &it : students) list.push_back(it.second);

    int rowsPerPage = 6;
    int totalStudents = list.size();
    totalPages = (totalStudents + rowsPerPage - 1) / rowsPerPage;
    if (totalPages == 0) totalPages = 1;

    int start = pageIndex * rowsPerPage;
    int end   = min(start + rowsPerPage, totalStudents);

    int row = 20;
    for (int i = start; i < end; i++, row += 3) {
        StudentData &stu = list[i];

        // NO
        H::setcolor(1);
        H::gotoxy(3, row);
        cout << setw(2) << setfill('0') << i + 1;

        // NAME
        H::setcolor(2);
        H::gotoxy(11, row);
        cout << stu.name;

        // ID
        H::setcolor(3);
        H::gotoxy(34, row);
        cout << stu.id;

        // SUBJECTS
        int startX = 45;
        int gapX   = 10;
        double total = 0;
        int count = 0;

        for (size_t j = 0; j < subjects.size(); j++) {
            H::setcolor(7);
            H::gotoxy(startX + j * gapX, row);

            bool found = false;
            for (auto &ps : stu.subjectScores) {
                if (strcasecmp(ps.first.c_str(), subjects[j].c_str()) == 0) {
                    cout << fixed << setprecision(2) << ps.second;
                    total += ps.second;
                    count++;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "-";
        }

        // TOTAL AVG
        double totalAvg = (count > 0 ? total / count : 0);

        // Calculate letter grade
        char grd;
        if (totalAvg >= 90) grd = 'A';
        else if (totalAvg >= 80) grd = 'B';
        else if (totalAvg >= 70) grd = 'C';
        else if (totalAvg >= 60) grd = 'D';
        else grd = 'F';

        // Display numeric average
        H::setcolor(6);
        H::gotoxy(183, row);
        cout << fixed << setprecision(2) << totalAvg;

        // Display grade
        H::setcolor(2);
        H::gotoxy(195, row);
        cout << grd;


        if (manageScoreCount < 100) {
            strcpy(manageScores[manageScoreCount].studentID, stu.id.c_str());
            strcpy(manageScores[manageScoreCount].studentName, stu.name.c_str());
            strcpy(manageScores[manageScoreCount].grade, grade);
            sprintf(manageScores[manageScoreCount].AvgScore, "%.2f", totalAvg);
            strcpy(manageScores[manageScoreCount].rank, string(1, grd).c_str());

            manageScoreCount++;
        }

    }

    // Page info
    H::setcolor(6);
    H::gotoxy(92, 39);
    cout << "PAGE: " << pageIndex + 1 << " / " << totalPages;
}


bool MainManageScore::IsPublished(const char* grade) {
    ifstream inFile("../data/ManageScoreBYAdmin.bin", ios::binary);
    if (!inFile) return false;

    MainManageScore s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(MainManageScore))) {
        if (strcmp(s.grade, grade) == 0) {
            inFile.close();
            return true; // already published
        }
    }
    inFile.close();
    return false; 
}


void MainManageScore::Header(){

    H::VLine(23,7,5,6,186);//chain
    H::VLine(175,7,5,6,186);//chain

    H::drawBoxDoubleLineWithBG(3,0,194,6,10);
    H::drawBoxSingleLineWithBG(3,5,48,1,7);
    H::drawBoxSingleLineWithBG(149,5,48,1,7); 
           
    H::setcolor(6);H::gotoxy(52,2);cout<<R"(                                                                                                )";
    H::setcolor(6);H::gotoxy(52,3);cout<<R"(     ______  ______  _____ ______  ______ ________            _______ ________________________  )";
    H::setcolor(6);H::gotoxy(52,4);cout<<R"( __  ____/__  / / /_  __ \_  __ \_  ___/__  ____/          __  ____/__  /___    |_  ___/_  ___/ )";
    H::setcolor(7);H::gotoxy(52,5);cout<<R"( _  /    __  /_/ /_  / / /  / / /____ \__  __/             _  /    __  / __  /| |____ \_____ \  )";
    H::setcolor(7);H::gotoxy(52,6);cout<<R"( / /___  _  __  / / /_/ // /_/ /____/ /_  /___             / /___  _  /___  ___ |___/ /____/ /  )";
    H::setcolor(7);H::gotoxy(52,7);cout<<R"( \____/  /_/ /_/  \____/ \____/ /____/ /_____/             \____/  /_____/_/  |_/____/ /____/   )";
    H::setcolor(2);H::gotoxy(52,8);cout<<R"(________________________________________________________________________________________________)";
    
    H::drawBoxDoubleLineWithBG(4,1,54,1,4);
    H::setcolor(4);H::gotoxy(11,2);cout<<"[!] PRESS ESC KEY TO BACK TO MAIN MENU !!";


}

void MainManageScore::Menu_Body(){

    //left
    H::drawBoxSingleLineWithBG(3, 11, 1, 21, 6);
    H::drawBoxSingleLineWithBG(42, 11, 1, 21, 6);

    H::drawBoxSingleLineWithBG(3, 11, 40, 3, 6);
    H::setcolor(6);H::gotoxy(8,12);cout<<"------------------->>>>>>>>>>>";
    H::setcolor(6);H::gotoxy(8,13);cout<<"ASSIGN SHCEDULE FOR EACH CLASS";
    H::setcolor(6);H::gotoxy(8,14);cout<<"___________________>>>>>>>>>>>";
    H::drawBoxSingleLineWithBG(3, 29, 40, 3, 6);

    H::setcolor(6); H::gotoxy(15, 24); cout << R"(      /\   |~\ )";
    H::setcolor(6); H::gotoxy(15, 25); cout << R"(    [__]---'__] )";
    H::setcolor(6); H::gotoxy(15, 26); cout << R"(    |""|'''|""| )";
    H::setcolor(6); H::gotoxy(15, 27); cout << R"(    |  | /^\  | )";
    H::setcolor(7); H::gotoxy(15, 28); cout << R"(   _|__|_I_|__|_ )";
    H::setcolor(8); H::gotoxy(15, 29); cout << R"(  /_____________\)";

    H::setcolor(6); H::gotoxy(8, 17);  cout << R"(     \  |  /     )";
    H::setcolor(6); H::gotoxy(8, 18);  cout << R"(      .---.      )";
    H::setcolor(6); H::gotoxy(8, 19);  cout << R"(  -- (     ) --   )";
    H::setcolor(6); H::gotoxy(8, 20);  cout << R"(      '---'      )";
    H::setcolor(6); H::gotoxy(8, 21);  cout << R"(     /  |  \     )";

    H::setcolor(7); H::gotoxy(16, 19); cout << R"(      .--.    )";
    H::setcolor(7); H::gotoxy(16, 20); cout << R"(   .-(    ).  )";
    H::setcolor(7); H::gotoxy(16, 21); cout << R"(  (___.__)__) )";


    //right
    H::drawBoxSingleLineWithBG(155, 11, 1, 21, 6);
    H::drawBoxSingleLineWithBG(194, 11, 1, 21, 6);

    H::drawBoxSingleLineWithBG(155, 11, 40, 3, 6);
    H::setcolor(6);H::gotoxy(160,12);cout<<"<<<<<<<<<<<-------------------";
    H::setcolor(6);H::gotoxy(160,13);cout<<"  CHOOSE ONE CLSSS TO ASSIGN  ";
    H::setcolor(6);H::gotoxy(160,14);cout<<"<<<<<<<<<<<___________________";
    H::drawBoxSingleLineWithBG(155, 29, 40, 3, 6);

    H::setcolor(6); H::gotoxy(167, 24); cout << R"(      /\   |~\ )";
    H::setcolor(6); H::gotoxy(167, 25); cout << R"(    [__]---'__] )";
    H::setcolor(6); H::gotoxy(167, 26); cout << R"(    |""|'''|""| )";
    H::setcolor(6); H::gotoxy(167, 27); cout << R"(    |  | /^\  | )";
    H::setcolor(7); H::gotoxy(167, 28); cout << R"(   _|__|_I_|__|_ )";
    H::setcolor(8); H::gotoxy(167, 29); cout << R"(  /_____________\)";

    H::setcolor(7); H::gotoxy(157, 16);  cout << R"(       _.._   )";
    H::setcolor(7); H::gotoxy(157, 17);  cout << R"(    .' .-'`   )";
    H::setcolor(7); H::gotoxy(157, 18);  cout << R"(   /  /       )";
    H::setcolor(7); H::gotoxy(157, 19);  cout << R"(  |  |        )";
    H::setcolor(7); H::gotoxy(157, 20);  cout << R"(   \  \       )";
    H::setcolor(7); H::gotoxy(157, 21);  cout << R"(    '._'-._   )";
    H::setcolor(7); H::gotoxy(157, 22);  cout << R"(       ```    )";

    H::setcolor(7); H::gotoxy(180, 17); cout << R"(*)";
    H::setcolor(7); H::gotoxy(175, 19); cout << R"(*)";
    H::setcolor(7); H::gotoxy(190, 19); cout << R"(*)";
    H::setcolor(7); H::gotoxy(185, 20); cout << R"(*)";

}

void MainManageScore::Footer(){
    
    H::drawBoxDoubleLineWithBG(3,37,194,6,7);
    H::drawBoxSingleLineWithBG(3,37,55,1,6); //bottom
    H::drawBoxSingleLineWithBG(142,37,55,1,6);

    H::setcolor(6);H::gotoxy(59,36);cout<<R"(  ------------------------------------------------------------------------------  )";
    H::setcolor(6);H::gotoxy(59,37);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,38);cout<<R"(  '                 [!] USE ALL ARROWS TO SELECT THE OPTIONS                   '  )";
    H::setcolor(6);H::gotoxy(59,39);cout<<R"(  '                                                                            '  )";
    H::setcolor(15);H::gotoxy(59,40);cout<<R"(  '                    USE [ESC] KEY TO BACK TO MAIN MENU                      '  )";
    H::setcolor(6);H::gotoxy(59,41);cout<<R"(  '                                                                            '  )";
    H::setcolor(6);H::gotoxy(59,42);cout<<R"(  ------------------------------------------------------------------------------  )";
}


void MainManageScore::HeaderMenuSelect(const char* grade){
    
    if(strcmp(grade,"10")==0){
        H::HLine(1,1,198,6,177);
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(43,1);cout<<R"( ██╗     ██╗███████╗████████╗     ██████╗ ███████╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██████╗  )";
        H::setcolor(1);H::gotoxy(43,2);cout<<R"( ██║     ██║██╔════╝╚══██╔══╝    ██╔═══██╗██╔════╝    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║██╔═████╗ )";
        H::setcolor(3);H::gotoxy(43,3);cout<<R"( ██║     ██║███████╗   ██║       ██║   ██║█████╗      ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║██║██╔██║ )";
        H::setcolor(3);H::gotoxy(43,4);cout<<R"( ██║     ██║╚════██║   ██║       ██║   ██║██╔══╝      ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║████╔╝██║ )";
        H::setcolor(6);H::gotoxy(43,5);cout<<R"( ███████╗██║███████║   ██║       ╚██████╔╝██║         ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║╚██████╔╝ )";
        H::setcolor(6);H::gotoxy(43,6);cout<<R"( ╚══════╝╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝          ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═════╝  )";                                                                                                                 
        system("chcp 437 >nul");
    }
    else if(strcmp(grade,"11")==0){
        
        H::HLine(1,1,198,5,177);
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(45,1);cout<<R"( ██╗     ██╗███████╗████████╗     ██████╗ ███████╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██╗ )";
        H::setcolor(1);H::gotoxy(45,2);cout<<R"( ██║     ██║██╔════╝╚══██╔══╝    ██╔═══██╗██╔════╝    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║███║ )";
        H::setcolor(4);H::gotoxy(45,3);cout<<R"( ██║     ██║███████╗   ██║       ██║   ██║█████╗      ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║╚██║ )";
        H::setcolor(4);H::gotoxy(45,4);cout<<R"( ██║     ██║╚════██║   ██║       ██║   ██║██╔══╝      ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║ ██║ )";
        H::setcolor(5);H::gotoxy(45,5);cout<<R"( ███████╗██║███████║   ██║       ╚██████╔╝██║         ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║ ██║ )";
        H::setcolor(5);H::gotoxy(45,6);cout<<R"( ╚══════╝╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝          ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═╝ )";                                                                                                                 
        system("chcp 437 >nul");
    }
    else if(strcmp(grade,"12")==0){
        
        H::HLine(1,1,198,4,177);
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(43,1);cout<<R"( ██╗     ██╗███████╗████████╗     ██████╗ ███████╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗██████╗  )";
        H::setcolor(1);H::gotoxy(43,2);cout<<R"( ██║     ██║██╔════╝╚══██╔══╝    ██╔═══██╗██╔════╝    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║╚════██╗ )";
        H::setcolor(5);H::gotoxy(43,3);cout<<R"( ██║     ██║███████╗   ██║       ██║   ██║█████╗      ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║ █████╔╝ )";
        H::setcolor(5);H::gotoxy(43,4);cout<<R"( ██║     ██║╚════██║   ██║       ██║   ██║██╔══╝      ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║██╔═══╝  )";
        H::setcolor(4);H::gotoxy(43,5);cout<<R"( ███████╗██║███████║   ██║       ╚██████╔╝██║         ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║███████╗ )";
        H::setcolor(4);H::gotoxy(43,6);cout<<R"( ╚══════╝╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝          ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═════╝ )";                                                                                                                 
        system("chcp 437 >nul");
    }
     
}


void MainManageScore::LoadingHeader(int id){
    if(id == 1){
        H::setcolor(1);H::gotoxy(38,12);cout << R"( ____________________________     _______________     ____________________________     _______________________________ )";
        H::setcolor(1);H::gotoxy(38,13);cout << R"( 7  _  77     77     77  7  7     7      77     7     7        77  _  77  77     7     7        77     77     77  7  7 )";
        H::setcolor(1);H::gotoxy(38,14);cout << R"( |   __||  ___!|  ___!|   __!     !__  __!|  7  |     |  _  _  ||  _  ||  ||  _  |     |  _  _  ||  ___!|  _  ||  |  | )";
        H::setcolor(1);H::gotoxy(38,15);cout << R"( |  _  ||  __|_|  7___|     |       7  7  |  |  |     |  7  7  ||  7  ||  ||  7  |     |  7  7  ||  __|_|  7  ||  |  | )";
        H::setcolor(7);H::gotoxy(38,16);cout << R"( |  7  ||     7|     7|  7  |       |  |  |  !  |     |  |  |  ||  |  ||  ||  |  |     |  |  |  ||     7|  |  ||  !  | )";
        H::setcolor(7);H::gotoxy(38,17);cout << R"( !_____!!_____!!_____!!__!__!       !__!  !_____!     !__!__!__!!__!__!!__!!__!__!     !__!__!__!!_____!!__!__!!_____! )";
    }
    else if(id == 2){
        H::setcolor(2);H::gotoxy(48,12);cout << R"( ______________     ___________________________________________________________________                    )";
        H::setcolor(2);H::gotoxy(48,13);cout << R"( 7     77     7     7     77  _  77     77     77     77     77     77  77     77     7                    )";
        H::setcolor(2);H::gotoxy(48,14);cout << R"( |  7  ||  _  |     |  -  ||    _||  7  ||  ___!|  ___!|  ___!|  ___!|  ||  _  ||   __!                    )";
        H::setcolor(2);H::gotoxy(48,15);cout << R"( |  |  ||  7  |     |  ___!|  _ \ |  |  ||  7___|  __|_!__   7!__   7|  ||  7  ||  !  7                    )";
        H::setcolor(7);H::gotoxy(48,16);cout << R"( |  !  ||  |  |     |  7   |  7  ||  !  ||     7|     77     |7     ||  ||  |  ||     |     ____________   )";
        H::setcolor(7);H::gotoxy(48,17);cout << R"( !_____!!__!__!     !__!   !__!__!!_____!!_____!!_____!!_____!!_____!!__!!__!__!!_____!     7__77__77__7   )";
    }

}


#endif