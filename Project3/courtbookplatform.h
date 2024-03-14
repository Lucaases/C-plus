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
		cout << "�������ݱ��:" << court_id << endl;
		cout << "������������:" << court_name << endl;
		cout << "��������1Сʱ����:" << expense_per_hour << endl;
		cout << "����������ԤԼʱ��:" << total_booked_hour << endl;
	}

	void show_info_admin_only() {
		cout << "-----------------------------------------" << endl;
		cout << "�������ݱ��:" << court_id << endl;
		cout << "������������:" << court_name << endl;
		cout << "����������ԤԼʱ��:" << total_booked_hour << endl;
		cout << "��������������:" << total_income << endl;
	}

	bool operator==(const int& courtid) { return this->court_id = courtid; }
	//C2665����,algorithm�е�find�����������βα�����һ����(��int,char,string...),�����ǳ���������,ͨ������==����ʹ��ָ������еĳ�Ա

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
	unordered_map<int, vector<court>> usercourts2;//һ���û�������ԤԼ�����,��ÿ����ֻ��ԤԼһ��ʱ��
	
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
		if (usercourts2[key].size() < d) {cout << "ɾ���ɹ�" << endl; }
		else { cout << "ɾ��ʧ��" << endl; }
		}
		else{cout<<"�㻹û��ԤԼ�κγ���"<<endl;}
	}
	void list_specfic_usercourts2(int key, court& value) {
		if (!usercourts2[key].empty()) {
			for (court& s : usercourts2[key]) {
				if (s.court_id == value.court_id) {
					s.show_info();
					for (timescale& t : s.times) {
						if (t.user_id == key&&t.count==1) {
							cout << "ԤԼ��ʱ���Ϊ:" << t.time << endl;
						}
					}
				}
			}
		}
		else { cout << "δԤԼ�κγ���" << endl; }
	}

	void list_all_usercourts2(int key) {
		if (!usercourts2[key].empty()) {
			for (court& s : usercourts2[key]) {
				cout << "----------------------------------" << endl;
				s.show_info();
				for (timescale& t : s.times) {
					if (t.user_id == key && t.count == 1) {
						cout << "ԤԼ��ʱ���Ϊ:" << t.time << endl;
					}
				}
			}
		}
		else { cout << "δԤԼ�κγ���" << endl; }
	}

	void fout_list_all_usercourts2(int key,ofstream& fout) {
		if (!usercourts2.empty()) {
			for (court& s : usercourts2[key]) {
				fout << "�������ݱ��:" << s.court_id << endl;
				fout << "������������:" << s.court_name << endl;
				for (timescale& t : s.times) {
					if (t.user_id == key) {
						fout << "ԤԼʱ���Ϊ:  " << left << setw(13) << t.time << endl;
					}
				}
			}
		}
		else { fout << "δԤԼ�κ���������!!" << endl; }
}

}u;

class platform {
private:
	vector<user> users;
	vector<court> courts;
public:
	vector<user> getusers() { return users; }

