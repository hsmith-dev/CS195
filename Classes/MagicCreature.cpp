#include "MagicCreature.h"

void MagicCreature::Read(ostream& ostream, istream& istream)
{
	ostream << "Enter the name of the magic creature: ";
	istream >> name;

	ostream << "Enter the magic level of this creature: ";
	istream >> magic_level;

	ostream << "Enter the habitat of this creature: ";
	istream >> habitat;

	ostream << "Enter the age of this creature: ";
	istream >> age;
}

void MagicCreature::Write(ostream& ostream)
{
	ostream << "Name: " << name << endl;
	ostream << "Magic Level: " << magic_level << endl;
	ostream << "Habitat: " << habitat << endl;
	ostream << "Age: " << age << endl;
}