/* 
 * Creator: Amna(23k-0066)
 * Desc: Write a program that uses composition to implement a game engine. A game engine is madeup of several 
         components. For example:
	 a) Graphics rendering engine
	 b) Input handler
	 c) Physics engine
*/


#include <iostream>
using namespace std;

class GraphicsRenderingEngine {
public:
    void render() {
        cout << "Graphics rendering..." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Handling input..." << endl;
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() {
        cout << "Simulating physics..." << endl;
    }
};

class GameEngine {
private:
    GraphicsRenderingEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void start() {
        graphicsEngine.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        cout << "Game started!" << endl;
    }
};

int main() {
    GameEngine game;
    game.start();

    return 0;
}
