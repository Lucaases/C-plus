#include "charlie21.h"
int main(){
	AmphibianCar A[3]={AmphibianCar(2,3,"蓝色","船车"),AmphibianCar(5,2,"黄色","车船"),AmphibianCar(7,9,"绿色","车船车")};
	for(int i=0;i<3;i++){
		cout<<endl;
		A[i].display();
	}
	return 0;
}
