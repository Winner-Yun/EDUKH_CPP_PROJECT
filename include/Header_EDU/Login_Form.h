#ifndef __LOGIN_PAGE_WITH_LOADING__
#define __LOGIN_PAGE_WITH_LOADING__

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class Login_Design {
    private:
        char strGmail[40];
        char strPassword[20];

    public:
        // loading process and all of its design
        static void loadingProcess();
        static void loginDesignCon();


        void MainLogin();
        void MainLogin_NoLoading();
    };

   void Login_Design::MainLogin(){

        loadingProcess();   // call design of loading function
        
        loginDesignCon();   //call design of  login

        //email form
        int attmp=0;
        while(true){
            H::drawBoxSingleLineWithBG(123,26,53,1,0);
            H::drawBoxSingleLineWithBG(123,33,53,1,0);
            H::gotoxy(123,27);H::setcolor(15);HLVInput::inputEmail(this->strGmail, 40);


            //password form
            H::gotoxy(123,34);H::setcolor(15);HLVInput::inputUNumber(this->strPassword, 21);

            if(strcmp(strGmail, "winner@gmail.com") == 0 && strcmp(strPassword, "123") == 0){
                H::gotoxy(135,38);H::setcolor(15);cout<<"         SUCCESS!!         ";
                break;
            }
            else{
                attmp ++;
                H::gotoxy(135,38);H::setcolor(4);cout<<"[!] WRONG EMAIL OR PASSWORD";
             }

            if(attmp==3){
                for(int i = 60 ; i>= 0; i--){
                    H::gotoxy(120,38);H::setcolor(4);cout<<"[!] YOUR TRY MANY ATTEMPTS, PLEASE WAIT "<<i<<"s TO INPUT AGAIN" ;
                    H::delay(1000);
                }
                H::gotoxy(120,38);H::setcolor(4);cout<<"                                                                " ;
            }
        }



     
    }

   void Login_Design::MainLogin_NoLoading(){

        
        loginDesignCon();   //call design of  login

        //email form
        int attmp=0;
        while(true){
            H::drawBoxSingleLineWithBG(123,26,53,1,0);
            H::drawBoxSingleLineWithBG(123,33,53,1,0);
            H::gotoxy(123,27);H::setcolor(15);HLVInput::inputEmail(this->strGmail, 40);


            //password form
            H::gotoxy(123,34);H::setcolor(15);HLVInput::inputUNumber(this->strPassword, 21);

            if(strcmp(strGmail, "winner@gmail.com") == 0 && strcmp(strPassword, "123") == 0){
                H::gotoxy(135,38);H::setcolor(15);cout<<"         SUCCESS!!         ";
                break;
            }
            else{
                attmp++;
                H::gotoxy(135,38);H::setcolor(4);cout<<"[!] WRONG EMAIL OR PASSWORD";
             }
            if(attmp==3){
                for(int i = 60 ; i>= 0; i--){
                    H::gotoxy(120,38);H::setcolor(4);cout<<"[!] YOUR TRY MANY ATTEMPTS, PLEASE WAIT "<<i<<"s TO INPUT AGAIN" ;
                    H::delay(1000);
                }
                H::gotoxy(120,38);H::setcolor(4);cout<<"                                                                " ;
            }
        }



     
    }


