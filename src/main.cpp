#include <windows.h>
#include <conio.h>
#include <iostream>
#include "../include/Header_EDU/MainController.h"

using namespace ANTHinsyOOP;
Edu_Main_Menu menu;	
Sub_ScheduleDesign subSche;
SubMENU_manage_stu_tech subStuTech;
Schedule_Management schdule;

int main() {
    H::DisableScreenResize();	
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45); 
    EDUSYSTEM::displayStartScreen();
    getch();
    return 0;
}
