#ifndef MEGANYANCAT_H
#define MEGANYANCAT_H

#include "NyanCat.h"

class MegaNyanCat : public NyanCat {
public:
    MegaNyanCat(int x, int y, char symbol);

    void move() override; // Override the move method for the highest fall speed
};

#endif // MEGANYANCAT_H
