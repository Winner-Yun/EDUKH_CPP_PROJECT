#ifndef __EDU_MASTER_MANAGE_SCHOOL_H__
#define __EDU_MASTER_MANAGE_SCHOOL_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/ScheduleForClass.h"
#include "HeaderOFManageScore.h"

using namespace ANTHinsyOOP;

class MainHeaderOFManageScore{

public:
   static void ManageScoreMain(const char* teacherID ,const char* subject);  // Main Header
   static void MenuSelect(const char* teacherID,const char* grade ,const char* subject);
   static void MenuGradeDesignDesign();
   static void MenuProcess(const char* teacherID, const char* grade,const char* subject);
   static void ReadFileAssMenu(const char* teacherID ,const char* subject);
   static void HeaderMenuSelect(const char* grade);
   string TeacherListMenu();
   static void LoadingHeader(int id);

};


MainHeaderOFManageScore manage;
AssignClassForm ac;
MainHeadOF_ManageScore managePro;



void MainHeaderOFManageScore::ManageScoreMain(const char* teacherID ,const char* subject){                                                                                                                                                                               
    H::setcursor(false,0);
    ReadFileAssMenu(teacherID,subject);
}


void MainHeaderOFManageScore::ReadFileAssMenu(const char* teacherID ,const char* subject) {
    const int consoleWidth = 199;
    const int consoleHeight = 45;

    ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(consoleWidth / 2 - 5, consoleHeight / 2);
        MessageBoxA(GetConsoleWindow(), "Error", "File not found", MB_OK);
        return;
    }

    vector<string> grades;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClassForm))) {
        if (strcmp(ac.teacherID, teacherID) == 0) {
            if (find(grades.begin(), grades.end(), string(ac.className)) == grades.end()) {
                grades.push_back(string(ac.className));
            }
            found = true;
        }
    }
    inFile.close();

    if (!found || grades.empty()) {
        H::setcolor(14);
        CustomMessageBox(80, 20, 60, "ALERT", "SORRY YOU NOT ASSIGNED TO THE CLASS YET.", ICON_WARNING);
        return;
    }

    H::setcolor(7);
    system("cls");
    LoadingHeader(2);
    EdumasterCustom::LoadingPage(30,30,135,5);
    H::cls();

    grades.push_back("<| BACK");

    int boxWidth = 30;  
    int boxHeight = 3;   
    int normalColor = 31;
    int highlightColor = 31; 

    int startX = (consoleWidth - boxWidth) / 2;
    int totalMenuHeight = static_cast<int>(grades.size()) * (boxHeight + 3);
    int startY = ( (consoleHeight - totalMenuHeight) / 2) + 1;

    int currentSelection = 0;
    bool running = true;
    MenuGradeDesignDesign();
    while (running) {
       
      for (size_t i = 0; i < grades.size(); ++i) {
            int yBox = startY + static_cast<int>(i) * (boxHeight + 3); 

            if (i == currentSelection) {
               if (grades[currentSelection] == "<| BACK"){
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLine(startX, yBox, boxWidth, boxHeight, 79);
                  H::setcolor(7);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 2) / 2), yBox+2); 
                  cout << " " << grades[i] << " ";
               }
               else{
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLine(startX, yBox, boxWidth, boxHeight, highlightColor);
                  H::setcolor(7);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 9) / 2), yBox+2); 
                  cout << " GRADE: " << grades[i] << " ";
               }
            } else {
                if (grades[i] == "<| BACK"){
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, 79);
                  H::setcolor(79);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 2) / 2), yBox+2); 
                  cout << " " << grades[i] << " ";

                }
                else{
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, normalColor);
                  H::setcolor(31);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 9) / 2), yBox+2); 
                  cout << " GRADE: " << grades[i] << " ";
                  
                }
            }
        }
        

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) { // Up
                currentSelection = (currentSelection - 1 + grades.size()) % grades.size();
            } else if (key == 80) { // Down
                currentSelection = (currentSelection + 1) % grades.size();
            }
        } else if (key == 13) {
            if (grades[currentSelection] == "<| BACK") {
                running = false;
                H::cls();
            } else {
                H::setcolor(7);
                system("cls");
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30, 30, 135, 5);
                H::cls();
                MenuProcess(teacherID, grades[currentSelection].c_str(),subject);
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30, 30, 135, 5);
                H::cls();
                MenuGradeDesignDesign();
            }
        } else if (key == 27) { // ESC
            running = false;
            H::setcolor(7);
            system("cls");
            LoadingHeader(2);
            EdumasterCustom::LoadingPage(30,30,135,5);
            H::cls();
        }
        
    }
}

