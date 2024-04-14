#include "MainMenu.h"
// all we need iostream ..etc in .h file above
// read impelimintation.md document to get some notes

void MainMenu::displayContent()
{
    _menuItems={"Show Clients List", "Client Operations", "Transactions", "Admin Operations", "logs", "Logout"};
    Ui_helpers::menu("Dashboard Options",_menuItems);
}

void MainMenu::CallSuitableProcess(MainChoices choice)
{
    Ui_helpers::clear();
    switch (choice)
    {
    case MainChoices::ShowClientsList:
        Ui_helpers::alert(" Show Clients List screen will be here");
        goMainMenu();
        break;
    case MainChoices::ClientsOperations:
        Ui_helpers::alert("Clients Operations screen will be here");
        goMainMenu();
        break;
    case MainChoices::Transactions:
        Ui_helpers::alert("Transactions screen will be here");
        goMainMenu();
        break;
    case MainChoices::AdminOperations:
        Ui_helpers::alert("Admin Operations screen will be here");
        goMainMenu();
        break;
    case MainChoices::Logs:
        Ui_helpers::alert("Logs screen will be here");
        goMainMenu();
        break;
    case MainChoices::Logout:
        Ui_helpers::alert("Logout screen will be here");
        goMainMenu();
        break;
    default:
        break;
    }


}

void MainMenu::handelInput()
{
    MainChoices choice = (MainChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}

void MainMenu::show()
{
    Ui_helpers::clear();
    __outScreenHeader("Dashboard Screen");
    displayContent();
    handelInput();
}

void MainMenu::goMainMenu(bool load)
{
    if (load)
    {
        cout << "We will go to the Home ,";
        system("pause");
    }
    show();
}