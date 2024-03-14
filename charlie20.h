#include <iostream>
#include <string>
using namespace std;

class Goods{
private:
	int id;
	string name;
	double price;
public:
	Goods(){}
	Goods(int a,string b,double c):id(a),name(b),price(c){}
	~Goods(){}
	int getid(){return id;}
	string getname(){return name;}
	double getprice(){return price;}
};

class Drinks:public Goods{
private:
	int volume;
	double calorie;
public:
	Drinks(){}
	Drinks(int a,string b,double c,int d,double e):Goods(a,b,c),volume(d),calorie(e){}
	~Drinks(){}
	void display(){
		cout<<"���Ϊ"<<this->getid()<<endl;
		cout<<"����Ϊ"<<this->getname()<<endl;
		cout<<"�۸�Ϊ"<<this->getprice()<<"Ԫ"<<endl;
		cout<<"����Ϊ"<<volume<<"mL"<<endl;
		cout<<"����Ϊ"<<calorie<<"kcal"<<endl;
	}
	int getvolume(){return volume;}
	double getcalorie(){return calorie;}
};

class Milk:private Drinks{
private:
	string type;
	string concentration;
	int expiration_date;
public:
	Milk(){}
	Milk(int a,string b,double c,int d,double e,string f,string g,int h):Drinks(a,b,c,d,e),type(f),concentration(g),expiration_date(h){}
	~Milk(){}
	void display1(){
		cout<<"���Ϊ"<<this->getid()<<endl;
		cout<<"����Ϊ"<<this->getname()<<endl;
		cout<<"�۸�Ϊ"<<this->getprice()<<"Ԫ"<<endl;
		cout<<"����Ϊ"<<this->getvolume()<<"mL"<<endl;
		cout<<"����Ϊ"<<this->getcalorie()<<"kcal"<<endl;
		cout<<"Ʒ��Ϊ"<<type<<endl;
		cout<<"Ũ��Ϊ"<<concentration<<endl;
		cout<<"������Ϊ"<<expiration_date<<"��"<<endl;
	}
	void compare(Milk* p,int n){
		Milk t;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(p[j+1].expiration_date<p[j].expiration_date){
					t=p[j+1];
					p[j+1]=p[j];
					p[j]=t;
			}
		}
	}
		for(int m=0;m<n;m++){
			cout<<endl;
			p[m].display1();
		}
}

};

class Tea:private Drinks{
private:
	string type;
	string concentration;
	int expiration_date;
public:
	Tea(){}
	Tea(int a,string b,double c,int d,double e,string f,string g,int h):Drinks(a,b,c,d,e),type(f),concentration(g),expiration_date(h){}
	~Tea(){}
	void display2(){
		cout<<"���Ϊ"<<this->getid()<<endl;
		cout<<"����Ϊ"<<this->getname()<<endl;
		cout<<"�۸�Ϊ"<<this->getprice()<<"Ԫ"<<endl;
		cout<<"����Ϊ"<<this->getvolume()<<"mL"<<endl;
		cout<<"����Ϊ"<<this->getcalorie()<<"kcal"<<endl;
		cout<<"Ʒ��Ϊ"<<type<<endl;
		cout<<"Ũ��Ϊ"<<concentration<<endl;
		cout<<"������Ϊ"<<expiration_date<<"��"<<endl;
	}
};
