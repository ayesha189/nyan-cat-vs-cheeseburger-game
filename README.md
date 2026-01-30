# Nyan Cat vs Cheeseburger 🐱🍔

A fun, console-based C++ game demonstrating Object-Oriented Programming concepts. Control a cheeseburger character to dodge falling Nyan Cats, collect power-ups, and achieve the highest score!

## 🎯 Overview

**Nyan Cat vs Cheeseburger** is an arcade-style survival game where you play as a brave Cheeseburger trying to survive against waves of falling Nyan Cats. The game progressively becomes more challenging as your score increases, introducing faster and more dangerous enemies.

### Game Objective

- **Survive**: Dodge falling Nyan Cats to stay alive
- **Collect**: Grab power-ups to gain advantages
- **Score High**: The longer you survive, the higher your score
- **Progress**: Reach new difficulty levels with different types of Nyan Cats

### Built With

- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Platform**: Windows Console Application
- **IDE**: Visual Studio

## ✨ Game Features

### Core Gameplay
- ✅ Real-time character movement (left, right, down)
- ✅ Three lives system with game over condition
- ✅ Progressive difficulty levels (Regular, Super, Mega Nyan Cats)
- ✅ Score tracking and high score saving
- ✅ Pause/Resume functionality
- ✅ Console-based graphics with colorful ASCII art

### Power-Up System
- 🛡️ **Shield Power-Up**: Temporary invincibility
- ⚡ **Speed Boost**: Increased movement speed
- ✨ **Score Multiplier**: Bonus points for a limited time

### Enemy Types
- 🐱 **Regular Nyan Cat**: Basic falling enemy (Level 1)
- 🦸 **Super Nyan Cat**: Faster falling speed (Level 2, Score ≥ 100)
- 💪 **Mega Nyan Cat**: Extremely fast (Level 3, Score ≥ 200)

## 🎓 OOP Concepts Implemented

This project demonstrates comprehensive understanding of Object-Oriented Programming:

### 1. **Inheritance**
```
GameObject (Base Class)
    ├── NyanCat
    │   ├── SuperNyanCat
    │   └── MegaNyanCat
    ├── Cheeseburger (Player)
    └── PowerUp (Abstract)
        ├── ShieldPowerUp
        ├── ScoreMultiplierPowerUp
        └── SpeedBoostPowerUp
```

### 2. **Polymorphism**
- **Virtual Functions**: `draw()`, `move()`, `collide()` are overridden in derived classes
- **Abstract Classes**: PowerUp class with pure virtual `activate()` method
- **Runtime Polymorphism**: Different behaviors for each enemy and power-up type

### 3. **Encapsulation**
- Private member variables with public getter/setter methods
- Protected members for inheritance hierarchy
- Information hiding in Game, Player, and Enemy classes

### 4. **Abstraction**
- GameObject abstract base class defines interface
- PowerUp abstract class for power-up system
- Clean separation between interface and implementation

### 5. **Friend Functions**
- `displayScore()`: Friend function to access private score
- `resetGame()`: Friend function to reset player state

### 6. **Dynamic Memory Management**
- Dynamic arrays for NyanCats and PowerUps
- Proper memory allocation and deallocation in constructor/destructor
- Pointer management for game objects

### 7. **Exception Handling**
- Try-catch blocks for game object initialization
- Error handling for file operations (score saving)
- Graceful error recovery

## 🎮 Game Mechanics

### Lives System
- Player starts with **3 lives**
- Collision with Nyan Cat = **-1 life**
- Game ends when lives reach **0**

### Scoring System
- **+10 points** for each Nyan Cat that falls past you
- **Bonus multiplier** when Score Multiplier power-up is active
- Score determines difficulty level and enemy type

### Difficulty Progression
| Score Range | Level | Enemy Type | Fall Speed |
|-------------|-------|------------|------------|
| 0 - 99 | 1 | Regular Nyan Cat | Slow |
| 100 - 199 | 2 | Super Nyan Cat | Medium |
| 200+ | 3 | Mega Nyan Cat | Fast |

## 📁 Project Structure

