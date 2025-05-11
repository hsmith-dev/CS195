/*
*	Author: Harrison Smith
*	Date: 2025-05-06
*/

#include <iostream>

using namespace std;

int main() {
	string name;
	char initial;
	short age;
	bool isAdult;
	unsigned int zipcode;
	float wage;
	short daysWorked;
	float hoursWorkedPerDay[7];

	const float TAX = 0.1f; // 10% tax rate

	cout << "Enter your name: ";
	cin >> name;

	cout << "Enter your initial: ";
	cin >> initial;

	cout << "Enter your age: ";
	cin >> age;

	isAdult = (age >= 18);

	cout << "Enter your zipcode: ";
	cin >> zipcode;

	cout << "Enter your wage: ";
	cin >> wage;

	cout << "Enter the number of days worked per week (7 max): ";
	cin >> daysWorked;

	float totalHours = 0;
	for (int i = 0; i < daysWorked; i++) {
		cout << "Enter hours worked for day " << (i + 1) << ": ";
		cin >> hoursWorkedPerDay[i];

		totalHours += hoursWorkedPerDay[i];
	}

	float grossIncome = wage * totalHours;
	float taxAmount = grossIncome * TAX;
	float netIncome = grossIncome - taxAmount;

	cout << "\nEmployee Payroll Summary\n";
	cout << "-------------------------\n";
	cout << "Name: " << name << " " << initial << ".\n";
	cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
	cout << "Zipcode: " << zipcode << "\n";
	cout << "Hourly Wage: $" << wage << " per hour\n";
	cout << "Total Hours Worked: " << totalHours << " hours\n";
	cout << "Gross Income: $" << grossIncome << "\n";
	cout << "Tax Amount: $" << taxAmount << "\n";
	cout << "Net Income: $" << netIncome << "\n";
}