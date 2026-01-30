#ifndef SPEEDBOOSTPOWERUP_H
#define SPEEDBOOSTPOWERUP_H

#include "PowerUp.h"

class Cheeseburger; // Forward declaration of Cheeseburger class

class SpeedBoostPowerUp : public PowerUp {
public:
    SpeedBoostPowerUp(int x, int y, char symbol, int fallSpeed);

    void activate(Cheeseburger* player) override;
};

#endif // SPEEDBOOSTPOWERUP_H
