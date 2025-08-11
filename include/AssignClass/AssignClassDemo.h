#ifndef __INC_ASSIGNCLASSDEMO__
#define __INC_ASSIGNCLASSDEMO__

#include "../Header_School/ANTHinsyOOP"


#include "AssignClassDesign.h"
#include "AssignClass.h"
using namespace ANTHinsyOOP;

class AssignClassDemo {
	public:
		static void AssignClassMenu(); // Main Menu
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

//
void AssignClassDemo::AssignGrade12Menu() {
    int currentPage = 0;
    AssignClass ac;
    const int recordsPerPage = 10;
    int currentSort = 0; 
    bool running = true; // controls the outer loop

    while (running) {
        H::setcursor(false, 0);
        H::setcolor(7);
        H::cls();
        AssignClassDesign::AssignGrade10Design();

        ac.DisplayAll("10", currentPage, currentSort);

        int totalRecords = ac.CountRecords("10");
        int maxPage = (totalRecords + recordsPerPage - 1) / recordsPerPage - 1;

        int option = GradeMenu();
        if (option == -1) {
            // ESC pressed in GradeMenu → go back to AssignClassMenu
            break;
        }

        switch (option) {
            case 0: { // Assign Class
                bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::G10(0, 15);
                    AssignClassDesign::G10(159, 15);
                    ac.InputClass("12");

                    H::setcolor(55);
                    H::gotoxy(70, 42);
                    cout << "Press [Enter] to assign another class, or [ESC] to return...";

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → exit mini-loop only
                }
                break;
            }

            case 1: { // Delete Class
                bool deleting = true;
                while (deleting) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::Grade10Text(70,10);
                    ac.DeleteClass("10");

                    int key = _getch();
                    if (key == 27) deleting = false; // ESC → exit mini-loop only
                }
                break;
            }

            case 2: { // Sort
                AssignClassDesign::SortClassText10(29,1);
                int sortMethod = SortMenu("10");
                if (sortMethod != -1) {
                    currentSort = sortMethod;
                }
                break;
            }

            case 3:
                // Search logic
                break;

            case 4: // Back to AssignClassMenu
                running = false; // break outer loop
                break;

            case 5: // previous page
                if (currentPage > 0) currentPage--;
                break;

            case 6: // next page
                if (currentPage < maxPage) currentPage++;
                break;
        }
    }
    // After breaking outer loop, return to AssignClassMenu
    H::setcolor(7);
    H::cls();
    AssignClassMenu();
}

void AssignClassDemo::AssignGrade11Menu() {
    int currentPage = 0;
    AssignClass ac;
    const int recordsPerPage = 10;
    int currentSort = 0; 
    bool running = true; // controls the outer loop

    while (running) {
        H::setcursor(false, 0);
        H::setcolor(7);
        H::cls();
        AssignClassDesign::AssignGrade10Design();

        ac.DisplayAll("11", currentPage, currentSort);

        int totalRecords = ac.CountRecords("11");
        int maxPage = (totalRecords + recordsPerPage - 1) / recordsPerPage - 1;

        int option = GradeMenu();
<<<<<<< HEAD
        if (option == -1) break;
=======
        if (option == -1) {
            // ESC pressed in GradeMenu → go back to AssignClassMenu
            break;
        }
>>>>>>> fcdb8dd45d3d1a46b5d9ace2ccbaa45f9aee4006

        switch (option) {
            case 0: { // Assign Class
                bool assigning = true;
                while (assigning) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::G10(0, 15);
                    AssignClassDesign::G10(159, 15);
                    ac.InputClass("11");

                    H::setcolor(55);
                    H::gotoxy(70, 42);
                    cout << "Press [Enter] to assign another class, or [ESC] to return...";

                    int key = _getch();
                    if (key == 27) assigning = false; // ESC → exit mini-loop only
                }
                break;
            }

            case 1: { // Delete Class
                bool deleting = true;
                while (deleting) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::Grade10Text(70,10);
                    ac.DeleteClass("11");

                    int key = _getch();
                    if (key == 27) deleting = false; // ESC → exit mini-loop only
                }
                break;
            }

            case 2: { // Sort
                AssignClassDesign::SortClassText10(29,1);
                int sortMethod = SortMenu("11");
                if (sortMethod != -1) {
                    currentSort = sortMethod;
                }
                break;
            }

            case 3:
                // Search logic
                break;

            case 4: // Back to AssignClassMenu
                running = false; // break outer loop
                break;

            case 5: // previous page
                if (currentPage > 0) currentPage--;
                break;

            case 6: // next page
                if (currentPage < maxPage) currentPage++;
                break;
        }
    }
    // After breaking outer loop, return to AssignClassMenu
    H::setcolor(7);
    H::cls();
    AssignClassMenu();
}

