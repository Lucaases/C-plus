#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

class Pokemen{
private:
	string name;
	int blood;
	int attack;
	int defend;
	int move;
public:
	Pokemen(){}
	Pokemen(string a,int b,int c,int d,int f):name(a),blood(b),attack(c),defend(d),move(f){}
	~Pokemen(){}
	void attack1(){attack=2*attack;}
	void defend1(){defend=2*defend;}
	void flee(){move=2*move;}
	int battle(){return (attack+defend+move);}

	void show(){
		cout<<left<<setw(10)<<name<<"  ";
		cout<<blood<<"  ";
		cout<<attack<<"  ";
		cout<<defend<<"  ";
		cout<<move<<"  ";
		cout<<battle()<<endl;
	}
};

