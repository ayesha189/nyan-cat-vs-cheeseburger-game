#include "MegaNyanCat.h"
#include"NyanCat.h"

MegaNyanCat::MegaNyanCat(int x, int y, char symbol)
    : NyanCat(x, y, symbol, 3) {} // Mega NyanCat has the highest fall speed

void MegaNyanCat::move() {
    fall(); // Calls the fall method from NyanCat with maximum speed
}
