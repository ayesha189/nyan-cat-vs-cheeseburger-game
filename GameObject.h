#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
    int x, y;
    char symbol;

public:
    GameObject(int x, int y, char symbol);
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual void collide(GameObject* other) = 0;
    bool checkCollision(const GameObject& other) const;

    int getX() const;
    int getY() const;
    char getSymbol() const;

    virtual ~GameObject();
};

#endif // GAMEOBJECT_H