	void register1(int& userid) {//ע���û�,��add_user��������
		size_t d = users.size(); int userid1 = userid++;
		while (1) {
			int count = 0;
			string a, b; int c; 
			cout << "����������û���(3-10����ĸ,�����ո�)" << endl; getline(cin, a); if (a == "q" || a == "Q") { userid--; break; }
			if (find(a.begin(), a.end(), ' ') == a.end() && a.length() >= 3 && a.length() <= 10) {
					for (u& s : users) {
						if (s.getuser_name() == a) {
							count++;
							cout << "���û����ѱ�ע��,����������!" << endl;
							break;
						}
					}
					if (count >= 1) { continue; }
					cout << "�������������(8-16����ĸ,�����ո�)" << endl; getline(cin, b); if (b == "q" || b == "Q") { userid--; break; }
				if (find(b.begin(), b.end(), ' ') == b.end() && b.length() >= 8 && b.length() <= 16) {
				cout << "��������ĳ�ʼ��������(������1000)" << endl; cin >> c; cin.ignore();
				if (c >= 0 && c <= 1000) {
					users.emplace_back(userid1, a, b, c);
					if (users.size() > d) { 
						cout << "ע��ɹ�" << endl; system("pause"); system("cls"); 
						while (1) {
							menu();
							cout << "���������ѡ��:" << endl; char e = _getch();
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
							default: {cout << "��������ȷ��ֵ" << endl; }
							}
							break;
						}
						break;
					}
					else { cout << "ע��ʧ��" << endl; system("pause"); userid--; break; }
				}
				else { cout << "��������ȷ�ĳ�ʼ��������ֵ!!" << endl; continue; }
			}
			else { cout << "���벻����Ҫ��,����������!!" << endl; continue; }
		}
			else { cout << "�û���������Ҫ��,����������!!" << endl; continue;}
	}
		
}

	void add_court(int& courtid) {//������������,δ����,���ܴ���Bug
		size_t d = courts.size();
		while (1) {
			string a; int b; 
			cout << "������������������"; getline(cin, a);if(a=="q"||a=="Q"){courtid-=1; break;}
			cout << "���������������շ�(1Сʱ)"; cin >> b; cin.sync();
			if (!a.empty() && a.length() <= 7 && b > 0) {
				courts.emplace_back(courtid, a, b, 0, 0);
				break;
			}
			else { cout << "��������ȷ��ֵ!!" << endl; continue; }
		}
		if (courts.size() > d) {
			cout << "����������������ݵĿ���ʱ���" << endl;
			cout << "�������������ݿ���ʱ��ε�����(����3��)"; int n; cin >> n; cin.sync();
			if (n >= 3) {
				for (int i = 0; i < n; i++) {
					string e;
					cout << "�������������ݿ���ʱ���(��8:00-9:00)(���Ϊ1Сʱ)"; getline(cin, e);
					if (e.empty() || (e.find("-") == e.npos && e.find(":") == e.npos)) { cout << "�������" << endl; i--; continue; }
					courts[d].times.emplace_back(e, 0, 0);
				}
				if (courts[d].times.size() == n) { cout << "��ӳɹ�" << endl; }
				else { cout << "���ʧ��:code 03" << endl; }
			}
			else { cout << "����n��ֵ����ȷ!���ʧ��:code 02" << endl; }
		}
		else { cout << "���ʧ��:code 01" << endl; }
	}

	void book(int userid) {//ԤԼ
		if (courts.empty()) { cout << "��ǰû���������ݿɹ�ԤԼ" << endl; }
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					while (1) {
						if (s.getuser_id() > 0 && static_cast<unsigned long int>(s.getuser_id()) <= users.size()) {
							cout << "��������ҪԤ���ĳ��ݱ��(����0����)" << endl; int a; cin >> a; cin.sync(); if (a == 0) { break; }
							if (a > 0 && static_cast<unsigned long int>(a) <= courts.size()) {
								if (full_book(a)) { cout << "��ǰ�����Ѿ�Լ��!!" << endl; }
								else {
									cout << "��������ҪԤ����ʱ���" << endl; string b; getline(cin, b);
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
															cout << "Ԥ���ɹ�" << endl; break;
														}
														else { cout << "����" << endl; break; }
													}
													else { cout << "��ǰ�ó����ѱ�ԤԼ" << endl; break; }
												}
												else { cout << "��������ȷ��ʱ���" << endl; break; }
											}
											break;
										}
									}
									break;
								}
							}
							else { cout << "��������ȷ��ֵ" << endl; continue; }
						}
						else { cout << "�û���Ų���ȷ" << endl; break; }
					}
					break;
				}
			}
		}
	}

	void random_book(int userid) {//���ԤԼ
		int count = 0;
		if(courts.empty()){cout<<"��ǰû���κ���������"<<endl; system("pause"); }
		else if (count >= 10) { cout << "�Ѵﵽ������ԤԼ����!!" << endl; }
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
						if (full_book(static_cast<unsigned long int>(a))) { cout << "��ǰ�����Ѿ�Լ��!!" << endl; }
						else {
							while (1) {
								if (courts[a].times[b].count == 0) {
									courts[a].total_booked_hour += 1;
									courts[a].total_income += courts[a].expense_per_hour;
									s.setuser_balance(s.getuser_balance() - courts[a].expense_per_hour);
									courts[a].times[b].count = 1;
									courts[a].times[b].user_id = s.getuser_id();
									s.add_usercourts2(s.getuser_id(), courts[a]);
									if (courts[a].times[b].user_id != 0&& courts[a].times[b].count == 1) { cout << "Ԥ���ɹ�" << endl; system("pause"); system("cls"); break; }
									else { cout << "Ԥ��ʧ��" << endl; system("pause"); system("cls"); break; }
								}
								else { continue; }
							}
							break;
						}
					}
					else { cout << "�û���Ų���ȷ" << endl; break; }
				}
			}

		}
	}

	void cancel(int userid) {//ȡ��ԤԼ
		int count = 0;
		if (users.empty() || courts.empty()) { cout << "��ǰû���û���ǰû���������ݿɹ�ԤԼ" << endl; }
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					count++;
					while (1) {
							cout << "��������Ҫȡ��Ԥ���ĳ��ݱ��" << endl; int a; cin >> a; cin.ignore(); if (a == 0) { break; }
							if (a > 0 && static_cast<unsigned long int>(a) <= courts.size()) {
								cout << "��������Ҫȡ��Ԥ����ʱ���" << endl; string b; getline(cin, b);
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
														cout << "ȡ���ɹ�" << endl; system("pause"); break;
													}
													else { cout << "��û��Ԥ����ʱ���" << endl; system("pause"); break; }
												}
											}
											break;
										}
									}
									break;
								}
								else{ cout << "��������ȷ��ֵ" << endl; continue; }
							}
							else { cout << "��������ȷ��ֵ" << endl; continue; }
					}
				}
			}
			if (count == 0) { cout << "�û���Ų�����" << endl; system("pause");}
		}
	}

	void cancel_all(int userid){//һ��ȡ������ԤԼ
		if (users.empty() || courts.empty()) { cout << "��ǰû���û���ǰû���������ݿɹ�ԤԼ" << endl; }
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
								cout << "һ��ȡ���ɹ�" << endl;
							}
						}
					}
				}
			}
		}
	}

	void search() {//��Ѱ��������ԤԼ��Ϣ
		if(courts.empty()){cout << "��ǰû���κ��û�" << endl; system("pause");}
		else{
		cout << "��������Ҫ��ѯ�ĳ��ݱ��" << endl; int a; cin >> a; cin.ignore();
		if (a > 0 && static_cast<unsigned long int>(a) <= courts.size()) {
			cout << "��������Ҫ��ѯ��ʱ���(���Ȳ�ѯ������Ϣ�鿴)" << endl; string b; getline(cin, b); t time1;
			if (!b.empty() && b.length() <= 11 && find(b.begin(), b.end(), '-') == b.end()&& find(b.begin(), b.end(), ':') == b.end()) {
				for (c& s : courts) {
					if (s.court_id == a) {
						for (timescale& t_time : s.times) {
							if (t_time.time == b) {
								time1 = t_time;
								if (t_time.count == 1) { cout << "��ʱ����ѱ�Ԥ��" << endl; }
								else { cout << "��ʱ���δ��Ԥ��" << endl; }
							}
						}
						if (time1.time.empty()) { cout << "û���ҵ���ʱ���" << endl; }
						system("pause");
					}
				}
			}
			else{ cout << "��������ȷ��ʱ���(����9:00-10:00,�����Ϊ1Сʱ)" << endl; }
		}
		}

	}

	void recharge(int userid) {//��ֵ��������
		if (users.empty()) { cout << "��ǰû���κ��û�" << endl; system("pause");}
		else {
			for (u& s : users) {
				if (s.getuser_id() == userid) {
					if (s.getuser_id() == userid && static_cast<unsigned long int>(s.getuser_id()) <= users.size()) {
						cout << "��������Ҫ��ֵ�Ľ��" << endl; int a; cin >> a; cin.sync();
						if ((s.getuser_balance() + a) > 1000) { cout << "��ֵʧ��,��ֵ����ܳ���1000" << endl; system("pause"); continue; }
						else {
							s.setuser_balance(s.getuser_balance() + a);
							cout << "��ֵ�ɹ�" << endl;
							system("pause"); break;
						}
					}
					else { cout << "��������ȷ��ֵ" << endl; system("pause"); continue; }
				}
			}

		}
	}

