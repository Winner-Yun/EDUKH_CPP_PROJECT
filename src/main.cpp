#include <windows.h>
#include <conio.h>
#include <iostream>
#include "../include/Header_School/ANTHinsyOOP"
#include "../include/Header_EDU/Login_Form.h"
#include "../include/Header_EDU/Main_menu.h"
#include "../include/Header_EDU/Manage_schedule.h"
#include "../include/Header_EDU/CustomHeader.h"
using namespace ANTHinsyOOP;
Login_Design logD;
MenuDsign menu;
Sub_ScheduleDesign subSche;

int main() {
    H::DisableScreenResize();	
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45); 
    EdumasterCustom::LoadingPage(23,3,140,20);
    // subSche.Header();
    // menu.Main_menu();
    
//    logD.MainLogin();
    getch();
    return 0;
}
