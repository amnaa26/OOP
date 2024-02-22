*
 * Programmer: Amna(23k - 0066)
 * Date: 15/02/2024
 * Desc: Construct a class representing a Book, encompassing attributes like name, author, ISBN number, and total page count, 
         along with a variable tracking the number of pages read. Tasks include defining constructors for the 
         Book class - one default constructor and another parameterized constructor initializing all attributes. Values can be 
         hardcoded within the main function. Additionally, implement a method to update the pages read, triggering a display of 
         "You have finished the book" when all pages are read. This method should be called from the main function to monitor 
         reading progress.
*/

#include <iostream>
#include <string>
using namespace std;

class Book{
    string author;
    string name;
    string ISBN;
    int pageCount;
    int pageRead;

    public:
        //default constructor
        Book(){
            this -> name = "Harry Potter and the Goblet of Fire";
            this -> author = "J.K Rowling";
            this -> ISBN = "03009876154";
            this -> pageCount = 300;
            this -> pageRead = 0;
        }

        //parametrized constructor
        Book(string author, string name, string isbn, int pageCount, int pageRead){
            this -> author = author;
            this -> name = name;
            this -> ISBN = isbn;
            this -> pageCount = pageCount;
            this -> pageRead = pageRead;
        }

        //updating count of page read
        void pagesRead(int read){
            pageRead += read;
            int count;
            int i;
            if(read >= pageCount){
                cout << "You have finished the book" <<endl;
            }
            else{
                cout << "You have read " << pageRead << " pages.\nYouhave to read " << pageCount - pageRead << " number of pages!";
            }
        }
};

int main(){
    Book obj1("Great Expectations", "Charles Dicken", "03009876154", 300, 10);
    obj1.pagesRead(13);
    return 0;
}
