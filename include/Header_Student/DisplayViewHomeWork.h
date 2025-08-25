#ifndef  __EDU_DISPLAY_VIEW_HOME_WORK_H__
#define  __EDU_DISPLAY_VIEW_HOME_WORK_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/ScheduleForClass.h"

using namespace ANTHinsyOOP;

class ViewHomeWork{
    
    public:
        static void MenuBySubject(const char* grade);
        static void ViewHomeMain(const char* grade);
        static void MenuGradeDesignDesign();
        static void ViewHomeWorkDetails(const char* subject, const char* grade);
        static void ViewHomeWorkDesign();
        static void HeaderDisplay(const char* homeWorkID);
        static void LoadingHeader(int id);
};

struct AssignHomeWork{
    char teacherID[10];
    char teacherName[20];
    char subject[20];
    char grade[10];
    char homeWorkID[2];
    char homeworkDescription[123];
    char homeWorkNote[123];
    char deadLineDate[20];
    char date[20];        
    char createTime[20]; 
};

AssignHomeWork aH;

void ViewHomeWork::MenuBySubject(const char* grade){
    ViewHomeMain(grade);
}
void ViewHomeWork::ViewHomeMain(const char* grade) {
    const int consoleWidth = 202;
    const int consoleHeight = 45;
    H::cls();

    ifstream inFile("../data/AssignCHomeWorkPUBLISH.bin", ios::binary);
    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(consoleWidth / 2 - 5, consoleHeight / 2);
        MessageBoxA(NULL, "Error", "File not found", MB_OK);
        return;
    }

    vector<string> subjects;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&aH), sizeof(AssignHomeWork))) {
        if (strcmp(aH.grade, grade) == 0) {
            if (find(subjects.begin(), subjects.end(), string(aH.subject)) == subjects.end()) {
                subjects.push_back(string(aH.subject));
            }
            found = true;
        }
    }

    if (!found || subjects.empty()) {
        H::setcolor(14);
        H::gotoxy(consoleWidth / 2 - 10, consoleHeight / 2);
        MessageBoxA(NULL, "NO HOMEWORK ASSIGN YET !", "Notice", MB_OK | MB_ICONASTERISK);
        return;
    }

    subjects.push_back("<| BACK");

    // Box settings
    int boxWidth = 30;
    int boxHeight = 3;
    int normalColor = 3;
    int highlightColor = 31;

 
    int cols, rows;
    if (subjects.size() <= 4) {
        cols = 1; 
        rows = subjects.size();  
    } else {
        cols = 2; 
        rows = (subjects.size() + 1) / 2; 
        if (rows > 4) rows = 4; 
    }

    int gridWidth = cols * (boxWidth + 4);
    int gridHeight = rows * (boxHeight + 4);

    int startX = (consoleWidth - gridWidth) / 2;
    int startY = (consoleHeight - gridHeight) / 2;

    int currentSelection = 0;
    bool running = true;
    MenuGradeDesignDesign();

    while (running) {
        // Draw menu
        for (size_t i = 0; i < subjects.size(); ++i) {
            int row = (i / cols);
            int col = (i % cols);

            int xBox = startX + col * (boxWidth + 4);
            int yBox = startY + row * (boxHeight + 4);

            // Label text
            string label = (subjects[i] == "<| BACK") ? subjects[i] : "SUBJECT: " + subjects[i];
            int textX = xBox + (boxWidth - static_cast<int>(label.size())) / 2;

            if (subjects[i] == "<| BACK") {
                if (i == currentSelection) {
                    H::clearBox(xBox, yBox, boxWidth, boxHeight, 7);
                    H::drawBoxSingleLineWithBG(xBox, yBox, boxWidth, boxHeight, 79); 
                    H::setcolor(79);
                } else {
                    H::clearBox(xBox, yBox, boxWidth, boxHeight, 7);
                    H::drawBoxSingleLineWithBG(xBox, yBox, boxWidth, boxHeight, 4); 
                    H::setcolor(7);
                }
            } else {
                if (i == currentSelection) {
                    H::clearBox(xBox, yBox, boxWidth, boxHeight, 7);
                    H::drawBoxSingleLineWithBG(xBox, yBox, boxWidth, boxHeight, highlightColor);
                    H::setcolor(highlightColor);
                } else {
                    H::clearBox(xBox, yBox, boxWidth, boxHeight, 7);
                    H::drawBoxSingleLineWithBG(xBox, yBox, boxWidth, boxHeight, normalColor);
                    H::setcolor(normalColor);
                }
            }

            H::gotoxy(textX, yBox + (boxHeight / 2) + 1);
            cout << label;
        }

        // Handle input
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) { // Up
                currentSelection = (currentSelection - cols + subjects.size()) % subjects.size();
            } else if (key == 80) { // Down
                currentSelection = (currentSelection + cols) % subjects.size();
            } else if (key == 75 && cols > 1) { // Left
                currentSelection = (currentSelection - 1 + subjects.size()) % subjects.size();
            } else if (key == 77 && cols > 1) { // Right
                currentSelection = (currentSelection + 1) % subjects.size();
            }
        } else if (key == 13) { // Enter
            if (subjects[currentSelection] == "<| BACK") {
                running = false;
            } else {
                H::setcolor(7);
                system("cls");
                ViewHomeWorkDetails(subjects[currentSelection].c_str(), grade);
                H::cls();
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30, 30, 135, 5);
                H::cls();
                running = false;
                ViewHomeMain(grade);
            }
        } else if (key == 27) { // ESC
            running = false;
        }
    }
}




