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

#include "../include/AssignClass/AssignClassDemo.h"


using namespace ANTHinsyOOP;
Login_Design logD;
Edu_Main_Menu menu;	
Sub_ScheduleDesign subSche;
SubMENU_manage_stu_tech subStuTech;
Schedule_Management schdule;



int main() {
    H::DisableScreenResize();	
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45); 
//       td.teacherManagement();
    // EdumasterCustom::LoadingPage(23,3,140,20);
       subSche.Main_ScheduleSubMenu();
    //      menu.Main_menu();
    //     s.Main_StudentManage();
    
    //    logD.MainLogin();
    // subStuTech.Main_SubMenuMangeStuTech();

    //AssignClassDemo::AssignClassMenu();
    AssignClassDesign::AssignGrade10Design();
    
    H::setcolor(9);

    getch();
    return 0;
}
 // One Teacher can add to 2 grade, Ex: add to grade 10 and grade 11,