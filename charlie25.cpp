#include "charlie25.h"

int main(){
	M a1(5,3,
		8,9);
	M a2(6,1,
		9,5);
	cout<<"����1��"<<endl;a1.display();cout<<endl;
	cout<<"����2��"<<endl;a2.display();cout<<endl;
	a1+a2;
	a1-a2;
    a1*a2;
	return 0;
}
