#ifndef __INC_ASSIGNCLASSDEMO__
#define __INC_ASSIGNCLASSDEMO__

#include "../Header_School/ANTHinsyOOP"
//#include "../Header_EDU/Main_menu.h"


#include "AssignClassDesign.h"
#include "AssignClass.h"
using namespace ANTHinsyOOP;

class AssignClassDemo {
	public:
		static int AssignClassMenu(); // Main Menu
        static void Highlight(int sel);
        // Grade 10
        static void AssignGrade10Menu();
        // Grade 11
        static void AssignGrade11Menu();
        // Grade 12
        static void AssignGrade12Menu();
        // Grade Menu
        static void drawSingleMenuItem(int index, bool isSelected);
        static void drawGradeMenu(int selected);
        static int GradeMenu();
        // Sort Menu
        static int SortMenu(const char* className);
};

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    // - Call AssignClassDemo::AssignClassMenu(); to use
    
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


//
void AssignClassDemo::AssignGrade12Menu() {
    int currentPage = 0;
    AssignClass ac;
    const int recordsPerPage = 10;
    int currentSort = 0; 

    while (true) {
        H::setcursor(false, 0);
        H::setcolor(7);
        H::cls();
        AssignClassDesign::AssignGrade12Design();
        
        ac.DisplayAll("12", currentPage, currentSort);

        int totalRecords = ac.CountRecords("12");
        int maxPage = (totalRecords + recordsPerPage - 1) / recordsPerPage - 1;
        
        int option = GradeMenu();
        if (option == -1) return;

        switch (option) {
            case 0: { // Assign Class
                bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::G12(0, 15);
                    AssignClassDesign::G12(158, 15);
                    ac.InputClass("12");

                    H::setcolor(55);
                    H::gotoxy(70, 42);
                    cout << "Press [Enter] to assign another class, or [ESC] to return...";

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → return
                }
                break;
            }

            case 1:
            {
            	bool assignings = true;
                while (assignings) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::Grade12Text(70,10);
                    ac.DeleteClass("12");

                    int key = _getch();
                    if (key == 27) assignings = false; // ESC → return
                }
                break;	
			}


            case 2:
            {
                AssignClassDesign::SortClassText12(29,1);
                int sortMethod = SortMenu("12");
                if (sortMethod != -1) {
                    currentSort = sortMethod; // store in a variable
                }
                break;
            }
            case 3:
            {
                H::setcursor(true, 0);
                AssignClass ac;
                bool searching = true;

                while (searching) {
                    H::setcolor(7);
                    H::cls();
                    AssignClassDesign::SearchDesign();

                    string keyword;
                    H::setcolor(7); H::gotoxy(70, 10);
                    H::gotoxy(61,13); cout<<"Enter Teacher Name To Search: ";
                    H::inputLetter(keyword);

                    // Display results (max 10 matches)
                    ac.SearchClass("12", keyword);

                    int key = _getch();
                    if (key == 27) { // ESC
                        searching = false;
                    }
                }
                break;
            }
            case 4:
                if(currentPage > 0 ) currentPage--;
                break;
            case 5:{ // for previous pagination
                if (currentPage < maxPage) currentPage++;
                break;
            }
        }
    }
}

