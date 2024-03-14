#include "charlie29.h"

int main(){
	Bee b[3]={Bee(11,12,13,"╨зи╚","type1",14),Bee(18,30,28,"╩фи╚","type2",20),Bee(7,5,11,"бли╚","type3",19)};
	for(int i=0;i<3;i++){
		b[i].show();
		cout<<endl;
	}
	return 0;
}