void check_user_info(int userid) {
	if (users.empty()) { cout << "��ǰû���κ��û�" << endl; }
	else {
		u t;
		for (u& s : users) {
			if (s.getuser_id() == userid) {
				t = s; break;
			}
		}
		if (t.getuser_id() > 0 && static_cast<unsigned long int>(t.getuser_id()) <= users.size()) {
			cout << "����û����Ϊ:" << t.getuser_id() << endl;
			cout << "����û���Ϊ:" << t.getuser_name() << endl;
			cout << "����û�����Ϊ:" << t.getuser_password() << endl;
			cout << "����û����Ϊ:" << t.getuser_balance() << endl;
			t.list_all_usercourts2(t.getuser_id());
			system("pause");
		}
		else { cout << "�û���Ŵ�������!" << endl; system("pause");}
	}
}

void check_user_info_admin() {
	if (users.empty()) { cout << "��ǰû���κ��û�" << endl; system("pause");}
	else {
		for (u& s : users) {
			cout << "�û����Ϊ:" << s.getuser_id() << endl;
			cout << "�û���Ϊ:" << s.getuser_name() << endl;
			cout << "�û�����Ϊ:" << s.getuser_password() << endl;
			cout << "�û����Ϊ:" << s.getuser_balance() << endl;
			s.list_all_usercourts2(s.getuser_id());
			cout << "----------------------------------------" << endl;
		}
		system("pause");
	}
}

