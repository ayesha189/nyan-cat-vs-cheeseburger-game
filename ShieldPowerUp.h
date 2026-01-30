#ifndef SHIELDPOWERUP_H
#define SHIELDPOWERUP_H

#include "PowerUp.h"

class Cheeseburger; // Forward declaration of Cheeseburger class

class ShieldPowerUp : public PowerUp {
public:
    ShieldPowerUp(int x, int y);

    void activate(Cheeseburger* player) override;
};

#endif // SHIELDPOWERUP_H
