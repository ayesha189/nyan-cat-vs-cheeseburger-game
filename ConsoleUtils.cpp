#include "ConsoleUtils.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<thread>
#include<chrono>
#include<windows.h>
#include<fstream>
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
#include"Game.h"
#include<sstream>
#include<stdexcept>
string filename = "score.txt";
Score* loadScores(int& count) {
    Score* scores = nullptr;
    count = 0;

    try {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Failed to open high scores file.");
        }

        // First, count valid lines to determine the number of scores
        string line;
        int validCount = 0;

        while (getline(file, line)) {
            // Check if line contains both "Player: " and " | Score: "
            int playerPos = line.find("Player: ");
            int scorePos = line.find(" | Score: ");
            if (playerPos != -1 && scorePos != -1) {
                ++validCount;
            }
        }

        if (validCount == 0) {
            throw runtime_error("No valid scores found in the file.");
        }

        // Reset the file stream to the beginning
        file.clear();
        file.seekg(0, ios::beg);

        // Allocate memory for valid scores
        scores = new Score[validCount];
        count = validCount;

        // Read the file again to store valid scores
        int index = 0;
        while (getline(file, line)) {
            int playerPos = line.find("Player: ");
            int scorePos = line.find(" | Score: ");
            if (playerPos != -1 && scorePos != -1) {
                // Extract player name and score
                string playerName = line.substr(playerPos + 8, scorePos - (playerPos + 8));
                string scoreStr = line.substr(scorePos + 9);

                // Trim any extra spaces from player name
                playerName.erase(0, playerName.find_first_not_of(' '));
                playerName.erase(playerName.find_last_not_of(' ') + 1);

                int score = stoi(scoreStr); // Convert score to integer

                scores[index].playerName = playerName;
                scores[index].score = score;
                ++index;
            }
        }

        file.close();
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        delete[] scores; // Clean up allocated memory
        scores = nullptr;
        count = 0;
    }
    catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
        delete[] scores; // Clean up allocated memory
        scores = nullptr;
        count = 0;
    }
    catch (...) {
        cerr << "An unknown error occurred while loading scores." << endl;
        delete[] scores;
        scores = nullptr;
        count = 0;
    }

    return scores;
}


void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Score::bubbleSort(Score scores[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (scores[j].score < scores[j + 1].score) {
                swap(scores[j], scores[j + 1]);
            }
        }
    }
}

void restart() {
    setConsoleColor(15);
    cout << "Choose Mode:\n";
    cout << "1. Easy\n";
    cout << "2. Hard\n";
    cout << "Enter your choice: \n";
    char modeChoice = _getch();
    cin >> modeChoice;
    int speed = (modeChoice == '2') ? 2 : 1;
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    Game game(speed, playerName, (modeChoice == '2') ? "Hard" : "Easy");
    game.startGame();
}

int me::menu() {
    int i = 0;
    while (true) {
        if (i != 0) system("pause");
        system("cls");
        cout << "#############################\n";
        cout << "#       NYAN CAT GAME       #\n";
        cout << "#############################\n";
        cout << "1. Start Game\n";
        cout << "2. Instructions\n";
        cout << "3. View High Scores\n";
        cout << "4. About Us\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: \n";

        char choice = _getch();
        switch (choice) {
        case '1': {
            cout << "Choose Mode:\n";
            cout << "1. Easy\n";
            cout << "2. Hard\n";
            cout << "Enter your choice: \n";

            char modeChoice;
            modeChoice = _getch(); // or use cin >> modeChoice, but not both

            int speed = (modeChoice == '2') ? 2 : 1; // Set speed for hard mode
            cout << "Enter your name: ";
            string playerName;
            cin >> playerName;

            // Assuming Game constructor and restart() are safe from memory issues
            Game game(speed, playerName, (modeChoice == '2') ? "Hard" : "Easy");
            game.startGame();

            // After game ends, ask if the user wants to restart
            char playAgain = 'n'; // Initialize it to 'n' by default
            do {
                cout << "Game Over! Would you like to play again? (y/n): ";
                cin >> playAgain;

                if (playAgain == 'y' || playAgain == 'Y') {
                    system("cls"); // Clear screen before restarting
                    restart();
                }
                else if (playAgain == 'n' || playAgain == 'N') {
                    cout << "Exiting game.\n";
                    return 0; // Exit the game
                }
                else {
                    cout << "Invalid choice. Please enter again (y/n):\n";
                }
            } while (playAgain != 'n' && playAgain != 'N'); // Continue only if user doesn't enter 'n' or 'N'

            break;
        }

        case '2': {
            cout << "Instructions:\n";
            cout << "1. Use 'A' and 'D' to move left and right.\n";
            cout << "2. Avoid falling NyanCats to stay alive.\n";
            cout << "3. Collect power-ups to boost your score or gain abilities.\n";
            cout << "4. Press 'P' to pause the game.\n";
            break;
        }
        case '3': {
            // View High Scores
            int count = 0;
            Score* scores = loadScores(count); // loadScores now returns a dynamically allocated array

            if (scores == nullptr) {
                cout << "No scores to display." << endl;
             
            }
            if (scores != nullptr) {
                scores->bubbleSort(scores, count);
                cout << "High Scores:\n";
                for (int i = 0; i < 5 && i < count; i++) {
                    cout << scores[i].playerName << " - " << scores[i].score << " (" << scores[i].mode << ")\n";
                }
            }
            delete[] scores;
            break;
        }
        case '4': {
            cout << "About Us:\n";
            cout << "This game is developed as a fun project to demonstrate C++ skills.\n";
            cout << "Enjoy the game and try to top the leaderboard!\n";
            break;
        }
        case '5':
            exit(1); // Exit the program
        }
        i++;
    }
}