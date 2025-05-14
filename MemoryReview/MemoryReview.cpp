// Assignment: Memory Review
// Author: Harrison Smith
// Date: 2025-5-13
// Class: CSC 195
// Professor: Omkar Terse

#include <iostream>
using namespace std;

struct Person
{
	char name[32];
	int id;
};

void squareInt(int num)
{
	num = num * num;
}

void squareIntReference(int& num)
{
	num = num * num;
}

void Double(int* num) {
	*num = *num * 2;
}

int main()
{
	// ** REFERENCE **
	// declare an int variable and set the value to some number (less than 10)
	int i = 5;

	// declare a int reference and set it to the int variable above
	int& iRef = i;

	// output the int variable
	cout << "i: " << i << endl;

	// set the int reference to some number
	iRef = 7;

	// output the int variable
	cout << "i: " << i << endl;
	
	// what happened to the int variable when the reference was changed? (insert answer)
	cout << "iRef became 7 and it directly referenced the original int and made a change to the original int so they are both now: " << iRef << endl;

	// output the address of the int variable
	cout << "Address of i: " << &i << endl;
	// output the address of the int reference
	cout << "Address of iRef: " << &iRef << endl;
	// are the addresses the same or different? (insert answer)
	cout << "The addresses are the same because the reference is just an alias for the original variable." << endl;

	// ** REFERENCE PARAMETER **
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	squareInt(i);

	// output the int variable to the console
	cout << "i (after square): " << i << endl;

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	squareIntReference(i);
	cout << "i (after squareByReference): " << i << endl;

	// ** POINTER VARIABLE **
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* iPoint = nullptr;
	// set the int pointer to the address of the int variable created in the REFERENCE section
	iPoint = &i;

	// output the value of the pointer
	cout << "Pointer Value: " << iPoint << endl;
	// what is this address that the pointer is pointing to? (insert answer)
	cout << "This is the address of the int variable i." << endl;
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << "Dereference Pointer Value (after square): " << *iPoint << endl;

	// ** POINTER PARAMETER **
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(iPoint);
	
	// output the dereference pointer
	cout << "Dereference Pointer Value (after double): " << *iPoint << endl;
	// output the int variable created in the REFERENCE section
	cout << "iRef: " << iRef << endl;
	// did the int variable's value change when using the pointer?
	cout << "The pointer variable changed the value of the int variable i and the reference variable (since reference is just an alias)." << endl;
}