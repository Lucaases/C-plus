#include <iostream>
#include <string>
using namespace std;

class Bug{
private:
	int age;
	int weight;
	int length;
public:
	Bug(int a,int b,int c):age(a),weight(b),length(c){}
	~Bug(){}
    int getage(){return age;}
	int getweight(){return weight;}
	int getlength(){return length;}

};

class Bee:public Bug{
private:
	string color;
	string type;
	int speed;
public:
	Bee(int a,int b,int c,string d,string f,int e):Bug(a,b,c),color(d),type(f),speed(e){}
	~Bee(){}
	void show(){
		cout<<getage()<<endl;
		cout<<getweight()<<endl;
		cout<<getlength()<<endl;
		cout<<color<<endl;
		cout<<type<<endl;
		cout<<speed<<endl;
	}
};
