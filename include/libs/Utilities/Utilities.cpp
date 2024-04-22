#include "Utilities.h"

// Date
Date::Data Date::getCurrentDateTime()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    short day, month,year,hour,minute,second;

    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    hour = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;

    return {std::to_string(year), std::to_string(month),std::to_string(day), std::to_string(hour), std::to_string(minute), std::to_string(second)};
};

string Date::getFormatedDate()
{
    Data currentDate=getCurrentDateTime();
    string formatedDate=currentDate.day+"/"+currentDate.month+"/"+currentDate.year;
    return formatedDate;
};

string Date::getFormatedTime()
{
    Data currentTime=getCurrentDateTime();
    string formatedTime=currentTime.hour+":"+currentTime.minute+":"+currentTime.second;
    return formatedTime;
};