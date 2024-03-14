#include "charlie14.h"
double mypay::transfer_fee=0.015;
int mypay::User_download=0;
int main(){
	mypay a[8]={mypay("Max",1000,1428000,100000,"sdw28asr","12345678903"),
	mypay("Jane",2000,256173.18,100000,"bvht4ght84","12345678911"),
	mypay("John",50000,5354.25,100000,"jhku879","12345678900"),
	mypay("Rick",1000000,7536.12,100000,"5f4efd51","12345678907"),
	mypay("Sarah",500000,65913.51,1000000,"a4qwds54","12345678910"),
	mypay("Mike",5000000,105484.85,1000000,"4864hgtdd","12345678906"),
	mypay("Orion",30000,25.86,30000,"7864fe51d","12345678905"),
	mypay("Ami",100000,48642.45,500000,"9e6rd1d","12345678908")};
    cout<<endl;
	for(int i=0;i<8;i++){
		a[i].Check_Infor();
		cout<<endl;
	}
	cout<<"User_download="<<a[0].Check_User_download()<<endl;
	return 0;
}