```
Project1/
├── Source Files (.cpp)
│   ├── Source.cpp              # Main entry point
│   ├── Game.cpp                # Game logic and loop
│   ├── GameObject.cpp          # Base class implementation
│   ├── Cheeseburger.cpp        # Player class
│   ├── NyanCat.cpp            # Base enemy class
│   ├── SuperNyanCat.cpp       # Level 2 enemy
│   ├── MegaNyanCat.cpp        # Level 3 enemy
│   ├── PowerUp.cpp            # Base power-up class
│   ├── ShieldPowerUp.cpp      # Shield implementation
│   ├── ScoreMultiplierPowerUp.cpp  # Multiplier implementation
│   ├── SpeedBoostPowerUp.cpp  # Speed boost implementation
│   ├── Friend.cpp             # Friend functions
│   └── ConsoleUtils.cpp       # Console utilities
│
├── Header Files (.h)
│   ├── Game.h
│   ├── GameObject.h
│   ├── Cheeseburger.h
│   ├── NyanCat.h
│   ├── SuperNyanCat.h
│   ├── MegaNyanCat.h
│   ├── PowerUp.h
│   ├── ShieldPowerUp.h
│   ├── ScoreMultiplierPowerUp.h
│   ├── SpeedBoostPowerUp.h
│   ├── Score.h
│   ├── Friend.h
│   └── ConsoleUtils.h
│
├── Data Files
│   └── score.txt              # High score storage
│
└── Project Files
    ├── Project1.vcxproj
    └── Project1.vcxproj.filters
```

## 🏗️ Class Hierarchy

### GameObject (Abstract Base Class)
```cpp
class GameObject {
protected:
    int x, y;           // Position
    char symbol;        // Display character
public:
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual void collide(GameObject* other) = 0;
    bool checkCollision(const GameObject& other) const;
};
```

### Cheeseburger (Player)
```cpp
class Cheeseburger : public GameObject {
private:
    int score;
    int lives;
    bool shieldActive;
    bool scoreMultiplierActive;
    bool speedBoostActive;
public:
    void move(string direction);
    void activatePowerUp(GameObject* other);
    void increaseScore(int points);
    friend void displayScore(Cheeseburger* player);
};
```

### NyanCat (Enemy Base)
```cpp
class NyanCat : public GameObject {
protected:
    int fallSpeed;
    bool isVisible;
public:
    virtual void fall();
};
```

### PowerUp (Abstract)
```cpp
class PowerUp : public GameObject {
protected:
    string type;
    int fallSpeed;
public:
    virtual void activate(Cheeseburger* player) = 0;
};
```

## 💻 Installation & Compilation

### Prerequisites
- **Windows OS**
- **Visual Studio 2019 or later** (with C++ development tools)
- **C++11 or higher**

### Setup Instructions

1. **Clone the Repository**
```bash
git clone https://github.com/yourusername/nyan-cat-vs-cheeseburger.git
cd nyan-cat-vs-cheeseburger
```

2. **Open in Visual Studio**
   - Double-click `Project1.vcxproj` to open in Visual Studio
   - Or open Visual Studio → File → Open → Project/Solution

3. **Build the Project**
   - Press `Ctrl + Shift + B` or
   - Build → Build Solution

4. **Run the Game**
   - Press `F5` to run with debugging
   - Or `Ctrl + F5` to run without debugging

### Alternative: Command Line Compilation
```bash
# Navigate to project directory
cd Project1

# Compile all source files
cl /EHsc Source.cpp Game.cpp GameObject.cpp Cheeseburger.cpp NyanCat.cpp SuperNyanCat.cpp MegaNyanCat.cpp PowerUp.cpp ShieldPowerUp.cpp ScoreMultiplierPowerUp.cpp SpeedBoostPowerUp.cpp Friend.cpp ConsoleUtils.cpp /Fe:game.exe

# Run the game
game.exe
```

## 🎮 How to Play

### Starting the Game
1. Run the executable
2. Enter your player name
3. Select game mode (if applicable)
4. Choose difficulty/speed setting

### Controls
| Key | Action |
|-----|--------|
| `A` or `←` | Move Left |
| `D` or `→` | Move Right |
| `S` or `↓` | Move Down |
| `P` | Pause/Resume |
| `ESC` | Exit Game |

### Game Rules
1. **Dodge the Nyan Cats** falling from the top
2. **Collect Power-Ups** (marked with special symbols) to gain advantages
3. **Survive as long as possible** to increase your score
4. **Watch your lives** - you only have 3!
5. **Beat your high score** - it's saved between sessions

## 🎁 Power-Ups

