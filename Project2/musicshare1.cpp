#include "musicshare.h"

void mainmenu() {//���˵�����
	cout << "��ӭ����Netease���ַ���ƽ̨!!!!" << endl << endl << endl;
	cout << "��enter�����û�ע�����!!!" << endl << endl;
	cout << "��ո���������û���¼����!!!" << endl << endl;
	cout << "��f/F������ʹ�ñ�Ų�������û���" << endl << endl;
	cout << "��g/G������ʹ�����������(ֻ������һ��,��ֹ����̫��������)" << endl << endl;
	cout << "��0�����Բ鿴��ǰ�����û���Ϣ(����Ա)" << endl << endl << endl << endl;
	cout << "��q/Q�����˳�ƽ̨" << endl << endl;
}

void mainmenu1() {//���˵�����
	cout << "��ӭ����Netease���ַ���ƽ̨!!!!" << endl << endl << endl;
	cout << "��enter�����û�ע�����!!!" << endl << endl;
	cout << "��ո���������û���¼����!!!" << endl << endl;
	cout << "��f/F������ʹ�ñ�Ų�������û���" << endl << endl;
	cout << "��0�����Բ鿴��ǰ�����û���Ϣ(����Ա)" << endl << endl << endl << endl;
	cout << "��q/Q�����˳�ƽ̨" << endl << endl;
}

void menu() {//�û����溯��
	cout << "1.���������µ�����,�밴1��" << endl << endl;
	cout << "2.�����鿴��ǰ���е���������,�밴2��" << endl << endl;
	cout << "3.�����鿴����С��,�밴3��" << endl << endl;
	cout << "4.��������С��,�밴4��" << endl << endl;
	cout << "5.������˳�С��,�밴5��" << endl << endl;
	cout << "6.����봴��С��,�밴6��" << endl << endl;	
	cout << "7.��������������,�밴7��" << endl << endl;
	cout << "8.�����ͨ�����ֲ��Ҹ���,�밴8��" << endl << endl;
	cout << "9.�����ͨ�����Ͳ��Ҹ���,�밴9��" << endl << endl;
	cout << "10.�����ͨ�����ֲ��Ҹ���,�밴*��" << endl << endl;
	cout << "11.�����ע���û�,�밴q/Q��" << endl << endl;
}

