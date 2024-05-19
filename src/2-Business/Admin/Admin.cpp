#include "Admin.h"

Admin::Admin(AdminInfos infos)
{
    _name=infos.name;
    _username=infos.username;
    _email=infos.email;
    _phone=infos.phone;
    _password=infos.password;
    _permissions=infos.permissions;
}

AdminInfos Admin::getInfos()
{
    return {this->_name,this->_username,this->_email,this->_phone,this->_password,this->_permissions};
}

vector<vector<string>> Admin::getAllAdminsData()
{
    return Bank::getAllAdminsData();
}

vector<vector<string>> Admin::getAllAdminsLogData()
{
    return Bank::getAllAdminsLogData();
}


AdminInfos Admin::searchForAdmin(string username)
{
    return Bank::getAdminInfo(username);
}

bool Admin::isExist(string username)
{
    return searchForAdmin(username).username == username;
}

bool Admin::login(string username,string password)
{
    username=DataManip_helpers::Trim(username);
    password=DataManip_helpers::Trim(password);

    AdminInfos adminInfos=searchForAdmin(username);
    if (adminInfos.username==username && adminInfos.password==password)
    {
        __CurrentAdmin__=adminInfos;
        Admin admn(adminInfos);
        return admn.log();
    }
    return false;
}

bool Admin::save()
{
    return Bank::saveAdmin(this->getInfos());
}

bool Admin::update(AdminInfos newInfos)
{
    return Bank::updateAdmin(this->_username,newInfos);
}

bool Admin::deleteIt()
{
    return Bank::deleteAdmin(this->_username);
}

bool Admin::log()
{
    return Bank::logAdmin(this->getInfos());
}