#ifndef __MAINSIGNHOMEWORK_H__
#define __MAINSIGNHOMEWORK_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/ScheduleForClass.h"
#include "HeaderOFAssignHomeProcess.h"

using namespace ANTHinsyOOP;

class MainAssignHomwork{

public:
    static void AssignHMain(const char* teacherId,const char* subject);
    static void MenuGradeDesignDesign();
    static void ReadFileAssMenu(const char* teacherID,const char* subject);
    static void AssignHMainProcess(const char* id , const char* grade,const char* subject);
    static void DesignAssingMain(const char* teacherID, const char* grade, const char* subject);
    static void HeaderOFGrade(const char* grade);
    static void LoadingHeader(int id);
    static void AssignHomeWorkMainDesign(const char* id , const char* grade, const char* homeWorkID,const char* subject);
};

AssignClassForm ass;

void MainAssignHomwork::AssignHMain(const char* teacherID,const char* subject ){     
   string upperSubject = subject;
   transform(upperSubject.begin(), upperSubject.end(), upperSubject.begin(), ::toupper);                                                                                                                                                                          
   H::setcursor(false,0);
   ReadFileAssMenu(teacherID,upperSubject.c_str());
}

void MainAssignHomwork::ReadFileAssMenu(const char* teacherID,const char* subject) {
    const int consoleWidth = 199;
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

    while (inFile.read(reinterpret_cast<char*>(&ass), sizeof(AssignClassForm))) {
        if (strcmp(ass.teacherID, teacherID) == 0) {
            if (find(grades.begin(), grades.end(), string(ass.className)) == grades.end()) {
                grades.push_back(string(ass.className));
            }
            found = true;
        }
    }

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
                } else {
                    H::setcolor(7);
                    system("cls");
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30, 30, 135, 5);
                    H::cls();
                    AssignHMainProcess(teacherID, grades[currentSelection].c_str(),subject);
                    H::cls();
                    LoadingHeader(2);
                    EdumasterCustom::LoadingPage(30, 30, 135, 5);
                    H::cls();
                    MenuGradeDesignDesign();
                }
            } else if (key == 27) { // ESC
                running = false;
            }
            
    }
}

