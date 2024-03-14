#include<iostream>
#include<string>
using namespace std;
class train{
private:
    string id;
    static string start;
    static string end;
    static string pass;
    static int seat;
    static double price_1;
    static double price_2;
    static double price_3;
public:
    train(string a){id=a;cout<<id<<endl;}
    ~train(){cout<<id<<endl;}
    void display();
    void display_price();
};
