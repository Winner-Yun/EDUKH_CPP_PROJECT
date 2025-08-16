#ifndef __EDU_MASTER_MANAGE_SCHOOL_H__
#define __EDU_MASTER_MANAGE_SCHOOL_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/ScheduleForClass.h"
#include "HeaderOFManageScore.h"

using namespace ANTHinsyOOP;

class MainHeaderOFManageScore{

public:
   static void ManageScoreMain(const char* teacherID );  // Main Header

   static void MenuSelect(const char* teacherID,const char* grade);
   static void MenuGradeDesignDesign();
   static void MenuProcess(const char* teacherID, const char* grade);
   static void FooterDesign();
   static void ReadFileAssMenu(const char* teacherID);
   static void HeaderMenuSelect(const char* grade);
   string TeacherListMenu();

};


MainHeaderOFManageScore manage;
AssignClassForm ac;
MainHeadOF_ManageScore managePro;



void MainHeaderOFManageScore::ManageScoreMain(const char* teacherID ){                                                                                                                                                                               
   H::setcursor(false,0);
   ReadFileAssMenu(teacherID);
}


void MainHeaderOFManageScore::ReadFileAssMenu(const char* teacherID) {
    const int consoleWidth = 200;
    const int consoleHeight = 45;
    H::cls();

    ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(consoleWidth / 2 - 5, consoleHeight / 2);
        MessageBoxA(NULL, "Error", "File not found", MB_OK);
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
        H::gotoxy(consoleWidth / 2 - 10, consoleHeight / 2);
        MessageBoxA(NULL,"SORRY YOU NOT ASSIGNED TO THE CLASS YET.","Notice",MB_OK | MB_ICONASTERISK);

        return;
    }

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
    while (running) {
      MenuGradeDesignDesign();
       
      for (size_t i = 0; i < grades.size(); ++i) {
            int yBox = startY + static_cast<int>(i) * (boxHeight + 3); 

            if (i == currentSelection) {
               if (grades[currentSelection] == "<| BACK"){
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLine(startX, yBox, boxWidth, boxHeight, 79);
                  H::setcolor(7);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 2) / 2), yBox+2); 
                  cout << " " << grades[i] << " ";
                  H::HLine(82,12,36,3,178);
               }
               else{
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLine(startX, yBox, boxWidth, boxHeight, highlightColor);
                  H::setcolor(7);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 9) / 2), yBox+2); 
                  cout << " GRADE: " << grades[i] << " ";
                  H::HLine(82,12,36,3,178);
               }
            } else {
                if (grades[i] == "<| BACK"){
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, 79);
                  H::setcolor(79);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 2) / 2), yBox+2); 
                  cout << " " << grades[i] << " ";
                  H::HLine(82,12,36,3,178);

                }
                else{
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, normalColor);
                  H::setcolor(31);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 9) / 2), yBox+2); 
                  cout << " GRADE: " << grades[i] << " ";
                   H::HLine(82,12,36,3,178);
                  
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
            } else {
                system("cls");
                MenuProcess(teacherID, grades[currentSelection].c_str());
            }
        } else if (key == 27) { // ESC
            running = false;
        }
        
    }
}

