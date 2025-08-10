#ifndef ___INC_QUIZ_DESIGN_H___
#define ___INC_QUIZ_DESIGN_H___

#include "../Header_School/ANTHinsyOOP"
#include "ManageQuiz.h"
using namespace ANTHinsyOOP;

class QuizDesign{
    public:
        static void QuizMenu();
        static void QuizMenuScreen();
        static void QuizGradeScreen();
        static void Grade10();
        static void Grade11();
        static void Grade12();
        static void QuizGButton();
        static void QuizButton();
        static void Quiz_Select();
        static void QuizCreateButton();
        static void QuizUpdateButton();
        static void QuizDeleteButton();

        void gradeTitle(int grade);
        void ManageQuizMenu(int grade);
};

QuizDesign quizD;

void QuizDesign::QuizCreateButton() {
    H::setcolor(7); H::gotoxy(102, 13); cout << R"(  ____                _             ___        _     )";
    H::setcolor(7); H::gotoxy(102, 14); cout << R"( / ___|_ __ ___  __ _| |_ ___      / _ \ _   _(_)____)";
    H::setcolor(1); H::gotoxy(102, 15); cout << R"(| |   | '__/ _ \/ _` | __/ _ \    | | | | | | | |_  /)";
    H::setcolor(1); H::gotoxy(102, 16); cout << R"(| |___| | |  __/ (_| | ||  __/    | |_| | |_| | |/ / )";
    H::setcolor(7); H::gotoxy(102, 17); cout << R"( \____|_|  \___|\__,_|\__\___|     \__\_\\__,_|_/___|)";

    H::setcolor(7); H::gotoxy(104, 21); cout << R"(     __________________   __________________                ___   )";
    H::setcolor(7); H::gotoxy(104, 22); cout << R"( .-/|  ---  Quiz  ---  \ /                  |\-.           |___|  )";
    H::setcolor(7); H::gotoxy(104, 23); cout << R"( ||||                   |                   ||||           |   |\_)";
    H::setcolor(7); H::gotoxy(104, 24); cout << R"( ||||  Q: ____________  |  Q: ____________  ||||           |   | |)";
    H::setcolor(7); H::gotoxy(104, 25); cout << R"( ||||                   |                   ||||           |   | |)";
    H::setcolor(7); H::gotoxy(104, 26); cout << R"( ||||    1. _______     |    1. _______     ||||           | W | |)";
    H::setcolor(7); H::gotoxy(104, 27); cout << R"( ||||                   |                   ||||           | K |_|)";
    H::setcolor(7); H::gotoxy(104, 28); cout << R"( ||||    2. _______     |    2. _______     ||||           | N |  )";
    H::setcolor(7); H::gotoxy(104, 29); cout << R"( ||||                   |                   ||||           | R |  )";
    H::setcolor(7); H::gotoxy(104, 30); cout << R"( ||||    3. _______     |    3. _______     ||||           |   |  )";
    H::setcolor(7); H::gotoxy(104, 31); cout << R"( ||||                   |                   ||||           |   |  )";
    H::setcolor(7); H::gotoxy(104, 32); cout << R"( ||||    4. _______     |    4. _______     ||||           | _ |  )";
    H::setcolor(7); H::gotoxy(104, 33); cout << R"( ||||__________________ | __________________||||            \_/   )";
    H::setcolor(7); H::gotoxy(104, 34); cout << R"( ||/===================\|/===================\||             v    )";
    H::setcolor(7); H::gotoxy(104, 35); cout << R"( `--------------------~___~-------------------''                  )";
}

