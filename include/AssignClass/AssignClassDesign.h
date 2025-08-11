#ifndef __ASSIGNCLASSDESIGN__
#define __ASSIGNCLASSDESIGN__

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class AssignClassDesign{
    public:
        static void AssignClassLogo(int x, int y);
        static void KBText(int x, int y);
        // Grade 10 Design ------------------------------------------------------------------------------------------------------------------------
        static void AssignGrade10Banner(int x, int y);
        static void AssignGrade10Design();
        // Grade 11 Design ------------------------------------------------------------------------------------------------------------------------
        static void AssignGrade11Banner(int x, int y);
        static void AssignGrade11Design();
        // Grade 12 Design ------------------------------------------------------------------------------------------------------------------------
        static void AssignGrade12Banner(int x, int y);
        static void AssignGrade12Design();
        // ------------------------------------------------------------------------------------------------------------------------
        static void AssignTeacherText(int x, int y);
        static void AssignTeacherDesign();
        static void G10(int x, int y);
        static void G11(int x, int y);
        static void G12(int x, int y);
        // Header ------------------------------------------------------------------------------------------------------------------------
        static void Header(int y);
        static void Footer();
        // Delete Design ------------------------------------------------------------------------------------------------------------------------
        static void DeleteClassText(int x, int y);
        static void Grade10Text(int x, int y);
        static void Grade11Text(int x, int y);
        static void Grade12Text(int x, int y);
        static void Home(int x, int y);
        static void Computer(int x, int y);
        static void DeleteClassDesign();
        // Sort Design ------------------------------------------------------------------------------------------------------------------------
        static void Car(int x, int y);
        static void SortClassText10(int x, int y);
        static void SortClassText11(int x, int y);
        static void SortClassText12(int x, int y);
        static void SortClassDesign();
        static void SortLoading();
        static void SortGradeIDText(int x, int y);
        static void SmallToBigText(int x, int y);
        static void BigToSmallText(int x, int y);
        static void SortTeacherNameText(int x, int y);
        static void ZToAText(int x, int y);
        static void AToZText(int x, int y);
        // Search Design ------------------------------------------------------------------------------------------------------------------------
        static void SearchClassText(int x, int y);
        static void SearchNotFound(int x, int y);
        static void SearchDesign();
        static void SearchTable();
};

void AssignClassDesign::SearchTable()
{
    Header(18);
	H::drawBoxSingleLine(30, 17, 140, 1,6); //  Table Header
    H::drawBoxSingleLine(30, 17, 140, 22,9); // Table Body Design
}

void AssignClassDesign::SearchDesign()
{
	SearchClassText(29,1);
	
    H::HLine(0,5,28,1,178);
    H::HLine(172,5,28,1,178);
    
    for(int i=6;i<45;i++){
    	H::HLine(0,i,2,1,178);
    	H::HLine(198,i,2,1,178);
	}
	H::HLine(2,44,196,1,178);
	
	//Field
	H::drawBoxDoubleLine(60,11,80,3,232);
	H::setcolor(7);
	H::gotoxy(61,13); cout<<"Enter Teacher Name To Search: ";

    // Header(18);
	// H::drawBoxSingleLine(30, 17, 140, 1,6); //  Table Header
    // H::drawBoxSingleLine(30, 17, 140, 22,9); // Table Body Design
    
    H::drawBoxSingleLineWithBG(30, 42,140,1,187);
    H::setcolor(191);
    H::gotoxy(75,43); cout << "Press any key to search again, or ESC to return...";
	
	//SearchNotFound(32,25);
}


void AssignClassDesign::SearchClassText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(   ▄████████    ▄████████    ▄████████    ▄████████  ▄████████    ▄█    █▄          ▄████████  ▄█          ▄████████    ▄████████    ▄████████)";
    H::setcolor(3); H::gotoxy(x,y+1); cout<<R"(  ███    ███   ███    ███   ███    ███   ███    ███ ███    ███   ███    ███        ███    ███ ███         ███    ███   ███    ███   ███    ███)";
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"(  ███    █▀    ███    █▀    ███    ███   ███    ███ ███    █▀    ███    ███        ███    █▀  ███         ███    ███   ███    █▀    ███    █▀ )";
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"(  ███         ▄███▄▄▄       ███    ███  ▄███▄▄▄▄██▀ ███         ▄███▄▄▄▄███▄▄      ███        ███         ███    ███   ███          ███       )";
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"(▀███████████ ▀▀███▀▀▀     ▀███████████ ▀▀███▀▀▀▀▀   ███        ▀▀███▀▀▀▀███▀       ███        ███       ▀███████████ ▀███████████ ▀███████████)";
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(         ███   ███    █▄    ███    ███ ▀███████████ ███    █▄    ███    ███        ███    █▄  ███         ███    ███          ███          ███)";
    H::setcolor(3); H::gotoxy(x,y+6); cout<<R"(   ▄█    ███   ███    ███   ███    ███   ███    ███ ███    ███   ███    ███        ███    ███ ███▌    ▄   ███    ███    ▄█    ███    ▄█    ███)";
    H::setcolor(3); H::gotoxy(x,y+7); cout<<R"( ▄████████▀    ██████████   ███    █▀    ███    ███ ████████▀    ███    █▀         ████████▀  █████▄▄██   ███    █▀   ▄████████▀   ▄████████▀ )";
    H::setcolor(3); H::gotoxy(x,y+8); cout<<R"(                                         ███    ███                                           ▀                                               )";
    
    system("chcp 437 > nul"); 
}

