#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<double>R;
    int a;
    double b,sum=0;
    cout<<"������Ҫ����Ĳ����������!!"<<endl;cin>>a;R.resize(a);
    for(int i=0;i<a;i++){
        cout<<"������Ҫ����Ĳ���������ֵ!!"<<endl;
        cin>>b;
        R[i]=1/b;
        sum+=R[i];
    }
    cout<<"�����ܵ���Ϊ"<<1/sum<<" ��"<<endl;
    return 0;
}