#include "GameObject.h"

GameObject::GameObject(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}

bool GameObject::checkCollision(const GameObject& other) const {
    return x == other.x && y == other.y;
}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}

char GameObject::getSymbol() const {
    return symbol;
}

GameObject::~GameObject() {}
