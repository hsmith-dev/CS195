#include <iostream>
#include "Employee.h"
using namespace std;



int main() {
	int numEmployees;
	std::cout << "Enter the number of employees (max 5): ";
	std::cin >> numEmployees;

	if (numEmployees > 5) numEmployees = 5;

	Employee employees[5];

	for (int i = 0; i < numEmployees; i++) {
		std::cout << "\nEmployee " << (i + 1) << ":\n";
		employees[i].Read();
	}

	std::cout << "\n--- Payroll Summary ---\n";
	for (int i = 0; i < numEmployees; i++) {
		std::cout << "\nEmployee " << (i + 1) << ":\n";
		employees[i].Write();
	}

	return 0;
}