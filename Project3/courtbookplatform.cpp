#include "courtbookplatform.h"

int main() {
	platform SZU_court;
	int user_id = 1, court_id = 1;int count = 0, count1 = 0;
	while (1) {
		cin.sync();
		system("cls");
		SZU_court.welcome_page();
		int choice = _getch();
		switch (choice) {
		case '1': {
			system("cls");
			SZU_court.login();
			continue; }
		case '2': {
			system("cls");
			SZU_court.register1(user_id);
			continue; }
		case '3': {
			system("cls");
			if (SZU_court.getusers().empty()) { cout << "当前没有任何用户" << endl; system("pause"); continue; }
			else {
				string username; cout << "请输入你的用户名" << endl; getline(cin, username);
				if (username == "q" || username == "Q") { continue; }
				SZU_court.password_forget(username);
				continue;
			}
		}
		case '4': {
			system("cls");
			SZU_court.admin_login(court_id,user_id, count, count1);
			continue;
		}
		case 'Q':
		case 'q':
		case '5': {system("cls"); break; }
		default: {cout << "输入错误，请重新输入" << endl; system("pause"); continue; }
		}
		break;
	}
	return 0;
}