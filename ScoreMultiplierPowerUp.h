#ifndef SCOREMULTIPLIERPOWERUP_H
#define SCOREMULTIPLIERPOWERUP_H

#include "PowerUp.h"
#include"Cheeseburger.h"
class ScoreMultiplierPowerUp : public PowerUp {
public:
    ScoreMultiplierPowerUp(int x, int y);

    void activate(Cheeseburger* player) override;
};

#endif
