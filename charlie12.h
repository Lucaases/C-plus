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
        cout<<"ÄÌ²èÃû³Æ:"<<name<<endl;
        cout<<"ÀäÈÈ:"<<temp<<endl;
        cout<<"ÄÌ²è¼Û¸ñ:"<<price<<"Ôª"<<endl;
        cout<<"ÄÌ²èÕÛ¿Û: %"<<discount*100<<endl;
        cout<<endl;
    }
    void order(){
        cout<<"ÄÌ²èÃû³Æ:"<<endl;
        cin>>name;
        cout<<"ÀäÈÈ:"<<endl;
        cin>>temp;
        cout<<"ÄÌ²è¼Û¸ñ:"<<endl;
        cin>>price;
        cout<<"ÄÌ²èÕÛ¿Û:"<<endl;
        cin>>discount;
    }
    double get_discount(){return price*discount;}
};