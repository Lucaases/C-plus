#include <iostream>
using namespace std;
void caculate1()
{
    int sum=0,s=1;
    for(int i=0;i<50;i++)
    {
        sum+=s;
        s=s+2;
    }
    cout<<"sum="<<sum<<endl;
}
void caculate2()
{
    int sum=0,s=1,sign=1;
    for(int i=0;i<50;i++)
    {
        sum+=s*sign;
        s=s+2;
        sign = -sign;
    }
    cout<<"sum="<<sum<<endl;
}
void caculate3()
{
    double sum=0,s=1;
    for(int i=0;i<99;i++)
    {
        sum+=s/(s+1);
        s+=1;
    }
    cout<<"sum="<<sum<<endl;
}
int main()
{
    caculate1();
    caculate2();
    caculate3();
    system("pause");
    return 0;
}