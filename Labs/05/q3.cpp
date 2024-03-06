/*
 * Creator: Amna(23k-0066)
 * Desc: Create a class called ValidateString. The purpose of this class will be check if the given characters in a string are alphabet only. 
		 Numbers and symbols will mean that the string is invalid. 
		 By using a parameterized constructor, create multiple objects for your class that accept different strings. 
		 Create a constant function that checks whether the string variable is valid or not.
		 What happens if you do not make your function constant? Add a comment right above your function explaining why we make a function constant.
*/

#include <iostream>
#include <string>
using namespace std;

class ValidateString {
    string str;

public:
    ValidateString(string s) {
        str = s;
    }

    /*
		If we do not make the isStringValid() function constant, it means that the function may modify the internal state of the object. However, in this case, the function only checks the validity of the string and does not modify any member variables. Therefore, making the function constant ensures that it does not accidentally modify any member variables of the object, providing a guarantee of safety when calling the function. 
	*/
    bool isStringValid() const {
       for (size_t i = 0; i < str.length(); ++i) {
            if (!isalpha(str[i])) { 
                return false; 
            }
        }
        return true; 
    }
};

int main() {
    
    ValidateString str1("Hello");
    ValidateString str2("1234");
    ValidateString str3("ThisIsAValidString");
    ValidateString str4("!@#$%^&*");

    
    cout << "String 1 is " << (str1.isStringValid() ? "valid" : "invalid") << endl;
    cout << "String 2 is " << (str2.isStringValid() ? "valid" : "invalid") << endl;
    cout << "String 3 is " << (str3.isStringValid() ? "valid" : "invalid") << endl;
    cout << "String 4 is " << (str4.isStringValid() ? "valid" : "invalid") << endl;

    return 0;
}

