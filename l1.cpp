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
    string resolution[6]={"2532 x 1170 ����","2400 x 1080 ����","2340 x 1080 ����","3200 x 1440 ����","3840 x 1644 ����","2448 x 1080 ����"};
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
    // ��ȡ�ļ��е��ֻ���Ϣ
    vector<Phone> phones;
    readFromFile(phones, "I:\\C plus\\c++\\phone_data.txt");

    int choice;
    do {
        cout << "\nѡ�����:\n"
             << "1. ��ʾ�����ֻ���Ϣ\n"
             << "2. ����ֻ���Ϣ\n"
             << "3. ɾ���ֻ���Ϣ\n"
             << "4. �����ֻ���Ϣ���ļ�\n"
             << "5. �˳�\n"
             << "ѡ��: ";
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
                cout << "�ѱ����ֻ���Ϣ���ļ�" << endl;
                break;
            case 5:
                cout << "�˳�����" << endl;
                break;
            default:
                cout << "��������Ч��ѡ��" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}