void Login_Design::loadingProcess() {
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

        H::drawBoxSingleLine(135,34,50,6,7);

        H::setcolor(11);
        H::gotoxy(140, 35); cout << "DEVELOPED BY:";
        
        H::setcolor(6);H::gotoxy(140, 36); cout << " [1] YUN WINNER  "; Sleep(50);
        H::setcolor(4);H::gotoxy(140, 37); cout << " [2] RY KIMCHHAY "; Sleep(50);
        H::setcolor(1);H::gotoxy(140, 38); cout << " [3] VANNA NICHH "; Sleep(50);
        H::setcolor(2);H::gotoxy(140, 39); cout << " [4] SLES ROFATH "; Sleep(50);

        H::setcolor(7);
        H::gotoxy(140, 40);
        for (const char* msg = "[ THANKS FOR USING EDUMASTER-KH SYSTEM! ]"; *msg; msg++) {
            cout << *msg;
            Sleep(10);
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

            H::setcolor(15);
            H::gotoxy(62,16); cout<<R"( | __||   \ | | | | |  \/  |  /_\   / __||_   _|| __|| _ \  | |/ /| || | )"; 
            H::gotoxy(62,17); cout<<R"( | _| | |) || |_| | | |\/| | / _ \  \__ \  | |  | _| |   /  | ' < | __ | )"; 
            H::setcolor(8);H::gotoxy(62,18); cout<<R"( |___||___/  \___/  |_|  |_|/_/ \_\ |___/  |_|  |___||_|_\  |_|\_\|_||_| )"; 

            if(i<140){
                H::HLine(i, 26, 1, 15, 177);
                cout<<i-40<<"%";
            }

            
            H::setcolor(4);H::gotoxy(15,34);cout<<R"( +-----------------------+ )";
            H::setcolor(1);H::gotoxy(15,35);cout<<R"( |     _    _   _ _____    )";
            H::setcolor(2);H::gotoxy(15,36);cout<<R"( |    / \  | \ | |_   _|   )";
            H::setcolor(6);H::gotoxy(15,37);cout<<R"( |   / _ \ |  \| | | |     )";
            H::setcolor(4);H::gotoxy(15,38);cout<<R"( |  / ___ \| |\  | | |     )";
            H::setcolor(1);H::gotoxy(15,39);cout<<R"( | /_/   \_\_| \_| |_|     )";
            H::setcolor(2);H::gotoxy(15,40);cout<<R"( |                         )";
            H::setcolor(6);H::gotoxy(15,41);cout<<R"( +-----------------------+ )";

            H::setcolor(1);H::gotoxy(42,34);cout<<R"( +---------------------------------------------------+ )";
            H::setcolor(2);H::gotoxy(42,35);cout<<R"(    ____ ____  ____  ____    _____ _   _ _   _ ____    )";
            H::setcolor(4);H::gotoxy(42,36);cout<<R"(   / ___| __ )|  _ \|  _ \  |  ___| | | | \ | |  _ \   )";
            H::setcolor(6);H::gotoxy(42,37);cout<<R"(  | |   |  _ \| |_) | | | | | |_  | | | |  \| | | | |  )";
            H::setcolor(1);H::gotoxy(42,38);cout<<R"(  | |___| |_) |  _ <| |_| | |  _| | |_| | |\  | |_| |  )";
            H::setcolor(2);H::gotoxy(42,39);cout<<R"(   \____|____/|_| \_\____/  |_|    \___/|_| \_|____/   )";
            H::setcolor(4);H::gotoxy(42,40);cout<<R"(                                                       )";
            H::setcolor(6);H::gotoxy(42,41);cout<<R"( +---------------------------------------------------+ )";

            H::setcolor(1);H::gotoxy(97,34);cout<<R"( +--------------------------------+ )";
            H::setcolor(2);H::gotoxy(97,35);cout<<R"(   ____        _____        ____  | )";
            H::setcolor(4);H::gotoxy(97,36);cout<<R"(  |  _ \      |_   _|      / ___| | )";
            H::setcolor(6);H::gotoxy(97,37);cout<<R"(  | |_) |       | |       | |     | )";
            H::setcolor(1);H::gotoxy(97,38);cout<<R"(  |  __/   _    | |    _  | |___  | )";
            H::setcolor(2);H::gotoxy(97,39);cout<<R"(  |_|     (_)   |_|   (_)  \____| | )";
            H::setcolor(4);H::gotoxy(97,40);cout<<R"(                                  | )";
            H::setcolor(6); H::gotoxy(97,41);cout<<R"( +--------------------------------+ )";

            
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
            
            H::setcolor(1);
            H::delay(60);
        }
        system("cls");
    }

    void Login_Design::loginDesignCon(){

        H::setcolor(15);H::gotoxy(4,1);cout<<R"(  .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.    )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,2);cout<<R"( / .. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \   )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,3);cout<<R"( \ \/\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ \/ /   )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,4);cout<<R"(  \/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\/ /    )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,5);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,6);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,7);cout<<R"(  \/ /                                                                                    \/ /    )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,8);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,9);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(6);H::gotoxy(4,10);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(15);H::gotoxy(4,11);cout<<R"(  \/_/ ---------------------------------------------------------------------------------- \/_/    )";H::delay(30);


        H::setcolor(15);H::gotoxy(100,11);cout<<R"(  .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.    )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,12);cout<<R"( / .. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \   )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,13);cout<<R"( \ \/\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ \/ /   )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,14);cout<<R"(  \/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\/ /    )";H::delay(30);
        H::setcolor(10);H::gotoxy(100,15);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(10);H::gotoxy(100,16);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,17);cout<<R"(  \/ /                                                                                    \/ /    )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,18);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,19);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,20);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,21);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(2);H::gotoxy(100,22);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(2);H::gotoxy(100,23);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(2);H::gotoxy(100,24);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,25);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,26);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,27);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,28);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,29);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(2);H::gotoxy(100,30);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(2);H::gotoxy(100,31);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(2);H::gotoxy(100,32);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,33);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,34);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(1);H::gotoxy(100,35);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,36);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,37);cout<<R"( / /\ \                                                                                  / /\ \   )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,38);cout<<R"( \ \/ /                                                                                  \ \/ /   )";H::delay(30);
        H::setcolor(6);H::gotoxy(100,39);cout<<R"(  / /\                                                                                    / /\    )";H::delay(30);
        H::setcolor(15);H::gotoxy(100,40);cout<<R"(  \/_/ ---------------------------------------------------------------------------------- \/_/    )";H::delay(30);
   
        H::setcolor(15);H::gotoxy(11, 5); cout << R"(         __        __  _____   _        ____    ___    __  __   _____            )";H::delay(100);
        H::setcolor(15);H::gotoxy(11, 6); cout << R"(         \ \      / / | ____| | |      / ___|  / _ \  |  \/  | | ____|           )";H::delay(100);
        H::setcolor(15);H::gotoxy(11, 7); cout << R"(          \ \ /\ / /  |  _|   | |     | |     | | | | | |\/| | |  _|             )";H::delay(100);
        H::setcolor(15);H::gotoxy(11, 8); cout << R"(           \ V  V /   | |___  | |___  | |___  | |_| | | |  | | | |___            )";H::delay(100);
        H::setcolor(8);H::gotoxy(11, 9); cout << R"(            \_/\_/    |_____| |_____|  \____|  \___/  |_|  |_| |_____|           )";H::delay(100);
        H::setcolor(15);H::gotoxy(11, 10); cout << R"(                                                                                )";

        H::setcolor(15);H::gotoxy(92, 5); cout << R"(  .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--    )";H::delay(100);
        H::setcolor(1);H::gotoxy(92, 6); cout << R"( / .. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \  \   )";H::delay(100);
        H::setcolor(1);H::gotoxy(92, 7); cout << R"( \ \/\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\   )";H::delay(100);
        H::setcolor(15);H::gotoxy(92, 8); cout << R"(  \/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'-  )";H::delay(100);

        
        H::setcolor(15);H::gotoxy(120, 17); cout << R"(  _     _____ _____  _ ____    _     ____  _____ _  _    _ )";H::delay(100);
        H::setcolor(15);H::gotoxy(120, 18); cout << R"( / \   /  __//__ __\|// ___\  / \   /  _ \/  __// \/ \  /| )";H::delay(100);
        H::setcolor(15);H::gotoxy(120, 19); cout << R"( | |   |  \    / \    |    \  | |   | / \|| |  _| || |\ || )";H::delay(100);
        H::setcolor(15);H::gotoxy(120, 20); cout << R"( | |_/\|  /_   | |    \___ |  | |_/\| \_/|| |_//| || | \|| )";H::delay(100);
        H::setcolor(8);H::gotoxy(120, 21); cout << R"( \____/\____\  \_/    \____/  \____/\____/\____\\_/\_/  \| )";H::delay(100);


        //About System
        H::HLine(6, 11, 93, 8, 205);              
        H::drawBoxSingleLineWithBG(5, 13, 94, 11, 31); 


        H::setcolor(15);
        H::drawBoxDoubleLineWithBG(30, 13, 40, 3, 9);

        H::gotoxy(35, 14); std::cout << "[ ABOUT EDUMASTER-KH SYSTEM ]";

        H::setcolor(11);
        H::gotoxy(9, 16); std::cout << "                                                                                     ";
        H::gotoxy(9, 17); std::cout << "           EDUMASTER-KH is a comprehensive school management system.                 ";
        H::gotoxy(9, 18); std::cout << "           It offers tools for students, teachers, and administrators                ";
        H::gotoxy(9, 19); std::cout << "           to manage academic records, schedules, and communication.                 ";

        H::drawBoxSingleLine(10,20,83,1,7);
        H::setcolor(10);
        H::gotoxy(9, 21); std::cout << "                                                                                     ";
        H::gotoxy(9, 22); std::cout << "          DEVELOPED BY: YUN WINNER, RY KIMCHHAY, VANNA NICHH, SLES ROFATH            ";
        H::gotoxy(9, 23); std::cout << "                                                                                     ";


        //Control
         
        H::drawBoxSingleLineWithBG(5, 28, 94, 11, 47); 

        H::setcolor(15);
        H::drawBoxDoubleLineWithBG(30, 28, 40, 3, 10);

        H::setcolor(10);H::gotoxy(38, 29); std::cout << "[ CONTROLER IN SYSTEM ]";

        H::setcolor(11);
        H::gotoxy(9, 31); std::cout << "                                                                                     ";
        H::gotoxy(9, 32); std::cout << "                  Keys Arrow For Control Up and Down Menu in System                  ";
        H::gotoxy(9, 33); std::cout << "                      Keys Arrow For Control Left and Right Menu in System           ";
        H::gotoxy(9, 34); std::cout << "            Key for BACK and        key For select the option or submit              ";

        H::drawBoxSingleLine(10,35,83,1,7);
        H::setcolor(10);
        H::gotoxy(9, 36); std::cout << "                                                                                     ";
        H::gotoxy(9, 37); std::cout << "     ALL OF THESE CAN BE MADE BECAUSE OF                              THANKS YOU     ";
        H::gotoxy(9, 38); std::cout << "                                                                                     ";


        // IMPORTANT TEXT
        H::setcolor(103);H::gotoxy(17,32);cout<<"UP & DOWN";
        H::setcolor(23);H::gotoxy(17,33);cout<<"LEFT & RIGHT";
        H::setcolor(71);H::gotoxy(17,34);cout<<"ESC";
        H::setcolor(87);H::gotoxy(39,34);cout<<"ENTER";
        H::setcolor(215);H::gotoxy(50,37);cout<<" ANT SCHOOL, CBRD FUND, PTC.";


        // BOX LOGIN Field 
        H::drawBoxDoubleLineWithBG(122,25,55,3,47);
        H::setcolor(15);H::gotoxy(121,25);cout<<"->  Email             :   ";
        H::drawBoxDoubleLineWithBG(122,32,55,3,31);
        H::setcolor(15);H::gotoxy(121,32);cout<<"->  Password          :   ";


    }


#endif