void menu() {
	cout << "��ӭ�������ڴ�ѧ��������ԤԼϵͳ" << endl << endl;
	cout << "1.ԤԼ��������" << endl;
	cout << "2.ȡ��ԤԼ" << endl;
	cout << "3.һ��ȡ������ԤԼ" << endl;
	cout << "4.��ѯ��������ԤԼ���" << endl;
	cout << "5.��ֵ" << endl;
	cout << "6.�鿴�û���Ϣ" << endl;
	cout << "7.������������ԤԼ��Ϣ" << endl;
	cout << "8.�˳�ϵͳ(��7,q/Q������)" << endl;
	cout << "9.���ԤԼ��������" << endl;
}

void welcome_page() {
	cout << "��ӭ�������ڴ�ѧ��������ԤԼϵͳ" << endl << endl;
	cout << "1.��¼" << endl;
	cout << "2.ע���û�" << endl;
	cout << "3.��������" << endl;
	cout << "4.����Աϵͳ" << endl;
	cout << "5.�˳�ϵͳ(��5,q/Q������)" << endl;
}

void admin_page() {
	cout << "��ӭ��������Աϵͳ" << endl << endl;
	cout << "1.�鿴��������ԤԼ���" << endl;
	cout << "2.�鿴����������Ϣ" << endl;
	cout << "3.�鿴�����û���Ϣ" << endl;
	cout << "4.�����û�������������Ϣ���ļ�" << endl;
	cout << "5.�����������" << endl;
	cout << "6.��������û�����������(ֻ������һ��,��ֹ����̫�ർ�³������)" << endl;
	cout << "7.�˳�ϵͳ(��6,q/Q������)" << endl;
}

void admin_page1() {
	cout << "��ӭ��������Աϵͳ" << endl << endl;
	cout << "1.�鿴��������ԤԼ���" << endl;
	cout << "2.�鿴����������Ϣ" << endl;
	cout << "3.�鿴�����û���Ϣ" << endl;
	cout << "4.�����û�������������Ϣ���ļ�" << endl;
	cout << "5.�����������" << endl;
	cout << "6.�˳�ϵͳ(��6,q/Q������)" << endl;
}

void show_booking_condition() {//�鿴��������ԤԼ״��
	if(courts.empty()){cout<<"��ǰû���κ���������"<<endl; system("pause");
	}
	else {
		for (c& s : courts) {
			s.show_info_admin_only();
			for (timescale& t : s.times) {
				if (t.count == 0) {
					cout << left << setw(12) << t.time << "    " << "δԤ��" << endl;
				}
				else if (t.count == 1) {
					for (u& s1 : users) { if (s1.getuser_id() == t.user_id) { cout << left << setw(12) << t.time << "    " << "�û�"<<s1.getuser_name()<<"��Ԥ��" << endl; } }
				}
				else { cerr << "Error!!" << endl; }
			}
			cout<<"----------------------------------------"<<endl;
		}
		system("pause");
	}
}

