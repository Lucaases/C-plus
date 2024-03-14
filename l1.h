#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

class Electronics {
private:
    string CPU_id;
    int power;
    int battery_capacity;

public:
    Electronics() {}
    Electronics(const string& cpu, int pwr, int battery): CPU_id(cpu), power(pwr), battery_capacity(battery) {}
    string getCPU_id() const { return CPU_id; }
    int getPower() const { return power; }
    int getBatteryCapacity() const { return battery_capacity; }
    void setCPU_id(const string& cpu) { CPU_id = cpu; }
    void setPower(int pwr) { power = pwr; }
    void setBatteryCapacity(int battery) { battery_capacity = battery; }
};

class Phone : public Electronics {
private:
    string phone_id;
    string phone_resolution;
    int price;
public:
    Phone() {}
    Phone(const string& cpu, int pwr, int battery, const string& id, const string& resolution, int cost) : Electronics(cpu, pwr, battery), phone_id(id), phone_resolution(resolution), price(cost) {}
    string getPhoneId() const { return phone_id; }
    string getPhoneResolution() const { return phone_resolution; }
    int getPrice() const { return price; }
    void setPhoneId(const string& id) { phone_id = id; }
    void setPhoneResolution(const string& resolution) { phone_resolution = resolution; }
    void setPrice(int cost) { price = cost; }
    friend bool operator<(const Phone& a, const Phone& b);
    friend ostream& operator<<(ostream& out, const Phone& p);
    friend istream& operator>>(istream& in, Phone& p);
};

bool operator<(const Phone& a, const Phone& b) {
    return a.getPrice() < b.getPrice();
}

ostream& operator<<(ostream& out, const Phone& p) {
    out << p.getPhoneId() << endl;
    out << p.getPhoneResolution() << endl;
    out << p.getCPU_id() << endl;
    out << p.getBatteryCapacity() << "mAh" << endl;
    out << p.getPower() << "W" << endl;
    out << p.getPrice() << "元" << endl;
    return out;
}

istream& operator>>(istream& in, Phone& p) {
    string cpu, id, resolution;
    int power, battery, price;

    in >> id >> resolution >> cpu >> battery >> power >> price;
    
    p.setPhoneId(id);
    p.setPhoneResolution(resolution);
    p.setCPU_id(cpu);
    p.setBatteryCapacity(battery);
    p.setPower(power);
    p.setPrice(price);

    return in;
}

void displayPhones(const vector<Phone>& phones) {
    for (const auto& phone : phones) {
        cout << phone << endl;
    }
}

void writeToFile(const vector<Phone>& phones, const string& filename) {
    ofstream outfile(filename);

    if (!outfile.is_open()) {
        cout << "无法打开文件" << endl;
        return;
    }

    for (const auto& phone : phones) {
        outfile << phone << endl;
    }

    outfile.close();
}

void readFromFile(vector<Phone>& phones, const string& filename) {
    ifstream infile(filename);

    if (!infile.is_open()) {
        cout << "无法打开文件" << endl;
        return;
    }

    phones.clear(); // Clear existing phones before reading from file

    Phone temp_phone;
    while (infile >> temp_phone) {
        phones.push_back(temp_phone);
    }

    infile.close();
}

void addPhone(vector<Phone>& phones) {
    string cpu, id, resolution;
    int power, battery, price;

    cout << "输入手机型号: ";
    cin >> id;
    cout << "输入手机分辨率: ";
    cin >> resolution;
    cout << "输入手机处理器: ";
    cin >> cpu;
    cout << "输入手机电池容量（mAh）: ";
    cin >> battery;
    cout << "输入手机功耗（W）: ";
    cin >> power;
    cout << "输入手机价格（元）: ";
    cin >> price;

    Phone new_phone(cpu, power, battery, id, resolution, price);
    phones.push_back(new_phone);
}

void deletePhone(vector<Phone>& phones) {
    string id;
    cout << "输入要删除的手机型号: ";
    cin >> id;

    auto it = find_if(phones.begin(), phones.end(), [&](const Phone& p) {
        return p.getPhoneId() == id;
    });

    if (it != phones.end()) {
        phones.erase(it);
        cout << "已成功删除手机信息" << endl;
    } else {
        cout << "未找到匹配的手机型号" << endl;
    }
}

unsigned int generateSeedFromTimestamp() {
  auto now = std::chrono::system_clock::now(); 
  auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()); 
  return static_cast<unsigned int>(timestamp.count());
}