void AssignClassDemo::AssignGrade11Menu() {
    int currentPage = 0;
    AssignClass ac;
    const int recordsPerPage = 10;
    int currentSort = 0;  

    while (true) {
        H::setcursor(false, 0);
        H::setcolor(7);
        H::cls();
        AssignClassDesign::AssignGrade11Design();
        
        ac.DisplayAll("11", currentPage, currentSort);

        int totalRecords = ac.CountRecords("11");
        int maxPage = (totalRecords + recordsPerPage - 1) / recordsPerPage - 1;

        int option = GradeMenu();
        if (option == -1) return;

        switch (option) {
            case 0: { // Assign Class
                bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::G11(0, 15);
                    AssignClassDesign::G11(158, 15);
                    ac.InputClass("11");

                    H::setcolor(55);
                    H::gotoxy(70, 42);
                    cout << "Press [Enter] to assign another class, or [ESC] to return...";

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → return
                }
                break;
            }

            case 1:
			{
				bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::Grade11Text(70,10);
                    ac.DeleteClass("11");

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → return
                }
                break;
			}

            case 2:
            {
                AssignClassDesign::SortClassText11(32,1);
                int sortMethod = SortMenu("11");
                if (sortMethod != -1) {
                    currentSort = sortMethod; // store in a variable
                }
                break;
            }
            case 3:
            {
                H::setcursor(true, 0);
                AssignClass ac;
                bool searching = true;

                while (searching) {
                    H::setcolor(7);
                    H::cls();
                    AssignClassDesign::SearchDesign();

                    string keyword;
                    H::setcolor(7); H::gotoxy(70, 10);
                    H::gotoxy(61,13); cout<<"Enter Teacher Name To Search: ";
                    H::inputLetter(keyword);

                    ac.SearchClass("11", keyword);

                    int key = _getch();
                    if (key == 27) { // ESC
                        searching = false;
                    }
                }
                break;
            }

            case 4:
                if(currentPage > 0 ) currentPage--;
                break;
            case 5:{ // for previous pagination
                if (currentPage < maxPage) currentPage++;
                break;
            }
        }
    }
}

void AssignClassDemo::AssignGrade10Menu() {
    int currentPage = 0;
    AssignClass ac;
    const int recordsPerPage = 10;
    int currentSort  = 0; 

    while (true) {
        H::setcursor(false, 0);
        H::setcolor(7);
        H::cls();
        AssignClassDesign::AssignGrade10Design();

        
        ac.DisplayAll("10", currentPage, currentSort );

        int totalRecords = ac.CountRecords("10");
        int maxPage = (totalRecords + recordsPerPage - 1) / recordsPerPage - 1;
        
        int option = GradeMenu();
        if (option == -1) return;

        switch (option) {
            case 0: { // Assign Class
                bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::G10(0, 15);
                    AssignClassDesign::G10(159, 15);
                    ac.InputClass("10");

                    H::setcolor(55);
                    H::gotoxy(70, 42);
                    cout << "Press [Enter] to assign another class, or [ESC] to return...";

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → return
                }
                break;
            }

            case 1:
			{
				bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::Grade10Text(70,10);
                    ac.DeleteClass("10");

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → return
                }
                break;
			}

            case 2:{
                AssignClassDesign::SortClassText10(29,1);
                int sortMethod = SortMenu("10");
                if (sortMethod != -1) {
                    currentSort = sortMethod; // store in a variable
                }
                break;
            }
            case 3:{
                H::setcursor(true, 0);
                AssignClass ac;
                bool searching = true;

                while (searching) {
                    H::setcolor(7);
                    H::cls();
                    AssignClassDesign::SearchDesign();

                    string keyword;
                    H::setcolor(7); H::gotoxy(70, 10);
                    H::gotoxy(61,13); cout<<"Enter Teacher Name To Search: ";
                    H::inputLetter(keyword);

                    // Display results (max 10 matches)
                    ac.SearchClass("10", keyword);

                    int key = _getch();
                    if (key == 27) { // ESC
                        searching = false;
                    }
                }
                break;
            }          
            case 4:
                if(currentPage > 0 ) currentPage--;
                break;
            case 5:{ // for previous pagination
                if (currentPage < maxPage) currentPage++;
                break;
            }
        }
    }
}
// Sort menu

