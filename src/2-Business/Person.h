#pragma once

#include <string>

using std::string;

class Person
{
protected:
    string _name;
    string _email;
    string _phone;
public:
    void setName(string name){_name=name;}
    void setEmail(string email){_email=email;}
    void setPhone(string phone){_phone=phone;}

    string getName(){return _name;}
    string getEmail(){return _email;}
    string getPhone(){return _phone;}

};