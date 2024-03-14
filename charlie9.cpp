#include "charlie9.h"
void Milktea::display(){
    cout<<"ÄÌ²èÃû³Æ:"<<name<<endl;
    cout<<"ÀäÈÈ:"<<temp<<endl;
    cout<<"ÄÌ²è¼Û¸ñ:"<<price<<"Ôª"<<endl;
    cout<<"ÄÌ²èÕÛ¿Û: %"<<discount*100<<endl;
    cout<<endl;
}

int main(){
    Milktea m1("ÕäÖéÄÌ²è","Àä",10,0.95),m2("ÑîÖ¦¸ÊÂ¶","Àä",15,0.85),m3("ÓóÄàÄÌ²è","ÈÈ",14,0.9),m4("ÜÔÀòÄÌÂÌ","³£ÎÂ",14,0.98),m5("³¬¼¶±­Ë®¹û²è","Àä",20,0.8);
    m1.display();
    m2.display();
    m3.display();
    m4.display();
    m5.display();
    return 0;
}
