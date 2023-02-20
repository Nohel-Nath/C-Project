#include "database.h"
using namespace check;
database::database() {}
database::~database() {}
void println()
{
    cout<<endl<<"\t\t\t";
    for(int i=0;i<80;i++)cout<<'_';
    cout<<endl;
}
bool database::login()
{
    int x,y;
    string user,pass;
    bool f=0;
    println();
    cout<<"\t\t\tSignUP or LOG in";
    println();
    while(1)
    {
        cout<<"\t\t\t1.Sign In"<<endl;
        cout<<"\t\t\t2.Sign Up"<<endl;
        println();
        cout<<"\t\t\tEnter Your Choice :: ";
        cin>>x;
        if(x==1)
        {
            cout<<"\t\t\tUserName :: ";
            cin>>user;
            cout<<"\t\t\tPassword :: ";
            cin>>pass;
            y=find_(user,pass);
            if(y==-1)
            {
                cout<<"\t\t\tInvalid Password or User Name\n\t\t\tTry Again\n";
            }
            else
            {
                f=1;
                idx=y;
                break;
            }
        }
        else if(x==2)
        {
            f=1;
            account a;
            cin>>a;
            register_(a);
            idx=vec.size()-1;
            break;
        }
        else
        {
            return f;
        }
    }
    return f;
}
void database::intro()
{
    read_();
init:
    int x;
    system("cls");
    println();
    cout<<"\t\t\tWelcome\tto Atm booth system";
    println();
    bool f=login();
    if(!f)
        return;
    else
    {
        system("cls");
        while(1)
        {
            system("COLOR 1E");
            println();
            cout<<"\t\t\t1.Edit Account\n";
            cout<<"\t\t\t2.Withdraw Money\n";
            cout<<"\t\t\t3.Check account\n";
            cout<<"\t\t\t4.Delete Account\n";
            cout<<"\t\t\t5.Exit\n";
            println();
            cout<<"\t\t\tYour Choice :: ";
            cin>>x;
            if(x==1)
                update_();
            else if(x==2)
                withdraw_();
            else if(x==3)
                cout<<vec[idx]<<endl;
            else if(x==4)
            {
                vec.erase(vec.begin()+idx);
                goto init;
            }
        }
    }
    write_();
}
void database::withdraw_()
{
    system("cls");
    println();
    int x;
    while(1)
    {
        cout<<"\t\t\tEnter amount Of Money You will Withdraw :: ";
        cin>>x;
        if(x>vec[idx].taka)
        {
            cout<<"\t\t\tTransition failed---Not enough sufficient Money\n\t\t\tTry again\n";
        }
        else
        {
            cout<<"\t\t\t"<<x<<" Amount Of money Will be deduced from your account\n";
            vec[idx].taka-=x;
            cout<<"\t\t\t New amount :: "<<vec[idx].taka<<endl;
            break;
        }
    }
}
int database::find_(account a)
{
    for(int i=0; i<(int)vec.size(); i++)
    {
        if(a.username==vec[i].username and a.mail==vec[i].mail and a.password==vec[i].password)
            return i;
    }
    return -1;
}
int database::find_(string user,string pass)
{
    for(int i=0; i<(int)vec.size(); i++)
    {
        if((user==vec[i].username or user==vec[i].mail) and pass==vec[i].password)
        {
            return i;
        }
    }
    return -1;
}
bool database::register_(account a)
{
    for(int i=0; i<(int)vec.size(); i++)
    {
        if(vec[i].username==a.username)
        {
            return 0;
        }
    }
    vec.push_back(a);
    return 1;
}
void database::read_()
{
    ifstream fin("database.txt");
    account s;
    while(fin>>s.username)
    {
        fin>>s.full>>s.password>>s.phone>>s.mail>>s.address>>s.taka;
        vec.push_back(s);
    }
    fin.close();
}
void database::write_()
{
    ofstream fout("database.txt");
    for(int i=0; i<vec.size(); i++)
    {
        fout<<vec[i].username<<" "<<vec[i].full<<" "<<vec[i].password<<" "<<vec[i].phone<<" "<<vec[i].mail<<" "<<vec[i].address<<" "<<vec[i].taka<<endl;
    }
    fout.close();
}
void database::update_()
{
    system("cls");
    check_class c;
    int x;
    string s;
    println();
    cout<<"\t\t\tUpdate Panel"<<endl;
  println();
    while(1)
    {
     println();
        cout<<"\t\t\t1.Update Name\n";
        cout<<"\t\t\t2.Update Password\n";
        cout<<"\t\t\t3.Update Mail\n";
        cout<<"\t\t\t4.Update Number\n";
        cout<<"\t\t\t5.Update Address\n";
        cout<<"\t\t\t6.Exit\n";
        println();
        cout<<"\t\t\tYour Choice :: ";
        cin>>x;
        if(x==1)
        {
            cout<<"\t\t\tNew Name :: ";
            cin>>s;
            vec[idx].full=s;
        }
        else if(x==2)
        {
            cout<<"\t\t\tNew Password :: ";
            cin>>s;
            vec[idx].password=s;
        }
        else if(x==3)
        {
xy:
            cout<<"\t\t\tNew mail :: ";
            cin>>s;
            if(c.check_mail(s))
                vec[idx].mail=s;
            else
            {
                cout<<"\t\t\tInvalid Email\t Try Again";
                goto xy;
            }
        }
        if(x==4)
        {
xxy:
            cout<<"\t\t\tNew Number :: ";
            cin>>s;
            if(c.check_phone_number(s))
            {
                vec[idx].phone=s;
            }
            else
            {
                cout<<"\t\t\tInvalid Number\t Try Again";
                goto xxy;
            }
        }
        if(x==5)
        {
            cout<<"\t\t\tNew Address :: ";
            getchar();
            getline(cin,s);
            vec[idx].address=s;
        }
        if(x==6)
            break;
    }
}
