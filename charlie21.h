#include <iostream>
#include <string>
using namespace std;

class car{
private:
	double weight;
public:
	car(){}
	car(double a):weight(a){}
	~car(){}
	double getweight(){return weight;}
};

class boat{
private:
	double weight;
public:
	boat(){}
	boat(double a):weight(a){}
	~boat(){}
	double getweight(){return weight;}
};

class AmphibianCar:public car,public boat{
private:
	string name_ac;
	string color_ac;
	double weight_ac;
public:
	AmphibianCar(){}
	AmphibianCar(double a,double f,string g,string h):car(a),boat(f),name_ac(g),color_ac(h),weight_ac(car::getweight()+boat::getweight()){}
	~AmphibianCar(){}
	void display(){
		cout<<name_ac<<endl;
		cout<<color_ac<<endl;
		cout<<weight_ac<<endl;
	}
};
