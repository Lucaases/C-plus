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
		else {cout<<"复数:"<<real<<"+0i"<<endl;
		cout<<"复数实部为"<<real<<endl;
		cout<<"复数虚部为"<<imag<<endl;
		cout<<"复数的模为"<<abs<<endl<<endl;
	    }
    }
};

Complex operator+(Complex& a,Complex& b){return Complex(a.getreal()+b.getreal(),a.getimag()+b.getimag());}

Complex operator-(Complex& a,Complex& b){return Complex(a.getreal()-b.getreal(),a.getimag()-b.getimag());}

Complex operator*(Complex& a,Complex& b){return Complex(a.getreal()*b.getreal()-a.getimag()*b.getimag(),a.getreal()*b.getimag()+a.getimag()*b.getreal());}

Complex operator/(Complex& a,Complex& b){return Complex((a.getreal()*b.getreal()-a.getimag()*(-b.getimag()))/(b.getreal()*b.getreal()+b.getimag()*b.getimag()),(a.getreal()*(-b.getimag())+a.getimag()*b.getreal())/(b.getreal()*b.getreal()+b.getimag()*b.getimag()));}

void operator<(Complex& a,Complex& b){Complex t;if(a.getabs()<b.getabs()){t=a;a=b;b=t;}}




