#include <iostream>
#include <string>
using namespace std;

class Animal{
private:
	int age;
	double weight;
public:
	Animal(int a,double b):age(a),weight(b){}
	Animal(){}
	~Animal(){}
	void walk(){
		cout<<"��"<<endl;
	}
	void eat(){
		cout<<"��"<<endl;
	}
	void sleep(){
		cout<<"˯"<<endl;
	}
	int get_age(){
		return age;
	}
	double get_weight(){
		return weight;
	}
};

class Cat:private Animal{
private:
	string type;
	string color;
public:
	Cat(int a,double b,string c,string d):Animal(a,b),type(c),color(d){}
	Cat(){}
	~Cat(){}
	void miao(){
		cout<<"��"<<endl;
	}
	
	void display(){
		cout<<"è�����䣺"<<this->get_age()<<"��"<<endl;
		cout<<"è�����أ�"<<this->get_weight()<<"kg"<<endl;
		cout<<"è�����ࣺ"<<type<<endl;
		cout<<"è�ķ�ɫ��"<<color<<endl<<endl;
	}
	void compare(Cat* p,int size){
		Cat t;
		for(int i=0;i<size;i++){
			for(int j=0;j<size-1-i;j++){
				if(p[j+1].get_weight()>p[j].get_weight()){
					t=p[j+1];
					p[j+1]=p[j];
					p[j]=t;
			}}
		}
		cout<<"��������è����Ϣ��"<<endl;
		p[0].display();
	}
	
};