void QuizDesign::QuizUpdateButton(){
    H::setcolor(7); H::gotoxy(102, 13); cout << R"( _   _           _       _             ___        _     )";
    H::setcolor(7); H::gotoxy(102, 14); cout << R"(| | | |_ __   __| | __ _| |_ ___      / _ \ _   _(_)____)";
    H::setcolor(2); H::gotoxy(102, 15); cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \    | | | | | | | |_  /)";
    H::setcolor(2); H::gotoxy(102, 16); cout << R"(| |_| | |_) | (_| | (_| | ||  __/    | |_| | |_| | |/ / )";
    H::setcolor(7); H::gotoxy(102, 17); cout << R"( \___/| .__/ \__,_|\__,_|\__\___|     \__\_\\__,_|_/___|)";
    H::setcolor(7); H::gotoxy(102, 18); cout << R"(      |_|                                               )";


    H::setcolor(4); H::gotoxy(88, 29); cout << R"( __________)";
    H::setcolor(4); H::gotoxy(88, 30); cout << R"(|__________|)";
    H::setcolor(7); H::gotoxy(88, 31); cout << R"(|          |)";
    H::setcolor(7); H::gotoxy(88, 32); cout << R"(|          |)";
    H::setcolor(7); H::gotoxy(88, 33); cout << R"(|__________|)";
    H::setcolor(6); H::gotoxy(91, 32); cout << "Eraser";


    H::setcolor(7); H::gotoxy(104, 21); cout << R"(     __________________   __________________                ___   )";
    H::setcolor(7); H::gotoxy(104, 22); cout << R"( .-/|  ---  Quiz  ---  \ /                  |\-.           |___|  )";
    H::setcolor(7); H::gotoxy(104, 23); cout << R"( ||||                   |                   ||||           |   |\_)";
    H::setcolor(7); H::gotoxy(104, 24); cout << R"( ||||  Q: ____________  |  Q: ____________  ||||           |   | |)";
    H::setcolor(7); H::gotoxy(104, 25); cout << R"( ||||                   |                   ||||           |   | |)";
    H::setcolor(7); H::gotoxy(104, 26); cout << R"( ||||    1. _______     |    1. _______     ||||           | W | |)";
    H::setcolor(7); H::gotoxy(104, 27); cout << R"( ||||                   |                   ||||           | K |_|)";
    H::setcolor(7); H::gotoxy(104, 28); cout << R"( ||||    2. _______     |    2. _______     ||||           | N |  )";
    H::setcolor(7); H::gotoxy(104, 29); cout << R"( ||||                   |                   ||||           | R |  )";
    H::setcolor(7); H::gotoxy(104, 30); cout << R"( ||||    3. _______     |    3. _______     ||||           |   |  )";
    H::setcolor(7); H::gotoxy(104, 31); cout << R"( ||||                   |                   ||||           |   |  )";
    H::setcolor(7); H::gotoxy(104, 32); cout << R"( ||||    4. _______     |    4. _______     ||||           | _ |  )";
    H::setcolor(7); H::gotoxy(104, 33); cout << R"( ||||__________________ | __________________||||            \_/   )";
    H::setcolor(7); H::gotoxy(104, 34); cout << R"( ||/===================\|/===================\||             v    )";
    H::setcolor(7); H::gotoxy(104, 35); cout << R"( `--------------------~___~-------------------''                  )";
}

