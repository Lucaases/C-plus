#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <iomanip>
#include <unordered_map>
#include "random1.h"

using namespace std;

typedef class timescale {
public:
	string time{};
	int count{};
	int user_id{};
	timescale(string a, int b, int c):time(a),user_id(b), count(c){}
	timescale(){}
	~timescale(){}
}t;

typedef class court {
public:
	int court_id{};
	string court_name{};
	vector<timescale> times;
	//vector<int> user_id;
	int expense_per_hour{};
	int total_booked_hour{};
	int total_income{};
	court(int a, string b, int c,  int e, vector<timescale> t) :court_id(a), court_name(b), expense_per_hour(c), total_booked_hour(e), total_income(0), times(t){}
	court(int a, string b, int c,  int e, int f) :court_id(a), court_name(b), expense_per_hour(c), total_booked_hour(e), total_income(f) {}
	court(){}
	~court(){}

	void show_info() {
		cout << "体育场馆编号:" << court_id << endl;
		cout << "体育场馆名称:" << court_name << endl;
		cout << "体育场馆1小时费用:" << expense_per_hour << endl;
		cout << "体育场馆总预约时数:" << total_booked_hour << endl;
	}

	void show_info_admin_only() {
		cout << "-----------------------------------------" << endl;
		cout << "体育场馆编号:" << court_id << endl;
		cout << "体育场馆名称:" << court_name << endl;
		cout << "体育场馆总预约时数:" << total_booked_hour << endl;
		cout << "体育场馆总收入:" << total_income << endl;
	}

	bool operator==(const int& courtid) { return this->court_id = courtid; }
	//C2665错误,algorithm中的find函数第三个形参必须是一数据(即int,char,string...),不能是抽象的类对象,通过重载==符号使其指向对象中的成员

}c;

typedef class user {
private:
	int user_id{};
	string user_name{};
	string user_password{};
	int user_balance_primary{};
	int user_balance{};
	//vector<court> user_courts;
	//unordered_multimap<int, int> usercourts1;
	//unordered_map<int, int> usercourts;
	unordered_map<int, vector<court>> usercourts2;//一个用户可以在预约多个球场,但每个球场只能预约一个时段
	
public:
	user(int a,string b,string c,int d):user_id(a),user_name(b),user_password(c),user_balance_primary(d), user_balance(d){}
	user(){}
	~user(){}
	int getuser_balance(){return user_balance;}
	int getuser_id() { return user_id; }
	string getuser_name() { return user_name; }
	string getuser_password() { return user_password; }
	void setuser_balance(int a) { user_balance = a; }
	unordered_map<int, vector<court>> getusercourts2() { return usercourts2; }
	//void add_user_courts(court& a) { user_courts.emplace_back(a); }
	//void add_usercourts(int key, int value) { usercourts[key] = value; }
	//void erase_usercourts(int key) { usercourts.erase(key); }
	//void add_usercourts1(int key, int value) {usercourts1.insert(pair<int, int>(key, value));}
	//void add_usercourts2(int key, int value) { usercourts2[key].emplace_back(value); }//key=user_id,value=court_id 
	//void erase_usercourts2(int key) { usercourts2.erase(key); }
	//void delete_usercourts2(int key, int court_id) {
		//for (int s : usercourts2[key]) {
			//if (s == court_id) {
			//	usercourts2[key].erase(find(usercourts2[key].begin(), usercourts2[key].end(), s));
		//	}
	//	}
//	}
	//void list_usercourt2(int key){

//	}
	void add_usercourts2(int key, court& value) { 
		usercourts2[key].emplace_back(value);
	}
	void erase_usercourts2(int key) { usercourts2.erase(key); }
	void delete_usercourts2(int key, court& value) {
		if (!usercourts2[key].empty()) {
		size_t d = usercourts2[key].size();
		usercourts2[key].erase(find(usercourts2[key].begin(), usercourts2[key].end(), value.court_id));
		if (usercourts2[key].size() < d) {cout << "删除成功" << endl; }
		else { cout << "删除失败" << endl; }
		}
		else{cout<<"你还没有预约任何场馆"<<endl;}
	}
	void list_specfic_usercourts2(int key, court& value) {
		if (!usercourts2[key].empty()) {
			for (court& s : usercourts2[key]) {
				if (s.court_id == value.court_id) {
					s.show_info();
					for (timescale& t : s.times) {
						if (t.user_id == key&&t.count==1) {
							cout << "预约的时间段为:" << t.time << endl;
						}
					}
				}
			}
		}
		else { cout << "未预约任何场馆" << endl; }
	}

	void list_all_usercourts2(int key) {
		if (!usercourts2[key].empty()) {
			for (court& s : usercourts2[key]) {
				cout << "----------------------------------" << endl;
				s.show_info();
				for (timescale& t : s.times) {
					if (t.user_id == key && t.count == 1) {
						cout << "预约的时间段为:" << t.time << endl;
					}
				}
			}
		}
		else { cout << "未预约任何场馆" << endl; }
	}

	void fout_list_all_usercourts2(int key,ofstream& fout) {
		if (!usercourts2.empty()) {
			for (court& s : usercourts2[key]) {
				fout << "体育场馆编号:" << s.court_id << endl;
				fout << "体育场馆名字:" << s.court_name << endl;
				for (timescale& t : s.times) {
					if (t.user_id == key) {
						fout << "预约时间段为:  " << left << setw(13) << t.time << endl;
					}
				}
			}
		}
		else { fout << "未预约任何体育场馆!!" << endl; }
}

}u;

