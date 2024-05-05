#include <iostream>
using namespace std;

template <typename T>
class GenericMatrix{
protected:
    T **data; //T** allows us to create a dynamic 2D array for storing the matrix data.
    int rows, cols;

public:
    GenericMatrix(int r, int c) : rows(r), cols(c){
        data = new T *[rows]; //dynamically allocating memory for rows
        for(int i = 0; i < rows; ++i){ 
            data[i] = new T[cols]; //dynamically allocating memory for the columns
        }
    }

    //getting values at data[i][j]
    T get(int i, int j) const{
        return data[i][j];
    }   

    //setting values at data[i][j]
    void set(int i, int j, T value){
        data[i][j] = value;
    }

    //Destructor to free memory
    ~GenericMatrix(){
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }

        delete[] data;
    }

    //Matrix addition using operator overloading
    GenericMatrix<T>& operator + (const GenericMatrix<T>& object){
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                data[i][j] += object.data[i][j];
            }
        }

        return *this;
    } 

     //Matrix substraction using operator overloading
     GenericMatrix<T>& operator - (const GenericMatrix<T>& object){
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                data[i][j] -= object.data[i][j];
            }
        }

        return *this;
     }   

      //Matrix multiplication using operator overloading
      GenericMatrix<T>& operator * (GenericMatrix<T>& object){
        if(cols != object.rows){
            cout << "\nMatrix multiplication Impossible!" << endl;
            return *this;
        }
        else{
            T result[rows][object.cols] = { T() };
            for(int i = 0; i < rows; ++i){
                for(int j = 0; j < object.cols; ++j){
                    //T sum = T();
                    for(int k = 0; k < rows; ++k){
                        result[i][j] += (data[i][k] * object.data[k][j]); 
                    }

                    //result.set(i, j, sum);
                }
            }

            for(int i = 0; i < rows; ++i){
                for(int j = 0; j < cols; ++j){
                    data[i][j] = result[i][j];
                }
            }

            return *this;
        }
      }

      virtual void display() const = 0;
};

class IntMatrix : public GenericMatrix <int>{
public:
    IntMatrix(int rows, int cols) : GenericMatrix<int>(rows, cols) {}
    void display() const{
        //cout << "\nInteger Matrix: " << endl;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                cout << data[i][j] << "     " ;
            }
            cout << endl;
        }

        cout << endl;
    }
};

class DoubleMatrix : public GenericMatrix<double>{
public:
    DoubleMatrix(int rows, int cols) : GenericMatrix<double>(rows, cols) {}
    void display() const{
       // cout << "\nDouble Matrix: " << endl;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                cout << data[i][j] << "     " ;
            }
            cout << endl;
        }

        cout << endl;
    }
};


int main(){
    cout << "\nCreator: Amna(23k-0066)";
    IntMatrix i1(2, 2);
    i1.set(0, 0, 0);
    i1.set(0, 1, 1);
    i1.set(1, 0, 2);
    i1.set(1, 1, 3);
    cout << "\nInteger Matrix i1: " << endl;
    i1.display();

    IntMatrix i2(2,2);
    i2.set(0, 0, 4);
    i2.set(0, 1, 5);
    i2.set(1, 0, 6);
    i2.set(1, 1, 7);
    cout << "\nInteger Matrix i2: " << endl;
    i2.display();

    IntMatrix i3(2,2);
    i3.set(0, 0, 2);
    i3.set(0, 1, 6);
    i3.set(1, 0, 12);
    i3.set(1, 1, 7);
    cout << "\nInteger Matrix i3: " << endl;
    i3.display();

    DoubleMatrix d1(2, 2);
    d1.set(0, 0, -2.34);
    d1.set(0, 1, 1.45);
    d1.set(1, 0, 0.02);
    d1.set(1, 1, 4.89);
    cout << "\nDouble Matrix d1: " << endl;
    d1.display();

    DoubleMatrix d2(2,2);
    d2.set(0, 0, 6.62);
    d2.set(0, 1, 5.57);
    d2.set(1, 0, -7.25);
    d2.set(1, 1, 1.09);
    cout << "\nDouble Matrix d2: " << endl;
    d2.display();

    cout << "Addition i1 and i2 matrices (integer matrices): " << endl;
    (i1 + i2).display();

    cout << "Multiplication of d1 and d2 matrices (double matrices): " << endl;
    (d1 * d2).display();

    cout << "Subtraction of i2 and i3 matrices (integer matrices): " << endl;  
    (i2 - i3).display();

    //There is no way through which we could prevent the values of i1 from being
    //changing as abstract class doesnot allows to create an object because of
    //pure virtual functions. Therefore, in my code, i1 - i2 will be equal to (i1 + i2)- i2.
    //The value of i2 won't change as we are saving the new data in object i1.
}