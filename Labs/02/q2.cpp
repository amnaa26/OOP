/*
Programmer: Amna(23K-0066)
Question: Envision that you’re assigned to create a program to handle a library’s book inventory. Each book has characteristics 
	  such as title, author, year of publication, and genre. 
	  Construct a struct that accurately depicts a book as an entity in the real world. Then, using a programming C++, write a 
	  basic program that uses this struct to demonstrate the creation, modification, and display of book data.
		 1. Expand the program to manage an array of multiple books.
		 2. Develop a function to find a book by its title or author.
		 3. Enable the user to interactively input new books and update existing book data.
*/

#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

void findBook(const Book books[], int size, string query) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].title == query || books[i].author == query) {
            cout << "Book found:" << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year: " << books[i].year << endl;
            cout << "Genre: " << books[i].genre << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

void updateBook(Book& book) {
    cout << "Enter new details for the book:" << endl;
    cout << "Title: ";
    getline(cin, book.title);
    cout << "Author: ";
    getline(cin, book.author);
    cout << "Year: ";
    cin >> book.year;
    cin.ignore(); // Ignore newline character left in the input stream
    cout << "Genre: ";
    getline(cin, book.genre);
}

int main(){
    const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int numBooks = 0;
    
    cout << "WELCOME TO BOOK MANAGEMENT SYSTEM" <<endl;
    int choice;
    do {
        cout << "\nMenu:\n\t1. Enter a new book\n\t2. Update a book\n\t3. Search for a book\n\t4. Display all books\n\t5. Exit\n\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        switch (choice) {
            case 1:
                if (numBooks < MAX_BOOKS) {
                    cout << "Enter book details:" << endl;
                    cout << "Title: ";
                    getline(cin, books[numBooks].title);
                    cout << "Author: ";
                    getline(cin, books[numBooks].author);
                    cout << "Year: ";
                    cin >> books[numBooks].year;
                    cin.ignore(); // Ignore newline character left in the input stream
                    cout << "Genre: ";
                    getline(cin, books[numBooks].genre);
                    numBooks++;
                } else {
                    cout << "Maximum number of books reached." << endl;
                }
                break;
            case 2:
                if (numBooks > 0) {
                    int bookIndex;
                    cout << "Enter the index of the book to update (1-" << numBooks << "): ";
                    cin >> bookIndex;
                    cin.ignore(); // Ignore newline character left in the input stream
                    if (bookIndex >= 1 && bookIndex <= numBooks) {
                        updateBook(books[bookIndex - 1]);
                        cout << "Book updated successfully." << endl;
                    } else {
                        cout << "Invalid book index." << endl;
                    }
                } else {
                    cout << "No books available to update." << endl;
                }
                break;
            case 3:
                if (numBooks > 0) {
                    string query;
                    cout << "Enter the title or author to search for: ";
                    getline(cin, query);
                    findBook(books, numBooks, query);
                } else {
                    cout << "No books available to search." << endl;
                }
                break;
            case 4:
                if (numBooks > 0) {
                    cout << "\nAll books:" << endl;
                    for (int i = 0; i < numBooks; ++i) {
                        cout << "Book " << i + 1 << ":" << endl;
                        cout << "Title: " << books[i].title << endl;
                        cout << "Author: " << books[i].author << endl;
                        cout << "Year: " << books[i].year << endl;
                        cout << "Genre: " << books[i].genre << endl;
                        cout << endl;
                    }
                } else {
                    cout << "No books available to display." << endl;
                }
                break;
            case 5:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
