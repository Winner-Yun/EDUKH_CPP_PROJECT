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
    //   td.teacherManagement();
    // EdumasterCustom::LoadingPage(23,3,140,20);
    //   subSche.Main_ScheduleSubMenu();
             menu.Main_menu();
//    EDUSYSTEM::displayStartScreen();
//        s.Main_StudentManage();
//    Teach_MainMenu::Main("te.yunwinner@gmail.com");
//    schdule.InterfaceADD_update("10");
//    logD.MainLogin();
    // subStuTech.Main_SubMenuMangeStuTech();
    getch();
    return 0;
}