void AssignClassDesign::SearchNotFound(int x, int y)
{
	system("chcp 65001  > nul");

    H::setcolor(4); H::gotoxy(x,y+0); cout<<R"( ███    ██  ██████      ████████ ███████  █████   ██████ ██   ██ ███████ ██████  ███████     ███████  ██████  ██    ██ ███    ██ ██████ )"; 
    H::setcolor(4); H::gotoxy(x,y+1); cout<<R"( ████   ██ ██    ██        ██    ██      ██   ██ ██      ██   ██ ██      ██   ██ ██          ██      ██    ██ ██    ██ ████   ██ ██   ██)";
    H::setcolor(4); H::gotoxy(x,y+2); cout<<R"( ██ ██  ██ ██    ██        ██    █████   ███████ ██      ███████ █████   ██████  ███████     █████   ██    ██ ██    ██ ██ ██  ██ ██   ██)"; 
    H::setcolor(4); H::gotoxy(x,y+3); cout<<R"( ██  ██ ██ ██    ██        ██    ██      ██   ██ ██      ██   ██ ██      ██   ██      ██     ██      ██    ██ ██    ██ ██  ██ ██ ██   ██)"; 
    H::setcolor(4); H::gotoxy(x,y+4); cout<<R"( ██   ████  ██████         ██    ███████ ██   ██  ██████ ██   ██ ███████ ██   ██ ███████     ██       ██████   ██████  ██   ████ ██████  ██)"; 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    system("chcp 437 > nul");                                                                                                                                                                                                                                                                                                                                  
}

void AssignClassDesign::SortLoading()
{
    const int barWidth = 114;   // Adjusted size
    const int barX = 43;       // Starting X
    const int barY = 25;       // Box Y position
    const int textY = 24;      // Text line above the box

    // Print "Loading..." on the left above the bar
    H::setcolor(14);
    H::gotoxy(barX, textY);
    cout << "Loading...";

    // Print initial "0%" on the right above the bar
    H::gotoxy(barX + barWidth - 3, textY);
    cout << "0%";

    // Draw outer box for progress bar
    H::drawBoxDoubleLine(barX, barY, barWidth, 1, 8);

    // Fill the progress bar gradually
    for (int i = 0; i <= barWidth; i++)
    {
        // Draw filled part inside the box
        H::HLine(barX, barY + 1, i, 10, 178);

        // Calculate and update percentage above the bar
        int percent = (i * 100) / barWidth;
        H::setcolor(14);
        H::gotoxy(barX + barWidth - 3, textY);
        cout << setw(3) << percent << "%";

        Sleep(20);
    }

    // Change "Loading..." to green when complete
    H::setcolor(10);
    H::gotoxy(barX, textY);
    cout << "Loading Complete!";
}

void AssignClassDesign::SortTeacherNameText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ███████╗ ██████╗ ██████╗ ████████╗    ██████╗ ██╗   ██╗    ████████╗███████╗ █████╗  ██████╗██╗  ██╗███████╗██████╗     ███╗   ██╗ █████╗ ███╗   ███╗███████╗)";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝    ██╔══██╗╚██╗ ██╔╝    ╚══██╔══╝██╔════╝██╔══██╗██╔════╝██║  ██║██╔════╝██╔══██╗    ████╗  ██║██╔══██╗████╗ ████║██╔════╝)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ███████╗██║   ██║██████╔╝   ██║       ██████╔╝ ╚████╔╝        ██║   █████╗  ███████║██║     ███████║█████╗  ██████╔╝    ██╔██╗ ██║███████║██╔████╔██║█████╗  )";
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ╚════██║██║   ██║██╔══██╗   ██║       ██╔══██╗  ╚██╔╝         ██║   ██╔══╝  ██╔══██║██║     ██╔══██║██╔══╝  ██╔══██╗    ██║╚██╗██║██╔══██║██║╚██╔╝██║██╔══╝  )";
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"( ███████║╚██████╔╝██║  ██║   ██║       ██████╔╝   ██║          ██║   ███████╗██║  ██║╚██████╗██║  ██║███████╗██║  ██║    ██║ ╚████║██║  ██║██║ ╚═╝ ██║███████╗)";
    H::setcolor(1); H::gotoxy(x,y+5); cout<<R"( ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚═════╝    ╚═╝          ╚═╝   ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝)";

    system("chcp 437 > nul"); 
}

void AssignClassDesign::AToZText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(6); H::gotoxy(x,y+0); cout<<R"(  ██╗ █████╗          ██╗      ███████╗██╗ )";
    H::setcolor(6); H::gotoxy(x,y+1); cout<<R"( ██╔╝██╔══██╗         ╚██╗     ╚══███╔╝╚██╗)";
    H::setcolor(6); H::gotoxy(x,y+2); cout<<R"( ██║ ███████║    █████╗╚██╗      ███╔╝  ██║)";
    H::setcolor(6); H::gotoxy(x,y+3); cout<<R"( ██║ ██╔══██║    ╚════╝██╔╝     ███╔╝   ██║)";
    H::setcolor(6); H::gotoxy(x,y+4); cout<<R"( ╚██╗██║  ██║         ██╔╝     ███████╗██╔╝)";
    H::setcolor(6); H::gotoxy(x,y+5); cout<<R"( ╚═╝╚═╝  ╚═╝         ╚═╝      ╚══════╝╚═╝  )";
    
    system("chcp 437 > nul");                                                                                        
}

void AssignClassDesign::ZToAText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(6); H::gotoxy(x,y+0); cout<<R"(  ██╗███████╗         ██╗       █████╗ ██╗ )";
    H::setcolor(6); H::gotoxy(x,y+1); cout<<R"( ██╔╝╚══███╔╝         ╚██╗     ██╔══██╗╚██╗)";
    H::setcolor(6); H::gotoxy(x,y+2); cout<<R"( ██║   ███╔╝     █████╗╚██╗    ███████║ ██║)";
    H::setcolor(6); H::gotoxy(x,y+3); cout<<R"( ██║  ███╔╝      ╚════╝██╔╝    ██╔══██║ ██║)";
    H::setcolor(6); H::gotoxy(x,y+4); cout<<R"( ╚██╗███████╗         ██╔╝     ██║  ██║██╔╝)";
    H::setcolor(6); H::gotoxy(x,y+5); cout<<R"(  ╚═╝╚══════╝         ╚═╝      ╚═╝  ╚═╝╚═╝ )";
    
    system("chcp 437 > nul");                                                                                        
}

