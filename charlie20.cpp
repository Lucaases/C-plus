#include "charlie20.h"
int main(){
	Drinks Drink[3]={Drinks(1,"����",2.5,300,500),Drinks(2,"ѩ��",3,400,400),Drinks(3,"�Ҵ�",3.5,350,200)};
	cout<<endl<<"������Ϣ���"<<endl;
	for(int i=0;i<3;i++){
		cout<<endl;
		Drink[i].display();
	}
	Milk Milks[3]={Milk(1,"����ţ��",5,200,100,"����","������70%",7),Milk(2,"����ţ��",3,150,120,"����","������90%",3),Milk(3,"��ţţ��",4,200,150,"��ţ��","������80%",180)};
	Tea Teas[3]={Tea(1,"�����",2,500,200,"���","��Ũ",365),Tea(2,"�̲�",3,500,180,"�̲�","һ��",180),Tea(3,"�ڲ�",2,600,220,"�ڲ�","��ϡ",365)};
	cout<<endl<<"ţ����Ϣ���"<<endl;
	for(int j=0;j<3;j++){
		cout<<endl;
		Milks[j].display1();
	}
	cout<<endl<<"ţ�̰������ڴ�С��������"<<endl;
	Milks->compare(Milks,3);
	return 0;
}