// Modified MenuProcess
void MainHeaderOFManageScore::MenuProcess(const char* teacherID, const char* grade ,const char* subject) {
    vector<string> studentIDs;
    managePro.writeDatatoFile(teacherID,grade,subject);

    ifstream inFile("../data/Student_Data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(GetConsoleWindow(), "Error", "Student_Data.bin not found", MB_OK);
        return;
    }

    Student_format sd;
    while (inFile.read(reinterpret_cast<char*>(&sd), sizeof(Student_format))) {
        if (strcmp(sd.grade, grade) == 0) {
            string sid = sd.id;
            if (find(studentIDs.begin(), studentIDs.end(), sid) == studentIDs.end()) {
                studentIDs.push_back(sid);
            }
        }
    }
    inFile.close();

    if (studentIDs.empty()) {
        MessageBoxA(GetConsoleWindow(), "No Student found", "Info", MB_OK);
        return;
    }

    // --- Menu State Variables ---
    int horizontalChoice = 1;
    int verticalChoice = 0;
    int verticalSubChoice = 0; 
    bool verticalActive = true;

    const int consoleWidth = 200;
    const int boxWidth = 27;
    const int boxHeight = 1;
    const int normalColor = 7;
    const int highlightColor = 31;
    const int activeHorizontalColor = 111;
    const int inactiveHorizontalColor = 7;

    bool running = true;
    int pageIndex = 0;
    const int rowsPerPage = 6;
    int totalStudents = managePro.countRecords(teacherID,grade);
    int totalPages = (totalStudents + rowsPerPage - 1) / rowsPerPage;
    // Design Header
    MenuSelect(teacherID, grade, subject);
    while (running) {
        H::setcursor(false, 0);

        // --- Horizontal Menu ---
        int xPos[] = {30, 70, 110, 145};
        string menuLabels[] = {"<- SHOW PREVIOUS", "SEARCH LIST", "CLEAR SCORE", "SHOW NEXT ->"};
        int menuWidths[] = {23, 17, 17, 23};

        for (int i = 0; i < 4; i++) {
            int color = (i == horizontalChoice - 1) ?
                (verticalActive ? inactiveHorizontalColor : activeHorizontalColor) : 7;
            H::drawBoxDoubleLineWithBG(xPos[i], 40, menuWidths[i], 1, color);
            H::setcolor(color);
            H::gotoxy(xPos[i] + (menuWidths[i] - menuLabels[i].size()) / 2, 41);
            cout << menuLabels[i];
        }

        // --- Vertical Menu (Student List) ---
        int startX = 58;
        int startY = 19;
        int startIndex = pageIndex * rowsPerPage;
        int endIndex = min(startIndex + rowsPerPage, (int)studentIDs.size());

        for (int i = startIndex; i < endIndex; ++i) {
            int displayIndex = i - startIndex;
            int yBox = startY + displayIndex * (boxHeight + 2);
            bool isSelected = (displayIndex == verticalChoice && verticalActive);

            // Draw student row box
            if (isSelected) {
                H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, highlightColor);
            } else {
                H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, normalColor);
            }

            int subX[] = {74,90, 102};

            for (int j = 0; j < 3; j++) {
                int boxW = 7; 
                int boxH = 1;

                if (isSelected && j == verticalSubChoice)
                    H::drawBoxSingleLineWithBG(subX[j], yBox, boxW, boxH, activeHorizontalColor);
                else
                    H::drawBoxSingleLineWithBG(subX[j], yBox, boxW, boxH, normalColor);

                H::setcolor(isSelected && j == verticalSubChoice ? activeHorizontalColor : normalColor);
                H::gotoxy(subX[j] + 1, yBox + 1);

            }
            H::setcolor(isSelected ? highlightColor : normalColor);
            H::gotoxy(59, yBox + 1);
            cout << "ENTER SCORE:";
        }

        // Read File
        managePro.readFile(teacherID,grade, pageIndex, rowsPerPage);

        //  Key Handling 
        int key = _getch();

        if (key == 224) {
            key = _getch();
            if (verticalActive) {
                if (key == 72) { // Up
                    verticalChoice--;
                    if (verticalChoice < 0) {
                        if (pageIndex > 0) {
                            H::clearBox(11,20,178,16,7);
                            pageIndex--;
                            verticalChoice = rowsPerPage - 1;
                            if (pageIndex == totalPages - 1)
                                verticalChoice = (totalStudents - 1) % rowsPerPage;
                        } else verticalChoice = 0;
                    }
                } else if (key == 80) { // Down
                    verticalChoice++;
                    if (startIndex + verticalChoice >= studentIDs.size()) {
                        verticalChoice = endIndex - startIndex - 1;
                    } else if (verticalChoice >= rowsPerPage) {
                        if (pageIndex < totalPages - 1) {
                            H::clearBox(11,20,178,16,7);
                            pageIndex++;
                            verticalChoice = 0;
                        } else
                            verticalChoice = endIndex - startIndex - 1;
                    }
                } else if (key == 75) { // Left
                    verticalSubChoice = (verticalSubChoice + 2) % 3;
                } else if (key == 77) { // Right
                    verticalSubChoice = (verticalSubChoice + 1) % 3;
                }
            } else { // Horizontal menu active
                if (key == 75) { // Left
                    horizontalChoice--;
                    if (horizontalChoice < 1) horizontalChoice = 4;
                } else if (key == 77) { // Right
                    horizontalChoice++;
                    if (horizontalChoice > 4) horizontalChoice = 1;
                }
            }
        }
        else if (key == 9) { // Tab 
            verticalActive = !verticalActive;
        }
        else if (key == 13) { // Enter
            if (verticalActive) {
                int selectedIndex = pageIndex * rowsPerPage + verticalChoice;
                if (selectedIndex < studentIDs.size()) {
                    char inputScore[20];
                    int yBox = startY + verticalChoice * (boxHeight + 2);
                    int editX = (verticalSubChoice == 0 ? 76 : (verticalSubChoice == 1 ? 92 : 104));

                    while (true) {
                        H::gotoxy(editX, yBox + 1);
                        cout << "    ";  
                        H::gotoxy(editX, yBox + 1);
                        H::inputUNumber(inputScore, 4);
                        int val = stoi(inputScore);
                        if (val <= 100) break;
                    }

                    if (verticalSubChoice == 0)
                        managePro.writeSetSchoolscore(teacherID,grade,studentIDs[selectedIndex].c_str(), inputScore);
                    else if (verticalSubChoice == 1)
                        managePro.writeSetH1Score(teacherID,grade,studentIDs[selectedIndex].c_str(), inputScore);
                    else if (verticalSubChoice == 2)
                        managePro.writeSetH2Score(teacherID,grade,studentIDs[selectedIndex].c_str(), inputScore);
                }
            } else { // Horizontal menu actions
                switch (horizontalChoice) {
                    case 1:{ 
                        if (pageIndex > 0){
                            pageIndex--; 
                            H::clearBox(11,20,178,16,7);
                        }
                        break;
                     }
                    case 2: { 
                        H::setcursor(true,1);
                        H::drawBoxDoubleLineWithBG(70,20,60,3,7);
                        H::gotoxy(79, 22);
                        cout << "ENTER STUDENT TO SEARCH :  ";
                        char strname[20];
                        H::inputLetter(strname,16);
                        H::clearBox(11,20,178,16,7);
                        managePro.searchRecords(teacherID,grade, strname);
                        getch();
                        H::clearBox(11,20,178,16,7);
                        break;
                    }
                    case 3:{
                        managePro.clearScore(teacherID,grade);
                        H::clearBox(11,20,178,16,7);
                        break;
                    }
                    case 4: {
                        H::clearBox(11,20,178,16,7);
                        if (pageIndex < totalPages - 1) pageIndex++;
                        break;
                    }
                }
            }
        }
        else if (key == 27) { // ESC
            running = false;
            H::cls();
        }
    }
}


