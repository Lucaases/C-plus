#include "charlie23.h"

int main(){
	FlyingCat a1("¼Ó·Æ",5,3,0.5,200);a1.display();cout<<endl;
	FlyingCat a2("¶ÌÎ²",6,4,1,100);a2.display();cout<<endl;
	a1<a2;
	return 0;
}