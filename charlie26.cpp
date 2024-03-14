#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream infile;
	ofstream outfile;
	
	int sum=0;
	vector<int>a;

	infile.open("I:\\C plus\\c++\\charlie26.txt");

	while(!infile.eof()){
		int n;
		infile>>n;
		a.push_back(n);
	}

	for(int j=0;j<static_cast<int>(a.size());j++){
		sum+=a[j];
		cout<<a[j]<<endl;
	}
	cout<<"平均分为"<<sum/a.size()<<endl;
    infile.close();

	int m;int sum1=0;

    outfile.open("I:\\C plus\\c++\\charlie26.txt",ios::app);

    while(true){
		cin>>m;
		if(m == -1) {
			break;
		}
		a.push_back(m);
        outfile<<" "<<m;
	}

    outfile.close();
	a.pop_back();

	for(int k=0;k<static_cast<int>(a.size());k++){
		sum1+=a[k];
		cout<<a[k]<<endl;
	}
	
	cout<<"平均分为"<<sum1/a.size()<<endl;

	return 0;
	
}
