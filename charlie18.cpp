#include "charlie18.h"
int main(){
	Cat cat[3]={Cat(5,3,"��żè","��ɫ"),Cat(6,4,"Ӣ����βè","��ɫ"),Cat(10,5,"��˹è","�ٻ�ɫ")};
	for(int i=0;i<3;i++){
		cat[i].display();
	}
	cat->compare(cat,3);
	return 0;
}
