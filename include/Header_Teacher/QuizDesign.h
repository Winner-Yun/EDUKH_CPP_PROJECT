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
        static void Quiz();
        static void QuizChooseMenu();
        static void QuizScreen();

        void gradeTitle(int grade);
        void ManageQuizMenu(int grade);
};

QuizDesign quizD;

void QuizDesign::QuizCreateButton() {
    H::setcolor(7); H::gotoxy(72, 11); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 12); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 13); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 14); cout << R"(                                                                                                                    )";
    H::setcolor(2); H::gotoxy(72, 15); cout << R"(                                                                                                                    )";
    H::setcolor(2); H::gotoxy(72, 16); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 17); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 18); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 19); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 20); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 19); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 20); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 21); cout << R"(                                     __________________   __________________                                        )";
    H::setcolor(7); H::gotoxy(72, 22); cout << R"(                                 .-/|  ---  Quiz  ---  \ /                  |\-.              ___                   )";
    H::setcolor(7); H::gotoxy(72, 23); cout << R"(                                 ||||                   |                   ||||             |___|                  )";
    H::setcolor(7); H::gotoxy(72, 24); cout << R"(                                 ||||  Q: ____________  |  Q: ____________  ||||             |   |\_                )";
    H::setcolor(7); H::gotoxy(72, 25); cout << R"(                                 ||||                   |                   ||||             |   | |                )";
    H::setcolor(7); H::gotoxy(72, 26); cout << R"(                                 ||||    1. _______     |     1. _______    ||||             |   | |                )";
    H::setcolor(7); H::gotoxy(72, 27); cout << R"(                                 ||||                   |                   ||||             | W | |                )";
    H::setcolor(7); H::gotoxy(72, 28); cout << R"(                                 ||||    2. _______     |     2. _______    ||||             | K |_|                )";
    H::setcolor(7); H::gotoxy(72, 29); cout << R"(                                 ||||                   |                   ||||             | N |                  )";
    H::setcolor(7); H::gotoxy(72, 30); cout << R"(                                 ||||    3. _______     |     3. _______    ||||             | R |                  )";
    H::setcolor(7); H::gotoxy(72, 31); cout << R"(                                 ||||                   |                   ||||             |   |                  )";
    H::setcolor(7); H::gotoxy(72, 32); cout << R"(                                 ||||    4. _______     |     4. _______    ||||             |   |                  )";
    H::setcolor(7); H::gotoxy(72, 33); cout << R"(                                 ||||__________________ | __________________||||             | _ |                  )";
    H::setcolor(7); H::gotoxy(72, 34); cout << R"(                                 ||/===================\|/===================\||              \_/                   )";
    H::setcolor(7); H::gotoxy(72, 35); cout << R"(                                 `--------------------~___~-------------------''               v                    )";
    H::setcolor(1); H::gotoxy(72, 36); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 37); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 38); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 39); cout << R"(                                                                                                                    )";

    H::setcolor(7); H::gotoxy(102, 13); cout << R"(  ____                _             ___        _     )";
    H::setcolor(7); H::gotoxy(102, 14); cout << R"( / ___|_ __ ___  __ _| |_ ___      / _ \ _   _(_)____)";
    H::setcolor(1); H::gotoxy(102, 15); cout << R"(| |   | '__/ _ \/ _` | __/ _ \    | | | | | | | |_  /)";
    H::setcolor(1); H::gotoxy(102, 16); cout << R"(| |___| | |  __/ (_| | ||  __/    | |_| | |_| | |/ / )";
    H::setcolor(7); H::gotoxy(102, 17); cout << R"( \____|_|  \___|\__,_|\__\___|     \__\_\\__,_|_/___|)";
}

