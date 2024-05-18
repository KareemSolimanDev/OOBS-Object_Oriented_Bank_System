#include "Logout.h"


void Logout::displayContent(){return;};

void Logout::handelInput()
{
    bool wantToLogin=Ui_helpers::confirmField("Do you want to login again : ");
    Config::AppRuningStatus=wantToLogin;

    if (!wantToLogin)
    {
        Ui_helpers::alert("Bye, see you sooon");
    }
}
