#ifndef __DESIGN_ASSIGNHOMEWORK__
#define __DESIGN_ASSIGNHOMEWORK__

 #include "ANTHinsyOOP"
using namespace ANTHinsyOOP;

class DesignAssHomework{
	public:
		static void asciiAsignHomework();
		static void AssignHomeworkTable();
		static void designInputHomework();
		static void designWrongInput();
		static void butterFly(int x, int y);
	
};
void DesignAssHomework::butterFly(int x , int y){
        H::gotoxy(x, y);     cout << "==.   .==";
        H::gotoxy(x, y + 1); cout << "`==`o'=='";
        H::gotoxy(x, y + 2); cout << "   (|)";
        H::gotoxy(x, y + 3); cout << "    8";

	
}
void DesignAssHomework::designWrongInput(){
		H::clearBox(50,20,124,21,1);
    	H::gotoxy(62, 27); H::setcolor(4); cout << R"(  _____               _                  _   _       _      _____                     _   _ _ _   )";
		H::gotoxy(62, 28); H::setcolor(4); cout << R"( |_   _|__  __ _  ___| |__   ____ __    | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |  )";
		H::gotoxy(62, 29); H::setcolor(4); cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |  )";
		H::gotoxy(62, 30); H::setcolor(4); cout << R"(   | |  __/ (_| | (__| | | |  __/ |     | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|  )";
		H::gotoxy(62, 31); H::setcolor(4); cout << R"(   |_|\___|\__,_|\___|_| |_|\___| |_|   |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_)  )";
		getch();
}
void DesignAssHomework::designInputHomework(){
	H::clearBox(28,13,146,28,1);
}
void DesignAssHomework::AssignHomeworkTable(){
	H::drawBoxDoubleLine(35,9,40,1,3);
	H::drawBoxDoubleLine(129,9,40,1,3);

	
	H::HLine(30,12,145,151,196);
	H::VLine(30,7,5,151,179);
	H::VLine(175,7,5,145,179);
	H::HLine(29,8,48,151,196);
	H::HLine(128,8,46,151,196);
	
	
	H::drawBoxDoubleLine(30,14,145,27,6);
	H::gotoxy(35,16);cout<<"MON/SAT";
	
	
	H::HLine(30,18,145,6,205);
	H::gotoxy(35,20);cout<<"MONDAY";
	H::HLine(30,22,145,6,205);
	
	H::gotoxy(35,24);cout<<"TUESDAY";
	H::HLine(30,26,145,6,205);
	
	H::gotoxy(35,28);cout<<"WEDNESDAY";
	H::HLine(30,30,145,6,205);
	
	H::gotoxy(35,32);cout<<"THURDAY";
	H::HLine(30,34,145,6,205);
	
	H::gotoxy(35,36);cout<<"FRIDAY";
	H::HLine(30,38,145,6,205);
	
	H::gotoxy(35,40);cout<<"SATURDAY";
	H::HLine(30,42,145,6,205);
	
	
	H::VLine(49,14,27,6,186);
	H::gotoxy(54,16);cout<<"SUBJECT";
	H::VLine(69,14,27,6,186);
	H::gotoxy(74,16);cout<<"DATE SET";
	H::VLine(89,14,27,6,186);
	H::gotoxy(94,16);cout<<"DATE DUE";
	H::VLine(109,14,27,6,186);
	H::gotoxy(128,16);cout<<"TASK";
	H::VLine(156,14,27,6,186);
	H::gotoxy(160,16);cout<<"COMPLETED";

}
void DesignAssHomework::asciiAsignHomework(){
	
	H::setcolor(3);DesignAssHomework::butterFly(2, 1);H::delay(150);
	H::setcolor(3);DesignAssHomework::butterFly(10,5);H::delay(150);
	H::setcolor(3);DesignAssHomework::butterFly(18,1);H::delay(150);
	
	H::setcolor(3);DesignAssHomework::butterFly(170, 1);H::delay(150);
	H::setcolor(3);DesignAssHomework::butterFly(180,5);H::delay(150);
	H::setcolor(3);DesignAssHomework::butterFly(189,1);H::delay(150);
	
    system("chcp 65001  > nul");
    
	H::setcolor(6); H::gotoxy(38, 1); cout << R"( █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗       )";
	H::setcolor(6); H::gotoxy(38, 2); cout << R"( ██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║       )";
	H::setcolor(6); H::gotoxy(38, 3); cout << R"( ███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║       )";
	H::setcolor(6); H::gotoxy(38, 4); cout << R"( ██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║       )";
	H::setcolor(6); H::gotoxy(38, 5); cout << R"( ██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║       )";
	H::setcolor(6); H::gotoxy(38, 6); cout << R"( ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝       )";
	
	H::setcolor(6); H::gotoxy(90, 1); cout << R"( ██╗  ██╗ ██████╗ ███╗   ███╗███████╗██╗    ██╗ ██████╗ ██████╗ ██╗  ██╗ )";
	H::setcolor(6); H::gotoxy(90, 2); cout << R"( ██║  ██║██╔═══██╗████╗ ████║██╔════╝██║    ██║██╔═══██╗██╔══██╗██║ ██╔╝ )";
	H::setcolor(6); H::gotoxy(90, 3); cout << R"( ███████║██║   ██║██╔████╔██║█████╗  ██║ █╗ ██║██║   ██║██████╔╝█████╔╝  )";
	H::setcolor(6); H::gotoxy(90, 4); cout << R"( ██╔══██║██║   ██║██║╚██╔╝██║██╔══╝  ██║███╗██║██║   ██║██╔══██╗██╔═██╗  )";
	H::setcolor(6); H::gotoxy(90, 5); cout << R"( ██║  ██║╚██████╔╝██║ ╚═╝ ██║███████╗╚███╔███╔╝╚██████╔╝██║  ██║██║  ██╗ )";
	H::setcolor(6); H::gotoxy(90, 6); cout << R"( ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ )";

    system("chcp 437 > nul");
    
}



#endif