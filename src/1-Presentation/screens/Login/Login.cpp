#include "Login.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::Login;

void Login::handelLoginData()
{
    if (_loginError)
    {
        Ui_helpers::warning("Invalid Data");
    }
    string usrename=Ui_helpers::textField("Please enter username : ");
    string password=Ui_helpers::textField("Please enter password : ");

    if (usrename=="admin"&&password=="1234")
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