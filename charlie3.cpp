#include <iostream>
#include <string>
using namespace std;
typedef struct phone
{
    int ID;
    int battery_capacity;
    int weight;
    string color;
    void set()
    {
        cin>>ID>>battery_capacity>>weight>>color;
    }
    void display()
    {
        cout<<"ID is "<<ID<<endl;
        cout<<"battery_capacity is "<<battery_capacity<<endl;
        cout<<"weight is "<<weight<<endl;
        cout<<"color is "<<color<<endl;
    }
}p,*a;

int main()
{
    p p1,p2,p3;
    p1.set();
    p2.set();
    p3.set();
    p1.display();
    p2.display();
    p3.display();
    system("pause");
}
