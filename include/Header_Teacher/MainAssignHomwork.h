#ifndef __MAINSIGNHOMEWORK_H__
#define __MAINSIGNHOMEWORK_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/ScheduleForClass.h"

using namespace ANTHinsyOOP;

class MainAssignHomwork{

public:
    static void AssignHMain(const char* teacherId);
    static void MenuSelect(const char* teacherID,const char* grade);
    static void MenuGradeDesignDesign();
    static void ReadFileAssMenu(const char* teacherID);
    static void AssignHMainProcess(const char* id , const char* grade);
    static void DesignAssingMain(const char* grade);
    static void HeaderOFGrade(const char* grade);
};

AssignClassForm ass;

void MainAssignHomwork::AssignHMain(const char* teacherID ){                                                                                                                                                                               
   H::setcursor(false,0);
   ReadFileAssMenu(teacherID);
}

void MainAssignHomwork::ReadFileAssMenu(const char* teacherID) {
    const int consoleWidth = 220;
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
                  H::HLine(92,12,36,7,178);
               }
               else{
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLine(startX, yBox, boxWidth, boxHeight, highlightColor);
                  H::setcolor(7);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 9) / 2), yBox+2); 
                  cout << " GRADE: " << grades[i] << " ";
                  H::HLine(92,12,36,7,178);
               }
            } else {
                if (grades[i] == "<| BACK"){
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, 79);
                  H::setcolor(79);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 2) / 2), yBox+2); 
                  cout << " " << grades[i] << " ";
                  H::HLine(92,12,36,7,178);

                }
                else{
                  H::clearBox(startX,yBox,boxWidth,boxHeight,7);
                  H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, normalColor);
                  H::setcolor(31);
                  H::gotoxy(startX + (boxWidth / 2) - ((grades[i].size() + 9) / 2), yBox+2); 
                  cout << " GRADE: " << grades[i] << " ";
                   H::HLine(92,12,36,7,178);
                  
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
                AssignHMainProcess(teacherID, grades[currentSelection].c_str());
            }
        } else if (key == 27) { // ESC
            running = false;
        }
        
    }
}

void MainAssignHomwork::MenuGradeDesignDesign(){
    H::VLine(90,11,33,1,178);
    H::VLine(91,11,33,1,178);
    H::VLine(130,11,33,1,178);
    H::VLine(131,11,33,1,178);
    H::HLine(92,44,36,7,178);


    H::gotoxy(144,17);H::setcolor(7);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.  ";
    H::gotoxy(144,19);H::setcolor(7);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
    H::gotoxy(144,21);H::setcolor(7);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.  ";
    H::gotoxy(144,23);H::setcolor(7);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.  ";
    H::HLine(143,25,47,7,178);

    H::VLine(167,25,19,1,178);
    H::VLine(168,25,19,1,178);

    H::HLine(0,5,69,1,178);
    H::VLine(69,1,7,1,178);

    H::HLine(153,5,47,1,178);
    H::VLine(153,1,7,1,178);

    
    H::gotoxy(71,2);H::setcolor(7);cout<<R"(   _____  _   _ _____  _____ _____ _____     _____  _      ___   _____ _____   )";
    H::gotoxy(71,3);H::setcolor(1);cout<<R"(  /  __ \| | | |  _  ||  _  /  ___|  ___|   /  __ \| |    / _ \ /  ___/  ___|  )";
    H::gotoxy(71,4);H::setcolor(1);cout<<R"(  | /  \/| |_| | | | || | | \ `--.| |__     | /  \/| |   / /_\ \\ `--.\ `--.   )";
    H::gotoxy(71,5);H::setcolor(1);cout<<R"(  | |    |  _  | | | || | | |`--. \  __|    | |    | |   |  _  | `--. \`--. \  )";
    H::gotoxy(71,6);H::setcolor(1);cout<<R"(  | \__/\| | | \ \_/ /\ \_/ /\__/ / |___    | \__/\| |___| | | |/\__/ /\__/ /  )";
    H::gotoxy(71,7);H::setcolor(7);cout<<R"(   \____/\_| |_/\___/  \___/\____/\____/     \____/\____/\_| |_/\____/\____/   )";
        
                                                                                                    
                                                                                                                                                                                               
}

void MainAssignHomwork::AssignHMainProcess(const char* id , const char* grade){
    H::cls();
    DesignAssingMain("12");
    getch();
}
void MainAssignHomwork::DesignAssingMain(const char* grade){
    HeaderOFGrade(grade);

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

        
}

void MainAssignHomwork::HeaderOFGrade(const char* grade){
    if(strcmp(grade,"10")==0){
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(7,1);cout<<R"(   █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗    ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗     ██████╗██╗      █████╗ ███████╗███████╗     ██╗ ██████╗   )";
        H::setcolor(1);H::gotoxy(7,2);cout<<R"(  ██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝██╔════╝    ███║██╔═████╗  )";
        H::setcolor(1);H::gotoxy(7,3);cout<<R"(  ███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝     ██║     ██║     ███████║███████╗███████╗    ╚██║██║██╔██║  )";
        H::setcolor(2);H::gotoxy(7,4);cout<<R"(  ██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗     ██║     ██║     ██╔══██║╚════██║╚════██║     ██║████╔╝██║  )";
        H::setcolor(2);H::gotoxy(7,5);cout<<R"(  ██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗    ╚██████╗███████╗██║  ██║███████║███████║     ██║╚██████╔╝  )";
        H::setcolor(7);H::gotoxy(7,6);cout<<R"(  ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝    ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝     ╚═════╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝     ╚═╝ ╚═════╝   )";                
        system("chcp 437 >nul");
        H::HLine(6,7,187,7,205);
    }
    else if(strcmp(grade,"11")==0){
        
        system("chcp 65001 > nul");
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
        system("chcp 65001 > nul");
        H::setcolor(2);H::gotoxy(7,1);cout<<R"(   █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗    ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗     ██████╗██╗      █████╗ ███████╗███████╗     ██╗██████╗    )";
        H::setcolor(2);H::gotoxy(7,2);cout<<R"(  ██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝    ██╔════╝██║     ██╔══██╗██╔════╝██╔════╝    ███║╚════██╗   )";
        H::setcolor(2);H::gotoxy(7,3);cout<<R"(  ███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝     ██║     ██║     ███████║███████╗███████╗    ╚██║ █████╔╝   )";
        H::setcolor(6);H::gotoxy(7,4);cout<<R"(  ██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗     ██║     ██║     ██╔══██║╚════██║╚════██║     ██║██╔═══╝    )";
        H::setcolor(6);H::gotoxy(7,5);cout<<R"(  ██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗    ╚██████╗███████╗██║  ██║███████║███████║     ██║███████╗   )";
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
        H::HLine(6,7,187,7,205);

        H::HLine(15,10,168,2,178);
        H::HLine(15,41,168,2,178);
                                                                                                                                                                     
    }
}


#endif