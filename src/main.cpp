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

using namespace ANTHinsyOOP;
Login_Design logD;
Edu_Main_Menu menu;
Sub_ScheduleDesign subSche;
SubMENU_manage_stu_tech subStuTech;

int main() {
    H::DisableScreenResize();	
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45); 
//    td.teacherManagement();
    // EdumasterCustom::LoadingPage(23,3,140,20);
//   subSche.Main_ScheduleSubMenu();
//      menu.Main_menu();
//     s.Main_StudentManage();
    
   logD.MainLogin();
    // subStuTech.Main_SubMenuMangeStuTech();
    getch();
    return 0;
}
