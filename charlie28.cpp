#include "charlie28.h"

bool cmp(Pokemen&a,Pokemen&b){
	return a.battle()>b.battle();
}
int main(){
	vector<Pokemen> P;
	P.emplace_back("Æ¤¿¨Çð",150,70,90,40);
	P.emplace_back("³¬ÃÎ",170,50,100,35);
	P.emplace_back("¹¢¹í",140,40,60,35);
	P.emplace_back("°¢¶ûÖæË¹",130,60,70,50);
	sort(P.begin() ,P.end(),cmp);
	for(Pokemen& a:P){
		a.show();
	}
	return 0;
}
