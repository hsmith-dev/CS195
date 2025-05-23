#pragma once
#include <iostream>
using namespace std;

class MagicCreature
{
public:
	enum class eType {
		DRAGON = 1,
		PHOENIX = 2,
	};
	string GetName() { return name; }
	int GetMagicLevel() { return magic_level; }
	string GetHabitat() { return habitat; }
	int GetAge() { return age; }

	virtual eType GetType() = 0;
	virtual void Read(ostream& os, istream& is);
	virtual void Write(ostream& os);

protected:
	string name;
	int magic_level;
	string habitat;
	int age;
};

