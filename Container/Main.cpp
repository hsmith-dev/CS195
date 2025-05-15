#include <iostream>
#include <array> // for STL array
#include <list> // for STL list
using namespace std;

int main() {
	// using built in array
	int numbers[5] = { 1, 2, 3, 4, 5 }; // static array with 5 elements and passed in the 5 elements

	cout << "3rd Number: " << numbers[2] << endl; // output the 3rd element of the array
	cout << "Out of bound element: " << numbers[5] << endl; // output the 6th element of the array (out of bounds), won't catch that you are outside the array

	// interating through array
	cout << "Iterating through array: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << numbers[i] << " "; // output each element of the array
	}
	cout << endl;

	// cannot use numbers.size() because of limited functionality of built-in array
	// you can use foreach loop
	// you can calculate the length of the array by sizeof
	int size = sizeof(numbers) / sizeof(int);
	cout << "Size of array: " << size << endl; // output the size of the array
	// output the size of the array using sizeof

	cout << "First element: " << numbers[0] << endl; // output the first element of the array
	cout << "First element address: " << numbers << endl; // output the address of the first element of the array
	// you can use the address to loop through with pointers as well. 

	// fixed length at compile time
	// no built in methods for common operations
	// no bounds checking
	// no dynamic resizing
	// fast access to elements, easy to set up
	// there is also the stl array which is a wrapper around the built in array

	// STL Array
	cout << endl << "STL Array" << endl;
	// need to import the STL array library
	// traditionally accessed with std::array but we are using namespace std
	array<string, 4> animals = { "Dog", "Cat", "Fish", "Bird" }; // static array with 4 elements and passed in the 4 elements

	cout << "3rd Animal: " << animals[2] << endl; // output the 3rd element of the array

	cout << "Size of array: " << animals.size() << endl; // output the size of the array

	cout << "All animals: ";
	for (string animal : animals) {
		cout << animal << " "; // output each element of the array
	}
	cout << endl;

	// fixed size with STL algorithm compatibility
	// out of bounds exceptions are given

	// STL list
	cout << endl << "STL List" << endl;
	// need to import the STL list library

	// normally std::list but we are using namespace std
	list<float> height = { 5.5f, 6.0f, 5.8f, 5.9f };

	// to iterate through you will use for each loop
	cout << "Size of list: " << height.size() << endl; // output the size of the list

	height.push_front(2.3f); // add to the front of the list
	height.push_back(7.8f); // add to the back of the list

	cout << "Size of list after adding: " << height.size() << endl; // output the size of the list

	height.sort(); // sort the list

	cout << "All heights: ";
	for (float h : height) {
		cout << h << " "; // output each element of the list
	}
	cout << endl;

	// resizable container - helpful for frequent & efficient insertion/deletion
	// no random access - must iterate through the list to find an element
	// higher memory overhead than arrays (pointers for each element)
	// works well iterators and other STL compatibility

}