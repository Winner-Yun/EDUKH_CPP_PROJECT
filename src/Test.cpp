#include "../include/Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

void Home(int x, int y);
void Computer(int x, int y);

void Car(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ──▄▄▐▀▀▀▀▀▀▀▀▀▀▀▌▄▄──)";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ─▄▄▄█▄▄▄▄▄▄▄▄▄▄▄█▄▄▄─)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ─█▄█░░█▓█▓█▓█▓█░░█▄█▌)";
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ─▓▓█▀███████████▀█▓▓──)";
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"( ─▓▓▀▀───────────▀▀▓▓──)";
    system("chcp 437 > nul"); 

}

void SortClassText10(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(   █████████     ███████    ███████████   ███████████      █████████  ███████████     █████████   ██████████   ██████████    ████     █████   )";
    H::setcolor(3); H::gotoxy(x,y+1); cout<<R"(  ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░█░░░███░░░█     ███░░░░░███░░███░░░░░███   ███░░░░░███ ░░███░░░░███ ░░███░░░░░█   ░░███   ███░░░███ )";
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( ░███    ░░░  ███     ░░███ ░███    ░███ ░   ░███  ░     ███     ░░░  ░███    ░███  ░███    ░███  ░███   ░░███ ░███  █ ░     ░███  ███   ░░███)";
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ░░█████████ ░███      ░███ ░██████████      ░███       ░███          ░██████████   ░███████████  ░███    ░███ ░██████       ░███ ░███    ░███)";
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"(  ░░░░░░░░███░███      ░███ ░███░░░░░███     ░███       ░███    █████ ░███░░░░░███  ░███░░░░░███  ░███    ░███ ░███░░█       ░███ ░███    ░███)";
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(  ███    ░███░░███     ███  ░███    ░███     ░███       ░░███  ░░███  ░███    ░███  ░███    ░███  ░███    ███  ░███ ░   █    ░███ ░░███   ███ )";
    H::setcolor(3); H::gotoxy(x,y+6); cout<<R"( ░░█████████  ░░░███████░   █████   █████    █████       ░░█████████  █████   █████ █████   █████ ██████████   ██████████    █████ ░░░█████░  )";
    H::setcolor(3); H::gotoxy(x,y+7); cout<<R"(  ░░░░░░░░░     ░░░░░░░    ░░░░░   ░░░░░    ░░░░░         ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░ ░░░░░░░░░░   ░░░░░░░░░░    ░░░░░    ░░░░░░   )";

    system("chcp 437 > nul"); 
}

void SortClassText11(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"(   █████████     ███████    ███████████   ███████████      █████████  ███████████     █████████   ██████████   ██████████    ████  ████)";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"(  ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░█░░░███░░░█     ███░░░░░███░░███░░░░░███   ███░░░░░███ ░░███░░░░███ ░░███░░░░░█   ░░███ ░░███)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ░███    ░░░  ███     ░░███ ░███    ░███ ░   ░███  ░     ███     ░░░  ░███    ░███  ░███    ░███  ░███   ░░███ ░███  █ ░     ░███  ░███)"; 
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ░░█████████ ░███      ░███ ░██████████      ░███       ░███          ░██████████   ░███████████  ░███    ░███ ░██████       ░███  ░███)"; 
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"(  ░░░░░░░░███░███      ░███ ░███░░░░░███     ░███       ░███    █████ ░███░░░░░███  ░███░░░░░███  ░███    ░███ ░███░░█       ░███  ░███)"; 
    H::setcolor(1); H::gotoxy(x,y+5); cout<<R"(  ███    ░███░░███     ███  ░███    ░███     ░███       ░░███  ░░███  ░███    ░███  ░███    ░███  ░███    ███  ░███ ░   █    ░███  ░███)"; 
    H::setcolor(1); H::gotoxy(x,y+6); cout<<R"( ░░█████████  ░░░███████░   █████   █████    █████       ░░█████████  █████   █████ █████   █████ ██████████   ██████████    █████ █████)";
    H::setcolor(1); H::gotoxy(x,y+7); cout<<R"(  ░░░░░░░░░     ░░░░░░░    ░░░░░   ░░░░░    ░░░░░         ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░ ░░░░░░░░░░   ░░░░░░░░░░    ░░░░░ ░░░░░ )";
    
    system("chcp 437 > nul"); 
}