void QuizDesign::QuizDeleteButton() {

    H::setcolor(7); H::gotoxy(102, 13); cout << R"( ____       _      _             ___        _     )";
    H::setcolor(7); H::gotoxy(102, 14); cout << R"(|  _ \  ___| | ___| |_ ___      / _ \ _   _(_)____)";
    H::setcolor(4); H::gotoxy(102, 15); cout << R"(| | | |/ _ \ |/ _ \ __/ _ \    | | | | | | | |_  /)";
    H::setcolor(4); H::gotoxy(102, 16); cout << R"(| |_| |  __/ |  __/ ||  __/    | |_| | |_| | |/ / )";
    H::setcolor(7); H::gotoxy(102, 17); cout << R"(|____/ \___|_|\___|\__\___|     \__\_\\__,_|_/___|)";

    H::setcolor(7); H::gotoxy(104, 21); cout << R"(     __________________   __________________    )";
    H::setcolor(7); H::gotoxy(104, 22); cout << R"( .-/|  ---  Quiz  ---  \ /    \             |\-.)";
    H::setcolor(7); H::gotoxy(104, 23); cout << R"( ||||                   |     /             ||||)";
    H::setcolor(7); H::gotoxy(104, 24); cout << R"( ||||  Q: ____________  |  Q:/ ___________  ||||)";
    H::setcolor(7); H::gotoxy(104, 25); cout << R"( ||||                   |    \              ||||)";
    H::setcolor(7); H::gotoxy(104, 26); cout << R"( ||||    1. _______     |     \ _______     ||||)";
    H::setcolor(7); H::gotoxy(104, 27); cout << R"( ||||                   |     /             ||||)";
    H::setcolor(7); H::gotoxy(104, 28); cout << R"( ||||    2. _______     |     \ _______     ||||)";
    H::setcolor(7); H::gotoxy(104, 29); cout << R"( ||||                   |     /             ||||)";
    H::setcolor(7); H::gotoxy(104, 30); cout << R"( ||||    3. _______     |     \ _______     ||||)";
    H::setcolor(7); H::gotoxy(104, 31); cout << R"( ||||                   |     /             ||||)";
    H::setcolor(7); H::gotoxy(104, 32); cout << R"( ||||    4. _______     |     \ _______     ||||)";
    H::setcolor(7); H::gotoxy(104, 33); cout << R"( ||||__________________ | ____/_____________||||)";
    H::setcolor(7); H::gotoxy(104, 34); cout << R"( ||/===================\|/===================\||)";
    H::setcolor(7); H::gotoxy(104, 35); cout << R"( `--------------------~___~-------------------'')";
}
  
void QuizDesign::QuizButton() {
    H::drawBoxSingleLineWithBG(16, 14, 40, 3, 5);
	H::setcolor(7); H::gotoxy(24, 16); cout << "C R E A T E   Q U I Z";
	H::drawBoxSingleLineWithBG(16, 20, 40, 3, 5);
	H::setcolor(7); H::gotoxy(24, 22); cout << "U P D A T E   Q U I Z";
	H::drawBoxSingleLineWithBG(16, 26, 40, 3, 5);
	H::setcolor(7); H::gotoxy(24, 28); cout << "D E L E T E   Q U I Z";
	H::drawBoxSingleLineWithBG(16, 32, 40, 3, 4);
	H::setcolor(7); H::gotoxy(31, 34); cout << "B A C K";
}

