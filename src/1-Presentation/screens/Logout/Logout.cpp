#include "Logout.h"
// all we need iostream ..etc in .h file above
#include "../Login/Login.h"
// read impelimintation.md document to get some notes

using Screen::Logout;

void Logout::handelInput()
{

    bool wantToLogin=Ui_helpers::confirmField("Do you want to login again : ");

    if (wantToLogin)
    {
        Screen::Login();
    }else{
        Ui_helpers::alert("Bye, see you sooon");
    }
    
}

void Logout::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    handelInput();
}

// constructor
Logout::Logout()
{
    show();
}