void QuizDesign::QuizUpdateButton(){
    H::setcolor(7); H::gotoxy(72, 11); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 12); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 13); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 14); cout << R"(                                                                                                                    )";
    H::setcolor(2); H::gotoxy(72, 15); cout << R"(                                                                                                                    )";
    H::setcolor(2); H::gotoxy(72, 16); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 17); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 18); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 19); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 20); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 19); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 20); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 21); cout << R"(                                     __________________   __________________                                        )";
    H::setcolor(7); H::gotoxy(72, 22); cout << R"(                                 .-/|  ---  Quiz  ---  \ /                  |\-.              ___                   )";
    H::setcolor(7); H::gotoxy(72, 23); cout << R"(                                 ||||                   |                   ||||             |___|                  )";
    H::setcolor(7); H::gotoxy(72, 24); cout << R"(                                 ||||  Q: ____________  |  Q: ____________  ||||             |   |\_                )";
    H::setcolor(7); H::gotoxy(72, 25); cout << R"(                                 ||||                   |                   ||||             |   | |                )";
    H::setcolor(7); H::gotoxy(72, 26); cout << R"(                                 ||||    1. _______     |     1. _______    ||||             |   | |                )";
    H::setcolor(7); H::gotoxy(72, 27); cout << R"(                                 ||||                   |                   ||||             | W | |                )";
    H::setcolor(7); H::gotoxy(72, 28); cout << R"(                                 ||||    2. _______     |     2. _______    ||||             | K |_|                )";
    H::setcolor(7); H::gotoxy(72, 29); cout << R"(                                 ||||                   |                   ||||             | N |                  )";
    H::setcolor(7); H::gotoxy(72, 30); cout << R"(                                 ||||    3. _______     |     3. _______    ||||             | R |                  )";
    H::setcolor(7); H::gotoxy(72, 31); cout << R"(                                 ||||                   |                   ||||             |   |                  )";
    H::setcolor(7); H::gotoxy(72, 32); cout << R"(                                 ||||    4. _______     |     4. _______    ||||             |   |                  )";
    H::setcolor(7); H::gotoxy(72, 33); cout << R"(                                 ||||__________________ | __________________||||             | _ |                  )";
    H::setcolor(7); H::gotoxy(72, 34); cout << R"(                                 ||/===================\|/===================\||              \_/                   )";
    H::setcolor(7); H::gotoxy(72, 35); cout << R"(                                 `--------------------~___~-------------------''               v                    )";
    H::setcolor(1); H::gotoxy(72, 36); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 37); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 38); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 39); cout << R"(                                                                                                                    )";

    H::setcolor(4); H::gotoxy(88, 29); cout << R"( __________)";
    H::setcolor(4); H::gotoxy(88, 30); cout << R"(|__________|)";
    H::setcolor(7); H::gotoxy(88, 31); cout << R"(|          |)";
    H::setcolor(7); H::gotoxy(88, 32); cout << R"(|          |)";
    H::setcolor(7); H::gotoxy(88, 33); cout << R"(|__________|)";
    H::setcolor(6); H::gotoxy(91, 32); cout << "Eraser";

    H::setcolor(7); H::gotoxy(102, 13); cout << R"( _   _           _       _             ___        _     )";
    H::setcolor(7); H::gotoxy(102, 14); cout << R"(| | | |_ __   __| | __ _| |_ ___      / _ \ _   _(_)____)";
    H::setcolor(2); H::gotoxy(102, 15); cout << R"(| | | | '_ \ / _` |/ _` | __/ _ \    | | | | | | | |_  /)";
    H::setcolor(2); H::gotoxy(102, 16); cout << R"(| |_| | |_) | (_| | (_| | ||  __/    | |_| | |_| | |/ / )";
    H::setcolor(7); H::gotoxy(102, 17); cout << R"( \___/| .__/ \__,_|\__,_|\__\___|     \__\_\\__,_|_/___|)";
    H::setcolor(7); H::gotoxy(102, 18); cout << R"(      |_|                                               )";
}

