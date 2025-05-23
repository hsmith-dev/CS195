#pragma once
#include "Animal.h"
#include <vector>
using namespace std;

class Database
{
public:
	~Database();
	void Create(Animal::eType type);
	void DisplayAll();
	void Display(const string& name);
	void Display(Animal::eType type);

private:
	vector<Animal*> m_animals; 
};

