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
    Milktea(){}
    Milktea(string a,string b,float c,double d){name = a;temp = b;price = c; discount = d;cout<<name<<endl;}
    ~Milktea(){}
    void display(){
        cout<<"�̲�����:"<<name<<endl;
        cout<<"����:"<<temp<<endl;
        cout<<"�̲�۸�:"<<price<<"Ԫ"<<endl;
        cout<<"�̲��ۿ�: %"<<discount*100<<endl;
        cout<<endl;
    }
    void order(){
        cout<<"�̲�����:"<<endl;
        cin>>name;
        cout<<"����:"<<endl;
        cin>>temp;
        cout<<"�̲�۸�:"<<endl;
        cin>>price;
        cout<<"�̲��ۿ�:"<<endl;
        cin>>discount;
    }
    double get_discount(){return price*discount;}
};