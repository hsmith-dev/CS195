#include <iostream>
using namespace std;

// set - pass by values
void setByValues(int i) {
	i = 123;
}

// set - pass by reference
void setByReference(int& i) {
	i = 123;
}

// set - pass by pointer
void setByPointer(int* i) {
	*i = 123;
}

// swap - pass by reference
void swapByReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapByPointer(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main() {
	int i1 = 10;
	int i2 = 20;

	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;

	// pass by reference
	int& r1 = i1; // reference must have a variable set when declared

	// pass by values
	int r2 = i2;

	setByReference(r1);
	setByValues(r2);

	cout << "setByReference(i1): " << i1 << endl;
	cout << "setByValue(i2): " << i2 << endl;

	// pointers
	// pointers can point to nothing
	int* p;
	int* p1 = nullptr;


	int* p2 = &i2;
	cout << "p2 (address of i2): " << p2 << endl;
	setByPointer(p2);
	cout << "setByPointer(p2): " << *p2 << endl;
	cout << "i2 (after setByPointer): " << i2 << endl;

	swap(i1, i2);
	cout << "before swap(i1, i2): " << i1 << " " << i2 << endl;
	cout << "swap(i1, i2): " << i1 << " " << i2 << endl;
}