#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Music {
public:
    string title;
    string artist;
    string genre;
    double rating;

    Music(const string& t, const string& a, const string& g)
        : title(t), artist(a), genre(g), rating(0.0) {}
};

class User {
public:
    int id;
    string username;
    unordered_map<string, double> musicRatings;  // Music title to rating mapping

    User(int i, const string& u) : id(i), username(u) {}

    void rateMusic(const string& title, double rating) {
        musicRatings[title] = rating;
    }
};

class Group {
public:
    string name;
    string description;
    vector<User*> members;

    Group(const string& n, const string& d) : name(n), description(d) {}

    void addUser(User* user) {
        members.push_back(user);
    }

    void showMembersAndRatings() {
        cout << "Group: " << name << " - Description: " << description << endl;
        for (User* user : members) {
            cout << "User " << user->id << ": " << user->username << " - Ratings:" << endl;
            for (const auto& rating : user->musicRatings) {
                cout << "  " << rating.first << ": " << rating.second << endl;
            }
        }
    }
};

class MusicPlatform {
public:
    vector<Music> musics;
    vector<User> users;
    vector<Group> groups;

    void addMusic(const string& title, const string& artist, const string& genre) {
        musics.emplace_back(title, artist, genre);
    }

    void addUser(const string& username) {
        users.emplace_back(users.size() + 1, username);
    }

    void rateMusic(User& user, const string& title, double rating) {
        user.rateMusic(title, rating);

        // Update average rating for the music
        double totalRating = 0.0;
        for (const User& u : users) {
            auto it = u.musicRatings.find(title);
            if (it != u.musicRatings.end()) {
                totalRating += it->second;
            }
        }

        for (Music& music : musics) {
            if (music.title == title) {
                music.rating = totalRating / users.size();
                break;
            }
        }
    }

    void createGroup(const string& name, const string& description) {
        groups.emplace_back(name, description);
    }

    void addUserToGroup(User& user, Group& group) {
        group.addUser(&user);
    }

    void showAllGroups() {
        for (const Group& group : groups) {
            cout << "Group: " << group.name << " - Description: " << group.description << endl;
        }
    }
};