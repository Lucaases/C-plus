#include "charlie12.h"

int main(){
    int N;
    double sum=0;
    cout<<"请输入下单奶茶数量"<<endl;
    cin>>N;
    Milktea *p;
    p = new Milktea[N];
    for (int i = 0; i < N; i++)
    {
        p[i].order();
    }
    system("cls");
    for (int j = 0; j < N; j++)
    {
        p[j].display();
        sum+=p[j].get_discount();
    }
    cout<<"奶茶总价为:"<<sum<<"元"<<endl;
    delete[] p;
    return 0;
}