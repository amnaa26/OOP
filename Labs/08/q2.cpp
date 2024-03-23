#include <iostream>
#include <string>
using namespace std;

class Character{
public:
    int health, damage;
    Character(int health, int damage) : health(health), damage(damage){
    }

    void display(){
        cout << "Character's Details: " << endl;
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};

class Enemy : public Character{
public:
    Enemy(int health, int damage) : Character(health, damage){
    }

    void display(){
        cout << "Enemy's Details: " << endl;
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};

class Player : public Character{
public:
    Player(int health, int damage) : Character(health, damage){
    }

    void display(){
        cout << "Player's Details: " << endl;
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};

class Wizard : public Player{
public:
    int magicPowers; string spells;
     Wizard(int power, string spell, int health, int damage) : Player(health, damage), magicPowers(power), spells(spell){
    }

    void display(){
        cout << "Wizard's Details: " << endl;
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
        cout << "Magic Power: " << magicPowers << endl;
        cout << "Spell: " << spells << endl;
    }
};

int main(){
    Wizard wizard(75, "Fireball, Lightning Bolt", 100, 50);
    wizard.display(); 
}
