#include "charlie17.h"
int main(){
	Complex com[10]={Complex(-4,3),Complex(9,-16),Complex(-10,5),Complex(-3,-2),Complex(14,3),
	Complex(21,13),Complex(25,5),Complex(-2,-1),Complex(-6,-9),Complex(20,0)};
	com->compare(com,10);
	return 0;
}
