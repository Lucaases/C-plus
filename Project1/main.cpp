#include "recommand.h"

int main() {
	user user[5] = { {1,"Max","Action"},{2,"Jame","Comedy"},{3,"Peter","Animation"},{4,"Sarah","Science Fiction"},{5,"Icey","Horror"} };
	film film[12] = {
		{1,"Full River Red","Comedy",7.0f},{2,"The Wandering Earth II","Science Fiction",8.3f},{3,"Chang An","Animation",8.4f},{4,"Creation of The God:Kingdom of Storms","Action",7.8f},
		{5,"Never Say Never","Action",7.3f},{6,"Godspeed","Comedy",5.8f},{7,"Deep Sea","Animation",7.2f},{8,"Born to Fly","Action",6.5f},
		{9,"A Night of Soul Turning","Horror",6.4f},{10,"Five Hundred Miles","Comedy",5.0f},{11,"Oh My School!","Animation",7.4f},{12,"Get in the Dark","Horror",6.3f}
	};
	for (int i = 0; i < 5; i++) {
		user[i].recommand_flim(film,12);
		user[i].display();
		for (int j = 0; j < 12; j++) {//通过内层循环找到每个用户对应推荐电影对象并输出
			if (film[j].get_name_film() == user[i].get_film_recommanding()) {
				film[j].display();
			}
		}
	}
	cout << endl <<"Sort all films by rating:"<< endl << endl;
	film->sort_by_rating(film, 12);
	cout << endl <<"Sort all films by type and rating:" << endl << endl;
	film->sort_by_type_and_rating(film, 12);
	return 0;
}