class platform {
private:
	vector<user> users;
	vector<court> courts;
public:
	vector<user> getusers() { return users; }

	void register1(int& userid) {//注册用户,由add_user进化而来
		size_t d = users.size(); int userid1 = userid++;
		while (1) {
			int count = 0;
			string a, b; int c; 
			cout << "请输入你的用户名(3-10个字母,不含空格)" << endl; getline(cin, a); if (a == "q" || a == "Q") { userid--; break; }
			if (find(a.begin(), a.end(), ' ') == a.end() && a.length() >= 3 && a.length() <= 10) {
					for (u& s : users) {
						if (s.getuser_name() == a) {
							count++;
							cout << "该用户名已被注册,请重新输入!" << endl;
							break;
						}
					}
					if (count >= 1) { continue; }
					cout << "请输入你的密码(8-16个字母,不含空格)" << endl; getline(cin, b); if (b == "q" || b == "Q") { userid--; break; }
				if (find(b.begin(), b.end(), ' ') == b.end() && b.length() >= 8 && b.length() <= 16) {
				cout << "请输入你的初始体育经费(不超过1000)" << endl; cin >> c; cin.ignore();
				if (c >= 0 && c <= 1000) {
					users.emplace_back(userid1, a, b, c);
					if (users.size() > d) { 
						cout << "注册成功" << endl; system("pause"); system("cls"); 
						while (1) {
							menu();
							cout << "请输入你的选择:" << endl; char e = _getch();
							switch (e) {
							case '1': {system("cls"); book(userid1); system("cls"); continue; }
							case '2': {system("cls"); cancel(userid1); system("cls"); continue; }
							case '3': {system("cls"); cancel_all(userid1); system("pause"); system("cls"); continue; }
							case '4': {system("cls"); show_booking_condition(); system("cls"); continue; }
							case '5': {system("cls"); recharge(userid1); system("cls"); continue; }
							case '6': {system("cls"); check_user_info(userid1); system("cls"); continue; }
							case '7': {system("cls"); search(); system("cls"); continue; }
							case 'Q':
							case 'q':
							case '8': {system("cls"); break; }
							case '9': {system("cls"); random_book(userid1); continue; }
							default: {cout << "请输入正确的值" << endl; }
							}
							break;
						}
						break;
					}
					else { cout << "注册失败" << endl; system("pause"); userid--; break; }
				}
				else { cout << "请输入正确的初始体育经费值!!" << endl; continue; }
			}
			else { cout << "密码不符合要求,请重新输入!!" << endl; continue; }
		}
			else { cout << "用户名不符合要求,请重新输入!!" << endl; continue;}
	}
		
}

