#include "charlie20.h"
int main(){
	Drinks Drink[3]={Drinks(1,"ø…¿÷",2.5,300,500),Drinks(2,"—©±Ã",3,400,400),Drinks(3,"∑“¥Ô",3.5,350,200)};
	cout<<endl<<"“˚¡œ–≈œ¢ ‰≥ˆ"<<endl;
	for(int i=0;i<3;i++){
		cout<<endl;
		Drink[i].display();
	}
	Milk Milks[3]={Milk(1,"π‚√˜≈£ƒÃ",5,200,100,"À·ƒÃ","∫¨ƒÃ¡ø70%",7),Milk(2,"“¡¿˚≈£ƒÃ",3,150,120,"œ ƒÃ","∫¨ƒÃ¡ø90%",3),Milk(3,"√…≈£≈£ƒÃ",4,200,150,"¥ø≈£ƒÃ","∫¨ƒÃ¡ø80%",180)};
	Tea Teas[3]={Tea(1,"±˘∫Ï≤Ë",2,500,200,"∫Ï≤Ë","Ωœ≈®",365),Tea(2,"¬Ã≤Ë",3,500,180,"¬Ã≤Ë","“ª∞„",180),Tea(3,"∫⁄≤Ë",2,600,220,"∫⁄≤Ë","Ωœœ°",365)};
	cout<<endl<<"≈£ƒÃ–≈œ¢ ‰≥ˆ"<<endl;
	for(int j=0;j<3;j++){
		cout<<endl;
		Milks[j].display1();
	}
	cout<<endl<<"≈£ƒÃ∞¥±£÷ ∆⁄¥”–°µΩ¥Û≈≈–Ú"<<endl;
	Milks->compare(Milks,3);
	return 0;
}