void QuizDesign::QuizMenu() {
    H::setcolor(6);  H::gotoxy(1,3); cout << R"( .--..--..--..--..--..--..--..--..--..--..--..--..--.)";
    H::setcolor(6);  H::gotoxy(1,4); cout << R"(\.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \)";
    H::setcolor(6);  H::gotoxy(1,5); cout << R"(\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\)";
    H::setcolor(6);  H::gotoxy(1,6); cout << R"(`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`)";

    H::setcolor(6);  H::gotoxy(146,3); cout << R"( .--..--..--..--..--..--..--..--..--..--..--..--..--.)";
    H::setcolor(6);  H::gotoxy(146,4); cout << R"(\.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \)";
    H::setcolor(6);  H::gotoxy(146,5); cout << R"(\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\)";
    H::setcolor(6);  H::gotoxy(146,6); cout << R"(`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`)";

    system("chcp 65001  > nul");
    H::setcolor(4); H::gotoxy(60, 2); cout << R"( ███╗   ███╗ █████╗ ███╗   ██╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗██╗███████╗ )";
    H::setcolor(3); H::gotoxy(60, 3); cout << R"( ███╗  ████║██╔══██╗████╗  ██║██╔════╝ ██╔════╝    ██╔═══██╗██║   ██║██║╚══███╔╝ )";
    H::setcolor(3); H::gotoxy(60, 4); cout << R"( ██╔████╔██║███████║██╔██╗ ██║██║  ███╗█████╗      ██║   ██║██║   ██║██║  ███╔╝  )";
    H::setcolor(3); H::gotoxy(60, 5); cout << R"( ██║╚██╔╝██║██╔══██║██║╚██╗██║██║   ██║██╔══╝      ██║▄▄ ██║██║   ██║██║ ███╔╝   )";
    H::setcolor(6); H::gotoxy(60, 6); cout << R"( ██║ ╚═╝ ██║██║  ██║██║ ╚████║╚██████╔╝███████╗    ╚██████╔╝╚██████╔╝██║███████╗ )";
    H::setcolor(6); H::gotoxy(60, 7); cout << R"( ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝     ╚══▀▀═╝  ╚═════╝ ╚═╝╚══════╝ )";
    system("chcp 437 > nul");

    H::drawBoxSingleLineWithBG(16, 14, 40, 3, 1);
	H::setcolor(7); H::gotoxy(27, 16); cout << "G R A D E    1 0";
	H::drawBoxSingleLineWithBG(16, 20, 40, 3, 1);
	H::setcolor(7); H::gotoxy(27, 22); cout << "G R A D E    1 1";
	H::drawBoxSingleLineWithBG(16, 26, 40, 3, 1);
	H::setcolor(7); H::gotoxy(27, 28); cout << "G R A D E    1 2";
	H::drawBoxSingleLineWithBG(16, 32, 40, 3, 4);
	H::setcolor(7); H::gotoxy(31, 34); cout << "B A C K";

    H::drawBoxSingleLineWithBG(2, 9, 1, 32, 206);
    H::drawBoxSingleLineWithBG(197, 9, 1, 32, 206);

    H::HLine(10, 11, 52, 7, 219);
    H::VLine(10, 10, 29, 7, 219);
    H::HLine(10, 63, 52, 7, 219);
    H::VLine(63, 10, 29, 7, 219);

    //Box
    H::drawBoxDoubleLine(70, 9, 120, 31, 2);
    H::drawBoxDoubleLineWithBG(72, 10, 116, 29, 2);
    QuizDesign::QuizMenuScreen();
    H::gotoxy(68, 43); H::setcolor(6);  cout << "[Tip!]"; H::setcolor(7);  cout << " : Use Arrow "; H::setcolor(1);  cout << "[Up]"; H::setcolor(7);  cout << " - Arrow "; H::setcolor(4);  cout << "[Down]"; H::setcolor(7); cout << " to Move | "; H::setcolor(2); cout << "[Enter]"; H::setcolor(7); cout << " to Select.";
}

