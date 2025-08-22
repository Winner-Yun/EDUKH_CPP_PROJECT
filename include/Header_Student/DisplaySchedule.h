#ifndef __EDU_DISPLAYSCHEDULE_H__
#define __EDU_DISPLAYSCHEDULE_H__

#include "../Header_School/ANTHinsyOOP"
#include "../Header_EDU/ScheduleForClass.h"

using namespace ANTHinsyOOP;

class DisplaySchedule{
public:
    static void DesignMain(const char* grade);  /* Desing Main */
    static  void Title_heading(const char* grade);
    static  void DisplaySchecduleIF();
};


void DisplaySchedule::DesignMain(const char* grade){    // Main Call By Grade of class
    int option;
    int choice = 1;
    H::setcursor(false, 0);
    do{
        Title_heading(grade);
        DisplaySchecduleIF();
        scmanage.ReadFile_Display(grade);
        option = getch();
    }while(option != 27);
}

void DisplaySchedule::Title_heading(const char* grade){
    // title
    if (strcmp(grade, "10") == 0) {
        H::setcolor(1);H::gotoxy(37,0);cout<<R"(  /\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\  )";
        H::setcolor(0);H::gotoxy(37,1);cout<<R"(     ////////////__\///////////////__\///////////////__\///////////////__\///////////////__\///////////////__\//////////////   )";
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(36,1);cout<<R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██████╗     ███████╗ ██████╗██╗  ██╗███████╗██████╗ ██╗   ██╗██╗     ███████╗  )";
        H::setcolor(1);H::gotoxy(36,2);cout<<R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║██╔═████╗    ██╔════╝██╔════╝██║  ██║██╔════╝██╔══██╗██║   ██║██║     ██╔════╝  )";
        H::setcolor(1);H::gotoxy(36,3);cout<<R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║██║██╔██║    ███████╗██║     ███████║█████╗  ██║  ██║██║   ██║██║     █████╗    )";
        H::setcolor(2);H::gotoxy(36,4);cout<<R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║████╔╝██║    ╚════██║██║     ██╔══██║██╔══╝  ██║  ██║██║   ██║██║     ██╔══╝    )";
        H::setcolor(2);H::gotoxy(36,5);cout<<R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║╚██████╔╝    ███████║╚██████╗██║  ██║███████╗██████╔╝╚██████╔╝███████╗███████╗  )";
        H::setcolor(2);H::gotoxy(36,6);cout<<R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═════╝     ╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚══════╝╚══════╝   )";
        system("chcp 437 >nul");                                                              
        H::setcolor(7);H::gotoxy(0,9);cout<<"=================================================================>|                                                              |<=====================================================================";
        H::drawBoxDoubleLineWithBG(70,8,56,1,79);
        H::gotoxy(79,9);H::setcolor(79);cout<<"PRESS ~ ESC KEY ~ TO BACK TO MAIN MENU";
    }
    
     else if (strcmp(grade, "11") == 0) {
            H::setcolor(2);H::gotoxy(37,0);cout<<R"(  /\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\  )";
            H::setcolor(0);H::gotoxy(37,1);cout<<R"(     ////////////__\///////////////__\///////////////__\///////////////__\///////////////__\///////////////__\//////////////   )";
            system("chcp 65001 > nul");
            H::setcolor(2);H::gotoxy(39,1);cout<<R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██╗    ███████╗ ██████╗██╗  ██╗███████╗██████╗ ██╗   ██╗██╗     ███████╗ )";
            H::setcolor(2);H::gotoxy(39,2);cout<<R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║███║    ██╔════╝██╔════╝██║  ██║██╔════╝██╔══██╗██║   ██║██║     ██╔════╝ )";
            H::setcolor(2);H::gotoxy(39,3);cout<<R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║╚██║    ███████╗██║     ███████║█████╗  ██║  ██║██║   ██║██║     █████╗   )";
            H::setcolor(1);H::gotoxy(39,4);cout<<R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║ ██║    ╚════██║██║     ██╔══██║██╔══╝  ██║  ██║██║   ██║██║     ██╔══╝   )";
            H::setcolor(1);H::gotoxy(39,5);cout<<R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║ ██║    ███████║╚██████╗██║  ██║███████╗██████╔╝╚██████╔╝███████╗███████  )";
            H::setcolor(1);H::gotoxy(39,6);cout<<R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═╝    ╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚══════╝╚══════  )";
            system("chcp 437 >nul");                                                              

            H::setcolor(7);H::gotoxy(0,9);cout<<"=================================================================>|                                                              |<=====================================================================";
            H::drawBoxDoubleLineWithBG(70,8,56,1,79);
            H::gotoxy(79,9);H::setcolor(79);cout<<"PRESS ~ ESC KEY ~ TO BACK TO MAIN MENU";

        }
        else if (strcmp(grade, "12") == 0) {
            H::setcolor(6);H::gotoxy(37,0);cout<<R"(  /\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\  )";
            H::setcolor(0);H::gotoxy(37,1);cout<<R"(     ////////////__\///////////////__\///////////////__\///////////////__\///////////////__\///////////////__\//////////////   )";
            system("chcp 65001 > nul");
            
            H::setcolor(6);H::gotoxy(37,1);cout<<R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗██████╗     ███████╗ ██████╗██╗  ██╗███████╗██████╗ ██╗   ██╗██╗     ███████╗  )";
            H::setcolor(6);H::gotoxy(37,2);cout<<R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║╚════██╗    ██╔════╝██╔════╝██║  ██║██╔════╝██╔══██╗██║   ██║██║     ██╔════╝  )";
            H::setcolor(6);H::gotoxy(37,3);cout<<R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║ █████╔╝    ███████╗██║     ███████║█████╗  ██║  ██║██║   ██║██║     █████╗    )";
            H::setcolor(4);H::gotoxy(37,4);cout<<R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║██╔═══╝     ╚════██║██║     ██╔══██║██╔══╝  ██║  ██║██║   ██║██║     ██╔══╝    )";
            H::setcolor(4);H::gotoxy(37,5);cout<<R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║███████╗    ███████║╚██████╗██║  ██║███████╗██████╔╝╚██████╔╝███████╗███████╗  )";
            H::setcolor(4);H::gotoxy(37,6);cout<<R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝╚══════╝    ╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚══════╝╚══════╝  )";
                                                                                                                              

            system("chcp 437 >nul");                                                              

            H::setcolor(7);H::gotoxy(0,9);cout<<"=================================================================>|                                                              |<=====================================================================";
            H::drawBoxDoubleLineWithBG(70,8,56,1,79);
            H::gotoxy(79,9);H::setcolor(79);cout<<"PRESS ~ ESC KEY ~ TO BACK TO MAIN MENU";
        }

}

   void DisplaySchedule::DisplaySchecduleIF(){

        H::drawBoxSingleLine(5, 11, 190, 32, 9);

        H::drawBoxSingleLineWithBG(10, 12, 20, 1, 224);
        H::setcolor(236); 
        H::gotoxy(10 + (20 - 4) / 2, 13); cout << "TIME";

        int headerColors = 27; 
        int textColor    = 31; 
        string days[6] = {"MON","TUE","WED","THU","FRI","SAT"};
        int x = 33;
        for (int i = 0; i < 6; i++, x += 23) {
            H::drawBoxSingleLineWithBG(x, 12, 20, 1, headerColors);
            H::setcolor(textColor); 
            H::gotoxy(x + (20 - days[i].size()) / 2, 13); cout << days[i];
        }

        H::drawBoxSingleLineWithBG(171, 12, 20, 1, 34);
        H::setcolor(47); 
        H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";

        H::setcolor(11);
        H::gotoxy(9,30);  cout<<R"( \________||________/ )";
        H::gotoxy(32,30); cout<<R"( \________||________/ )";
        H::gotoxy(55,30); cout<<R"( \________||________/ )";
        H::gotoxy(78,30); cout<<R"( \________||________/ )";
        H::gotoxy(101,30);cout<<R"( \________||________/ )";
        H::gotoxy(124,30);cout<<R"( \________||________/ )";
        H::gotoxy(147,30);cout<<R"( \________||________/ )";

        H::drawBoxSingleLineWithBG(171, 29, 20, 1, 202);
        H::setcolor(207); 
        H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";

        H::drawBoxSingleLine(10,15,20,1,8);

        
        //morning
        H::drawBoxSingleLine(10,18,20,1,0);
        H::drawBoxSingleLine(10,21,20,1,0);
        H::drawBoxSingleLine(10,24,20,1,0);
        H::drawBoxSingleLine(10,27,20,1,0);
        
        H::drawBoxSingleLine(33,15,20,1,0);
        H::drawBoxSingleLine(33,18,20,1,0);
        H::drawBoxSingleLine(33,21,20,1,0);
        H::drawBoxSingleLine(33,24,20,1,0);
        H::drawBoxSingleLine(33,27,20,1,0);

        H::drawBoxSingleLine(56,15,20,1,0);
        H::drawBoxSingleLine(56,18,20,1,0);
        H::drawBoxSingleLine(56,21,20,1,0);
        H::drawBoxSingleLine(56,24,20,1,0);
        H::drawBoxSingleLine(56,27,20,1,0);

        H::drawBoxSingleLine(79,15,20,1,0);
        H::drawBoxSingleLine(79,18,20,1,0);
        H::drawBoxSingleLine(79,21,20,1,0);
        H::drawBoxSingleLine(79,24,20,1,0);
        H::drawBoxSingleLine(79,27,20,1,0);

        H::drawBoxSingleLine(102,15,20,1,0);
        H::drawBoxSingleLine(102,18,20,1,0);
        H::drawBoxSingleLine(102,21,20,1,0);
        H::drawBoxSingleLine(102,24,20,1,0);
        H::drawBoxSingleLine(102,27,20,1,0);

        H::drawBoxSingleLine(125,15,20,1,0);
        H::drawBoxSingleLine(125,18,20,1,0);
        H::drawBoxSingleLine(125,21,20,1,0);
        H::drawBoxSingleLine(125,24,20,1,0);
        H::drawBoxSingleLine(125,27,20,1,0);

        H::drawBoxSingleLine(148,15,20,1,0);
        H::drawBoxSingleLine(148,18,20,1,0);
        H::drawBoxSingleLine(148,21,20,1,0);
        H::drawBoxSingleLine(148,24,20,1,0);
        H::drawBoxSingleLine(148,27,20,1,0);

        //afternoon
        H::drawBoxSingleLine(10,32,20,1,0);
        H::drawBoxSingleLine(10,35,20,1,0);
        H::drawBoxSingleLine(10,38,20,1,0);
        H::drawBoxSingleLine(10,41,20,1,0);
    
        H::drawBoxSingleLine(33,32,20,1,0);
        H::drawBoxSingleLine(33,35,20,1,0);
        H::drawBoxSingleLine(33,38,20,1,0);
        H::drawBoxSingleLine(33,41,20,1,0);
    
        H::drawBoxSingleLine(56,32,20,1,0);
        H::drawBoxSingleLine(56,35,20,1,0);
        H::drawBoxSingleLine(56,38,20,1,0);
        H::drawBoxSingleLine(56,41,20,1,0);
    
        H::drawBoxSingleLine(79,32,20,1,0);
        H::drawBoxSingleLine(79,35,20,1,0);
        H::drawBoxSingleLine(79,38,20,1,0);
        H::drawBoxSingleLine(79,41,20,1,0);
    
        H::drawBoxSingleLine(102,32,20,1,0);
        H::drawBoxSingleLine(102,35,20,1,0);
        H::drawBoxSingleLine(102,38,20,1,0);
        H::drawBoxSingleLine(102,41,20,1,0);
    
        H::drawBoxSingleLine(125,32,20,1,0);
        H::drawBoxSingleLine(125,35,20,1,0);
        H::drawBoxSingleLine(125,38,20,1,0);
        H::drawBoxSingleLine(125,41,20,1,0);
    
        H::drawBoxSingleLine(148,32,20,1,0);
        H::drawBoxSingleLine(148,35,20,1,0);
        H::drawBoxSingleLine(148,38,20,1,0);
        H::drawBoxSingleLine(148,41,20,1,0);

        H::setcolor(6);H::gotoxy(170,15);cout<<R"(         _____          )";
        H::setcolor(6);H::gotoxy(170,16);cout<<R"(      _.'_____`._       )";
        H::setcolor(6);H::gotoxy(170,17);cout<<R"(    .'.-'  12 `-.`.     )";
        H::setcolor(6);H::gotoxy(170,18);cout<<R"(   /,' 11      1 `.\    )";
        H::setcolor(6);H::gotoxy(170,19);cout<<R"(  // 10          2 \\   )";
        H::setcolor(6);H::gotoxy(170,20);cout<<R"( ;;                 ::  )";
        H::setcolor(6);H::gotoxy(170,21);cout<<R"( || 9     A M     3 ||  )";
        H::setcolor(6);H::gotoxy(170,22);cout<<R"( ::                 ;;  )";
        H::setcolor(6);H::gotoxy(170,23);cout<<R"(  \\ 8           4 //   )";
        H::setcolor(6);H::gotoxy(170,24);cout<<R"(   \`. 7       5 ,'/    )";
        H::setcolor(6);H::gotoxy(170,25);cout<<R"(    '.`-.__6__.-'.'     )";
        H::setcolor(7);H::gotoxy(170,26);cout<<R"(     ((-._____.-))      )";
        H::setcolor(0);H::gotoxy(170,27);cout<<R"(         _____          )";
        

        H::setcolor(3);H::gotoxy(170,32);cout<<R"(         _____          )";
        H::setcolor(3);H::gotoxy(170,33);cout<<R"(      _.'_____`._       )";
        H::setcolor(3);H::gotoxy(170,34);cout<<R"(    .'.-'  12 `-.`.     )";
        H::setcolor(3);H::gotoxy(170,35);cout<<R"(   /,' 11      1 `.\    )";
        H::setcolor(3);H::gotoxy(170,36);cout<<R"(  // 10          2 \\   )";
        H::setcolor(3);H::gotoxy(170,37);cout<<R"( ;;                 ::  )";
        H::setcolor(3);H::gotoxy(170,38);cout<<R"( || 9     P M     3 ||  )";
        H::setcolor(3);H::gotoxy(170,39);cout<<R"( ::                 ;;  )";
        H::setcolor(3);H::gotoxy(170,40);cout<<R"(  \\ 8           4 //   )";
        H::setcolor(3);H::gotoxy(170,41);cout<<R"(   \`. 7       5 ,'/    )";
        H::setcolor(3);H::gotoxy(170,42);cout<<R"(    '.`-.__6__.-'.'     )";
        H::setcolor(7);H::gotoxy(170,43);cout<<R"(     ((-._____.-))      )";

    }
#endif