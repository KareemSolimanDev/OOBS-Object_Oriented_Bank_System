#include "AdminsList.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::AdminsList;




void AdminsList::displayContent()
{
    vector<AdminInfos> admins=Admin::loadAdminsInfo();

    cout << "\n\t\t\tAdmins List (" << admins.size() << ") admin(s).";
    cout << "\n_________________________________________________________________________________________\n";
    cout << "| " << std::left << std::setw(10) << "Name";
    cout << "| " << std::left << std::setw(10) << "User name";
    cout << "| " << std::left << std::setw(20) << "Email";
    cout << "| " << std::left << std::setw(15) << "Phone";
    cout << "| " << std::left << std::setw(10) << "Password";
    cout << "| " << std::left << std::setw(12) << "Permissions";
    cout << "\n_________________________________________________________________________________________\n";
    for (AdminInfos &admin : admins)
    {

            cout << "| " << std::setw(10) << std::left << admin.name;
            cout << "| " << std::setw(10) << std::left << admin.username;
            cout << "| " << std::setw(20) << std::left << admin.email;
            cout << "| " << std::setw(15) << std::left << admin.phone;
            cout << "| " << std::setw(10) << std::left << admin.password;
            cout << "| " << std::setw(12) << std::left << admin.permissions;
            cout << endl;
    }
    cout << "\n_________________________________________________________________________________________\n";
}



void AdminsList::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
AdminsList::AdminsList()
{
    show();
}
