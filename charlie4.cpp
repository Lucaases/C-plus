#include "charlie4.h"
int main()
{
    //pc com[5]={{"Asus",16,17.3,"I9 12900H",2048,15999},{"MSI",32,17.3,"I9 13980HX",4096,19999},{"Lenovo",16,15.6,"I9 12700H",2048,9999},{"Apple",16,14,"M2",2048,24999},{"Dell",32,15.6,"R9 7945HX",2048,12999}};
    pc p1,p2,p3,p4,p5;
    p1.autoset("Asus",16,17.3,"I9 12900H",2048,15999);
    p2.autoset("MSI",32,17.3,"I9 13980HX",4096,19999);
    p3.autoset("Lenovo",16,15.6,"I9 12700H",2048,9999);
    p4.autoset("Apple",16,14,"M2",2048,24999);
    p5.autoset("Dell",32,15.6,"R9 7945HX",2048,12999);
    pc com[5]={p1,p2,p3,p4,p5};
    com->sort_by_price(com,5);
    cout<<"\n";
    cout<<"Computer's average price is "<<setprecision(8)<<com->avg(com,5)<<endl;
     system("pause");
}