#include "charlie19.h"
int main(){
	Cat cat[3]={Cat(5,4,"��żè","��ɫ"),Cat(6,3,"Ӣ����βè","��ɫ"),Cat(10,6,"��˹è","�ٻ�ɫ")};
	for(int i=0;i<3;i++){
		cat[i].display();
		//cat[i].eat();
	}
	cat->compare(cat,3);
	return 0;
}
