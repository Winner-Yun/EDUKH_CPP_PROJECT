#include "../include/Header_School/ANTHinsyOOP"

using namespace ANTHinsyOOP;

int main() {
    
    int option;
    static int j = 0;
    system("cls");

    do {
        H::setcolor(14);
        H::gotoxy(17, 7);
        cout << "-- MENU --" << endl;
        H::gotoxy(9, 9);
        cout << "1 - OPTION 1" << endl;
        H::gotoxy(30, 9);
        cout << "2 - OPTION 2" << endl;
        H::gotoxy(51, 9);
        cout << "3 - OPTION 3" << endl;

        H::gotoxy(9, 17);
        cout << "USE UP AND DOWN ARROW KEYS...";

        if (j == 0) {
            H::setcolor(5);
            H::gotoxy(9, 9);
            cout << "1 - OPTION 1" << endl;
        }
        if (j == 1) {
            H::setcolor(5);
            H::gotoxy(30, 9);
            cout << "2 - OPTION 2" << endl;
        }
        if (j == 2) {
            H::setcolor(5);
            H::gotoxy(51, 9);
            cout << "3 - OPTION 3" << endl;
        }

        option = getch();
        switch (option) {
            case 77: j++; if (j > 2) j = 0; break;
            case 75: j--; if (j < 0) j = 2; break;
        }
    } while (option != 13);

    switch (j) {
        case 0:
            H::cls();
            cout << " Handle OPTION 1 ";
            getch();
            break;
        case 1:
            H::cls();
            cout << " Handle OPTION 2 ";
            getch();
            break;
        case 2:
            H::cls();
//            Name();
          //  cout << " Handle OPTION 3 ";
            getch();
            break;
    }

    return 0;
}
