#include "charlie18.h"
int main(){
	Cat cat[3]={Cat(5,3,"布偶猫","灰色"),Cat(6,4,"英国短尾猫","白色"),Cat(10,5,"波斯猫","橘黄色")};
	for(int i=0;i<3;i++){
		cat[i].display();
	}
	cat->compare(cat,3);
	return 0;
}
