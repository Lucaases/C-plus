#include <iostream>
#include <string>
using namespace std;
class phone{
private:
    string id;
    int price;
    int year;
public:
    phone(string a,int b,int c){
        id = a;
        price = b;
        year = c;
    }
    void display(){
        cout<<"型号为"<<id<<endl;
        cout<<"价格为"<<price<<endl;
        cout<<"生产日期为"<<year<<endl;
        cout<<endl;
    }
};