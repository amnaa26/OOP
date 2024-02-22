/*
 * Programmer: Amna(23k - 0066)
 * Date: 15/02/2024
 * Desc: Revise the previous Book class by eliminating the parameterized constructor and enhancing the default constructor. 
 		 The revised default constructor should initialize the page count to 1000 and the pages read to 0 using a member initialization list. 
		 Generate setter methods for the remaining attributes and utilize them within the main function to update attribute values. 
		 Introduce a method called "showBookInfo" to exhibit all book details. Invoke this method from the main function for displaying book information.
*/

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string name;
    string author;
    string ISBN;
    int pageCount;
    int pageRead;

public:
    // Default constructor with member initialization list
    Book() : name("Harry Potter and the Goblet of Fire"), author("J.K Rowling"), ISBN("978-0743273565"), pageCount(1000), pageRead(0) {}

    // Setter methods
    void setName(string bookName) { name = bookName; }
    void setAuthor(string bookAuthor) { author = bookAuthor; }
    void setISBN(string bookISBN) { ISBN = bookISBN; }
    void setPageCount(int count) { pageCount = count; }
    void setPageRead(int read) { pageRead = read; }


	//Updating read count
    void updatePagesRead(int read) {
        pageRead += read;
        if (pageRead >= pageCount) {
            cout << "You have finished the book" << endl;
        } else {
            cout << "You have read " << pageRead << " pages.\nYou have to read " << pageCount - pageRead << " more pages." << endl;
        }
    }

	//Displaying info
    void displayBookInfo() {
        cout << "Book Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Total Page Count: " << pageCount << endl;
        cout << "Pages Read: " << pageRead << endl;
    }
};

int main() {
    // Create a Book object using default constructor
    Book myBook;

    // Display initial book information
    myBook.displayBookInfo();

    // Update pages read
    myBook.updatePagesRead(25);

    return 0;
}

