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

AdminLogInfos Admin::convertLogToInfos(string adminLog)
{
    vector<string> log=DataManip_helpers::SplitWords(adminLog,",");
    //     | date  | time  | name  |username| email | phon  | permissions
    return { log[0], log[1], log[2],log[3],   log[4], log[5], short(stoi(log[6]))};
    
}

string Admin::convertInfosToLog(AdminInfos adminInfos)
{
    vector<string> SData= {  Date::getFormatedDate(),Date::getFormatedTime()
                            ,adminInfos.name,adminInfos.username,adminInfos.email
                            ,adminInfos.phone,std::to_string(adminInfos.permissions)};

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

vector<AdminLogInfos> Admin::formatAdminsLogData(vector<string> adminsData)
{
    vector<AdminLogInfos> FAdmins;
    AdminLogInfos infos;
    for (string adminData : adminsData )
    {
        infos=convertLogToInfos(adminData);
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

vector<AdminLogInfos> Admin::loadAdminsLog()
{
    vector<string> adminsData=Bank::loadAdminsLog();
    vector<AdminLogInfos> adminsInfos=formatAdminsLogData(adminsData);
    return adminsInfos;
}

AdminInfos Admin::getAdminInfo(string username)
{
    vector<AdminInfos> adminsInfos=loadAdminsInfo();
    for (AdminInfos adminInfos : adminsInfos )
    {
        if (adminInfos.username==username)
        {
            return adminInfos;
        }
    }
    return {};
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
            Admin::log(username);
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

bool Admin::asUpdateTo(string username)
{
    AdminInfos newInfos=getInfos();
    vector<AdminInfos> adminsInfos=loadAdminsInfo();
    vector<string> newAdminsInfos;

    
    for (AdminInfos &admin : adminsInfos)
    {
        if (admin.username==username)
        {
            admin=newInfos;
        }
        newAdminsInfos.push_back(convertInfosToRecord(admin));
    }

    return Bank::updateData(newAdminsInfos);
}

bool Admin::deleteAdmin(string username)
{
    vector<AdminInfos> adminsInfos=loadAdminsInfo();
    vector<string> newAdminsInfos;
    short posToDelete;
    short counter=0;
    
    for (AdminInfos &admin : adminsInfos)
    {
        counter++;
        if (admin.username==username)
        {
            posToDelete=counter;
        }
        newAdminsInfos.push_back(convertInfosToRecord(admin));
    }

    newAdminsInfos.erase(newAdminsInfos.begin()+posToDelete);
    return Bank::updateData(newAdminsInfos);
}

bool Admin::log(string username)
{
    AdminInfos adminsInfos=getAdminInfo(username);
    
    return Bank::saveAdminLog(convertInfosToLog(adminsInfos));
}