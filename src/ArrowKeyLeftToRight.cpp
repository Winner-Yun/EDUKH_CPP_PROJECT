#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 100;

class Schedule_Mangement {
protected:
    char start_time[20], end_time[20], sMon[20], sTus[20], sWed[20], sThu[20], sFri[20], sSat[20], timeZone[5], grade[5];
public:
    const char* getStartTime() const { return start_time; }
    const char* getEndTime() const { return end_time; }
    const char* getMon() const { return sMon; }
    const char* getTus() const { return sTus; }
    const char* getWed() const { return sWed; }
    const char* getThu() const { return sThu; }
    const char* getFri() const { return sFri; }
    const char* getSat() const { return sSat; }
    const char* getTimeZone() const { return timeZone; }
    const char* getGrade() const { return grade; }
};

void readAndDisplaySchedule(const char* filename, const char* label) {
    Schedule_Mangement schedules[MAX];

    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    cout << "\n===== " << label << " Schedule =====" << endl;

    int i = 0;
    while (fread(&schedules[i], sizeof(Schedule_Mangement), 1, file) == 1 && i < MAX) {
        cout << "\n======== Row " << i + 1 << " ========" << endl;
        cout << "Time     : " << schedules[i].getStartTime() << " - " << schedules[i].getEndTime() << " " << schedules[i].getTimeZone() << endl;
        cout << "Grade    : " << schedules[i].getGrade() << endl;
        cout << "Monday   : " << schedules[i].getMon() << endl;
        cout << "Tuesday  : " << schedules[i].getTus() << endl;
        cout << "Wednesday: " << schedules[i].getWed() << endl;
        cout << "Thursday : " << schedules[i].getThu() << endl;
        cout << "Friday   : " << schedules[i].getFri() << endl;
        cout << "Saturday : " << schedules[i].getSat() << endl;
        i++;
    }

    fclose(file);
}

int main() {
    readAndDisplaySchedule("../data/schedule_data_AM.bin", "AM");
    readAndDisplaySchedule("../data/schedule_data_PM.bin", "PM");

    return 0;
}
