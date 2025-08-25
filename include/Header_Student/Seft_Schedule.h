#ifndef ___SCHEDULE_FOR_CLASS_STU_EDU_H___ 
#define ___SCHEDULE_FOR_CLASS_STU_EDU_H___

#include "../Header_School/ANTHinsyOOP"


using namespace ANTHinsyOOP;

class Schedule_Management_Seft{
    protected:
        char  studentID[10],start_time[20],end_time[20],sMon[20],sTus[20],sWed[20],sThu[20],sFri[20],sSat[20],timeZone[5];
    public: 

        // Setter Method
        void setAll(const char* start, const char* end , const char* mon = "________________", const char* tus = "________________", const char* wrd = "________________",
                    const char* thu = "________________", const char* fri = "________________", const char* sat = "________________");
        void setTimeZone(const char* tz);
        void setstudentID(const char* id);

        // Getters Method
        const char* getStartTime() const;
        const char* getEndTime() const;
        const char* getMon() const;
        const char* getTus() const;
        const char* getWed() const;
        const char* getThu() const;
        const char* getFri() const;
        const char* getSat() const;
        const char* getTimeZone() const;
        const char* getstudentID() const;
        const char* getFileNameByTimeZone(const char* timezone);


        // PhySic Method Work with Class
        void ReadFile_Display(const char* studentID); // read file display
        void DeleteRowDataBYstudentID(const char* studentID);
        void AddToFileRow(int rowIndex , const char* studentID);   // update file for each row
        void LoadScheduleDataFromFile(const char* targetTimeZone,const char* studentID);   // count rows of file
        void Schedule_Management_SeftstudentID_Process(int x, string timeZone, string title, string studentID);  // schedule managementstudentID_Process
        void Times_Schedule_Select(const char* timezone, const char* studentID, int  newRow);  // Time PROCESS
        void Mon_Schedule_Select(const char* studentID); // MON PROCESS
        void Tus_Schedule_Select(const char* studentID); // TUS PROCESS
        void Wed_Schedule_Select(const char* studentID); // WED PROCESS
        void Thu_Schedule_Select(const char* studentID); // THU PROCESS
        void Fri_Schedule_Select(const char* studentID); // FRI PROCESS
        void Sat_Schedule_Select(const char* studentID); // SAT PROCESS

        // Static Class Design
        static void DesignMain(const char* studentID);  /* Desing Main */
        static void Title_heading(bool Checkupdate);
        static void DisplaySchecduleIF();
        static void InterfaceADD_update(const char* studentID);
        static void DesignInputSchedule(int x, string timeZone, string title);
        static void ProcessOFTimelineAM_PM(string title,int max, const char* timezone, const char* studentID);
        static void AlertMESAGE_SHOW();
        
};


Schedule_Management_Seft seftManage, seftWritemanage[MAX];


// ********************************************************************************************
// ****************************  [ BODY OF  SEFT  SCHEDULE  ] *********************************
// ********************************************************************************************


void Schedule_Management_Seft::DesignMain(const char* studentID){    // Main Call By studentID of class
    int option;
    int choice = 1;
    H::setcursor(false, 0);
    do{
        Title_heading(false);
        DisplaySchecduleIF();
        seftManage.ReadFile_Display(studentID);
        

        do{

            H::drawBoxDoubleLineWithBG(145, 8, 10, 1, 47);
            H::setcolor(47); H::gotoxy(145 + (10 - 2) / 2, 9); cout << "ESC";
            H::drawBoxDoubleLineWithBG(161, 8, 17, 1, 63);
            H::setcolor(63); H::gotoxy(161 + (16 - 12) / 2, 9); cout << "CREATE/UPDATE";
            H::drawBoxDoubleLineWithBG(184, 8, 10, 1, 79);
            H::setcolor(79);H::gotoxy(184 + (10 - 5) / 2, 9); cout << "DELETE";

            switch (choice) {
                case 1: {
                     H::drawBoxSingleLineWithBG(145, 8, 10, 1, 0);
                     H::setcolor(10); H::gotoxy(145 + (10 - 2) / 2, 9); cout << "ESC";
                    break;
                }
                case 2: {
                    H::drawBoxSingleLineWithBG(161, 8, 17, 1, 0);
                    H::setcolor(3); H::gotoxy(161 + (16 - 12) / 2, 9); cout << "CREATE/UPDATE";
                    break;
                }
                case 3: {
                    H::drawBoxSingleLineWithBG(184, 8, 10, 1, 0);
                    H::setcolor(4); H::gotoxy(184 + (10 - 5) / 2, 9); cout << "DELETE";
                    break;
                }

            }

            option = getch();

            choice = EdumasterCustom::ArrowKeyConTrol(3,0,choice,option);    // usage here :)
            
        }while(option != 27 && option != 13);

        if(option==27){
            system("cls");
        }

        if (option == 13) {
                switch (choice) {
                    
                case 1:{
                    system("cls");
                    option = 27;
                    H::cls();
                    break;
                }

                case 2:{
                    system("cls");
                    InterfaceADD_update(studentID);
                    H::cls();
                    break;
                }
                case 3:{
                    int result = MessageBoxA(
                                NULL,
                                "This will Delete all schedule data of this studentID.\nDo you want to continue?",
                                "Restore Confirmation",
                                MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2
                        );


                        if (result == IDYES) {
                            seftManage.DeleteRowDataBYstudentID(studentID);
                            H::cls();
                        } else {
                            H::cls();
                        }
                    break;
                }


            }
        }
    }while(option != 27);
}

