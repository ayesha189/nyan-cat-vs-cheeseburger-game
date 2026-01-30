#ifndef SUPERNYANCAT_H
#define SUPERNYANCAT_H

#include "NyanCat.h"

class SuperNyanCat : public NyanCat {
public:
    SuperNyanCat(int x, int y, char symbol);

    void move() override; // Override the move method to use higher fall speed
};

#endif // SUPERNYANCAT_H
