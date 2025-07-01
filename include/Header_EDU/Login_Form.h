#ifndef TEST_HPP
#define TEST_HPP

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class Loading_Design {
public:
    static void mainTile() {
        H::setcolor(5);
        H::gotoxy(55,8);cout<<R"(  _____                                                                         _____  )";
        H::gotoxy(55,9);cout<<R"( ( ___ )                                                                       ( ___ ) )";
        H::setcolor(6);
        H::gotoxy(55,10);cout<<R"(  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |  )";
        H::gotoxy(55,11);cout<<R"(  |   |                                                                         |   |  )";
        H::gotoxy(55,12);cout<<R"(  |   |                                                                         |   |  )";
        H::gotoxy(55,13);cout<<R"(  |   |                                                                         |   |  )";
        H::gotoxy(55,14);cout<<R"(  |   |                                                                         |   |  )";
        H::gotoxy(55,15);cout<<R"(  |   |                                                                         |   |  )"; 
        H::gotoxy(55,16);cout<<R"(  |   |                                                                         |   |  )"; 
        H::gotoxy(55,17);cout<<R"(  |   |                                                                         |   |  )"; 
        H::gotoxy(55,18);cout<<R"(  |   |                                                                         |   |  )"; 
        H::gotoxy(55,19);cout<<R"(  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|  )"; 
        H::setcolor(5);
        H::gotoxy(55,20);cout<<R"( (_____)                                                                       (_____) )";

        string flameLines[] = {
            R"(      (                *             (                (          )    )  )",
            R"(      )\ )           (  `     (      )\ )  *   )      )\ )    ( /( ( /(  )",
            R"(  (  (()/(      (    )\))(    )\    (()/(` )  /( (   (()/(    )\()))\()) )",
            R"(  )\  /(_)) )(  )\  ((_)()\((((_)(   /(_))( )(_)))\  /(_))  ((_)\((_)_)  )",
            R"( ((_)(_))_ (_) ((_) (_()((_))\ _ )  (_)) (_(_())((_) (_))   (_((_)_((_)  )"
        };

        string box1[] = {
            R"( +-----------------------+ )",
            R"( |     _    _   _ _____    )",
            R"( |    / \  | \ | |_   _|   )",
            R"( |   / _ \ |  \| | | |     )",
            R"( |  / ___ \| |\  | | |     )",
            R"( | /_/   \_\_| \_| |_|     )",
            R"( |                         )",
            R"( +-----------------------+ )"
        };

        string box2[] = {
            R"( +---------------------------------------------------+ )",
            R"(    ____ ____  ____  ____    _____ _   _ _   _ ____    )",
            R"(   / ___| __ )|  _ \|  _ \  |  ___| | | | \ | |  _ \   )",
            R"(  | |   |  _ \| |_) | | | | | |_  | | | |  \| | | | |  )",
            R"(  | |___| |_) |  _ <| |_| | |  _| | |_| | |\  | |_| |  )",
            R"(   \____|____/|_| \_\____/  |_|    \___/|_| \_|____/   )",
            R"(                                                       )",
            R"( +---------------------------------------------------+ )"
        };

        string box3[] = {
            R"( +--------------------------------+ )",
            R"(   ____        _____        ____  | )",
            R"(  |  _ \      |_   _|      / ___| | )",
            R"(  | |_) |       | |       | |     | )",
            R"(  |  __/   _    | |    _  | |___  | )",
            R"(  |_|     (_)   |_|   (_)  \____| | )",
            R"(                                  | )",
            R"( +--------------------------------+ )"
        };

        H::setcolor(7);
        for (int i = 0; i < 8; i++) {
            H::gotoxy(15, 34 + i); cout << box1[i];
            H::delay(40);
        }

        for (int i = 0; i < 8; i++) {
            H::gotoxy(42, 34 + i); cout << box2[i];
            H::delay(40);
        }

        for (int i = 0; i < 8; i++) {
            H::gotoxy(97, 34 + i); cout << box3[i];
            H::delay(40);
        }

        int fireColors[] = {4, 6, 12, 14};
        bool footerCleared = false;

        srand((unsigned)time(0));
        H::drawBoxSingleLine(54, 24, 89, 2);
        H::gotoxy(55,25);cout<<"LOADING...";

        for (int i = 55; i <= 175; i++) {
            for (int l = 0; l < 5; l++) {
                H::gotoxy(62, 11 + l);
                for (char ch : flameLines[l]) {
                    if (ch == ' ') {
                        cout << ' ';
                    } else {
                        H::setcolor(fireColors[rand() % 4]);
                        cout << ch;
                    }
                }
            }

            H::setcolor(5);
            H::gotoxy(62,16); cout<<R"( | __||   \ | | | | |  \/  |  /_\   / __||_   _|| __|| _ \  | |/ /| || | )"; 
            H::gotoxy(62,17); cout<<R"( | _| | |) || |_| | | |\/| | / _ \  \__ \  | |  | _| |   /  | ' < | __ | )"; 
            H::gotoxy(62,18); cout<<R"( |___||___/  \___/  |_|  |_|/_/ \_\ |___/  |_|  |___||_|_\  |_|\_\|_||_| )"; 

            if(i<140){
                H::HLine(i, 26, 1, 15, 177);
                cout<<i-40<<"%";
            }

            
            H::setcolor(7);
            H::gotoxy(15,34);cout<<R"( +-----------------------+ )";
            H::gotoxy(15,35);cout<<R"( |     _    _   _ _____    )";
            H::gotoxy(15,36);cout<<R"( |    / \  | \ | |_   _|   )";
            H::gotoxy(15,37);cout<<R"( |   / _ \ |  \| | | |     )";
            H::gotoxy(15,38);cout<<R"( |  / ___ \| |\  | | |     )";
            H::gotoxy(15,39);cout<<R"( | /_/   \_\_| \_| |_|     )";
            H::gotoxy(15,40);cout<<R"( |                         )";
            H::gotoxy(15,41);cout<<R"( +-----------------------+ )";

            H::gotoxy(42,34);cout<<R"( +---------------------------------------------------+ )";
            H::gotoxy(42,35);cout<<R"(    ____ ____  ____  ____    _____ _   _ _   _ ____    )";
            H::gotoxy(42,36);cout<<R"(   / ___| __ )|  _ \|  _ \  |  ___| | | | \ | |  _ \   )";
            H::gotoxy(42,37);cout<<R"(  | |   |  _ \| |_) | | | | | |_  | | | |  \| | | | |  )";
            H::gotoxy(42,38);cout<<R"(  | |___| |_) |  _ <| |_| | |  _| | |_| | |\  | |_| |  )";
            H::gotoxy(42,39);cout<<R"(   \____|____/|_| \_\____/  |_|    \___/|_| \_|____/   )";
            H::gotoxy(42,40);cout<<R"(                                                       )";
            H::gotoxy(42,41);cout<<R"( +---------------------------------------------------+ )";

            H::gotoxy(97,34);cout<<R"( +--------------------------------+ )";
            H::gotoxy(97,35);cout<<R"(   ____        _____        ____  | )";
            H::gotoxy(97,36);cout<<R"(  |  _ \      |_   _|      / ___| | )";
            H::gotoxy(97,37);cout<<R"(  | |_) |       | |       | |     | )";
            H::gotoxy(97,38);cout<<R"(  |  __/   _    | |    _  | |___  | )";
            H::gotoxy(97,39);cout<<R"(  |_|     (_)   |_|   (_)  \____| | )";
            H::gotoxy(97,40);cout<<R"(                                  | )";
            H::gotoxy(97,41);cout<<R"( +--------------------------------+ )";

            
            H::drawBoxSingleLine(29,0,1,14,i);      
            H::drawBoxSingleLine(26,14,1,2,i+6);     
            H::drawBoxSingleLine(32,14,1,2,i+12);    
            H::drawBoxSingleLine(23,16,1,2,i+18);   
            H::drawBoxSingleLine(29,16,1,2,i+24);    
            H::drawBoxSingleLine(35,16,1,2,i+30);  

            H::drawBoxSingleLine(169,0,1,14,i);      
            H::drawBoxSingleLine(166,14,1,2,i+6);     
            H::drawBoxSingleLine(172,14,1,2,i+12);    
            H::drawBoxSingleLine(163,16,1,2,i+18);   
            H::drawBoxSingleLine(169,16,1,2,i+24);    
            H::drawBoxSingleLine(175,16,1,2,i+30);   

            H::drawBoxSingleLine(135,34,50,6,7);
            H::setcolor(11);
            H::gotoxy(140, 35); cout << "DEVELOPED BY:";
            H::setcolor(2);
            H::gotoxy(140, 36); cout << " [1] YUN WINNER  ";
            H::gotoxy(140, 37); cout << " [2] RY KIMCHHAY ";
            H::gotoxy(140, 38); cout << " [3] VANNA NICHH ";
            H::gotoxy(140, 39); cout << " [4] SLES ROFATH ";
            H::setcolor(7);
            H::gotoxy(140, 40); cout << "[ THANKS FOR USING EDUMASTER-KH SYSTEM! ]";
            
            H::delay(60);
        }
        system("cls");
    }

    
};

#endif
