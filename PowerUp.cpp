#include "PowerUp.h"
#include"NyanCat.h"
PowerUp::PowerUp(int x, int y, char symbol, int fallSpeed, string type)
    : GameObject(x, y, symbol), fallSpeed(fallSpeed), type(type) {}

void PowerUp::move() {
    y += fallSpeed;
    if (y >= GRID_HEIGHT) {
        y = 0;
        x = rand() % GRID_WIDTH;
    }
}

void PowerUp::draw() {
    cout << "\033[" << y + 1 << ";" << x + 1 << "H" << symbol;
}

void PowerUp::collide(GameObject* other) {
    // No specific collision behavior defined yet
}

string PowerUp::getType() const {
    return type;
}
