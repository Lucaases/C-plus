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
		cout<<"ab���С���㣬�޷���ƽ������"<<endl;
	}
	try{
		cout<<c.divide()<<endl;
	}
	catch(float){
		cout<<"��ĸΪ�㣬�޷��������"<<endl;
	}
	return 0;
}