void QuizDesign::QuizMenuScreen() {
    H::setcolor(7); H::gotoxy(72, 11); cout << R"(               ___                                                                  __                              )";
    H::setcolor(7); H::gotoxy(72, 12); cout << R"(              (`  ).                   _                                          (`  ).                   _        )";
    H::setcolor(7); H::gotoxy(72, 13); cout << R"(             (     ).              .:(`  )`.              .__                     (     ).              .:(`  )`.   )";
    H::setcolor(7); H::gotoxy(72, 14); cout << R"(            _(       '`.          :(   .    )          .-(`  )                  _(       '`.          :(   .    )   )";
    H::setcolor(7); H::gotoxy(72, 15); cout << R"(        .=(`(      .   )     .--  `.  (    ) )         (      ))            .=(`(      .   )     .--  `.  (    ) )  )";
    H::setcolor(7); H::gotoxy(72, 16); cout << R"(       ((    (..__.:'-'   . (   )   ` _`  ) )          (    )  ))          ((    (..__.:'-'   .+(   )   ` _`  ) )   )";
    H::setcolor(7); H::gotoxy(72, 17); cout << R"(`.     `(       ) )       (   .  )     (   )  ._        ` __.:'         `(       ) )       (   .  )     (   )  .    )";
    H::setcolor(7); H::gotoxy(72, 18); cout << R"(  )      ` __.:'   )     (   (   ))     `-'.-(`  )                    `( __.:'   )     (   (   ))     `-'.-(`  )    )";
    H::setcolor(7); H::gotoxy(72, 19); cout << R"()  )  ( )       --'       `- __.'         :(      ))        ( )              (--'       `- __.'         :(      ))  )";
    H::setcolor(7); H::gotoxy(72, 20); cout << R"(.-'  (_.'          .')                    `(    )  ))      (_.'                  .')                    `(    )  )) )";
    H::setcolor(7); H::gotoxy(72, 21); cout << R"(                  (_  )                     ` __.:'                             (_..)                     ` __.:'   )";
    H::setcolor(3); H::gotoxy(72, 22); cout << R"(                                                                                                                    )";
    H::setcolor(3); H::gotoxy(72, 23); cout << R"(                                                                                                                    )";
    H::setcolor(3); H::gotoxy(72, 24); cout << R"(                                                                                                                    )";
    H::setcolor(3); H::gotoxy(72, 25); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 26); cout << R"(                       .-.                 _                                              .-.                 _     )";
    H::setcolor(7); H::gotoxy(72, 27); cout << R"(                      /   \              _/ \                                            /   \              _/ \    )";
    H::setcolor(7); H::gotoxy(72, 28); cout << R"(         _        .--'\/\_ \            /    \       ___                    _        .--'\/\_ \            /    \   )";
    H::setcolor(7); H::gotoxy(72, 29); cout << R"(   _    / \_    _/ ^      \/\'__        /\/\  /\  __/   \     _            / \_    _/ ^      \/\ __        /\/\  /\ )";
    H::setcolor(7); H::gotoxy(72, 30); cout << R"(  / \  /    \  /    .'   _/  /  \     /    \/  \/ .`'\_/\    / \   _      /    \  /    .'   _/  /  \     /    \/   \)";
    H::setcolor(7); H::gotoxy(72, 31); cout << R"( /   \/\/\  /\/ :' __  ^/  ^/    `--./.'  ^  `-.\ _    _:\ _/   \_/ | _  /\/\  /\/ :' __  ^/  ^/    `--./.'  ^  `-..)";
    H::setcolor(2); H::gotoxy(72, 32); cout << R"(/    /    \/  \  _/  \-' __/.' ^ _   \_   .'\   _/ \ .  __/ \   /   |/ \/    \/  \  _/  \-' __/.' ^ _   \_   .'\   _)";
    H::setcolor(2); H::gotoxy(72, 33); cout << R"(   /\  .-   `. \/     \ / -.   _/ \ -. `_/   \ /    `._/  ^  \ /     \/\  .-   `. \/     \ / -.   _/ \ -. `_/   \ / )";
    H::setcolor(2); H::gotoxy(72, 34); cout << R"(  /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.     /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `--)";
    H::setcolor(2); H::gotoxy(72, 35); cout << R"(@/        `.  / /      `-.   /  .-'   / .   .'   \    \  \  .-  \   /        `.  / /      `-.   /  .-'   / .   .'   )";
    H::setcolor(1); H::gotoxy(72, 36); cout << R"(@&8jgs@@%% @)&@&(88&@.-_=_-=_-=_-=_-=_.8@% &@&&8(8%@%8)(8@%8 8%@)% @&8jgs@@%% @)&@&(88&@.-_=_-=_-=_-=_-=_.8@% &@&&88)";
    H::setcolor(1); H::gotoxy(72, 37); cout << R"(@88:::&(&8&&8:::::%&`.~-_~~-~~_~-~_~-~~=.'@(&%::::%@8&8)::&#@8:::: @88:::&(&8&&8:::::%&`.~-_~~-~~_~-~_~-~~=.'@(&%:::)";
    H::setcolor(1); H::gotoxy(72, 38); cout << R"(`::::::8%@@%:::::@%&8:`.=~~-.~~-.~~=..~'8::::::::&@8:::::&8:::::::::::::::8%@@%:::::@%&8:`.=~~-.~~-.~~=..~'8::::::::)";
    H::setcolor(1); H::gotoxy(72, 39); cout << R"( `::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::)";
}

