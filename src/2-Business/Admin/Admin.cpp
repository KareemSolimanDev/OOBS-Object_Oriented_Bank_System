#include "Admin.h"


bool Admin::isValid(string username,string password)
{
    vector<string> adminsData=Bank::loadAdminsData();
    vector<string> record;
    string uname;
    string pword;
    for (string i : adminsData )
    {
        record=DataManip_helpers::SplitWords(i,",");
        uname=record[1]; // username possition
        pword=record[4]; // password possition
        if (username==uname && password==pword)
        {
            return true;
        }
        
    }
    return false;
}