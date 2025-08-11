#ifndef HEADER_ASSIGNHOMEWORK_H
#define HEADER_ASSIGNHOMEWORK_H


#include "../Header_School/ANTHinsyOOP"
#include "DesignAssignHomework.h"
using namespace ANTHinsyOOP;

class AssignHomework {
private:
    char teacherName[50];
    int teacherGrade; 
    char subject[20];
    char startDate[11];  
    char dueDate[11];
    char task[50];
    char status[20];

public:
    void inputHomework();
    void displayHomework();
    void firstScreenAssign();
    void Main_AssignHomework();
};

AssignHomework homework;

void AssignHomework::inputHomework() {
    H::foreColor(6);
    H::gotoxy(35, 10);
    cout << "ENTER TEACHER NAME  :";
    H::gotoxy(57, 10);
    cin >> teacherName;

    if (strcmp(teacherName, "nich") == 0) {
        H::foreColor(6);H::gotoxy(129,10);
        cout << "ENTER TEACHER GRADE :";H::gotoxy(150,10);
        cin >> teacherGrade;

        if (teacherGrade == 10 || teacherGrade == 11 || teacherGrade == 12) {
            H::clearBox(50,20,124,21,1);
            for (int x = 50; x <= 173; x++){ 
				H::gotoxy(x, 19); cout << char(178); H::delay(1);
			}
			
            for (int y = 19; y <= 41; y++) {
			 H::gotoxy(50, y); cout << char(178); H::delay(1);
			}
			
            for (int y = 19; y <= 41; y++) {
			 H::gotoxy(173, y); cout << char(178); H::delay(1);
			}
			 
            for (int x = 50; x <= 173; x++) {
			 H::gotoxy(x, 41); cout << char(178); H::delay(1);
			}
            
            
            H::drawBoxSingleLine(64,24,40,1,3);
            H::foreColor(3); H::gotoxy(65,25); cout << "ENTER SUBJECT :";
            
            H::drawBoxSingleLine(123,24,40,1,3);
            H::foreColor(3); H::gotoxy(124,25); cout << "ENTER SET DATE:";
            
            H::drawBoxSingleLine(64,34,40,1,3);
            H::foreColor(3); H::gotoxy(65,35); cout << "ENTER DUE DATE :";
            
            H::drawBoxSingleLine(123,34,40,1,3);
            H::foreColor(3); H::gotoxy(124,35); cout << "TASK :";
            
            H::gotoxy(80,25); H::inputLetter(subject, sizeof(subject)-1);
            H::gotoxy(140,25); H::inputDate(startDate, '/', false);
            H::gotoxy(81,35); H::inputDate(dueDate, '/', false);
            H::gotoxy(130,35); H::inputLetter(task,40);

            strcpy(status, "Incomplete"); 

        } else {
            DesignAssHomework::designWrongInput();
        }
    } else {
        DesignAssHomework::designWrongInput();
    }
   
}

void AssignHomework::displayHomework() {
    H::cls();
    DesignAssHomework::asciiAsignHomework();
    DesignAssHomework::AssignHomeworkTable();

    H::gotoxy(36, 10);  cout << "TEACHER NAME : " << teacherName;
    H::gotoxy(130, 10); cout << "TEACHER GRADE: " << teacherGrade;
    int y = 20;
    H::gotoxy(56, y);  cout << subject;    
    H::gotoxy(72, y);  cout << startDate;   
    H::gotoxy(94, y); cout << dueDate;     
    H::gotoxy(114, y); cout << task;        
    H::gotoxy(159, y); cout << status;     
}

void AssignHomework::firstScreenAssign(){

	DesignAssHomework::asciiAsignHomework();
    H::drawBoxDoubleLine(35,9,42,1,3);
	H::drawBoxDoubleLine(129,9,40,1,3);
	
//	H::gotoxy(36,10);cout<<"[!] USE [UP] [DOWN] ARROW KEY FOR SELECT ";
//	H::gotoxy(132,10);cout<<"PRESS [ESC] FOR [BACK TO MENU]";

	// First line
	H::gotoxy(36,10); 
	H::setcolor(7); // White
	cout << "[!] USE ";
	H::setcolor(2); // Green
	cout << "[UP] [DOWN]";
	H::setcolor(7); // White
	cout << " ARROW KEY FOR SELECT ";
	
	// Second line
	H::gotoxy(136,10); 
	H::setcolor(7); // White
	cout << "PRESS ";
	H::setcolor(2); // Green
	cout << "[ESC] [BACK TO MENU]";
	H::setcolor(7); // White

	
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
	
	do{	
		int x =0;
		char op;
		do{
			
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
			
			
			if(x==0){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,16);cout<<"MON/SAT";	
			}
			if(x==1){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,20);cout<<"MONDAY";	
			}
			if(x==2){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,24);cout<<"TUESDAY";	
			}
			if(x==3){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,28);cout<<"WEDNESDAY";	
			}
			if(x==4){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,32);cout<<"THURDAY";	
			}
			if(x==5){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,36);cout<<"FRIDAY";	
			}
			if(x==6){
				
				H::drawBoxDoubleLine(30,14,145,27,2);
				H::gotoxy(35,40);cout<<"SATURDAY";	
			}
			op = getch();
		
		        switch (op) {
		            case 72: 
		                x--;
		                if (x < 0) {
		                	x = 8; 
						} 
		            break;
		            case 80: 
		                x++;
		                if (x > 8){
		                	x = 0;  
						}
		            break;
		        }
		}while(op!=13);
		H::cls();
		
		    if (x == 0) {
		    	H::cls();
		    	DesignAssHomework::asciiAsignHomework();
    			DesignAssHomework::AssignHomeworkTable();
				AssignHomework::inputHomework(); 
				AssignHomework::displayHomework();		    
			}
		    if(x==1){
		    	H::cls();
		    	DesignAssHomework::asciiAsignHomework();
    			DesignAssHomework::AssignHomeworkTable();
		    	AssignHomework::inputHomework();
		    }
		    if (x == 2) {
		    	H::cls();
		    	DesignAssHomework::asciiAsignHomework();
    			DesignAssHomework::AssignHomeworkTable();
		    	AssignHomework::inputHomework(); 
		    }
		    if (x == 3) {
		    	H::cls();
		    	DesignAssHomework::asciiAsignHomework();
    			DesignAssHomework::AssignHomeworkTable();
		    	AssignHomework::inputHomework();
		    }
		    if (x == 4) {
		    	H::cls();
		    	AssignHomework::inputHomework(); 
		    }
		    if (x == 5) {
		    	H::cls();
		    	DesignAssHomework::asciiAsignHomework();
    			DesignAssHomework::AssignHomeworkTable();
		    	AssignHomework::inputHomework();
		    }
		    if (x == 6) {
		    	H::cls();
		    	DesignAssHomework::asciiAsignHomework();
    			DesignAssHomework::AssignHomeworkTable();
		    	AssignHomework::inputHomework();
		    	H::cls();
		    	AssignHomework::displayHomework();
		    }
	}while(true);
	getch();
    H::cls();
}

void AssignHomework::Main_AssignHomework() {
//	AssignHomework::firstScreenAssign();
    DesignAssHomework::asciiAsignHomework();
    DesignAssHomework::AssignHomeworkTable();
    homework.inputHomework();
    homework.displayHomework();
}

#endif
