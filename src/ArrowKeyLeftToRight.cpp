#include "../include/Header_School/ANTHinsyOOP"
using namespace ANTHinsyOOP;

// Define the Student structure used for binary reading
struct Student {
    static int lastId;    
	char teacherId[20];
	int yearOfExp,academyYear;
	char teacherName[30],gender[30],subject[30],phoneNumber[15],dateOfBirth[20],email[20];
};

void showAllStudents() {
    ifstream file("../data/Teacher_Data.bin", ios::binary);
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
        cout  << s.email << " | " ;
        row += 2;
        colorIndex++;
    }

    file.close();
}

int main() {
    showAllStudents();
}