// Modified MenuProcess
void MainHeaderOFManageScore::MenuProcess(const char* teacherID, const char* grade) {
    vector<string> studentIDs;
    managePro.writeDatatoFile(grade);

    ifstream inFile("../data/Student_Data.bin", ios::binary);
    if (!inFile) {
        MessageBoxA(NULL, "Error", "Student_Data.bin not found", MB_OK);
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
        MessageBoxA(NULL, "No Student found", "Info", MB_OK);
        return;
    }

    // --- Menu State Variables ---
    int horizontalChoice = 1;
    int verticalChoice = 0;
    bool verticalActive = true;

    const int consoleWidth = 200;
    const int boxWidth = 27;
    const int boxHeight = 1;
    const int normalColor = 7;
    const int highlightColor = 31;
    const int activeHorizontalColor = 31;
    const int inactiveHorizontalColor = 7;

    bool running = true;
    int pageIndex = 0;            
    const int rowsPerPage = 6;    
    int totalStudents = managePro.countRecords(grade);
    int totalPages = (totalStudents + rowsPerPage - 1) / rowsPerPage;

    while (running) {
        H::cls();
        H::setcursor(false, 0);

        //Design
        MenuSelect(teacherID, grade);

       
        // --- Horizontal Menu ---
        int xPos[] = {30, 70, 110, 145};
        string menuLabels[] = {"<- SHOW PREVIOUS", "SEARCH LIST", "BACK", "SHOW NEXT ->"};
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

            if (isSelected) {
                H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, highlightColor);
                H::setcolor(highlightColor);
            } else {
                H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, normalColor);
                H::setcolor(normalColor);
            }

            H::gotoxy(60, yBox + 1);
            cout << "STUDENT SCORE: "; 
        }


        // read File
        managePro.readFile(grade, pageIndex, rowsPerPage);



        // --- Key Handling ---
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 75) { // Left
                verticalActive = false;
                horizontalChoice = (horizontalChoice - 1 + 4) % 4;
                if (horizontalChoice == 0) horizontalChoice = 4;
                
            }
            else if (key == 77) { // Right
                verticalActive = false;
                horizontalChoice = (horizontalChoice % 4) + 1;
            }
            else if (key == 72) { // Up
                verticalActive = true;
                verticalChoice--;
                if (verticalChoice < 0) {
                    if (pageIndex > 0) {
                        pageIndex--;
                        verticalChoice = rowsPerPage - 1;
                        if (pageIndex == totalPages - 1) {
                            verticalChoice = (totalStudents - 1) % rowsPerPage;
                        }
                    } else {
                        verticalChoice = 0;
                    }
                }
            }
            else if (key == 80) { // Down
                verticalActive = true;
                verticalChoice++;
                if (startIndex + verticalChoice >= studentIDs.size()) {
                    verticalChoice = endIndex - startIndex - 1; // Stay at last
                } else if (verticalChoice >= rowsPerPage || startIndex + verticalChoice >= studentIDs.size()) {
                    if (pageIndex < totalPages - 1) {
                        pageIndex++;
                        verticalChoice = 0;
                    } else {
                        verticalChoice = endIndex - startIndex - 1;
                    }
                }
            }
        }
        else if (key == 13) { // Enter
            if (verticalActive) {
                int selectedIndex = pageIndex * rowsPerPage + verticalChoice;
                if (selectedIndex < studentIDs.size()) {
                    char setScoreStudent[20];

                    int yBox = startY + verticalChoice * (boxHeight + 2);

                    H::gotoxy(75, yBox + 1);

                    while (true) {
                            
                            H::gotoxy(76, yBox + 1);
                            cout << "    ";  
                            H::gotoxy(76, yBox + 1);

                            H::inputUNumber(setScoreStudent, 4);
                            int val = stoi(setScoreStudent);
                            if (val <= 100) {
                                break;
                            } 
                        }        

                   managePro.writeSetSchoolscore(studentIDs[selectedIndex].c_str(), setScoreStudent);
                }
            } else {
                switch (horizontalChoice) {
                    case 1: {
                        // Previous Page
                        if (pageIndex > 0) pageIndex--;
                        break;
                    }    
                    case 2:{
                        H::drawBoxDoubleLineWithBG(70,20,60,3,7);
                        H::gotoxy(79, 22);
                        cout << "ENTER STUDENT TO SEARCH :  ";
                        char strname[20];
                        H::inputLetter(strname,16);
                        H::clearBox(11,20,178,16,7);
                        managePro.searchRecords(grade, strname);
                        getch();
                        break;
                    }
                    case 3:{
                         running = false;
                         H::cls();
                    }
                    case 4: {
                        // Next Page
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
      H::drawBoxDoubleLineWithBG(1,1,97,1,153);
      H::drawBoxDoubleLineWithBG(101,1,99,1,170);


      H::HLine(60,13,23,3,178);
      H::HLine(40,14,23,3,178);

      H::HLine(117,13,23,3,178);
      H::HLine(137,14,23,3,178);
      
      H::HLine(60,40,23,3,178);
      H::HLine(40,39,23,3,178);

      H::HLine(82,41,36,3,178);

      H::HLine(117,40,23,3,178);
      H::HLine(137,39,23,3,178);
      

      H::gotoxy(125,17);H::setcolor(7);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.  ";
      H::gotoxy(125,19);H::setcolor(7);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
      H::gotoxy(125,21);H::setcolor(7);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.  ";
      H::gotoxy(125,23);H::setcolor(7);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.  ";


      
      system("chcp 65001 > nul");
      H::setcolor(3);H::gotoxy(10,5);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████     ██████  ███████ ███████ ██████   ██████  ███    ██ ██████  ██ ███    ██  ██████       ██████  ██████   █████  ██████  ███████ )";
      H::setcolor(3);H::gotoxy(10,6);cout<<R"( ██      ██   ██ ██    ██ ██    ██ ██      ██          ██   ██ ██      ██      ██   ██ ██    ██ ████   ██ ██   ██ ██ ████   ██ ██           ██       ██   ██ ██   ██ ██   ██ ██      )";
      H::setcolor(1);H::gotoxy(10,7);cout<<R"( ██      ███████ ██    ██ ██    ██ ███████ █████       ██████  █████   ███████ ██████  ██    ██ ██ ██  ██ ██   ██ ██ ██ ██  ██ ██   ███     ██   ███ ██████  ███████ ██   ██ █████   )";
      H::setcolor(1);H::gotoxy(10,8);cout<<R"( ██      ██   ██ ██    ██ ██    ██      ██ ██          ██   ██ ██           ██ ██      ██    ██ ██  ██ ██ ██   ██ ██ ██  ██ ██ ██    ██     ██    ██ ██   ██ ██   ██ ██   ██ ██      )";
      H::setcolor(1);H::gotoxy(10,9);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████     ██   ██ ███████ ███████ ██       ██████  ██   ████ ██████  ██ ██   ████  ██████       ██████  ██   ██ ██   ██ ██████  ███████ )";
      system("chcp 437 >nul");      
}



void MainHeaderOFManageScore::MenuSelect(const char* teacherID,const char* grade){
   H::setcolor(0);
   H::cls();
   H::HLine(1,0,198,1,239);
   HeaderMenuSelect(grade);
   H::drawBoxSingleLineWithBG(157,2,41,3,153);

   ifstream inFile("../data/AssignClass_Data.bin", ios::binary);
    if (!inFile) {
        H::setcolor(12);
        MessageBoxA(NULL, "Error", "File not found", MB_OK);
        return;
    }
    vector<string> grades;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(AssignClassForm))) {
        if (strcmp(ac.teacherID, teacherID) == 0) {
            const int nameFieldWidth = 18;

            string nameStr(ac.teacherName);
            if (nameStr.size() < nameFieldWidth) {
                nameStr += string(nameFieldWidth - nameStr.size(), ' ');
            }

            string idStr(ac.teacherID);
            if (idStr.size() < nameFieldWidth) {
                idStr += string(nameFieldWidth - idStr.size(), ' ');
            }

            string GradeStr(grade);
            if (GradeStr.size() < nameFieldWidth) {
                GradeStr += string(nameFieldWidth - GradeStr.size(), ' ');
            }

            H::setcolor(31);
            H::gotoxy(159, 3);
            cout << "  TEACHER NAME  : " << nameStr;

            H::setcolor(31);
            H::gotoxy(159, 4);
            cout << "  TEACHER ID    : " << idStr;

            H::setcolor(31);
            H::gotoxy(159, 5);
            cout << "  WORK AT GRADE : " << GradeStr;

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


    H::setcolor(6);H::gotoxy(90,9);cout<<" [ TIP 1 ] USE ~ UP AND DOWN ARROWS ~ TO SELECT THE SUBJECT OF SCORE IN CLASS THAT YOU WANT TO INPUT ";
    H::setcolor(6);H::gotoxy(90,11);cout<<" [ TIP 2 ] USE ~ LEFT AND RIGHT ARROWS ~  TO SELECT THE MENU. ALSO USE ~ ENTER KEY ~ TO SELECT IT ";

    H::drawBoxSingleLine(10,13,180,3,7);
    H::gotoxy(18,15);H::setcolor(1);cout<<"NO";
    H::gotoxy(26,15);H::setcolor(2);cout<<"NAME";
    H::gotoxy(49,15);H::setcolor(3);cout<<"ID";
    H::gotoxy(58,15);H::setcolor(31);cout<<" SCORE OF SUBJECT IN CLASS ";
    H::gotoxy(92,15);H::setcolor(10);cout<<"Q1";
    H::gotoxy(104,15);H::setcolor(10);cout<<"Q2";
    H::gotoxy(116,15);H::setcolor(10);cout<<"Q3";
    H::gotoxy(127,15);H::setcolor(6);cout<<"H1";
    H::gotoxy(137,15);H::setcolor(6);cout<<"H2";
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

#endif
