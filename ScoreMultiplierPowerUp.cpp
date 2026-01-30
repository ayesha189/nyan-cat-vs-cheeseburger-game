#include "ScoreMultiplierPowerUp.h"
#include <iostream>
#include"Cheeseburger.h"
ScoreMultiplierPowerUp::ScoreMultiplierPowerUp(int x, int y)
    : PowerUp(x, y, 'M', 1, "ScoreMultiplier") {}

void ScoreMultiplierPowerUp::activate(Cheeseburger* player) { player->increaseScore(5); }