	void add_court(int& courtid) {//加入体育场馆,未测试,可能存在Bug
		size_t d = courts.size();
		while (1) {
			string a; int b; 
			cout << "请输入体育场馆名称"; getline(cin, a);if(a=="q"||a=="Q"){courtid-=1; break;}
			cout << "请输入体育场馆收费(1小时)"; cin >> b; cin.sync();
			if (!a.empty() && a.length() <= 7 && b > 0) {
				courts.emplace_back(courtid, a, b, 0, 0);
				break;
			}
			else { cout << "请输入正确的值!!" << endl; continue; }
		}
		if (courts.size() > d) {
			cout << "请继续输入体育场馆的开放时间段" << endl;
			cout << "请输入体育场馆开放时间段的数量(至少3个)"; int n; cin >> n; cin.sync();
			if (n >= 3) {
				for (int i = 0; i < n; i++) {
					string e;
					cout << "请输入体育场馆开放时间段(例8:00-9:00)(间隔为1小时)"; getline(cin, e);
					if (e.empty() || (e.find("-") == e.npos && e.find(":") == e.npos)) { cout << "输入错误" << endl; i--; continue; }
					courts[d].times.emplace_back(e, 0, 0);
				}
				if (courts[d].times.size() == n) { cout << "添加成功" << endl; }
				else { cout << "添加失败:code 03" << endl; }
			}
			else { cout << "输入n的值不正确!添加失败:code 02" << endl; }
		}
		else { cout << "添加失败:code 01" << endl; }
	}

