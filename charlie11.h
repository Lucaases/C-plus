#include<iostream>
#include<string>
using namespace std;
class Milktea{
private:
    string name;
    string temp;
    float price;
    double discount;
    string sweet;
    string recommand;
    double calorie;
public:
    Milktea(){}
    Milktea(string a,string b,float c,double d,string e,string f,double g){name=a;temp=b;price=c;discount=d;sweet=e;recommand=f;calorie=g;cout<<name<<endl<<endl;}
    ~Milktea(){cout<<endl<<name<<endl;}
    void display(){
        cout<<"�̲�����:"<<name<<endl;
        cout<<"����:"<<temp<<endl;
        cout<<"�̲�۸�:"<<price<<"Ԫ"<<endl;
        cout<<"�̲��ۿ�: %"<<discount*100<<endl;
        cout<<"�̲����:"<<sweet<<endl;
        cout<<"�̲��Ƽ���:"<<recommand<<endl;
        cout<<"�̲�����:"<<calorie<<"kcal"<<endl;
        cout<<"�̲��ۿۺ�۸�:"<<discount*price<<"Ԫ"<<endl;
        cout<<endl;
    }

    float discount_price(){
        return price*discount;
    }

    double get_calorie(){
        return calorie;
    }

    void sort(Milktea* p){
        Milktea t;
        for(int i=0;i<7;i++){
            for(int j=0;j<7-i;j++){
                if(p[j+1].discount_price()>p[j].discount_price()){
                    t=p[j+1];
                    p[j+1]=p[j];
                    p[j]=t;
                }
            }
        } 
        p[7].display();
    }
};