void QuizDesign::QuizGradeScreen() {
    H::setcolor(3); H::gotoxy(72, 22); cout << R"(                                                                                           ________                 )";
    H::setcolor(3); H::gotoxy(72, 23); cout << R"(                                                                                          |        |                )";
    H::setcolor(3); H::gotoxy(72, 24); cout << R"(                                                                                          | School |                )";
    H::setcolor(3); H::gotoxy(72, 25); cout << R"(                                                                                          |________|                )";
    H::setcolor(7); H::gotoxy(72, 26); cout << R"(              (                                                                           |                         )";
    H::setcolor(7); H::gotoxy(72, 27); cout << R"(               )                                                                    _ _.-'`-._ _                    )";
    H::setcolor(7); H::gotoxy(72, 28); cout << R"(             ( _   _._                                                             ;.'________'.;                   )";
    H::setcolor(4); H::gotoxy(72, 29); cout << R"(              |_|-'_~_`-._                                              _________n.[____________].n_________        )";
    H::setcolor(4); H::gotoxy(72, 30); cout << R"(           _.-'-_~_-~_-~-_`-._                                         |""_""_""_""||==||==||==||""_""_""_""]       )";
    H::setcolor(4); H::gotoxy(72, 31); cout << R"(       _.-'_~-_~-_-~-_~_~-_~-_`-._                                     |"""""""""""||..||..||..||"""""""""""|       )";
    H::setcolor(6); H::gotoxy(72, 32); cout << R"(      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                    |LI LI LI LI||LI||LI||LI||LI LI LI LI|       )";
    H::setcolor(6); H::gotoxy(72, 33); cout << R"(        |  []  []   []   []  [] |                                      |.. .. .. ..||..||..||..||.. .. .. ..|       )";
    H::setcolor(6); H::gotoxy(72, 34); cout << R"(        |           __    ___   |                                      |LI LI LI LI||LI||LI||LI||LI LI LI LI|       )";
    H::setcolor(6); H::gotoxy(72, 35); cout << R"(._._._._|  []  []  | .|  [___]  |_._._._._._._._._._._._._._._._._._._/______________________________________\_._._.)";
    H::setcolor(6); H::gotoxy(72, 36); cout << R"(|=|=|=|=|________()|__|()_______|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|/----------------------------------------\|=|=|)";
    H::setcolor(7); H::gotoxy(72, 37); cout << R"(^^^^^^^^^^^^^^^^^^^ === ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^)";
    H::setcolor(7); H::gotoxy(72, 38); cout << R"(=   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   ===   === )";
    H::setcolor(7); H::gotoxy(72, 39); cout << R"(____________________________________________________________________________________________________________________)";
}

void QuizDesign::QuizGButton() {
    H::drawBoxSingleLineWithBG(16, 14, 40, 3, 1);
	H::setcolor(7); H::gotoxy(27, 16); cout << "G R A D E    1 0";
	H::drawBoxSingleLineWithBG(16, 20, 40, 3, 1);
	H::setcolor(7); H::gotoxy(27, 22); cout << "G R A D E    1 1";
	H::drawBoxSingleLineWithBG(16, 26, 40, 3, 1);
	H::setcolor(7); H::gotoxy(27, 28); cout << "G R A D E    1 2";
	H::drawBoxSingleLineWithBG(16, 32, 40, 3, 4);
	H::setcolor(7); H::gotoxy(31, 34); cout << "B A C K";
}

