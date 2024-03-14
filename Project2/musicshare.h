#include <iostream>
#include <random>
#include <string>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>//ʹ�ö�̬����
#include <unordered_map>//STL�е�һ����������,֧�ֿ��ٵĲ��ҡ������ɾ������

using namespace std;

default_random_engine e(static_cast<unsigned int>(time(NULL)));
uniform_int_distribution<int> u(0, 10);

class Music{
private:
    int id{};
    string name{};
    string singer{};
    string type{};
    int rating_default{};
    int rating{};
public:
    Music() {}
    Music(string a,string b,string c, int d): name(a), singer(b), type(c), rating(0) ,id(d) , rating_default(u(e)){}
    string getname() { return name; }
    string getsinger() { return singer; }
    string gettype() { return type; }
    int getrating() { return rating; }
    int getid() { return id; }
    void sendrating(int a) { rating = a; }
    int getrating_default() { return rating_default; }
    void display() {
        cout << left <<"�������:"<< left << setw(10) << id ;
        cout << left << "��������:"<< left << setw(20) << name ;
        cout << left  << "����:" << left << setw(10) << singer ;
        cout << left << "����:" << left << setw(10) << type ;
        cout << left  << "ƽ̨��ʼ����:" << right <<setw(2)<< rating_default<< "/10��";
        if (rating != 0) {
            cout << "      " << "�ۺ�����:" << right << rating << "/10��" << endl;
        }
        else {
            cout << "      " <<"��ʱ��û������"<< endl;
        }
    }
};

class User {
private:
    int id{};
    string username{};
public:
    unordered_map<string, int> musicRatings;
    unordered_map<string, string> musicSingers;
    User(int i,string u) : id(i), username(u) {}
    User() {}
    int getid() { return id; }
    string getusername() { return username; }
    void display() {
        cout << "�û����" << left << setw(10) << id  ;
        cout << "�û���" << left << setw(10) << username<<endl;
    }
    void rateMusic1(string a, int b) {
        musicRatings[a] = b;
    }
    void rateMusic2(string a, string b) {
        musicSingers[a] = b;
    }
};

class Group {
private:
    int id{};
    string name{};
    string introduction{};
public:
    vector<User*>members;
    Group() {}
    Group(string a, string b, int c) :name(a), introduction(b),id(c){}
    string getname() { return name; }
    string getintroduction() { return introduction; }
    int getid() { return id; }

    void add_user(User* user) {//��С����ӳ�Ա
        members.push_back(user);
    }

    void show_Members_Ratings() {
        if (members.empty()) {
            cout << endl << "С���пտ���Ҳ,�ڴ���ļ���" << endl<<endl;
        }
        else {
            for (User* user : members) {//����members
                cout << "�û����" << left << setw(5) << user->getid() << "�û���:" << left << setw(10) << user->getusername();
                if (user->musicRatings.empty()) {
                    cout << "�û�û�в������������" << endl;
                }
                else {
                    cout<< "���û�����:" << endl<<endl;
                    for (auto rating : user->musicRatings) {
                        cout << left<<setw(20)<< rating.first << ": " << rating.second <<"��" << endl;//�����ֵ��
                    }
                    cout <<"----------------------------------------" << endl;
                }
            }
        }
    }
};

class Platform {
public:
    vector<Music>musics;
    vector<User>users;
    vector<Group>groups;

    void add_newsong(int id) {
        string a, b, c;
        cout << "������Ҫ����ĸ���:" << endl; getline(cin, a);
        cout << "�������������:" << endl; getline(cin, b); 
        cout << "������������:" << endl; getline(cin, c);
        musics.emplace_back(a, b, c, id);
    }

    void add_newuser(int id,string a) {
            users.emplace_back(id, a);
    }

    void create_newgroup(int id, User& user) {
        string a, b;
        cout << "������Ҫ������С������:" << endl; getline(cin, a);
        cout << "������С����:" << endl; getline(cin, b);
        groups.emplace_back(a, b, id);
        for (Group& group : groups) {
            if (group.getname() == a) { group.add_user(&user); }
        }
    }

    void show_All_songs() {
        if (musics.empty()) {
            cout << endl << "����û������" << endl;
            system("pause");
        }
        else {
            for (Music& m : musics) {
                m.display();
            }
        }
    }

    void show_All_Groups() {
            for (Group group : groups) {
                cout << "*************************************************************************" << endl;
                cout<<"С����:"<<left<<setw(2)<<group.getid()<<endl<< "С������: " << group.getname() << endl << "С����: " << left <<setw(20)<<group.getintroduction() << endl;
                group.show_Members_Ratings();
            }    
    }

