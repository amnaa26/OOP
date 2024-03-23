#include <iostream>
#include <string>
using namespace std;

class Book{
public:
	string title, author, publisher;
	Book(string title, string author, string publisher){
		this -> title = title;
		this -> author = author;
		this -> publisher = publisher;
	}
	
	void display(){
		cout << "Book Details: " << endl;
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Publisher: "  << publisher << endl;
	}
};

class FictionBook : public Book{
public:
    string genre, protagonist;
    FictionBook(string genre, string protagonist, string title, string author, string publisher)
        : Book(title, author, publisher), genre(genre), protagonist(protagonist) {
    }
    void displayFunction(){
        display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};


int main() {
    FictionBook book("Fantasy", "Harry Potter", "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Scholastic");
    book.displayFunction();
}