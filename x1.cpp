#include "x1.h"

int main() {
    MusicPlatform platform;

    platform.addMusic("Song1", "Artist1", "Pop");
    platform.addMusic("Song2", "Artist2", "Rock");

    platform.addUser("User1");
    platform.addUser("User2");

    User& user1 = platform.users[0];
    User& user2 = platform.users[1];

    platform.rateMusic(user1, "Song1", 4.5);
    platform.rateMusic(user2, "Song1", 3.0);
    platform.rateMusic(user1, "Song2", 5.0);

    platform.showAllGroups();

    Group group("Group1", "Description1");
    platform.createGroup("Group1", "Description1");

    platform.addUserToGroup(user1, group);
    platform.addUserToGroup(user2, group);

    group.showMembersAndRatings();

    return 0;
}