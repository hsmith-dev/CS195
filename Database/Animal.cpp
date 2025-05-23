#include "Animal.h"

void Animal::Read(ostream& ostream, istream& istream)
{
	// the above variables passed in as arguments are used to read and write the data as cout and cin
	ostream << "Enter the name of the animal: ";
	istream >> m_name;

	ostream << "Enter the lifespan of the animal: ";
	istream >> m_lifespan;
}

void Animal::Write(ostream& ostream)
{
	ostream << "Animal Name: " << m_name << endl;
	ostream << "Animal Lifespan: " << m_lifespan << endl;
}
