#include "NyanCat.h"

NyanCat::NyanCat(int x, int y, char symbol, int fallSpeed, bool isVisible)
    : GameObject(x, y, symbol), fallSpeed(fallSpeed), isVisible(isVisible) {}

void NyanCat::draw() {
    if (isVisible) {
        cout << "\033[" << y + 1 << ";" << x + 1 << "H" << symbol;
    }
}

void NyanCat::move() {
    y += fallSpeed;
    if (y >= GRID_HEIGHT) {
        y = 0;
        x = rand() % (GRID_WIDTH - 2) + 1; // Prevent NyanCats from spawning near borders
        isVisible = rand() % 2;           // Random visibility (50% chance)
    }
}

void NyanCat::collide(GameObject* other) {
    // No specific collision logic yet
}

void NyanCat::fall() {
    y += fallSpeed;
    if (y >= GRID_HEIGHT) {
        y = 0;
        x = rand() % GRID_WIDTH;
        isVisible = rand() % 2; // Random visibility (50% chance)
    }
}