void AssignClassDemo::AssignGrade10Menu() {
    int currentPage = 0;
    AssignClass ac;
    const int recordsPerPage = 10;
    int currentSort = 0; 
    bool running = true; // controls the outer loop

    while (running) {
        H::setcursor(false, 0);
        H::setcolor(7);
        H::cls();
        AssignClassDesign::AssignGrade10Design();

        ac.DisplayAll("10", currentPage, currentSort);

        int totalRecords = ac.CountRecords("10");
        int maxPage = (totalRecords + recordsPerPage - 1) / recordsPerPage - 1;

        int option = GradeMenu();
        if (option == -1) {
            // ESC pressed in GradeMenu → go back to AssignClassMenu
            break;
        }

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
                    if (key == 27) assigning = false; // ESC → exit mini-loop only
                }
                break;
            }

            case 1: { // Delete Class
                bool deleting = true;
                while (deleting) {
                    H::setcolor(7);
                    H::cls();

                    AssignClassDesign::Grade10Text(70,10);
                    ac.DeleteClass("10");

                    int key = _getch();
                    if (key == 27) deleting = false; // ESC → exit mini-loop only
                }
                break;
            }

            case 2: { // Sort
                AssignClassDesign::SortClassText10(29,1);
                int sortMethod = SortMenu("10");
                if (sortMethod != -1) {
                    currentSort = sortMethod;
                }
                break;
            }

            case 3:
                // Search logic
                break;

            case 4: // Back to AssignClassMenu
                running = false; // break outer loop
                break;

            case 5: // previous page
                if (currentPage > 0) currentPage--;
                break;

            case 6: // next page
                if (currentPage < maxPage) currentPage++;
                break;
        }
    }
    // After breaking outer loop, return to AssignClassMenu
    H::setcolor(7);
    H::cls();
    AssignClassMenu();
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
    {31, 12, "Add Class", 55},
    {98, 12, "Delete Class", 55},
    {119, 12, "Sort Class", 55},
    {138, 12, "Search Class", 55},
    {162, 12, "Back", 55},
    {89, 40, "<---", 55},   // New box 1
    {108, 40, "--->", 55}   // New box 2
};

void AssignClassDemo::drawSingleMenuItem(int index, bool isSelected) {
    int bgColor = isSelected ? 199 : menuItems[index].color;
    int width = 15;

    if (index <= 4) {
        // Top row buttons
        int x;
        switch(index) {
            case 0: x = 28; break;
            case 1: x = 97; break;
            case 2: x = 117; break;
            case 3: x = 137; break;
            case 4: x = 157; break;
        }
        H::drawBoxDoubleLineWithBG(x, 11, width, 1, bgColor);
        H::gotoxy(menuItems[index].x, menuItems[index].y);
        cout << menuItems[index].label;
    } else {
        // Bottom arrow boxes (index 5 & 6)
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
    int menuSize = sizeof(menuItems) / sizeof(MenuItem); // now 7

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
            return -1;
        }
    }
}


/*void AssignClassDemo::drawGradeMenu(int selected) {
    // Clear all buttons area first (draw blank boxes with black background)
    for (int i = 0; i < 5; ++i) {
        int x, width = 15;
        switch(i) {
            case 0: x = 28; break;
            case 1: x = 97; break;
            case 2: x = 117; break;
            case 3: x = 137; break;
            case 4: x = 157; break;
        }
        H::drawBoxDoubleLineWithBG(x, 11, width, 1, 0); // 0 = black or default
    }

    // Now draw actual menu items
    for (int i = 0; i < 5; ++i) {
        drawSingleMenuItem(i, i == selected);
    }
}*/

/*int AssignClassDemo::GradeMenu() {
    int selected = 0;
    int prevSelected = -1;
    int menuSize = sizeof(menuItems) / sizeof(MenuItem);
    
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
            
            // Only redraw if selection actually changed
            if (prevSelected != selected) {
                // Redraw previous item (remove highlight)
                drawSingleMenuItem(prevSelected, false);
                // Redraw current item (add highlight)  
                drawSingleMenuItem(selected, true);
            }
            
        } else if (ch == 13) { // Enter
            return selected;
        }
    }
}*/

/* --------------- Main Menu --------------------- */

void AssignClassDemo::AssignClassMenu() {
    H::setcursor(false, 0);
    int selected = 0;
    bool running = true;
    AssignClassDesign::AssignClassLogo(53, 0);
    Highlight(selected);

    while (running) {
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
                case 0: H::cls(); AssignGrade10Menu(); return;
                case 1: H::cls(); AssignGrade11Menu(); return;
                case 2: H::cls(); AssignGrade12Menu(); return;
                case 3: H::cls();  running = false;  // Exit to main menu
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