void QuizDesign::QuizDeleteButton() {
    H::setcolor(7); H::gotoxy(72, 11); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 12); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 13); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 14); cout << R"(                                                                                                                    )";
    H::setcolor(2); H::gotoxy(72, 15); cout << R"(                                                                                                                    )";
    H::setcolor(2); H::gotoxy(72, 16); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 17); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 18); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 19); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 20); cout << R"(                                                                                                                    )";
    H::setcolor(7); H::gotoxy(72, 21); cout << R"(                                     __________________   __________________                                        )";
    H::setcolor(7); H::gotoxy(72, 22); cout << R"(                                 .-/|  ---  Quiz  ---  \ /    \             |\-.                                    )";
    H::setcolor(7); H::gotoxy(72, 23); cout << R"(                                 ||||                   |     /             ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 24); cout << R"(                                 ||||  Q: ____________  |  Q:/ ___________  ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 25); cout << R"(                                 ||||                   |    \              ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 26); cout << R"(                                 ||||    1. _______     |     \ _______     ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 27); cout << R"(                                 ||||                   |     /             ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 28); cout << R"(                                 ||||    2. _______     |     \ _______     ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 29); cout << R"(                                 ||||                   |     /             ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 30); cout << R"(                                 ||||    3. _______     |     \ _______     ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 31); cout << R"(                                 ||||                   |     /             ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 32); cout << R"(                                 ||||    4. _______     |     \ _______     ||||                                    )";
    H::setcolor(7); H::gotoxy(72, 33); cout << R"(                                 ||||__________________ | ____/_____________||||                                    )";
    H::setcolor(7); H::gotoxy(72, 34); cout << R"(                                 ||/===================\|/===================\||                                    )";
    H::setcolor(7); H::gotoxy(72, 35); cout << R"(                                 `--------------------~___~-------------------''                                    )";
    H::setcolor(1); H::gotoxy(72, 36); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 37); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 38); cout << R"(                                                                                                                    )";
    H::setcolor(1); H::gotoxy(72, 39); cout << R"(                                                                                                                    )";

    H::setcolor(7); H::gotoxy(102, 13); cout << R"( ____       _      _             ___        _     )";
    H::setcolor(7); H::gotoxy(102, 14); cout << R"(|  _ \  ___| | ___| |_ ___      / _ \ _   _(_)____)";
    H::setcolor(4); H::gotoxy(102, 15); cout << R"(| | | |/ _ \ |/ _ \ __/ _ \    | | | | | | | |_  /)";
    H::setcolor(4); H::gotoxy(102, 16); cout << R"(| |_| |  __/ |  __/ ||  __/    | |_| | |_| | |/ / )";
    H::setcolor(7); H::gotoxy(102, 17); cout << R"(|____/ \___|_|\___|\__\___|     \__\_\\__,_|_/___|)";
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

    H::HLine(10, 11, 53, 7, 219);
    H::VLine(10, 10, 29, 7, 219);
    H::VLine(9, 10, 29, 7, 219);
    H::HLine(10, 63, 53, 7, 219);
    H::VLine(63, 10, 29, 7, 219);
    H::VLine(64, 10, 29, 7, 219);

    //Box
    H::drawBoxDoubleLine(70, 9, 120, 31, 2);
    H::HLine(70, 9, 120, 2, 219);
    H::VLine(70, 8, 33, 2, 219);
    H::VLine(71, 8, 33, 2, 219);
    H::VLine(190, 8, 33, 2, 219);
    H::VLine(191, 8, 33, 2, 219);
    H::HLine(70, 41, 120, 2, 219);
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

void QuizDesign::QuizScreen() {
    system("chcp 65001  > nul");
    H::setcolor(6); H::gotoxy(82, 1); cout << R"(    ██████                ███            )";
    H::setcolor(6); H::gotoxy(82, 2); cout << R"(  ███░░░░███             ░░░             )";
    H::setcolor(6); H::gotoxy(82, 3); cout << R"( ███    ░░███ █████ ████ ████   █████████)";
    H::setcolor(6); H::gotoxy(82, 4); cout << R"(░███     ░███░░███ ░███ ░░███  ░█░░░░███ )";
    H::setcolor(6); H::gotoxy(82, 5); cout << R"(░███   ██░███ ░███ ░███  ░███  ░   ███░  )";
    H::setcolor(6); H::gotoxy(82, 6); cout << R"(░░███ ░░████  ░███ ░███  ░███    ███░   █)";
    H::setcolor(6); H::gotoxy(82, 7); cout << R"( ░░░██████░██ ░░████████ █████  █████████)";
    H::setcolor(6); H::gotoxy(82, 8); cout << R"(   ░░░░░░ ░░   ░░░░░░░░ ░░░░░  ░░░░░░░░░ )";
    system("chcp 437 > nul");

    H::setcolor(6); H::gotoxy(5, 10); cout << R"(  __________________________________________________________________________________________________________________________________________________________________________________________   )";
    H::setcolor(6); H::gotoxy(5, 11); cout << R"( /:-\                                                                                                                                                                                       `\ )";
    H::setcolor(6); H::gotoxy(5, 12); cout << R"(|< > |                                                                                                                                                                                        |)";
    H::setcolor(6); H::gotoxy(5, 13); cout << R"(|\__/________________________________________________________________________________________________________________________________________________________________________________________/ )";
    H::setcolor(6); H::gotoxy(5, 14); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 15); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 16); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 17); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 18); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 19); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 20); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 21); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 22); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 23); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 24); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 25); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 26); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 27); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 28); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 29); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 30); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 31); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 32); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 33); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 34); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 35); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 36); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 37); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 38); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 39); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 40); cout << R"(|                                                                                                                                                                                          |   )";
    H::setcolor(6); H::gotoxy(5, 41); cout << R"(| _________________________________________________________________________________________________________________________________________________________________________________________|   )";
    H::setcolor(6); H::gotoxy(5, 42); cout << R"(|/`--_                                                                                                                                                                                      `\ )";
    H::setcolor(6); H::gotoxy(5, 43); cout << R"(||[ ]||                                                                                                                                                                                       |)";
    H::setcolor(6); H::gotoxy(5, 44); cout << R"( \===/_______________________________________________________________________________________________________________________________________________________________________________________/ )";

    H::setcolor(7); H::gotoxy(15, 15); cout << "QUESTION : ";
    H::drawBoxDoubleLine(15, 16, 170, 4, 7);

    H::setcolor(7); H::gotoxy(92, 23); cout << "SELECT YOUR ANSWER :";

    H::drawBoxSingleLine(15, 26, 80, 3, 1);
    H::drawBoxSingleLine(15, 34, 80, 3, 1);

    H::drawBoxSingleLine(105, 26, 80, 3, 1);
    H::drawBoxSingleLine(105, 34, 80, 3, 1);
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

