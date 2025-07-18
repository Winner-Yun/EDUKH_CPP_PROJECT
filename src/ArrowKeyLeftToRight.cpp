#include "../include/Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

// Define the Student structure used for binary reading
struct Student {
    char id[6], name[19], gender[7], bdate[11], grade[3], tel[10], sYear[5], email[30], pw[19];
    int No;
};

void showAllStudents() {
    ifstream file("../data/TeacherAndStudent_data.bin", ios::binary);
    int row = 5;
    int colorCodes[] = {9, 10, 7, 11, 14};
    int colorIndex = 0;

    if (!file.is_open()) {
        H::gotoxy(50, 10); H::setcolor(4); cout << "Unable to open Student_Data.bin";
        return;
    }

    Student s;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        int color = colorCodes[colorIndex % 5];
        H::setcolor(color);
        H::gotoxy(50, row);
        cout  << s.email << " | " << s.pw;
        row += 2;
        colorIndex++;
    }

    file.close();
}

int main() {
    showAllStudents();
}
