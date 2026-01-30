#ifndef GAME_H
#define GAME_H

#include "Cheeseburger.h"
#include "NyanCat.h"
#include "PowerUp.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <conio.h>

#define MAX_NYAN_CATS 10
#define MAX_POWER_UPS 10

using namespace std;

class Game {
private:
    Cheeseburger* player;
    NyanCat** nyanCats;
    int nyanCatCount;

    PowerUp** powerUps;
    int powerUpCount;

    bool isGameRunning;
    bool isPaused;
    string playerName;
    string mode;
    int speed;

public:
    // Constructor and Destructor
    Game(int speed, const string& playerName, const string& mode);
    ~Game();

    // Getter functions
    string getPlayerName() const;
    string getMode() const;
    int getSpeed() const;

    // Game functions
    void initializeGameObjects();
    void drawBorders();
    void drawGame();
    void updateGame();
    void startGame();
    void pauseGame();
};

#endif // GAME_H
