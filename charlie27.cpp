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
    string resolution[6]={"2532 x 1170 像素","2400 x 1080 像素","2340 x 1080 像素","3200 x 1440 像素","3840 x 1644 像素","2448 x 1080 像素"};
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
            cout<<"请输入手机型号："<<endl;cin>>d;
            cout<<"请输入手机分辨率："<<endl;cin>>e;
            cout<<"请输入手机处理器："<<endl;cin>>f;
            cout<<"请输入手机电池容量："<<endl;cin>>a;
            cout<<"请输入手机功耗："<<endl;cin>>b;
            cout<<"请输入手机价格："<<endl;cin>>c;
            if(a<0||b<0||c<0){
                cout<<"输入错误，请重新输入"<<endl;
                system("pause");
                continue;}
            phones.emplace_back(f,b,a,d,e,c);
            if(phones.size()>j){
                cout<<"添加成功"<<endl;}
            savetofile(phones);
            system("pause");
            system("cls");
            continue;}
        case '3':{
            system("cls");
            int g;unsigned int j=phones.size();
            cout<<"请输入要删除的手机序号："<<endl;cin>>g;
            if(g<1||g>static_cast<int>(j)){
                cout<<"输入错误，请重新输入"<<endl;
                system("pause");
                continue;}
            phones.erase(phones.begin()+g-1);
            if(phones.size()<j){
                cout<<"删除成功"<<endl;}
            savetofile(phones);
            system("pause");
            system("cls");
            continue;}
        case '4':{
            system("cls");
            cout<<"退出"<<endl;
            return 0;}
        default:{
            cout<<"输入错误，请重新输入"<<endl;
            system("pause");
            continue;}
    }
}
    return 0;
}