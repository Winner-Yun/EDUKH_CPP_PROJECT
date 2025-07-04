#include <windows.h>
#include <conio.h>
#include <iostream>
#include "../include/Header_School/ANTHinsyOOP"
#include "../include/Header_EDU/Login_Form.h"
#include "../include/Header_EDU/Main_menu.h"
using namespace ANTHinsyOOP;
Login_Design logD;
MenuDsign menu;

int main() {
    H::DisableScreenResize();
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45); 

    menu.Main_menu();
    
    // logD.MainLogin();
    getch();
    return 0;
}
