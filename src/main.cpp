#include <windows.h>
#include <conio.h>
#include <iostream>
#include "../include/Header_School/ANTHinsyOOP"
#include "../include/Header_EDU/Login_Form.h"
using namespace ANTHinsyOOP;

int main() {
    H::DisableScreenResize();
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45);
    Loading_Design::mainTile();
    getch();
    return 0;
}
