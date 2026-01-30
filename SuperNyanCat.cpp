#include "SuperNyanCat.h"
#include"NyanCat.h"
SuperNyanCat::SuperNyanCat(int x, int y, char symbol)
    : NyanCat(x, y, symbol, 2) {} // Super NyanCat has a higher fall speed

void SuperNyanCat::move() {
    fall(); // Calls the fall method with higher speed
}
