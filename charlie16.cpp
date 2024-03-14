#include "charlie16.h"
int main(){
    int a[6]={13,51,231,5,91,26};
    float b[6]={13.6,51.1,231.2,5.4,91.5,26.7};
    char c[6]={'z','b','a','y','x','f'};
    Compare<int> c1(a);
    Compare<float> c2(b);
    Compare<char> c3(c);
    c1.Check_info();
    cout<<endl;
    c2.Check_info();
    cout<<endl;
    c3.Check_info();
    return 0;
}