void SortClassText12(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"(   █████████     ███████    ███████████   ███████████      █████████  ███████████     █████████   ██████████   ██████████    ████   ████████ )";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"(  ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░█░░░███░░░█     ███░░░░░███░░███░░░░░███   ███░░░░░███ ░░███░░░░███ ░░███░░░░░█   ░░███  ███░░░░███)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ░███    ░░░  ███     ░░███ ░███    ░███ ░   ░███  ░     ███     ░░░  ░███    ░███  ░███    ░███  ░███   ░░███ ░███  █ ░     ░███ ░░░    ░███)";
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ░░█████████ ░███      ░███ ░██████████      ░███       ░███          ░██████████   ░███████████  ░███    ░███ ░██████       ░███    ███████ )";
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"(  ░░░░░░░░███░███      ░███ ░███░░░░░███     ░███       ░███    █████ ░███░░░░░███  ░███░░░░░███  ░███    ░███ ░███░░█       ░███   ███░░░░  )";
    H::setcolor(1); H::gotoxy(x,y+5); cout<<R"(  ███    ░███░░███     ███  ░███    ░███     ░███       ░░███  ░░███  ░███    ░███  ░███    ░███  ░███    ███  ░███ ░   █    ░███  ███      █)";
    H::setcolor(1); H::gotoxy(x,y+6); cout<<R"( ░░█████████  ░░░███████░   █████   █████    █████       ░░█████████  █████   █████ █████   █████ ██████████   ██████████    █████░██████████)";
    H::setcolor(1); H::gotoxy(x,y+7); cout<<R"(  ░░░░░░░░░     ░░░░░░░    ░░░░░   ░░░░░    ░░░░░         ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░ ░░░░░░░░░░   ░░░░░░░░░░    ░░░░░ ░░░░░░░░░░ )";
    
    system("chcp 437 > nul"); 
}

void SortClassDesign()
{
	//SortClassText10(29,1);
    //SortClassText11(32,1);
    SortClassText12(29,1);
    Car(3,2);
    Car(174,2);
    
    H::HLine(29,10,143,4,219);
    
    for(int i=11; i<17;i++){
    	H::HLine(45,i,2,2,178);
    	H::HLine(154,i,2,2,178);
	}
	
	H::drawBoxDoubleLineWithBG(70,15,61,1,230);
	H::setcolor(225);
    H::gotoxy(90,16); cout<<"Choose Sorting Option";
	H::HLine(47,16,22,2,219);
	H::HLine(132,16,22,2,219);
	
	for(int i=18;i<23;i++) H::HLine(100,i,2,1,219);
	
	H::HLine(45,23,112,3,219);
	
	for(int i=24;i<30;i++){
		H::HLine(45,i,2,1,219); // Start
		H::HLine(118,i,2,1,219); // mid 2
		
	}
	for(int i=24;i<28;i++){
		H::HLine(82,i,2,1,219); // mid 1
		H::HLine(155,i,2,1,219); // End
	}
	
}

