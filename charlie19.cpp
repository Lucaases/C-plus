#include "charlie19.h"
int main(){
	Cat cat[3]={Cat(5,4,"布偶猫","灰色"),Cat(6,3,"英国短尾猫","白色"),Cat(10,6,"波斯猫","橘黄色")};
	for(int i=0;i<3;i++){
		cat[i].display();
		//cat[i].eat();
	}
	cat->compare(cat,3);
	return 0;
}