void MainAssignHomwork::MenuGradeDesignDesign(){
    
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

void MainAssignHomwork::AssignHMainProcess(const char* id , const char* grade,const char* subject){
    H::setcolor(7);
    H::cls();
    int option;
    int choice = 1;
    H::setcursor(false,0);
    do{

        DesignAssingMain(id,"11",subject);      

        do{
            H::drawBoxDoubleLineWithBG(35,20,40,1,47);
            H::drawBoxDoubleLineWithBG(45,25,40,1,47);
            H::drawBoxDoubleLineWithBG(55,30,40,1,79);

            H::setcolor(7);
            H::gotoxy(36, 21);cout << "-------[      HOME WORK 1      ]------" << endl;
            H::gotoxy(43, 20);cout << "-------------------------" << endl;
            H::gotoxy(43, 22);cout << "-------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(46, 26);cout << "-------[      HOME WORK 2      ]------" << endl;
            H::gotoxy(53, 25);cout << "-------------------------" << endl;
            H::gotoxy(53, 27);cout << "-------------------------" << endl;

            H::setcolor(7);
            H::gotoxy(56, 31);cout << "----------[      BACK      ]----------" << endl;
            H::setcolor(4);
            H::gotoxy(66, 30);cout << R"(\----------------/)"<< endl;
            H::gotoxy(66, 32);cout << "__________________" << endl;
           

            switch (choice) {
                case 1: {
                    H::drawBoxDoubleLineWithBG(35,20,40,1,250);
                    H::setcolor(2);
                    H::gotoxy(36, 21);cout << "-------[      HOME WORK 1      ]------" << endl;
                    H::gotoxy(43, 20);cout << "-------------------------" << endl;
                    H::gotoxy(43, 22);cout << "-------------------------" << endl;
                    break;
                }
                case 2: {
                    H::drawBoxDoubleLineWithBG(45,25,40,1,250);
                    H::setcolor(2);
                    H::gotoxy(46, 26);cout << "-------[      HOME WORK 2      ]------" << endl;
                    H::gotoxy(53, 25);cout << "-------------------------" << endl;
                    H::gotoxy(53, 27);cout << "-------------------------" << endl;
                    break;
                }
                case 3: {
                    H::drawBoxDoubleLineWithBG(55,30,40,1,252);
                    H::setcolor(4);
                    H::gotoxy(56, 31);cout << "----------[      BACK      ]----------" << endl;
                    H::setcolor(4);
                    H::gotoxy(66, 30);cout << R"(\----------------/)"<< endl;
                    H::gotoxy(66, 32);cout << "__________________" << endl;
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
                    H::setcolor(7);
                    AssignHomeWorkMainDesign(id ,  grade , "1", subject);
                    H::clearBox(16, 12, 166, 28, 7);
                    break;
                }

                case 2:{
                    H::setcolor(7);
                    AssignHomeWorkMainDesign(id ,  grade , "2", subject);
                    H::clearBox(16, 12, 166, 28, 7);
                    break;
                }

                case 3:{
                    option = 27;
                    H::setcolor(7);
                    break;
                }

            }
        }
    }while(option != 27);

}


void MainAssignHomwork::AssignHomeWorkMainDesign(const char* teacherID, const char* grade, const char* homeWorkID,const char* subject) {
    H::clearBox(16, 12, 166, 28, 7);

    H::VLine(32,30,10,1,219);
    H::VLine(100,30,10,1,219);
    H::VLine(162,30,10,1,219);
    H::drawBoxDoubleLineWithBG(19, 10, 160, 20, 3);
    H::drawBoxDoubleLineWithBG(19, 10, 160, 3, 31);
    H::setcolor(31);
    H::gotoxy(60, 12); 
    cout << " TIP: USE LEFT OR RIGHT TO SWITCH | ENTER TO SELECT | ESC TO QUIT"; 

    H::drawBoxDoubleLineWithBG(21, 14, 156, 4, 111);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    H::drawBoxSingleLineWithBG(49,14,100,3,7);
    H::setcolor(6);H::gotoxy(50, 15); cout << "Teacher Name : "; H::setcolor(7); cout << assH.getnameFromFile(teacherID);
    H::setcolor(6); H::gotoxy(50, 17); cout << "Teacher ID   : "; H::setcolor(7); cout << teacherID;
    H::setcolor(6); H::gotoxy(123, 15); cout << "Grade : "; H::setcolor(7); cout << grade;
    H::setcolor(6); H::gotoxy(123, 17); cout << "UPDATE DATE :"; 
    
    H::drawBoxDoubleLineWithBG(20, 19, 158, 8, 7);
    H::drawBoxSingleLine(84,14,25,1,7);
    H::gotoxy(86,15);H::setcolor(2);cout<<"ASSIGN AT HOMEWORK 0"<<homeWorkID;
    H::gotoxy(84,17);H::setcolor(2);cout<<"ASSIGN AT SUBJECT : "<<subject;

    H::setcolor(2);H::gotoxy(22, 20); cout << "Homework 0"<<homeWorkID<<" Description:";
    
    H::setcolor(6);H::gotoxy(22, 24); cout << "* NOTE :";

    H::VLine(150,19,8,7,186);

    H::gotoxy(152,20);H::setcolor(1);cout<<"DEADLINE DD/MM/YY :";


    int activeIndex = 0;
    bool running = true;

    while (running) {
        bool isPublished = assH.isPublished(teacherID, grade, homeWorkID);
        const char* menuItems[4] = { "RE/CREATE", "CLEAR", isPublished ? "UNPUBLISH" : "PUBLISH", "BACK" };
        bool checkExprire = assH.checkExpire(teacherID, grade, homeWorkID);

        if(checkExprire ){
            H::drawBoxSingleLine(151,25,12,1,4);
            H::setcolor(4);H::gotoxy(154,26);cout<<"EXPIRED";
            assH.unpublishHomework(teacherID, grade, homeWorkID);
            isPublished = false;
            menuItems[2] = "PUBLISH";
        }
        else{
            H::drawBoxSingleLine(151,25,12,1,2);
            H::setcolor(2);H::gotoxy(154,26);cout<<"STABLE";
        }

        if(isPublished){
            H::drawBoxSingleLine(165,25,12,1,6);
            H::setcolor(6);H::gotoxy(166,26);cout<<"PUBLISHED ";
        }
        else{
            H::drawBoxSingleLine(165,25,12,1,3);
            H::setcolor(3);H::gotoxy(166,26);cout<<"InProgress";
        }

        H::setcursor(false,0);
        H::setcolor(2);H::gotoxy(22, 22); cout << ">> ";
        H::setcolor(6);H::gotoxy(22, 26); cout << ">> ";
        H::setcolor(1);H::gotoxy(152, 22); cout << ">> ";
        H::drawBoxDoubleLineWithBG(46, 28, 100, 4, 3);
        H::setcolor(7);H::gotoxy(137,17);cout<< assH.getDateFromFile(teacherID,homeWorkID,grade);
        H::setcolor(7);H::gotoxy(25,22);cout<< assH.getDescriptionFromFile(teacherID,homeWorkID,grade);
        H::setcolor(7);H::gotoxy(25,26);cout<< assH.gethomeWorkNote(teacherID,homeWorkID,grade);
        H::setcolor(7);H::gotoxy(155,22);cout<< assH.getDeadlineFromFile(teacherID,homeWorkID,grade);

        for (int i = 0; i < 4; i++) {
            int xPos = 59 + i * 22;
            int yPos = 30;

            if (i == activeIndex) {
                H::setcolor(12);
                H::gotoxy(xPos, yPos);
                cout << "[ " << menuItems[i] << " ]";
            } else {
                H::setcolor(7);
                H::gotoxy(xPos, yPos);
                cout << "  " << menuItems[i] << "  ";
            }
        }

        int ch = _getch();
        if (ch == 0 || ch == 224) {
            ch = _getch();
            if (ch == 75 && activeIndex > 0) activeIndex--;
            else if (ch == 77 && activeIndex < 3) activeIndex++;
        } else if (ch == 13) {
            H::gotoxy(60, 34);
            H::setcolor(10);

            switch (activeIndex) {
                case 0: // Recreate
                    if (isPublished) {
                        MessageBoxA(NULL, "You need to UNPUBLISH the homework first!", "Action Denied", MB_ICONWARNING);
                    }else{
                        if(MessageBoxA(GetConsoleWindow(), "Are you sure you want to RECREATE this homework?", "Confirm", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                        H::setcursor(true,1);
                        assH.recreateHomework(teacherID, grade, homeWorkID,subject);
                        H::setcolor(7); H::gotoxy(25, 22); cout << string(120, ' ');
                        H::setcolor(7); H::gotoxy(25, 26); cout << string(120, ' ');
                        H::setcolor(7); H::gotoxy(155, 22); cout << string(23, ' ');
                    }
                    }
                    break;

               case 1: // Clear
                    if (isPublished) {
                        MessageBoxA(NULL, "You need to UNPUBLISH the homework first!", "Action Denied", MB_ICONWARNING);
                    } else {
                        if(MessageBoxA(GetConsoleWindow(), "Are you sure you want to CLEAR this homework?", "Confirm", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                            assH.clearHomework(teacherID, grade, homeWorkID, subject);
                            H::setcolor(7); H::gotoxy(25, 22); cout << string(120, ' ');
                            H::setcolor(7); H::gotoxy(25, 26); cout << string(120, ' ');
                            H::setcolor(7); H::gotoxy(155, 22); cout << string(23, ' ');
                        }
                    }
                    break;
                case 2: // Publish / Unpublish
                    if (isPublished) {
                        if(MessageBoxA(GetConsoleWindow(), "Are you sure you want to UNPUBLISH this homework?", "Confirm", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                            assH.unpublishHomework(teacherID, grade, homeWorkID);
                            isPublished = false;
                            menuItems[2] = "PUBLISH";
                        }
                    } else {
                        if(MessageBoxA(GetConsoleWindow(), "Are you sure you want to PUBLISH this homework?", "Confirm", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                            assH.publishHomework(teacherID, grade, homeWorkID);
                            isPublished = true;
                            menuItems[2] = "UNPUBLISH";
                        }
                    }
                    H::setcolor(7); H::gotoxy(25, 22); cout << string(120, ' ');
                    H::setcolor(7); H::gotoxy(25, 26); cout << string(120, ' ');
                    H::setcolor(7); H::gotoxy(155, 22); cout << string(23, ' ');
                    break;

                case 3: // Back
                    running = false; 
                    break;
            }
        } else if (ch == 27) {
            running = false;   
        }
    }
}



void MainAssignHomwork::DesignAssingMain(const char* teacherID, const char* grade,const char* subject){
    HeaderOFGrade(grade);
    H::HLine(18,16,87,7,205);
    H::drawBoxSingleLineWithBG(102,14,60,3,7);
    H::gotoxy(103,15);cout<<"TEACHER NAME  : "<<assH.getnameFromFile(teacherID)<<" | "<<"TEACHER ID: "<<teacherID;
    H::gotoxy(103,17);cout<<"WORK AT GRADE : "<<grade<< " | "<<"SUBJECT RESPONSIBILITY : "<<subject;

   
                                                                                                                                                                                                      
    system("chcp 65001 > nul");


    H::setcolor(1);H::gotoxy(5,12);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,13);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,14);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,15);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,16);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,17);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,18);cout<<R"(  ░██ ░██   )";          
    H::setcolor(1);H::gotoxy(5,19);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,20);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,21);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,22);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,23);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,24);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,25);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,26);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,27);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,28);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,29);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,30);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,31);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,32);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,33);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,34);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,35);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,36);cout<<R"(  ░██ ░██   )";   
    H::setcolor(1);H::gotoxy(5,37);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,38);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(5,39);cout<<R"(  ░██ ░██   )"; 

    
    H::setcolor(1);H::gotoxy(182,12);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,13);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,14);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,15);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,16);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,17);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,18);cout<<R"(  ░██ ░██   )";          
    H::setcolor(1);H::gotoxy(182,19);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,20);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,21);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,22);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,23);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,24);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,25);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,26);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,27);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,28);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,29);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,30);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,31);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,32);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,33);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,34);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,35);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,36);cout<<R"(  ░██ ░██   )";   
    H::setcolor(1);H::gotoxy(182,37);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,38);cout<<R"(  ░██ ░██   )"; 
    H::setcolor(1);H::gotoxy(182,39);cout<<R"(  ░██ ░██   )"; 

    system("chcp 437 >nul");

    H::setcolor(7); H::gotoxy(34, 12);cout<<"________________________________________[                                             ]__________________________________________";
    H::setcolor(7);H::gotoxy(76, 12);cout<<"--- CHOOSE HOMEWORK THAT WANT TO ASSIGN ---"; 
    H::gotoxy(122,23);H::setcolor(7);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.    ";
    H::gotoxy(122,25);H::setcolor(7);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
    H::gotoxy(122,27);H::setcolor(7);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.       ";
    H::gotoxy(122,29);H::setcolor(7);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.   ";

                                                                                                                                                                                                           
    H::setcolor(7);H::gotoxy(17,37);cout<<R"( |\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /||\     /| )";
    H::setcolor(1);H::gotoxy(17,38);cout<<R"( | )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( | )";
    H::setcolor(1);H::gotoxy(17,39);cout<<R"( | (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) || (___) | )";
    H::setcolor(7);H::gotoxy(17,40);cout<<R"( |  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  ||  ___  | )";
    H::setcolor(1);H::gotoxy(17,41);cout<<R"( | (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) || (   ) | )";
    H::setcolor(1);H::gotoxy(17,42);cout<<R"( | )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( || )   ( | )";
    H::setcolor(7);H::gotoxy(17,43);cout<<R"( |/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \||/     \| )";
}

