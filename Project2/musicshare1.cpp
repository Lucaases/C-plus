#include "musicshare.h"

void mainmenu() {//主菜单函数
	cout << "欢迎来到Netease音乐分享平台!!!!" << endl << endl << endl;
	cout << "请enter进入用户注册界面!!!" << endl << endl;
	cout << "请空格键键进入用户登录界面!!!" << endl << endl;
	cout << "按f/F键可以使用编号查找你的用户名" << endl << endl;
	cout << "按g/G键可以使用随机生成器(只能生成一次,防止生成太多程序崩溃)" << endl << endl;
	cout << "按0键可以查看当前所有用户信息(管理员)" << endl << endl << endl << endl;
	cout << "按q/Q键可退出平台" << endl << endl;
}

void mainmenu1() {//主菜单函数
	cout << "欢迎来到Netease音乐分享平台!!!!" << endl << endl << endl;
	cout << "请enter进入用户注册界面!!!" << endl << endl;
	cout << "请空格键键进入用户登录界面!!!" << endl << endl;
	cout << "按f/F键可以使用编号查找你的用户名" << endl << endl;
	cout << "按0键可以查看当前所有用户信息(管理员)" << endl << endl << endl << endl;
	cout << "按q/Q键可退出平台" << endl << endl;
}

void menu() {//用户界面函数
	cout << "1.如果想添加新的音乐,请按1键" << endl << endl;
	cout << "2.如果想查看当前库中的所有音乐,请按2键" << endl << endl;
	cout << "3.如果想查看所有小组,请按3键" << endl << endl;
	cout << "4.如果想加入小组,请按4键" << endl << endl;
	cout << "5.如果想退出小组,请按5键" << endl << endl;
	cout << "6.如果想创建小组,请按6键" << endl << endl;	
	cout << "7.如果想对音乐评分,请按7键" << endl << endl;
	cout << "8.如果想通过名字查找歌曲,请按8键" << endl << endl;
	cout << "9.如果想通过类型查找歌曲,请按9键" << endl << endl;
	cout << "10.如果想通过歌手查找歌曲,请按*键" << endl << endl;
	cout << "11.如果想注销用户,请按q/Q键" << endl << endl;
}

