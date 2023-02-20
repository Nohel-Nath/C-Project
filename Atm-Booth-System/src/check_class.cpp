#include "check_class.h"
using namespace check;
check_class::check_class()
{

}
check_class::~check_class()
{

}

bool check_class::check_phone_number(string s)
{
    if((int)s.size()!=11)
        return 0;
    for(int i=0; i<(int)s.size(); i++)
    {
        if((s[i]>='0' and s[i]<='9'))
            continue;
        else
            return 0;
    }
    return 1;
}
bool check_class::check_mail(string s)
{
    bool f1,f2;
    f1=f2=0;
    for(int i=0; i<(int)s.size(); i++)
    {
        if(s[i]=='@' and !f2)
        {
            f1=1;
        }
        else if(s[i]=='@' and f2)
        {
            return 0;
        }
        else if(s[i]=='.' and f1)
        {
            f2=1;
        }
        else if(s[i]=='.' and !f1)
            return 0;
    }
    return f1=f2=1;
}
