#ifndef CHEESEBURGER_H
#define CHEESEBURGER_H

#include "GameObject.h"
#include "PowerUp.h"
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include "NyanCat.h"
#include "ConsoleUtils.h"
using namespace std;

class Cheeseburger : public GameObject {
private:
    int score;
    int lives;
    bool shieldActive;
    bool scoreMultiplierActive;
    bool speedBoostActive;

public:
    int speed;
    Cheeseburger(int x, int y, char symbol, int speed, int lives);

    void draw() override;
    void move(string direction);
    void move() override;
    void collide(GameObject* other) override;
    void activatePowerUp(GameObject* other);
    void increaseScore(int points);
    void fall();
    int getLives() const;
    int getScore() const;
    int getSpeed() const;

    // Friend function declarations
    friend void displayScore(Cheeseburger* cheeseburger);
    friend void resetGame(Cheeseburger* cheeseburger);
};

#endif
