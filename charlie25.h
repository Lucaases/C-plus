#include <iostream>
#include <string>

using namespace std;

typedef class SquareMatrix2{
public:
	int a;
	int b;
	int c;
	int d;
	SquareMatrix2(int e,int f,int g,int h):a(e),b(f),c(g),d(h){}
	SquareMatrix2(){}
	~SquareMatrix2(){}
	void display(){
		cout<<a<<"    "<<b<<endl<<endl;
		cout<<c<<"    "<<d<<endl<<endl;
	}
}M;

void operator+(M& a1,M& b1){
	M c1;
	c1.a=a1.a+b1.a;
	c1.b=a1.b+b1.b;
	c1.c=a1.c+b1.c;
	c1.d=a1.d+b1.d;
	cout<<"¾ØÕó¼Ó·¨£º"<<endl;
	c1.display();
}

void operator-(M& a1,M& b1){
	M c1;
	c1.a=a1.a-b1.a;
	c1.b=a1.b-b1.b;
	c1.c=a1.c-b1.c;
	c1.d=a1.d-b1.d;
	cout<<"¾ØÕó¼õ·¨£º"<<endl;
	c1.display();
}

void operator*(M& a1,M& b1){
	M c1;
	c1.a=a1.a*b1.a+a1.b*b1.c;
	c1.b=a1.a*b1.b+a1.b*b1.d;
	c1.c=a1.c*b1.a+a1.d*b1.c;
	c1.d=a1.c*b1.b+a1.d*b1.d;
	cout<<"¾ØÕó³Ë·¨£º"<<endl;
	c1.display();
}
