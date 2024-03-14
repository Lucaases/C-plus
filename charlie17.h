#include <iostream>
#include <math.h>
using namespace std;

class Complex{
private:
	double real;
	double imag;
	double abs;
public:
	Complex(double a,double b):real(a),imag(b){abs=sqrt(a*a+b*b);}
	Complex(){};
	~Complex(){}
	void display(){
		if(imag>0){
		cout<<"����:"<<real<<"+"<<imag<<"i"<<endl;
		cout<<"�����:"<<real<<"-"<<imag<<"i"<<endl;
        cout<<"����ʵ��Ϊ"<<real<<endl;
		cout<<"�����鲿Ϊ"<<imag<<endl;
		cout<<"������ģΪ"<<abs<<endl<<endl;
		}
		else if(imag<0){
		cout<<"����:"<<real<<imag<<"i"<<endl;
		cout<<"�����:"<<real<<"+"<<-imag<<"i"<<endl;
        cout<<"����ʵ��Ϊ"<<real<<endl;
		cout<<"�����鲿Ϊ"<<imag<<endl;
		cout<<"������ģΪ"<<abs<<endl<<endl;
		}
		else {cout<<"����:"<<real<<endl;
		cout<<"����ʵ��Ϊ"<<real<<endl;
		cout<<"�����鲿Ϊ"<<imag<<endl;
		cout<<"������ģΪ"<<abs<<endl<<endl;
	}
}

	void compare(Complex* p,int size){
		Complex t;
		for(int i=0;i<size;i++){
			for(int j=0;j<size-1-i;j++){
				if(p[j+1].abs<p[j].abs){
					 t=p[j+1];
					 p[j+1]=p[j];
					 p[j]=t;
			}}
		}
	cout<<"ģ�����Ϊ��"<<endl;
	p[size-1].display();

	for(int m=0;m<size;m++){
		p[m].display();
		}
	}
};
