#ifndef __CUSTOM_HEADER_IN_EDU_H__
#define __CUSTOM_HEADER_IN_EDU_H__
#include "../Header_School/ANTHinsyOOP"
#include "../TeacherProfile/ConsoleColor.h"
using namespace ANTHinsyOOP;

class EdumasterCustom{
    public:
        static int ArrowKeyConTrol(int maxOption, int _stepDown_UP, int fchoice,int option) ; // For all arrow key control data need : Max OPtion, step of up and down arrow, fchoice selected and option number
        static void LoadingPage(int x, int y, int width, int speed); // for make loading bar need x, y , width , speed of loading
		static void inputDate(int startX, int startY, char* buffer, bool allowFuture);
        static void inputDeadline(int startX, int startY, char* buffer);
};

struct Cell {
    char ch;
    int color;
};

enum IconType {
    ICON_NONE,
    ICON_INFO,
    ICON_WARNING,
    ICON_ERROR
};

void CustomMessageBox(int x, int y,int w=50, string title="Message", string message="This is example!", IconType icon=ICON_NONE);
void drawIcon(int x, int y, IconType type);
char readCharAt(int x, int y);
int readColorAt(int x, int y);
vector<vector<Cell>> saveBackground(int x, int y, int w, int h);
void restoreBackground(int x, int y, const vector<vector<Cell>>& buffer);

int EdumasterCustom::ArrowKeyConTrol(int maxOption, int _stepDown_UP, int fchoice, int option){
	int step = fchoice;
    if (option == 224) {
        // Arrow key pressed
        int direction = getch();
        
		    if (direction == 77) { // Right arrow    
		        if (step == maxOption) {
		            step = 1;
		        }
		        else {
		            step++;
		        }
		    } 

		    else if (direction == 75) { // Left arrow
		        if (step == 1) {
		            step = maxOption;
		        }
		        else {
		            step--;
		        }
		    } 

		    else if (direction == 80) { // Down arrow        
		        if (step <= maxOption- _stepDown_UP) {
		            step = step + _stepDown_UP;
		        }
		        else {
		            step = step - (maxOption- _stepDown_UP);  //reset
		        }
		    } 
            
		    else if (direction == 72) { // Up arrow  
		        if (step > _stepDown_UP) {
		            step = step - _stepDown_UP;
		        }
		        else {
		            step = step + (maxOption- _stepDown_UP);   //reset
		        }
		    }
    }
    return step;
}

void EdumasterCustom::LoadingPage(int x, int y, int width, int speed) {
	H::setcursor(false, 0);
    H::setcolor(7);H::gotoxy(x,y-1);cout<<"LOADING...";
    H::drawBoxSingleLineWithBG(x, y, width+5, 1, 15);
    for (int i = 0; i <= width; i++) {
        H::HLine(x + i, y + 1, 1, 15, 177);
        cout<<((i*100)/width)<<"%";
        H::delay(speed);
    }
}

void EdumasterCustom::inputDate(int startX, int startY, char* buffer, bool allowFuture) {
    while (true) {
        char temp[11] = {0};
        int index = 0;

        H::gotoxy(startX, startY);
        for (int i = 0; i < 10; i++) cout << " "; // clear previous
        H::gotoxy(startX, startY);

        while (true) {
            char ch = _getch();
            if (ch == 13 && index == 10) {
                temp[index] = '\0';
                break;
            } else if (ch == 8 && index > 0) {
                index--;
                temp[index] = '\0';
                H::gotoxy(startX + index, startY);
                cout << " \b";
            } else if ((ch >= '0' && ch <= '9') && index < 10) {
                if (index == 2 || index == 5) {
                    temp[index++] = '/';
                    cout << '/';
                }
                temp[index++] = ch;
                cout << ch;
            }
        }

        int d, m, y;
        sscanf(temp, "%d/%d/%d", &d, &m, &y);

        bool valid = true;
        if (d < 1 || d > 31) valid = false;
        if (m < 1 || m > 12) valid = false;
        if (y < 1900) valid = false;

        int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) daysInMonth[2] = 29;
        if (m >= 1 && m <= 12 && d > daysInMonth[m]) valid = false;

        if (!allowFuture) {
            time_t t = time(0);
            tm* now = localtime(&t);
            int curY = now->tm_year + 1900;
            int curM = now->tm_mon + 1;
            int curD = now->tm_mday;

            if (y > curY) valid = false;
            else if (y == curY && m > curM) valid = false;
            else if (y == curY && m == curM && d >= curD) valid = false;
        }

        if (valid) {
            strcpy(buffer, temp);
            break;
        } else {
            H::gotoxy(startX, startY);
            for (int i = 0; i < 10; i++) cout << " "; // clear line
            H::gotoxy(startX, startY);
        }
    }
}

