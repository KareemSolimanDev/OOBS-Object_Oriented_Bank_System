#pragma once

#include <iostream>
#include "../BaseScreen.h"

using std::string;
using std::cout;


class MainMenu : protected BaseScreen
{
private:
    string _title;

public:
    MainMenu(string title);
    void display() override;

};
#include "MainMenu.cpp"