void ViewHomeWork::MenuGradeDesignDesign(){
    
    H::HLine(14,3,34,1,254);
    H::HLine(150,3,35,1,254);

    H::HLine(14,41,34,1,254);
    H::HLine(150,41,35,1,254);


    H::drawBoxSingleLineWithBG(41,0,118,5,47);
    H::drawBoxSingleLineWithBG(41,38,118,5,47);

    H::drawBoxSingleLineWithBG(2,1,11,41,31);
    H::drawBoxSingleLineWithBG(186,1,11,41,31);
    
    H::HLine(14,19,45,3,254);
    H::HLine(14,25,45,3,254);

    H::HLine(140,19,45,3,254);
    H::HLine(140,25,45,3,254);

    H::HLine(58,10,20,3,254);
    H::HLine(58,34,20,3,254);

    H::HLine(120,10,20,3,254);
    H::HLine(120,34,20,3,254);

    H::VLine(59,10,23,3,219);
    H::VLine(140,10,23,3,219);
    

    H::gotoxy(52,40);H::setcolor(47);cout<<"  [ TIP 1! ] ENTER TO SELECT THE OPTION.    ";
    H::gotoxy(102,40);H::setcolor(47);cout<<"  [ TIP 2! ] ESC KEY TO BACK TO MAIN MENU.  ";
    H::gotoxy(52,42);H::setcolor(47);cout<<"  [ TIP 3! ] UP ARROW KEY TO MOVE UP.       ";
    H::gotoxy(102,42);H::setcolor(47);cout<<"  [ TIP 4! ] DOWN ARROW KEY TO MOVE DOWN.   ";

    
    system("chcp 65001 > nul");
    H::setcolor(47);H::gotoxy(43,1);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████      ███████ ██    ██ ██████       ██ ███████  ██████ ████████  )";
    H::setcolor(47);H::gotoxy(43,2);cout<<R"( ██      ██   ██ ██    ██ ██    ██ ██      ██           ██      ██    ██ ██   ██      ██ ██      ██         ██     )";
    H::setcolor(47);H::gotoxy(43,3);cout<<R"( ██      ███████ ██    ██ ██    ██ ███████ █████        ███████ ██    ██ ██████       ██ █████   ██         ██     )";
    H::setcolor(47);H::gotoxy(43,4);cout<<R"( ██      ██   ██ ██    ██ ██    ██      ██ ██                ██ ██    ██ ██   ██ ██   ██ ██      ██         ██     )";
    H::setcolor(47);H::gotoxy(43,5);cout<<R"(  ██████ ██   ██  ██████   ██████  ███████ ███████      ███████  ██████  ██████   █████  ███████  ██████    ██     )";
    system("chcp 437 >nul");                                                                                                     
                                                                                                                                                                                               
}

