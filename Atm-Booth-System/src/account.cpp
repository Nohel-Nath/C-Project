#include "account.h"

account::account()
{

}
account::~account()
{

}
istream& operator>>(istream& fin,account &a)
{
    check::check_class c;
    cout<<"\t\t\tUsername :: ";
    fin>>a.username;
    cout<<"\t\t\tName :: ";
    fin>>a.full;
xx:
    cout<<"\t\t\tMail :: ";
    fin>>a.mail;
    if(!c.check_mail(a.mail))
    {
        cout<<"\t\t\tInvalid Mail | Try again |\n";
        goto xx;
    }
    cout<<"\t\t\tPassword :: ";
    fin>>a.password;
xxx:
    cout<<"\t\t\tPhone Number :: ";
    fin>>a.phone;
    if(!c.check_phone_number(a.phone))
    {
        cout<<"\t\t\tInvalid Phone Number | Try Again |\n";
        goto xxx;
    }
    cout<<"\t\t\tAddress :: ";
    fin>>a.address;
    cout<<"\t\t\tAmount Of Money to deposit :: ";
    fin>>a.taka;
    return fin;
}
ostream& operator<<(ostream& fout,account &a)
{
    fout<<"\t\t\tName :: "<<a.full<<endl;
    fout<<"\t\t\tUser Name :: "<<a.username<<"\n\t\t\tMail :: "<<a.mail<<"\n\t\t\tPhone Number :: "<<a.phone<<endl;
    fout<<"\t\t\tAddress :: "<<a.address<<endl;
    fout<<"\t\t\tTaka Available :: "<<a.taka<<endl;
    return fout;
}
int account::ammount()
{
    return taka;
}
bool account::withdraw(int M)
{
    if(M>ammount())
    {
        return 0;
    }
    taka-=M;
    return 1;
}
