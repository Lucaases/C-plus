#include <iostream>
using namespace std;
template<typename T>
void Anysort(T *p){
	T t;
	for(int i=0;i<10;i++){
		for(int j=0;j<9-i;j++){
			if(p[j+1]<p[j]){
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}	
		}
	}
	for(int m=0;m<10;m++){
		cout<<p[m]<<" ";
	}
	cout<<endl;
}
template<typename F>
void Anysort1(F *p){
	F t;
	for(int i=0;i<3;i++){
		for(int j=0;j<2-i;j++){
			if(p[j+1]<p[j]){
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}	
		}
	}
	for(int m=0;m<3;m++){
		cout<<p[m]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[10]={9,54,31,26,101,56,223,1,15,23};
	float b[10]={9,54,31,26,101,56,223,1,15,23};
	char c[10]={'a','c','b','z','d','g','f','s','x','t'};
	int d[3]={9,54,31};
	float f[3]={9,54,31};
	char e[3]={'a','c','b'};
	Anysort(a);
	Anysort(b);
	Anysort(c);
	Anysort1(d);
	Anysort1(f);
	Anysort1(e);
	return 0;
}
