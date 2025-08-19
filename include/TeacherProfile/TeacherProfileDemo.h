#ifndef __INC_TEACHERPROFILEDEMO__
#define __INC_TEACHERPROFILEDEMO__

#include "TeacherProfile.h"

void displayTeacherProfile(const char* emailToFind)
{
    // const char* searchEmail = "te.nakia@gmail.com";
    TeacherProfile profile;
    getTeacherProfileByEmail(emailToFind, profile);
    profile.display();
}

#endif