#ifndef __CUSTOM_HEADER_IN_EDU__
#define __CUSTOM_HEADER_IN_EDU__
#include "../Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

class EdumasterCustom{
    public:
        static int ArrowKeyConTrol(int maxOption, int _stepDown_UP, int fchoice,int option) ; // For all arrow key control data need : Max OPtion, step of up and down arrow, fchoice selected and option number
        static void LoadingPage(int x, int y, int width, int speed); // for make loading bar need x, y , width , speed of loading
};

int EdumasterCustom::ArrowKeyConTrol(int maxOption, int _stepDown_UP, int fchoice, int option){
	int step = fchoice;
    if (option == 224) {
        // Arrow key pressed
        int direction = getch();
        
		    if (direction == 77) { // Right arrow    
		        if (step == maxOption) {
		            step = 1;
		        }
		        else {
		            step++;
		        }
		    } 

		    else if (direction == 75) { // Left arrow
		        if (step == 1) {
		            step = maxOption;
		        }
		        else {
		            step--;
		        }
		    } 

		    else if (direction == 80) { // Down arrow        
		        if (step <= maxOption- _stepDown_UP) {
		            step = step + _stepDown_UP;
		        }
		        else {
		            step = step - (maxOption- _stepDown_UP);  //reset
		        }
		    } 
            
		    else if (direction == 72) { // Up arrow  
		        if (step > _stepDown_UP) {
		            step = step - _stepDown_UP;
		        }
		        else {
		            step = step + (maxOption- _stepDown_UP);   //reset
		        }
		    }
    }
    return step;
}

void EdumasterCustom::LoadingPage(int x, int y, int width, int speed) {
    H::setcolor(7);H::gotoxy(x,y-1);cout<<"LOADING...";
    H::drawBoxSingleLineWithBG(x, y, width+5, 1, 15);
    for (int i = 0; i <= width; i++) {
        H::HLine(x + i, y + 1, 1, 15, 177);
        cout<<((i*100)/width)<<"%";
        H::delay(speed);
    }
}

#endif