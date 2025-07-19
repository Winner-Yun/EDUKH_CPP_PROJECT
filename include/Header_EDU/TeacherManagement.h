#ifndef __TEACHERMANAGEMENT__
#define __TEACHERMANAGEMENT__

#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class Teacher{
	private: 
		static int lastId;    
		char teacherId[20];
		int yearOfExp,academyYear;
		char teacherName[30],gender[30],subject[30],phoneNumber[15],dateOfBirth[20],email[20];
	public:
		void generateTeacherID(); 
		const char* getTeacherId(){
		    return teacherId;
		}
		const char* getTeacherName() const{
			return teacherName;
		}
		void input();
		void output(int y);
		void newInput();
};

class TeacherDesign{
	public:
		static void loading();
		static void allformForWrongInput();
		static void allformForInput();
		static void increaseId();
		static void showTeacher();
		static void showdesign();
		static void designTable();
		static void insertTeacher();
		static void system();
		static void searchTeacher();
		static void updateTeacher();
		static void deletedTeacher();
		static void sortTeacherByName();
		static void teacherManagement();
		static void asciiDelete();
		static void asciiTeacherNotFound();
		static void asciiSearchTeacher();
		static void sorting();
	
};
TeacherDesign td;
int Teacher::lastId = 0;

void  Teacher::input(){
	H::setFixedScreenConsole(200,45);
	
	H::drawBoxSingleLine(50, 5, 100, 7, 153);
	H::foreColor(154); H::gotoxy(49, 5); cout << "><";
	H::delay(50); H::foreColor(3); H::gotoxy(63, 6); cout << R"( ___                   _     _____               _              )";
	H::delay(50); H::foreColor(4); H::gotoxy(63, 7); cout << R"(|_ _|_ __  _ __  _   _| |_  |_   _|__  __ _  ___| |__   ___ _ __ )";
	H::delay(50); H::foreColor(5); H::gotoxy(63, 8); cout << R"( | || '_ \| '_ \| | | | __|   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
	H::delay(50); H::foreColor(6); H::gotoxy(63, 9); cout << R"( | || | | | |_) | |_| | |_    | |  __/ (_| | (__| | | |  __/ |   )";
	H::delay(50); H::foreColor(7); H::gotoxy(63, 10); cout << R"(|___|_| |_| .__/ \__,_|\__|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
	H::delay(50); H::foreColor(7); H::gotoxy(63, 11); cout << R"(          |_|                                                    )";

	H::delay(10); H::foreColor(3); H::gotoxy(10, 1); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(10, 2); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(10, 3); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(10, 4); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(10, 5); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(33, 7); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(33, 8); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(33, 9); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(33, 10); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(33, 11); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(180, 1); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(180, 2); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(180, 3); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(180, 4); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(180, 5); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(155, 7); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(155, 8); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(155, 9); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(155, 10); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(155, 11); cout << R"(  / |  | \)";
	
	H::drawBoxDoubleLineWithBG(25, 18, 150, 25, 10);  // Outer box
	H::drawBoxDoubleLineWithBG(30, 20, 140, 21, 145);   // Inner background
	
	H::VLine(85,14,1,7,186);
	H::VLine(85,15,1,7,186);
	H::VLine(85,16,1,7,186);
	H::VLine(85,13,1,7,186);
	
	H::VLine(105,14,1,7,186);
	H::VLine(105,15,1,7,186);
	H::VLine(105,16,1,7,186);
	H::VLine(105,13,1,7,186);
	
	H::drawBoxSingleLineWithBG(32,22,50,1,0);
	H::drawBoxSingleLineWithBG(32,28,50,1,0);
	H::drawBoxSingleLineWithBG(32,35,50,1,0);
	
	H::drawBoxSingleLineWithBG(115,22,50,1,0);
	H::drawBoxSingleLineWithBG(115,28,50,1,0);
	H::drawBoxSingleLineWithBG(115,35,50,1,0);
	
	H::drawBoxSingleLineWithBG(75,40,50,1,0);
	
  if (lastId == 0) {
        ifstream file("../data/Teacher_Data.bin", ios::binary); //open file
        Teacher temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Teacher))) {
            int num = atoi(temp.getTeacherId() + 2);  
            if (num > lastId) lastId = num;
        }
        file.close();
    }

    lastId++;  
    sprintf(teacherId, "T-%03d", lastId); 

    H::gotoxy(33, 23);  H::foreColor(6); cout << "TEACHER ID      :";
    H::gotoxy(33, 29);  H::foreColor(6); cout << "TEACHER NAME    :";
    H::gotoxy(33, 36);  H::foreColor(6); cout << "GENDER          :";
    H::gotoxy(116, 23); H::foreColor(6); cout << "SUBJECT         :";
    H::gotoxy(116, 29); H::foreColor(6); cout << "DATE OF BIRTH   :";
    H::gotoxy(116, 36); H::foreColor(6); cout << "PHONE NUMBER    :";
    H::gotoxy(76, 41);  H::foreColor(6); cout << "ACADEMIC YEAR   :";

    string stracademyYear;
    H::gotoxy(60, 23); cout << teacherId;
    H::gotoxy(60, 29); H::inputLetter(teacherName, 30);
    H::gotoxy(60, 36); H::inputLetter(gender, 30);
    H::gotoxy(145, 23); H::inputLetter(subject, 30);
    H::gotoxy(145, 29); H::inputDate(dateOfBirth, '/', false);
    H::gotoxy(145, 36); H::inputUNumber(phoneNumber, 15);
    H::gotoxy(95, 41); academyYear = stoi(H::inputUNumber(stracademyYear, 10));


}

void Teacher::output(int y){
	char teacherName[] = "Winner Yun";
	char cleanedName[30];
	int j = 0;

	for (int i = 0; teacherName[i] != '\0'; i++) {
		if (teacherName[i] != ' ') {
			cleanedName[j++] = tolower(teacherName[i]);
		}
	}
	cleanedName[j] = '\0';

	char email[50] = "te.";
	strcat(email, cleanedName);
	strcat(email, "@gmail.com");
    H::gotoxy(20,y);cout<<teacherId<<endl;
	H::gotoxy(36,y);cout<<teacherName<<endl;
	H::gotoxy(60,y);cout<<gender<<endl;
	H::gotoxy(77,y);cout<<subject<<endl;
	H::gotoxy(100,y);cout<<dateOfBirth<<endl;
	H::gotoxy(119,y);cout<<phoneNumber<<endl;
	H::gotoxy(134,y);cout<<email<<endl;
	H::gotoxy(162,y);cout<<academyYear<<endl;
	
}

