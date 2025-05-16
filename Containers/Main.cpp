// Author: Harrison Smith
// Assignment: Containers
// Date: 5/16/2025
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>

void array() {
	//Create an array<string, 7>
	std::cout << "Array" << std::endl;
	std::array<std::string, 7> week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	std::cout << "There are " << week.size() << " days in a week." << std::endl;
	int count = 1;
	for (std::string day : week) {
		std::cout << count << ". " << day << std::endl;
		count++;
	}
}

void vector() {
	// Use a vector<int
	std::cout << std::endl << "Vector" << std::endl;
	std::vector<int> numbers = {1, 2, 3, 4, 5};
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.pop_back();
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
}

void list() {
	// Use a list<string>
	std::cout << std::endl << std::endl << "List" << std::endl;
	std::list<std::string> fruit = { "Apple", "Pear", "Orange" };
	fruit.push_front("Grapes");
	fruit.push_back("Banana");
	fruit.remove("Orange");
	for (auto it = fruit.begin(); it != fruit.end(); ++it) {
		std::cout << *it << " ";
	}
}

void map() {
	// Use a map<string, int> 
	std::cout << std::endl << std::endl << "Map" << std::endl;
	std::map<std::string, int> ages;
	ages.insert(std::pair<std::string, int>("Elrond", 50));
	ages.insert(std::pair<std::string, int>("Gandalf", 1000));
	ages.insert(std::pair<std::string, int>("Frodo", 33));
	ages["Gandalf"] = 2000;
	for (auto it = ages.begin(); it != ages.end(); ++it) {
		std::cout << it->first << " is " << it->second << " years old." << std::endl;
	}
}

int main() {
	std::cout << "Containers Assignment" << std::endl << std::endl;
	array();
	vector();
	list();
	map();
}
