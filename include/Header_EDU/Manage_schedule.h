#ifndef ___SUB_MENU_SCHEDULE_CPP_HEADER__
#define ___SUB_MENU_SCHEDULE_CPP_HEADER__

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;
class Sub_ScheduleDesign{
    public:
        void Main_SubMenu();
        static void Header();
        static void Menu_Body();
        static void Footer();
};

void Sub_ScheduleDesign::Header(){

    H::VLine(23,7,5,6,186);//chain
    H::VLine(175,7,5,6,186);//chain

    H::drawBoxDoubleLineWithBG(3,0,194,6,10);
    H::drawBoxSingleLineWithBG(3,5,48,1,7);
    H::drawBoxSingleLineWithBG(149,5,48,1,7); 
           
    H::setcolor(10);H::gotoxy(52,2);cout<<R"(                                                                                                )";
    H::setcolor(10);H::gotoxy(52,3);cout<<R"(     ______  ______  _____ ______  ______ ________            _______ ________________________  )";
    H::setcolor(10);H::gotoxy(52,4);cout<<R"( __  ____/__  / / /_  __ \_  __ \_  ___/__  ____/          __  ____/__  /___    |_  ___/_  ___/ )";
    H::setcolor(7);H::gotoxy(52,5);cout<<R"( _  /    __  /_/ /_  / / /  / / /____ \__  __/             _  /    __  / __  /| |____ \_____ \  )";
    H::setcolor(7);H::gotoxy(52,6);cout<<R"( / /___  _  __  / / /_/ // /_/ /____/ /_  /___             / /___  _  /___  ___ |___/ /____/ /  )";
    H::setcolor(7);H::gotoxy(52,7);cout<<R"( \____/  /_/ /_/  \____/ \____/ /____/ /_____/             \____/  /_____/_/  |_/____/ /____/   )";
    H::setcolor(2);H::gotoxy(52,8);cout<<R"(________________________________________________________________________________________________)";


    //left
    H::drawBoxSingleLineWithBG(3, 11, 1, 21, 10);
    H::drawBoxSingleLineWithBG(42, 11, 1, 21, 10);

    H::drawBoxSingleLineWithBG(3, 11, 40, 3, 6);
    H::setcolor(2);H::gotoxy(8,12);cout<<"------------------->>>>>>>>>>>";
    H::setcolor(2);H::gotoxy(8,13);cout<<"ASSIGN SHCEDULE FOR EACH CLASS";
    H::setcolor(2);H::gotoxy(8,14);cout<<"___________________>>>>>>>>>>>";
    H::drawBoxSingleLineWithBG(3, 29, 40, 3, 10);

    H::setcolor(6); H::gotoxy(15, 24); cout << R"(      /\   |~\ )";
    H::setcolor(6); H::gotoxy(15, 25); cout << R"(    [__]---'__] )";
    H::setcolor(6); H::gotoxy(15, 26); cout << R"(    |""|'''|""| )";
    H::setcolor(6); H::gotoxy(15, 27); cout << R"(    |  | /^\  | )";
    H::setcolor(7); H::gotoxy(15, 28); cout << R"(   _|__|_I_|__|_ )";
    H::setcolor(8); H::gotoxy(15, 29); cout << R"(  /_____________\)";

    H::setcolor(6); H::gotoxy(8, 17);  cout << R"(     \  |  /     )";
    H::setcolor(6); H::gotoxy(8, 18);  cout << R"(      .---.      )";
    H::setcolor(6); H::gotoxy(8, 19);  cout << R"(  -- (     ) --   )";
    H::setcolor(6); H::gotoxy(8, 20);  cout << R"(      '---'      )";
    H::setcolor(6); H::gotoxy(8, 21);  cout << R"(     /  |  \     )";

    H::setcolor(7); H::gotoxy(16, 19); cout << R"(      .--.    )";
    H::setcolor(7); H::gotoxy(16, 20); cout << R"(   .-(    ).  )";
    H::setcolor(7); H::gotoxy(16, 21); cout << R"(  (___.__)__) )";


    //right
    H::drawBoxSingleLineWithBG(155, 11, 1, 21, 10);
    H::drawBoxSingleLineWithBG(194, 11, 1, 21, 10);

    H::drawBoxSingleLineWithBG(155, 11, 40, 3, 6);
    H::setcolor(2);H::gotoxy(160,12);cout<<"<<<<<<<<<<<-------------------";
    H::setcolor(2);H::gotoxy(160,13);cout<<"  CHOOSE ONE CLSSS TO ASSIGN  ";
    H::setcolor(2);H::gotoxy(160,14);cout<<"<<<<<<<<<<<___________________";
    H::drawBoxSingleLineWithBG(155, 29, 40, 3, 10);

    H::setcolor(6); H::gotoxy(167, 24); cout << R"(      /\   |~\ )";
    H::setcolor(6); H::gotoxy(167, 25); cout << R"(    [__]---'__] )";
    H::setcolor(6); H::gotoxy(167, 26); cout << R"(    |""|'''|""| )";
    H::setcolor(6); H::gotoxy(167, 27); cout << R"(    |  | /^\  | )";
    H::setcolor(7); H::gotoxy(167, 28); cout << R"(   _|__|_I_|__|_ )";
    H::setcolor(8); H::gotoxy(167, 29); cout << R"(  /_____________\)";

    H::setcolor(7); H::gotoxy(157, 16);  cout << R"(       _.._   )";
    H::setcolor(7); H::gotoxy(157, 17);  cout << R"(    .' .-'`   )";
    H::setcolor(7); H::gotoxy(157, 18);  cout << R"(   /  /       )";
    H::setcolor(7); H::gotoxy(157, 19);  cout << R"(  |  |        )";
    H::setcolor(7); H::gotoxy(157, 20);  cout << R"(   \  \       )";
    H::setcolor(7); H::gotoxy(157, 21);  cout << R"(    '._'-._   )";
    H::setcolor(7); H::gotoxy(157, 22);  cout << R"(       ```    )";

    H::setcolor(7); H::gotoxy(180, 17); cout << R"(*)";
    H::setcolor(7); H::gotoxy(175, 19); cout << R"(*)";
    H::setcolor(7); H::gotoxy(190, 19); cout << R"(*)";
    H::setcolor(7); H::gotoxy(185, 20); cout << R"(*)";


    



    H::drawBoxDoubleLineWithBG(3,37,194,6,47);
    H::drawBoxSingleLineWithBG(3,37,55,1,2); //bottom
    H::drawBoxSingleLineWithBG(142,37,55,1,2); 

}




#endif