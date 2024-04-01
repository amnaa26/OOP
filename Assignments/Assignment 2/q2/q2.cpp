/*#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Character;
class Enemy;

class Weapons {
public:
    vector<string> weaponList;
    Weapons() : weaponList{"Sword", "Axe", "Bow", "Magic Staff", "Dagger", "Bankai", "Rassengan", "Enma", "Susanoo", "Fuma Shuriken", "Cards", "Samehada"} {}

    void use() {
        cout << "\nAvailable weapons:" << endl;
        for (int i = 0; i < weaponList.size(); i++) {
            cout << i + 1 << ". " << weaponList[i] << endl;
        }
        int choice;
        cout << "\nChoose a weapon to use (1-" << weaponList.size() << "): ";
        cin >> choice;
        cin.ignore();
        cout << "Using " << weaponList[choice - 1] << "...\n";
    }
};

class Player {
public:
    int playerID, health;
    string playerName;

    Player(int id, string name) : playerID(id), playerName(name), health(100) {}

    void displayInfo() {
        cout << "Player ID: " << playerID << endl;
        cout << "Player Name: " << playerName << endl;
        cout << "Health: " << health << endl;
    }
};

class Enemy : public Weapons {
public:
    int damage;
    static int randomIndex;
    Enemy(int d) : damage(d) {
        if (damage < 1 || damage > 10) {
            cout << "Invalid damage value! Setting default damage to 1.\n";
            damage = 1;
        }
    }

    void attack(Character &character);
    void use(Character &character);

};

class Character : public Player, public Weapons {
public:
    int level, points;
    string experience;
    Character(int id, string name) : Player(id, name), level(0), points(0), experience("Beginner") {}
    void levelUp() {
        points += 10;
        if (points == 10) {
            experience = "Intermediate";
            level++;
        }
        else if (points == 20) {
            experience = "Advanced";
            level++;
        }
        else if (points == 30) {
            experience = "Expert";
            level++;
        }
    }

    void playGame(Enemy &enemy);
    void displayInfo() {
        Player::displayInfo();
        cout << "Level: " << level << endl;
        cout << "Experience: " << experience << endl;
        cout << "Points: " << points << endl;
    }
};


//Implementing Enemy functions
int Enemy :: randomIndex = 0;

void Enemy::use(Character &character) {
    srand(time(NULL)); 
    int newIndex;
    newIndex = rand() % weaponList.size();
    randomIndex = newIndex;
    cout << "Enemy uses " << weaponList[randomIndex] << "...\n";
    character.health -= damage;
}

void Enemy::attack(Character &character) {
    use(character);
    cout << "Enemy attacks using " << weaponList[randomIndex] << "...\n"; 
}


//Implementing character function "playGame"
void Character::playGame(Enemy &enemy) {
    use();
    enemy.attack(*this);
    cout << "Enemy attacks back...\n";
    health -= enemy.damage;
    points += 10;
    levelUp();
}


int main() {
    cout << "\nCreator: Amna(23k-0066)" << endl;
    cout << "Creating a Gaming Environment" << endl;
    cout << "Starting the program..... " << endl;
    cout << endl;
    Character player(1, "John");
    Enemy enemy(5);

    player.displayInfo();
    cout << endl;
    enemy.attack(player);
    player.displayInfo();
    
    cout << "\nPlaying the game...\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nGame " << i+1 << ":\n";
        player.playGame(enemy);
        player.displayInfo();
    }

    return 0;
} */