int AssignClassDemo::SortMenu(const char* className) {
    H::setcursor(false, 0);
    int selected = 0; // 0=Small->Big, 1=Big->Small, 2=A-Z, 3=Z-A
    bool running = true;

    // Coordinates for each box
    struct OptionBox {
        int x, y, w, h;
        int titleX, titleY;
        const char* title;
    } boxes[4] = {
        {29, 30, 32, 1, 30, 31, "Sort by GradeID (Small -> Big)"},
        {66, 28, 32, 1, 67, 29, "Sort by GradeID (Big -> Small)"},
        {102, 30, 32, 1, 103, 31, "Sort by Teacher Name (A-Z)"},
        {139, 28, 32, 1, 140, 29, "Sort by Teacher Name (Z-A)"}
    };

    // Draw static background
    H::setcolor(7);
    system("cls");
    AssignClassDesign::SortClassDesign();

    auto drawBoxes = [&](int highlightIndex) {
        for (int i = 0; i < 4; i++) {
            if (i == highlightIndex) {
                H::setcolor(2);
                H::drawBoxDoubleLine(boxes[i].x, boxes[i].y, boxes[i].w, boxes[i].h, 2);
            } else {
                H::setcolor(3);
                H::drawBoxDoubleLine(boxes[i].x, boxes[i].y, boxes[i].w, boxes[i].h, 3);
            }
            H::setcolor(i == highlightIndex ? 14 : 7);
            H::gotoxy(boxes[i].titleX, boxes[i].titleY);
            cout << boxes[i].title;
        }
    };

    drawBoxes(selected);

    H::setcolor(7);
    H::gotoxy(70, 40);
    cout << "[Arrow Keys] Move   [Enter] Select   [ESC] Exit";

    while (running) {
        int key = _getch();
        if (key == 0 || key == 224) {
            key = _getch();
            if (key == 75) { // Left arrow
                selected = (selected + 3) % 4;
                drawBoxes(selected);
            }
            else if (key == 77) { // Right arrow
                selected = (selected + 1) % 4;
                drawBoxes(selected);
            }
        }
        else if (key == 13) { // Enter key
            H::setcolor(7);
            H::cls();

            switch (selected) {
                case 0:
                    AssignClassDesign::SortGradeIDText(43, 9);
                    AssignClassDesign::SmallToBigText(52, 16);
                    AssignClassDesign::SortLoading();
                    break;
                case 1:
                    AssignClassDesign::SortGradeIDText(43, 9);
                    AssignClassDesign::BigToSmallText(52, 16);
                    AssignClassDesign::SortLoading();
                    break;
                case 2:
                    AssignClassDesign::SortTeacherNameText(23, 9);               
                    AssignClassDesign::AToZText(80, 16);
                    AssignClassDesign::SortLoading();
                    break;
                case 3:
                    // TODO: Add loading UI for Teacher Name Z->A
                    AssignClassDesign::SortTeacherNameText(23, 9);
                    AssignClassDesign::ZToAText(80,16);
                    AssignClassDesign::SortLoading();
                    break;
            }

            return selected; // return chosen sort option
        }
        else if (key == 27) { // ESC key
            return -1; // cancel
        }
    }
    return -1; // fallback
}


/* ----------------------------------- */
struct MenuItem {
    int x, y;
    const char* label;
    int color;
};

MenuItem menuItems[] = {
    {31, 12, "Add Class", 55},       // stays same
    {118, 12, "Delete Class", 55},     // moved here (from index 2)
    {138, 12, "Sort Class", 55},   // moved here (from index 3)
    {158, 12, "Search Class", 55},           // reused position for Search Class from before
    {89, 40, "<---", 55},            // bottom arrows stay same
    {108, 40, "--->", 55}
};

void AssignClassDemo::drawSingleMenuItem(int index, bool isSelected) {
    int bgColor = isSelected ? 199 : menuItems[index].color;
    int width = 15;

    if (index <= 3) {  // top row buttons 0 to 3
        int x;
        switch(index) {
            case 0: x = 28; break;
            case 1: x = 117; break;  // moved from 97 to 117 (matches new menuItems)
            case 2: x = 137; break;  // moved from 117 to 137
            case 3: x = 157; break;  // moved from 137 to 157
        }
        H::drawBoxDoubleLineWithBG(x, 11, width, 1, bgColor);
        H::gotoxy(menuItems[index].x, menuItems[index].y);
        cout << menuItems[index].label;
    } else {
        // bottom arrow boxes (indices 4 and 5)
        H::drawBoxDoubleLineWithBG(menuItems[index].x - 1, menuItems[index].y - 1, 8, 1, bgColor);
        H::gotoxy(menuItems[index].x, menuItems[index].y);
        cout << menuItems[index].label;
    }
}

