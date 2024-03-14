#include "charlie10.h"

string train::start = "深圳北站";
string train::end = "香港西九龙站";
string train::pass = "福田站";
int train::seat = 500;
double train::price_1 =226;
double train::price_2 =120;
double train::price_3 =75;

void train::display(){
    cout<<"列车编号:"<<id<<endl;
    cout<<"列车始发站:"<<start<<endl;
    cout<<"列车经停站:"<<pass<<endl;
    cout<<"列车终点站:"<<end<<endl;
    cout<<endl;
}
void train::display_price(){
    cout<<"商务座统一价格:"<<price_1<<endl;
    cout<<"一等座统一价格:"<<price_2<<endl;
    cout<<"二等座统一价格:"<<price_3<<endl;
}

int main(){
    train t1("G5611"),t2("G5607"),t3("G5625"),t4("G6539"),t5("G5821"),t6("G5613");
    t1.display();
    t2.display();
    t3.display();
    t4.display();
    t5.display();
    t6.display();
    t1.display_price();
    return 0;
}