void QuizDesign::Quiz_Select() {
    int option;
    int x = 0;
    H::cls();
    QuizDesign::QuizMenu();
    do {
        H::setcursor(false, 0);
        QuizDesign::QuizGButton();
        if (x == 0) {
            H::drawBoxSingleLineWithBG(16, 14, 40, 3, 1);
            H::clearBox(16, 15, 40, 3, 151);
            H::setcolor(151); H::gotoxy(27, 16); cout << "G R A D E    1 0";
            QuizDesign::QuizGradeScreen();
        }
        if (x == 1) {
            H::drawBoxSingleLineWithBG(16, 20, 40, 3, 1);
            H::clearBox(16, 21, 40, 3, 151);
            H::setcolor(151); H::gotoxy(27, 22); cout << "G R A D E    1 1";
            QuizDesign::QuizGradeScreen();
        }
        if (x == 2) {
            H::drawBoxSingleLineWithBG(16, 26, 40, 3, 1);
            H::clearBox(16, 27, 40, 3, 151);
            H::setcolor(151); H::gotoxy(27, 28); cout << "G R A D E    1 2";
            QuizDesign::QuizGradeScreen();
        }
        if (x == 3) {
            H::drawBoxSingleLineWithBG(16, 32, 40, 3, 1);
            H::clearBox(16, 33, 40, 3, 199);
            H::setcolor(199); H::gotoxy(31, 34); cout << "B A C K";
            QuizDesign::QuizMenuScreen();
        }
        option = getch();

        switch (option) {
            case 72:
                x--;
                if (x < 0) x = 3;
                break;
            case 80:
                x++;
                if (x > 3) x = 0;
                break;
        }
    } while (option != 13);
    H::setcolor(1);
    H::cls();

    if (x == 3) {
        return; // or your BACK logic
    } else {
        // x is 0,1,2 means grade 10,11,12 respectively
        int grade = 10 + x;  // maps 0->10, 1->11, 2->12
        quizD.ManageQuizMenu(grade);
    }
}

void QuizDesign::gradeTitle(int grade) {
    if (grade == 10) {
        system("chcp 65001  > nul");
        H::setcolor(4); H::gotoxy(54, 2); cout << R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗   ██╗ ██████╗       ██████╗ ██╗   ██╗██╗███████╗ )";
        H::setcolor(3); H::gotoxy(54, 3); cout << R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝  ███║██╔═████╗     ██╔═══██╗██║   ██║██║╚══███╔╝ )";
        H::setcolor(3); H::gotoxy(54, 4); cout << R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗    ╚██║██║██╔██║     ██║   ██║██║   ██║██║  ███╔╝  )";
        H::setcolor(3); H::gotoxy(54, 5); cout << R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝     ██║████╔╝██║     ██║▄▄ ██║██║   ██║██║ ███╔╝   )";
        H::setcolor(6); H::gotoxy(54, 6); cout << R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗   ██║╚██████╔╝     ╚██████╔╝╚██████╔╝██║███████╗ )";
        H::setcolor(6); H::gotoxy(54, 7); cout << R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝   ╚═╝ ╚═════╝       ╚══▀▀═╝  ╚═════╝ ╚═╝╚══════╝ )";
        system("chcp 437 > nul");
    }
    else if (grade == 11) {
        system("chcp 65001  > nul");
        H::setcolor(4); H::gotoxy(56, 2); cout << R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗    ██╗ ██╗      ██████╗ ██╗   ██╗██╗███████╗ )";
        H::setcolor(3); H::gotoxy(56, 3); cout << R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝   ███║███║     ██╔═══██╗██║   ██║██║╚══███╔╝ )";
        H::setcolor(3); H::gotoxy(56, 4); cout << R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗     ╚██║╚██║     ██║   ██║██║   ██║██║  ███╔╝  )";
        H::setcolor(3); H::gotoxy(56, 5); cout << R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝      ██║ ██║     ██║▄▄ ██║██║   ██║██║ ███╔╝   )";
        H::setcolor(6); H::gotoxy(56, 6); cout << R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗    ██║ ██║     ╚██████╔╝╚██████╔╝██║███████╗ )";
        H::setcolor(6); H::gotoxy(56, 7); cout << R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝    ╚═╝ ╚═╝      ╚══▀▀═╝  ╚═════╝ ╚═╝╚══════╝ )";
        system("chcp 437 > nul");
    }
    else if (grade == 12) {
        system("chcp 65001  > nul");
        H::setcolor(4); H::gotoxy(55, 2); cout << R"(  ██████╗ ██████╗  █████╗ ██████╗ ███████╗   ██╗██████╗       ██████╗ ██╗   ██╗██╗███████╗ )";
        H::setcolor(3); H::gotoxy(55, 3); cout << R"( ██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██╔════╝  ███║╚════██╗     ██╔═══██╗██║   ██║██║╚══███╔╝ )";
        H::setcolor(3); H::gotoxy(55, 4); cout << R"( ██║  ███╗██████╔╝███████║██║  ██║█████╗    ╚██║ █████╔╝     ██║   ██║██║   ██║██║  ███╔╝  )";
        H::setcolor(3); H::gotoxy(55, 5); cout << R"( ██║   ██║██╔══██╗██╔══██║██║  ██║██╔══╝     ██║██╔═══╝      ██║▄▄ ██║██║   ██║██║ ███╔╝   )";
        H::setcolor(6); H::gotoxy(55, 6); cout << R"( ╚██████╔╝██║  ██║██║  ██║██████╔╝███████╗   ██║███████╗     ╚██████╔╝╚██████╔╝██║███████╗ )";
        H::setcolor(6); H::gotoxy(55, 7); cout << R"(  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝   ╚═╝╚══════╝      ╚══▀▀═╝  ╚═════╝ ╚═╝╚══════╝ )";
        system("chcp 437 > nul");
    }
}

