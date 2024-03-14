#include<iostream>
#include<string>
using namespace std;
class Milktea{
private:
    string name;
    string temp;
    float price;
    double discount;
public:
    Milktea(string a,string b,float c,double d){name = a;temp = b;price = c; discount = d;cout<<name<<endl;}
    ~Milktea(){cout<<name<<endl;}
    void display();
};