void QuizDesign::QuizChooseMenu() {
	int option;
    int x = 0;
    H::cls();
    
    do {
    	H::setcursor(false, 0);
        H::setcolor(3); H::gotoxy(86, 3); cout << R"( __  __  ____  _  _  __  __ )";
        H::setcolor(3); H::gotoxy(86, 4); cout << R"((  \/  )( ___)( \( )(  )(  ))";
        H::setcolor(3); H::gotoxy(86, 5); cout << R"( )    (  )__)  )  (  )(__)( )";
        H::setcolor(3); H::gotoxy(86, 6); cout << R"((_/\/\_)(____)(_)\_)(______))";
        H::HLine(7, 1, 186, 7, 220);
        H::HLine(7, 9, 186, 7, 223);
        
        H::drawBoxSingleLineWithBG(75, 12, 50, 3, 1);
        H::setcolor(2); H::gotoxy(94, 14); cout << "Q U I Z   1";
        H::drawBoxSingleLineWithBG(75, 18, 50, 3, 1);
        H::setcolor(2); H::gotoxy(94, 20); cout << "Q U I Z   2";
        H::drawBoxSingleLineWithBG(75, 24, 50, 3, 1);
        H::setcolor(2); H::gotoxy(94, 26); cout << "Q U I Z   3";
        H::drawBoxSingleLineWithBG(75, 30, 50, 3, 1);
        H::setcolor(4); H::gotoxy(96, 32); cout << "Q U I T";
        
        H::drawBoxDoubleLine(1, 0, 5, 43, 235);
        H::clearBox(2, 2, 3, 41, 222);
        
        H::drawBoxDoubleLine(194, 0, 5, 43, 235);
        H::clearBox(195, 2, 3, 41, 222);
        if (x == 0) {
            H::drawBoxSingleLineWithBG(75, 12, 50, 3, 153);
            H::clearBox(76, 14, 48, 1, 110);
            H::VLine(76, 12, 3, 153, 219);
            H::VLine(125, 12, 3, 153, 219);
			H::setcolor(111); H::gotoxy(94, 14); cout << "Q U I Z   1";
        }
        if (x == 1) {
            H::drawBoxSingleLineWithBG(75, 18, 50, 3, 153);
            H::clearBox(76, 20, 48, 1, 110);
            H::VLine(76, 18, 3, 153, 219);
            H::VLine(125, 18, 3, 153, 219);
			H::setcolor(111); H::gotoxy(94, 20); cout << "Q U I Z   2";
        }
        if (x == 2) {
            H::drawBoxSingleLineWithBG(75, 24, 50, 3, 153);
            H::clearBox(76, 26, 48, 1, 110);
            H::VLine(76, 24, 3, 153, 219);
            H::VLine(125, 24, 3, 153, 219);
			H::setcolor(111); H::gotoxy(94, 26); cout << "Q U I Z   3";
        }
        if (x == 3) {
            H::drawBoxSingleLineWithBG(75, 30, 50, 3, 153);
            H::clearBox(76, 32, 48, 1, 199);
            H::VLine(76, 30, 3, 153, 219);
            H::VLine(125, 30, 3, 153, 219);
			H::setcolor(199); H::gotoxy(96, 32); cout << "Q U I T";
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
    switch (x) {
        case 0:
            
            break;
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            exit(0);
            break;
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

        if (x == 0) {
            H::clearBox(16, 15, 40, 3, 215);
            H::setcolor(215); H::gotoxy(24, 16); cout << "C R E A T E   Q U I Z";
            QuizDesign::QuizCreateButton();
        }
        if (x == 1) {
            H::clearBox(16, 21, 40, 3, 215);
            H::setcolor(215); H::gotoxy(24, 22); cout << "U P D A T E   Q U I Z";
            QuizDesign::QuizUpdateButton();
        }
        if (x == 2) {
            H::clearBox(16, 27, 40, 3, 215);
            H::setcolor(215); H::gotoxy(24, 28); cout << "D E L E T E   Q U I Z";
            QuizDesign::QuizDeleteButton();
        }
        if (x == 3) {
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
            QuizDesign::QuizScreen();
            manager.createQuiz();
            break;
        case 1:
            manager.updateQuiz();
            break;
        case 2:
            manager.deleteQuiz();
            break;
        case 3:
            quizD.Quiz_Select();
            return;
    }
    ManageQuizMenu(grade);
}

#endif