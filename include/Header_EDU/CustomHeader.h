#ifndef __CUSTOM_HEADER_IN_EDU_H__
#define __CUSTOM_HEADER_IN_EDU_H__
#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class EdumasterCustom{
    public:
        static int ArrowKeyConTrol(int maxOption, int _stepDown_UP, int fchoice,int option) ; // For all arrow key control data need : Max OPtion, step of up and down arrow, fchoice selected and option number
        static void LoadingPage(int x, int y, int width, int speed); // for make loading bar need x, y , width , speed of loading
		static void inputDate(int startX, int startY, char* buffer, bool allowFuture);
};

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



#endif