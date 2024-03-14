#include "charlie27.h"

int main(){
    unsigned int seed = generateSeedFromTimestamp();
    random_device rd;
    mt19937 gen(seed);
    mt19937 gen1(rd());
    uniform_int_distribution<> l(-10000,10000);
    mt19937 gen2(seed+l(gen1));
    mt19937 gen3(seed+l(gen2));
    mt19937 gen4(seed-l(gen3));
    uniform_int_distribution<> x(0,10);
    uniform_int_distribution<> y(0,9);
    uniform_int_distribution<> z(0,11);
    uniform_int_distribution<> m(0,5);
    string resolution[6]={"2532 x 1170 ����","2400 x 1080 ����","2340 x 1080 ����","3200 x 1440 ����","3840 x 1644 ����","2448 x 1080 ����"};
    string cpu[11]={"Apple A17","HiSilicon Kirin 9000S","Qualcomm Snapdragon 888","Qualcomm Snapdragon 8+","Qualcomm Snapdragon 8 Gen 3","Qualcomm Snapdragon 765G","Apple A16","Apple A15","Apple A17 Pro","MediaTek Dimensity 9200","MediaTek Dimensity 9300"};
    string phoneid[10]={"Apple","Xiaomi","Huawei","Oppo","Vivo","OnePlus","Samsung","Honor","ZTE","Sony"};
    int bt[12]={4500,3200,4000,3800,4100,5000,5300,4600,2800,3500,3900,3700};
    int price[12]={1899,9399,12999,2699,3299,4499,5999,6799,5899,4899,3799,2399};
    int power[10]={8,10,12,14,16,7,9,11,13,17};
    string line; vector<P>p; vector<P>phones;
    for(int i=0;i<10;i++){
        p.emplace_back(cpu[x(gen)],power[y(gen1)],bt[z(gen2)],phoneid[y(gen3)],resolution[m(gen4)],price[z(gen1)]);
    }

    savetofile(p);
    readFromFile(phones);

    while(1){
     system("cls");
     menu();
     char choice=_getch();
    switch(choice){
        case '1':{
            system("cls");
            for(P& S:phones){
                S.display();
            }
            system("pause");
            system("cls");
            continue;}
        case '2':{
            system("cls");
            int a,b,c;string d,e,f;unsigned int j=phones.size();
            cout<<"�������ֻ��ͺţ�"<<endl;cin>>d;
            cout<<"�������ֻ��ֱ��ʣ�"<<endl;cin>>e;
            cout<<"�������ֻ���������"<<endl;cin>>f;
            cout<<"�������ֻ����������"<<endl;cin>>a;
            cout<<"�������ֻ����ģ�"<<endl;cin>>b;
            cout<<"�������ֻ��۸�"<<endl;cin>>c;
            if(a<0||b<0||c<0){
                cout<<"�����������������"<<endl;
                system("pause");
                continue;}
            phones.emplace_back(f,b,a,d,e,c);
            if(phones.size()>j){
                cout<<"��ӳɹ�"<<endl;}
            savetofile(phones);
            system("pause");
            system("cls");
            continue;}
        case '3':{
            system("cls");
            int g;unsigned int j=phones.size();
            cout<<"������Ҫɾ�����ֻ���ţ�"<<endl;cin>>g;
            if(g<1||g>static_cast<int>(j)){
                cout<<"�����������������"<<endl;
                system("pause");
                continue;}
            phones.erase(phones.begin()+g-1);
            if(phones.size()<j){
                cout<<"ɾ���ɹ�"<<endl;}
            savetofile(phones);
            system("pause");
            system("cls");
            continue;}
        case '4':{
            system("cls");
            cout<<"�˳�"<<endl;
            return 0;}
        default:{
            cout<<"�����������������"<<endl;
            system("pause");
            continue;}
    }
}
    return 0;
}