void AssignClassDemo::drawGradeMenu(int selected) {
    int menuSize = sizeof(menuItems) / sizeof(MenuItem);
    for (int i = 0; i < menuSize; ++i) {
        drawSingleMenuItem(i, i == selected);
    }
}

int AssignClassDemo::GradeMenu() {
    int selected = 0;
    int prevSelected = -1;
    int menuSize = sizeof(menuItems) / sizeof(MenuItem); // now 6

    // Initial draw
    drawGradeMenu(selected);

    while (true) {
        int ch = _getch();

        if (ch == 0 || ch == 224) { // Arrow keys
            ch = _getch();
            prevSelected = selected;

            if (ch == 77) { // Right arrow
                selected = (selected + 1) % menuSize;
            } else if (ch == 75) { // Left arrow
                selected = (selected - 1 + menuSize) % menuSize;
            }

            if (prevSelected != selected) {
                drawSingleMenuItem(prevSelected, false);
                drawSingleMenuItem(selected, true);
            }
        } else if (ch == 13) { // Enter
            return selected;
        } else if (ch == 27) { // ESC
            H::setcolor(7);
            H::cls();
            AssignClassDesign::AssignClassLogo(53, 0);
            return -1;
        }
    }
}

/* --------------- Main Menu --------------------- */

int AssignClassDemo::AssignClassMenu() {
    H::setcursor(false, 0);
    int selected = 0;
    AssignClassDesign::AssignClassLogo(53, 0);
    Highlight(selected);

    while (true) {
        int key = _getch();

        if (key == 0 || key == 224) {
            int arrow = _getch();
            switch (arrow) {
                case 72: // ↑ Up
                    if (selected == 1) selected = 0;
                    else if (selected == 3) selected = 2;
                    break;

                case 80: // ↓ Down
                    if (selected == 0) selected = 1;
                    else if (selected == 2) selected = 3;
                    else if (selected == 3) selected = 0; // ✅ Loop back to top
                    break;

                case 75: // ← Left
                    if (selected == 2) selected = 1;
                    break;

                case 77: // → Right
                    if (selected == 1) selected = 2;
                    break;
            }
        } else if (key == 13) { // Enter
            switch (selected) {
                case 0: H::cls(); AssignGrade10Menu(); break;
                case 1: H::cls(); AssignGrade11Menu(); break;
                case 2: H::cls(); AssignGrade12Menu(); break;
                case 3: H::cls(); return 0; //
            }
        }
        Highlight(selected);
    }
}


void AssignClassDemo::Highlight(int sel) {
    const int normalBoxColor = 213;
    const int normalTextColor = 215;

    const int highlightBoxColor = 153; 
    const int highlightTextColor = 150;

    string items[4] = {
        "1. Assign Grade 10",
        "2. Assign Grade 11",
        "3. Assign Grade 12",
        "4. Back to Main Menu"
    };

    int posX[4] = {90, 66, 115, 90};
    int posY[4] = {14, 19, 19, 24};
    int boxX[4] = {85, 61, 110, 85};
    int boxY[4] = {13, 18, 18, 23};

    for (int i = 0; i < 4; i++) {
        // Draw box with appropriate background color
        int boxColor = (i == sel) ? highlightBoxColor : normalBoxColor;
        H::drawBoxDoubleLineWithBG(boxX[i], boxY[i], 29, 1, boxColor);

        // Set text color
        H::setcolor(i == sel ? highlightTextColor : normalTextColor);
        H::gotoxy(posX[i], posY[i]);
        cout << items[i];
    }

    H::setcolor(7); // Reset to default
}


#endif // __INC_ASSIGNCLASSDEMO__