	void book(int userid) {//预约
		if (courts.empty()) { cout << "当前没有体育场馆可供预约" << endl; }
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					while (1) {
						if (s.getuser_id() > 0 && static_cast<unsigned long int>(s.getuser_id()) <= users.size()) {
							cout << "请输入你要预定的场馆编号(输入0返回)" << endl; int a; cin >> a; cin.sync(); if (a == 0) { break; }
							if (a > 0 && static_cast<unsigned long int>(a) <= courts.size()) {
								if (full_book(a)) { cout << "当前场馆已经约满!!" << endl; }
								else {
									cout << "请输入你要预定的时间段" << endl; string b; getline(cin, b);
									for (c& f : courts) {
										if (f.court_id == a) {
											for (timescale& t_time : f.times) {
												if (t_time.time == b) {
													if (t_time.count == 0) {
														if (s.getuser_balance() >= f.expense_per_hour) {
															f.total_booked_hour += 1;
															f.total_income += f.expense_per_hour;
															//t.add_user_courts(s);
															//t.add_usercourts(t.getuser_id(), s.court_id);
															t_time.count = 1;
															s.setuser_balance(s.getuser_balance() - f.expense_per_hour);
															t_time.user_id = s.getuser_id();
															s.add_usercourts2(s.getuser_id(), f);
															cout << "预定成功" << endl; break;
														}
														else { cout << "余额不足" << endl; break; }
													}
													else { cout << "当前该场地已被预约" << endl; break; }
												}
												else { cout << "请输入正确的时间段" << endl; break; }
											}
											break;
										}
									}
									break;
								}
							}
							else { cout << "请输入正确的值" << endl; continue; }
						}
						else { cout << "用户编号不正确" << endl; break; }
					}
					break;
				}
			}
		}
	}

	void random_book(int userid) {//随机预约
		int count = 0;
		if(courts.empty()){cout<<"当前没有任何体育场馆"<<endl; system("pause"); }
		else if (count >= 10) { cout << "已达到最大随机预约次数!!" << endl; }
		else {
			count++;
			random_device rd;
			mt19937 gen(rd());
			size_t courtssize = courts.size();
			distinct_uniform_int_distribution<size_t> x(0, courtssize - 1);
			size_t a = x(gen); size_t timessize = courts[a].times.size(); distinct_uniform_int_distribution<size_t> y(0, timessize - 1); size_t b = y(gen);
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					if (s.getuser_id() > 0 && static_cast<unsigned long int>(s.getuser_id()) <= users.size()) {
						if (full_book(static_cast<unsigned long int>(a))) { cout << "当前场馆已经约满!!" << endl; }
						else {
							while (1) {
								if (courts[a].times[b].count == 0) {
									courts[a].total_booked_hour += 1;
									courts[a].total_income += courts[a].expense_per_hour;
									s.setuser_balance(s.getuser_balance() - courts[a].expense_per_hour);
									courts[a].times[b].count = 1;
									courts[a].times[b].user_id = s.getuser_id();
									s.add_usercourts2(s.getuser_id(), courts[a]);
									if (courts[a].times[b].user_id != 0&& courts[a].times[b].count == 1) { cout << "预定成功" << endl; system("pause"); system("cls"); break; }
									else { cout << "预定失败" << endl; system("pause"); system("cls"); break; }
								}
								else { continue; }
							}
							break;
						}
					}
					else { cout << "用户编号不正确" << endl; break; }
				}
			}

		}
	}

	void cancel(int userid) {//取消预约
		int count = 0;
		if (users.empty() || courts.empty()) { cout << "当前没有用户或当前没有体育场馆可供预约" << endl; }
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					count++;
					while (1) {
							cout << "请输入你要取消预定的场馆编号" << endl; int a; cin >> a; cin.ignore(); if (a == 0) { break; }
							if (a > 0 && static_cast<unsigned long int>(a) <= courts.size()) {
								cout << "请输入你要取消预定的时间段" << endl; string b; getline(cin, b);
								if (!b.empty() && b.find("-") != b.npos && b.find(":") != b.npos && b.find(" ")==b.npos) {
									for (c& f : courts) {
										if (f.court_id == a) {
											for (timescale& t_time : f.times) {
												if (t_time.time == b) {
													if (t_time.count == 1) {
														f.total_booked_hour -= 1;
														f.total_income -= f.expense_per_hour;
														s.setuser_balance(s.getuser_balance() + f.expense_per_hour);
														t_time.count = 0;
														t_time.user_id = 0;
														s.delete_usercourts2(s.getuser_id(), f);
														cout << "取消成功" << endl; system("pause"); break;
													}
													else { cout << "你没有预定该时间段" << endl; system("pause"); break; }
												}
											}
											break;
										}
									}
									break;
								}
								else{ cout << "请输入正确的值" << endl; continue; }
							}
							else { cout << "请输入正确的值" << endl; continue; }
					}
				}
			}
			if (count == 0) { cout << "用户编号不存在" << endl; system("pause");}
		}
	}

	void cancel_all(int userid){//一键取消所有预约
		if (users.empty() || courts.empty()) { cout << "当前没有用户或当前没有体育场馆可供预约" << endl; }
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid && !s.getusercourts2().empty()) {
					s.erase_usercourts2(userid);
					for (c& f : courts) {
						for(timescale& t_time:f.times){
							if(t_time.user_id==s.getuser_id()){
								f.total_booked_hour -= 1;
								f.total_income -= f.expense_per_hour;
								s.setuser_balance(s.getuser_balance() + f.expense_per_hour);
								t_time.count = 0;
								t_time.user_id = 0;
								cout << "一键取消成功" << endl;
							}
						}
					}
				}
			}
		}
	}

	void search() {//搜寻体育场馆预约信息
		if(courts.empty()){cout << "当前没有任何用户" << endl; system("pause");}
		else{
		cout << "请输入你要查询的场馆编号" << endl; int a; cin >> a; cin.ignore();
		if (a > 0 && static_cast<unsigned long int>(a) <= courts.size()) {
			cout << "请输入你要查询的时间段(请先查询场馆信息查看)" << endl; string b; getline(cin, b); t time1;
			if (!b.empty() && b.length() <= 11 && find(b.begin(), b.end(), '-') == b.end()&& find(b.begin(), b.end(), ':') == b.end()) {
				for (c& s : courts) {
					if (s.court_id == a) {
						for (timescale& t_time : s.times) {
							if (t_time.time == b) {
								time1 = t_time;
								if (t_time.count == 1) { cout << "该时间段已被预定" << endl; }
								else { cout << "该时间段未被预定" << endl; }
							}
						}
						if (time1.time.empty()) { cout << "没有找到该时间段" << endl; }
						system("pause");
					}
				}
			}
			else{ cout << "请输入正确的时间段(例如9:00-10:00,间隔都为1小时)" << endl; }
		}
		}

	}

	void recharge(int userid) {//充值体育经费
		if (users.empty()) { cout << "当前没有任何用户" << endl; system("pause");}
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					if (s.getuser_id() == userid && static_cast<unsigned long int>(s.getuser_id()) <= users.size()) {
						cout << "请输入你要充值的金额" << endl; int a; cin >> a; cin.sync();
						if ((s.getuser_balance() + a) > 1000) { cout << "充值失败,充值后金额不能超过1000" << endl; system("pause"); continue; }
						else {
							s.setuser_balance(s.getuser_balance() + a);
							cout << "充值成功" << endl;
							system("pause"); break;
						}
					}
					else { cout << "请输入正确的值" << endl; system("pause"); continue; }
				}
			}

		}
	}

