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
        cout<<"�ͺ�Ϊ"<<id<<endl;
        cout<<"�۸�Ϊ"<<price<<endl;
        cout<<"��������Ϊ"<<year<<endl;
        cout<<endl;
    }
};