void MainAssignHomwork::HeaderOFGrade(const char* grade){
    if(strcmp(grade,"10")==0){
        H::drawBoxSingleLineWithBG(1,0,198,6,31);
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(7,0);cout<<R"(                                                                                                                                                                                          )";
        H::setcolor(1);H::gotoxy(7,1);cout<<R"(   █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗    ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗     ██████╗██╗      █████╗ ███████╗███████╗     ██╗ ██████╗   )";
        H::setcolor(1);H::gotoxy(7,2);cout<<R"(  ██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝██╔════╝    ███║██╔═████╗  )";
        H::setcolor(1);H::gotoxy(7,3);cout<<R"(  ███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝     ██║     ██║     ███████║███████╗███████╗    ╚██║██║██╔██║  )";
        H::setcolor(2);H::gotoxy(7,4);cout<<R"(  ██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗     ██║     ██║     ██╔══██║╚════██║╚════██║     ██║████╔╝██║  )";
        H::setcolor(2);H::gotoxy(7,5);cout<<R"(  ██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗    ╚██████╗███████╗██║  ██║███████║███████║     ██║╚██████╔╝  )";
        H::setcolor(7);H::gotoxy(7,6);cout<<R"(  ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝     ╚═════╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝     ╚═╝ ╚═════╝   )"; 
        
        H::setcolor(2);H::gotoxy(5,10);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(5,11);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(5,40);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(5,41);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,10);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,11);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,40);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,41);cout<<R"(  ░██ ░██   )";
        system("chcp 437 >nul");
        H::HLine(6,7,188,7,205);

        H::HLine(15,10,168,2,178);
        H::HLine(15,41,168,2,178);
    }
    else if(strcmp(grade,"11")==0){
        H::drawBoxSingleLineWithBG(1,0,198,6,111);
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(9,0);cout<<R"(                                                                                                                                                                                     )";
        H::setcolor(6);H::gotoxy(9,1);cout<<R"(   █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗    ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗     ██████╗██╗      █████╗ ███████╗███████╗     ██╗ ██╗  )";
        H::setcolor(6);H::gotoxy(9,2);cout<<R"(  ██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝██╔════╝    ███║███║  )";
        H::setcolor(6);H::gotoxy(9,3);cout<<R"(  ███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝     ██║     ██║     ███████║███████╗███████╗    ╚██║╚██║  )";
        H::setcolor(4);H::gotoxy(9,4);cout<<R"(  ██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗     ██║     ██║     ██╔══██║╚════██║╚════██║     ██║ ██║  )";
        H::setcolor(4);H::gotoxy(9,5);cout<<R"(  ██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗    ╚██████╗███████╗██║  ██║███████║███████║     ██║ ██║  )";
        H::setcolor(7);H::gotoxy(9,6);cout<<R"(  ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝     ╚═════╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝     ╚═╝ ╚═╝  )";
        
        H::setcolor(4);H::gotoxy(5,10);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(5,11);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(5,40);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(5,41);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(182,10);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(182,11);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(182,40);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(4);H::gotoxy(182,41);cout<<R"(  ░██ ░██   )";
        system("chcp 437 >nul");
        H::HLine(6,7,187,7,205);

        H::HLine(15,10,168,4,178);
        H::HLine(15,41,168,4,178);
                                                                                                                                                                                 
    }
    else{
        H::drawBoxSingleLineWithBG(1,0,198,6,47);
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(7,0);cout<<R"(                                                                                                                                                                                          )";
        H::setcolor(2);H::gotoxy(7,1);cout<<R"(   █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗    ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗     ██████╗██╗      █████╗ ███████╗███████╗     ██╗██████╗    )";
        H::setcolor(2);H::gotoxy(7,2);cout<<R"(  ██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝██╔════╝    ███║╚════██╗   )";
        H::setcolor(2);H::gotoxy(7,3);cout<<R"(  ███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝     ██║     ██║     ███████║███████╗███████╗    ╚██║ █████╔╝   )";
        H::setcolor(1);H::gotoxy(7,4);cout<<R"(  ██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗     ██║     ██║     ██╔══██║╚════██║╚════██║     ██║██╔═══╝    )";
        H::setcolor(1);H::gotoxy(7,5);cout<<R"(  ██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗    ╚██████╗███████╗██║  ██║███████║███████║     ██║███████╗   )";
        H::setcolor(7);H::gotoxy(7,6);cout<<R"(  ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝     ╚═════╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝     ╚═╝╚══════╝   )";
       
        H::setcolor(2);H::gotoxy(5,10);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(5,11);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(5,40);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(5,41);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,10);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,11);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,40);cout<<R"(  ░██ ░██   )"; 
        H::setcolor(2);H::gotoxy(182,41);cout<<R"(  ░██ ░██   )";
        system("chcp 437 >nul");     
        H::HLine(6,7,188,7,205);

        H::HLine(15,10,168,2,178);
        H::HLine(15,41,168,2,178);
                                                                                                                                                                     
    }
}

void MainAssignHomwork::LoadingHeader(int id){
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