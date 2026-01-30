#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const int GRID_HEIGHT = 20; // Example grid height
const int GRID_WIDTH = 40;  // Example grid width

class NyanCat : public GameObject {
protected:
    int fallSpeed;
    bool isVisible;

public:
    NyanCat(int x, int y, char symbol, int fallSpeed, bool isVisible = true);

    virtual void draw() override;
    virtual void move() override;
    virtual void collide(GameObject* other) override;
    virtual void fall();
};

#endif // NYANCAT_H
