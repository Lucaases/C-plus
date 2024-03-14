#include<iostream>
#include<string>
using namespace std;
class mypay{
private:
    string name;
    double Regular_balance;
    double Current_balance;
    int transfer_limit;
    string password;
    string phone_number;
    static double transfer_fee;
    static int User_download;
public:
    mypay(){User_download++;cout<<"User download="<<User_download<<endl;}
    mypay(string a,double b,double c,int d,string f,string g):name(a),Regular_balance(b),Current_balance(c),transfer_limit(d),password(f),phone_number(g){User_download++;cout<<"User download="<<User_download<<endl;}
    ~mypay(){User_download--;cout<<"User download="<<User_download<<endl;}
    double Check_R_Balance(){return Regular_balance;}
    double Check_C_Balance(){return Current_balance;}
    static int Check_User_download(){return User_download;}
    void Check_Infor(){
        cout<<"Name is "<<name<<endl;
        cout<<"Regular_balance is "<<Regular_balance<<endl;
        cout<<"Current_balance is "<<Current_balance<<endl;
        cout<<"transfer_limit is "<<transfer_limit<<endl;
        cout<<"password is "<<password<<endl;
        cout<<"phone_number is "<<phone_number<<endl;
        cout<<"transfer_fee is "<<transfer_fee<<endl;
    }
};