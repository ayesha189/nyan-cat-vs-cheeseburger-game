#include "Game.h"
#include"Score.h"
#include"GameObject.h"
#include"NyanCat.h"
#include"SuperNyanCat.h"
#include"MegaNyanCat.h"
#include"PowerUp.h"
#include"ShieldPowerUp.h"
#include"ScoreMultiplierPowerUp.h"
#include"SpeedBoostPowerUp.h"
#include"Cheeseburger.h"

//const string filename = "score.txt";
Game::Game(int speed, const string& playerName, const string& mode)
    : player(nullptr), nyanCats(nullptr), nyanCatCount(0),
    powerUps(nullptr), powerUpCount(0), isGameRunning(true),
    isPaused(false), playerName(playerName), mode(mode), speed(speed) {

    // Initialize the player
    player = new Cheeseburger(20, 19, 'C', 1, 3);

    // Allocate memory for nyanCats and powerUps arrays
    nyanCats = new NyanCat * [MAX_NYAN_CATS];
    powerUps = new PowerUp * [MAX_POWER_UPS];
}

Game::~Game() {
    // Clean up dynamically allocated memory
    delete player;

    for (int i = 0; i < nyanCatCount; ++i) {
        delete nyanCats[i];
    }
    delete[] nyanCats;

    for (int i = 0; i < powerUpCount; ++i) {
        delete powerUps[i];
    }
    delete[] powerUps;
}

string Game::getPlayerName() const { return playerName; }
string Game::getMode() const { return mode; }
int Game::getSpeed() const { return speed; }

void Game::initializeGameObjects() {
    try {
        if (powerUpCount == 0) {
            powerUps = new PowerUp * [MAX_POWER_UPS];
            for (int i = 0; i < powerUpCount; i++) {
                int randomType = rand() % 3; // Assuming 3 types of power-ups
                if (randomType == 0)
                    powerUps[i] = new ShieldPowerUp(rand() % GRID_WIDTH, rand() % GRID_HEIGHT);
                else if (randomType == 1)
                    powerUps[i] = new ScoreMultiplierPowerUp(rand() % GRID_WIDTH, rand() % GRID_HEIGHT);
                else
                    powerUps[i] = new SpeedBoostPowerUp(rand() % GRID_WIDTH, rand() % GRID_HEIGHT, 'B', 1);
            }
        }
    }
    catch (const exception& e) {
        cout << "Error initializing game objects: " << e.what() << endl;
    }
}

void Game::drawBorders() {
    cout << "##########################################\n";
    for (int i = 0; i < GRID_HEIGHT; i++) {
        cout << "#";
        for (int j = 0; j < GRID_WIDTH; j++) {
            cout << " ";
        }
        cout << "#\n";
    }
    cout << "##########################################\n";
    cout << "Level: "
        << (player->getScore() >= 200 ? "3 (Mega Nyan Cat)" :
            (player->getScore() >= 100 ? "2 (Super Nyan Cat)" : "1 (Regular Nyan Cat)"))
        << " Score: ";
    displayScore(player);
    cout << " Lives: " << player->getLives() << endl;

    cout << "\nActive Power-Ups:\n";
    if (player->getSpeed() > 1) cout << "- Speed Boost Active\n";
   // if (player->getLives()) cout << "- Shield Active\n";
    if (player->getScore() % 10 == 0 && player->getScore() != 0) cout << "- Score Multiplier Active\n";
}

void Game::drawGame() {
    system("cls");
    drawBorders();
    for (int i = 0; i < nyanCatCount; ++i) {
        nyanCats[i]->draw();
    }
    for (int i = 0; i < powerUpCount; ++i) {
        powerUps[i]->draw();
    }
    player->draw();
}

void Game::updateGame() {
    player->increaseScore(1);

    static int currentLevel = 1;

    if (player->getScore() >= 500 && currentLevel < 3) {
        currentLevel = 3;
        nyanCats[nyanCatCount++] = new NyanCat(rand() % 25, 0, 'G', 4, true);
    }
    else if (player->getScore() >= 200 && player->getScore() < 500 && currentLevel < 2) {
        currentLevel = 2;
        nyanCats[nyanCatCount++] = new NyanCat(rand() % 20, 0, 'S', 2, true);
    }
    else if (currentLevel == 1) {
        if (nyanCatCount < MAX_NYAN_CATS + player->getScore() / 50) {
            nyanCats[nyanCatCount++] = new NyanCat(rand() % GRID_WIDTH, 0, 'N', 1, false);
        }
        if (powerUpCount < MAX_POWER_UPS + player->getScore() / 100) {
            int randomType = rand() % 3;
            if (randomType == 0)
                powerUps[powerUpCount++] = new ShieldPowerUp(rand() % GRID_WIDTH, 0);
            else if (randomType == 1)
                powerUps[powerUpCount++] = new ScoreMultiplierPowerUp(rand() % GRID_WIDTH, 0);
            else
                powerUps[powerUpCount++] = new SpeedBoostPowerUp(rand() % GRID_WIDTH, 0, 'B', 1);
        }
    }

    for (int i = 0; i < nyanCatCount; ++i) {
        nyanCats[i]->move();
    }

    for (int i = 0; i < powerUpCount; ++i) {
        powerUps[i]->move();
    }

    for (int i = 0; i < nyanCatCount; ++i) {
        if (nyanCats[i]->getX() == player->getX() && nyanCats[i]->getY() == player->getY()) {
            player->collide(nyanCats[i]);
        }
    }

    for (int i = 0; i < powerUpCount; ++i) {
        if (powerUps[i]->getX() == player->getX() && powerUps[i]->getY() == player->getY()) {
            player->activatePowerUp(powerUps[i]);
        }
    }

    if (player->getLives() <= 0) {
        isGameRunning = false;

        for (int i = 0; i < nyanCatCount; ++i) {
            delete nyanCats[i];
            nyanCats[i] = nullptr;
        }

        for (int i = 0; i < powerUpCount; ++i) {
            delete powerUps[i];
            powerUps[i] = nullptr;
        }

        nyanCatCount = 0;
        powerUpCount = 0;
    }
}

void Game::startGame() {
    try {
        while (isGameRunning) {
            if (_kbhit()) {
                char move = _getch();
                if (move == 'a') player->move("left");
                if (move == 'd') player->move("right");
                if (move == 'p' || move == 'P') {
                    isPaused = true;
                    pauseGame();
                }
            }

            if (!isPaused) {
                drawGame();
                updateGame();
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }

        cout << "\n\n\n\n\nGame Over! Final Score: " << player->getScore() << endl;

        ofstream outFile("score.txt", ios::app);
        if (!outFile.is_open()) {
            throw runtime_error("Error: Unable to open file!");
        }

        outFile << "Player: " << playerName <<" | Score: " << player->getScore() << endl;
        outFile.close();
    }
    catch (const exception& e) {
        cout << "Error occurred: " << e.what() << endl;
    }
}

void Game::pauseGame() {
    char input;
    while (isPaused) {
        cout << "Game Paused. Press 'r' to resume or 'q' to quit: ";
        input = _getch();
        if (input == 'r' || input == 'R') {
            isPaused = false;
        }
        else if (input == 'q' || input == 'Q') {
            isGameRunning = false;
            break;
        }
    }
}
