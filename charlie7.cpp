#include "charlie7.h"

int main(){
    element x1(15),x2(90),x3(64),x4(59),x5(26),x6(31),x7(45),x8(82),x9(76);
    element y1(17),y2(58),y3(20),y4(86),y5(77),y6(29),y7(49),y8(99),y9(43);
    element matrix1[3][3]={x1,x2,x3,x4,x5,x6,x7,x8,x9};
    element matrix2[3][3]={y1,y2,y3,y4,y5,y6,y7,y8,y9};
    cout<<"����1:"<<endl;
    element::print(matrix1);
    cout<<endl<<"����2:"<<endl;
    element::print(matrix2);
    cout<<endl<<"����1ת��:"<<endl;
    element::transport(matrix1);
    cout<<endl<<"����2ת��:"<<endl;
    element::transport(matrix2);
    cout<<endl<<"����1�;���2���:"<<endl;
    element::dot(matrix1,matrix2);
    cout<<endl<<"����1�;���2�����ڿ˻�:"<<endl;
    element::kroneckor(matrix1,matrix2);
    system("pause");
    return 0;
}

