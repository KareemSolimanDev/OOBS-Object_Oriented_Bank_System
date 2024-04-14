#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::vector;
using std::cout;


class MainMenu : protected BaseScreen
{
private:
    vector<string> _menuItems;

    enum MainChoices
    {
        ShowClientsList = 1,
        ClientsOperations,
        Transactions,
        AdminOperations,
        Logs,
        Logout,
    };

    void displayContent();
    void handelInput();
    void CallSuitableProcess(MainChoices choice);

public:

    void show() override;
    void goMainMenu(bool load=true);
};
#include "MainMenu.cpp"
