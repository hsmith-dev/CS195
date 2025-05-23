#include <iostream>  
#include "Database.h"  
#include "MagicCreature.h"  
using namespace std;  

void CreateMagicCreature(Database database) {
	int choice;
	cout << "Choose which magic creature to create:\n1 - Dragon\n2 - Phoenix" << endl;
	cin >> choice;
	switch (choice) {
		case 1: {
			database.Create(MagicCreature::eType::DRAGON);
			break;
		}
		case 2: {
			database.Create(MagicCreature::eType::PHOENIX);
			break;
		}
	}
}

int main() {  
	Database database;  

	bool quit = false;  

	while (!quit) {  
		cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit" << endl;  

		int choice;  
		cin >> choice;  

		switch (choice) {  
		case 1: {
			CreateMagicCreature(database);
			break;
		}
		case 2: {
			database.DisplayAll();
			break;
		}
		case 3: {  
			cout << "Enter the name to search for: ";  
			string name;  
			cin >> name;  
			database.Display(name); 
			break;  
		}  
		case 4: {  
			cout << "Enter the type to search for:\n1 - Dragon\n2 - Phoenix";  
			int input;  
			cin >> input;  
			switch (input) {  
				case 1:  
					database.Display(MagicCreature::eType::DRAGON);  
					break;  
				case 2:  
					database.Display(MagicCreature::eType::PHOENIX);  
					break;  
				default:  
					cout << "Invalid type." << endl;  
			}  
			break;  
			}  
		case 5: {
			quit = true;
			break;
		}
		default: {
			cout << "Invalid choice. Please try again." << endl;
			choice = NULL;
		}
		}  
	}  
}