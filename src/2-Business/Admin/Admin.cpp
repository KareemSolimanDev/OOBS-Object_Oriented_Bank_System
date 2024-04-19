#include "Admin.h"


AdminInfos Admin::getInfos()
{
    return {_name,_username,_email,_phone,_password,_permissions};
}

vector<AdminInfos> Admin::formatAdminsData(vector<string> adminsData)
{
    vector<AdminInfos> FAdmins;
    vector<string> record;
    for (string adminData : adminsData )
    {
        record=DataManip_helpers::SplitWords(adminData,",");
        //                | name     | username | email     | phone    | password  | permissions
        FAdmins.push_back({ record[0], record[1], record[2],  record[3], record[4],  short(stoi(record[5]))});
    }
    return FAdmins;
}


bool Admin::login(string username,string password)
{
    vector<string> adminsData=Bank::loadAdminsData();
    vector<AdminInfos> adminsInfos=formatAdminsData(adminsData);

    for (AdminInfos adminInfos : adminsInfos )
    {
        if (adminInfos.username==username && adminInfos.password==password)
        {
            return true;
        }
    }
    return false;
}