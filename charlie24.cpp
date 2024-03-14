#include "charlie24.h"

int main(){
	CPU cpu1(1500,60,1000,70,"i9 14900k");cpu1.display();cout<<endl;
	CPU cpu2(1800,80,1900,90,"R9 7900x3d");cpu2.display();cout<<endl;
	cpu1<cpu2;
	return 0;
}
