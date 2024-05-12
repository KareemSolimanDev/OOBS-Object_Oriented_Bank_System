#include "Login.h"

using Screen::Login;

void Login::handelLoginData()
{
    if (_loginError)
    {
        Ui_helpers::warning("Invalid Data");
    }
    string usrename=Ui_helpers::textField("Please enter username : ");
    string password=Ui_helpers::textField("Please enter password : ");

    if (Admin::login(usrename,password))
    {
        Screen::Dashboard();
    }else{
        Screen::Login(true);
    }
    
}

void Login::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    handelLoginData();
}

// constructor
Login::Login(bool error)
{
    _loginError=error;
    show();
}