void random_generate_user(int userid) {//��������û�
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

void random_generate_court(int courtid) {//���������������
	random_device rd;
	mt19937 gen(rd());
	string court1[10] = { "����","����","��ë��","ƹ����","����","����","����","�߶�����","������","������" };
	uniform_int_distribution<> a(0, 9);
	uniform_int_distribution<> b(20, 100);
	vector<timescale> t;									
	for (int i = 0; i < 12; i++) {//Ĭ�Ͽ���ʱ��Ϊ8:00-22:00,ÿ��ʱ���Ϊ1Сʱ
		string str = to_string(8 + i) + ":00-" + to_string(9 + i) + ":00";
		t.emplace_back(str, 0, 0);
	}
	courts.emplace_back(courtid, court1[a(gen)], b(gen), 0, t);
}

void password_forget(string username) {//�һ�����
		if (username.length() >= 3 && username.length() <= 10) {
			u t;
			for (u& s : users) {
				if (s.getuser_name() == username) {
					t = s;
				}
			}
			if (!t.getuser_password().empty()) {
				cout << "�������Ϊ:" << t.getuser_password() << endl; system("pause");
			}
			else { cout << "δ�ҵ����û�!!" << endl; system("pause"); }
		}
		else { cout << "��������ȷ���û���" << endl; system("pause"); }
	
}

void save_data() {//�ļ�����
	if (users.empty() || courts.empty()) { cout << "��ǰû���û���ǰû���������ݿɹ�ԤԼ" << endl; system("pause"); }
	else {
		ofstream fout("users.txt");
		for (u& s : users) {
			fout << "------------------------------------------" << endl;
			fout << "�û����:" << s.getuser_id() << endl << "�û���:" << s.getuser_name() << endl << "�û�����:" << s.getuser_password() << endl << "�û����:" << s.getuser_balance() << endl;
			fout<<"�û�ԤԼ�ĳ�����Ϣ:"<<endl;
			s.fout_list_all_usercourts2(s.getuser_id(),fout);
		}
		if (!fout.fail()) { cout << "�û��ļ�д��ɹ�!" << endl << endl; }
		fout.close();
		ofstream fout1("courts.txt");
		for (c& s : courts) {
			fout1 << "------------------------------------------" <<endl;
			fout1 << "�������ݱ��:" << s.court_id << endl << "������������:" << s.court_name << endl << "��������һСʱ����:" << s.expense_per_hour << endl << "����������ԤԼʱ��:" << s.total_booked_hour << endl << "��������������:" << s.total_income << endl;
			for (timescale& t : s.times) {
				if (t.count == 1) { fout1 << left << setw(13) << t.time<<"    "<<"�ѱ��û����Ϊ"<<t.user_id<<"���û�ԤԼ!"<<endl; }
				else if (t.count == 0) { fout1 << left << setw(13) << t.time << "    " << "δ��ԤԼ" << endl; }
				else { cerr << "Error!!" << endl; }
			}
		}
		if (!fout1.fail()) { cout << "���������ļ�д��ɹ�!" << endl; }
		fout1.close();
		system("pause");
	}
}

void login() {//�û���¼
	while (1) {
		system("cls"); int count=0;
		if (users.empty()) { cout << "��ǰû���κ��û�" << endl; system("pause"); break; }
		cout << "����������û���(����q/Q���ز˵�):" << endl; string b; cin >> b; cin.sync(); if (b == "Q" || b == "q") {  break; }
		cout << "�������������(����q/Q���ز˵�):" << endl; string c;  cin >> c; cin.sync();  if (c == "Q" || c == "q") {  break; }
			for (u& s : users) {
				if (s.getuser_name() == b && s.getuser_password() == c) {
					system("cls"); count++;
					while (1) {
						menu();
						cout << "���������ѡ��:"; char d = _getch();
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
						case '8': {cout << "�˳���¼" << endl; break; }
						case '9': {system("cls"); random_book(s.getuser_id()); continue; }
						default: {cout << "��������ȷ��ֵ" << endl; }
						}
						break;
					}
					break;
				}
			}
			if (count == 1) { break; }
			else if (count == 0) { cout << "�û������������!!" << endl; system("pause"); continue; }
		}
	}

