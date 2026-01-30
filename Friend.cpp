#include "Friend.h"
#include <iostream>

using namespace std;

Friend::Friend(int supportLevel) : supportLevel(supportLevel) {}

// Friend function definition
void increaseSupportLevel(Friend* friendObj) {
    if (friendObj) {
        friendObj->supportLevel++;
        cout << "Support level increased! New support level: " << friendObj->supportLevel << endl;
    }
}
