#ifndef __LOGIN_PAGE_WITH_LOADING__
#define __LOGIN_PAGE_WITH_LOADING__

#include "../Header_School/ANTHinsyOOP"
#include "Main_menu.h"
#include "CustomHeader.h"
#include "../Header_Teacher/Teach_MainMenu.h"
#include "../Header_Student/Sudent_Menu.h"

using namespace ANTHinsyOOP;

class Login_Design {
    private:
        char strGmail[40];
        char strPassword[20];

    public:
    
        void MainLogin();
        // loading process and all of its design
        static void loadingProcess(); // loading process
        static void loginDesignCon(); // login design
        static void LoadingHeader(int id);
        // login process function
        static void processLogin(const char* inputEmail, const char* inputPassword, int& attmp);
        static bool startsWith(const string& str, const string& prefix);   // compare first word of email to define the role
        static bool compareCredentials_STU(const char* inputEmail, const char* inputPassword); // compare email and password of each file for studen
        static bool compareCredentials_TECH(const char* inputEmail, const char* inputPassword); // compare email and password of each file for stuent
      
    };

    // Define the Student structure used for binary reading
    struct Student_form {
        char id[6], name[19], gender[7], bdate[15], grade[3], tel[10], sYear[5], email[30], pw[19];
    };
    struct Teacher_form { 
    char teacherId[20], teacherName[20],gender[20],subject[20],phoneNumber[15],dateOfBirth[20],email[40],pw[20],academyYear[10];
    };
    bool trueInput = true;
     //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // ---------------------------------------------------------<< Login Main Process >>-------------------------------------------------------------
   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   