int main() {
	system("color 0b");
	int music_id = 1, user_id = 1, group_id = 1; //ÿ���û�,ÿ������,ÿ��С�鶼��һ����һ�޶��ı��,���Է����������
	int random_gen=0;
	string a; string d; 
	Platform Netease;
	
	while (1) {
		int error = 0;
		system("cls");
		if (random_gen < 1) { mainmenu(); }else{ mainmenu1(); }
		char b = _getch();
		if (b == '\r') {
			system("cls");
			cout << "����������û���(������3���ַ�,������10���ַ�,��������ո�)" << endl; getline(cin, a);
			if (find(a.begin(), a.end(), ' ') == a.end() && a.length() >= 3&& a.length() <= 10 &&Netease.samename(a)) {//�ж��û����Ƿ����
				Netease.add_newuser(user_id++,a);
				cout << "���μ�,����û����Ϊ" << user_id-1 << endl;
				system("pause");
				while (1)
				{
					system("cls");
					menu();
					char c = _getch();
					switch (c) {
					case '1':
						system("cls");
						Netease.add_newsong(music_id++);
						if (Netease.musics.size() == music_id - 1) { system("cls"); cout << endl << "�ɹ��������" << endl; system("pause"); }
						continue;
					case '2':
						system("cls");
						Netease.show_All_songs();
						system("pause");
						continue;
					case '3':
						system("cls");
						if (Netease.groups.empty())
						{
							cout << "������һ��С�鶼û��" << endl;
							system("pause");
						}
						else {
							Netease.show_All_Groups();
							system("pause");
						}
						continue;
					case'5':
						system("cls");
						int h;
						if (Netease.groups.empty()) {
							cout << "������һ��С�鶼û��,�޷��˳�" << endl;
							system("pause");
						}
						else if (!Netease.judge_group_member(user_id-1)) {
							cout << "��һ��С�鶼û�м�,�޷��˳�" << endl;
							system("pause");
						}
						else {
							cout << "�Ѽ���С��:" << endl;
							for (Group*& p : Netease.get_user_groups(user_id-1)) {
								cout <<"С����:"<<left<<setw(2)<<p->getid()<<"    "<< "С������:" << left << setw(10) << p->getname() << endl;
							}
							system("pause");
							cout << endl << "������Ҫ�˳�С��ı��" << endl; cin.width(2); cin >> h; cin.ignore();
							Netease.quit_group(h, user_id-1);
						}
						continue;
					case'4':
						system("cls");
						if (Netease.groups.empty()) {
							cout << "������һ��С�鶼û��,�޷�����" << endl;
							system("pause");
						}
						else {
							int p;
							cout << "������Ҫ�����С����(����0����)" << endl; cin.width(2); cin >> p; cin.ignore();
							if (p == 0) { break; }
							else if(p<=Netease.groups.size() && p > 0){
								for (User& u : Netease.users) {
									if (u.getid() == user_id - 1) {
										Netease.join_group(p, u);
										system("pause");
									}
								}
							}
							else { cout << "��������ȷ���" << endl; system("pause");}
						}
						continue;
					case'6':
						system("cls");
						for (User& u : Netease.users) {
							if (u.getid() == user_id - 1) {
								Netease.create_newgroup(group_id++,u);
							}
						}
						if (Netease.groups.size() == group_id - 1) { system("cls"); cout << endl << "�ɹ�����С��" << endl; system("pause"); }
						continue;
					case'7':
						system("cls");
						if (Netease.musics.empty()) {
							cout << endl << "����û������,�޷�����" << endl;
							system("pause");
						}
						else {
							Netease.show_All_songs();
							for (User& z : Netease.users) {
								if (z.getid() == user_id - 1) {
									Netease.rate_music(z);
									cout << "���۳ɹ�,лл���֧��" << endl;
									system("pause");
								}
							}
						}
						continue;
					case'8':
						system("cls");
						if (Netease.musics.empty()) {
							cout << endl << "����û������,�޷�����" << endl;
							system("pause");
						}
						else {
							Netease.sort_name();
							system("pause");
						}
						continue;
					case'9':
						system("cls");
						if (Netease.musics.empty()) {
							cout << endl << "����û������,�޷�����" << endl;
							system("pause");
						}
						else {
							Netease.sort_type();
							system("pause");
						}
						continue;
					case'*':
						system("cls");
						if (Netease.musics.empty()) {
							cout << endl << "����û������,�޷�����" << endl;
							system("pause");
						}
						else {
							Netease.sort_singer();
							system("pause");
						}
						continue;
					case'Q':
					case'q':break;
					default:
						system("cls");
						cout << "error:��������ȷ��ֵ!" << endl << endl;
						system("pause");
						continue;
					}
					if (c == 'q'||c=='Q') {
						system("cls");
						cout << "��ǰ�û����˳�" << endl << endl;
						system("pause");
						system("cls");
						break;
					}
				}
			}
			else {
				cout << "����û���̫��(���������ַ�)����̫��(����ʮ���ַ�)���߰����ո����������" << endl;
				system("pause");
				continue;
			}
		}
		else if (b == ' ') {
			User k;
			system("cls");
			if (Netease.users.empty()) {
				system("cls"); cout << "ƽ̨�տ���Ҳ,ɶ��û!!" << endl << endl; system("pause");
			}
			else {
				cout << "����������û���" << endl; getline(cin, d);
				for (User& l : Netease.users) {
					if (l.getusername() == d) { k = l; }
				}
				if (!k.getusername().empty()) {//�ж��û��Ƿ���ע���
					while (1)
					{
						system("cls");
						menu();
						char a = _getch();
						switch (a) {
						case '1':
							system("cls");
							Netease.add_newsong(music_id++);
							if (Netease.musics.size() == music_id - 1) { system("cls"); cout << endl << "�ɹ��������" << endl; system("pause"); }
							continue;
						case '2':
							system("cls");
							Netease.show_All_songs();
							system("pause");
							continue;
						case '3':
							system("cls");
							if (Netease.groups.empty())
							{
								cout << "������һ��С�鶼û��" << endl;
								system("pause");
							}
							else {
								Netease.show_All_Groups();
								system("pause");
							}
							continue;
						case'5':
							system("cls");
							int h;
							if (Netease.groups.empty()) {
								cout << "������һ��С�鶼û��,�޷��˳�" << endl;
								system("pause");
							}
							else if (!Netease.judge_group_member(k.getid())) {
								cout << "��һ��С�鶼û�м�,�޷��˳�" << endl;
								system("pause");
							}
							else {
								cout << "�Ѽ���С��:" << endl;
								for (Group* p : Netease.get_user_groups(k.getid())) {
									cout << "С����:" << left << setw(2) << p->getid() << "    " << "С������:" << left << setw(10) << p->getname() << endl;
								}
								system("pause");
								cout << endl << "������Ҫ�˳�С��ı��" << endl; cin.width(2); cin >> h; cin.sync();
								Netease.quit_group_login(h, k);
								
							}
							continue;
						case'4':
							system("cls");
							int o;
							if (Netease.groups.empty()) 
							{
								cout << "������һ��С�鶼û��" << endl;
								system("pause");
							}
							else {
								cout << "������Ҫ�����С����(����0����)" << endl; cin.width(2); cin >> o; cin.sync();
								if (o <= Netease.groups.size()&&o>0) {
									Netease.join_group(o, k);
									cout << endl << "����С��ɹ�,лл���֧��" << endl;
									system("pause");
								}
								else if(o==0) {break;}
								else{ cout << "��������ȷ���" << endl; system("pause"); }
							}
							continue;
						case'6':
							system("cls");
							Netease.create_newgroup(group_id++,k);
							if (Netease.groups.size() == group_id - 1) { system("cls"); cout << endl << "�ɹ�����С��" << endl; system("pause"); }
							continue;
						case'7':
							system("cls");
							if (Netease.musics.empty()) {
								cout << endl << "����û������,�޷�����" << endl;
								system("pause");
							}
							else {
								Netease.show_All_songs();
								Netease.rate_music(k);
								cout << "���۳ɹ�,лл���֧��" << endl;
								system("pause");
							}
							continue;
						case'8':
							system("cls");
							if (Netease.musics.empty()) {
								cout << endl << "����û������,�޷�����" << endl;
								system("pause");
							}
							else {
								Netease.sort_name();
								system("pause");
							}
							continue;
						case'9':
							system("cls");
							if (Netease.musics.empty()) {
								cout << endl << "����û������,�޷�����" << endl;
								system("pause");
							}
							else {
								Netease.sort_type();
								system("pause");
							}
							continue;
						case'*':
							system("cls");
							if (Netease.musics.empty()) {
								cout << endl << "����û������,�޷�����" << endl;
								system("pause");
							}
							else {
								Netease.sort_singer();
								system("pause");
							}
							continue;
						case'Q':
						case'q':break;
						default:
							system("cls");
							cout << "error:��������ȷ��ֵ!" << endl << endl;
							system("pause");
							continue;
						}
						if (a == 'q'||a == 'Q') {
							system("cls");
							cout << "��ǰ�û����˳�" << endl << endl;
							system("pause");
							system("cls");
							break;
						}
					}
				}
				else { system("cls"); cout << "�Բ���,������ûע��!!" << endl << endl; system("pause"); }
			}
		}
		else if (b == 'q'||b=='Q') { system("cls"); break; }
		else if (b == '0') {
			string password;
			while (1) {
				system("cls");
				cout << "���������Ա����!!(�����ν��Զ��˳�����)(����q�ɷ��ز˵�)" << endl; getline(cin, password);
				if (password == "114514") {
					system("cls");
					Netease.show_all_users();
					system("pause");
					break;
				}
				else if (password == "q"||password=="Q") { break; }
				else {
					error++;
					cout << "�������!!!����������!!!(�����ν��Զ��˳�����)" << endl;
					system("pause");
					if (error >= 5) { system("cls"); break; }
				}
			}
			if (error >= 5) { system("cls"); break; }
		}
		else if (b == 'g'||b=='G') {
			int u, s, g;
			random_gen++;
			if (random_gen < 2) {
				while (1) {
					system("cls");
					cout << "������������ɵ��û�,���ֺ�С������(�ո����)(�û�������20��,���ֲ�����15��,С�鲻����10��)(����0 0 0����������0�س��ص��˵�)" << endl;
					cin >> u >> s >> g; cin.sync();//��cin�س��������ַ�ʡ��,�������ڻ�����Ӱ��������Ҫ��������
					if (u <= 20 && s <= 15 && g <= 10 && u > 0 && s > 0 && g > 0) {//�޶���������,ֻ��̫���ظ�
						random_device rd;
						mt19937 gen(rd());//÷ɭ��ת�㷨����α�����
						uniform_int_distribution<> u1(0, u - 1);
						uniform_int_distribution<> g1(0, g - 1);
						for (int i = 0; i < u; i++) {
							Netease.random_generate_user(user_id++);
						}
						for (int i = 0; i < s; i++) {
							Netease.random_generate_song(music_id++);
						}
						for (int i = 0; i < g; i++) {
							Netease.random_generate_group(group_id++);
						}
						for (User& u : Netease.users) {
							for (Music& m : Netease.musics) {
								Netease.rate_music_random(u, m);
							}
						}
						for (int i = 0; i < u; i++) {
							Netease.random_grouping(Netease.users[u1(gen)], Netease.groups[g1(gen)]);
						}
						if (Netease.users.size() == user_id - 1 && Netease.musics.size() == music_id - 1 && Netease.groups.size() == group_id - 1 && Netease.judge_rating_exist()) {//����Ƿ�ɹ�����
							system("cls");
							cout << "��ϲ,�ɹ�����!!!" << endl;
							system("pause");
							break;
						}
						else {
							system("cls");
							cout << "����ʧ��,������!!!" << endl;
							system("pause");
							break;
						}
					}
					else if (u == 0 && s == 0 && g == 0) { break; }
					else {
						cout << "������������ȷ����ֵ" << endl;
						system("pause");
						continue;
					}
				}
			}
			else { continue; }
		}
		else if (b == 'f'||b=='F') {
			system("cls"); 
			if (!Netease.users.empty()) {
				User t;
				int f; cout << "����������û�����Բ��Ҷ�Ӧ�û���!!!" << endl; cin.width(2); cin >> f; cin.sync();
				for (User& u : Netease.users) {
					if (u.getid() == f) {
						t = u;
						cout << "����û���Ϊ" << u.getusername() << endl;
						system("pause");
					}
				}
				if (t.getusername().empty()) { cout << "û���ҵ���Ӧ���û���,������������ı��!!" << endl; system("pause"); }
			}
			else {
				cout << "һ���û���û��,�޷�Ѱ���û���" << endl; system("pause");
			}
		}
		else { system("cls"); cout << "error:��������ȷ��ֵ!" << endl << endl; system("pause"); continue; }
	}
	return 0;
}