void Schedule_Management_Seft::InterfaceADD_update(const char* studentID){   // Menu OF ADD
    int option;
    int choice = 1;

    do{
        H::setcursor(false,0);
        Title_heading(true);
        DisplaySchecduleIF();
        seftManage.ReadFile_Display(studentID);

        
        do{

            H::drawBoxSingleLineWithBG(10, 12, 20, 1, 111);
            H::setcolor(111); H::gotoxy(10 + (20 - 4) / 2, 13); cout << "TIME";

            // 2. Mon
            H::drawBoxSingleLineWithBG(33, 12, 20, 1, 31);
            H::setcolor(31); H::gotoxy(33 + (20 - 3) / 2, 13); cout << "MON";

            // 3. Tue
            H::drawBoxSingleLineWithBG(56, 12, 20, 1, 31);
            H::setcolor(31); H::gotoxy(56 + (20 - 3) / 2, 13); cout << "TUE";

            // 4. Wed
            H::drawBoxSingleLineWithBG(79, 12, 20, 1, 31);
            H::setcolor(31); H::gotoxy(79 + (20 - 3) / 2, 13); cout << "WED";

            // 5. Thu
            H::drawBoxSingleLineWithBG(102, 12, 20, 1, 31);
            H::setcolor(31); H::gotoxy(102 + (20 - 3) / 2, 13); cout << "THU";

            // 6. Fri
            H::drawBoxSingleLineWithBG(125, 12, 20, 1, 31);
            H::setcolor(31); H::gotoxy(125 + (20 - 3) / 2, 13); cout << "FRI";

            // 7. Sat
            H::drawBoxSingleLineWithBG(148, 12, 20, 1, 31);
            H::setcolor(31); H::gotoxy(148 + (20 - 3) / 2, 13); cout << "SAT";

            H::setcolor(6);H::gotoxy(9,30);  cout<<R"( \________||________/ )";
            H::setcolor(1);H::gotoxy(32,30); cout<<R"( \________||________/ )";
            H::setcolor(1);H::gotoxy(55,30); cout<<R"( \________||________/ )";
            H::setcolor(1);H::gotoxy(78,30); cout<<R"( \________||________/ )";
            H::setcolor(1);H::gotoxy(101,30);cout<<R"( \________||________/ )";
            H::setcolor(1);H::gotoxy(124,30);cout<<R"( \________||________/ )";
            H::setcolor(1);H::gotoxy(147,30);cout<<R"( \________||________/ )";
        

            switch (choice) {
                case 1: {
                    H::drawBoxSingleLineWithBG(10, 12, 20, 1, 7);
                    H::setcolor(6); H::gotoxy(10 + (20 - 7) / 2, 13); cout << "__TIME__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 2: {
                    H::drawBoxSingleLineWithBG(33, 12, 20, 1, 7);
                    H::setcolor(3); H::gotoxy(33 + (20 - 7) / 2, 13); cout << "__MON__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 3: {
                    H::drawBoxSingleLineWithBG(56, 12, 20, 1, 7);
                    H::setcolor(3); H::gotoxy(56 + (20 - 7) / 2, 13); cout << "__TUE__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 4: {
                    H::drawBoxSingleLineWithBG(79, 12, 20, 1, 7);
                    H::setcolor(3); H::gotoxy(79 + (20 - 7) / 2, 13); cout << "__WED__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 5: {
                    H::drawBoxSingleLineWithBG(102, 12, 20, 1, 7);
                    H::setcolor(3); H::gotoxy(102 + (20 - 7) / 2, 13); cout << "__THU__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 6: {
                    H::drawBoxSingleLineWithBG(125, 12, 20, 1, 7);
                    H::setcolor(3); H::gotoxy(125 + (20 - 7) / 2, 13); cout << "__FRI__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 7: {
                    H::drawBoxSingleLineWithBG(148, 12, 20, 1, 7);
                    H::setcolor(3); H::gotoxy(148 + (20 - 7) / 2, 13); cout << "__SAT__";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 214);
                    H::setcolor(214); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    break;
                }
                case 8:{
                    H::setcolor(7);H::gotoxy(9,30);  cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }
                case 9:{
                    H::setcolor(7);H::gotoxy(32,30); cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }
                case 10:{
                    H::setcolor(7);H::gotoxy(55,30); cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }
                case 11:{
                    H::setcolor(7);H::gotoxy(78,30); cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }
                case 12:{
                    H::setcolor(7);H::gotoxy(101,30);cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }
                case 13:{
                    H::setcolor(7);H::gotoxy(124,30);cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }
                case 14:{
                    H::setcolor(7);H::gotoxy(147,30);cout<<R"( _______  PM  _______ )";
                    H::drawBoxSingleLineWithBG(171, 29, 20, 1, 111);
                    H::setcolor(111); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";
                    H::drawBoxSingleLineWithBG(171, 12, 20, 1, 0);
                    H::setcolor(0); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";
                    break;
                }

            }

            option = getch();

            choice = EdumasterCustom::ArrowKeyConTrol(14,7,choice,option);    // usage here :)
            
        }while(option != 27 && option != 13);

        if(option==27){
            H::cls();
            
            system("cls");
        }

        if (option == 13) {
                switch (choice) {
                    
                    case 1: {
                        seftManage.LoadScheduleDataFromFile("AM",studentID);
                        if(numRows == 0){
                            seftManage.Schedule_Management_SeftstudentID_Process(78, "AM", "TIME", studentID);
                        }
                        else{
                            int result = MessageBoxA(
                                NULL,
                                "This will restore and overwrite the current data.\nDo you want to continue?",
                                "Restore Confirmation",
                                MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2
                            );


                            if (result == IDYES) {
                                seftManage.Schedule_Management_SeftstudentID_Process(78, "AM", "TIME", studentID);
                            } else {
                                H::cls();
                            }
                        }

                        break;
                    }


                case 2:{
                    seftManage.LoadScheduleDataFromFile("AM",studentID);
                    if(is_clickTimeAM){
                        seftManage.Schedule_Management_SeftstudentID_Process(77,"AM","MONDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    H::cls();
                    break;
                }
                case 3:{
                    seftManage.LoadScheduleDataFromFile("AM",studentID);
                    if(is_clickTimeAM){
                        seftManage.Schedule_Management_SeftstudentID_Process(77,"AM","TUESDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    system("cls");
                    break;
                }
                case 4:{
                    seftManage.LoadScheduleDataFromFile("AM",studentID);
                    if(is_clickTimeAM){
                            seftManage.Schedule_Management_SeftstudentID_Process(75,"AM","WEDNESDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    system("cls");
                    break;
                }
                case 5:{
                    seftManage.LoadScheduleDataFromFile("AM",studentID);
                    if(is_clickTimeAM){
                        seftManage.Schedule_Management_SeftstudentID_Process(75,"AM","THURSDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 6:{
                    seftManage.LoadScheduleDataFromFile("AM",studentID);
                    if(is_clickTimeAM){
                        seftManage.Schedule_Management_SeftstudentID_Process(77,"AM","FRIDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 7:{
                    seftManage.LoadScheduleDataFromFile("AM",studentID);
                    if(is_clickTimeAM){
                        seftManage.Schedule_Management_SeftstudentID_Process(76,"AM","SATURDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 8:{
                    seftManage.LoadScheduleDataFromFile("PM",studentID);
                        if(numRows == 0){
                            seftManage.Schedule_Management_SeftstudentID_Process(78, "PM", "TIME", studentID);
                        }
                        else{
                            int result = MessageBoxA(
                                NULL,
                                "This will restore and overwrite the current data.\nDo you want to continue?",
                                "Restore Confirmation",
                                MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2
                            );


                            if (result == IDYES) {
                                seftManage.Schedule_Management_SeftstudentID_Process(78, "PM", "TIME", studentID);
                            } else {
                                H::cls();
                            }
                        }
                    break;
                }
                case 9:{
                    seftManage.LoadScheduleDataFromFile("PM",studentID);
                    if(is_clickTimePM){
                        seftManage.Schedule_Management_SeftstudentID_Process(77,"PM","MONDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 10:{
                    seftManage.LoadScheduleDataFromFile("PM",studentID);
                    if(is_clickTimePM){
                        seftManage.Schedule_Management_SeftstudentID_Process(77,"PM","TUESDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                
                case 11:{
                    seftManage.LoadScheduleDataFromFile("PM",studentID);
                    if(is_clickTimePM){
                        seftManage.Schedule_Management_SeftstudentID_Process(75,"PM","WEDNESDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 12:{
                    seftManage.LoadScheduleDataFromFile("PM",studentID);
                    if(is_clickTimePM){
                        seftManage.Schedule_Management_SeftstudentID_Process(75,"PM","THURSDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 13:{
                    if(is_clickTimePM){
                        seftManage.Schedule_Management_SeftstudentID_Process(77,"PM","FRIDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    
                    system("cls");
                    break;
                }
                case 14:{
                    if(is_clickTimePM){
                        seftManage.Schedule_Management_SeftstudentID_Process(76,"PM","SATURDAY",studentID);
                    }
                    else{
                        AlertMESAGE_SHOW();
                    }
                    system("cls");
                    break;
                }
                


            }
        }
    }while(option != 27);
}

// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------
//                                                      [Setter]
// ----------------------------------------------------------------------------------------------------------------------------------


void Schedule_Management_Seft::setAll(const char* start, const char* end,
                      const char* mon, const char* tus, const char* wed,
                      const char* thu, const char* fri, const char* sat){

    strncpy(start_time, start, sizeof(start_time) - 1);
    start_time[sizeof(start_time) - 1] = '\0';

    strncpy(end_time, end, sizeof(end_time) - 1);
    end_time[sizeof(end_time) - 1] = '\0';

    strncpy(sMon, mon, sizeof(sMon) - 1);
    sMon[sizeof(sMon) - 1] = '\0';

    strncpy(sTus, tus, sizeof(sTus) - 1);
    sTus[sizeof(sTus) - 1] = '\0';

    strncpy(sWed, wed, sizeof(sWed) - 1);
    sWed[sizeof(sWed) - 1] = '\0';

    strncpy(sThu, thu, sizeof(sThu) - 1);
    sThu[sizeof(sThu) - 1] = '\0';

    strncpy(sFri, fri, sizeof(sFri) - 1);
    sFri[sizeof(sFri) - 1] = '\0';

    strncpy(sSat, sat, sizeof(sSat) - 1);
    sSat[sizeof(sSat) - 1] = '\0';


}

void Schedule_Management_Seft::setTimeZone(const char* tz){
    strncpy(timeZone, tz, sizeof(timeZone) - 1);
    timeZone[sizeof(timeZone) - 1] = '\0';
}

void Schedule_Management_Seft::setstudentID(const char* id){
    strncpy(studentID, id, sizeof(studentID) - 1);
    studentID[sizeof(studentID) - 1] = '\0';
}

// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------
//                                                      [ Getter ]
// ----------------------------------------------------------------------------------------------------------------------------------

const char* Schedule_Management_Seft::getStartTime() const {
    return start_time;
}

const char* Schedule_Management_Seft::getEndTime() const {
    return end_time;
}

const char* Schedule_Management_Seft::getMon() const {
    return sMon;
}

const char* Schedule_Management_Seft::getTus() const {
    return sTus;
}

const char* Schedule_Management_Seft::getWed() const {
    return sWed;
}

const char* Schedule_Management_Seft::getThu() const {
    return sThu;
}

const char* Schedule_Management_Seft::getFri() const {
    return sFri;
}

const char* Schedule_Management_Seft::getSat() const {
    return sSat;
}

const char* Schedule_Management_Seft::getTimeZone() const {
    return timeZone;
}

const char* Schedule_Management_Seft::getstudentID() const {
    return studentID;
}


// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------
//                                                      [ File Manage ]
// ----------------------------------------------------------------------------------------------------------------------------------

void Schedule_Management_Seft::ReadFile_Display(const char* studentID) {
    Schedule_Management_Seft schedules[MAX];

    const char* files[2] = {
        "../data/seft_schedule_data_AM.bin",
        "../data/seft_schedule_data_PM.bin"
    };
    const int startY[2] = {15, 32};

    for (int f = 0; f < 2; f++) {
        FILE* file = fopen(files[f], "rb");
        if (!file) {
            cerr << "Failed to open file: " << files[f] << endl;
            continue;
        }

        int count = fread(schedules, sizeof(Schedule_Management_Seft), MAX, file);
        fclose(file);

        // Find the first index for this studentID with valid start time
        int firstIdx = 0;
        for (; firstIdx < count; ++firstIdx) {
            if (strlen(schedules[firstIdx].getStartTime()) != 0 &&
                strcmp(schedules[firstIdx].getstudentID(), studentID) == 0) {
                break;
            }
        }

        string lastTimeZone = "";
        int boxY = startY[f];

        for (int i = firstIdx; i < count; i++) {
            // Only display rows matching the studentID
            if (strlen(schedules[i].getStartTime()) == 0) continue;
            if (strcmp(schedules[i].getstudentID(), studentID) != 0) continue;

            if (lastTimeZone != schedules[i].getTimeZone()) {
                lastTimeZone = schedules[i].getTimeZone();
                if (i != firstIdx) boxY += 3;
            }

            H::setcolor(7);
            H::gotoxy(10 + 2, boxY + 1);   cout << schedules[i].getStartTime() << " ~ " << schedules[i].getEndTime() << " " << schedules[i].getTimeZone();

            auto centerText = [](const string& str, int width = 17) -> string {
                int len = str.length();
                if (len >= width) return str.substr(0, width);
                int padding = width - len;
                int padLeft = padding / 2;
                int padRight = padding - padLeft;
                return string(padLeft, ' ') + str + string(padRight, ' ');
            };

            H::gotoxy(33 + 2, boxY + 1);   cout << centerText(schedules[i].getMon());
            H::gotoxy(56 + 2, boxY + 1);   cout << centerText(schedules[i].getTus());
            H::gotoxy(79 + 2, boxY + 1);   cout << centerText(schedules[i].getWed());
            H::gotoxy(102 + 2, boxY + 1);  cout << centerText(schedules[i].getThu());
            H::gotoxy(125 + 2, boxY + 1);  cout << centerText(schedules[i].getFri());
            H::gotoxy(148 + 2, boxY + 1);  cout << centerText(schedules[i].getSat());

            boxY += 3;
        }
    }
}

void Schedule_Management_Seft::DeleteRowDataBYstudentID(const char* studentID) {
    const char* files[2] = {
        "../data/schedule_data_AM.bin",
        "../data/schedule_data_PM.bin"
    };

    for (int f = 0; f < 2; ++f) {
        Schedule_Management_Seft tempArr[MAX];
        int count = 0;

        FILE* file = fopen(files[f], "rb");
        if (file) {
            count = fread(tempArr, sizeof(Schedule_Management_Seft), MAX, file);
            fclose(file);
        }

        // Remove rows with matching studentID
        int newCount = 0;
        for (int i = 0; i < count; ++i) {
            if (strcmp(tempArr[i].getstudentID(), studentID) != 0) {
                tempArr[newCount++] = tempArr[i];
            }
        }

        // Write back filtered data
        file = fopen(files[f], "wb");
        if (file) {
            fwrite(tempArr, sizeof(Schedule_Management_Seft), newCount, file);
            fclose(file);
        }
    }
}



void Schedule_Management_Seft::LoadScheduleDataFromFile(const char* targetTimeZone, const char* studentID) {
    const char* filename = getFileNameByTimeZone(targetTimeZone);

    FILE* file = fopen(filename, "rb");
    if (!file) {
        numRows = 0;
        if (strcmp(targetTimeZone, "AM") == 0) is_clickTimeAM = false;
        else if (strcmp(targetTimeZone, "PM") == 0) is_clickTimePM = false;
        return;
    }

    Schedule_Management_Seft temp;
    int i = 0;

    while (fread(&temp, sizeof(Schedule_Management_Seft), 1, file) == 1 && i < MAX) {
        if (strcmp(temp.getstudentID(), studentID) == 0) {
            seftWritemanage[i++] = temp;
        }
    }

    fclose(file);

    numRows = i;

    if (strcmp(targetTimeZone, "AM") == 0) {
        is_clickTimeAM = (numRows > 0);
    } else if (strcmp(targetTimeZone, "PM") == 0) {
        is_clickTimePM = (numRows > 0);
    }
}


const char* Schedule_Management_Seft::getFileNameByTimeZone(const char* timezone) {
    if (strcmp(timezone, "AM") == 0) {
        return "../data/seft_schedule_data_AM.bin";
    } else if (strcmp(timezone, "PM") == 0) {
        return "../data/seft_schedule_data_PM.bin";
    }
    return "../data/error.bin";
}


void Schedule_Management_Seft::AddToFileRow(int rowIndex, const char* studentID) {
    const char* filename = getFileNameByTimeZone(seftWritemanage[rowIndex].getTimeZone());

    FILE* file = fopen(filename, "rb+");
    if (!file) {
        perror("Failed to open file for updating");
        return;
    }

    // Find the correct row for this studentID
    Schedule_Management_Seft tempArr[MAX];
    int count = fread(tempArr, sizeof(Schedule_Management_Seft), MAX, file);

    int foundIdx = -1;
    for (int i = 0, g = 0; i < count; ++i) {
        if (strcmp(tempArr[i].getstudentID(), studentID) == 0) {
            if (g == rowIndex) {
                foundIdx = i;
                break;
            }
            ++g;
        }
    }

    if (foundIdx != -1) {
        fseek(file, sizeof(Schedule_Management_Seft) * foundIdx, SEEK_SET);
        fwrite(&seftWritemanage[rowIndex], sizeof(Schedule_Management_Seft), 1, file);
    }

    fclose(file);
}


// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------
//                                                     Schedule_Management_Seft 
// ----------------------------------------------------------------------------------------------------------------------------------


void Schedule_Management_Seft::Schedule_Management_SeftstudentID_Process(int x, string timeZone, string title, string studentID){

    DesignInputSchedule(x,timeZone,title);

    int max = 0;
    H::setcursor(true,1);

    if(timeZone == "AM"){
        max=5;
        ProcessOFTimelineAM_PM(title,max,timeZone.c_str(),studentID.c_str());
        is_clickTimeAM = true;
    }
    else if(timeZone == "PM"){
        max=4;
        ProcessOFTimelineAM_PM(title,max,timeZone.c_str(),studentID.c_str());
        is_clickTimePM =true;
    }
    
}



void Schedule_Management_Seft::ProcessOFTimelineAM_PM(string title, int max,  const char* timezone, const char* studentID){
    char n[2];
    int newRow;

    if(title == "TIME"){
        while(true){
            H::setcolor(7);H::gotoxy(70,23);cout<<"HOW MANY ROWS DO YOU WANT TO INPUT? 1-"<<max<<" :";H::gotoxy(112,23);H::inputUNumber(n,2);
            
            newRow = stoi(n);

            if (newRow >= 1 && newRow <= max) break; 

            H::setcolor(7);
            H::gotoxy(70, 23); cout << "                                           ";
            
        }
        numRows = newRow;


        seftManage.Times_Schedule_Select(timezone, studentID, newRow );
        
    }
    else if(title == "MONDAY"){
        seftManage.Mon_Schedule_Select(studentID);
    }
    else if(title == "TUESDAY"){
        seftManage.Tus_Schedule_Select(studentID);
    }
    else if(title == "WEDNESDAY"){
        seftManage.Wed_Schedule_Select(studentID);
    }
    else if(title == "THURSDAY"){
        seftManage.Thu_Schedule_Select(studentID);
    }
    else if(title == "FRIDAY"){
        seftManage.Fri_Schedule_Select(studentID);
    }
    else if(title == "SATURDAY"){
        seftManage.Sat_Schedule_Select(studentID);
    }
    
}

void Schedule_Management_Seft::Times_Schedule_Select(const char* timezone, const char* studentID, int newRow) {
    // Load existing file data
    const char* filename = getFileNameByTimeZone(timezone);
    Schedule_Management_Seft tempArr[MAX];
    int fileRows = 0;

    FILE* file = fopen(filename, "rb");
    if (file) {
        fileRows = fread(tempArr, sizeof(Schedule_Management_Seft), MAX, file);
        fclose(file);
    }

    // Find all rows for the current studentID
    int studentIDStart = -1, studentIDCount = 0;
    for (int i = 0; i < fileRows; ++i) {
        if (strcmp(tempArr[i].getstudentID(), studentID) == 0) {
            if (studentIDStart == -1) studentIDStart = i;
            ++studentIDCount;
        }
    }

    int insertPos = (studentIDStart == -1) ? fileRows : studentIDStart;

    // Input for each row
    for (int i = 0; i < newRow; ++i) {
        string strHour, strMin;
        string strStartime, strEndtime;

        int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2); cout << "ENTER START TIME :";
        H::gotoxy(boxX + 23, baseY + 2); cout << "HOUR :";
        H::setcolor(2); H::gotoxy(boxX + 34, baseY + 2); cout << "h";
        H::setcolor(7);
        H::gotoxy(boxX + 40, baseY + 2); cout << "MINUTE :";
        H::setcolor(1); H::gotoxy(boxX + 53, baseY + 2); cout << "min";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 3); cout << "ENTER END TIME   :";
        H::gotoxy(boxX + 23, baseY + 3); cout << "HOUR :";
        H::setcolor(2); H::gotoxy(boxX + 34, baseY + 3); cout << "h";
        H::setcolor(7);
        H::gotoxy(boxX + 40, baseY + 3); cout << "MINUTE :";
        H::setcolor(1); H::gotoxy(boxX + 53, baseY + 3); cout << "min";

        int startHour, startMin, currentStartMin;
        // === START TIME INPUT ===
        while (true) {
            while (true) {
                strHour.clear();
                H::setcolor(2); H::gotoxy(boxX + 30, baseY + 2); H::inputUNumber(strHour, 2);
                if (!strHour.empty() && stoi(strHour) >= 0 && stoi(strHour) <= 12) break;
                else { 
                    H::gotoxy(boxX + 30, baseY + 2); cout << "   "; 
                }
            }
            while (true) {
                strMin.clear();
                H::setcolor(2); H::gotoxy(boxX + 49, baseY + 2); H::inputUNumber(strMin, 2);
                if (!strMin.empty() && stoi(strMin) >= 0 && stoi(strMin) < 60) break;
                else { 
                    H::gotoxy(boxX + 49, baseY + 2); cout << "   "; 
                }
            }
            startHour = stoi(strHour);
            startMin = stoi(strMin);
            currentStartMin = startHour * 60 + startMin;

            if (i > 0) {
                string prevEnd;
                if (studentIDStart != -1 && i < studentIDCount) {
                    prevEnd = tempArr[studentIDStart + i - 1].getEndTime();
                } else if (i > 0) {
                    prevEnd = seftWritemanage[i - 1].getEndTime();
                }
                int prevHour = stoi(prevEnd.substr(0, 2));
                int prevMin = stoi(prevEnd.substr(3, 2));
                int prevEndMin = prevHour * 60 + prevMin;
                H::gotoxy(boxX + 29, baseY);H::setcolor(4);
                cout << "PREVIOUS END TIME: " << prevEnd << " "<<timezone;
                if (currentStartMin < prevEndMin) {
                    H::gotoxy(boxX + 5, baseY + 5);
                    H::setcolor(4);
                    cout << "START TIME MUST BE >= PREVIOUS END TIME. RE-ENTER."; getch();
                    H::gotoxy(boxX + 5, baseY + 5); cout << "                                                       ";
                    H::setcolor(7);
                    H::gotoxy(boxX + 30, baseY + 2); cout << "   ";
                    H::gotoxy(boxX + 49, baseY + 2); cout << "   ";
                    continue;
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        ostringstream startTimeStream;
        startTimeStream << setw(2) << setfill('0') << startHour << ":" << setw(2) << setfill('0') << startMin;
        strStartime = startTimeStream.str();

        int endHour, endMin, startTotalMin = startHour * 60 + startMin, endTotalMin;
        // === END TIME INPUT ===
        while (true) {
            while (true) {
                strHour.clear();
                H::setcolor(2); H::gotoxy(boxX + 30, baseY + 3); H::inputUNumber(strHour, 2);
                if (!strHour.empty() && stoi(strHour) >= 0 && stoi(strHour) <= 12) break;
                else { H::gotoxy(boxX + 30, baseY + 3); cout << "   "; }
            }
            while (true) {
                strMin.clear();
                H::setcolor(2); H::gotoxy(boxX + 49, baseY + 3); H::inputUNumber(strMin, 2);
                if (!strMin.empty() && stoi(strMin) >= 0 && stoi(strMin) < 60) break;
                else { H::gotoxy(boxX + 49, baseY + 3); cout << "   "; }
            }
            endHour = stoi(strHour);
            endMin = stoi(strMin);
            endTotalMin = endHour * 60 + endMin;
            if (endTotalMin > startTotalMin) {
                break;
            } else {
                H::gotoxy(boxX + 6, baseY + 5);
                H::setcolor(4);
                cout << "END TIME MUST BE > START TIME. PLEASE RE-ENTER."; getch();
                H::gotoxy(boxX + 6, baseY + 5); cout << "                                                        ";
                H::setcolor(7);
                H::gotoxy(boxX + 30, baseY + 3); cout << "   ";
                H::gotoxy(boxX + 49, baseY + 3); cout << "   ";
            }
        }

        ostringstream endTimeStream;
        endTimeStream << setw(2) << setfill('0') << endHour << ":" << setw(2) << setfill('0') << endMin;
        strEndtime = endTimeStream.str();

        seftWritemanage[i].setAll(strStartime.c_str(), strEndtime.c_str());
        seftWritemanage[i].setTimeZone(timezone);
        seftWritemanage[i].setstudentID(studentID);

        // Update tempArr for file write
        tempArr[insertPos + i] = seftWritemanage[i];
    }

    if (studentIDStart == -1) {
        fileRows += newRow;
    } else {

        if (newRow > studentIDCount) {
            
            for (int i = fileRows - 1; i >= studentIDStart + studentIDCount; --i) {
                tempArr[i + (newRow - studentIDCount)] = tempArr[i];
            }
            fileRows += (newRow - studentIDCount);
        }
       
        else if (newRow < studentIDCount) {
            for (int i = studentIDStart + newRow; i < fileRows; ++i) {
                tempArr[i] = tempArr[i + (studentIDCount - newRow)];
            }
            fileRows -= (studentIDCount - newRow);
        }
    }

    // Write back to file
    FILE* outFile = fopen(filename, "wb");
    if (outFile) {
        fwrite(tempArr, sizeof(Schedule_Management_Seft), fileRows, outFile);
        fclose(outFile);
    }

    H::cls();
}



void Schedule_Management_Seft::Mon_Schedule_Select(const char* studentID) {
    int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
    bool keepInput = true;
    if(numRows == 1){
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::gotoxy(70, 23); cout << "LETS INPUT -> :";
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-1 :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
        H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

        while (true) {
            H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
            H::inputLetter(seftWritemanage[0].sMon, 17);

            if (strlen(seftWritemanage[0].sMon) > 3) {
                break;
            } else {
                H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
            }
        }

        AddToFileRow(0,studentID);
    }
    else{
        while (keepInput) {
            // Draw Input Prompt
            H::setcolor(2);
            H::gotoxy(70, 23); cout << "LETS INPUT -> : SELECT ROW [1 - " << numRows << "]";
            H::gotoxy(70, 24); cout << "____________________________________________________________";
            H::gotoxy(70, 36); cout << "_____|________________________|______________________|______";

            string strrowSelect;
            H::setcolor(7);H::gotoxy(70, 26); cout << "ENTER ROW NUMBER: ";
            H::setcolor(7);H::gotoxy(70, 27); cout << "____________________________________________________________";
            H::setcolor(1);H::gotoxy(90, 26);H::inputNumber(strrowSelect,1);

            int rowSelect = stoi(strrowSelect);

            if (rowSelect < 1 || rowSelect > numRows) {
                H::setcolor(4); H::gotoxy(70, 29); cout << "[!] INVALID ROW. TRY AGAIN.";H::delay(1000);
                H::setcolor(4); H::gotoxy(70, 29); cout << "                           ";
                H::setcolor(4); H::gotoxy(90, 26); cout << " ";
                _getch();
                continue;
            }

            int i = rowSelect - 1; 
            H::clearBox(boxX, boxY, boxW, boxH);
            H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

            int baseY = boxY + 2;
            H::setcolor(1);
            H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
            H::setcolor(7);
            H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
            H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

            while (true) {
                H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
                H::inputLetter(seftWritemanage[i].sMon, 17);

                if (strlen(seftWritemanage[i].sMon) > 3) {
                    break;
                } else {
                    H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
                }
            }

            AddToFileRow(i,studentID); 

            while (true){
                H::setcolor(7); H::gotoxy(74, 33);
                cout << "DO YOU WANT TO INPUT ANOTHER ROW ? : ";
                H::setcolor(1);H::gotoxy(79, 36);cout<<"~ [ TIPS ] Y/ENTER = YES - N/ESC = NO . ~";
                H::gotoxy(112, 33);
                int key = _getch();
                if (key == 'n' || key == 'N' || key == 27) {
                    keepInput = false;
                    break;
                }
                else if(key == 'y' || key == 'Y' || key == 13){
                    H::clearBox(boxX, boxY, boxW, boxH);
                    H::setcolor(4);H::gotoxy(80, 35);cout<<"                                     ";
                    break;
                }
            }
        

    }
    }
    
}


void Schedule_Management_Seft::Tus_Schedule_Select(const char* studentID) {
    int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
    bool keepInput = true;
    if(numRows == 1){
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::gotoxy(70, 23); cout << "LETS INPUT -> :";
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-1 :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
        H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

        while (true) {
            H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
            H::inputLetter(seftWritemanage[0].sTus, 17);

            if (strlen(seftWritemanage[0].sTus) > 3) {
                break;
            } else {
                H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
            }
        }

        AddToFileRow(0,studentID);
    }
    else{
        while (keepInput) {
            // Draw Input Prompt
            H::setcolor(2);
            H::gotoxy(70, 23); cout << "LETS INPUT -> : SELECT ROW [1 - " << numRows << "]";
            H::gotoxy(70, 24); cout << "____________________________________________________________";
            H::gotoxy(70, 36); cout << "_____|________________________|______________________|______";

            string strrowSelect;
            H::setcolor(7);H::gotoxy(70, 26); cout << "ENTER ROW NUMBER: ";
            H::setcolor(7);H::gotoxy(70, 27); cout << "____________________________________________________________";
            H::setcolor(1);H::gotoxy(90, 26);H::inputNumber(strrowSelect,1);

            int rowSelect = stoi(strrowSelect);

            if (rowSelect < 1 || rowSelect > numRows) {
                H::setcolor(4); H::gotoxy(70, 29); cout << "[!] INVALID ROW. TRY AGAIN.";H::delay(1000);
                H::setcolor(4); H::gotoxy(70, 29); cout << "                           ";
                H::setcolor(4); H::gotoxy(90, 26); cout << " ";
                _getch();
                continue;
            }

            int i = rowSelect - 1; 
            H::clearBox(boxX, boxY, boxW, boxH);
            H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

            int baseY = boxY + 2;
            H::setcolor(1);
            H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
            H::setcolor(7);
            H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
            H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

            while (true) {
                H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
                H::inputLetter(seftWritemanage[i].sTus, 17);

                if (strlen(seftWritemanage[i].sTus) > 3) {
                    break;
                } else {
                    H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
                }
            }

            AddToFileRow(i,studentID); 

            while (true){
                H::setcolor(7); H::gotoxy(74, 33);
                cout << "DO YOU WANT TO INPUT ANOTHER ROW ? : ";
                H::setcolor(1);H::gotoxy(79, 36);cout<<"~ [ TIPS ] Y/ENTER = YES - N/ESC = NO . ~";
                H::gotoxy(112, 33);
                int key = _getch();
                if (key == 'n' || key == 'N' || key == 27) {
                    keepInput = false;
                    break;
                }
                else if(key == 'y' || key == 'Y' || key == 13){
                    H::clearBox(boxX, boxY, boxW, boxH);
                    H::setcolor(4);H::gotoxy(80, 35);cout<<"                                     ";
                    break;
                }
            }
        }
    }
}

void Schedule_Management_Seft::Wed_Schedule_Select(const char* studentID) {
    int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
    bool keepInput = true;
    if(numRows == 1){
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::gotoxy(70, 23); cout << "LETS INPUT -> :";
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-1 :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
        H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

        while (true) {
            H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
            H::inputLetter(seftWritemanage[0].sWed, 17);

            if (strlen(seftWritemanage[0].sWed) > 3) {
                break;
            } else {
                H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
            }
        }

        AddToFileRow(0,studentID);
    }
    else{
        while (keepInput) {
            // Draw Input Prompt
            H::setcolor(2);
            H::gotoxy(70, 23); cout << "LETS INPUT -> : SELECT ROW [1 - " << numRows << "]";
            H::gotoxy(70, 24); cout << "____________________________________________________________";
            H::gotoxy(70, 36); cout << "_____|________________________|______________________|______";

            string strrowSelect;
            H::setcolor(7);H::gotoxy(70, 26); cout << "ENTER ROW NUMBER: ";
            H::setcolor(7);H::gotoxy(70, 27); cout << "____________________________________________________________";
            H::setcolor(1);H::gotoxy(90, 26);H::inputNumber(strrowSelect,1);

            int rowSelect = stoi(strrowSelect);

            if (rowSelect < 1 || rowSelect > numRows) {
                H::setcolor(4); H::gotoxy(70, 29); cout << "[!] INVALID ROW. TRY AGAIN.";H::delay(1000);
                H::setcolor(4); H::gotoxy(70, 29); cout << "                           ";
                H::setcolor(4); H::gotoxy(90, 26); cout << " ";
                _getch();
                continue;
            }

            int i = rowSelect - 1; 
            H::clearBox(boxX, boxY, boxW, boxH);
            H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

            int baseY = boxY + 2;
            H::setcolor(1);
            H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
            H::setcolor(7);
            H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
            H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

            while (true) {
                H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
                H::inputLetter(seftWritemanage[i].sWed, 17);

                if (strlen(seftWritemanage[i].sWed) > 3) {
                    break;
                } else {
                    H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
                }
            }

            AddToFileRow(i,studentID); 

            while (true){
                H::setcolor(7); H::gotoxy(74, 33);
                cout << "DO YOU WANT TO INPUT ANOTHER ROW ? : ";
                H::setcolor(1);H::gotoxy(79, 36);cout<<"~ [ TIPS ] Y/ENTER = YES - N/ESC = NO . ~";
                H::gotoxy(112, 33);
                int key = _getch();
                if (key == 'n' || key == 'N' || key == 27) {
                    keepInput = false;
                    break;
                }
                else if(key == 'y' || key == 'Y' || key == 13){
                    H::clearBox(boxX, boxY, boxW, boxH);
                    H::setcolor(4);H::gotoxy(80, 35);cout<<"                                     ";
                    break;
                }
            }
        }
    }
}

void Schedule_Management_Seft::Thu_Schedule_Select(const char* studentID) {
    int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
    bool keepInput = true;
    if(numRows == 1){
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::gotoxy(70, 23); cout << "LETS INPUT -> :";
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-1 :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
        H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

        while (true) {
            H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
            H::inputLetter(seftWritemanage[0].sThu, 17);

            if (strlen(seftWritemanage[0].sThu) > 3) {
                break;
            } else {
                H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
            }
        }

        AddToFileRow(0,studentID);
    }
    else{
        while (keepInput) {
            // Draw Input Prompt
            H::setcolor(2);
            H::gotoxy(70, 23); cout << "LETS INPUT -> : SELECT ROW [1 - " << numRows << "]";
            H::gotoxy(70, 24); cout << "____________________________________________________________";
            H::gotoxy(70, 36); cout << "_____|________________________|______________________|______";

            string strrowSelect;
            H::setcolor(7);H::gotoxy(70, 26); cout << "ENTER ROW NUMBER: ";
            H::setcolor(7);H::gotoxy(70, 27); cout << "____________________________________________________________";
            H::setcolor(1);H::gotoxy(90, 26);H::inputNumber(strrowSelect,1);

            int rowSelect = stoi(strrowSelect);

            if (rowSelect < 1 || rowSelect > numRows) {
                H::setcolor(4); H::gotoxy(70, 29); cout << "[!] INVALID ROW. TRY AGAIN.";H::delay(1000);
                H::setcolor(4); H::gotoxy(70, 29); cout << "                           ";
                H::setcolor(4); H::gotoxy(90, 26); cout << " ";
                _getch();
                continue;
            }

            int i = rowSelect - 1; 
            H::clearBox(boxX, boxY, boxW, boxH);
            H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

            int baseY = boxY + 2;
            H::setcolor(1);
            H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
            H::setcolor(7);
            H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
            H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

            while (true) {
                H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
                H::inputLetter(seftWritemanage[i].sThu, 17);

                if (strlen(seftWritemanage[i].sThu) > 3) {
                    break;
                } else {
                    H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
                }
            }

            AddToFileRow(i,studentID); 

            while (true){
                H::setcolor(7); H::gotoxy(74, 33);
                cout << "DO YOU WANT TO INPUT ANOTHER ROW ? : ";
                H::setcolor(1);H::gotoxy(79, 36);cout<<"~ [ TIPS ] Y/ENTER = YES - N/ESC = NO . ~";
                H::gotoxy(112, 33);
                int key = _getch();
                if (key == 'n' || key == 'N' || key == 27) {
                    keepInput = false;
                    break;
                }
                else if(key == 'y' || key == 'Y' || key == 13){
                    H::clearBox(boxX, boxY, boxW, boxH);
                    H::setcolor(4);H::gotoxy(80, 35);cout<<"                                     ";
                    break;
                }
            }
        }
    }
}

void Schedule_Management_Seft::Fri_Schedule_Select(const char* studentID) {
    int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
    bool keepInput = true;
    if(numRows == 1){
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::gotoxy(70, 23); cout << "LETS INPUT -> :";
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-1 :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
        H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

        while (true) {
            H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
            H::inputLetter(seftWritemanage[0].sFri, 17);

            if (strlen(seftWritemanage[0].sFri) > 3) {
                break;
            } else {
                H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
            }
        }

        AddToFileRow(0,studentID);
    }
    else{
        while (keepInput) {
            // Draw Input Prompt
            H::setcolor(2);
            H::gotoxy(70, 23); cout << "LETS INPUT -> : SELECT ROW [1 - " << numRows << "]";
            H::gotoxy(70, 24); cout << "____________________________________________________________";
            H::gotoxy(70, 36); cout << "_____|________________________|______________________|______";

            string strrowSelect;
            H::setcolor(7);H::gotoxy(70, 26); cout << "ENTER ROW NUMBER: ";
            H::setcolor(7);H::gotoxy(70, 27); cout << "____________________________________________________________";
            H::setcolor(1);H::gotoxy(90, 26);H::inputNumber(strrowSelect,1);

            int rowSelect = stoi(strrowSelect);

            if (rowSelect < 1 || rowSelect > numRows) {
                H::setcolor(4); H::gotoxy(70, 29); cout << "[!] INVALID ROW. TRY AGAIN.";H::delay(1000);
                H::setcolor(4); H::gotoxy(70, 29); cout << "                           ";
                H::setcolor(4); H::gotoxy(90, 26); cout << " ";
                _getch();
                continue;
            }

            int i = rowSelect - 1; 
            H::clearBox(boxX, boxY, boxW, boxH);
            H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

            int baseY = boxY + 2;
            H::setcolor(1);
            H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
            H::setcolor(7);
            H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
            H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

            while (true) {
                H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
                H::inputLetter(seftWritemanage[i].sFri, 17);

                if (strlen(seftWritemanage[i].sFri) > 3) {
                    break;
                } else {
                    H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
                }
            }

            AddToFileRow(i,studentID); 

            while (true){
                H::setcolor(7); H::gotoxy(74, 33);
                cout << "DO YOU WANT TO INPUT ANOTHER ROW ? : ";
                H::setcolor(1);H::gotoxy(79, 36);cout<<"~ [ TIPS ] Y/ENTER = YES - N/ESC = NO . ~";
                H::gotoxy(112, 33);
                int key = _getch();
                if (key == 'n' || key == 'N' || key == 27) {
                    keepInput = false;
                    break;
                }
                else if(key == 'y' || key == 'Y' || key == 13){
                    H::clearBox(boxX, boxY, boxW, boxH);
                    H::setcolor(4);H::gotoxy(80, 35);cout<<"                                     ";
                    break;
                }
            }
        }
    }
}

void Schedule_Management_Seft::Sat_Schedule_Select(const char* studentID) {
    int boxX = 70, boxY = 26, boxW = 60, boxH = 7;
    bool keepInput = true;
    if(numRows == 1){
        H::clearBox(boxX, boxY, boxW, boxH);
        H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

        int baseY = boxY + 2;
        H::gotoxy(70, 23); cout << "LETS INPUT -> :";
        H::setcolor(1);
        H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-1 :";
        H::setcolor(7);
        H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
        H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

        while (true) {
            H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
            H::inputLetter(seftWritemanage[0].sSat, 17);

            if (strlen(seftWritemanage[0].sSat) > 3) {
                break;
            } else {
                H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
            }
        }

        AddToFileRow(0,studentID);
    }
    else{
        while (keepInput) {
            // Draw Input Prompt
            H::setcolor(2);
            H::gotoxy(70, 23); cout << "LETS INPUT -> : SELECT ROW [1 - " << numRows << "]";
            H::gotoxy(70, 24); cout << "____________________________________________________________";
            H::gotoxy(70, 36); cout << "_____|________________________|______________________|______";

            string strrowSelect;
            H::setcolor(7);H::gotoxy(70, 26); cout << "ENTER ROW NUMBER: ";
            H::setcolor(7);H::gotoxy(70, 27); cout << "____________________________________________________________";
            H::setcolor(1);H::gotoxy(90, 26);H::inputNumber(strrowSelect,1);

            int rowSelect = stoi(strrowSelect);

            if (rowSelect < 1 || rowSelect > numRows) {
                H::setcolor(4); H::gotoxy(70, 29); cout << "[!] INVALID ROW. TRY AGAIN.";H::delay(1000);
                H::setcolor(4); H::gotoxy(70, 29); cout << "                           ";
                H::setcolor(4); H::gotoxy(90, 26); cout << " ";
                _getch();
                continue;
            }

            int i = rowSelect - 1; 
            H::clearBox(boxX, boxY, boxW, boxH);
            H::drawBoxDoubleLine(boxX, boxY, boxW, boxH, 7);

            int baseY = boxY + 2;
            H::setcolor(1);
            H::gotoxy(boxX + 2, baseY); cout << "[+]   ROW-" << (i + 1) << " :";
            H::setcolor(7);
            H::gotoxy(boxX + 2, baseY + 2);  cout << "ENTER THE SUBJECT :";
            H::gotoxy(boxX + 2, baseY + 3);  cout << "_________________________________________";

            while (true) {
                H::setcolor(2);H::gotoxy(boxX + 23, baseY + 2);
                H::inputLetter(seftWritemanage[i].sSat, 17);

                if (strlen(seftWritemanage[i].sSat) > 3) {
                    break;
                } else {
                    H::gotoxy(boxX + 23, baseY + 2); cout << "   ";
                }
            }

            AddToFileRow(i,studentID); 

            while (true){
                H::setcolor(7); H::gotoxy(74, 33);
                cout << "DO YOU WANT TO INPUT ANOTHER ROW ? : ";
                H::setcolor(1);H::gotoxy(79, 36);cout<<"~ [ TIPS ] Y/ENTER = YES - N/ESC = NO . ~";
                H::gotoxy(112, 33);
                int key = _getch();
                if (key == 'n' || key == 'N' || key == 27) {
                    keepInput = false;
                    break;
                }
                else if(key == 'y' || key == 'Y' || key == 13){
                    H::clearBox(boxX, boxY, boxW, boxH);
                    H::setcolor(4);H::gotoxy(80, 35);cout<<"                                     ";
                    break;
                }
            }
        }
    }
}


// ______________________________________________________________________________________________________________ 
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DESIGN CONTENT >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ______________________________________________________________________________________________________________ 

void Schedule_Management_Seft::Title_heading(bool Checkupdate){
    // title
        H::setcolor(1);H::gotoxy(37,0);cout<<R"(  /\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\  )";
        H::setcolor(0);H::gotoxy(37,1);cout<<R"(      ///////////__\///////////////__\///////////////__\///////////////__\///////////////__\///////////////__\//////////////   )";
        system("chcp 65001 > nul");
        H::setcolor(1);H::gotoxy(38,1);cout<<R"(  ██████╗██████╗ ███████╗ █████╗ ████████╗███████╗          ███████╗ ██████╗██╗  ██╗███████╗██████╗ ██╗   ██╗██╗     ███████╗  )";
        H::setcolor(1);H::gotoxy(38,2);cout<<R"( ██╔════╝██╔══██╗██╔════╝██╔══██╗╚══██╔══╝██╔════╝   ╗ ╗    ██╔════╝██╔════╝██║  ██║██╔════╝██╔══██╗██║   ██║██║     ██╔════╝  )";
        H::setcolor(1);H::gotoxy(38,3);cout<<R"( ██║     ██████╔╝█████╗  ███████║   ██║   █████╗     ║ ║    ███████╗██║     ███████║█████╗  ██║  ██║██║   ██║██║     █████╗    )";
        H::setcolor(2);H::gotoxy(38,4);cout<<R"( ██║     ██╔══██╗██╔══╝  ██╔══██║   ██║   ██╔══╝     ║ ║    ╚════██║██║     ██╔══██║██╔══╝  ██║  ██║██║   ██║██║     ██╔══╝    )";
        H::setcolor(2);H::gotoxy(38,5);cout<<R"( ╚██████╗██║  ██║███████╗██║  ██║   ██║   ███████╗   ╝ ╝    ███████║╚██████╗██║  ██║███████╗██████╔╝╚██████╔╝███████╗███████╗  )";
        H::setcolor(2);H::gotoxy(38,6);cout<<R"(  ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝          ╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚══════╝╚══════╝   )";
        system("chcp 437 >nul");                                                              

        if(Checkupdate){
            H::setcolor(7);H::gotoxy(0,9);cout<<"===========================================>| ~ USE LEFT AND RIGHT ARROWS ~ TOP AND DOWN ARROWS ~ TO CONTROL THE SYSTEM AND ~ ENTER ~ KEY TO SELECT THE OPTION |<=======================================";
            H::drawBoxSingleLine(14,8,27,1,4);
            H::setcolor(4);H::gotoxy(14,9);cout<<" PRESS ~ ESC ~ KEY TO EXIT ";
        }
        else{   
            H::setcolor(7);H::gotoxy(0,9);cout<<"=================================================================>| ~ LEFT AND RIGHT ARROWS ~ TO CHOOSE THE [ MENU ] OF SCHEDULE |=============[";
        }

}

    
    void Schedule_Management_Seft::DisplaySchecduleIF(){


        H::drawBoxSingleLine(5, 11, 190, 32, 7); 

        H::drawBoxSingleLineWithBG(10, 12, 20, 1, 111);
        H::setcolor(111); H::gotoxy(10 + (20 - 4) / 2, 13); cout << "TIME";

        H::drawBoxSingleLineWithBG(33, 12, 20, 1, 31);
        H::setcolor(31); H::gotoxy(33 + (20 - 3) / 2, 13); cout << "MON";

        H::drawBoxSingleLineWithBG(56, 12, 20, 1, 31);
        H::setcolor(31); H::gotoxy(56 + (20 - 3) / 2, 13); cout << "TUE";

        H::drawBoxSingleLineWithBG(79, 12, 20, 1, 31);
        H::setcolor(31); H::gotoxy(79 + (20 - 3) / 2, 13); cout << "WED";

        H::drawBoxSingleLineWithBG(102, 12, 20, 1, 31);
        H::setcolor(31); H::gotoxy(102 + (20 - 3) / 2, 13); cout << "THU";

        H::drawBoxSingleLineWithBG(125, 12, 20, 1, 31);
        H::setcolor(31); H::gotoxy(125 + (20 - 3) / 2, 13); cout << "FRI";

        H::drawBoxSingleLineWithBG(148, 12, 20, 1, 31);
        H::setcolor(31); H::gotoxy(148 + (20 - 3) / 2, 13); cout << "SAT";

        H::drawBoxSingleLineWithBG(171, 12, 20, 1, 7);
        H::setcolor(7); H::gotoxy(171 + (20 - 16) / 2, 13); cout << "<---| MORNING |";

        // H::HLine(6,30,188,0,196); // wall line
        H::setcolor(6);H::gotoxy(9,30);  cout<<R"( \________||________/ )";

        H::setcolor(1);H::gotoxy(32,30); cout<<R"( \________||________/ )";

        H::setcolor(1);H::gotoxy(55,30); cout<<R"( \________||________/ )";

        H::setcolor(1);H::gotoxy(78,30); cout<<R"( \________||________/ )";

        H::setcolor(1);H::gotoxy(101,30);cout<<R"( \________||________/ )";

        H::setcolor(1);H::gotoxy(124,30);cout<<R"( \________||________/ )";

        H::setcolor(1);H::gotoxy(147,30);cout<<R"( \________||________/ )";
        H::drawBoxSingleLineWithBG(171, 29, 20, 1, 7);
        H::setcolor(7); H::gotoxy(171 + (20 - 18) / 2, 30); cout << "<---| AFTERNOON |";


        H::drawBoxSingleLine(10,15,20,1,0); 
        
        //morning
        H::drawBoxSingleLine(10,18,20,1,0);
        H::drawBoxSingleLine(10,21,20,1,0);
        H::drawBoxSingleLine(10,24,20,1,0);
        H::drawBoxSingleLine(10,27,20,1,0);
        
        H::drawBoxSingleLine(33,15,20,1,0);
        H::drawBoxSingleLine(33,18,20,1,0);
        H::drawBoxSingleLine(33,21,20,1,0);
        H::drawBoxSingleLine(33,24,20,1,0);
        H::drawBoxSingleLine(33,27,20,1,0);

        H::drawBoxSingleLine(56,15,20,1,0);
        H::drawBoxSingleLine(56,18,20,1,0);
        H::drawBoxSingleLine(56,21,20,1,0);
        H::drawBoxSingleLine(56,24,20,1,0);
        H::drawBoxSingleLine(56,27,20,1,0);

        H::drawBoxSingleLine(79,15,20,1,0);
        H::drawBoxSingleLine(79,18,20,1,0);
        H::drawBoxSingleLine(79,21,20,1,0);
        H::drawBoxSingleLine(79,24,20,1,0);
        H::drawBoxSingleLine(79,27,20,1,0);

        H::drawBoxSingleLine(102,15,20,1,0);
        H::drawBoxSingleLine(102,18,20,1,0);
        H::drawBoxSingleLine(102,21,20,1,0);
        H::drawBoxSingleLine(102,24,20,1,0);
        H::drawBoxSingleLine(102,27,20,1,0);

        H::drawBoxSingleLine(125,15,20,1,0);
        H::drawBoxSingleLine(125,18,20,1,0);
        H::drawBoxSingleLine(125,21,20,1,0);
        H::drawBoxSingleLine(125,24,20,1,0);
        H::drawBoxSingleLine(125,27,20,1,0);

        H::drawBoxSingleLine(148,15,20,1,0);
        H::drawBoxSingleLine(148,18,20,1,0);
        H::drawBoxSingleLine(148,21,20,1,0);
        H::drawBoxSingleLine(148,24,20,1,0);
        H::drawBoxSingleLine(148,27,20,1,0);

        //afternoon
        H::drawBoxSingleLine(10,32,20,1,0);
        H::drawBoxSingleLine(10,35,20,1,0);
        H::drawBoxSingleLine(10,38,20,1,0);
        H::drawBoxSingleLine(10,41,20,1,0);
    
        H::drawBoxSingleLine(33,32,20,1,0);
        H::drawBoxSingleLine(33,35,20,1,0);
        H::drawBoxSingleLine(33,38,20,1,0);
        H::drawBoxSingleLine(33,41,20,1,0);
    
        H::drawBoxSingleLine(56,32,20,1,0);
        H::drawBoxSingleLine(56,35,20,1,0);
        H::drawBoxSingleLine(56,38,20,1,0);
        H::drawBoxSingleLine(56,41,20,1,0);
    
        H::drawBoxSingleLine(79,32,20,1,0);
        H::drawBoxSingleLine(79,35,20,1,0);
        H::drawBoxSingleLine(79,38,20,1,0);
        H::drawBoxSingleLine(79,41,20,1,0);
    
        H::drawBoxSingleLine(102,32,20,1,0);
        H::drawBoxSingleLine(102,35,20,1,0);
        H::drawBoxSingleLine(102,38,20,1,0);
        H::drawBoxSingleLine(102,41,20,1,0);
    
        H::drawBoxSingleLine(125,32,20,1,0);
        H::drawBoxSingleLine(125,35,20,1,0);
        H::drawBoxSingleLine(125,38,20,1,0);
        H::drawBoxSingleLine(125,41,20,1,0);
    
        H::drawBoxSingleLine(148,32,20,1,0);
        H::drawBoxSingleLine(148,35,20,1,0);
        H::drawBoxSingleLine(148,38,20,1,0);
        H::drawBoxSingleLine(148,41,20,1,0);

        H::setcolor(6);H::gotoxy(170,15);cout<<R"(         _____          )";
        H::setcolor(6);H::gotoxy(170,16);cout<<R"(      _.'_____`._       )";
        H::setcolor(6);H::gotoxy(170,17);cout<<R"(    .'.-'  12 `-.`.     )";
        H::setcolor(6);H::gotoxy(170,18);cout<<R"(   /,' 11      1 `.\    )";
        H::setcolor(6);H::gotoxy(170,19);cout<<R"(  // 10          2 \\   )";
        H::setcolor(6);H::gotoxy(170,20);cout<<R"( ;;                 ::  )";
        H::setcolor(6);H::gotoxy(170,21);cout<<R"( || 9     A M     3 ||  )";
        H::setcolor(6);H::gotoxy(170,22);cout<<R"( ::                 ;;  )";
        H::setcolor(6);H::gotoxy(170,23);cout<<R"(  \\ 8           4 //   )";
        H::setcolor(6);H::gotoxy(170,24);cout<<R"(   \`. 7       5 ,'/    )";
        H::setcolor(6);H::gotoxy(170,25);cout<<R"(    '.`-.__6__.-'.'     )";
        H::setcolor(7);H::gotoxy(170,26);cout<<R"(     ((-._____.-))      )";
        H::setcolor(0);H::gotoxy(170,27);cout<<R"(         _____          )";
        

        H::setcolor(3);H::gotoxy(170,32);cout<<R"(         _____          )";
        H::setcolor(3);H::gotoxy(170,33);cout<<R"(      _.'_____`._       )";
        H::setcolor(3);H::gotoxy(170,34);cout<<R"(    .'.-'  12 `-.`.     )";
        H::setcolor(3);H::gotoxy(170,35);cout<<R"(   /,' 11      1 `.\    )";
        H::setcolor(3);H::gotoxy(170,36);cout<<R"(  // 10          2 \\   )";
        H::setcolor(3);H::gotoxy(170,37);cout<<R"( ;;                 ::  )";
        H::setcolor(3);H::gotoxy(170,38);cout<<R"( || 9     P M     3 ||  )";
        H::setcolor(3);H::gotoxy(170,39);cout<<R"( ::                 ;;  )";
        H::setcolor(3);H::gotoxy(170,40);cout<<R"(  \\ 8           4 //   )";
        H::setcolor(3);H::gotoxy(170,41);cout<<R"(   \`. 7       5 ,'/    )";
        H::setcolor(3);H::gotoxy(170,42);cout<<R"(    '.`-.__6__.-'.'     )";
        H::setcolor(7);H::gotoxy(170,43);cout<<R"(     ((-._____.-))      )";

    }


    void Schedule_Management_Seft::AlertMESAGE_SHOW(){
        
        H::setcolor(4);H::gotoxy(21,25);cout<<R"(                                                                                                                                        )";
        H::setcolor(4);H::gotoxy(21,26);cout<<R"(     _____ _   _ _____ ___________   _____ _   _  _____   _____ ________  ___ _____ _____   ______ ___________  _____ _____   _   _     )";H::delay(50);
        H::setcolor(4);H::gotoxy(21,27);cout<<R"(    |  ___| \ | |_   _|  ___| ___ \ |_   _| | | ||  ___| |_   _|_   _|  \/  ||  ___/  ___|  |  ___|_   _| ___ \/  ___|_   _| | | | |    )";H::delay(50);
        H::setcolor(4);H::gotoxy(21,28);cout<<R"(    | |__ |  \| | | | | |__ | |_/ /   | | | |_| || |__     | |   | | | .  . || |__ \ `--.   | |_    | | | |_/ /\ `--.  | |   | | | |    )";H::delay(50);
        H::setcolor(4);H::gotoxy(21,29);cout<<R"(    |  __|| . ` | | | |  __||    /    | | |  _  ||  __|    | |   | | | |\/| ||  __| `--. \  |  _|   | | |    /  `--. \ | |   | | | |    )";H::delay(50);
        H::setcolor(4);H::gotoxy(21,30);cout<<R"(    | |___| |\  | | | | |___| |\ \    | | | | | || |___    | |  _| |_| |  | || |___/\__/ /  | |    _| |_| |\ \ /\__/ / | |   |_| |_|    )";H::delay(50);
        H::setcolor(4);H::gotoxy(21,31);cout<<R"(    \____/\_| \_/ \_/ \____/\_| \_|   \_/ \_| |_/\____/    \_/  \___/\_|  |_/\____/\____/   \_|    \___/\_| \_|\____/  \_/   (_) (_)    )";H::delay(50);
        H::setcolor(4);H::gotoxy(21,32);cout<<R"(                                                                                                                                        )";
        H::delay(1000);                                                                                                                                                                          

    }

    void Schedule_Management_Seft::DesignInputSchedule(int x ,string timeZone, string title){
        H::drawBoxDoubleLineWithBG(1,25,198,6,2);
        H::drawBoxSingleLineWithBG(30,11,140,32,2);                                                                                                                                                                  
                                                                                                                                                                        
        H::setcolor(7);H::gotoxy(32,12);cout<<R"(          ____________________________________________________________________________________________________________________           )";
        H::setcolor(1);H::gotoxy(32,13);cout<<R"( _::::::::::::::::::::::__::::::::::::::::::::::__::::::::::::::::::::::__::::::::::::::::::::::__::::::::::::::::::::::__:::::::::::::: )";
        H::setcolor(7);H::gotoxy(32,14);cout<<R"( _______________________________________________________________________________________________________________________________________ )";

        H::setcolor(7);H::gotoxy(32,40);cout<<R"( ______________________________________________________________________________________________________________________________________ )";
        H::setcolor(1);H::gotoxy(32,41);cout<<R"( _::::::::::::::::::::::__::::::::::::::::::::::__::::::::::::::::::::::__::::::::::::::::::::::__::::::::::::::::::::::__:::::::::::::: )";
        H::setcolor(7);H::gotoxy(32,42);cout<<R"( _______________________________________________________________________________________________________________________________________ )";
                
        H::setcolor(7);H::gotoxy(31,12);cout<<R"(  _______  )"; 
        H::setcolor(7);H::gotoxy(31,13);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(31,14);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,15);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,16);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,17);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,18);cout<<R"(  |:::::|  )"; 
        H::setcolor(7);H::gotoxy(31,19);cout<<R"(  |||||||  )"; 
                        
        H::setcolor(7);H::gotoxy(31,21);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(31,22);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,23);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,24);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,25);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,26);cout<<R"(  |:::::|  )"; 
        H::setcolor(4);H::gotoxy(31,27);cout<<R"(  |||||||  )";  
        H::setcolor(4);H::gotoxy(31,28);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(31,29);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,30);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,31);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,32);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,33);cout<<R"(  |:::::|  )"; 
        H::setcolor(7);H::gotoxy(31,34);cout<<R"(  |||||||  )"; 
                        
        H::setcolor(7);H::gotoxy(31,36);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(31,37);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,38);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,39);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,40);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(31,41);cout<<R"(  |:::::|  )"; 
        H::setcolor(7);H::gotoxy(31,42);cout<<R"(  |||||||  )"; 

        H::setcolor(7);H::gotoxy(158,12);cout<<R"(  _______  )"; 
        H::setcolor(7);H::gotoxy(158,13);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(158,14);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,15);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,16);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,17);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,18);cout<<R"(  |:::::|  )"; 
        H::setcolor(7);H::gotoxy(158,19);cout<<R"(  |||||||  )"; 
                        
        H::setcolor(7);H::gotoxy(158,21);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(158,22);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,23);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,24);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,25);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,26);cout<<R"(  |:::::|  )"; 
        H::setcolor(4);H::gotoxy(158,27);cout<<R"(  |||||||  )";  
        H::setcolor(4);H::gotoxy(158,28);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(158,29);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,30);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,31);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,32);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,33);cout<<R"(  |:::::|  )"; 
        H::setcolor(7);H::gotoxy(158,34);cout<<R"(  |||||||  )"; 
                        
        H::setcolor(7);H::gotoxy(158,36);cout<<R"(  |||||||  )"; 
        H::setcolor(1);H::gotoxy(158,37);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,38);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,39);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,40);cout<<R"(  |:::::|  )"; 
        H::setcolor(1);H::gotoxy(158,41);cout<<R"(  |:::::|  )"; 
        H::setcolor(7);H::gotoxy(158,42);cout<<R"(  |||||||  )"; 

        H::drawBoxSingleLine(70,15,60,3,7);

        H::setcolor(7);H::gotoxy(x,17);cout<<"|-------------[ "<<title<<" ]-------------"<<"(~ "<<timeZone<<" ~)";


    }


#endif