void check_user_info(int userid) {
	if (users.empty()) { cout << "当前没有任何用户" << endl; }
	else {
		u t;
		for (u& s : users) {
			if (s.getuser_id() == userid) {
				t = s; break;
			}
		}
		if (t.getuser_id() > 0 && static_cast<unsigned long int>(t.getuser_id()) <= users.size()) {
			cout << "你的用户编号为:" << t.getuser_id() << endl;
			cout << "你的用户名为:" << t.getuser_name() << endl;
			cout << "你的用户密码为:" << t.getuser_password() << endl;
			cout << "你的用户余额为:" << t.getuser_balance() << endl;
			t.list_all_usercourts2(t.getuser_id());
			system("pause");
		}
		else { cout << "用户编号存在问题!" << endl; system("pause");}
	}
}

void check_user_info_admin() {
	if (users.empty()) { cout << "当前没有任何用户" << endl; system("pause");}
	else {
		for (u& s : users) {
			cout << "用户编号为:" << s.getuser_id() << endl;
			cout << "用户名为:" << s.getuser_name() << endl;
			cout << "用户密码为:" << s.getuser_password() << endl;
			cout << "用户余额为:" << s.getuser_balance() << endl;
			s.list_all_usercourts2(s.getuser_id());
			cout << "----------------------------------------" << endl;
		}
		system("pause");
	}
}

void menu() {
	cout << "欢迎来到深圳大学体育场馆预约系统" << endl << endl;
	cout << "1.预约体育场馆" << endl;
	cout << "2.取消预约" << endl;
	cout << "3.一键取消所有预约" << endl;
	cout << "4.查询体育场馆预约情况" << endl;
	cout << "5.充值" << endl;
	cout << "6.查看用户信息" << endl;
	cout << "7.搜索体育场馆预约信息" << endl;
	cout << "8.退出系统(按7,q/Q都可以)" << endl;
	cout << "9.随机预约体育场馆" << endl;
}

void welcome_page() {
	cout << "欢迎来到深圳大学体育场馆预约系统" << endl << endl;
	cout << "1.登录" << endl;
	cout << "2.注册用户" << endl;
	cout << "3.忘记密码" << endl;
	cout << "4.管理员系统" << endl;
	cout << "5.退出系统(按5,q/Q都可以)" << endl;
}