void MainHeaderOFManageScore::MenuGradeDesignDesign(){

    H::HLine(14,3,34,7,254);
    H::HLine(150,3,35,7,254);

    H::HLine(14,41,34,7,254);
    H::HLine(150,41,35,7,254);


    H::drawBoxSingleLineWithBG(49,0,100,5,79);
    H::drawBoxSingleLineWithBG(49,38,100,5,79);

    H::drawBoxSingleLineWithBG(2,1,11,41,31);
    H::drawBoxSingleLineWithBG(186,1,11,41,31);
    
    H::HLine(14,19,45,7,254);
    H::HLine(14,25,45,7,254);

    H::HLine(140,19,45,7,254);
    H::HLine(140,25,45,7,254);

    H::HLine(58,10,20,7,254);
    H::HLine(58,34,20,7,254);

    H::HLine(120,10,20,7,254);
    H::HLine(120,34,20,7,254);

    H::VLine(59,10,23,7,219);
    H::VLine(140,10,23,7,219);
    

    H::gotoxy(52,40);H::setcolor(79);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.    ";
    H::gotoxy(102,40);H::setcolor(79);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
    H::gotoxy(52,42);H::setcolor(79);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.       ";
    H::gotoxy(102,42);H::setcolor(79);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.   ";


    
    system("chcp 65001 > nul");
    H::setcolor(79);H::gotoxy(51,1);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████      ██████  ██████   █████  ██████  ███████ )";
    H::setcolor(79);H::gotoxy(51,2);cout<<R"( ██      ██   ██ ██    ██ ██    ██ ██      ██          ██       ██   ██ ██   ██ ██   ██ ██      )";
    H::setcolor(79);H::gotoxy(51,3);cout<<R"( ██      ███████ ██    ██ ██    ██ ███████ █████       ██   ███ ██████  ███████ ██   ██ █████   )";
    H::setcolor(79);H::gotoxy(51,4);cout<<R"( ██      ██   ██ ██    ██ ██    ██      ██ ██          ██    ██ ██   ██ ██   ██ ██   ██ ██      )";
    H::setcolor(79);H::gotoxy(51,5);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████      ██████  ██   ██ ██   ██ ██████  ███████ )";
    system("chcp 437 >nul");      
}