void AssignClassDesign::SortGradeIDText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(3); H::gotoxy(x,y+0); cout<<R"( ███████╗ ██████╗ ██████╗ ████████╗    ██████╗ ██╗   ██╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗  ██╗██████╗  )";    
    H::setcolor(3); H::gotoxy(x,y+1); cout<<R"( ██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝    ██╔══██╗╚██╗ ██╔╝    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝  ██║██╔══██╗ )";   
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( ███████╗██║   ██║██████╔╝   ██║       ██████╔╝ ╚████╔╝     ██║  ███╗██████╔╝███████║██║  ██║█████╗    ██║██║  ██║ )";   
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ╚════██║██║   ██║██╔══██╗   ██║       ██╔══██╗  ╚██╔╝      ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝    ██║██║  ██║ )";   
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ███████║╚██████╔╝██║  ██║   ██║       ██████╔╝   ██║       ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗  ██║██████╔╝ )";   
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"( ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚═════╝    ╚═╝        ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝  ╚═╝╚═════╝  )";
                                                                                                                                                                                                            
    system("chcp 437 > nul"); 
}

void AssignClassDesign::BigToSmallText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(  ██╗██████╗ ██╗ ██████╗          ██╗      ███████╗███╗   ███╗ █████╗ ██╗     ██╗     ██╗ )";
    H::setcolor(3); H::gotoxy(x,y+1); cout<<R"( ██╔╝██╔══██╗██║██╔════╝          ╚██╗     ██╔════╝████╗ ████║██╔══██╗██║     ██║     ╚██╗)";
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( ██║ ██████╔╝██║██║  ███╗    █████╗╚██╗    ███████╗██╔████╔██║███████║██║     ██║      ██║)";
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ██║ ██╔══██╗██║██║   ██║    ╚════╝██╔╝    ╚════██║██║╚██╔╝██║██╔══██║██║     ██║      ██║)";
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ╚██╗██████╔╝██║╚██████╔╝         ██╔╝     ███████║██║ ╚═╝ ██║██║  ██║███████╗███████╗██╔╝)";
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(  ╚═╝╚═════╝ ╚═╝ ╚═════╝          ╚═╝      ╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ )";
                                                                                         
    system("chcp 437 > nul");                                                                                        
}

void AssignClassDesign::SmallToBigText(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(3); H::gotoxy(x,y+0); cout<<R"(  ██╗███████╗███╗   ███╗ █████╗ ██╗     ██╗              ██╗      ██████╗ ██╗ ██████╗ ██╗ )";
    H::setcolor(3); H::gotoxy(x,y+1); cout<<R"( ██╔╝██╔════╝████╗ ████║██╔══██╗██║     ██║              ╚██╗     ██╔══██╗██║██╔════╝ ╚██╗)";
    H::setcolor(3); H::gotoxy(x,y+2); cout<<R"( ██║ ███████╗██╔████╔██║███████║██║     ██║         █████╗╚██╗    ██████╔╝██║██║  ███╗ ██║)";
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ██║ ╚════██║██║╚██╔╝██║██╔══██║██║     ██║         ╚════╝██╔╝    ██╔══██╗██║██║   ██║ ██║)";
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ╚██╗███████║██║ ╚═╝ ██║██║  ██║███████╗███████╗         ██╔╝     ██████╔╝██║╚██████╔╝██╔╝)";
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(  ╚═╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝         ╚═╝      ╚═════╝ ╚═╝ ╚═════╝ ╚═╝ )";
    system("chcp 437 > nul");                                                                                        
}

void AssignClassDesign::SortClassDesign()
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

void AssignClassDesign::SortClassText10(int x, int y)
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

void AssignClassDesign::SortClassText11(int x, int y)
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

void AssignClassDesign::SortClassText12(int x, int y)
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

void AssignClassDesign::Car(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ──▄▄▐▀▀▀▀▀▀▀▀▀▀▀▌▄▄──)";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ─▄▄▄█▄▄▄▄▄▄▄▄▄▄▄█▄▄▄─)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ─█▄█░░█▓█▓█▓█▓█░░█▄█▌)";
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ─▓▓█▀███████████▀█▓▓──)";
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"( ─▓▓▀▀───────────▀▀▓▓──)";
    system("chcp 437 > nul"); 

}

void AssignClassDesign::DeleteClassDesign()
{
    DeleteClassText(11,2);

    Home(20,35);
    Home(160,35);
    Computer(20,10);
    Computer(160,10);

    H::HLine(0,0,200,4,219);
    H::HLine(0,8,200,4,219);
    
    // Frame Lines
    for(int i=1;i<8;i++)
    {
    	H::HLine(0,i,2,4,219);
    	H::HLine(198,i,2,4,219);
	}

    for(int i=9;i<42;i++)
    {
        H::HLine(0,i,2,3,219);
        H::HLine(198,i,2,3,219);
    }
    
	H::drawBoxDoubleLine(65,40,70,3,2);
	H::gotoxy(70, 42); 
	cout << "Press [Enter] to delete another teacher, or [ESC] to go back.";
	H::HLine(0,42,64,3,219);
	H::HLine(136,42,64,3,219);
    
	// Field
	H::drawBoxDoubleLine(65,20,70,10,2);
	
	// Input
	H::drawBoxSingleLine(70,22,60,1,8);
	
	//H::setcolor(3); H::gotoxy(72,23); cout<<"Enter Grade ID To Delete: ";
	
	H::HLine(97,32,4,2,219);
	H::HLine(97,33,4,2,219);
	H::HLine(97,34,4,2,219);
	H::HLine(97,35,4,2,219);
	H::HLine(97,36,4,2,219);
	
	H::drawBoxDoubleLine(70,37,60,1,6);
	//H::setcolor(2); H::gotoxy(86,38); cout<<"Teacher deleted successfully";
	//cout<<"Teacher not found";
}

void AssignClassDesign::DeleteClassText(int x, int y)
{
    system("chcp 65001  > nul");

    
    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ██████  ███████ ██      ███████ ████████ ███████      █████  ███████ ███████ ██  ██████  ███    ██ ███████ ██████      ████████ ███████  █████   ██████ ██   ██ ███████ ██████ )"; 
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ██   ██ ██      ██      ██         ██    ██          ██   ██ ██      ██      ██ ██       ████   ██ ██      ██   ██        ██    ██      ██   ██ ██      ██   ██ ██      ██   ██)"; 
    H::setcolor(2); H::gotoxy(x,y+2); cout<<R"( ██   ██ █████   ██      █████      ██    █████       ███████ ███████ ███████ ██ ██   ███ ██ ██  ██ █████   ██   ██        ██    █████   ███████ ██      ███████ █████   ██████ )"; 
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ██   ██ ██      ██      ██         ██    ██          ██   ██      ██      ██ ██ ██    ██ ██  ██ ██ ██      ██   ██        ██    ██      ██   ██ ██      ██   ██ ██      ██   ██)"; 
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ██████  ███████ ███████ ███████    ██    ███████     ██   ██ ███████ ███████ ██  ██████  ██   ████ ███████ ██████         ██    ███████ ██   ██  ██████ ██   ██ ███████ ██   ██)";                                                                                                                                                                  

    system("chcp 437 > nul");
                                                                                                                                                                                        
}