    void join_group(int a,User& user) {
        Group t;
        for (Group& group : groups) {
            int b = static_cast<int>(group.members.size());
            if (group.getid() == a) { t = group; group.add_user(&user); }
            if (group.members.size() > b) {
                cout << endl << "�ɹ�����С��,��ϲ!!" << endl;
            }
        }
        if (t.getname().empty()) { cout << "û���ҵ����С��,������" << endl; }
    }

    void quit_group(int id,int user_id) {
        Group t1; User t2; User* t3;
        for (Group& group : groups) {
            if (group.getid() == id) {
                t1 = group;
                for (User& user : users) {
                    t3 = &user;
                    if (user.getid()== user_id && find(group.members.begin(), group.members.end(), t3) != group.members.end()) {
                        int size = static_cast<int>(group.members.size());
                        auto it = find(group.members.begin(), group.members.end(), t3);
                        t2 = user;
                        group.members.erase(it);
                        if (size > static_cast<int>(group.members.size())) { system("cls"); cout << "�ɹ��˳�С��!!!" << endl; system("pause");}
                    }
                }
            }
        }
        if (t1.getname().empty()) { cout << "û���ҵ���С��!!" << endl; }
        if (!t1.getname().empty()&&t2.getusername().empty()) { cout << "û����С�����ҵ��ó�Ա!!" << endl; }
    }

    void quit_group_login(int id, User& u) {
        Group t1; User t2; User* t3; t3 = &u;
        for (Group& group : groups) {
            if (group.getid() == id) {
                t1 = group;
                for (User& user : users) {
                    if (find(group.members.begin(), group.members.end(), t3) != group.members.end()) {
                        int size = static_cast<int>(group.members.size());
                        auto it = find(group.members.begin(), group.members.end(), t3);
                        t2 = u;
                        group.members.erase(it);
                        if (size > static_cast<int>(group.members.size())) { system("cls"); cout << "�ɹ��˳�С��!!!" << endl; system("pause"); }
                    }
                }
            }
        }
        if (t1.getname().empty()) { cout << "û���ҵ���С��!!" << endl; }
        if (!t1.getname().empty() && t2.getusername().empty()) { cout << "û����С�����ҵ��ó�Ա!!" << endl; }
    }

    vector<Group*> get_user_groups(int id) {
        vector<Group*> user_groups;
        for (User& i : users) {
            if (i.getid() == id) {
                for (Group& j : groups) {
                    if (find(j.members.begin(), j.members.end(), &i) != j.members.end()) {
                        user_groups.push_back(&j);
                    }
                }
            }
        }
        return user_groups;
    }


