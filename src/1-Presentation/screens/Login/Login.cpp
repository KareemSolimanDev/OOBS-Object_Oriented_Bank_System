#include "Login.h"


void Login::displayContent(){return;}

void Login::handelInput()
{
    if (_loginError)
    {
        Ui_helpers::warning("Invalid Data");
    }
    string usrename=Ui_helpers::textField("Please enter username : ");
    string password=Ui_helpers::textField("Please enter password : ");

    if (Admin::login(usrename,password))
    {
        _loginError=false;
        DashboardScreen.render();
    }else{
        _loginError=true;
        this->render();
    }
    
}