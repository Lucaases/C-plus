#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ALU{
private:
    double MIPS;
    double power;
public:
    ALU(){}
    ALU(double a,double b):MIPS(a),power(b){}
    ~ALU(){}
    double getpower(){return power;}
};

class CU{
private:
    double MIPS;
    double power;
public:
    CU(){}
    CU(double a,double b):MIPS(a),power(b){}
    ~CU(){}
    double getpower(){return power;}
};

class CPU : public ALU,public CU{
private:
    string id;
    double MIPS_Compared;
    double power_total;
public:
    CPU(){}
    CPU(double a,double b,double c,double d,string e):ALU(a,b),CU(c,d),id(e),MIPS_Compared(min(a,c)),power_total(ALU::getpower()+CU::getpower()){}
    ~CPU(){}
    double getpower_total(){return power_total;}
    void display(){
        cout<<"cpu型号:"<<id<<endl;
        cout<<"cpu执行速度:"<<MIPS_Compared<<"MIPS"<<endl;
        cout<<"cpu功耗:"<<power_total<<"W"<<endl;
    }
};

void operator<(CPU&a,CPU&b){
    if(a.getpower_total()<b.getpower_total()){a.display();}
    else{b.display();}
}