void QuizDesign::ManageQuizMenu(int grade) {
    int option;
    int x = 0;

    H::cls();
    QuizDesign::QuizMenu();
    QuizDesign::gradeTitle(grade);
    do {
        H::setcursor(false, 0);
        QuizDesign::QuizButton();
        H::drawBoxDoubleLineWithBG(72, 10, 116, 29, 2);

        if (x == 0) {
            H::drawBoxSingleLineWithBG(16, 14, 40, 3, 1);
            H::clearBox(16, 15, 40, 3, 215);
            H::setcolor(215); H::gotoxy(24, 16); cout << "C R E A T E   Q U I Z";
            QuizDesign::QuizCreateButton();
        }
        if (x == 1) {
            H::drawBoxSingleLineWithBG(16, 20, 40, 3, 1);
            H::clearBox(16, 21, 40, 3, 215);
            H::setcolor(215); H::gotoxy(24, 22); cout << "U P D A T E   Q U I Z";
            QuizDesign::QuizUpdateButton();
        }
        if (x == 2) {
            H::drawBoxSingleLineWithBG(16, 26, 40, 3, 1);
            H::clearBox(16, 27, 40, 3, 215);
            H::setcolor(215); H::gotoxy(24, 28); cout << "D E L E T E   Q U I Z";
            QuizDesign::QuizDeleteButton();
        }
        if (x == 3) {
            H::drawBoxSingleLineWithBG(16, 32, 40, 3, 1);
            H::clearBox(16, 33, 40, 3, 199);
            H::setcolor(199); H::gotoxy(31, 34); cout << "B A C K";
            QuizDesign::QuizMenuScreen();
        }

        option = getch();

        switch (option) {
            case 72:
                x--;
                if (x < 0) x = 3;
                break;
            case 80:
                x++;
                if (x > 3) x = 0;
                break;
        }
    } while (option != 13);

    H::setcolor(7);
    H::cls();
    H::setcursor(true, 1);

    QuizManager manager(grade);

    switch (x) {
        case 0:
            manager.createQuiz();
            break;
        case 1:
            manager.updateQuiz();
            break;
        case 2:
            manager.deleteQuiz();
            break;
        case 3:
            quizD.Quiz_Select(); // Go back to grade selection
            return;
    }

    // After an operation, return to this same menu for the same grade
    ManageQuizMenu(grade);
}

#endif