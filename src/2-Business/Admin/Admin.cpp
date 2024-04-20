#include "Admin.h"
#include "../../3-Data Access/Bank.h"


AdminInfos Admin::convertRecordToInfos(string adminRecord)
{
    vector<string> record=DataManip_helpers::SplitWords(adminRecord,",");
    //     | name     | username | email     | phone    | password  | permissions
    return { record[0], record[1], record[2],  record[3], record[4],  short(stoi(record[5]))};
    
}
string Admin::convertInfosToRecord(AdminInfos adminInfos)
{
    vector<string> SData={adminInfos.name,adminInfos.username,adminInfos.email,adminInfos.phone,adminInfos.password,std::to_string(adminInfos.permissions)};
    return DataManip_helpers::JoinWords(SData,",");
}



AdminInfos Admin::getInfos()
{
    return {_name,_username,_email,_phone,_password,_permissions};
}
Admin::Admin(AdminInfos infos)
{
    _name=infos.name;
    _username=infos.username;
    _email=infos.email;
    _phone=infos.phone;
    _password=infos.password;
    _permissions=infos.permissions;
}




vector<AdminInfos> Admin::formatAdminsData(vector<string> adminsData)
{
    vector<AdminInfos> FAdmins;
    AdminInfos infos;
    for (string adminData : adminsData )
    {
        infos=convertRecordToInfos(adminData);
        FAdmins.push_back(infos);
    }
    return FAdmins;
}

vector<AdminInfos> Admin::loadAdminsInfo()
{
    vector<string> adminsData=Bank::loadAdminsData();
    vector<AdminInfos> adminsInfos=formatAdminsData(adminsData);
    return adminsInfos;
}

bool Admin::isExist(string username)
{
    vector<AdminInfos> adminsInfos=loadAdminsInfo();
    for (AdminInfos adminInfos : adminsInfos )
    {
        if (adminInfos.username==username)
        {
            return true;
        }
    }
    return false;
}

bool Admin::login(string username,string password)
{

    vector<AdminInfos> adminsInfos=loadAdminsInfo();

    for (AdminInfos adminInfos : adminsInfos )
    {
        if (adminInfos.username==username && adminInfos.password==password)
        {
            __CurrentAdmin__=adminInfos;
            return true;
        }
    }
    return false;
}

bool Admin::save()
{
    string record=convertInfosToRecord(getInfos());
    return Bank::saveRecord(record);
}
