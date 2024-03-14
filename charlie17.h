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
		cout<<"复数:"<<real<<"+"<<imag<<"i"<<endl;
		cout<<"共轭复数:"<<real<<"-"<<imag<<"i"<<endl;
        cout<<"复数实部为"<<real<<endl;
		cout<<"复数虚部为"<<imag<<endl;
		cout<<"复数的模为"<<abs<<endl<<endl;
		}
		else if(imag<0){
		cout<<"复数:"<<real<<imag<<"i"<<endl;
		cout<<"共轭复数:"<<real<<"+"<<-imag<<"i"<<endl;
        cout<<"复数实部为"<<real<<endl;
		cout<<"复数虚部为"<<imag<<endl;
		cout<<"复数的模为"<<abs<<endl<<endl;
		}
		else {cout<<"复数:"<<real<<endl;
		cout<<"复数实部为"<<real<<endl;
		cout<<"复数虚部为"<<imag<<endl;
		cout<<"复数的模为"<<abs<<endl<<endl;
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
	cout<<"模最大复数为："<<endl;
	p[size-1].display();

	for(int m=0;m<size;m++){
		p[m].display();
		}
	}
};