void AssignClassDesign::Grade12Text(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(2); H::gotoxy(x,y+0); cout<<R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗██████╗ )";
    H::setcolor(2); H::gotoxy(x,y+1); cout<<R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║╚════██╗)";
    H::setcolor(2); H::gotoxy(x,y+2); cout<<R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║ █████╔╝)";
    H::setcolor(3); H::gotoxy(x,y+3); cout<<R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║██╔═══╝ )";
    H::setcolor(3); H::gotoxy(x,y+4); cout<<R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║███████╗)";
    H::setcolor(3); H::gotoxy(x,y+5); cout<<R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝╚══════╝)";                           
    
    system("chcp 437 > nul");                                                                                                                                                                                  
}

void AssignClassDesign::Grade11Text(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(4); H::gotoxy(x,y+0); cout<<R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██╗)";
    H::setcolor(4); H::gotoxy(x,y+1); cout<<R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║███║)";
    H::setcolor(4); H::gotoxy(x,y+2); cout<<R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║╚██║)";
    H::setcolor(5); H::gotoxy(x,y+3); cout<<R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║ ██║)";
    H::setcolor(5); H::gotoxy(x,y+4); cout<<R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║ ██║)";
    H::setcolor(5); H::gotoxy(x,y+5); cout<<R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═╝)";                          
    
    system("chcp 437 > nul");                                                                                                                                                                                  
}

void AssignClassDesign::Grade10Text(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██████╗ )";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║██╔═████╗)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║██║██╔██║)";
    H::setcolor(2); H::gotoxy(x,y+3); cout<<R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║████╔╝██║)";
    H::setcolor(2); H::gotoxy(x,y+4); cout<<R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║╚██████╔╝)";
    H::setcolor(2); H::gotoxy(x,y+5); cout<<R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═════╝ )";                            
    
    system("chcp 437 > nul");                                                                                                                                                                                  
}

void AssignClassDesign::Home(int x, int y)
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

void AssignClassDesign::Computer(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(1); H::gotoxy(x,y+0); cout<<R"( ▐▓█▀▀▀▀▀▀▀▀▀█▓▌░▄▄▄▄▄░)";
    H::setcolor(1); H::gotoxy(x,y+1); cout<<R"( ▐▓█░░▀░░▀▄░░█▓▌░█▄▄▄█░)";
    H::setcolor(1); H::gotoxy(x,y+2); cout<<R"( ▐▓█░░▄░░▄▀░░█▓▌░█▄▄▄█░)";
    H::setcolor(1); H::gotoxy(x,y+3); cout<<R"( ▐▓█▄▄▄▄▄▄▄▄▄█▓▌░█████░)";
    H::setcolor(1); H::gotoxy(x,y+4); cout<<R"( ░░░░▄▄███▄▄░░░░░█████░)";
    system("chcp 437 > nul"); 

}

void AssignClassDesign::Header(int y)
{
    H::gotoxy(35, y);  cout << "No."; // y =16
    H::gotoxy(45, y);  cout << "Grade ID";
    H::gotoxy(65, y);  cout << "Teacher ID";
    H::gotoxy(85, y);  cout << "Teacher Name";
    H::gotoxy(110, y);  cout << "Subject";
    H::gotoxy(130, y); cout << "Academic Year";
    H::gotoxy(150, y); cout << "Phone Number";
}

void AssignClassDesign::Footer()
{
    // H::gotoxy(100,40); cout<< "1";
    H::drawBoxDoubleLineWithBG(30, 42, 140, 1, 3); // Footer Line
    H::setcolor(2); H::gotoxy(60,43); cout<<"Tip: [Right Arrow] Next    [Left Arrow] Back    [Enter] Select     [ESC] Exit";
}
/* ================= Input Design ================= */
void AssignClassDesign::AssignTeacherDesign()
{
    AssignTeacherText(17,0);
    H::HLine(17,10,166,2,223);
    H::VLine(95,9,5,3,219);
    H::VLine(105,9,5,3,219);
    //
    H::drawBoxDoubleLineWithBG(70,15,59,1,153); // Enter ID Field

    H::HLine(44,16,25,1,223);
    H::HLine(130,16,25,1,223);
    H::VLine(44,15,10,1,219);
    H::VLine(155,15,10,1,219);
    H::drawBoxDoubleLineWithBG(42,26,5,6,179);
    H::drawBoxDoubleLineWithBG(152,26,5,6,179);

    H::drawBoxDoubleLineWithBG(52,19,4,20,171);
    H::drawBoxDoubleLineWithBG(143,19,4,20,171);

    H::drawBoxDoubleLineWithBG(58,20,83,18,136); // Big Box
    // Field
    H::drawBoxDoubleLineWithBG(79,22,41,1,179);
    H::drawBoxDoubleLineWithBG(60,26,37,1,179);
    H::drawBoxDoubleLineWithBG(102,26,37,1,179);
    H::drawBoxDoubleLineWithBG(60,30,37,1,179);
    H::drawBoxDoubleLineWithBG(102,30,37,1,179);

    // Message Box
    H::drawBoxDoubleLineWithBG(67,36,65,1,247);
    H::drawBoxDoubleLine(67,41,65,1,1);
    H::setcolor(4);
    //H::gotoxy(70,42); cout<<"Tip: [Press Enter] to add more, [Esc] Back to menu.";
}

