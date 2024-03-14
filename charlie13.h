#include<iostream>
#include<string>
using namespace std;

class sugar{
private:
    string amount;
public:
    sugar(){}
    sugar(string a):amount(a){}
    string get_amount(){return amount;}
};

class milk{
private:
    int amount;
    string brand;
public:
    milk(){}
    milk(int a,string b):amount(a),brand(b){}
    int get_amount(){return amount;}
    string get_brand(){return brand;}
};

class tea{
private:
    int amount;
    string type;
public:
    tea(){}
    tea(int a,string b):amount(a),type(b){}
    int get_amount(){return amount;}
    string get_type(){return type;}
};

class Milktea{
private:
    string name;
    string temp;
    double price;
    double discount;
    sugar Sugar;
    tea Tea;
    milk Milk;
public:
    Milktea(){}
    Milktea(string a,string b,float c,double d,sugar e,tea f,milk g)
    {name = a;temp = b;price = c; discount = d;Sugar = e;Tea = f;Milk = g;}
    ~Milktea(){}
    void display(){
        cout<<"�̲�����:"<<name<<endl;
        cout<<"����:"<<temp<<endl;
        cout<<"�̲������:"<<Sugar.get_amount()<<endl;
        cout<<"�̲�Ӳ���:"<<Tea.get_amount()<<"mL"<<endl;
        cout<<"�̲����:"<<Tea.get_type()<<endl;
        cout<<"�̲������:"<<Milk.get_amount()<<"mL"<<endl;
        cout<<"�̲���Ʒ��:"<<Milk.get_brand()<<endl;
        cout<<"�̲�ԭ��:"<<price<<"Ԫ"<<endl;
        cout<<"�̲��ۿ�:%"<<discount*100<<endl;
        cout<<"�̲��ۺ�۸�:"<<price*discount<<"Ԫ"<<endl<<endl;
    }
    double get_price(){return price*discount;}
};
