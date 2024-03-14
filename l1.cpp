#include "l1.h"

int main() {
    unsigned int seed = generateSeedFromTimestamp();
    random_device rd;
    mt19937 gen(seed);
    mt19937 gen1(rd());
    mt19937 gen2(seed+45);
    mt19937 gen3(seed-25);
    mt19937 gen4(seed-80);
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

    vector<Phone> p;
    
    ofstream outfile;
    outfile.open("I:\\C plus\\c++\\phone_data.txt");
    for(int i=0;i<10;i++){
        p.emplace_back(cpu[x(gen)],power[y(gen1)],bt[z(gen2)],phoneid[y(gen3)],resolution[m(gen4)],price[z(gen1)]);
    }
    for(Phone& S:p){
        outfile<<S;
    }
    outfile.close();
    // 读取文件中的手机信息
    vector<Phone> phones;
    readFromFile(phones, "I:\\C plus\\c++\\phone_data.txt");

    int choice;
    do {
        cout << "\n选择操作:\n"
             << "1. 显示所有手机信息\n"
             << "2. 添加手机信息\n"
             << "3. 删除手机信息\n"
             << "4. 保存手机信息到文件\n"
             << "5. 退出\n"
             << "选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayPhones(phones);
                break;
            case 2:
                addPhone(phones);
                break;
            case 3:
                deletePhone(phones);
                break;
            case 4:
                writeToFile(phones, "phone_data.txt");
                cout << "已保存手机信息到文件" << endl;
                break;
            case 5:
                cout << "退出程序" << endl;
                break;
            default:
                cout << "请输入有效的选项" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}