// password input with position
    void inputPasswordMask(int x, int y, char* password, int maxLen) {
        int i = 0;
        bool showPassword = false;  // start hidden
        char ch;

        H::gotoxy(x, y);  // move cursor to position

        while (true) {
            ch = _getch(); // read key without echo

            // Enter key -> finish input
            if (ch == 13) { 
                password[i] = '\0';
                break;
            }
            // Backspace
            else if (ch == 8) {
                if (i > 0) {
                    i--;
                    password[i] = '\0';
                    cout << "\b \b"; // erase last char
                }
            }
            // Toggle password visibility (example: press TAB key)
            else if (ch == 9) {
                showPassword = !showPassword; 
                // redraw password
                H::gotoxy(x, y);
                for (int j = 0; j < i; j++) {
                    cout << (showPassword ? password[j] : '*');
                }
                // clear the rest if needed
                cout << string(maxLen - i, ' ');
                H::gotoxy(x + i, y);
            }
            // Normal input
            else if (i < maxLen - 1 && isprint(ch)) {
                password[i++] = ch;
                password[i] = '\0';
                cout << (showPassword ? ch : '*');
            }
        }
    }


   void Login_Design::MainLogin(){


        // loadingProcess();   // call design of loading function
        

        //email form
        int attmp=0;
        
        while(true){
            H::setcursor(true,1);
            if(trueInput){
                loginDesignCon();
                H::gotoxy(123,37); H::setcolor(2); cout << "TAP TO SHOW/HIDE PASSWORD";
            }   //call design of  login
          
            H::drawBoxSingleLineWithBG(123,26,53,1,0);
            H::drawBoxSingleLineWithBG(123,33,53,1,0);
            H::gotoxy(123,27);H::setcolor(15);HLVInput::inputEmail(this->strGmail, 40);
            //password form
            H::gotoxy(123,34);H::setcolor(15);inputPasswordMask(123, 34, this->strPassword, 19);;
            processLogin(strGmail , strPassword , attmp);
            
        }

    }

    void Login_Design::processLogin(const char* inputEmail, const char* inputPassword, int& attmp) {
        string adminEmail = "edu.master.admin@gmail.com";
        string adminPassword = "admin123";

        if (inputEmail == adminEmail && inputPassword == adminPassword) {
            trueInput = true;
            system("cls");
            LoadingHeader(1);
            EdumasterCustom::LoadingPage(30, 21, 135, 20);
            system("cls");
            Edu_Main_Menu eduMenu;
            eduMenu.Main_menu();
        }
        else if (startsWith(inputEmail, "stu")) {
            if (compareCredentials_STU(inputEmail, inputPassword)) {
                trueInput = true;
                H::cls();
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30, 21, 135, 20);
                H::cls();
                Student_MainMenu::Main(inputEmail);


            }
            else {
                trueInput = false;
                attmp++;
                H::setcolor(4);
                H::gotoxy(120, 39);
                cout << "             [!] INVALID EMAIL OR PASSWORD               ";
                H::delay(1000);
                H::gotoxy(120, 39);
                cout << "                                                         ";
            }
        }
        else if (startsWith(inputEmail, "te")) {
            if (compareCredentials_TECH(inputEmail, inputPassword)) {
                trueInput = true;
                H::cls();
                LoadingHeader(2);
                EdumasterCustom::LoadingPage(30, 21, 135, 20);
                H::cls();
                Teach_MainMenu::Main(inputEmail);
            }
            else {
                trueInput = false;
                attmp++;
                H::setcolor(4);
                H::gotoxy(120, 39);
                cout << "             [!] INVALID EMAIL OR PASSWORD               ";
                H::delay(1000);
                H::gotoxy(120, 39);
                cout << "                                                         ";
            }
        }
        else {
            trueInput = false;
            attmp++;
            H::setcolor(4);
            H::gotoxy(120, 39);
            cout << "             [!] INVALID EMAIL OR PASSWORD               ";
            H::delay(1000);
            H::gotoxy(120, 39);
            cout << "                                                         ";
        }

        if (attmp == 3) {
            H::setcursor(false,0);
            for (int i = 60; i >= 0; i--) {
                H::gotoxy(120, 38);
                H::setcolor(4);
                cout << "[!] YOUR TRY MANY ATTEMPTS, PLEASE WAIT " << i << "s TO INPUT AGAIN";
                H::delay(1000);
            }
            H::gotoxy(120, 38);
            H::setcolor(4);
            cout << "                                                                ";
            attmp = 0;
        }
    }
    
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //<<----------------------------------------------------- Sub function for spp the main process ------------------------------------------------------------------->>>>>>
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    //for cheack which devide we are login as
    bool Login_Design::startsWith(const string& str, const string& prefix) {
        return str.compare(0, prefix.length(), prefix) == 0;   // compare (position , length, other string )
    }

    //read compare login process for student
    bool Login_Design::compareCredentials_STU(const char* inputEmail, const char* inputPassword) {
    ifstream file("../data/Student_Data.bin", ios::binary);
    if (!file) {
        cout << "Failed to open file.\n";
        return false;
    }

    Student_form s;   // structure for from in file
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student_form))) {
        if (strcmp(s.email, inputEmail) == 0 && strcmp(s.pw, inputPassword) == 0) {
            return true;
        }
    }

    return false;
}

    //read compare login process for teacher
    bool Login_Design::compareCredentials_TECH(const char* inputEmail, const char* inputPassword) {
    ifstream file("../data/Teacher_Data.bin", ios::binary);
    if (!file) {
        cout << "Failed to open file.\n";
        return false;
    }

    Teacher_form t; // to get structure teacher form 
    while (file.read(reinterpret_cast<char*>(&t), sizeof(Teacher_form))) {
        if (strcmp(t.email, inputEmail) == 0 && strcmp(t.pw, inputPassword) == 0) {
            return true;
        }
    }

    return false;
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

        string box3[] = {
            R"( +-----------------------+ )",
            R"(       _    _   _ _____  | )",
            R"(      / \  | \ | |_   _| | )",
            R"(     / _ \ |  \| | | |   | )",
            R"(    / ___ \| |\  | | |   | )",
            R"(   /_/   \_\_| \_| |_|   | )",
            R"(                         | )",
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

        string box1[] = {
            R"( +--------------------------------+ )",
            R"( |  ____        _____        ____   )",
            R"( | |  _ \      |_   _|      / ___|  )",
            R"( | | |_) |       | |       | |      )",
            R"( | |  __/   _    | |    _  | |___   )",
            R"( | |_|     (_)   |_|   (_)  \____|  )",
            R"( |                                  )",
            R"( +--------------------------------+ )"
        };

        // Print box1 with colors 1 to 12
        for (int i = 0; i < 8; i++) {
            H::setcolor((i % 12) + 1); // Cycle from 1 to 12
            H::gotoxy(16, 34 + i); 
            cout << box1[i];
            H::delay(40);
        }

        // Print box2 with colors 1 to 12
        for (int i = 0; i < 8; i++) {
            H::setcolor((i % 12) + 1);
            H::gotoxy(52, 34 + i); 
            cout << box2[i];
            H::delay(40);
        }

        // Print box3 with colors 1 to 12
        for (int i = 0; i < 8; i++) {
            H::setcolor((i % 12) + 1);
            H::gotoxy(107, 34 + i); 
            cout << box3[i];
            H::delay(40);
        }

        H::drawBoxSingleLine(135,34,50,6,7);

        H::setcolor(11);
        H::gotoxy(140, 35); cout << "DEVELOPED BY:";
        
        H::setcolor(6);H::gotoxy(140, 36); cout << " [1] YUN WINNER  "; Sleep(50);
        H::setcolor(4);H::gotoxy(140, 37); cout << " [2] RY KIMCHHAY "; Sleep(50);
        H::setcolor(1);H::gotoxy(140, 38); cout << " [3] VANNA NICH  "; Sleep(50);
        H::setcolor(2);H::gotoxy(140, 39); cout << " [4] SLES ROFATH "; Sleep(50);

        H::setcolor(7);
        H::gotoxy(140, 40);
        for (const char* msg = "[ THANKS FOR USING EDUMASTER-KH SYSTEM! ]"; *msg; msg++) {
            cout << *msg;
            Sleep(10);
        }

        int fireColors[] = {4, 6, 12, 14};

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
            H::delay(30);
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
   
        H::setcolor(7);H::gotoxy(11, 5); cout << R"(         __        __  _____   _        ____    ___    __  __   _____            )";H::delay(100);
        H::setcolor(7);H::gotoxy(11, 6); cout << R"(         \ \      / / | ____| | |      / ___|  / _ \  |  \/  | | ____|           )";H::delay(100);
        H::setcolor(10);H::gotoxy(11, 7); cout << R"(          \ \ /\ / /  |  _|   | |     | |     | | | | | |\/| | |  _|             )";H::delay(100);
        H::setcolor(10);H::gotoxy(11, 8); cout << R"(           \ V  V /   | |___  | |___  | |___  | |_| | | |  | | | |___            )";H::delay(100);
        H::setcolor(8);H::gotoxy(11, 9); cout << R"(            \_/\_/    |_____| |_____|  \____|  \___/  |_|  |_| |_____|           )";H::delay(100);
        H::setcolor(15);H::gotoxy(11, 10); cout << R"(                                                                                )";

         H::setcolor(7);H::gotoxy(100, 1); cout << R"( _______________________________________________________________________________________________   )";H::delay(100);
         H::setcolor(4);H::gotoxy(100, 2); cout << R"(          ___________ _   ____  ___  ___   _____ _____ ___________       _   __ _   _              )";H::delay(100);
         H::setcolor(2);H::gotoxy(100, 3); cout << R"(          |  ___|  _  \ | | |  \/  | / _ \ /  ___|_   _|  ___| ___ \     | | / /| | | |             )";H::delay(100);
         H::setcolor(2);H::gotoxy(100, 4); cout << R"(          | |__ | | | | | | | .  . |/ /_\ \\ `--.  | | | |__ | |_/ /_____| |/ / | |_| |             )";H::delay(100);
         H::setcolor(2);H::gotoxy(100, 5); cout << R"(          |  __|| | | | | | | |\/| ||  _  | `--. \ | | |  __||    /______|    \ |  _  |             )";H::delay(100);
         H::setcolor(2);H::gotoxy(100, 6); cout << R"(          | |___| |/ /| |_| | |  | || | | |/\__/ / | | | |___| |\ \      | |\  \| | | |             )";H::delay(100);
         H::setcolor(4);H::gotoxy(100, 7); cout << R"(          \____/|___/  \___/\_|  |_/\_| |_/\____/  \_/ \____/\_| \_|     \_| \_/\_| |_/            )";H::delay(100);
         H::setcolor(1);H::gotoxy(100, 8); cout << R"(                                                                                                    )";H::delay(100);
         H::setcolor(7);H::gotoxy(100, 9); cout << R"( ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  )";H::delay(100);
         H::setcolor(0);H::gotoxy(100, 10); cout << R"( _______________________________________________________________________________________________  )";H::delay(100);


        
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

        H::gotoxy(35, 14); cout << "[ ABOUT EDUMASTER-KH SYSTEM ]";

        H::setcolor(11);
        H::gotoxy(9, 16); cout << "                                                                                     ";
        H::gotoxy(9, 17); cout << "           EDUMASTER-KH is a comprehensive school management system.                 ";
        H::gotoxy(9, 18); cout << "           It offers tools for students, teachers, and administrators                ";
        H::gotoxy(9, 19); cout << "           to manage academic records, schedules, and communication.                 ";

        H::drawBoxSingleLine(10,20,83,1,7);
        H::setcolor(10);
        H::gotoxy(9, 21); cout << "                                                                                     ";
        H::gotoxy(9, 22); cout << "          DEVELOPED BY: YUN WINNER, RY KIMCHHAY, VANNA NICH, SLES ROFATH            ";
        H::gotoxy(9, 23); cout << "                                                                                     ";


        //Control
         
        H::drawBoxSingleLineWithBG(5, 28, 94, 11, 47); 

        H::setcolor(15);
        H::drawBoxDoubleLineWithBG(30, 28, 40, 3, 10);

        H::setcolor(10);H::gotoxy(38, 29); cout << "[ CONTROLER IN SYSTEM ]";

        H::setcolor(11);
        H::gotoxy(9, 31); cout << "                                                                                     ";
        H::gotoxy(9, 32); cout << "                  Keys Arrow For Control Up and Down Menu in System                  ";
        H::gotoxy(9, 33); cout << "                      Keys Arrow For Control Left and Right Menu in System           ";
        H::gotoxy(9, 34); cout << "            Key for BACK and        key For select the option or submit              ";

        H::drawBoxSingleLine(10,35,83,1,7);
        H::setcolor(10);
        H::gotoxy(9, 36); cout << "                                                                                     ";
        H::gotoxy(9, 37); cout << "     ALL OF THESE CAN BE MADE BECAUSE OF                              THANKS YOU     ";
        H::gotoxy(9, 38); cout << "                                                                                     ";


        // IMPORTANT TEXT
        H::setcolor(103);H::gotoxy(17,32);cout<<"UP & DOWN";
        H::setcolor(23);H::gotoxy(17,33);cout<<"LEFT & RIGHT";
        H::setcolor(71);H::gotoxy(17,34);cout<<"ESC";
        H::setcolor(87);H::gotoxy(39,34);cout<<"ENTER";
        H::setcolor(215);H::gotoxy(50,37);cout<<" PTC, CBRD FUND, ANT SCHOOL ";


        // BOX LOGIN Field 
        H::drawBoxDoubleLineWithBG(122,25,55,3,47);
        H::setcolor(15);H::gotoxy(121,25);cout<<"->  Email             :   ";
        H::drawBoxDoubleLineWithBG(122,32,55,3,31);
        H::setcolor(15);H::gotoxy(121,32);cout<<"->  Password          :   ";


    }


    void Login_Design::LoadingHeader(int id){
    if(id == 1){
        H::setcolor(1);H::gotoxy(48,15);cout << R"(   __   ____  __________  __  ___   ____  ___   ___  __  ________  __ )";
        H::setcolor(1);H::gotoxy(48,16);cout << R"(  / /  / __ \/ ___/  _/ |/ / / _ | / __/ / _ | / _ \/  |/  /  _/ |/ / )";
        H::setcolor(1);H::gotoxy(48,17);cout << R"( / /__/ /_/ / (_ // //    / / __ |_\ \  / __ |/ // / /|_/ // //    /  )";
        H::setcolor(7);H::gotoxy(48,18);cout << R"(/____/\____/\___/___/_/|_/ /_/ |_/___/ /_/ |_/____/_/  /_/___/_/|_/   )";
    }
    else if(id == 2){
        H::setcolor(2);H::gotoxy(49,12);cout << R"( ______________     ___________________________________________________________________                    )";
        H::setcolor(2);H::gotoxy(49,13);cout << R"( 7     77     7     7     77  _  77     77     77     77     77     77  77     77     7                    )";
        H::setcolor(2);H::gotoxy(49,14);cout << R"( |  7  ||  _  |     |  -  ||    _||  7  ||  ___!|  ___!|  ___!|  ___!|  ||  _  ||   __!                    )";
        H::setcolor(2);H::gotoxy(49,15);cout << R"( |  |  ||  7  |     |  ___!|  _ \ |  |  ||  7___|  __|_!__   7!__   7|  ||  7  ||  !  7                    )";
        H::setcolor(7);H::gotoxy(49,16);cout << R"( |  !  ||  |  |     |  7   |  7  ||  !  ||     7|     77     |7     ||  ||  |  ||     |     ____________   )";
        H::setcolor(7);H::gotoxy(49,17);cout << R"( !_____!!__!__!     !__!   !__!__!!_____!!_____!!_____!!_____!!_____!!__!!__!__!!_____!     7__77__77__7   )";
    }

}

#endif