#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Pet{
private:
    string name;
    int age;

public:
    Pet(string n, int a) : name(n), age(a) {}
    virtual void makeSound() = 0;
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Cat : public Pet<void>{
public:
    Cat(string name, int age) : Pet(name, age) {}
    void makeSound(){
        cout << "Sound: Meow" << endl;
    }
};

class Dog : public Pet<void>{
public:
    Dog(string name, int age) : Pet(name, age) {}
    void makeSound(){
        cout << "Sound: Woof" << endl;
    }
};

class Bird : public Pet<void> {
public:
    Bird(string name, int age) : Pet(name, age) {}
    void makeSound(){
        cout << "Sound: Chirp" << endl;
    }
};


int main(){
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    Cat cat("Misty", 2);
    Dog dog("Casper", 5);
    Bird bird("Tweety", 2);

    //Interacting with pets using polymorphism
    Pet<void>* pets[] = {&cat, &dog, &bird};

    // Display each pet's information and make them produce their unique sound
    for (auto pet : pets) {
        pet->display();
        pet->makeSound();
        cout << endl;
    }

}