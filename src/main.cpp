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
#include "../include/Header_EDU/MainController.h"
#include "../include/Header_Teacher/MainHeaderOFManageScore.h"
#include "../include/Header_Teacher/MainAssignHomwork.h"
#include "../include/Header_Student/Sudent_Menu.h"
#include "../include/Header_EDU/ManageScoreHeader.h"

using namespace ANTHinsyOOP;

Edu_Main_Menu menu;	
Sub_ScheduleDesign subSche;
SubMENU_manage_stu_tech subStuTech;
Schedule_Management schdule;

int main() {
    H::DisableScreenResize();
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45);	
    H::setFont(15);
//     Student_MainMenu::Main("stu.winner@gmail.com");
    // QuizDesign::Quiz_Select();
//       td.teacherManagement();
    // EdumasterCustom::LoadingPage(23,3,140,20);
    //   subSche.Main_ScheduleSubMenu(); 	 
    //MainManageScore::ManageScoreProcess(); 
//      menu.Main_menu();;
//   EDUSYSTEM::DisplayStartScreen();
//      MainAssignHomwork::AssignHMain("T-011");
//     MainAssignHomwork::AssignHMainProcess("T-011","11");
//MainAssignHomwork::AssignHMainProcess("T-011","11","khmer");
    //MainHeaderOFManageScore::ManageScoreMain("T-011","MATH");
//        s.Main_StudentManage();
     Teach_MainMenu::Main("te.yunwinner@gmail.com");
//    schdule.InterfaceADD_update("10");
//  logD.MainLogin();
//     subStuTech.Main_SubMenuMangeStuTech();
    getch();
    return 0;
}
