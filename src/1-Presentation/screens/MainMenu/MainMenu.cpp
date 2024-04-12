#include "MainMenu.h"

MainMenu::MainMenu(string title)
{
    _title=title;
}

void MainMenu::display() {

    cout << _title;
}