void EdumasterCustom::inputDeadline(int startX, int startY, char* buffer) {
    while (true) {
        char temp[11] = {0};
        int index = 0;

        H::gotoxy(startX, startY);
        for (int i = 0; i < 10; i++) cout << " ";
        H::gotoxy(startX, startY);

        while (true) {
            char ch = _getch();
            if (ch == 13 && index == 10) {
                temp[index] = '\0';
                break;
            } else if (ch == 8 && index > 0) {
                index--;
                temp[index] = '\0';
                H::gotoxy(startX + index, startY);
                cout << " \b";
            } else if ((ch >= '0' && ch <= '9') && index < 10) {
                if (index == 2 || index == 5) {
                    temp[index++] = '/';
                    cout << '/';
                }
                temp[index++] = ch;
                cout << ch;
            }
        }

        int d, m, y;
        sscanf(temp, "%d/%d/%d", &d, &m, &y);

        bool valid = true;
        if (d < 1 || d > 31) valid = false;
        if (m < 1 || m > 12) valid = false;
        if (y < 1900) valid = false;

        int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) daysInMonth[2] = 29;
        if (m >= 1 && m <= 12 && d > daysInMonth[m]) valid = false;

        time_t t = time(0);
        tm* now = localtime(&t);
        int curY = now->tm_year + 1900;
        int curM = now->tm_mon + 1;
        int curD = now->tm_mday;

        if (y < curY) valid = false;
        else if (y == curY && m < curM) valid = false;
        else if (y == curY && m == curM && d < curD) valid = false;

        if (valid) {
            strcpy(buffer, temp);
            break;
        } else {
            H::gotoxy(startX, startY);
            for (int i = 0; i < 10; i++) cout << " ";
            H::gotoxy(startX, startY);
        }
    }
}

void CustomMessageBox(int x, int y,int w, string title, string message, IconType icon) {
    H::setcursor(false, 0);
    int h = 10;
    auto bg = saveBackground(x - 1, y - 1, w + 2, h + 5);

    int headerBG = 153, headerFG = 151, bodyFG = 244;
    if (icon == ICON_WARNING) { headerBG = 204; headerFG = 207; }
    else if (icon == ICON_ERROR) { headerBG = 204; headerFG = 207; }
    else if (icon == ICON_INFO) { headerBG = 170; headerFG = 167; bodyFG = 250; }

    H::drawBoxDoubleLineWithBG(x, y, w, 1, headerBG);
    H::setcolor(headerFG);
    H::gotoxy(x + 2, y + 1); cout << title;

    H::drawBoxDoubleLineWithBG(x, y + 3, w, 7, 247);
    H::setcolor(bodyFG);
    H::gotoxy(x + 10, y + 5); cout << message;

    int buttonWidth = 20, buttonHeight = 1;
    int buttonX = x + (w - buttonWidth) / 2;
    int buttonY = y + h - 2;
    H::drawBoxDoubleLineWithBG(buttonX, buttonY, buttonWidth, buttonHeight, 153);

    string btnText = "OK";
    int textX = buttonX + (buttonWidth - (int)btnText.size()) / 2;
    int textY = buttonY + 1;
    H::setcolor(151); H::gotoxy(textX, textY); cout << btnText;

    if (icon != ICON_NONE) {
        drawIcon(x + 1, y + 3, icon);
    }

    while (true) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 13) break;
        }
    }
    restoreBackground(x - 1, y - 1, bg);
}

// --- drawIcon ---
void drawIcon(int x, int y, IconType type) {
    if (type == ICON_INFO) {
        H::setcolor(250);
        system("chcp 65001 > nul");
        H::gotoxy(x, y+0); cout << "  ___";
        H::gotoxy(x, y+1); cout << " /   \\";
        H::gotoxy(x, y+2); cout << "|  ✓  |";
        H::gotoxy(x, y+3); cout << " \\___/";
        system("chcp 437 >nul");
    } else if (type == ICON_WARNING) {
        H::setcolor(244);
        H::gotoxy(x, y+0); cout << "   _";
        H::gotoxy(x, y+1); cout << "  / \\";
        H::gotoxy(x, y+2); cout << " / ! \\";
        H::gotoxy(x, y+3); cout << "/_____\\";
    } else if (type == ICON_ERROR) {
        H::setcolor(244);
        H::gotoxy(x, y+0); cout << "  ___";
        H::gotoxy(x, y+1); cout << " /   \\";
        H::gotoxy(x, y+2); cout << "|  X  |";
        H::gotoxy(x, y+3); cout << " \\___/";
    }
}

// --- Background Save/Restore ---
std::vector<std::vector<Cell>> saveBackground(int x, int y, int w, int h) {
    std::vector<std::vector<Cell>> buffer(h, std::vector<Cell>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            buffer[i][j].ch = readCharAt(x + j, y + i);
            buffer[i][j].color = readColorAt(x + j, y + i);
        }
    }
    return buffer;
}
void restoreBackground(int x, int y, const std::vector<std::vector<Cell>>& buffer) {
    int h = buffer.size(), w = buffer[0].size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            H::setcolor(buffer[i][j].color);
            H::gotoxy(x + j, y + i);
            cout << buffer[i][j].ch;
        }
    }
}
char readCharAt(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CHAR_INFO ci;
    COORD bufferSize = {1,1};
    COORD bufferCoord = {0,0};
    SMALL_RECT readRegion = {(SHORT)x,(SHORT)y,(SHORT)x,(SHORT)y};
    if (ReadConsoleOutput(hConsole, &ci, bufferSize, bufferCoord, &readRegion))
        return ci.Char.AsciiChar;
    return ' ';
}
int readColorAt(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CHAR_INFO ci;
    COORD bufferSize = {1,1};
    COORD bufferCoord = {0,0};
    SMALL_RECT readRegion = {(SHORT)x,(SHORT)y,(SHORT)x,(SHORT)y};
    if (ReadConsoleOutput(hConsole, &ci, bufferSize, bufferCoord, &readRegion))
        return ci.Attributes;
    return 7;
}


#endif