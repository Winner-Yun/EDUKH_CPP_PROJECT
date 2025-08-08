#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawMenu(const string menu[], int size, int selected) {
    for (int i = 0; i < size; ++i) {
        gotoxy(5, 5 + i);
        if (i == selected) {
            setcolor(3);
            cout << "-> " << menu[i];
        } else {
            setcolor(7);
            cout << "   " << menu[i];
        }
    }
}

void drawClock(int hour, int minute) {
    string period = (hour >= 12) ? "PM" : "AM";
    int hour12 = hour % 12;
    if (hour12 == 0) hour12 = 12;

    gotoxy(50, 2);
    setcolor(6);
    cout << "TIME: ";
    if (hour12 < 10) cout << "0";
    cout << hour12 << ":";
    if (minute < 10) cout << "0";
    cout << minute << " " << period << "   ";
}

int main() {
    const string menu[] = { "Dashboard", "Students", "Teachers", "Classes", "Exit" };
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    int selected = 0;
    bool running = true;

    time_t now = time(0);
    tm* lastTime = localtime(&now);
    int lastMinute = lastTime->tm_min;

    system("cls");
    drawClock(lastTime->tm_hour, lastMinute);
    drawMenu(menu, menuSize, selected);

    while (running) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 224) {
                key = _getch();
                if (key == 72) selected = (selected - 1 + menuSize) % menuSize;
                else if (key == 80) selected = (selected + 1) % menuSize;
                drawMenu(menu, menuSize, selected);
            } else if (key == 13) {
                if (menu[selected] == "Exit") running = false;
            }
        }

        now = time(0);
        tm* currentTime = localtime(&now);
        if (currentTime->tm_min != lastMinute) {
            lastMinute = currentTime->tm_min;
            drawClock(currentTime->tm_hour, currentTime->tm_min);
        }

        Sleep(100);
    }

    return 0;
}