void SortMenu(const char* className) {
    int selected = 0; // 0=Small->Big, 1=Big->Small, 2=A-Z, 3=Z-A
    bool running = true;

    // Coordinates for each box (X, Y, Width, Height, TitleX, TitleY)
    struct OptionBox {
        int x, y, w, h;
        int titleX, titleY;
        const char* title;
    } boxes[4] = {
        {29, 30, 32, 1, 30, 31, "Sort by GradeID (Small -> Big)"},
        {66, 28, 32, 1, 67, 29, "Sort by GradeID (Big -> Small)"},
        {102, 30, 32, 1, 103, 31, "Sort by Teacher Name (A-Z)"},
        {139, 28, 32, 1, 140, 29, "Sort by Teacher Name (Z-A)"}
    };

    // Draw static background
    system("cls");
    SortClassDesign();

    // Function to draw all boxes
    auto drawBoxes = [&](int highlightIndex) {
        for (int i = 0; i < 4; i++) {
            // Draw border with different color if selected
            if (i == highlightIndex) {
                H::setcolor(2);
                H::drawBoxDoubleLine(boxes[i].x, boxes[i].y, boxes[i].w, boxes[i].h, 2);
            } else {
                H::setcolor(3);  // Blue border
                H::drawBoxDoubleLine(boxes[i].x, boxes[i].y, boxes[i].w, boxes[i].h, 3);
            }

            // Draw title text
            H::setcolor(i == highlightIndex ? 14 : 7);
            H::gotoxy(boxes[i].titleX, boxes[i].titleY);
            cout << boxes[i].title;
        }
    };

    drawBoxes(selected);

    // Controls hint
    H::setcolor(7);
    H::gotoxy(70, 40);
    cout << "[Arrow Keys] Move   [Enter] Select   [ESC] Exit";

    while (running) {
        int key = _getch();
        if (key == 0 || key == 224) { // Special key
            key = _getch();
            if (key == 75) { // Left arrow
                selected = (selected + 3) % 4; // Wrap around
                drawBoxes(selected);
            }
            else if (key == 77) { // Right arrow
                selected = (selected + 1) % 4; // Wrap around
                drawBoxes(selected);
            }
        }
        else if (key == 13) { // Enter key
            system("cls");
            switch (selected) {
                // case 0: SortByGradeIDAsc(className); break;
                // case 1: SortByGradeID(className); break;
                // case 2: SortByTeacherNameAZ(className); break;
                // case 3: SortByTeacherNameZA(className); break;
            }
            H::gotoxy(70, 40);
            cout << "Press any key to return to sort menu...";
            _getch();

            // Restore menu after sorting
            system("cls");
            SortClassDesign();
            drawBoxes(selected);
            H::setcolor(7);
            H::gotoxy(70, 40);
            cout << "[Arrow Keys] Move   [Enter] Select   [ESC] Exit";
        }
        else if (key == 27) { // ESC key
            running = false;
        }
    }
}



int main()
{
    H::DisableScreenResize();	
    H::DisableButtonMaximized();
    H::setFixedScreenConsole(200,45); 
    H::setFont(16);

	//SortClassDesign();
    SortMenu("10");

    getch();
    return 0;
}



void Home(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(8); H::gotoxy(x,y+0); cout<<R"(▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒)";
    H::setcolor(8); H::gotoxy(x,y+1); cout<<R"(▒▒▄▄▄▒▒▒█▒▒▒▒▄▒▒▒▒▒▒▒▒)";
    H::setcolor(8); H::gotoxy(x,y+3); cout<<R"(▒█▀█▀█▒█▀█▒▒█▀█▒▄███▄▒)";
    H::setcolor(8); H::gotoxy(x,y+2); cout<<R"(░█▀█▀█░█▀██░█▀█░█▄█▄█░)";
    H::setcolor(8); H::gotoxy(x,y+4); cout<<R"(░█▀█▀█░█▀████▀█░█▄█▄█░)";
    H::setcolor(7); H::gotoxy(x,y+5); cout<<R"(████████▀█████████████)";
    system("chcp 437 > nul"); 
}

void Computer(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ▐▓█▀▀▀▀▀▀▀▀▀█▓▌░▄▄▄▄▄░)";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ▐▓█░░▀░░▀▄░░█▓▌░█▄▄▄█░)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ▐▓█░░▄░░▄▀░░█▓▌░█▄▄▄█░)";
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ▐▓█▄▄▄▄▄▄▄▄▄█▓▌░█████░)";
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"( ░░░░▄▄███▄▄░░░░░█████░)";
    system("chcp 437 > nul"); 

}


