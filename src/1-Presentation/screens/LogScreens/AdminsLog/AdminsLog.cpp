#include "AdminsLog.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::AdminsLog;




void AdminsLog::displayContent()
{
    vector<AdminLogInfos> admins=Admin::loadAdminsLog();

    cout << "\n\t\t\t\tAdmins List (" << admins.size() << ") admin(s).";
    cout << "\n_______________________________________________________________________________________________________________\n";
    cout << "| " << std::left << std::setw(15) << "Date(dd/mm/yy)";
    cout << "| " << std::left << std::setw(10) << "Time";
    cout << "| " << std::left << std::setw(10) << "Name";
    cout << "| " << std::left << std::setw(10) << "User name";
    cout << "| " << std::left << std::setw(20) << "Email";
    cout << "| " << std::left << std::setw(15) << "Phone";
    cout << "| " << std::left << std::setw(12) << "Permissions";
    cout << "\n_______________________________________________________________________________________________________________\n";
    for (AdminLogInfos &admin : admins)
    {

            cout << "| " << std::setw(15) << std::left << admin.date;
            cout << "| " << std::setw(10) << std::left << admin.time;
            cout << "| " << std::setw(10) << std::left << admin.name;
            cout << "| " << std::setw(10) << std::left << admin.username;
            cout << "| " << std::setw(20) << std::left << admin.email;
            cout << "| " << std::setw(15) << std::left << admin.phone;
            cout << "| " << std::setw(12) << std::left << admin.permissions;
            cout << endl;
    }
    cout << "\n_______________________________________________________________________________________________________________\n";
}



void AdminsLog::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
AdminsLog::AdminsLog()
{
    show();
}
