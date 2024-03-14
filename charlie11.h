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
        cout<<"ÄÌ²èÃû³Æ:"<<name<<endl;
        cout<<"ÀäÈÈ:"<<temp<<endl;
        cout<<"ÄÌ²è¼Û¸ñ:"<<price<<"Ôª"<<endl;
        cout<<"ÄÌ²èÕÛ¿Û: %"<<discount*100<<endl;
        cout<<"ÄÌ²èÌð¶È:"<<sweet<<endl;
        cout<<"ÄÌ²èÍÆ¼ö¶È:"<<recommand<<endl;
        cout<<"ÄÌ²èÈÈÁ¿:"<<calorie<<"kcal"<<endl;
        cout<<"ÄÌ²èÕÛ¿Ûºó¼Û¸ñ:"<<discount*price<<"Ôª"<<endl;
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