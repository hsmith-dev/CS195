#pragma once
#include "MagicCreature.h"
#include <vector>
using namespace std;

class Database
{
public: 
	Database();
	~Database();
	void Create(MagicCreature::eType type);
	void DisplayAll();
	void Display(const string& name);
	void Display(MagicCreature::eType type);

private:
	vector<MagicCreature*> creatures;
};