void MainHeaderOFManageScore::MenuSelect(const char* teacherID,const char* grade ,const char* subject){
   H::setcolor(0);
   H::cls();
   H::HLine(1,0,198,1,239);
   HeaderMenuSelect(grade);
   H::drawBoxSingleLineWithBG(157,2,41,3,153);

   ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) {
        H::setcolor(12);
        MessageBoxA(GetConsoleWindow(), "Error", "File not found", MB_OK);
        return;
    }
    vector<string> grades;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClassForm))) {
        if (strcmp(ac.teacherID, teacherID) == 0) {
            const int nameFieldWidth = 19;

            string nameStr(ac.teacherName);
            if (nameStr.size() < nameFieldWidth) {
                nameStr += string(nameFieldWidth - nameStr.size(), ' ');
            }
            transform(nameStr.begin(), nameStr.end(), nameStr.begin(), ::toupper);

            string idStr(ac.teacherID);
            if (idStr.size() < nameFieldWidth) {
                idStr += string(nameFieldWidth - idStr.size(), ' ');
            }
            transform(idStr.begin(), idStr.end(), idStr.begin(), ::toupper);

            string GradeStr(grade);
            if (GradeStr.size() < nameFieldWidth) {
                GradeStr += string(nameFieldWidth - GradeStr.size(), ' ');
            }
            transform(GradeStr.begin(), GradeStr.end(), GradeStr.begin(), ::toupper);

            string SubjectStr(subject);
            if (SubjectStr.size() < nameFieldWidth) {
                SubjectStr += string(nameFieldWidth - SubjectStr.size(), ' ');
            }
            transform(SubjectStr.begin(), SubjectStr.end(), SubjectStr.begin(), ::toupper);


            H::setcolor(31);
            H::gotoxy(158, 3);
            cout << "  TEACHER NAME    : " << nameStr;

            H::setcolor(31);
            H::gotoxy(158, 4);
            cout << "  TEACHER ID      : " << idStr;

            H::setcolor(31);
            H::gotoxy(158, 5);
            cout << "  WORK AT GRADE   : " << GradeStr;
            H::setcolor(31);
            H::gotoxy(158, 6);
            cout << "  WORK AT SUBJECT : " << SubjectStr;

            found = true;
        }

    }
    inFile.close();

    if (!found) {
        H::setcolor(14);
        cout << "No grades found for this teacher.";
        return;
    }

    H::drawBoxSingleLine(2,2,40,3,4);
    H::gotoxy(10,4);cout<<"PRESS ECS KEY TO BACK !!";

    H::HLine(10,8,180,7,205);
    H::setcolor(6);H::gotoxy(12,9);cout << "GRADE SCALE: A: 90-100, B: 80-89, C: 70-79, D: 60-69, F: 0-59\n";
    H::setcolor(6);H::gotoxy(12,11);cout << "NOTE: GRADES ARE BASED ON THE AVERAGE SCORE (AVG).\n";


    H::setcolor(6);H::gotoxy(82,9);cout<<" [ TIP 1 ] USE ~ UP AND DOWN ARROWS ~ TO GO UP AND DOWN. USE ~ LEFT AND RIGHT ARROWS ~ TO GO LEFT AND RIGHT.";
    H::setcolor(4);H::gotoxy(82,11);cout<<" [ NOTE ] TAP TO SWITCH MENU BETWEEN ENTER SCORE AND CONTROL MENU. ALSO USE ~ ENTER KEY ~ TO SELECT IT";

    H::drawBoxSingleLine(10,13,180,3,7);
    H::gotoxy(18,15);H::setcolor(1);cout<<"NO";
    H::gotoxy(26,15);H::setcolor(2);cout<<"NAME";
    H::gotoxy(49,15);H::setcolor(3);cout<<"ID";
    H::gotoxy(58,15);H::setcolor(6);cout<<" SCORE OF ACTIVITY IN CLASS ";
    H::gotoxy(92,15);H::setcolor(6);cout<<"H1";
    H::gotoxy(104,15);H::setcolor(6);cout<<"H2";
    H::gotoxy(116,15);H::setcolor(10);cout<<"Q1";
    H::gotoxy(127,15);H::setcolor(10);cout<<"Q2";
    H::gotoxy(137,15);H::setcolor(10);cout<<"Q3";
    H::gotoxy(147,15);H::setcolor(7);cout<<"TOTAL SCORE";
    H::gotoxy(164,15);H::setcolor(7);cout<<"AVG SCORE";
    H::gotoxy(179,15);H::setcolor(7);cout<<"Gr";

    H::drawBoxSingleLine(10,18,180,18,3);


}


