/*
 * Programmer: Amna(23k-0066)
 * Desc: Create a `Image` class which manages image data for a graphics application. Key features include:
		 - Constructor: Initializes width, height, and data pointer, creating an independent copy of provided data.
		 - Copy Constructor: Creates a new `Image` object as a copy of another.
		 - Destructor: Deallocates memory for image data.
		 - Display Function: Outputs image data.
		 - updateData Function: Updates image data.

		 In the main function:
		 - An `Image` object with dimensions 2x3 is created and initialized.
		 - A copy of the original image is made.
		 - Both original and copied images' data are displayed.
		 - The updateData function modifies image data, and changes are displayed for both images.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Image{
	int width;
	int height;
	int* ImageData;
	
public:
	Image(int width, int height, int* data){
		int i;
		this -> width = width;
		this -> height = height;
		ImageData = new int [width * height];
		for(i = 0; i < (width * height); ++i){
			ImageData[i] = data[i];
		}
	}
	
	Image(const Image& obj){
		width = obj.width;
		height = obj.height;
		ImageData = new int [height * width];
		int i;
		for(i = 0; i < (width * height); ++i){
			ImageData[i] = obj.ImageData[i];
		}
	}
	
	~Image(){
		delete[] ImageData;
	}
	
	void display(){
		int i, j;
		for(i = 0; i < height; ++i){
			for(j = 0; j < width; ++j){
				cout << ImageData[i*width + j] << " ";
			}
			
			cout << endl;
		}
	}
	
	void updateData(){
		int i;
		for(i = 0; i < width*height; ++i){
			if(ImageData[i] <= 0) ImageData[i] = rand() % 255 + 1;
		}
	}
};


int main(){
	int imageData[2*3] = {-6, 0, 23, 12, 54, 14};
	Image object(3, 2, imageData);
	Image copy(object);
	
	cout << "Image Data of Original Object: " << endl;
	object.display();
	cout << "\nImage Data of Copied Object: " << endl;
	copy.display();
	
	object.updateData();
	copy.updateData();
	cout <<"\nUpdated Image Data of Original Object: " << endl;
	object.display();
	cout << "\nUpdated Image Data of Copied Object: " << endl;
	copy.display();
}
