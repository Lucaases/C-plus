#include "charlie11.h"

int main(){
    float sum=0,sum1=0;
    Milktea mt[8]={{"�����̲�","��",10,0.95,"����","һ��",260},{"��֦��¶","��",15,0.85,"������","�Ƚ��Ƽ�",240},{"�����̲�","��",14,0.9,"����","�ǳ��Ƽ�",320},{"������ˮ����","��",20,0.8,"������","�ǳ��Ƽ�",150},{"���ɲ�","��",16,0.9,"������","���Ƽ�",350},
    {"֥ʿ�����̸�","��",20,1.0,"����","һ��",280},{"���ʲ�","��",12,0.7,"����","�ǳ��Ƽ�",180},{"����֭","��",14,0.85,"������","һ��",190}};
    for(int i=0;i<8;i++){
        mt[i].display();
        sum+=mt[i].discount_price();
        sum1+=mt[i].get_calorie();
    }
    cout<<"8���̲��ۺ��ܼ�:"<<sum<<"Ԫ"<<endl<<endl;
    cout<<"8���̲������ܺ�:"<<sum1<<"kcal"<<endl<<endl;
    cout<<"�˱��̲�����ʵ�ݵ��̲�:"<<endl;
    mt->sort(mt);
    return 0;
}