void Teacher::newInput(){
	H::setFixedScreenConsole(200,45);
	H::cls();
	H::drawBoxSingleLine(50, 5, 100, 7, 153);
	H::foreColor(154); H::gotoxy(49, 5); cout << "><";
	H::delay(50); H::foreColor(3); H::gotoxy(63, 6);  cout << R"( _   _           _       _         _____               _               )";
	H::delay(50); H::foreColor(4); H::gotoxy(63, 7);  cout << R"(| | | |_ __   __| | __ _| |_ ___  |_   _|__  __ _  ___| |__   ___ _ __ )";
	H::delay(50); H::foreColor(5); H::gotoxy(63, 8);  cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
	H::delay(50); H::foreColor(6); H::gotoxy(63, 9);  cout << R"(| |_| | |_) | (_| | (_| | ||  __/   | |  __/ (_| | (__| | | |  __/ |   )";
	H::delay(50); H::foreColor(7); H::gotoxy(63, 10); cout << R"( \___/| .__/ \__,_|\__,_|\__\___|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
	H::delay(50); H::foreColor(7); H::gotoxy(63, 11); cout << R"(      |_|                                                              )";

	H::delay(10); H::foreColor(3); H::gotoxy(10, 1); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(10, 2); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(10, 3); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(10, 4); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(10, 5); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(33, 7); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(33, 8); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(33, 9); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(33, 10); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(33, 11); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(180, 1); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(180, 2); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(180, 3); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(180, 4); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(180, 5); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(155, 7); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(155, 8); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(155, 9); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(155, 10); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(155, 11); cout << R"(  / |  | \)";
	
	H::drawBoxDoubleLineWithBG(25, 18, 150, 25, 10);  // Outer box
	H::drawBoxDoubleLineWithBG(30, 20, 140, 21, 145);   // Inner background
	
	H::VLine(85,14,1,7,186);
	H::VLine(85,15,1,7,186);
	H::VLine(85,16,1,7,186);
	H::VLine(85,13,1,7,186);
	
	H::VLine(105,14,1,7,186);
	H::VLine(105,15,1,7,186);
	H::VLine(105,16,1,7,186);
	H::VLine(105,13,1,7,186);
	
	H::drawBoxSingleLineWithBG(32,22,50,1,0);
	H::drawBoxSingleLineWithBG(32,28,50,1,0);
	H::drawBoxSingleLineWithBG(32,35,50,1,0);
	
	H::drawBoxSingleLineWithBG(115,22,50,1,0);
	H::drawBoxSingleLineWithBG(115,28,50,1,0);
	H::drawBoxSingleLineWithBG(115,35,50,1,0);
	
	H::drawBoxSingleLineWithBG(75,40,50,1,0);
	
	H::gotoxy(33, 23);  H::foreColor(6); cout << "TEACHER ID      :";
	H::gotoxy(33, 29);  H::foreColor(6); cout << "TEACHER NAME    :";
	H::gotoxy(33, 36);  H::foreColor(6); cout << "GENDER          :";
	H::gotoxy(116, 23); H::foreColor(6); cout << "SUBJECT         :";
	H::gotoxy(116, 29); H::foreColor(6); cout << "DATE OF BIRTH   :";
	H::gotoxy(116, 36); H::foreColor(6); cout << "PHONE NUMBER    :";
	H::gotoxy(76, 41);  H::foreColor(6); cout << "ACADEMIC YEAR   :";

	string stracademyYear;
    H::gotoxy(60, 23);  H::foreColor(6); cout << teacherId;
	H::gotoxy(60, 29);  H::foreColor(6); H::inputLetter(teacherName,30); cin.ignore();
	H::gotoxy(60, 36);  H::foreColor(6); H::inputLetter(gender,30); 
	H::gotoxy(145, 23); H::foreColor(6); H::inputLetter(subject,30);
	H::gotoxy(145, 29); H::foreColor(6); H::inputDate(dateOfBirth,'/',false);   
	H::gotoxy(145, 36); H::foreColor(6); H::inputUNumber(phoneNumber,15);    

	H::gotoxy(95, 41);  H::foreColor(6); academyYear=stoi(H::inputUNumber(stracademyYear,10));
	getch();
	H::cls();
	H::foreColor(0);
}

