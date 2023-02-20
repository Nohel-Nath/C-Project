#ifndef DATABASE_H
#define DATABASE_H
#include<vector>
#include"account.h"
#include<windows.h>
using namespace std;
class database:public account
{
public:
    database();
    virtual ~database();
    int find_(account a);
    int find_(string user,string pass);
    bool register_(account a);
    void update_();
    void read_();
    void intro();
    bool login();
    void write_();
    void withdraw_();
protected:
private:
    int idx;
    vector<account>vec;
};

#endif // DATABASE_H
