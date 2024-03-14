#include <iostream>
#include <string>
using namespace std;

class Cat{
private:
    string name;
    double age;
    double weight;
public:
    Cat(){}
    Cat(string a, double b, double c):name(a),age(b),weight(c){}
    ~Cat(){}
    void mow(){cout<<"miao!"<<endl;}
    void eat(){cout<<"haochi!"<<endl;}
    void sleep(){cout<<"shui!"<<endl;}
    double getweight(){return weight;}
    double getage(){return age;}
    string getname(){return name;}
};

class FlyingCat :public Cat{
private:
    double wing_weight;
    double speed;
public:
    FlyingCat(){}
    FlyingCat(string a, double b, double c, double d,double f):Cat(a,b,c),wing_weight(d),speed(f){}
     ~FlyingCat(){}
     double get_totalweight(){return wing_weight+this->getweight();}
     void display(){
        cout<<"��è����:"<<this->getname()<<endl;
        cout<<"��è����:"<<this->getage()<<"��"<<endl;
        cout<<"��è����:"<<this->getweight()<<"kg"<<endl;
        cout<<"��è�������:"<<wing_weight<<"kg"<<endl;
        cout<<"��è�ٶ�:"<<speed<<"km/h"<<endl;
        cout<<"��è������:"<<this->get_totalweight()<<"kg"<<endl;
     }
};

void operator<(FlyingCat&a,FlyingCat&b){
    if(a.get_totalweight()<b.get_totalweight()){a.display();}
    else{b.display();}
}