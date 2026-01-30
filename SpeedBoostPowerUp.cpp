#include "SpeedBoostPowerUp.h"
#include <iostream>
#include"Cheeseburger.h"
SpeedBoostPowerUp::SpeedBoostPowerUp(int x, int y, char symbol, int fallSpeed)
    : PowerUp(x, y, symbol, fallSpeed, "SpeedBoost") {}

void SpeedBoostPowerUp::activate(Cheeseburger* player) {
    player->speed++; // Function body
}