int main() {
	system("color 0b");
	int music_id = 1, user_id = 1, group_id = 1; //每个用户,每首音乐,每个小组都有一个独一无二的编号,可以方便后续操作
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
			cout << "请输入你的用户名(不少于3个字符,不多于10个字符,请勿输入空格)" << endl; getline(cin, a);
			if (find(a.begin(), a.end(), ' ') == a.end() && a.length() >= 3&& a.length() <= 10 &&Netease.samename(a)) {//判断用户名是否可用
				Netease.add_newuser(user_id++,a);
				cout << "请牢记,你的用户编号为" << user_id-1 << endl;
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
						if (Netease.musics.size() == music_id - 1) { system("cls"); cout << endl << "成功添加音乐" << endl; system("pause"); }
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
							cout << "看起来一个小组都没有" << endl;
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
							cout << "看起来一个小组都没有,无法退出" << endl;
							system("pause");
						}
						else if (!Netease.judge_group_member(user_id-1)) {
							cout << "你一个小组都没有加,无法退出" << endl;
							system("pause");
						}
						else {
							cout << "已加入小组:" << endl;
							for (Group*& p : Netease.get_user_groups(user_id-1)) {
								cout <<"小组编号:"<<left<<setw(2)<<p->getid()<<"    "<< "小组名称:" << left << setw(10) << p->getname() << endl;
							}
							system("pause");
							cout << endl << "请输入要退出小组的编号" << endl; cin.width(2); cin >> h; cin.ignore();
							Netease.quit_group(h, user_id-1);
						}
						continue;
					case'4':
						system("cls");
						if (Netease.groups.empty()) {
							cout << "看起来一个小组都没有,无法加入" << endl;
							system("pause");
						}
						else {
							int p;
							cout << "请输入要加入的小组编号(输入0返回)" << endl; cin.width(2); cin >> p; cin.ignore();
							if (p == 0) { break; }
							else if(p<=Netease.groups.size() && p > 0){
								for (User& u : Netease.users) {
									if (u.getid() == user_id - 1) {
										Netease.join_group(p, u);
										system("pause");
									}
								}
							}
							else { cout << "请输入正确编号" << endl; system("pause");}
						}
						continue;
					case'6':
						system("cls");
						for (User& u : Netease.users) {
							if (u.getid() == user_id - 1) {
								Netease.create_newgroup(group_id++,u);
							}
						}
						if (Netease.groups.size() == group_id - 1) { system("cls"); cout << endl << "成功创建小组" << endl; system("pause"); }
						continue;
					case'7':
						system("cls");
						if (Netease.musics.empty()) {
							cout << endl << "库中没有音乐,无法评价" << endl;
							system("pause");
						}
						else {
							Netease.show_All_songs();
							for (User& z : Netease.users) {
								if (z.getid() == user_id - 1) {
									Netease.rate_music(z);
									cout << "评价成功,谢谢你的支持" << endl;
									system("pause");
								}
							}
						}
						continue;
					case'8':
						system("cls");
						if (Netease.musics.empty()) {
							cout << endl << "库中没有音乐,无法查找" << endl;
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
							cout << endl << "库中没有音乐,无法查找" << endl;
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
							cout << endl << "库中没有音乐,无法查找" << endl;
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
						cout << "error:请输入正确的值!" << endl << endl;
						system("pause");
						continue;
					}
					if (c == 'q'||c=='Q') {
						system("cls");
						cout << "当前用户已退出" << endl << endl;
						system("pause");
						system("cls");
						break;
					}
				}
			}
			else {
				cout << "你的用户名太短(少于三个字符)或者太长(多于十个字符)或者包含空格或者有重名" << endl;
				system("pause");
				continue;
			}
		}
		else if (b == ' ') {
			User k;
			system("cls");
			if (Netease.users.empty()) {
				system("cls"); cout << "平台空空如也,啥都没!!" << endl << endl; system("pause");
			}
			else {
				cout << "请输入你的用户名" << endl; getline(cin, d);
				for (User& l : Netease.users) {
					if (l.getusername() == d) { k = l; }
				}
				if (!k.getusername().empty()) {//判断用户是否有注册过
					while (1)
					{
						system("cls");
						menu();
						char a = _getch();
						switch (a) {
						case '1':
							system("cls");
							Netease.add_newsong(music_id++);
							if (Netease.musics.size() == music_id - 1) { system("cls"); cout << endl << "成功添加音乐" << endl; system("pause"); }
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
								cout << "看起来一个小组都没有" << endl;
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
								cout << "看起来一个小组都没有,无法退出" << endl;
								system("pause");
							}
							else if (!Netease.judge_group_member(k.getid())) {
								cout << "你一个小组都没有加,无法退出" << endl;
								system("pause");
							}
							else {
								cout << "已加入小组:" << endl;
								for (Group* p : Netease.get_user_groups(k.getid())) {
									cout << "小组编号:" << left << setw(2) << p->getid() << "    " << "小组名称:" << left << setw(10) << p->getname() << endl;
								}
								system("pause");
								cout << endl << "请输入要退出小组的编号" << endl; cin.width(2); cin >> h; cin.sync();
								Netease.quit_group_login(h, k);
								
							}
							continue;
						case'4':
							system("cls");
							int o;
							if (Netease.groups.empty()) 
							{
								cout << "看起来一个小组都没有" << endl;
								system("pause");
							}
							else {
								cout << "请输入要加入的小组编号(输入0返回)" << endl; cin.width(2); cin >> o; cin.sync();
								if (o <= Netease.groups.size()&&o>0) {
									Netease.join_group(o, k);
									cout << endl << "加入小组成功,谢谢你的支持" << endl;
									system("pause");
								}
								else if(o==0) {break;}
								else{ cout << "请输入正确编号" << endl; system("pause"); }
							}
							continue;
						case'6':
							system("cls");
							Netease.create_newgroup(group_id++,k);
							if (Netease.groups.size() == group_id - 1) { system("cls"); cout << endl << "成功创建小组" << endl; system("pause"); }
							continue;
						case'7':
							system("cls");
							if (Netease.musics.empty()) {
								cout << endl << "库中没有音乐,无法评价" << endl;
								system("pause");
							}
							else {
								Netease.show_All_songs();
								Netease.rate_music(k);
								cout << "评价成功,谢谢你的支持" << endl;
								system("pause");
							}
							continue;
						case'8':
							system("cls");
							if (Netease.musics.empty()) {
								cout << endl << "库中没有音乐,无法查找" << endl;
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
								cout << endl << "库中没有音乐,无法查找" << endl;
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
								cout << endl << "库中没有音乐,无法查找" << endl;
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
							cout << "error:请输入正确的值!" << endl << endl;
							system("pause");
							continue;
						}
						if (a == 'q'||a == 'Q') {
							system("cls");
							cout << "当前用户已退出" << endl << endl;
							system("pause");
							system("cls");
							break;
						}
					}
				}
				else { system("cls"); cout << "对不起,您好像还没注册!!" << endl << endl; system("pause"); }
			}
		}
		else if (b == 'q'||b=='Q') { system("cls"); break; }
		else if (b == '0') {
			string password;
			while (1) {
				system("cls");
				cout << "请输入管理员密码!!(输错五次将自动退出程序)(输入q可返回菜单)" << endl; getline(cin, password);
				if (password == "114514") {
					system("cls");
					Netease.show_all_users();
					system("pause");
					break;
				}
				else if (password == "q"||password=="Q") { break; }
				else {
					error++;
					cout << "密码错误!!!请重新输入!!!(输错五次将自动退出程序)" << endl;
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
					cout << "请输入随机生成的用户,音乐和小组数量(空格隔开)(用户不超过20个,音乐不超过15首,小组不超过10个)(输入0 0 0或依次输入0回车回到菜单)" << endl;
					cin >> u >> s >> g; cin.sync();//将cin回车后留下字符省略,以免留在缓冲区影响其他需要输入的组件
					if (u <= 20 && s <= 15 && g <= 10 && u > 0 && s > 0 && g > 0) {//限定生成条件,只因太多重复
						random_device rd;
						mt19937 gen(rd());//梅森旋转算法生成伪随机数
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
						if (Netease.users.size() == user_id - 1 && Netease.musics.size() == music_id - 1 && Netease.groups.size() == group_id - 1 && Netease.judge_rating_exist()) {//检测是否成功生成
							system("cls");
							cout << "恭喜,成功生成!!!" << endl;
							system("pause");
							break;
						}
						else {
							system("cls");
							cout << "生成失败,请重试!!!" << endl;
							system("pause");
							break;
						}
					}
					else if (u == 0 && s == 0 && g == 0) { break; }
					else {
						cout << "请重新输入正确的数值" << endl;
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
				int f; cout << "请输入你的用户编号以查找对应用户名!!!" << endl; cin.width(2); cin >> f; cin.sync();
				for (User& u : Netease.users) {
					if (u.getid() == f) {
						t = u;
						cout << "你的用户名为" << u.getusername() << endl;
						system("pause");
					}
				}
				if (t.getusername().empty()) { cout << "没有找到对应的用户名,请重新输入你的编号!!" << endl; system("pause"); }
			}
			else {
				cout << "一个用户都没有,无法寻找用户名" << endl; system("pause");
			}
		}
		else { system("cls"); cout << "error:请输入正确的值!" << endl << endl; system("pause"); continue; }
	}
	return 0;
}


