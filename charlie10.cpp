#include "charlie10.h"

string train::start = "���ڱ�վ";
string train::end = "���������վ";
string train::pass = "����վ";
int train::seat = 500;
double train::price_1 =226;
double train::price_2 =120;
double train::price_3 =75;

void train::display(){
    cout<<"�г����:"<<id<<endl;
    cout<<"�г�ʼ��վ:"<<start<<endl;
    cout<<"�г���ͣվ:"<<pass<<endl;
    cout<<"�г��յ�վ:"<<end<<endl;
    cout<<endl;
}
void train::display_price(){
    cout<<"������ͳһ�۸�:"<<price_1<<endl;
    cout<<"һ����ͳһ�۸�:"<<price_2<<endl;
    cout<<"������ͳһ�۸�:"<<price_3<<endl;
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