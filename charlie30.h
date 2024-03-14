#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Calculator{
public:
	float a;
	float b;
	Calculator(){}
	Calculator(float c,float d):a(c),b(d){}
	~Calculator(){}
	float add(){
		return a+b;
	}
	float minus(){
		return a-b;
	} 
	float mutiply(){
		return a*b;
	}
	float sqrt1(){
		if((a*b)<0){throw a;}
		return sqrt(a*b);
	}
	float divide(){
		if(b==0){throw b;}
		return a/b;
	}
};