void AssignClassDesign::G12(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(2);
    H::gotoxy(x,y+0);   cout<<R"(  _____                            _____ )";
    H::gotoxy(x,y+1);   cout<<R"( ( ___ )--------------------------( ___ ))";
    H::gotoxy(x,y+2);   cout<<R"(  |   |                            |   | )";
    H::gotoxy(x,y+3);   cout<<R"(  |   |        ▄▄▄▄▄▄▄▄▄▄▄         |   | )";
    H::gotoxy(x,y+4);   cout<<R"(  |   |       ▐░░░░░░░░░░░▌        |   | )";
    H::gotoxy(x,y+5);   cout<<R"(  |   |       ▐░█▀▀▀▀▀▀▀▀▀         |   | )";
    H::gotoxy(x,y+6);   cout<<R"(  |   |       ▐░▌                  |   | )";
    H::gotoxy(x,y+7);   cout<<R"(  |   |       ▐░▌ ▄▄▄▄▄▄▄▄         |   | )";
    H::gotoxy(x,y+8);   cout<<R"(  |   |       ▐░▌▐░░░░░░░░▌        |   | )";
    H::gotoxy(x,y+9);   cout<<R"(  |   |       ▐░▌ ▀▀▀▀▀▀█░▌        |   | )";
    H::gotoxy(x,y+10);  cout<<R"(  |   |       ▐░▌       ▐░▌        |   | )";
    H::gotoxy(x,y+11);  cout<<R"(  |   |       ▐░█▄▄▄▄▄▄▄█░▌        |   | )";
    H::gotoxy(x,y+12);  cout<<R"(  |   |       ▐░░░░░░░░░░░▌        |   | )";
    H::gotoxy(x,y+13);  cout<<R"(  |   |        ▀▀▀▀▀▀▀▀▀▀▀         |   | )";
    H::gotoxy(x,y+14);  cout<<R"(  |   |                            |   | )";
    H::gotoxy(x,y+15);  cout<<R"(  |   |     ▄▄▄▄      ▄▄▄▄▄▄▄▄▄▄▄  |   | )";
    H::gotoxy(x,y+16);  cout<<R"(  |   |   ▄█░░░░▌    ▐░░░░░░░░░░░▌ |   | )";
    H::gotoxy(x,y+17);  cout<<R"(  |   |  ▐░░▌▐░░▌     ▀▀▀▀▀▀▀▀▀█░▌ |   | )";
    H::gotoxy(x,y+18);  cout<<R"(  |   |   ▀▀ ▐░░▌              ▐░▌ |   | )";
    H::gotoxy(x,y+19);  cout<<R"(  |   |      ▐░░▌              ▐░▌ |   | )";
    H::gotoxy(x,y+20);  cout<<R"(  |   |      ▐░░▌     ▄▄▄▄▄▄▄▄▄█░▌ |   | )";
    H::gotoxy(x,y+21);  cout<<R"(  |   |      ▐░░▌    ▐░░░░░░░░░░░▌ |   | )";
    H::gotoxy(x,y+22);  cout<<R"(  |   |      ▐░░▌    ▐░█▀▀▀▀▀▀▀▀▀  |   | )";
    H::gotoxy(x,y+23);  cout<<R"(  |   |  ▄▄▄▄█░░█▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄  |   | )"; 
    H::gotoxy(x,y+24);  cout<<R"(  |   | ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌ |   | )";
    H::gotoxy(x,y+25);  cout<<R"(  |   |  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  |   | )";
    H::gotoxy(x,y+26);  cout<<R"(  |___|                            |___| )";
    H::gotoxy(x,y+27);  cout<<R"( (_____)--------------------------(_____))";

    system("chcp 437 > nul"); 
}

void AssignClassDesign::G11(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(4);
    H::gotoxy(x,y+0);   cout<<R"(  _____                            _____ )";
    H::gotoxy(x,y+1);   cout<<R"( ( ___ )--------------------------( ___ ))";
    H::gotoxy(x,y+2);   cout<<R"(  |   |                            |   | )";
    H::gotoxy(x,y+3);   cout<<R"(  |   |       ▄▄▄▄▄▄▄▄▄▄▄          |   | )";
    H::gotoxy(x,y+4);   cout<<R"(  |   |      ▐░░░░░░░░░░░▌         |   | )";
    H::gotoxy(x,y+5);   cout<<R"(  |   |      ▐░█▀▀▀▀▀▀▀▀▀          |   | )";
    H::gotoxy(x,y+6);   cout<<R"(  |   |      ▐░▌                   |   | )";
    H::gotoxy(x,y+7);   cout<<R"(  |   |      ▐░▌ ▄▄▄▄▄▄▄▄          |   | )";
    H::gotoxy(x,y+8);   cout<<R"(  |   |      ▐░▌▐░░░░░░░░▌         |   | )";
    H::gotoxy(x,y+9);   cout<<R"(  |   |      ▐░▌ ▀▀▀▀▀▀█░▌         |   | )";
    H::gotoxy(x,y+10);  cout<<R"(  |   |      ▐░▌       ▐░▌         |   | )";
    H::gotoxy(x,y+11);  cout<<R"(  |   |      ▐░█▄▄▄▄▄▄▄█░▌         |   | )";
    H::gotoxy(x,y+12);  cout<<R"(  |   |      ▐░░░░░░░░░░░▌         |   | )";
    H::gotoxy(x,y+13);  cout<<R"(  |   |       ▀▀▀▀▀▀▀▀▀▀▀          |   | )";
    H::gotoxy(x,y+14);  cout<<R"(  |   |                            |   | )";
    H::gotoxy(x,y+15);  cout<<R"(  |   |     ▄▄▄▄         ▄▄▄▄      |   | )";
    H::gotoxy(x,y+16);  cout<<R"(  |   |   ▄█░░░░▌      ▄█░░░░▌     |   | )";
    H::gotoxy(x,y+17);  cout<<R"(  |   |  ▐░░▌▐░░▌     ▐░░▌▐░░▌     |   | )";
    H::gotoxy(x,y+18);  cout<<R"(  |   |   ▀▀ ▐░░▌      ▀▀ ▐░░▌     |   | )";
    H::gotoxy(x,y+19);  cout<<R"(  |   |      ▐░░▌         ▐░░▌     |   | )";
    H::gotoxy(x,y+20);  cout<<R"(  |   |      ▐░░▌         ▐░░▌     |   | )";
    H::gotoxy(x,y+21);  cout<<R"(  |   |      ▐░░▌         ▐░░▌     |   | )";
    H::gotoxy(x,y+22);  cout<<R"(  |   |      ▐░░▌         ▐░░▌     |   | )";
    H::gotoxy(x,y+23);  cout<<R"(  |   |  ▄▄▄▄█░░█▄▄▄  ▄▄▄▄█░░█▄▄▄  |   | )";
    H::gotoxy(x,y+24);  cout<<R"(  |   | ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌ |   | )";
    H::gotoxy(x,y+25);  cout<<R"(  |   |  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  |   | )";
    H::gotoxy(x,y+26);  cout<<R"(  |___|                            |___| )";
    H::gotoxy(x,y+27);  cout<<R"( (_____)--------------------------(_____))";

    system("chcp 437 > nul"); 
}