void MainHeaderOFManageScore::HeaderMenuSelect(const char* grade){
    
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

void MainHeaderOFManageScore::LoadingHeader(int id){
    if(id == 1){
         H::setcolor(4);H::gotoxy(70,16);cout << R"( ____   ____________________________________              )";
         H::setcolor(4);H::gotoxy(70,17);cout << R"( 7  7   7     77     77     77  7  77      7              )";
         H::setcolor(4);H::gotoxy(70,18);cout << R"( |  |   |  7  ||   __!|  7  ||  |  |!__  __!              )";
         H::setcolor(4);H::gotoxy(70,19);cout << R"( |  !___|  |  ||  !  7|  |  ||  |  |  7  7                )";
         H::setcolor(7);H::gotoxy(70,20);cout << R"( |     7|  !  ||     ||  !  ||  !  |  |  |  ____________  )";
         H::setcolor(7);H::gotoxy(70,21);cout << R"( !_____!!_____!!_____!!_____!!_____!  !__!  7__77__77__7  )";
    }
    else if(id == 2){
        H::setcolor(2);H::gotoxy(49,12);cout << R"( ______________     ___________________________________________________________________                    )";
        H::setcolor(2);H::gotoxy(49,13);cout << R"( 7     77     7     7     77  _  77     77     77     77     77     77  77     77     7                    )";
        H::setcolor(2);H::gotoxy(49,14);cout << R"( |  7  ||  _  |     |  -  ||    _||  7  ||  ___!|  ___!|  ___!|  ___!|  ||  _  ||   __!                    )";
        H::setcolor(2);H::gotoxy(49,15);cout << R"( |  |  ||  7  |     |  ___!|  _ \ |  |  ||  7___|  __|_!__   7!__   7|  ||  7  ||  !  7                    )";
        H::setcolor(7);H::gotoxy(49,16);cout << R"( |  !  ||  |  |     |  7   |  7  ||  !  ||     7|     77     |7     ||  ||  |  ||     |     ____________   )";
        H::setcolor(7);H::gotoxy(49,17);cout << R"( !_____!!__!__!     !__!   !__!__!!_____!!_____!!_____!!_____!!_____!!__!!__!__!!_____!     7__77__77__7   )";
    }

}

#endif