void ViewHomeWork::ViewHomeWorkDetails(const char* subject, const char* grade){
    ifstream inFile("../data/AssignCHomeWorkPUBLISH.bin", ios::binary);
    if (!inFile) {
        H::setcolor(12);
        H::gotoxy(100, 22);
        MessageBoxA(NULL, "Error", "File not found", MB_OK);
        return;
    }

    vector<AssignHomeWork> homeworks;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&aH), sizeof(AssignHomeWork))) {
        if (strcmp(aH.grade, grade) == 0 && strcmp(aH.subject, subject) == 0) {
            homeworks.push_back(aH);
            found = true;
        }
    }
    sort(homeworks.begin(), homeworks.end(), [](const AssignHomeWork& a, const AssignHomeWork& b) {
        return atoi(a.homeWorkID) < atoi(b.homeWorkID);
    });

    if (!found || homeworks.empty()) {
        H::setcolor(14);
        H::gotoxy(100, 22);
        MessageBoxA(NULL, "NO HOMEWORK ASSIGN YET !", "Notice", MB_OK | MB_ICONASTERISK);
        return;
    }

    ViewHomeWork::ViewHomeWorkDesign();
    int startX = 60;
    int startY = 20;
    int boxWidth = 80;
    int boxHeight = 3;
    int gapY = 3;
    int normalColor = 3;
    int highlightColor = 31;
    int currentSelection = 0;
    bool running = true;
    ifstream teacherFile("../data/Teacher_Data.bin", ios::binary);
    if (!teacherFile) {
        H::setcolor(12);
        H::gotoxy(100, 22);
        MessageBoxA(NULL, "Error", "Teacher file not found", MB_OK);
        return;
    }

    struct Teacher {
		char teacherId[20], teacherName[20],gender[20],subject[20],phoneNumber[15],dateOfBirth[20],email[40],pw[20],academyYear[10];
    };

    vector<Teacher> teachers;
    Teacher t;

    while (teacherFile.read(reinterpret_cast<char*>(&t), sizeof(Teacher))) {
        teachers.push_back(t);
    }

    teacherFile.close();

    while (running) {
        for (size_t i = 0; i < homeworks.size(); ++i) {
            int yBox = startY + i * (boxHeight + gapY);

            // Find teacher name by teacher ID
            string teacherName = "Unknown";
            for (const auto& teacher : teachers) {
                if (strcmp(teacher.teacherId, homeworks[i].teacherID) == 0) {
                    teacherName = teacher.teacherName;
                    break;
                }
            }

            // convert to UPPERCASE
            transform(teacherName.begin(), teacherName.end(), teacherName.begin(),
                    [](unsigned char c){ return std::toupper(c); });

            string label = "HOMEWORK NUMBER: " + string(homeworks[i].homeWorkID) + " | ASSIGN BY: " + teacherName + " | DEADLINE: " + string(homeworks[i].deadLineDate);
            int textX = startX + 7;

            if (i == currentSelection) {
                H::clearBox(startX, yBox, boxWidth, boxHeight, 7);
                H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, highlightColor);
                H::setcolor(highlightColor);
            } else {
                H::clearBox(startX, yBox, boxWidth, boxHeight, 7);
                H::drawBoxSingleLineWithBG(startX, yBox, boxWidth, boxHeight, normalColor);
                H::setcolor(normalColor);
            }

            H::gotoxy(textX, yBox + (boxHeight / 2) + 1);
            cout << label;
        }

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) { // Up
                currentSelection = (currentSelection - 1 + homeworks.size()) % homeworks.size();
            } else if (key == 80) { // Down
                currentSelection = (currentSelection + 1) % homeworks.size();
            }
        } else if (key == 13) { // Enter
            H::setcolor(7);
            H::clearBox(22, 4, 158, 38, 7);
            int detailStartY = 5;
            H::setcolor(7);

            const AssignHomeWork& hw = homeworks[currentSelection];
            HeaderDisplay(hw.homeWorkID);
            string teacherName = "UNKNOWN";
            for (const auto& teacher : teachers) {
                if (strcmp(teacher.teacherId, hw.teacherID) == 0) {
                    teacherName = teacher.teacherName;
                    transform(teacherName.begin(), teacherName.end(), teacherName.begin(), ::toupper);
                    break;
                }
            }

            int boxWidth = 72; 
            int fullBoxWidth = 146; 
            int boxHeight = 3;
            int gapY = 3;
            int startXLeft = 28; 
            int startXRight = startXLeft + boxWidth + 2; 
            int currentY = detailStartY + 3;

            auto drawInfoBox = [&](const string& label, const string& value, bool isFullWidth = false, int customColor = -1) {
                if (isFullWidth) {
                    H::clearBox(startXLeft, currentY, fullBoxWidth, boxHeight, 7);
                    H::drawBoxSingleLineWithBG(startXLeft, currentY, fullBoxWidth, boxHeight, 7);
                    H::setcolor(6);
                    H::gotoxy(startXLeft + 2, currentY + 2);
                    cout << label << value;
                    currentY += boxHeight + gapY;
                } else {
                    static bool isLeft = true; 
                    int startX = isLeft ? startXLeft : startXRight;
                    H::clearBox(startX, currentY, boxWidth, boxHeight, 31);
                    H::drawBoxSingleLineWithBG(startX, currentY, boxWidth, boxHeight, 3);
                    H::setcolor(customColor == -1 ? 7 : customColor);  // default 7 unless overridden
                    H::gotoxy(startX + 2, currentY + 2);
                    cout << label << value;
                    if (!isLeft) currentY += boxHeight + gapY;
                    isLeft = !isLeft; 

                }
            };

            drawInfoBox("HOMEWORK NUMBER : ", string(hw.homeWorkID));
            drawInfoBox("ASSIGNED BY     : ", teacherName);
            drawInfoBox("SUBJECT         : ", string(hw.subject));
            drawInfoBox("GRADE           : ", string(hw.grade));
            drawInfoBox("HOMEWORK ID     : ", string(hw.homeWorkID));
            drawInfoBox("DESCRIPTION     : ", string(hw.homeworkDescription), true); // Full width
            drawInfoBox("NOTE            : ", string(hw.homeWorkNote), true); // Full width
            drawInfoBox("DEADLINE DATE   : ", string(hw.deadLineDate),false, 12);
            drawInfoBox("ASSIGNED DATE   : ", string(hw.date));
            drawInfoBox("ASSIGNED TIME   : ", string(hw.createTime));

            H::gotoxy(28 ,35);
            H::setcolor(2);
            cout << "[!] PRESS ANY KEY TO GO BACK...";
            _getch();
            H::setcolor(7);
            H::cls();
            ViewHomeWork::ViewHomeWorkDesign();
        } else if (key == 27) { // ESC
            running = false;
        }
    }
    H::setcolor(7);
}

