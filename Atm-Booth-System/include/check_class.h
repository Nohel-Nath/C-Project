#ifndef CHECK_CLASS_H
#define CHECK_CLASS_H
#include<string>
#include<iostream>
using namespace std;
namespace check
{
class check_class
{
public:
    check_class();
    virtual ~check_class();
    bool check_phone_number(string s);
    bool check_mail(string s);
protected:
private:
};
}

#endif
