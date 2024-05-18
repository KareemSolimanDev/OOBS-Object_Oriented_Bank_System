#include "FindAdmin.h"


void FindAdmin::displayContent(){return;}

void FindAdmin::handelInput()
{
    string username=Ui_helpers::textField("Enter Admin username : ");
    AdminInfos admin=Admin::searchForAdmin(username);
    
    vector<string> cardDetailsKeys={"Name","User Name","Email","Phone","Password","Permissions"};
    vector<string> adminDetailsValue={admin.name,admin.username,admin.email,admin.phone,admin.password,std::to_string(admin.permissions)};

    if (admin.username!="")
    {
        Ui_helpers::card("Admin Details",cardDetailsKeys,adminDetailsValue);
    }else
    {
        Ui_helpers::warning("Admin Not Found");
    }
    Ui_helpers::pause("We will go back");

}