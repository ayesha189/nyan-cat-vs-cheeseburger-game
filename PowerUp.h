#ifndef POWERUP_H
#define POWERUP_H

#include "GameObject.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include"Cheeseburger.h"
using namespace std;

 // Forward declaration for activate method
class Cheeseburger;
class PowerUp : public GameObject {
protected:
    int fallSpeed;
    string type;

public:
    PowerUp(int x, int y, char symbol, int fallSpeed, string type);

    virtual void activate(Cheeseburger* player) = 0;

    void move() override;
    void draw() override;
    void collide(GameObject* other) override;

    string getType() const;
};

#endif // POWERUP_H
