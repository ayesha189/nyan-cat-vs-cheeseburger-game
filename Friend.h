#ifndef FRIEND_H
#define FRIEND_H

class Friend {
private:
    int supportLevel;

public:
    Friend(int supportLevel);

    // Friend function declaration
    friend void increaseSupportLevel(Friend* friendObj);
};

#endif // FRIEND_H