/*
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Weapon {
public:
    vector<string> weaponList;
    Weapon() : weaponList{"Sword", "Axe", "Bow", "Magic Staff", "Dagger"} {}

    void use() {
        cout << "\nAvailable weapons:" << endl;
        for (int i = 0; i < weaponList.size(); i++) {
            cout << i + 1 << ". " << weaponList[i] << endl;
        }
        int choice;
        cout << "\nChoose a weapon to use (1-" << weaponList.size() << "): ";
        cin >> choice;
        cin.ignore();
        cout << "Using " << weaponList[choice - 1] << "...\n";
    }
};

class Player {
public:
    int playerID, health;
    string playerName;

    Player(int id, string name) : playerID(id), playerName(name), health(100) {}

    void displayInfo() {
        cout << "Player ID: " << playerID << endl;
        cout << "Player Name: " << playerName << endl;
        cout << "Health: " << health << endl;
    }
};

class Enemy {
public:
    int damage;
    string enemyWeapon;

    Enemy(int d) : damage(d), enemyWeapon("") {}

    void attack(Player &player);
    void use();
};

class Character : public Player, public Weapon {
public:
    int level, points;
    string experience;

    Character(int id, string name) : Player(id, name), level(0), points(0), experience("Beginner") {}

    void levelUp() {
        points += 10;
        if (points == 10) {
            experience = "Intermediate";
            level++;
        }
        else if (points == 20) {
            experience = "Advanced";
            level++;
        }
        else if (points == 30) {
            experience = "Expert";
            level++;
        }
    }

    void playGame(Enemy &enemy);
    void displayInfo() {
        Player::displayInfo();
        cout << "Level: " << level << endl;
        cout << "Experience: " << experience << endl;
        cout << "Points: " << points << endl;
    }
};

void Enemy::attack(Player &player) {
    cout << "\nEnemy attacks the player using " << enemyWeapon << "...\n";
    player.health -= damage;
    cout << "Player health decreased by " << damage << ".\n";
}

void Enemy::use() {
    cout << "\nEnter enemy's weapon: ";
    cin >> enemyWeapon;
}

void Character::playGame(Enemy &enemy) {
    use();
    enemy.attack(*this);
    cout << "\nPlayer counterattacks the enemy...\n";
    health -= 5;
    points += 10;
    levelUp();
}

int main() {
    cout << "\nCreator: Amna(23k-0066)" << endl;
    cout << "Creating a Gaming Environment" << endl;
    cout << "Starting the program..... " << endl;
    cout << endl;

    string name;
    cout << "Enter your name: ";
    cin >> name;

    Character player(1, name);
    Enemy enemy(5);

    player.displayInfo();
    cout << endl;
    enemy.use();
    enemy.attack(player);
    player.displayInfo();
    
    cout << "\nPlaying the game...\n";

    // First Round
    cout << "\nRound 1:\n";
    player.playGame(enemy);
    player.displayInfo();

    // Second Round
    cout << "\nRound 2:\n";
    enemy.damage = 3;  // Decrease enemy damage for the second round
    enemy.use();
    enemy.attack(player);
    player.playGame(enemy);
    player.displayInfo();

    // Third Round
    cout << "\nRound 3:\n";
    enemy.damage = 7;  // Increase enemy damage for the third round
    enemy.use();
    enemy.attack(player);
    player.playGame(enemy);
    player.displayInfo();

    // Fourth Round
    cout << "\nRound 4:\n";
    enemy.damage = 3;  // Decrease enemy damage for the fourth round
    enemy.use();
    enemy.attack(player);
    player.playGame(enemy);
    player.displayInfo();

    // Fifth Round
    cout << "\n 5:\n";
    enemy.damage = 5;  // Reset enemy damage for the fifth round
    enemy.use();
    enemy.attack(player);
    player.playGame(enemy);
    player.displayInfo();

    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Weapon {
public:
    vector<string> weaponList;
    Weapon() : weaponList{"Sword", "Axe", "Bow", "Magic Staff", "Dagger", "Bankai", "Rassengan", "Enma", "Susanoo", "Fuma Shuriken", "Cards", "Samehada"} {}

    string use() {
        cout << "\nAvailable weapons:" << endl;
        for (int i = 0; i < weaponList.size(); i++) {
            cout << i + 1 << ". " << weaponList[i] << endl;
        }
        int choice;
        cout << "\nChoose a weapon for the character to use (1-" << weaponList.size() << "): ";
        cin >> choice;
        cin.ignore();
        return weaponList[choice - 1];
    }
};

class Player {
public:
    int playerID, health;
    string playerName, weaponName;

    Player(int id, string name) : playerID(id), playerName(name), health(100), weaponName("") {}

    void displayInfo() {
        cout << "Player ID: " << playerID << endl;
        cout << "Player Name: " << playerName << endl;
        cout << "Health: " << health << endl;
        cout << "Weapon: " << weaponName << endl;
    }
};

class Enemy : public Weapon {
public:
    int damage, health;
    string enemyWeapon;

    Enemy(int d) : damage(d), enemyWeapon(""), health(100) {}

    void attack(Player &player) {
        cout << "\nEnemy attacks the player using " << enemyWeapon << "...\n";
        player.health -= damage;
        cout << "Player health decreased by " << damage << ".\n";
    }

    void use() {
        cout << "\nEnter enemy's weapon: ";
        int enemyChoice;
        cin >> enemyChoice;
        cin.ignore();
        enemyWeapon = weaponList[enemyChoice - 1];
    }

    void displayInfo();
};

class Character : public Player, public Weapon {
public:
    int level, points;
    string experience;

    Character(int id, string name) : Player(id, name), level(0), points(0), experience("Beginner") {}

    void levelUp() {
        points += 10;
        if (points == 20) {
            experience = "Intermediate";
            level++;
        }
        else if (points == 30) {
            experience = "Advanced";
            level++;
        }
        else if (points == 40) {
            experience = "Expert";
            level++;
        }
    }

    void playGame(Enemy &enemy);
    void displayInfo() {
        Player::displayInfo();
       // levelUp();
        cout << "Points: " << points << endl;
        cout << "Level: " << level << endl;
        cout << "Experience: " << experience << endl;
    }
};

void Character::playGame(Enemy &enemy) {
    weaponName = use();
    enemy.use();
    enemy.attack(*this);
    cout << "\nPlayer counterattacks the enemy using " << weaponName << "...\n";
    health -= 5;
    //points += 10;
    levelUp();
}

void Enemy :: displayInfo() {
        health = health - 5;
        cout << "Enemy Health: " << health << endl;
        cout << "Enemy Weapon: " << enemyWeapon << endl;
    }

int main() {
    cout << "\nCreator: Amna(23k-0066)" << endl;
    cout << "Creating a Gaming Environment" << endl;
    cout << "Starting the program..... " << endl;
    cout << endl;

    string name;
    cout << "Enter your name: ";
    cin >> name;

    Character player(1, name);
    Enemy enemy(5);

    player.displayInfo();
    cout << endl;

    cout << "\nPlaying the game...\n";

    // First Round
    cout << "\nRound 1:\n";
    player.playGame(enemy);
    player.displayInfo();
    cout << "\nEnemy Info: " << endl;
    enemy.displayInfo();

    // Second Round
    cout << "\nRound 2:\n";
    enemy.damage = 3;  // Decrease enemy damage for the second round
    player.playGame(enemy);
    player.displayInfo();
    cout << "\nEnemy Info: " << endl;
    enemy.displayInfo();

    // Third Round
    cout << "\nRound 3:\n";
    enemy.damage = 7;  // Increase enemy damage for the third round
    player.playGame(enemy);
    player.displayInfo();
    cout << "\nEnemy Info: " << endl;
    enemy.displayInfo();

    // Fourth Round
    cout << "\nRound 4:\n";
    enemy.damage = 3;  // Decrease enemy damage for the fourth round
    player.playGame(enemy);
    player.displayInfo();
    cout << "\nEnemy Info: " << endl;
    enemy.displayInfo();

    return 0;
}
