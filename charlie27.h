#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <conio.h>

using namespace std;

typedef class Electronic{
private:
    string CPU_id;
    int power;
    int battery_capacity;
public:
    Electronic(){}
    Electronic(string a,int b,int c):CPU_id(a),power(b),battery_capacity(c){}
    ~Electronic(){}
    string getCPU_id(){return CPU_id;}
    int getpower(){return power;}
    int getbattery_capacity(){return battery_capacity;}
    void sentCPU_id(string a){CPU_id=a;}
    void sentpower(int a){power=a;}
    void sentbattery_capacity(int a){battery_capacity=a;}
}E;

typedef class Phone:public E{
private:
    string phone_id;
    string phone_resolution;
    int price;
public:
    Phone(){}
    Phone(string a,int b,int c,string d,string e,int f):E(a,b,c),phone_id(d),phone_resolution(e),price(f){}
    ~Phone(){}
    int getprice(){return price;}
    string getphone_id(){return phone_id;}
    string getphone_resolution(){return phone_resolution;}
    void setprice(int a){price = a;}
    void setphone_id(string a){phone_id=a;}
    void setphone_resolution(string a){phone_resolution=a;}

    friend ostream & operator<<(ostream &out,Phone &A);
    friend istream & operator>>(istream &in,Phone &A);
    void display(){
        cout<<"�ֻ��ͺ�:"<<phone_id<<endl;
        cout<<"�ֻ��ֱ���:"<<phone_resolution<<endl;
        cout<<"�ֻ�������:"<<this->getCPU_id()<<endl;
        cout<<"�ֻ��������:"<<this->getbattery_capacity()<<"mAh"<<endl;
        cout<<"�ֻ�����:"<<this->getpower()<<"W"<<endl;
        cout<<"�ֻ��۸�:"<<price<<"Ԫ"<<endl<<endl;
    }
}P;

void operator<(P& a,P& b){
   P c=a.getprice()<b.getprice() ? a:b;
   c.display();
}

unsigned int generateSeedFromTimestamp() {//��ȡ��ǰʱ�������
  auto now = std::chrono::system_clock::now(); 
  auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()); 
  return static_cast<unsigned int>(timestamp.count());
}

ostream & operator<<(ostream &out, P &a){
       // cout<<"�ֻ��ͺ�:"<<a.phone_id<<endl;
       // cout<<"�ֻ��ֱ���:"<<a.phone_resolution<<endl;
       // cout<<"�ֻ�������:"<<a.getCPU_id()<<endl;
       // cout<<"�ֻ��������:"<<a.getbattery_capacity()<<"mAh"<<endl;
       // cout<<"�ֻ�����:"<<a.getpower()<<"W"<<endl;
       // cout<<"�ֻ��۸�:"<<a.price<<"Ԫ"<<endl<<endl;
        out<<a.phone_id<<endl;
        out<<a.phone_resolution<<endl;
        out<<a.getCPU_id()<<endl;
        out<<a.getbattery_capacity()<<"mAh"<<endl;
        out<<a.getpower()<<"W"<<endl;
        out<<a.price<<"Ԫ"<<endl;
    return out;
}

void savetofile(vector<P>& phones){
    ofstream outFile("I:\\C plus\\c++\\charlie27.txt", ios::out);
    if (!outFile) {
        cerr << "Failed opening" << endl;
        exit(1);
    }
    for(P& S:phones){
        outFile<<S;
    }
    outFile.close();
}

void readFromFile(vector<P>& phones) {
    ifstream inFile("I:\\C plus\\c++\\charlie27.txt");
    string line;
    int count{};

    if (!inFile) {
        cerr << "Failed opening" << endl;
        exit(1);
    }

    while (true) {
        count++;
        vector<string> lines;
        for (int i = 0; i < 6; ++i) {
            if (!getline(inFile, line)) {
                break;
            }
            lines.push_back(line);
        }
        if (lines.size() < 6) {
            break;  // �ļ��е���������6�ı������˳�ѭ��
        }
        phones.emplace_back(lines[2], stoi(lines[4]), stoi(lines[3]), lines[0], lines[1], stoi(lines[5]));
    }
    inFile.close();
}

void menu(){
    cout<<"1.��ʾ�����ֻ���Ϣ"<<endl<<endl;
    cout<<"2.����ֻ�"<<endl<<endl;
    cout<<"3.ɾ���ֻ�"<<endl<<endl;
    cout<<"4.�˳�"<<endl;
}
