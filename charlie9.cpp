#include "charlie9.h"
void Milktea::display(){
    cout<<"�̲�����:"<<name<<endl;
    cout<<"����:"<<temp<<endl;
    cout<<"�̲�۸�:"<<price<<"Ԫ"<<endl;
    cout<<"�̲��ۿ�: %"<<discount*100<<endl;
    cout<<endl;
}

int main(){
    Milktea m1("�����̲�","��",10,0.95),m2("��֦��¶","��",15,0.85),m3("�����̲�","��",14,0.9),m4("��������","����",14,0.98),m5("������ˮ����","��",20,0.8);
    m1.display();
    m2.display();
    m3.display();
    m4.display();
    m5.display();
    return 0;
}
