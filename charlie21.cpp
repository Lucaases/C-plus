#include "charlie21.h"
int main(){
	AmphibianCar A[3]={AmphibianCar(2,3,"��ɫ","����"),AmphibianCar(5,2,"��ɫ","����"),AmphibianCar(7,9,"��ɫ","������")};
	for(int i=0;i<3;i++){
		cout<<endl;
		A[i].display();
	}
	return 0;
}