void AssignClassDesign::G10(int x, int y)
{
    system("chcp 65001  > nul");
    H::setcolor(2);
    H::gotoxy(x,y+0);  cout<<R"(  _____                           _____ )";
    H::gotoxy(x,y+1);  cout<<R"( ( ___ )-------------------------( ___ ))";
    H::gotoxy(x,y+2);  cout<<R"(  |   |                           |   | )";
    H::gotoxy(x,y+3);  cout<<R"(  |   |        ▄▄▄▄▄▄▄▄▄▄▄        |   | )";
    H::gotoxy(x,y+4);  cout<<R"(  |   |       ▐░░░░░░░░░░░▌       |   | )";
    H::gotoxy(x,y+5);  cout<<R"(  |   |       ▐░█▀▀▀▀▀▀▀▀▀        |   | )";
    H::gotoxy(x,y+6);  cout<<R"(  |   |       ▐░▌                 |   | )";
    H::gotoxy(x,y+7);  cout<<R"(  |   |       ▐░▌ ▄▄▄▄▄▄▄▄        |   | )";
    H::gotoxy(x,y+8);  cout<<R"(  |   |       ▐░▌▐░░░░░░░░▌       |   | )";
    H::gotoxy(x,y+9);  cout<<R"(  |   |       ▐░▌ ▀▀▀▀▀▀█░▌       |   | )";
    H::gotoxy(x,y+10); cout<<R"(  |   |       ▐░▌       ▐░▌       |   | )";
    H::gotoxy(x,y+11); cout<<R"(  |   |       ▐░█▄▄▄▄▄▄▄█░▌       |   | )";
    H::gotoxy(x,y+12); cout<<R"(  |   |       ▐░░░░░░░░░░░▌       |   | )";
    H::gotoxy(x,y+13); cout<<R"(  |   |        ▀▀▀▀▀▀▀▀▀▀▀        |   | )";
    H::gotoxy(x,y+14); cout<<R"(  |   |                           |   | )";
    H::gotoxy(x,y+15); cout<<R"(  |   |     ▄▄▄▄      ▄▄▄▄▄▄▄▄▄   |   | )";
    H::gotoxy(x,y+16); cout<<R"(  |   |   ▄█░░░░▌    ▐░░░░░░░░░▌  |   | )";
    H::gotoxy(x,y+17); cout<<R"(  |   |  ▐░░▌▐░░▌   ▐░█░█▀▀▀▀▀█░▌ |   | )";
    H::gotoxy(x,y+18); cout<<R"(  |   |   ▀▀ ▐░░▌   ▐░▌▐░▌    ▐░▌ |   | )";
    H::gotoxy(x,y+19); cout<<R"(  |   |      ▐░░▌   ▐░▌ ▐░▌   ▐░▌ |   | )";
    H::gotoxy(x,y+20); cout<<R"(  |   |      ▐░░▌   ▐░▌  ▐░▌  ▐░▌ |   | )";
    H::gotoxy(x,y+21); cout<<R"(  |   |      ▐░░▌   ▐░▌   ▐░▌ ▐░▌ |   | )";
    H::gotoxy(x,y+22); cout<<R"(  |   |      ▐░░▌   ▐░▌    ▐░▌▐░▌ |   | )";
    H::gotoxy(x,y+23); cout<<R"(  |   |  ▄▄▄▄█░░█▄▄▄▐░█▄▄▄▄▄█░█░▌ |   | )";
    H::gotoxy(x,y+24); cout<<R"(  |   | ▐░░░░░░░░░░░▌▐░░░░░░░░░▌  |   | )";
    H::gotoxy(x,y+25); cout<<R"(  |   |  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀   |   | )";
    H::gotoxy(x,y+26); cout<<R"(  |___|                           |___| )";
    H::gotoxy(x,y+27); cout<<R"( (_____)-------------------------(_____))";

    system("chcp 437 > nul"); 
}

void AssignClassDesign::AssignTeacherText(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(6);H::gotoxy(x,y+1); cout<<R"(    █████████    █████████   █████████  █████   █████████  ██████   █████    ███████████ ██████████   █████████     █████████  █████   █████ ██████████ ███████████ )"; 
    H::setcolor(6);H::gotoxy(x,y+2); cout<<R"(   ███░░░░░███  ███░░░░░███ ███░░░░░███░░███   ███░░░░░███░░██████ ░░███    ░█░░░███░░░█░░███░░░░░█  ███░░░░░███   ███░░░░░███░░███   ░░███ ░░███░░░░░█░░███░░░░░███ )";
    H::setcolor(6);H::gotoxy(x,y+3); cout<<R"(  ░███    ░███ ░███    ░░░ ░███    ░░░  ░███  ███     ░░░  ░███░███ ░███    ░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░░  ░███    ░███  ░███  █ ░  ░███    ░███ )";
    H::setcolor(6);H::gotoxy(x,y+4); cout<<R"(  ░███████████ ░░█████████ ░░█████████  ░███ ░███          ░███░░███░███        ░███     ░██████    ░███████████ ░███          ░███████████  ░██████    ░██████████  )";
    H::setcolor(6);H::gotoxy(x,y+5); cout<<R"(  ░███░░░░░███  ░░░░░░░░███ ░░░░░░░░███ ░███ ░███    █████ ░███ ░░██████        ░███     ░███░░█    ░███░░░░░███ ░███          ░███░░░░░███  ░███░░█    ░███░░░░░███ )";
    H::setcolor(6);H::gotoxy(x,y+6); cout<<R"(  ░███    ░███  ███    ░███ ███    ░███ ░███ ░░███  ░░███  ░███  ░░█████        ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░███    ░███  ░███ ░   █ ░███    ░███ )";
    H::setcolor(6);H::gotoxy(x,y+7); cout<<R"(  █████   █████░░█████████ ░░█████████  █████ ░░█████████  █████  ░░█████       █████    ██████████ █████   █████ ░░█████████  █████   █████ ██████████ █████   █████)";
    H::setcolor(6);H::gotoxy(x,y+8); cout<<R"( ░░░░░   ░░░░░  ░░░░░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░░░░░  ░░░░░    ░░░░░       ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░   ░░░░░ )";
    H::setcolor(6);H::gotoxy(x,y+9); cout<<R"(                                      ░░░░░░                                                                                      )";

    system("chcp 437 > nul"); 
}

