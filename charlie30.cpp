#include "charlie30.h"

int main(){
	Calculator c;float a1,b1;
	cout<<"please enter a value of a!"<<endl;cin>>a1;c.a=a1;
	cout<<"please enter a value of b!"<<endl;cin>>b1;c.b=b1;
	cout<<c.add()<<endl;
	cout<<c.minus()<<endl;
	cout<<c.mutiply()<<endl;
	try{
		cout<<c.sqrt1()<<endl;
	}
	catch(float){
		cout<<"ab相乘小于零，无法开平方根！"<<endl;
	}
	try{
		cout<<c.divide()<<endl;
	}
	catch(float){
		cout<<"分母为零，无法相除！！"<<endl;
	}
	return 0;
}