void ViewHomeWork::ViewHomeWorkDesign(){
    H::cls();
    H::HLine(1,3,19,7,254);
    H::HLine(1,22,19,7,254);
    H::HLine(182,3,17,7,254);
    H::HLine(182,22,17,7,254);

    H::HLine(1,41,19,7,254);
    H::HLine(182,41,17,7,254);
    H::drawBoxSingleLineWithBG(20, 1, 162, 40, 47);
    H::drawBoxSingleLineWithBG(22, 3, 158, 36, 0);
    H::drawBoxSingleLineWithBG(22, 3, 158, 3, 1); 
    H::drawBoxSingleLineWithBG(22, 39, 158, 3, 1); 
    H::drawBoxSingleLineWithBG(20, 1, 162, 3, 2);
    H::drawBoxSingleLineWithBG(20, 38, 162, 3, 2);
    H::drawBoxSingleLineWithBG(20, 1, 3, 40, 47);
    H::drawBoxSingleLineWithBG(179, 1, 3, 40, 47);

    H::setcolor(11); 
    H::gotoxy(62, 3); cout << "~ USE UP AND DOWN ARROW KEYS TO NAVIGATE AND ENTER TO SELECT AN OPTION ~";
    H::drawBoxSingleLine(30, 39, 35, 1, 4);
    H::gotoxy(32, 40); cout << "ECS KEY TO BACK TO SUBJECT MENU";

    system("chcp 65001 > nul");
    H::setcolor(1); H::gotoxy(25, 9); cout << R"( ██████████████████████  )";
    H::setcolor(1); H::gotoxy(25, 10); cout << R"( ██                  ██  )";
    H::setcolor(1); H::gotoxy(25, 11); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 12); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 13); cout << R"( ██     ▄███▄▄▄█     ██  )";  
    H::setcolor(1); H::gotoxy(25, 14); cout << R"( ██     ▀   ▀▀▀      ██  )";  
    H::setcolor(1); H::gotoxy(25, 15); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 16); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 17); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 18); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 19); cout << R"( ██                  ██  )";
    H::setcolor(1); H::gotoxy(25, 20); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 21); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 22); cout << R"( ██     ▄███▄▄▄█     ██  )";  
    H::setcolor(1); H::gotoxy(25, 23); cout << R"( ██     ▀   ▀▀▀      ██  )";  
    H::setcolor(1); H::gotoxy(25, 24); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 25); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 26); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 27); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 28); cout << R"( ██                  ██  )";
    H::setcolor(1); H::gotoxy(25, 29); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 30); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 31); cout << R"( ██     ▄███▄▄▄█     ██  )";  
    H::setcolor(1); H::gotoxy(25, 32); cout << R"( ██     ▀   ▀▀▀      ██  )";  
    H::setcolor(1); H::gotoxy(25, 33); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 34); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 35); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 36); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(25, 37); cout << R"( ██████████████████████  )";

    H::setcolor(1); H::gotoxy(152, 9); cout << R"( ██████████████████████  )";
    H::setcolor(1); H::gotoxy(152, 10); cout << R"( ██                  ██  )";
    H::setcolor(1); H::gotoxy(152, 11); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 12); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 13); cout << R"( ██     ▄███▄▄▄█     ██  )";  
    H::setcolor(1); H::gotoxy(152, 14); cout << R"( ██     ▀   ▀▀▀      ██  )";  
    H::setcolor(1); H::gotoxy(152, 15); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 16); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 17); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 18); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 19); cout << R"( ██                  ██  )";
    H::setcolor(1); H::gotoxy(152, 20); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 21); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 22); cout << R"( ██     ▄███▄▄▄█     ██  )";  
    H::setcolor(1); H::gotoxy(152, 23); cout << R"( ██     ▀   ▀▀▀      ██  )";  
    H::setcolor(1); H::gotoxy(152, 24); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 25); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 26); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 27); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 28); cout << R"( ██                  ██  )";
    H::setcolor(1); H::gotoxy(152, 29); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 30); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 31); cout << R"( ██     ▄███▄▄▄█     ██  )";  
    H::setcolor(1); H::gotoxy(152, 32); cout << R"( ██     ▀   ▀▀▀      ██  )";  
    H::setcolor(1); H::gotoxy(152, 33); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 34); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 35); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 36); cout << R"( ██                  ██  )";  
    H::setcolor(1); H::gotoxy(152, 37); cout << R"( ██████████████████████  )";


    H::setcolor(2); H::gotoxy(45, 8); cout << R"(                                                                                                                )";
    H::setcolor(2); H::gotoxy(45, 9); cout << R"(    ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗   ██╗   ██╗██╗███████╗██╗    ██╗    )";
    H::setcolor(2); H::gotoxy(45, 10); cout << R"(    ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝   ██║   ██║██║██╔════╝██║    ██║    )";
    H::setcolor(2); H::gotoxy(45, 11); cout << R"(    ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝    ██║   ██║██║█████╗  ██║ █╗ ██║    )";
    H::setcolor(2); H::gotoxy(45, 12); cout << R"(    ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██║██╔═██╗    ╚██╗ ██╔╝██║██╔══╝  ██║███╗██║    )";
    H::setcolor(2); H::gotoxy(45, 13); cout << R"(    ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗    ╚████╔╝ ██║███████╗╚███╔███╔╝    )";
    H::setcolor(7); H::gotoxy(45, 14); cout << R"(    ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝     ╚═══╝  ╚═╝╚══════╝ ╚══╝╚══╝     )";

                                  
   
    system("chcp 437 > nul");

    


}