/* Grade 12 */
void AssignClassDesign::AssignGrade12Design()
{
    H::setcursor(false, 0);
    AssignGrade12Banner(45, 0);
    
    system("chcp 437 > nul"); 
    H::drawBoxDoubleLine(25, 10, 150, 3,2); // Menu Bar

    H::drawBoxSingleLine(30, 15, 140, 1,6); //  Table Header
    H::drawBoxSingleLine(30, 15, 140, 22,9); // Table Body Design
    Header(16);

    // Footer
    Footer();
}

void AssignClassDesign::AssignGrade12Banner(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(6);H::gotoxy(x,y+0); cout<<R"(╔╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╗)";
    H::setcolor(6);H::gotoxy(x,y+1); cout<<R"(╟┼┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┼╢)";
    H::setcolor(6);H::gotoxy(x,y+2); cout<<R"(╟┤ █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗██████╗ ├╢)";
    H::setcolor(6);H::gotoxy(x,y+3); cout<<R"(╟┤██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║╚════██╗├╢)";
    H::setcolor(6);H::gotoxy(x,y+4); cout<<R"(╟┤███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║ █████╔╝├╢)";
    H::setcolor(6);H::gotoxy(x,y+5); cout<<R"(╟┤██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║██╔═══╝ ├╢)";
    H::setcolor(6);H::gotoxy(x,y+6); cout<<R"(╟┤██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║███████╗├╢)";
    H::setcolor(6);H::gotoxy(x,y+7); cout<<R"(╟┤╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝╚══════╝├╢)";
    H::setcolor(6);H::gotoxy(x,y+8); cout<<R"(╟┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼╢)";
    H::setcolor(6);H::gotoxy(x,y+9); cout<<R"(╚╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╝)";
    system("chcp 437 > nul"); 
}

// Table Design
void AssignClassDesign::AssignGrade11Design()
{
    H::setcursor(false, 0);
    AssignGrade11Banner(46, 0);
    
    H::drawBoxDoubleLine(25, 10, 150, 3,2); // Menu Bar

    H::drawBoxSingleLine(30, 15, 140, 1,6); //  Table Header
    H::drawBoxSingleLine(30, 15, 140, 22,9); // Table Body Design
    Header(16);

        // Footer
    Footer();
}

/* Grade 11*/
void AssignClassDesign::AssignGrade11Banner(int x, int y)
{
    system("chcp 65001  > nul");

    H::setcolor(6);H::gotoxy(x,y+0); cout<<R"(╔╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╗)";
    H::setcolor(6);H::gotoxy(x,y+1); cout<<R"(╟┼┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┼╢)";
    H::setcolor(6);H::gotoxy(x,y+2); cout<<R"(╟┤ █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██╗├╢)";
    H::setcolor(6);H::gotoxy(x,y+3); cout<<R"(╟┤██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║███║├╢)";
    H::setcolor(6);H::gotoxy(x,y+4); cout<<R"(╟┤███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║╚██║├╢)";
    H::setcolor(6);H::gotoxy(x,y+5); cout<<R"(╟┤██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║ ██║├╢)";
    H::setcolor(6);H::gotoxy(x,y+6); cout<<R"(╟┤██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║ ██║├╢)";
    H::setcolor(6);H::gotoxy(x,y+7); cout<<R"(╟┤╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═╝├╢)";
    H::setcolor(6);H::gotoxy(x,y+8); cout<<R"(╟┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼╢)";
    H::setcolor(6);H::gotoxy(x,y+9); cout<<R"(╚╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╝)";
    system("chcp 437 > nul"); 
}

void AssignClassDesign::AssignGrade10Design()
{
    H::setcursor(false, 0);
    AssignGrade10Banner(44, 0);
    
    H::drawBoxDoubleLine(25, 10, 150, 3,2); // Menu Bar

    H::drawBoxSingleLine(30, 15, 140, 1,6); //  Table Header
    H::drawBoxSingleLine(30, 15, 140, 22,9); // Table Body Design
    Header(16);

        // Footer
    Footer();
}

/* Grade 10 */
void AssignClassDesign::AssignGrade10Banner(int x, int y)
{
    system("chcp 65001  > nul");
    
    H::setcolor(6);H::gotoxy(x,y+0); cout<<R"(╔╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╗)";
    H::setcolor(6);H::gotoxy(x,y+1); cout<<R"(╟┼┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┼╢)";
    H::setcolor(6);H::gotoxy(x,y+2); cout<<R"(╟┤ █████╗ ███████╗███████╗██╗ ██████╗ ███╗   ██╗     ██████╗ ██████╗  █████╗ ██████╗ ███████╗     ██╗ ██████╗ ├╢)";
    H::setcolor(6);H::gotoxy(x,y+3); cout<<R"(╟┤██╔══██╗██╔════╝██╔════╝██║██╔════╝ ████╗  ██║    ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝    ███║██╔═████╗├╢)";
    H::setcolor(6);H::gotoxy(x,y+4); cout<<R"(╟┤███████║███████╗███████╗██║██║  ███╗██╔██╗ ██║    ██║  ███╗██████╔╝███████║██║  ██║█████╗      ╚██║██║██╔██║├╢)";
    H::setcolor(4);H::gotoxy(x,y+5); cout<<R"(╟┤██╔══██║╚════██║╚════██║██║██║   ██║██║╚██╗██║    ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝       ██║████╔╝██║├╢)";
    H::setcolor(4);H::gotoxy(x,y+6); cout<<R"(╟┤██║  ██║███████║███████║██║╚██████╔╝██║ ╚████║    ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗     ██║╚██████╔╝├╢)";
    H::setcolor(4);H::gotoxy(x,y+7); cout<<R"(╟┤╚═╝  ╚═╝╚══════╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝     ╚═╝ ╚═════╝ ├╢)";
    H::setcolor(4);H::gotoxy(x,y+8); cout<<R"(╟┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼╢)";
    H::setcolor(4);H::gotoxy(x,y+9); cout<<R"(╚╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╝)";
    system("chcp 437 > nul"); 
}