void admin_page() {
	cout << "欢迎来到管理员系统" << endl << endl;
	cout << "1.查看体育场馆预约情况" << endl;
	cout << "2.查看体育场馆信息" << endl;
	cout << "3.查看所有用户信息" << endl;
	cout << "4.保存用户及体育场馆信息到文件" << endl;
	cout << "5.添加体育场馆" << endl;
	cout << "6.随机生成用户和体育场馆(只能生成一次,防止生成太多导致程序崩溃)" << endl;
	cout << "7.退出系统(按6,q/Q都可以)" << endl;
}

void admin_page1() {
	cout << "欢迎来到管理员系统" << endl << endl;
	cout << "1.查看体育场馆预约情况" << endl;
	cout << "2.查看体育场馆信息" << endl;
	cout << "3.查看所有用户信息" << endl;
	cout << "4.保存用户及体育场馆信息到文件" << endl;
	cout << "5.添加体育场馆" << endl;
	cout << "6.退出系统(按6,q/Q都可以)" << endl;
}

void show_booking_condition() {//查看体育场馆预约状况
	if(courts.empty()){cout<<"当前没有任何体育场馆"<<endl; system("pause");
	}
	else {
		for (c& s : courts) {
			s.show_info_admin_only();
			for (timescale& t : s.times) {
				if (t.count == 0) {
					cout << left << setw(12) << t.time << "    " << "未预定" << endl;
				}
				else if (t.count == 1) {
					for (u& s1 : users) { if (s1.getuser_id() == t.user_id) { cout << left << setw(12) << t.time << "    " << "用户"<<s1.getuser_name()<<"已预定" << endl; } }
				}
				else { cerr << "Error!!" << endl; }
			}
			cout<<"----------------------------------------"<<endl;
		}
		system("pause");
	}
}

void random_generate_user(int userid) {//随机生成用户
	random_device rd;
	mt19937 gen(rd());
	string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; string username;string password;
	uniform_int_distribution<> a(0, static_cast<unsigned long int>(str.size() - 1));
	uniform_int_distribution<> b(3, 10); int length = b(gen);
	uniform_int_distribution<> c(8, 16); int length1= c(gen);
	uniform_int_distribution<> d(0, 1000); 
	for (int i = 0; i < length; i++) {
		username += str[a(gen)];
	}
	for(int i=0; i < length1; i++){
		password += str[a(gen)];
	}
	users.emplace_back(userid, username, password, d(gen));
}

void random_generate_court(int courtid) {//随机生成体育场馆
	random_device rd;
	mt19937 gen(rd());
	string court1[10] = { "篮球场","足球场","羽毛球场","乒乓球场","网球场","排球场","棒球场","高尔夫球场","保龄球场","滑冰场" };
	uniform_int_distribution<> a(0, 9);
	uniform_int_distribution<> b(20, 100);
	vector<timescale> t;									
	for (int i = 0; i < 12; i++) {//默认开放时间为8:00-22:00,每个时间段为1小时
		string str = to_string(8 + i) + ":00-" + to_string(9 + i) + ":00";
		t.emplace_back(str, 0, 0);
	}
	courts.emplace_back(courtid, court1[a(gen)], b(gen), 0, t);
}

void password_forget(string username) {//找回密码
		if (username.length() >= 3 && username.length() <= 10) {
			u t;
			for (u& s : users) {
				if (s.getuser_name() == username) {
					t = s;
				}
			}
			if (!t.getuser_password().empty()) {
				cout << "你的密码为:" << t.getuser_password() << endl; system("pause");
			}
			else { cout << "未找到该用户!!" << endl; system("pause"); }
		}
		else { cout << "请输入正确的用户名" << endl; system("pause"); }
	
}

