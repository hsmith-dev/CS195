#include "Database.h"
#include "Bird.h"

void Database::Create(Animal::eType type)
{
	Animal* animal = nullptr;

	switch (type)
	{
		case Animal::eType::BIRD:
			animal = new Bird();
			break;
		case Animal::eType::REPTILE:
			//animal = new Reptile();
			break;
		default:
			break;
	}

	animal->Read(cout, cin);

	m_animals.push_back(animal); // Add the new animal to the database with the base class pointer
}

void Database::DisplayAll()
{

}
