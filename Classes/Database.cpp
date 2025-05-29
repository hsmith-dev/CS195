#include "Database.h"
#include "Dragon.h"
#include "Phoenix.h"
using namespace std;

Database::Database() {
	//creatures = vector<MagicCreature*>();
}

Database::~Database() {
	for (MagicCreature* creature : creatures) {
		delete creature;
	}
	creatures.clear();
}

void Database::Create(MagicCreature::eType type) {
	MagicCreature* creature = nullptr;

	switch (type) {
	case MagicCreature::eType::DRAGON: {
		creature = new Dragon;
		break;
	}
	case MagicCreature::eType::PHOENIX: {
		creature = new Phoenix;
		break;
	}
	default:
		throw invalid_argument("Invalid type");
	}

	creature->Read(cout, cin);
	creatures.push_back(creature);
	for (MagicCreature* creature : creatures) {
		cout << "Creature added: " << creature->GetName() << endl;
	}
}

void Database::Display(const string& name) {
	cout << "Creature with name " << name << ":" << endl;
	for (MagicCreature* creature : creatures) {
		if (creature->GetName() == name) {
			creature->Write(cout);
			return;
		}
	}
	cout << "Creature not found." << endl;
}

void Database::Display(MagicCreature::eType type) {
	cout << "Creatures of type provided: " << endl;
	bool found = false;
	for (MagicCreature* creature : creatures) {
		if (creature->GetType() == type) {
			found = true;
			creature->Write(cout);
		}
	}
	if (!found) {
		cout << "No creatures of this type in the database." << endl;
	}
}

void Database::DisplayAll() {
	cout << "All creatures:" << endl;
	for (MagicCreature* creature : creatures) {
		creature->Write(cout);
	}
	cout << "No creatures in the database." << endl;
}