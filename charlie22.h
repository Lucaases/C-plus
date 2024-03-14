#include <iostream>
#include <random>
#include <math.h>
using namespace std;

class Complex{
private:
    double real;
    double imag;
    double abs;
public:
    Complex(){}
    Complex(double a,double b):real(a),imag(b),abs(sqrt(a*a+b*b)){}
    ~Complex(){}
    double getreal(){return real;}
    double getimag(){return imag;}
    double getabs(){return abs;}
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
		else {cout<<"����:"<<real<<"+0i"<<endl;
		cout<<"����ʵ��Ϊ"<<real<<endl;
		cout<<"�����鲿Ϊ"<<imag<<endl;
		cout<<"������ģΪ"<<abs<<endl<<endl;
	    }
    }
};

Complex operator+(Complex& a,Complex& b){return Complex(a.getreal()+b.getreal(),a.getimag()+b.getimag());}

Complex operator-(Complex& a,Complex& b){return Complex(a.getreal()-b.getreal(),a.getimag()-b.getimag());}

Complex operator*(Complex& a,Complex& b){return Complex(a.getreal()*b.getreal()-a.getimag()*b.getimag(),a.getreal()*b.getimag()+a.getimag()*b.getreal());}

Complex operator/(Complex& a,Complex& b){return Complex((a.getreal()*b.getreal()-a.getimag()*(-b.getimag()))/(b.getreal()*b.getreal()+b.getimag()*b.getimag()),(a.getreal()*(-b.getimag())+a.getimag()*b.getreal())/(b.getreal()*b.getreal()+b.getimag()*b.getimag()));}

void operator<(Complex& a,Complex& b){Complex t;if(a.getabs()<b.getabs()){t=a;a=b;b=t;}}




