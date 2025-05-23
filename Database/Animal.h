#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
	enum class eType {
		BIRD = 1,
		REPTILE = 2,
	};
	string GetName() { return m_name; } // this function is implemented in the base class, so it can be used by derived classes, no need to implement it in the derived classes
	virtual eType GetType() = 0; // this means the base class is abstract and cannot be instantiated, do not need to implement this function in the base class

	virtual void Read(ostream& ostream, istream& istream);
	virtual void Write(ostream& ostream); 

protected: 
	string m_name;
	int m_lifespan;
};