    void rate_music(User& user) {
        string a,c; int b; Music t1; int totalrating = 0; int totaluser = 0;
        cout << "������Ҫ���۵ĸ�������:" << endl; getline(cin, a);
        cout << "������Ҫ���۵ĸ������ֵ�����:" << endl; getline(cin, c);//ͬʱ������ַ�ֹ���ָ�����������
        for (Music& m : musics) {
            if (m.getname() == a&&m.getsinger() == c) {
                t1 = m;
            }
        }
        if (t1.getname().empty() ||t1.getsinger().empty()) { cout << endl << "����û���ҵ����׸�" << endl; }
        else {
            cout << "����������(10����,��������):" << endl; cin >> b; cin.ignore();
            if (b >= 0 && b <= 10) {
                user.rateMusic1(t1.getname(), b); user.rateMusic2(t1.getname(), t1.getsinger());

                for (User& u : users) {
                    auto it = u.musicRatings.find(t1.getname());//����user��̬����,���������Ԫ�ص�������Ա���з��ϵĸ���,�Ҹ�����Ӧ�ĸ���һ��
                    if (it != u.musicRatings.end() && u.musicSingers[t1.getname()] == t1.getsinger()) {//find����Ѱ��ʧ�ܻ᷵��end(),��������it!=end()�ʹ����ҵ���
                        totalrating += it->second;//���ڸ�����,first�����,second����ֵ
                        totaluser++;
                    }
                }

                for (Music& m : musics) {
                    if (m.getname() == t1.getname() && m.getsinger() == t1.getsinger()) {
                        m.sendrating(totaluser > 0 ? ((totalrating + t1.getrating_default()) / (totaluser + 1)) : 0);//��ʵʱ���µ�rating���صĶ�Ӧ��music������
                    }
                }
            }
            else{
                cout << "error:������0��10������!!" << endl;
            }
        }
    }
    void sort_id() {
        int a; Music t;
        cout << "��������Ҹ�������:" << endl; cin.width(2); cin >> a; cin.sync();
        cout << endl << "��Ҫ���ҵĸ���:" << endl;
        for (Music& m : musics) {
            if (m.getid() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "����û���ҵ����׸�" << endl; }
    }

    void sort_type() {
        string a; Music t;
        cout << "��������Ҹ�������:" << endl; getline(cin, a);
        cout << endl << "��Ҫ���ҵĸ���:" << endl;
        for (Music& m : musics) {
            if (m.gettype() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "����û���ҵ����׸�" << endl; }
    }
    

    void sort_name() {
        string a; Music t;
        cout << "��������Ҹ�������:" << endl; getline(cin, a);
        cout << endl << "��Ҫ���ҵĸ���:" << endl;
        for (Music& m : musics) {
            if (m.getname() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "����û���ҵ����׸�" << endl;  }
    }

    void sort_singer() {
        string a; Music t;
        cout << "��������Ҹ�������:" << endl; getline(cin, a);
        cout <<endl<< "��Ҫ���ҵĸ���:" << endl;
        for (Music& m : musics) {
            if (m.getsinger() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "����û���ҵ����׸�" << endl;  }
    }

    void show_all_users() {
        if (users.empty()) {
            cout << "���ϧ.��ô�õ�ƽ̨��ôһ����û��!" << endl;
        }
        else {
            cout << "�û��б�:" << endl;
            for (User& u : users) {
                u.display();
            }
        }
    }

    bool samename(string a) {//�ж���������
        for (User& i : users) {
            if (a != i.getusername()) {
                return true;
            }
            else {
                return false;
            }
        }
        return true;
    }

    bool judge_rating_exist() {//�ж��Ƿ�ɹ�������ֺ���
        for (User& i : users) {
            for (Music& j : musics) {
                if (i.musicRatings.empty() && j.getrating() == 0) {
                    return false;
                }
                else { return true; }
            }
        }
        return false;
    }

    bool judge_group_member(int id) {
        for (User& i : users) {
            if (i.getid() == id) {
                for (Group& j : groups) {
                    if (find(j.members.begin(), j.members.end(), &i) != j.members.end()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }


    void random_generate_user(int id) {
        string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; string username;
        random_device rd;
        mt19937 gen(rd());//÷ɭ��ת�㷨
        uniform_int_distribution<> a(0, static_cast<int>(str.size() - 1));
        uniform_int_distribution<> b(3, 10);
        int length = b(gen);
        for (int i = 0; i < length; ++i) {
            username += str[a(gen)];
        }
        users.emplace_back(id, username);
    }
    void random_generate_song(int id) {
        random_device rd;
        mt19937 gen(rd());
        vector<string>songs = { "ÿ�찮���һЩ","�µ�����ʹ","������","���","ǧǧ�ڸ�","���˻�","˭���Ҵ���","˭��������","�ټ�����","�µ���Ӱ","����ӵ��" };
        vector<string>singers = { "��ѧ��","����Ѹ","����","�ܻ���","���»�","����","������","����","�»��","������","Beyond","����" };
        vector<string>types = { "����","ҡ��","��ʿ","���","����","����","���","R&B" };
        uniform_int_distribution<> c(0, static_cast<int>(songs.size() - 1));
        uniform_int_distribution<> d(0, static_cast<int>(singers.size() - 1));
        uniform_int_distribution<> e(0, static_cast<int>(types.size() - 1));
        string randomsongs = songs[c(gen)];
        string randomsingers = singers[d(gen)];
        string randomtypes = types[e(gen)];
        musics.emplace_back(randomsongs, randomsingers, randomtypes, id);
    }
    void random_generate_group(int id){
        random_device rd;
        mt19937 gen(rd());
        vector<string>types_group= { "���������ܲ�","ҡ�������ܲ�","��ʿ�����ܲ�","��������ܲ�","���������ܲ�","���������ܲ�","��������ܲ�","R&B�����ܲ�" };
        uniform_int_distribution<> f(0, static_cast<int>(types_group.size() - 1));
        string randomtypes_group = types_group[f(gen)];
        string introduction = "ϲ���������ֵĿ��Լ���С��һ�������!!!";
        groups.emplace_back(randomtypes_group, introduction, id);
    }

    void rate_music_random(User& user,Music& music) {
        int totalrating = 0; int totaluser = 0;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> a(0, 10);
        int randomrating = a(gen);
        user.rateMusic1(music.getname(), randomrating); user.rateMusic2(music.getname(), music.getsinger());
         for (User& u : users) {
              auto it = u.musicRatings.find(music.getname());
              if (it != u.musicRatings.end() && u.musicSingers[music.getname()] == music.getsinger()) {
                   totalrating += it->second;
                   totaluser++;
              }
         }
         for (Music& m : musics) {
              if (m.getname() == music.getname() && m.getsinger() == music.getsinger()) {
                   m.sendrating(totaluser > 0 ? ((totalrating + music.getrating_default()) / (totaluser + 1)) : 0);
              }
         } 
    }

    void random_grouping(User& user,Group& group) {
        group.add_user(&user);
    }
    
};




