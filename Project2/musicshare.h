#include <iostream>
#include <random>
#include <string>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>//使用动态数组
#include <unordered_map>//STL中的一个关联容器,支持快速的查找、插入和删除操作

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
        cout << left <<"歌曲编号:"<< left << setw(10) << id ;
        cout << left << "歌曲名称:"<< left << setw(20) << name ;
        cout << left  << "歌手:" << left << setw(10) << singer ;
        cout << left << "类型:" << left << setw(10) << type ;
        cout << left  << "平台初始评分:" << right <<setw(2)<< rating_default<< "/10分";
        if (rating != 0) {
            cout << "      " << "综合评分:" << right << rating << "/10分" << endl;
        }
        else {
            cout << "      " <<"暂时还没有评分"<< endl;
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
        cout << "用户编号" << left << setw(10) << id  ;
        cout << "用户名" << left << setw(10) << username<<endl;
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

    void add_user(User* user) {//向小组添加成员
        members.push_back(user);
    }

    void show_Members_Ratings() {
        if (members.empty()) {
            cout << endl << "小组中空空如也,期待你的加入" << endl<<endl;
        }
        else {
            for (User* user : members) {//遍历members
                cout << "用户编号" << left << setw(5) << user->getid() << "用户名:" << left << setw(10) << user->getusername();
                if (user->musicRatings.empty()) {
                    cout << "用户没有参与过歌曲评分" << endl;
                }
                else {
                    cout<< "该用户评分:" << endl<<endl;
                    for (auto rating : user->musicRatings) {
                        cout << left<<setw(20)<< rating.first << ": " << rating.second <<"分" << endl;//输出键值对
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
        cout << "请输入要加入的歌名:" << endl; getline(cin, a);
        cout << "请输入歌手名称:" << endl; getline(cin, b); 
        cout << "请输入歌的类型:" << endl; getline(cin, c);
        musics.emplace_back(a, b, c, id);
    }

    void add_newuser(int id,string a) {
            users.emplace_back(id, a);
    }

    void create_newgroup(int id, User& user) {
        string a, b;
        cout << "请输入要创建的小组名称:" << endl; getline(cin, a);
        cout << "请输入小组简介:" << endl; getline(cin, b);
        groups.emplace_back(a, b, id);
        for (Group& group : groups) {
            if (group.getname() == a) { group.add_user(&user); }
        }
    }

    void show_All_songs() {
        if (musics.empty()) {
            cout << endl << "库中没有音乐" << endl;
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
                cout<<"小组编号:"<<left<<setw(2)<<group.getid()<<endl<< "小组名称: " << group.getname() << endl << "小组简介: " << left <<setw(20)<<group.getintroduction() << endl;
                group.show_Members_Ratings();
            }    
    }

    void join_group(int a,User& user) {
        Group t;
        for (Group& group : groups) {
            int b = static_cast<int>(group.members.size());
            if (group.getid() == a) { t = group; group.add_user(&user); }
            if (group.members.size() > b) {
                cout << endl << "成功加入小组,恭喜!!" << endl;
            }
        }
        if (t.getname().empty()) { cout << "没有找到这个小组,请重试" << endl; }
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
                        if (size > static_cast<int>(group.members.size())) { system("cls"); cout << "成功退出小组!!!" << endl; system("pause");}
                    }
                }
            }
        }
        if (t1.getname().empty()) { cout << "没有找到该小组!!" << endl; }
        if (!t1.getname().empty()&&t2.getusername().empty()) { cout << "没有在小组中找到该成员!!" << endl; }
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
                        if (size > static_cast<int>(group.members.size())) { system("cls"); cout << "成功退出小组!!!" << endl; system("pause"); }
                    }
                }
            }
        }
        if (t1.getname().empty()) { cout << "没有找到该小组!!" << endl; }
        if (!t1.getname().empty() && t2.getusername().empty()) { cout << "没有在小组中找到该成员!!" << endl; }
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
        cout << "请输入要评价的歌曲名称:" << endl; getline(cin, a);
        cout << "请输入要评价的歌曲歌手的名字:" << endl; getline(cin, c);//同时输入歌手防止出现歌曲重名现象
        for (Music& m : musics) {
            if (m.getname() == a&&m.getsinger() == c) {
                t1 = m;
            }
        }
        if (t1.getname().empty() ||t1.getsinger().empty()) { cout << endl << "库中没有找到这首歌" << endl; }
        else {
            cout << "请输入评分(10分制,请输整数):" << endl; cin >> b; cin.ignore();
            if (b >= 0 && b <= 10) {
                user.rateMusic1(t1.getname(), b); user.rateMusic2(t1.getname(), t1.getsinger());

                for (User& u : users) {
                    auto it = u.musicRatings.find(t1.getname());//遍历user动态数组,如果当中有元素的容器成员中有符合的歌名,且歌名对应的歌手一致
                    if (it != u.musicRatings.end() && u.musicSingers[t1.getname()] == t1.getsinger()) {//find函数寻找失败会返回end(),所以这里it!=end()就代表找到了
                        totalrating += it->second;//对于该容器,first代表键,second代表值
                        totaluser++;
                    }
                }

                for (Music& m : musics) {
                    if (m.getname() == t1.getname() && m.getsinger() == t1.getsinger()) {
                        m.sendrating(totaluser > 0 ? ((totalrating + t1.getrating_default()) / (totaluser + 1)) : 0);//将实时更新的rating返回的对应的music对象中
                    }
                }
            }
            else{
                cout << "error:请输入0到10的整数!!" << endl;
            }
        }
    }
    void sort_id() {
        int a; Music t;
        cout << "请输入查找歌曲类型:" << endl; cin.width(2); cin >> a; cin.sync();
        cout << endl << "所要查找的歌曲:" << endl;
        for (Music& m : musics) {
            if (m.getid() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "库中没有找到这首歌" << endl; }
    }

    void sort_type() {
        string a; Music t;
        cout << "请输入查找歌曲类型:" << endl; getline(cin, a);
        cout << endl << "所要查找的歌曲:" << endl;
        for (Music& m : musics) {
            if (m.gettype() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "库中没有找到这首歌" << endl; }
    }
    

    void sort_name() {
        string a; Music t;
        cout << "请输入查找歌曲名称:" << endl; getline(cin, a);
        cout << endl << "所要查找的歌曲:" << endl;
        for (Music& m : musics) {
            if (m.getname() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "库中没有找到这首歌" << endl;  }
    }

    void sort_singer() {
        string a; Music t;
        cout << "请输入查找歌曲歌手:" << endl; getline(cin, a);
        cout <<endl<< "所要查找的歌曲:" << endl;
        for (Music& m : musics) {
            if (m.getsinger() == a) {
                t = m;
                m.display();
            }
        }
        if (t.getname().empty()) { cout << endl << "库中没有找到这首歌" << endl;  }
    }

    void show_all_users() {
        if (users.empty()) {
            cout << "真可惜.这么好的平台怎么一个人没有!" << endl;
        }
        else {
            cout << "用户列表:" << endl;
            for (User& u : users) {
                u.display();
            }
        }
    }

    bool samename(string a) {//判断重名函数
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

    bool judge_rating_exist() {//判断是否成功随机评分函数
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
        mt19937 gen(rd());//梅森旋转算法
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
        vector<string>songs = { "每天爱你多一些","孤单的心痛","李香兰","大哥","千千阙歌","流浪花","谁伴我闯荡","谁明浪子心","再见悲哀","孤单背影","曾是拥有" };
        vector<string>singers = { "张学友","陈奕迅","卫兰","周慧敏","刘德华","黎明","郭富城","吕方","陈慧娴","林忆莲","Beyond","王杰" };
        vector<string>types = { "流行","摇滚","爵士","乡村","经典","金属","民歌","R&B" };
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
        vector<string>types_group= { "流行音乐总部","摇滚音乐总部","爵士音乐总部","乡村音乐总部","经典音乐总部","金属音乐总部","民歌音乐总部","R&B音乐总部" };
        uniform_int_distribution<> f(0, static_cast<int>(types_group.size() - 1));
        string randomtypes_group = types_group[f(gen)];
        string introduction = "喜欢此类音乐的可以加入小组一起分享交流!!!";
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




