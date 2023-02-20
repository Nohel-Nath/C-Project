#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
#include<fstream>
#include<iostream>
#include "check_class.h"
using namespace std;
class account
{
public:
    friend istream& operator>>(istream& fin,account &a);
    friend ostream& operator<<(ostream& fout,account &a);
    string username,mail,password,phone,address,full;
    int taka;
    int ammount();
    bool withdraw(int M);
    account();
    virtual ~account();
protected:
private:
};

#endif // ACCOUNT_H