void ViewHomeWork::HeaderDisplay(const char* homeWorkID){
    if(strcmp(homeWorkID, "1") == 0){
        H::setcolor(11); 
          system("chcp 65001 > nul");                                                                                                            
            H::setcolor(31); H::gotoxy(45, 1); cout << R"(  ▄▄    ▄▄    ▄▄▄▄    ▄▄▄  ▄▄▄  ▄▄▄▄▄▄▄▄ ▄▄      ▄▄   ▄▄▄▄    ▄▄▄▄▄▄    ▄▄   ▄▄▄      ▄▄▄▄      ▄▄▄    )";
            H::setcolor(31); H::gotoxy(45, 2); cout << R"(  ██    ██   ██▀▀██   ███  ███  ██▀▀▀▀▀▀ ██      ██  ██▀▀██   ██▀▀▀▀██  ██  ██▀      ██▀▀██    █▀██    )";
            H::setcolor(31); H::gotoxy(45, 3); cout << R"(  ██    ██  ██    ██  ████████  ██       ▀█▄ ██ ▄█▀ ██    ██  ██    ██  ██▄██       ██    ██     ██    )";
            H::setcolor(31); H::gotoxy(45, 4); cout << R"(  ████████  ██    ██  ██ ██ ██  ███████   ██ ██ ██  ██    ██  ███████   █████       ██ ██ ██     ██    )";
            H::setcolor(31); H::gotoxy(45, 5); cout << R"(  ██    ██  ██    ██  ██ ▀▀ ██  ██        ███▀▀███  ██    ██  ██  ▀██▄  ██  ██▄     ██    ██     ██    )";
            H::setcolor(31); H::gotoxy(45, 6); cout << R"(  ██    ██   ██▄▄██   ██    ██  ██▄▄▄▄▄▄  ███  ███   ██▄▄██   ██    ██  ██   ██▄     ██▄▄██   ▄▄▄██▄▄▄ )";
            H::setcolor(31); H::gotoxy(45, 7); cout << R"(  ▀▀    ▀▀    ▀▀▀▀    ▀▀    ▀▀  ▀▀▀▀▀▀▀▀  ▀▀▀  ▀▀▀    ▀▀▀▀    ▀▀    ▀▀▀ ▀▀    ▀▀      ▀▀▀▀    ▀▀▀▀▀▀▀▀ )";
        system("chcp 437 > nul");
    }
    else{
         system("chcp 65001 > nul");                                                                                                            
            H::setcolor(31); H::gotoxy(45, 1); cout << R"(  ▄▄    ▄▄    ▄▄▄▄    ▄▄▄  ▄▄▄  ▄▄▄▄▄▄▄▄ ▄▄      ▄▄   ▄▄▄▄    ▄▄▄▄▄▄    ▄▄   ▄▄▄      ▄▄▄▄      ▄▄▄▄▄    )";
            H::setcolor(31); H::gotoxy(45, 2); cout << R"(  ██    ██   ██▀▀██   ███  ███  ██▀▀▀▀▀▀ ██      ██  ██▀▀██   ██▀▀▀▀██  ██  ██▀      ██▀▀██    █▀▀▀▀██▄  )";
            H::setcolor(31); H::gotoxy(45, 3); cout << R"(  ██    ██  ██    ██  ████████  ██       ▀█▄ ██ ▄█▀ ██    ██  ██    ██  ██▄██       ██    ██         ██  )";
            H::setcolor(31); H::gotoxy(45, 4); cout << R"(  ████████  ██    ██  ██ ██ ██  ███████   ██ ██ ██  ██    ██  ███████   █████       ██ ██ ██       ▄█▀   )";
            H::setcolor(31); H::gotoxy(45, 5); cout << R"(  ██    ██  ██    ██  ██ ▀▀ ██  ██        ███▀▀███  ██    ██  ██  ▀██▄  ██  ██▄     ██    ██     ▄█▀     )";
            H::setcolor(31); H::gotoxy(45, 6); cout << R"(  ██    ██   ██▄▄██   ██    ██  ██▄▄▄▄▄▄  ███  ███   ██▄▄██   ██    ██  ██   ██▄     ██▄▄██   ▄▄██▄▄▄▄▄  )";
            H::setcolor(31); H::gotoxy(45, 7); cout << R"(  ▀▀    ▀▀    ▀▀▀▀    ▀▀    ▀▀  ▀▀▀▀▀▀▀▀  ▀▀▀  ▀▀▀    ▀▀▀▀    ▀▀    ▀▀▀ ▀▀    ▀▀      ▀▀▀▀    ▀▀▀▀▀▀▀▀▀  )";
        system("chcp 437 > nul");
    }
}       

void ViewHomeWork::LoadingHeader(int id){
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