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
		cout<<"走"<<endl;
	}
	void eat(){
		cout<<"吃"<<endl;
	}
	void sleep(){
		cout<<"睡"<<endl;
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
		cout<<"喵"<<endl;
	}
	
	void display(){
		cout<<"猫的年龄："<<this->get_age()<<"岁"<<endl;
		cout<<"猫的体重："<<this->get_weight()<<"kg"<<endl;
		cout<<"猫的种类："<<type<<endl;
		cout<<"猫的发色："<<color<<endl<<endl;
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
		cout<<"体重最大的猫的信息："<<endl;
		p[0].display();
	}
	
};
