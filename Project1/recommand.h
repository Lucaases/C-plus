#include<iostream>
#include<string>
using namespace std;
class film {
private:
	int id_film{};
	string name_film{};
	string type_film{};
	float rating{};
public:
	film(int a, string b, string c, float d) :id_film(a), name_film(b), type_film(c), rating(d) {}
	film() {}
	~film() {}

	string get_type_film() {
		return type_film;
	}

	float get_rating() {
		return rating;
	}

	string get_name_film() {
		return name_film;
	}

	void display() {
		cout << "Film's id " << id_film << endl;
		cout << "Film's name is " << name_film << endl;
		cout << "Film's type is " << type_film << endl;
		cout << "Film's rating is " << rating << endl << endl;
	}

	void sort_by_rating(film* p, int size) {
		film t;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (p[j + 1].get_rating() > p[j].get_rating()) {
					t = p[j + 1];
					p[j + 1] = p[j];
					p[j] = t;
				}
			}
		}
		for (int m = 0; m < size; m++) {
			p[m].display();
		}
	}

	bool compare(film a, film b) {//��������ʵ�ֵ�Ӱ���������ֵ�ͬʱ����
		if (a.get_type_film() == b.get_type_film()) { return a.get_rating() > b.get_rating(); }//��������Ӱ������ͬ,�����б�ʽ a��Ӱ����>b��Ӱ����,��a��Ӱ���ֵ�ȷ����b��Ӱ����,����true;����,����false,���ͬ��Ӱ�������ֱȽ�
		return a.get_type_film() < b.get_type_film();//��������Ӱ���Ͳ�ͬ,�����б�ʽ a��Ӱ����<b��Ӱ����,��a��Ӱ�������ֵ����ϵ�ȷС��b��Ӱ����,����true,��ʾa��b֮ǰ;����,����false,��ʾb��a֮ǰ
	}

	void sort_by_type_and_rating(film* p, int size) {
		film t;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (compare(p[j + 1], p[j])) {
					t = p[j + 1];
					p[j + 1] = p[j];
					p[j] = t;
				}
			}
		}
		for (int m = 0; m < size; m++) {
			p[m].display();
		}
		
	}

};

class user {
private:
	int id_user{};
	string name_user{};
	string preference{};
	string film_recommanding{};
public:
	user(int a, string b, string c) :id_user(a), name_user(b), preference(c){ }
	~user() {}

	void recommand_flim(film* p, int size) {
		film* best_film = nullptr;
		for (int i = 0; i < size; i++) {
			if (p[i].get_type_film() == this->preference &&( best_film == nullptr || p[i].get_rating() > best_film->get_rating())) {
				best_film = &p[i];
			}
			if (best_film != nullptr) {
				this->film_recommanding = best_film->get_name_film();
			}
		}
	}

	string get_film_recommanding() {
		return film_recommanding;
	}

	void display() {
		cout << "User's id is " << id_user << endl;
		cout << "User's name is " << name_user << endl;
		cout << "User's preference is " << preference << endl;
		cout << "User's recommanded film is " << film_recommanding << endl;
		
	}
};