void admin_login(int& courtid,int& userid,int& count,int& count1) {//����Ա��¼
	while (1) {
		system("cls");
		cout << "���������Ա����(����q/Q���ز˵�):"<<endl; string a; getline(cin, a);
		if (a == "114514") {
			while (1) {
				cin.sync();
				if (count + count1 < 2) {
					system("cls");
					admin_page();
					cout << "���������ѡ��:"; char d = _getch();
					switch (d) {
					case '1': {system("cls"); show_booking_condition(); continue; }
					case '2': {system("cls");
						if (!courts.empty()) {
							for (c& s : courts) { s.show_info_admin_only(); }system("pause"); continue;
						}
						else { cout << "��ǰû���κ���������" << endl; system("pause"); continue; }
					}
					case '3': {system("cls"); check_user_info_admin(); continue; }
					case '4': {system("cls"); save_data(); continue; }
					case '5': {system("cls"); add_court(courtid); continue; }
					case '6': {
						while (1) {
							system("cls");
							cout<<"1.���������������"<<endl;
							cout << "2.��������û�" << endl;
							cout << "3.���ز˵�(q/Q/3)" << endl;
							char a = _getch();
							if (a == '1' && count < 1) {
								system("cls");
								cout << "��������Ҫ������ɵ�������������(������10��)(����0���ز˵�)" << endl; int n; cin >> n; cin.sync(); size_t d = courts.size();
								if (n > 0 && n <= 10) {
									for (int i = 0; i < n; i++) {
										random_generate_court(courtid++);
									}
									if (courts.size() == (d + n)) { count++; cout << "��������������ɳɹ�" << endl; system("pause"); cin.ignore(); continue; }
									else { cout << "���������������ʧ��" << endl; system("pause"); continue; }
								}
								else if (n == 0) { system("cls"); continue; }
								else { cout << "��������ȷ��ֵ" << endl; system("pause"); continue; }
							}
							else if (a == '2' && count1 < 1) {
								system("cls");
								cout << "��������Ҫ������ɵ��û�����(������20��)(����0���ز˵�)" << endl; int m; cin >> m; cin.sync(); size_t f = users.size();
								if (m > 0 && m <= 20) {
									for (int i = 0; i < m; i++) {
										random_generate_user(userid++);
									}
									if (users.size() == (f + m)) { count1++; cout << "�û�������ɳɹ�" << endl; system("pause"); cin.ignore(); continue; }
									else { cout << "�û��������ʧ��" << endl;  system("pause"); continue; }
								}
								else if (m == 0) { system("cls"); continue; }
								else { cout << "��������ȷ��ֵ" << endl; system("pause"); continue; }
							}
							else if (a == '3' || a == 'q' || a == 'Q') { break; }
							else { cout << "����ֵ���� �� �����û����������涨 �� �����������ݴ��������涨" << endl; system("pause"); continue; }
					}
					continue;
				}
					case 'Q':
					case 'q':
					case '7': {break; }
					default: {cout << "��������ȷ��ֵ" << endl; system("pause"); continue; }
					}
				}
				else {
					system("cls");
					admin_page1();
					cout << "���������ѡ��:"; char d = _getch();
					switch (d) {
					case '1': {system("cls"); show_booking_condition(); continue; }
					case '2': {system("cls");
						if (!courts.empty()) {
							for (c& s : courts) { s.show_info_admin_only(); }system("pause"); continue;
						}
						else { cout << "��ǰû���κ���������" << endl; system("pause"); continue; }
					}
					case '3': {system("cls"); check_user_info_admin(); continue; }
					case '4': {system("cls"); save_data(); continue; }
					case '5': {system("cls"); add_court(courtid); continue; }
					case 'Q':
					case 'q':
					case '6': {break; }
					default: {cout << "��������ȷ��ֵ" << endl; system("pause"); continue; }
					}
				}
				break;
			}
			break;
		}
		else if (a == "q" || a == "Q") { break; }
		else { cout << "�������,����������" << endl; system("pause"); continue; }
	}
}

bool full_book(int courtid) {//�жϵ�ǰ�����Ƿ��Ѿ�Լ��
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

court operator>(court&a,court&b) {//����������Ƚ������������ݵ���ԤԼʱ��
	if (a.total_booked_hour > b.total_booked_hour) {
		return a;
	}
	return b;
}
