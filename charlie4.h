#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
typedef class computer
{
private:
    string brand;
    int memory_size;
    double monitor_size;
    string cpu;
    int disk_size;
    double price;
public:
    void setdata(){
        cin>>brand>>memory_size>>monitor_size>>cpu>>disk_size>>price;
    }
    void display(){
        cout<<"Computer's brand is "<<brand<<endl;
        cout<<"Computer's memory_size is "<<memory_size<<"GB"<<endl;
        cout<<"Computer's monitor_size is "<<monitor_size<<"Itch"<<endl;
        cout<<"Computer's cpu is "<<cpu<<endl;
        cout<<"Computer's disk_size is "<<disk_size<<"GB"<<endl;
        cout<<"Computer's price is "<<price<<"Yuan"<<endl;
    }
    void autoset(string a,int b,double c,string d,int e,double f)
    {
        brand = a;
        memory_size = b;
        monitor_size = c;
        cpu = d;
        disk_size = e;
        price = f;
    }
    void sort_by_price(computer* a,int n)
    {
        computer temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                if(a[j].price>a[j+1].price){
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            a[i].display();
            cout<<"\n";
        }
     }
    double avg(computer* a,int n)
    {
        double sum;
        for(int i=0;i<n;i++){
            sum+=a[i].price;
        }
        return (sum/5);
    }
}pc,*p;