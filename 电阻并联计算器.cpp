#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<double>R;
    int a;
    double b,sum=0;
    cout<<"请输入要计算的并联电阻个数!!"<<endl;cin>>a;R.resize(a);
    for(int i=0;i<a;i++){
        cout<<"请输入要计算的并联电阻阻值!!"<<endl;
        cin>>b;
        R[i]=1/b;
        sum+=R[i];
    }
    cout<<"并联总电阻为"<<1/sum<<" Ω"<<endl;
    return 0;
}