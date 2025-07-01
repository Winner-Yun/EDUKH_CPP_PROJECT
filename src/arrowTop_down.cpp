#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void Name(){
	string name;
	cout<<"name : "; cin>>name;
}

void foreColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void cls() {
    system("cls");
}

int main() {
    again:
    int option;
    static int j = 0;
    system("cls");

    do {
        foreColor(14);
        gotoxy(17, 7);
        cout << "-- MENU --" << endl;
        gotoxy(9, 9);
        cout << "1 - OPTION 1" << endl;
        gotoxy(9, 11);
        cout << "2 - OPTION 2" << endl;
        gotoxy(9, 13);
        cout << "3 - OPTION 3" << endl;

        gotoxy(9, 17);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            foreColor(5);
            gotoxy(9, 9);
            cout << "1 - OPTION 1" << endl;
        }
        if (j == 1) {
            foreColor(5);
            gotoxy(9, 11);
            cout << "2 - OPTION 2" << endl;
        }
        if (j == 2) {
            foreColor(5);
            gotoxy(9, 13);
            cout << "3 - OPTION 3" << endl;
        }

        option = getch();
        switch (option) {
            case 80: j++; if (j > 2) j = 0; break;
            case 72: j--; if (j < 0) j = 2; break;
        }
    } while (option != 13);

    switch (j) {
        case 0:
            cls();
            cout << " Handle OPTION 1 ";
            getch();
            break;
        case 1:
            cls();
            cout << " Handle OPTION 2 ";
            getch();
            break;
        case 2:
            cls();
            Name();
          //  cout << " Handle OPTION 3 ";
            getch();
            break;
    }
    getch();
    return 0;
}