void save_data() {//文件保存
	if (users.empty() || courts.empty()) { cout << "当前没有用户或当前没有体育场馆可供预约" << endl; system("pause"); }
	else {
		ofstream fout("users.txt");
		for (u& s : users) {
			fout << "------------------------------------------" << endl;
			fout << "用户编号:" << s.getuser_id() << endl << "用户名:" << s.getuser_name() << endl << "用户密码:" << s.getuser_password() << endl << "用户余额:" << s.getuser_balance() << endl;
			fout<<"用户预约的场馆信息:"<<endl;
			s.fout_list_all_usercourts2(s.getuser_id(),fout);
		}
		if (!fout.fail()) { cout << "用户文件写入成功!" << endl << endl; }
		fout.close();
		ofstream fout1("courts.txt");
		for (c& s : courts) {
			fout1 << "------------------------------------------" <<endl;
			fout1 << "体育场馆编号:" << s.court_id << endl << "体育场馆名称:" << s.court_name << endl << "体育场馆一小时费用:" << s.expense_per_hour << endl << "体育场馆总预约时长:" << s.total_booked_hour << endl << "体育场馆总收入:" << s.total_income << endl;
			for (timescale& t : s.times) {
				if (t.count == 1) { fout1 << left << setw(13) << t.time<<"    "<<"已被用户编号为"<<t.user_id<<"的用户预约!"<<endl; }
				else if (t.count == 0) { fout1 << left << setw(13) << t.time << "    " << "未被预约" << endl; }
				else { cerr << "Error!!" << endl; }
			}
		}
		if (!fout1.fail()) { cout << "体育场馆文件写入成功!" << endl; }
		fout1.close();
		system("pause");
	}
}

void login() {//用户登录
	while (1) {
		system("cls"); int count=0;
		if (users.empty()) { cout << "当前没有任何用户" << endl; system("pause"); break; }
		cout << "请输入你的用户名(输入q/Q返回菜单):" << endl; string b; cin >> b; cin.sync(); if (b == "Q" || b == "q") {  break; }
		cout << "请输入你的密码(输入q/Q返回菜单):" << endl; string c;  cin >> c; cin.sync();  if (c == "Q" || c == "q") {  break; }
			for (u& s : users) {
				if (s.getuser_name() == b && s.getuser_password() == c) {
					system("cls"); count++;
					while (1) {
						menu();
						cout << "请输入你的选择:"; char d = _getch();
						switch (d) {
						case '1': {system("cls"); book(s.getuser_id()); system("cls"); continue; }
						case '2': {system("cls"); cancel(s.getuser_id()); system("cls"); continue; }
						case '3': {system("cls"); cancel_all(s.getuser_id()); system("pause"); system("cls"); continue; }
						case '4': {system("cls"); show_booking_condition(); system("cls"); continue; }
						case '5': {system("cls"); recharge(s.getuser_id()); system("cls"); continue; }
						case '6': {system("cls"); check_user_info(s.getuser_id()); system("cls"); continue; }
						case '7': {system("cls"); search(); system("cls"); continue; }
						case 'Q':
						case 'q':
						case '8': {cout << "退出登录" << endl; break; }
						case '9': {system("cls"); random_book(s.getuser_id()); continue; }
						default: {cout << "请输入正确的值" << endl; }
						}
						break;
					}
					break;
				}
			}
			if (count == 1) { break; }
			else if (count == 0) { cout << "用户名或密码错误!!" << endl; system("pause"); continue; }
		}
	}

