#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
typedef class student
{
public:
    string name;
    int age;
    double spend_1;
    double spend_2;
    double spend_3;
    double avg_spend_max_age(student* s,int n)
    {
        int a=0;
        for(int i=0;i<n;++i)
        {
            if(s[i].age>s[i-1].age){
                a=i;
            }
        }
        return ((s[a].spend_1+s[a].spend_2+s[a].spend_3)/3);
    }
}s,*a;

int main()
{
    s stu[3]={{"hu",20,800,900,9500},{"liu",26,780,858,920},{"chen",25,1750,860,959}};
    cout<<"avg="<<setprecision(9)<<stu->avg_spend_max_age(stu,3)<<endl;
    system("pause");
}
