#include "Cheeseburger.h"
#include"Friend.h"

Cheeseburger::Cheeseburger(int x, int y, char symbol, int speed, int lives)
    : GameObject(x, y, symbol), speed(speed), score(0), lives(lives),
    shieldActive(false), scoreMultiplierActive(false), speedBoostActive(false) {}

void Cheeseburger::draw() {
    cout << "\033[" << y + 1 << ";" << x + 1 << "H" << symbol;
}

void Cheeseburger::move(string direction) {
    if (direction == "left" && x > 0)
        x -= speed;
    else if (direction == "right" && x < GRID_WIDTH - 1) 
        x += speed;
}

void Cheeseburger::move() {}

void Cheeseburger::collide(GameObject* other) {
    if (!other) return;

    char symbol = other->getSymbol();
    if (symbol == 'N' || symbol == 'S' || symbol == 'G') {
        setConsoleColor(2); // Handle collision with NyanCats
        if (shieldActive) {
            shieldActive = false;
            cout << "Shield absorbed the hit! Lives remain: " << lives << "\n";
        }
        else {
            lives--;
            cout << "Hit by " << symbol << "! Lives left: " << lives << "\n";
        }
    }
    else if (symbol == 'P') {
        setConsoleColor(3);
        string type = static_cast<PowerUp*>(other)->getType();
        if (type == "Shield") {
            shieldActive = true;
            cout << "Shield activated! You are protected for one hit.\n";
        }
    }
}

void Cheeseburger::activatePowerUp(GameObject* other) {
    char symbol = other->getSymbol();
    if (symbol == 'P') {
        setConsoleColor(3);
        string type = static_cast<PowerUp*>(other)->getType();
        if (type == "Shield") {
            shieldActive = true;
            cout << "Shield activated! You are protected for one hit.\n";
        }
    }
    else if (symbol == 'B') {
        setConsoleColor(4);
        speed += 2;
        cout << "Speed boost activated! Speed increased by 2.\n";
        thread([this]() {
            this_thread::sleep_for(chrono::seconds(5));
            speed -= 2;
            cout << "Speed boost ended.\n";
            }).detach();
    }
    else if (symbol == 'M') {
        setConsoleColor(1);
        score *= 10;
        cout << "Score multiplier activated! Score multiplied by 10.\n";
    }
}

void Cheeseburger::increaseScore(int points) {
    score += points;
}

int Cheeseburger::getLives() const {
    return lives;
}

int Cheeseburger::getScore() const {
    return score;
}

int Cheeseburger::getSpeed() const {
    return speed;
}
void Cheeseburger::fall() {
    int isVisible, fallSpeed = 1;
    y += fallSpeed;
    if (y >= GRID_HEIGHT) {
        y = 0;
        x = rand() % GRID_WIDTH;
        // Randomly determine visibility (50% chance)
        isVisible = rand() % 2;
    }
}
void displayScore(Cheeseburger* cheeseburger) {
    cout << "Player's score: " << cheeseburger->score << endl;
}
// Friend function to reset the game
void resetGame(Cheeseburger* cheeseburger) {
    cheeseburger->score = 0;
    cheeseburger->lives = 3; // Reset to default lives
    cheeseburger->shieldActive = false;
    cheeseburger->scoreMultiplierActive = false;
    cheeseburger->speedBoostActive = false;
    cout << "Game has been reset. Score: " << cheeseburger->score << ", Lives: " << cheeseburger->lives << endl;
}