void admin_login(int& courtid,int& userid,int& count,int& count1) {//管理员登录
	while (1) {
		system("cls");
		cout << "请输入管理员密码(输入q/Q返回菜单):"<<endl; string a; getline(cin, a);
		if (a == "114514") {
			while (1) {
				cin.sync();
				if (count + count1 < 2) {
					system("cls");
					admin_page();
					cout << "请输入你的选择:"; char d = _getch();
					switch (d) {
					case '1': {system("cls"); show_booking_condition(); continue; }
					case '2': {system("cls");
						if (!courts.empty()) {
							for (c& s : courts) { s.show_info_admin_only(); }system("pause"); continue;
						}
						else { cout << "当前没有任何体育场馆" << endl; system("pause"); continue; }
					}
					case '3': {system("cls"); check_user_info_admin(); continue; }
					case '4': {system("cls"); save_data(); continue; }
					case '5': {system("cls"); add_court(courtid); continue; }
					case '6': {
						while (1) {
							system("cls");
							cout<<"1.随机生成体育场馆"<<endl;
							cout << "2.随机生成用户" << endl;
							cout << "3.返回菜单(q/Q/3)" << endl;
							char a = _getch();
							if (a == '1' && count < 1) {
								system("cls");
								cout << "请输入想要随机生成的体育场馆数量(不超过10个)(输入0返回菜单)" << endl; int n; cin >> n; cin.sync(); size_t d = courts.size();
								if (n > 0 && n <= 10) {
									for (int i = 0; i < n; i++) {
										random_generate_court(courtid++);
									}
									if (courts.size() == (d + n)) { count++; cout << "体育场馆随机生成成功" << endl; system("pause"); cin.ignore(); continue; }
									else { cout << "体育场馆随机生成失败" << endl; system("pause"); continue; }
								}
								else if (n == 0) { system("cls"); continue; }
								else { cout << "请输入正确的值" << endl; system("pause"); continue; }
							}
							else if (a == '2' && count1 < 1) {
								system("cls");
								cout << "请输入想要随机生成的用户数量(不超过20个)(输入0返回菜单)" << endl; int m; cin >> m; cin.sync(); size_t f = users.size();
								if (m > 0 && m <= 20) {
									for (int i = 0; i < m; i++) {
										random_generate_user(userid++);
									}
									if (users.size() == (f + m)) { count1++; cout << "用户随机生成成功" << endl; system("pause"); cin.ignore(); continue; }
									else { cout << "用户随机生成失败" << endl;  system("pause"); continue; }
								}
								else if (m == 0) { system("cls"); continue; }
								else { cout << "请输入正确的值" << endl; system("pause"); continue; }
							}
							else if (a == '3' || a == 'q' || a == 'Q') { break; }
							else { cout << "输入值错误 或 生成用户次数超过规定 或 生成体育场馆次数超过规定" << endl; system("pause"); continue; }
					}
					continue;
				}
					case 'Q':
					case 'q':
					case '7': {break; }
					default: {cout << "请输入正确的值" << endl; system("pause"); continue; }
					}
				}
				else {
					system("cls");
					admin_page1();
					cout << "请输入你的选择:"; char d = _getch();
					switch (d) {
					case '1': {system("cls"); show_booking_condition(); continue; }
					case '2': {system("cls");
						if (!courts.empty()) {
							for (c& s : courts) { s.show_info_admin_only(); }system("pause"); continue;
						}
						else { cout << "当前没有任何体育场馆" << endl; system("pause"); continue; }
					}
					case '3': {system("cls"); check_user_info_admin(); continue; }
					case '4': {system("cls"); save_data(); continue; }
					case '5': {system("cls"); add_court(courtid); continue; }
					case 'Q':
					case 'q':
					case '6': {break; }
					default: {cout << "请输入正确的值" << endl; system("pause"); continue; }
					}
				}
				break;
			}
			break;
		}
		else if (a == "q" || a == "Q") { break; }
		else { cout << "密码错误,请重新输入" << endl; system("pause"); continue; }
	}
}

bool full_book(int courtid) {//判断当前场馆是否已经约满
	int a = 0; c t;
	for (c& s : courts) {
		if (s.court_id == courtid) {
			t = s;
			for (timescale& t1 : s.times) {
				if (t1.count == 1) {
					a += t1.count;
				}
			}
		}
	}
	if (a == t.times.size() ) { return true; }
	else{ return false; }
}

};

court operator>(court&a,court&b) {//重载运算符比较两个体育场馆的总预约时间
	if (a.total_booked_hour > b.total_booked_hour) {
		return a;
	}
	return b;
}
