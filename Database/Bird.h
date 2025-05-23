#pragma once
#include "Animal.h"
class Bird : public Animal
{
public:
	eType GetType() override { return eType::BIRD; }

	void Read(ostream& osstream, istream& istream) override;
	void Write(ostream& osstream) override;

protected:
	int m_numFeathers = 0;
};

