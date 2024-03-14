#include "charlie22.h"
int main(){
    Complex a(5,6),b(7,-8);
    Complex Complexs[4]={a+b,a-b,a*b,a/b};
    cout<<"以下分别两复数相加,相减,相乘,相除的结果:"<<endl;
    for(int i=0;i<4;i++){
        Complexs[i].display();
    }

    cout<<endl<<"以下为随机生成20个复数按照模的大小由小到大排序:"<<endl;
    Complex Complexs1[20];

    for(int j=0;j<20;j++){
        uniform_real_distribution<double> u(-100, 100);
        uniform_real_distribution<double> y(-120, 120);
        default_random_engine e(j);
        Complexs1[j]=Complex(u(e),y(e));
    }

    for(int m=0;m<20;m++){
        for(int g=0;g<19-m;g++){
            Complexs1[g+1]<Complexs1[g];
        }
    }

    for(int n=0;n<20;n++){
        Complexs1[n].display();
    }

    return 0;
}