void AssignClassDesign::AssignClassLogo(int x, int y) {
    H::setcolor(6);
    H::gotoxy(x,y+0); cout<<R"( _____                                                                                  _____ )";
    H::gotoxy(x,y+1); cout<<R"(( ___ )--------------------------------------------------------------------------------( ___ ))";
    H::gotoxy(x,y+2); cout<<R"( |   |            _____ _____ _____ _____ _   _     _____ _                _____ _____  |   | )";
    H::gotoxy(x,y+3); cout<<R"( |   |     /\    / ____/ ____|_   _/ ____| \ | |   / ____| |        /\    / ____/ ____| |   | )";
    H::gotoxy(x,y+4); cout<<R"( |   |    /  \  | (___| (___   | || |  __|  \| |  | |    | |       /  \  | (___| (___   |   | )";
    H::gotoxy(x,y+5); cout<<R"( |   |   / /\ \  \___ \\___ \  | || | |_ | . ` |  | |    | |      / /\ \  \___ \\___ \  |   | )";
    H::gotoxy(x,y+6); cout<<R"( |   |  / ____ \ ____) |___) |_| || |__| | |\  |  | |____| |____ / ____ \ ____) |___) | |   | )";
    H::gotoxy(x,y+7); cout<<R"( |   | /_/    \_\_____/_____/|_____\_____|_| \_|   \_____|______/_/    \_\_____/_____/  |   | )";
    H::gotoxy(x,y+8); cout<<R"( |___|                                                                                  |___| )";
    H::gotoxy(x,y+9); cout<<R"((_____)--------------------------------------------------------------------------------(_____))";
    
    // Draw the border lines
    H::HLine(6,5,48,7,223);
    H::HLine(146,5,48,7,223);
    H::HLine(0,41,200,2,223);
    H::HLine(0,44,200,2,223);

    // Draw Line Below the logo   
    H::HLine(60,11,80,7,223);
    H::VLine(100, 10, 3, 153, 223);
    // Box Menu
    H::drawBoxDoubleLineWithBG(61, 13, 78, 12, 2);
    //Menu
    // H::drawBoxDoubleLineWithBG(85, 13, 29, 1, 213);
    // H::drawBoxDoubleLineWithBG(61, 18, 29, 1, 213);
    // H::drawBoxDoubleLineWithBG(110, 18, 29, 1, 213);
    // H::drawBoxDoubleLineWithBG(85, 23, 29, 1, 213);
    // H::setcolor(215);
    // H::gotoxy(90,14); cout << "1. Assign Grade 10";
    // H::gotoxy(66,19); cout << "2. Assign Grade 11";
    // H::gotoxy(115,19); cout << "3. Assign Grade 12";
    // H::gotoxy(90,24); cout << "4. Back to Main Menu";
    //
    H::VLine(100, 15, 7, 153, 223);
    H::VLine(74, 10, 7, 153, 223);
    H::VLine(125, 10, 7, 153, 223);

    //
    KBText(70, 27);

    /* Small box */
    int leftX[]  = {1, 8, 15, 22, 29, 36, 43};
    int rightX[] = {194, 187, 180, 173, 166, 159, 152};
    int yPairs[][2] = {
        {4, 38},
        {7, 35},
        {10, 32},
        {13, 29},
        {16, 26},
        {19, 23},
        {21, -1} // -1 means only one box
    };

    for (int i = 0; i < 7; ++i) {
        int lx = leftX[i];
        int rx = rightX[i];
        int y1 = yPairs[i][0];
        int y2 = yPairs[i][1];

        H::drawBoxDoubleLineWithBG(lx, y1, 5, 1, 136);
        if (y2 != -1) H::drawBoxDoubleLineWithBG(lx, y2, 5, 1, 136);

        H::drawBoxDoubleLineWithBG(rx, y1, 5, 1, 136);
        if (y2 != -1) H::drawBoxDoubleLineWithBG(rx, y2, 5, 1, 136);
    }

}

void AssignClassDesign::KBText(int x, int y)
{
    H::setcolor(9);
    H::gotoxy(x, y + 0); cout << R"(    |==================================================|)";
    H::gotoxy(x, y + 1); cout << R"(    | __  ___________  ___________            AMIGA == |)";
    H::gotoxy(x, y + 2); cout << R"(    |[_j  L_I_I_I_I_j  L_I_I_I_I_j            ~~~~~ == |)";
    H::gotoxy(x, y + 3); cout << R"(    |________________________________ _______ ______==_|)";
    H::gotoxy(x, y + 4); cout << R"(    |[__I_I_I_I_I_I_I_I_I_I_I_I_I_I_] [__I__] [_I_I_I_]|)";
    H::gotoxy(x, y + 5); cout << R"(    |[___I_I_I_I_I_I_I_I_I_I_I_I_]  |    _    [_I_I_I_]|)";
    H::gotoxy(x, y + 6); cout << R"(    |[__I_I_I_I_I_I_I_I_I_I_I_I_L___|  _[_]_  [_I_I_I_]|)";
    H::gotoxy(x, y + 7); cout << R"(    |[_____I_I_I_I_I_I_I_I_I_I_I____] [_I_I_] [_I_I_T ||)";
    H::gotoxy(x, y + 8); cout << R"(    | [__I__I_________________I__L_] ________ [___I_I_j|)";
    H::gotoxy(x, y + 9); cout << R"(    |                                                  |)";
    H::gotoxy(x, y + 10);cout << R"(    |__________________________________________________|)";
}

#endif 