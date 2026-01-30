#include "ShieldPowerUp.h"
#include <iostream>
#include"Cheeseburger.h"

ShieldPowerUp::ShieldPowerUp(int x, int y)
    : PowerUp(x, y, 'P', 1, "Shield") {}

void ShieldPowerUp::activate(Cheeseburger* player) { player->collide(this); }
//void ShieldPowerUp::activate(Cheeseburger* player) {}