void TeacherDesign::loading(){
	H::drawBoxSingleLineWithBG(47,24,105,1,15);
		
    for (int i = 47; i <= 147; i++) {
        H::HLine(i, 25, 1, 15, 177);
        cout<<i-47<<"%";
        H::delay(10);
    }
}
void TeacherDesign::allformForWrongInput(){
	H::setFixedScreenConsole(200,45);
	int i = 90;
    H::foreColor(1); H::delay(50); H::gotoxy(i - 63, 2); std::cout << R"(    _______   )";
    H::foreColor(2); H::delay(50); H::gotoxy(i - 63, 3); std::cout << R"(   /      /,  )";
    H::foreColor(3); H::delay(50); H::gotoxy(i - 63, 4); std::cout << R"(  /      //   )";
    H::foreColor(4); H::delay(50); H::gotoxy(i - 63, 5); std::cout << R"( /______//    )";
    H::foreColor(5); H::delay(200); H::gotoxy(i - 63, 6); std::cout << R"((______(/     )";

    H::delay(50); H::foreColor(1); H::gotoxy(i - 0, 1);  std::cout << R"(      _ _                  )";
    H::delay(50); H::foreColor(2); H::gotoxy(i - 10, 2); std::cout << R"( .-. | | |                 )";
    H::delay(50); H::foreColor(3); H::gotoxy(i - 10, 3); std::cout << R"( |M|_|A|N|                  )";
    H::delay(50); H::foreColor(4); H::gotoxy(i - 10, 4); std::cout << R"( |A|a|.|.|<\                )";
    H::delay(50); H::foreColor(5); H::gotoxy(i - 10, 5); std::cout << R"( |T|r| | | \\               )";
    H::delay(50); H::foreColor(1); H::gotoxy(i - 10, 6); std::cout << R"( |H|t|M|Z|  \\             )";
    H::delay(50); H::foreColor(7); H::gotoxy(i - 10, 7); std::cout << R"( | |!| | |   \>            )";
    H::delay(50); H::foreColor(8); H::gotoxy(i - 10, 8); std::cout << R"( """""""""""""""""""       )";
    

    H::delay(10); H::foreColor(3); H::gotoxy(155, 1);  cout << R"((\         )";
	H::delay(10); H::foreColor(4); H::gotoxy(155, 2);  cout << R"('\'\       )";
	H::delay(10); H::foreColor(5); H::gotoxy(155, 3);  cout << R"( \'\     __________  )";
	H::delay(10); H::foreColor(6); H::gotoxy(155, 4); cout << R"( / '|   ()_________))";
	H::delay(10); H::foreColor(7); H::gotoxy(155, 5); cout << R"( \ '/    \ ~~~~~~~~ \)";
	H::delay(10); H::foreColor(8); H::gotoxy(155, 6); cout << R"(   \       \ ~~~~~~   \)";
	H::delay(10); H::foreColor(9); H::gotoxy(155, 7); cout << R"(   ==).      \__________\)";
	H::delay(10); H::foreColor(10);H::gotoxy(155, 8); cout << R"(  (__)       ()__________))";
	
	
	H::delay(10); H::foreColor(1); H::gotoxy(5, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2); H::gotoxy(5, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3); H::gotoxy(5, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4); H::gotoxy(5, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5); H::gotoxy(5, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6); H::gotoxy(5, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7); H::gotoxy(5, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8); H::gotoxy(5, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9); H::gotoxy(5, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(5, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";

	H::delay(10); H::foreColor(1);  H::gotoxy(155, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2);  H::gotoxy(155, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3);  H::gotoxy(155, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4);  H::gotoxy(155, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5);  H::gotoxy(155, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6);  H::gotoxy(155, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7);  H::gotoxy(155, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8);  H::gotoxy(155, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9);  H::gotoxy(155, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(155, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";

    H::drawBoxDoubleLineWithBG(50, 15, 90, 20, 153);
    H::drawBoxDoubleLineWithBG(55, 17, 80, 16, 170);
    H::drawBoxSingleLineWithBG(60, 19, 70, 12, 213);
    H::drawBoxSingleLineWithBG(65, 21, 60, 8, 0);
}
void TeacherDesign::allformForInput(){
	H::setFixedScreenConsole(200,45);
	H::drawBoxDoubleLineWithBG(50, 16, 100, 20, 153);  // Outer box
	H::drawBoxDoubleLineWithBG(55, 18, 90, 16, 2);   // Inner background
	H::drawBoxSingleLineWithBG(60, 20, 80, 12, 170);   // Input container
	H::drawBoxSingleLineWithBG(65, 22, 70, 8,2);

	
	H::delay(10); H::foreColor(3); H::gotoxy(10, 1); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(10, 2); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(10, 3); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(10, 4); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(10, 5); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(33, 7); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(33, 8); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(33, 9); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(33, 10); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(33, 11); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(180, 1); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(180, 2); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(180, 3); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(180, 4); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(180, 5); cout << R"(  / |  | \)";
	
	H::delay(10); H::foreColor(3); H::gotoxy(155, 7); cout << R"(  __   _)";
	H::delay(10); H::foreColor(4); H::gotoxy(155, 8); cout << R"( _(  )_( )_)";
	H::delay(10); H::foreColor(5); H::gotoxy(155, 9); cout << R"((_   _    _))";
	H::delay(10); H::foreColor(6); H::gotoxy(155, 10); cout << R"(  (_) (__))";
	H::delay(10); H::foreColor(7); H::gotoxy(155, 11); cout << R"(  / |  | \)";


	H::delay(10); H::foreColor(1); H::gotoxy(5, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2); H::gotoxy(5, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3); H::gotoxy(5, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4); H::gotoxy(5, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5); H::gotoxy(5, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6); H::gotoxy(5, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7); H::gotoxy(5, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8); H::gotoxy(5, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9); H::gotoxy(5, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(5, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";

	H::delay(10); H::foreColor(1);  H::gotoxy(155, 20); cout << R"(       .--.                   .---.)";
	H::delay(10); H::foreColor(2);  H::gotoxy(155, 21); cout << R"(   .---|__|           .-.     |~~~|)";
	H::delay(10); H::foreColor(3);  H::gotoxy(155, 22); cout << R"(.--|===|--|_          |_|     |~~~|--.)";
	H::delay(10); H::foreColor(4);  H::gotoxy(155, 23); cout << R"(|  |===|  |'\     .---!~|  .--|   |--|)";
	H::delay(10); H::foreColor(5);  H::gotoxy(155, 24); cout << R"(|%%|   |  |.'\    |===| |--|%%|   |  |)";
	H::delay(10); H::foreColor(6);  H::gotoxy(155, 25); cout << R"(|%%|   |  |\.'\   |   | |__|  |   |  |)";
	H::delay(10); H::foreColor(7);  H::gotoxy(155, 26); cout << R"(|  |   |  | \  \  |===| |==|  |   |  |)";
	H::delay(10); H::foreColor(8);  H::gotoxy(155, 27); cout << R"(|  |   |__|  \.'\ |   |_|__|  |~~~|__|)";
	H::delay(10); H::foreColor(9);  H::gotoxy(155, 28); cout << R"(|  |===|--|   \.'\|===|~|--|%%|~~~|--|)";
	H::delay(10); H::foreColor(10); H::gotoxy(155, 29); cout << R"(^--^---'--^    `-'`---^-^--^--^---'--')";
	
	H::foreColor(0);
	H::gotoxy(62, 19);
}

fstream teachF; 
Teacher t;

void TeacherDesign::insertTeacher(){
	H::setFixedScreenConsole(200,45);
	H::cls();
	H::foreColor(3); H::gotoxy(60, 9);  cout << R"(   ______  _______     ________       _     _________  _____  ____  _____    ______ )";
	H::foreColor(3); H::gotoxy(60, 10); cout << R"( .' ___  ||_   __ \   |_   __  |     / \   |  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(60, 11); cout << R"(/ .'   \_|  | |__) |    | |_ \_|    / _ \  |_/ | | \_|  | |    |   \ | |  / .'   \_| )";
	H::foreColor(3); H::gotoxy(60, 12); cout << R"(| |         |  __ /     |  _| _    / ___ \     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(60, 13); cout << R"(\ `.___.'\ _| |  \ \_  _| |__/ | _/ /   \ \_  _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(60, 14); cout << R"( `.____ .'|____| |___||________||____| |____||_____|  |_____||_____|\____| `._____.')";


	TeacherDesign::loading();  
	H::cls();                  
	Teacher t;
	
		fstream file("../data/Teacher_Data.bin", ios::binary | ios::app); // create file
	if (!file) {
	    H::gotoxy(70, 25); H::setcolor(4);
	    cout << "Error can not open file !";
	    getch();
	    return;
	}
	t.input(); 
	file.write((char*)&t, sizeof(t)); //write data to file
	file.close();

//	file.write(reinterpret_cast<char*>(&t), sizeof(t));
//	file.close();


} 

void TeacherDesign::showTeacher(){
	 H::foreColor(0);
    ifstream file("../data/Teacher_Data.bin", ios::binary); //open file
     if (!teachF) {
        cout << "Warning File can't open !" << endl;
        return;
    }
    int y=18;
    while (file.read((char*)&t, sizeof(t))) { // read data from file
        t.output(y);
        y+=2;
    }
    file.close();
}
void TeacherDesign::designTable(){
	int x = 185;
	H::setcolor(3);
	H::gotoxy(0, 0);  cout << R"(             _|)";         H::gotoxy(x, 0);  cout << R"(|_             )";
	H::gotoxy(0, 1);  cout << R"(\_-_-_-_-_-_/)";       H::gotoxy(x, 1);  cout << R"(  \_-_-_-_-_-_/)";
	for (int i = 2; i <= 36; ++i) {
	    H::gotoxy(0, i);     cout << R"(   | | | |)";
	    H::gotoxy(x + 2, i); cout << R"(   | | | |)";
	}
	H::gotoxy(0, 37); cout << R"(  /_______\)";       H::gotoxy(x, 37); cout << R"(    /_______\)";
	H::gotoxy(0, 38); cout << R"(  |_______|)";       H::gotoxy(x, 38); cout << R"(    |_______|)";
	H::gotoxy(0, 39); cout << R"(  |_______|)";       H::gotoxy(x, 39); cout << R"(    |_______|)";
	H::gotoxy(0, 40); cout << R"( /-_-_-_-_-\)";      H::gotoxy(x, 40); cout << R"(   /-_-_-_-_-\)";
	H::gotoxy(0, 41); cout << R"(/___________\)";     H::gotoxy(x, 41); cout << R"(  /___________\)";
	
	H::drawBoxDoubleLine(15, 13, 170, 1, 2);
	H::drawBoxDoubleLine(15, 16, 170, 20, 3);
	H::setcolor(6);
	H::gotoxy(20, 14); cout << "ID";
	H::gotoxy(36, 14); cout << "NAME";
	H::gotoxy(60, 14); cout << "GENDER";
	H::gotoxy(77, 14); cout << "SUBJECT";
	H::gotoxy(100, 14); cout << "BIRTOFDATE";
	H::gotoxy(119, 14); cout << "TEL";
	H::gotoxy(134, 14); cout << "EMAIL";
	H::gotoxy(162, 14); cout << "STUDY YEAR";
	
	H::setcolor(159); H::gotoxy(14, 39); cout << "<---";
	H::setcolor(103); H::gotoxy(20, 39); cout << "[Previous Page]";
	H::setcolor(159); H::gotoxy(182, 39); cout << "--->";
	H::setcolor(103); H::gotoxy(165, 39); cout << "[Next Page]";
	
	H::HLine(0, 42, 200, 6, 223);
	H::gotoxy(60, 43); H::setcolor(10); cout << "    [Right Arrow] Next    [Left Arrow] Back    [Enter] Select     [ESC] Exit";
	H::HLine(0, 44, 200, 6, 220);
}
void TeacherDesign::showdesign(){
	H::setFixedScreenConsole(200, 45);
		H::setcolor(2); H::gotoxy(50, 1);  cout << R"(  _____               _                  )";
	H::setcolor(2); H::gotoxy(50, 2);  cout << R"( |_   _|__  __ _  ___| |__   ___ _ __    )";
	H::setcolor(2); H::gotoxy(50, 3);  cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|   )";
	H::setcolor(3); H::gotoxy(50, 4);  cout << R"(   | |  __/ (_| | (__| | | |  __/ |      )";
	H::setcolor(5); H::gotoxy(50, 5);  cout << R"(   |_|\___|\__,_|\___|_| |_|\___|_|      )";
	
	H::setcolor(2); H::gotoxy(90, 1);  cout << R"(   ___       __                             _   _             )";
	H::setcolor(2); H::gotoxy(90, 2);  cout << R"(  |_ _|_ __ / _| ___  _ __ _ __ ___    __ _| |_(_) ___  _ __  )";
	H::setcolor(3); H::gotoxy(90, 3);  cout << R"(   | || '_ \| |_ / _ \| '__| '_ ` _ \ / _` | __| |/ _ \| '_ \ )";
	H::setcolor(4); H::gotoxy(90, 4);  cout << R"(   | || | | |  _| (_) | |  | | | | | | (_| | |_| | (_) | | | |)";
	H::setcolor(5); H::gotoxy(90, 5);  cout << R"(  |___|_| |_|_|  \___/|_|  |_| |_| |_|\__,_|\__|_|\___/|_| |_|)";
	
	H::HLine(50, 7, 105, 5, 223);
	
	TeacherDesign::designTable();
	TeacherDesign::showTeacher();

}


void TeacherDesign::asciiDelete(){
		H::delay(10); H::foreColor(3); H::gotoxy(63, 4);  cout << R"( ____       _      _         _____               _                )";
		H::delay(10); H::foreColor(4); H::gotoxy(63, 5);  cout << R"(|  _ \  ___| | ___| |_ ___  |_   _|__  __ _  ___| |__   ___ _ __ )";
		H::delay(10); H::foreColor(5); H::gotoxy(63, 6);  cout << R"(| | | |/ _ \ |/ _ \ __/ _ \   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
		H::delay(10); H::foreColor(6); H::gotoxy(63, 7);  cout << R"(| |_| |  __/ |  __/ ||  __/   | |  __/ (_| | (__| | | |  __/ |   )";
		H::delay(10); H::foreColor(7); H::gotoxy(63, 8);  cout << R"(|____/ \___|_|\___|\__\___|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
		H::HLine(63, 10, 66, 5, 223);
}

void TeacherDesign::asciiTeacherNotFound(){
				
	 	H::gotoxy(52, 26); H::setcolor(4); cout << R"(  _____               _                  _   _       _      _____                     _   _ _ _   )";
		H::gotoxy(52, 27); H::setcolor(4); cout << R"( |_   _|__  __ _  ___| |__   ____ __    | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |  )";
		H::gotoxy(52, 28); H::setcolor(4); cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |  )";
		H::gotoxy(52, 29); H::setcolor(4); cout << R"(   | |  __/ (_| | (__| | | |  __/ |     | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|  )";
		H::gotoxy(52, 30); H::setcolor(4); cout << R"(   |_|\___|\__,_|\___|_| |_|\___| |_|   |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_)  )";

}
void TeacherDesign::asciiSearchTeacher(){
		H::setcolor(4);
 		H::gotoxy(15, 1); cout << R"( | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |)";
		H::gotoxy(13, 2); cout << R"(_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|)";
		H::gotoxy(12, 3); cout << R"(UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU)";
		
		H::delay(50); H::foreColor(3); H::gotoxy(63, 6); cout << R"( ____                      _       _____               _               )";
		H::delay(50); H::foreColor(4); H::gotoxy(63, 7); cout << R"(/ ___|  ___  __ _ _ __ ___| |__   |_   _|__  __ _  ___| |__   ___ _ __ )";
		H::delay(50); H::foreColor(5); H::gotoxy(63, 8); cout << R"(\___ \ / _ \/ _` | '__/ __| '_ \    | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
		H::delay(50); H::foreColor(6); H::gotoxy(63, 9); cout << R"( ___) |  __/ (_| | | | (__| | | |   | |  __/ (_| | (__| | | |  __/ |   )";
		H::delay(50); H::foreColor(7); H::gotoxy(63, 10); cout << R"(|____/ \___|\__,_|_|  \___|_| |_|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
		H::HLine(63, 12, 66, 5, 223);	
}
void TeacherDesign::sorting(){
	H::foreColor(3); H::gotoxy(62, 9);  cout << R"(  ______     ___   _______   _________  _____  ____  _____   ______  )";
	H::foreColor(3); H::gotoxy(62, 10); cout << R"(.' ____ \  .'   `.|_   __ \ |  _   _  ||_   _||_   \|_   _|.' ___  | )";
	H::foreColor(3); H::gotoxy(62, 11); cout << R"(| (___ \_|/  .-.  \ | |__) ||_/ | | \_|  | |    |   \ | | / .'   \_| )";
	H::foreColor(3); H::gotoxy(62, 12); cout << R"( _.____`. | |   | | |  __ /     | |      | |    | |\ \| | | |   ____ )";
	H::foreColor(3); H::gotoxy(62, 13); cout << R"(| \____) |\  `-'  /_| |  \ \_  _| |_    _| |_  _| |_\   |_\ `.___]  |)";
	H::foreColor(7); H::gotoxy(62, 14); cout << R"( \______.' `.___.'|____| |___||_____|  |_____||_____|\____|`._____.' )";
	
}
void TeacherDesign::system(){
	H::setFixedScreenConsole(200,45);
	for (int i = 8; i <= 120; i++) {
		H::foreColor(4);
	    H::gotoxy(i - 3, 7);  cout << R"(  _____    _       )";
	    H::gotoxy(i - 3, 8);  cout << R"( | ____|__| |_   _ )";
	    H::gotoxy(i - 3, 9);  cout << R"( |  _| / _` | | | |)";
	    H::gotoxy(i - 3, 10);  cout << R"( | |__| (_| | |_| |)";
	    H::gotoxy(i - 3, 11);  cout << R"( |_____\__,_|\__,_|)";
	    
		H::foreColor(1);
	    H::gotoxy(70, 15);  cout << R"( __  __           _            _  ___   _ )";
	    H::gotoxy(70, 16);  cout << R"(|  \/  | __ _ ___| |_ ___ _ __| |/ / | | |)";
	    H::gotoxy(70, 17);  cout << R"(| |\/| |/ _` / __| __/ _ \ '__| ' /| |_| |)";
	    H::gotoxy(70, 18);  cout << R"(| |  | | (_| \__ \ ||  __/ |  | . \|  _  |)";
	    H::gotoxy(70, 19);  cout << R"(|_|  |_|\__,_|___/\__\___|_|  |_|\_\_| |_|)";
	    
		H::foreColor(6);
	    H::gotoxy(150 - i, 24); cout << R"( ____            _                     )";
	    H::gotoxy(150 - i, 25); cout << R"(/ ___| _   _ ___| |_ ___ _ __ ___     )";
	    H::gotoxy(150 - i, 26); cout << R"(\___ \| | | / __| __/ _ \ '_ ` _ \    )";
	    H::gotoxy(150 - i, 27); cout << R"( ___) | |_| \__ \ ||  __/ | | | | |   )";
	    H::gotoxy(150 - i, 28); cout << R"(|____/ \__, |___/\__\___|_| |_| |_|   )";
	    H::gotoxy(150 - i, 29); cout << R"(        |___/                         )";
	
	    H::delay(5);
	    H::foreColor(0);
	}
	H::delay(2);
	for (int i = 5; i <= 180; i++)
	{
	    H::HLine(14, 1, i, 34, ' ');       
	    H::HLine(12, 2, i, 31, ' ');       
	    H::HLine(10, 3, i, 204, ' ');      
	
	    H::HLine(196 - i, 37, 1, 204, ' '); 
	    H::HLine(194 - i, 38, 1, 31, ' ');  
	    H::HLine(192 - i, 39, 1, 34, ' ');  
	}
	for (int i = 5; i <= 30; i++){
	    H::VLine(5, 6, i - 3, 224, ' ');   
	    H::VLine(6, 6, i - 3, 224, ' ');   
	    H::VLine(7, 5, i - 1, 31, ' ');    
	    H::VLine(8, 5, i - 1, 31, ' ');    
	    H::VLine(9, 4, i + 1, 204, ' ');   
	    H::VLine(10, 4, i + 1, 204, ' ');   
	
	    H::VLine(191, 4, i + 1, 204, ' '); 
	    H::VLine(192, 4, i + 1, 204, ' '); 
	    H::VLine(193, 5, i - 1, 31, ' ');  
	    H::VLine(194, 5, i - 1, 31, ' ');  
	    H::VLine(195, 6, i - 3, 224, ' '); 
	    H::VLine(196, 6, i - 3, 224, ' '); 
	    
	}
	H::delay(500);
	H::cls();
	H::foreColor(0);
}
void TeacherDesign::searchTeacher() {
    H::setFixedScreenConsole(200, 45);
    H::cls();
    H::foreColor(3);
    H::gotoxy(51, 9);  cout << R"(  ______   ________       _       _______      ______  ____  ____  _____  __ __  _____   ______  )";
    H::gotoxy(51, 10); cout << R"(.' ____ \ |_   __  |     / \     |_   __ \   .' ___  ||_   ||   _||_   _||_   \|_   _|.' ___  | )";
    H::gotoxy(51, 11); cout << R"(| (___ \_|  | |_ \_|    / _ \      | |__) | / .'   \_|  | |__| |    | |    |   \ | | / .'   \_| )";
    H::gotoxy(51, 12); cout << R"( _.____`.   |  _| _    / ___ \     |  __ /  | |         |  __  |    | |    | |\ \| | | |   ____ )";
    H::gotoxy(51, 13); cout << R"(| \____) | _| |__/ | _/ /   \ \_  _| |  \ \_\ `.___.'\ _| |  | |_  _| |_  _| |_\   |_\ `.___]  |)";
    H::gotoxy(51, 14); cout << R"( \______.'|________||____| |____||____| |___|`.____ .'|____||____||_____||_____|\____|`._____.' )";

    TeacherDesign::loading();

    char key;
    do {
        bool found = false;
        char searchID[20];

        H::cls();
        TeacherDesign::asciiSearchTeacher();
        H::HLine(63, 12, 66, 5, 223);
        TeacherDesign::designTable();
        TeacherDesign::showTeacher();

        H::drawBoxSingleLine(75, 38, 45, 1, 1);
        H::gotoxy(76, 39); cout << "Enter Teacher ID For Search : ";
        H::gotoxy(106, 39);
        cin.getline(searchID, 20);

        fstream teachF("../data/Teacher_Data.bin", ios::in | ios::binary); //open file
        if (!teachF) {
            H::gotoxy(62, 2);
            cout << "Cannot open teacher data file!";
            getch();
            return;
        }

        Teacher t;
        while (teachF.read((char*)&t, sizeof(t))) { // read data from file 
            if (strcmp(t.getTeacherId(), searchID) == 0) { // compare ID that user search and id data in file 
                found = true;
                H::cls();
                H::setcolor(4);
                TeacherDesign::asciiSearchTeacher();
                TeacherDesign::designTable();
                t.output(20);
                break;
            }
        }
        teachF.close();

        H::gotoxy(70, 40);
        H::foreColor(0);
        if (found) {
            cout << "Press [ENTER] to search again or [ESC] to go back to menu.";
        } else {
            H::cls();
            H::setcolor(4);
            TeacherDesign::asciiSearchTeacher();
            TeacherDesign::designTable();
            TeacherDesign::asciiTeacherNotFound();
            H::gotoxy(70, 40);
            cout << "Teacher ID not found. Press [ENTER] to try again or [ESC] to go back.";
        }

        key = getch();
        if (key == 27) { // ESC
//            H::cls();
//            TeacherDesign::designTable();
//            TeacherDesign::showTeacher();
            return;
        }
    } while (true);
}


void TeacherDesign::updateTeacher(){
	H::setFixedScreenConsole(200,45);
	H::cls();
	H::foreColor(3); H::gotoxy(56, 9);  cout << R"( _____  _____  _______  ______        _     _________  _____  ____  _____    ______  )";
	H::foreColor(3); H::gotoxy(56, 10); cout << R"(|_   _||_   _||_   __ \|_   _ `.     / \   |  _   _  ||_   _||_   \|_   _| .' ___  | )";
	H::foreColor(3); H::gotoxy(56, 11); cout << R"(  | |    | |    | |__) | | | `. \   / _ \  |_/ | | \_|  | |    |   \ | |  / .'   \_|)";
	H::foreColor(3); H::gotoxy(56, 12); cout << R"(  | '    ' |    |  ___/  | |  | |  / ___ \     | |      | |    | |\ \| |  | |   ____ )";
	H::foreColor(3); H::gotoxy(56, 13); cout << R"(   \ \__/ /    _| |_    _| |_.' /_/ /   \ \_  _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
	H::foreColor(7); H::gotoxy(56, 14); cout << R"(    `.__.'    |_____|  |______.'|____| |____||_____|  |_____||_____|\____| `._____.' )";

	TeacherDesign::loading();
	H::cls();
    int x;
	do {
		Teacher t;
		char updateId[20];
		bool isUpdate = false;

		H::cls();
		TeacherDesign::allformForInput();
		H::drawBoxSingleLine(50, 5, 100, 7, 153);
		H::foreColor(154); H::gotoxy(49, 5); cout << "><";
		H::delay(10); H::foreColor(3); H::gotoxy(63, 6); cout << R"( _   _           _       _         _____               _                )";
		H::delay(10); H::foreColor(4); H::gotoxy(63, 7); cout << R"(| | | |_ __   __| | __ _| |_ ___  |_   _|__  __ _  ___| |__   ___ _ __ )";
		H::delay(10); H::foreColor(5); H::gotoxy(63, 8); cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
		H::delay(10); H::foreColor(6); H::gotoxy(63, 9); cout << R"(| |_| | |_) | (_| | (_| | ||  __/   | |  __/ (_| | (__| | | |  __/ |   )";
		H::delay(10); H::foreColor(7); H::gotoxy(63, 10); cout << R"(\___/| .__/ \__,_|\__,_|\__\___|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
		H::delay(10); H::foreColor(7); H::gotoxy(63, 11); cout << R"(       |_|                                                               )";
		H::gotoxy(70, 26); cout << "Enter Teacher ID for Update :";
		H::gotoxy(100, 26); cin >> updateId;

		fstream teachF("../data/Teacher_Data.bin", ios::in | ios::out | ios::binary); // open file
		if (!teachF) {
			H::gotoxy(63, 28); cout << "Cannot open file!";
			break;
		}

		while (teachF.read((char*)&t, sizeof(t))) { // read data from file
			if (strcmp(t.getTeacherId(), updateId) == 0) {
				isUpdate = true;
				t.newInput();
				H::foreColor(0);
				teachF.seekp((int)teachF.tellg() - sizeof(t));
				teachF.write((char*)&t, sizeof(t));
				break;
			}
		}
		teachF.close();

		if (isUpdate) {
			break;
		} else {
			H::cls();
			TeacherDesign::allformForWrongInput();
			H::gotoxy(75, 25); H::foreColor(4);
			cout << " Oops! TEACHER ID " << updateId << " WERE NOT FOUND !  ";
			H::gotoxy(75, 27); H::foreColor(0);
			cout << "PRESS KEY ";
			H::foreColor(4); cout << "[ESC]";
			H::foreColor(0); cout << " FOR BACK TO MENU!";
			x = getch();
			if(x == 27) return;
		}
	} while (true);

	H::cls();
	H::foreColor(0);
}
fstream backup;
void TeacherDesign::deletedTeacher(){
	H::cls();
	H::foreColor(3); H::gotoxy(60, 9); cout << R"( ______   ________  _____     ________  _________   _____  ____  _____    ______  )";
  	H::foreColor(3); H::gotoxy(60, 10); cout << R"(|_   _ `.|_   __  ||_   _|   |_   __  ||  _   _  ||_   _||_   \|_   _| .' ___  | )";
  	H::foreColor(3); H::gotoxy(60, 11); cout << R"(  | | `. \ | |_ \_|  | |       | |_ \_||_/ | | \_|  | |    |   \ | |  / .'   \_| )";
  	H::foreColor(3); H::gotoxy(60, 12); cout << R"(  | |  | | |  _| _   | |   _   |  _| _     | |      | |    | |\ \| |  | |   ____ )";
  	H::foreColor(3); H::gotoxy(60, 13); cout << R"( _| |_.' /_| |__/ | _| |__/ | _| |__/ |   _| |_    _| |_  _| |_\   |_ \ `.___]  |)";
  	H::foreColor(7); H::gotoxy(60, 14); cout << R"(|______.'|________||________||________|  |_____|  |_____||_____|\____| `._____.' )";
	TeacherDesign::loading();
	H::cls();
    int x;
    do {
        bool isDeleted = false;
        char deleteId[20];
		H::setcolor(4);
	    H::gotoxy(14,1);	cout << R"( | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |)";
		H::gotoxy(13, 2); cout << R"(_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|)";
		H::gotoxy(12, 3); cout << R"(UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU)";
			
		TeacherDesign::designTable();
		TeacherDesign::showTeacher();
		TeacherDesign::asciiDelete();
		H::drawBoxSingleLine(77,38,37,1,1);
      	H::gotoxy(78, 39); cout << "ENTER TEACHER ID TO DELETE :";
        H::gotoxy(106,39); cin >> deleteId;

        fstream backup("../data/backup_data.bin", ios::out | ios::binary); // create back up file
        fstream teachF("../data/Teacher_Data.bin", ios::in | ios::binary); // open file

        if (!teachF) {
            H::gotoxy(75, 28);
            cout << "Cannot open file!";
            break;
        }

        while (teachF.read((char*)&t, sizeof(t))) {
            if (strcmp(t.getTeacherId(), deleteId) == 0) {
                isDeleted = true;
                continue; 
            }
            backup.write((char*)&t, sizeof(t));
        }

        teachF.close();
        teachF.flush();
        backup.close();

        remove("../data/Teacher_Data.bin"); // remove  file
        rename("../data/backup_data.bin", "../data/Teacher_Data.bin"); // rename from back up to teacherData file

        if (isDeleted) {
            H::foreColor(2);
			TeacherDesign::designTable();
			TeacherDesign::showTeacher();
			TeacherDesign::asciiDelete();
            H::foreColor(2); H::gotoxy(76, 35); cout << "Teacher ID " << deleteId << " deleted successfully!";
            break;
        } else {
			H::cls();
			H::setcolor(4);
			cout << R"( | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |)";
			H::gotoxy(13, 2); cout << R"(_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|)";
			H::gotoxy(12, 3); cout << R"(UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU)";
			
			H::delay(10); H::foreColor(3); H::gotoxy(63, 4);  cout << R"( ____       _      _         _____               _                )";
			H::delay(10); H::foreColor(4); H::gotoxy(63, 5);  cout << R"(|  _ \  ___| | ___| |_ ___  |_   _|__  __ _  ___| |__   ___ _ __ )";
			H::delay(10); H::foreColor(5); H::gotoxy(63, 6);  cout << R"(| | | |/ _ \ |/ _ \ __/ _ \   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|)";
			H::delay(10); H::foreColor(6); H::gotoxy(63, 7);  cout << R"(| |_| |  __/ |  __/ ||  __/   | |  __/ (_| | (__| | | |  __/ |   )";
			H::delay(10); H::foreColor(7); H::gotoxy(63, 8); cout << R"(|____/ \___|_|\___|\__\___|   |_|\___|\__,_|\___|_| |_|\___|_|   )";
			H::HLine(63, 10, 66, 5, 223);
			
			TeacherDesign::designTable();
			
			H::gotoxy(52, 26); H::setcolor(4); cout << R"(  _____               _                  _   _       _      _____                     _   _ _ _   )";
			H::gotoxy(52, 27); H::setcolor(4); cout << R"( |_   _|__  __ _  ___| |__   ____ __    | \ | | ___ | |_   |  ___|__  _   _ _ __   __| | | | | |  )";
			H::gotoxy(52, 28); H::setcolor(4); cout << R"(   | |/ _ \/ _` |/ __| '_ \ / _ \ '__|  |  \| |/ _ \| __|  | |_ / _ \| | | | '_ \ / _` | | | | |  )";
			H::gotoxy(52, 29); H::setcolor(4); cout << R"(   | |  __/ (_| | (__| | | |  __/ |     | |\  | (_) | |_   |  _| (_) | |_| | | | | (_| | |_|_|_|  )";
			H::gotoxy(52, 30); H::setcolor(4); cout << R"(   |_|\___|\__,_|\___|_| |_|\___| |_|   |_| \_|\___/ \__|  |_|  \___/ \__,_|_| |_|\__,_| (_|_|_)  )";
            if (x != 27) break; 
        }

    } while (true);
	
	getch();
    H::cls();
	
}
void TeacherDesign::sortTeacherByName() {
    H::setFixedScreenConsole(200, 45);
    H::cls();
    TeacherDesign::sorting();
    TeacherDesign::loading();

    char key;
    do {
        H::cls();  
        TeacherDesign::allformForInput();
        H::drawBoxSingleLine(50, 5, 100, 7, 153);
        H::foreColor(154); H::gotoxy(49, 5); cout << "><";  
        H::delay(10); H::foreColor(3); H::gotoxy(63, 6);  cout << R"(  ____             _    ____          _   _                      )";
        H::delay(10); H::foreColor(4); H::gotoxy(63, 7);  cout << R"( / ___|  ___  _ __| |_ | __ ) _   _  | \ | | __ _ _ __ ___   ___ )";
        H::delay(10); H::foreColor(5); H::gotoxy(63, 8);  cout << R"(\___ \ / _ \| '__| __| |  _ \| | | | |  \| |/ _` | '_ ` _ \ / _ \)";
        H::delay(10); H::foreColor(6); H::gotoxy(63, 9);  cout << R"( ___) | (_) | |  | |_  | |_) | |_| | | |\  | (_| | | | | | |  __/)";
        H::delay(10); H::foreColor(7); H::gotoxy(63, 10); cout << R"(|____/ \___/|_|   \__| |____/ \__, | |_| \_|\__,_|_| |_| |_|\___|)";
        H::delay(10); H::foreColor(7); H::gotoxy(63, 11); cout << R"(                              |___/                              )";

        H::gotoxy(70, 26); cout << "Press Enter To Sort Data or ESC to Cancel!";
        key = getch();
        if (key == 27) {
            return; 
        } else if (key != 13) {
            continue; 
        }

        const int MAX_TEACHERS = 100;
        Teacher teachers[MAX_TEACHERS];
        int count = 0;

        fstream teachF("../data/Teacher_Data.bin", ios::in | ios::binary); // open file
        if (!teachF) {
            H::gotoxy(60, 5);
            cout << "Error opening file!";
            getch();
            TeacherDesign::system();  
            return;
        }

        while (teachF.read((char*)&teachers[count], sizeof(Teacher)) && count < MAX_TEACHERS) { // read data from file
            count++;
        }
        teachF.close();

        if (count == 0) {
            H::cls();
            H::gotoxy(70, 15);
            cout << "No teacher records found!";
            getch();
            TeacherDesign::system(); 
            return;
        }

        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (strcmp(teachers[j].getTeacherName(), teachers[j + 1].getTeacherName()) > 0) {
                    Teacher temp = teachers[j];
                    teachers[j] = teachers[j + 1];
                    teachers[j + 1] = temp;
                }
            }
        }

        H::cls();
        H::setcolor(4);
        H::gotoxy(15, 1); cout << R"( | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |)";
        H::gotoxy(13, 2); cout << R"(_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_)";
        H::gotoxy(12, 3); cout << R"(UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU)";

        H::delay(50); H::foreColor(3); H::gotoxy(63, 6);  cout << R"(  ______     ___   _______   _________  _____  ____  _____   ______  )";
        H::delay(50); H::foreColor(4); H::gotoxy(63, 7);  cout << R"(.' ____ \  .'   `.|_   __ \ |  _   _  ||_   _||_   \|_   _|.' ___  | )";
        H::delay(50); H::foreColor(5); H::gotoxy(63, 8);  cout << R"(| (___ \_|/  .-.  \ | |__) ||_/ | | \_|  | |    |   \ | | / .'   \_| )";
        H::delay(50); H::foreColor(6); H::gotoxy(63, 9);  cout << R"( _.____`. | |   | | |  __ /     | |      | |    | |\ \| | | |   ____ )";
        H::delay(50); H::foreColor(7); H::gotoxy(63, 10); cout << R"(| \____) |\  `-'  /_| |  \ \_  _| |_    _| |_  _| |_\   |_\ `.___]  |)";
        H::delay(50); H::foreColor(7); H::gotoxy(63, 11); cout << R"( \______.' `.___.'|____| |___||_____|  |_____||_____|\____|`._____.' )";
        H::HLine(63, 13, 66, 5, 223);

        TeacherDesign::designTable();

        int y = 20;
        for (int i = 0; i < count; ++i) {
            teachers[i].output(y);
            y += 2;

            if (y > 45) {
                H::cls();
                TeacherDesign::designTable();
                y = 14;
            }
        }

        H::gotoxy(70, 44);
        H::foreColor(0);
        cout << "Press [ENTER] to sort again or [ESC] to return to menu.";
                while (true) {
            key = getch();
            if (key == 13) {
                break; 
            } else if (key == 27) {
                return;
            }
        }
    } while (true);
}
void TeacherDesign::teacherManagement(){
	H::setFixedScreenConsole(200, 45);
	// TeacherDesign::system();
	H::cls();
	H::foreColor(0);
	do{
		TeacherDesign::showdesign();
		
		H::drawBoxSingleLineWithBG(40,10,10,1,153); // short 
		H::foreColor(146);H::gotoxy(43,11);cout<<"SORT";
		
		H::drawBoxSingleLineWithBG(105,10,10,1,153); // delete
		H::drawBoxSingleLineWithBG(120,10,10,1,153); // update
		H::drawBoxSingleLineWithBG(135,10,10,1,153); // search
		H::drawBoxSingleLineWithBG(150,10,10,1,153); // button add
	
		H::foreColor(146);H::gotoxy(107,11);cout<<"DELETE";
		H::foreColor(146);H::gotoxy(122,11);cout<<"UPDATE";
		H::foreColor(146);H::gotoxy(137,11);cout<<"SEARCH";
		H::foreColor(146);H::gotoxy(153,11);cout<<"ADD";
		
		
		char option;
		int x=0;
		
		do{	
				H::foreColor(146);H::gotoxy(43,11);cout<<"SORT";
				H::foreColor(146);H::gotoxy(107,11);cout<<"DELETE";
				H::foreColor(146);H::gotoxy(122,11);cout<<"UPDATE";
				H::foreColor(146);H::gotoxy(137,11);cout<<"SEARCH";
				H::foreColor(146);H::gotoxy(153,11);cout<<"ADD";
				
				if(x==0){
				H::foreColor(158);H::gotoxy(43,11);cout<<"SORT";	
				}
				if(x==1){
					H::foreColor(158);H::gotoxy(107,11);cout<<"DELETE";
				}
				if(x==2){
					H::foreColor(158);H::gotoxy(122,11);cout<<"UPDATE";
		
				}
				if(x==3){
				
					H::setcolor(158);H::gotoxy(137,11);cout<<"SEARCH";
				}
				if(x==4){
					H::setcolor(158);H::gotoxy(153,11);cout<<"ADD";
	
				}
		
				option=getch();
				switch(option){
					case 75:{ // left
						x--;
						if(x<0){
							x=4;
						}
						break;
					}case 77:{ // right
						x++;
						if(x>4){
							x=0;
						}
						break;
					}
				}
	    	}while(option!=13);	
			H::cls();
			
			if(x==0){
			H::foreColor(0);
			sortTeacherByName();
			
			}if(x==1){
			
				H::foreColor(0);
				TeacherDesign::deletedTeacher();
			}
			if(x==2){
				H::foreColor(0);
				TeacherDesign::updateTeacher();
			}
			if(x==3){
				H::foreColor(0);
				TeacherDesign::searchTeacher();
			}	
			if(x==4){
				char op;
				H::foreColor(0);
				TeacherDesign::insertTeacher();
			}
			H::cls();
	}while(true);

}


#endif