### 🛡️ Shield Power-Up
- **Symbol**: `S`
- **Effect**: Makes you invincible for 5 seconds
- **Behavior**: Nyan Cats pass through without damage
- **Visual**: Shield icon displayed when active

### ⚡ Speed Boost
- **Symbol**: `B`
- **Effect**: Increases movement speed by 50%
- **Duration**: 8 seconds
- **Use**: Better maneuverability to dodge enemies

### ✨ Score Multiplier
- **Symbol**: `M`
- **Effect**: Doubles all points earned
- **Duration**: 10 seconds
- **Strategy**: Best used at higher levels for maximum points

## 🏆 Scoring System

### Points Breakdown
```
Regular Nyan Cat dodged:      +10 points
Super Nyan Cat dodged:        +10 points
Mega Nyan Cat dodged:         +10 points

With Score Multiplier active: ×2 multiplier
```

### Level Thresholds
```
Level 1 (Regular):    0 - 99 points
Level 2 (Super):      100 - 199 points
Level 3 (Mega):       200+ points
```

### High Score
- High scores are saved to `score.txt`
- Persistent across game sessions
- Displayed at game over screen

## 📸 Screenshots

```
##########################################
#                                        #
#              🐱 💨                    #
#                                        #
#                     🐱 💨             #
#                                        #
#       ⚡                               #
#                                        #
#                🍔                      #
##########################################
Level: 2 (Super Nyan Cat)  Score: 150
Lives: ❤️❤️❤️
```

## 🔧 Technical Details

### Key Features Implementation

#### Collision Detection
```cpp
bool GameObject::checkCollision(const GameObject& other) const {
    return (x == other.x && y == other.y);
}
```

#### Dynamic Enemy Spawning
- Random X-position generation
- Progressive difficulty based on score
- Multiple enemies simultaneously

#### Memory Management
```cpp
// Constructor - Dynamic allocation
nyanCats = new NyanCat*[MAX_NYAN_CATS];
powerUps = new PowerUp*[MAX_POWER_UPS];

// Destructor - Proper cleanup
for (int i = 0; i < nyanCatCount; ++i) {
    delete nyanCats[i];
}
delete[] nyanCats;
```

#### File I/O
- High score persistence using `fstream`
- Score reading at game start
- Score writing at game over

### Performance Considerations
- Frame-rate control using `std::this_thread::sleep_for()`
- Efficient console clearing and redrawing
- Optimized collision detection (O(n) where n is enemy count)

## 🚀 Future Enhancements

### Planned Features
- [ ] Multiple difficulty modes (Easy, Medium, Hard)
- [ ] Boss battles at certain score thresholds
- [ ] More power-up types (Time Slow, Extra Life, Magnet)
- [ ] Leaderboard system with multiple player scores
- [ ] Sound effects and background music
- [ ] Graphics upgrade using SFML or SDL
- [ ] Multiplayer mode (competitive or co-op)
- [ ] Customizable player characters
- [ ] Achievement system
- [ ] Save/Load game state

### Technical Improvements
- [ ] Better collision detection (bounding boxes)
- [ ] Improved rendering (double buffering)
- [ ] Cross-platform compatibility (Linux/Mac)
- [ ] Configuration file for game settings
- [ ] Smoother animations
- [ ] Particle effects for collisions


## 📝 License

Educational university project — free to use and modify for learning purposes.

---

## 📧 Contact
**Ayesha Rauf** — [@ayesha189](https://github.com/ayesha189)  
**Project Link**: [https://github.com/ayesha189/nyan-cat-vs-cheeseburger-game]

---


## 🙏 Acknowledgments

- Inspired by classic arcade games
- Nyan Cat meme for the awesome enemies
- Object-Oriented Programming course materials
- Visual Studio for the excellent C++ development environment
- Our professor/instructor for guidance

---

## 📝 Assignment Details

**Course**: Object-Oriented Programming (OOP)  
**Project Type**: Final Project  

### Learning Outcomes Demonstrated
✅ Class design and implementation  
✅ Inheritance and polymorphism  
✅ Abstract classes and interfaces  
✅ Dynamic memory management  
✅ Friend functions  
✅ Exception handling  
✅ File I/O operations  
✅ Console application development  

---

## ⭐ Support
---
⭐ **If you enjoyed playing this game or found the code helpful, please consider giving it a star!**

🎮 **Happy Gaming!** 🍔🐱💨
