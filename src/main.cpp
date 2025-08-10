#include <windows.h>
#include <conio.h>
#include <iostream>
#include "../include/Header_School/ANTHinsyOOP"
#include "../include/Header_EDU/Login_Form.h"
#include "../include/Header_EDU/Main_menu.h"
#include "../include/Header_EDU/Manage_schedule.h"
#include "../include/Header_EDU/CustomHeader.h"
#include "../include/Header_EDU/StudentManagerment.h"
#include "../include/Header_EDU/Manage_student_teacher_menu.h"
#include "../include/Header_EDU/TeacherManagement.h"
#include "../include/Header_EDU/ScheduleForClass.h"
#include "../include/Header_Teacher/Teach_MainMenu.h"
// #include "../include/Header_EDU/mainController.h"
#include "../include/Header_EDU/Main_AssHomework.h"

using namespace ANTHinsyOOP;
Login_Design logD;
Edu_Main_Menu menu;	
Sub_ScheduleDesign subSche;
SubMENU_manage_stu_tech subStuTech;
Schedule_Management schdule;

int main() {
    H::DisableScreenResize();	
    H::DisableButtonMaximized();
<<<<<<< Updated upstream
    H::setFixedScreenConsole(200,45);
//	abu.displayStartScreen(); 
//       AboutUs::openAboutUsPage();
//	Teach_MainMenu::Main("te.yunwinner@gmail.com");
//       td.teacherManagement();
    // EdumasterCustom::LoadingPage(23,3,140,20);
    //   subSche.Main_ScheduleSubMenu();
//          menu.Main_menu();
=======
    H::setFixedScreenConsole(200,45); 
    //td.teacherManagement();
    // EdumasterCustom::LoadingPage(23,3,140,20);
    //   subSche.Main_ScheduleSubMenu();
    //      menu.Main_menu();
>>>>>>> Stashed changes
    //     s.Main_StudentManage();
     Teach_MainMenu::Main("te.yunwinner@gmail.com");
//    schdule.InterfaceADD_update("10");
//    logD.MainLogin();
    // subStuTech.Main_SubMenuMangeStuTech();
<<<<<<< Updated upstream
    getch();
    return 0;
}
=======

    AssignClassDemo::AssignClassMenu();
    //AssignClassDesign::AssignGrade10Design();
    
    H::setcolor(9);

    getch();
    return 0;
}


>>>>>>> Stashed changes
