#include <iostream>
#include <string>
using namespace std;

class Position{
public:
    float x, y, z;
    Position(float x, float y, float z) : x(x), y(y), z(z){
    }
    void displayPosition() {
        cout << "Position: " << endl;
        cout << " x: " << x << "\n y: " << y << "\n z: " << z << endl;
    }
};

class Health{
public:
    double health;
    Health(double health) : health(health){
    }
    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};

class Character : public Position, public Health{
public:
    string name; int level;
    Character(float x, float y, float z, int health, string name, int level) : Position(x, y, z), Health(health), name(name), level(level) {}
    void display(){
        cout << "Character Name: " << name << endl;
        cout << "Character Level: " << level << endl;
        displayPosition();
        displayHealth();
    }
};

int main(){
    Character character(10.5f, 20.3f, 5.0f, 100, "Hero", 10);
    character.display();
}