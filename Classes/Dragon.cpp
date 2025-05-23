#include "Dragon.h"

void Dragon::Read(ostream& ostream, istream& istream)
{
	MagicCreature::Read(ostream, istream);

	ostream << "Enter the fire power of the dragon: ";
	istream >> fire_power;

	ostream << "Enter the wing span of the dragon (meters): ";
	istream >> wing_span;

	ostream << "Enter the hoard value of the dragon: ";
	istream >> hoard_value;

	int color;
	ostream << "Enter the color of the dragon's scales (1: RED, 2: GREEN, 3: BLUE, 4: BLACK, 5: WHITE): ";
	istream >> color;
	SetScaleColor(color);

}

void Dragon::Write(ostream& ostream)
{
	MagicCreature::Write(ostream);

	ostream << "Fire Power: " << GetFirePower() << endl;
	ostream << "Wing Span: " << GetWingSpan() << " meters" << endl;
	ostream << "Hoard Value: " << GetHoardValue() << endl;
	ostream << "Scale Color: " << GetScaleColor() << endl;
}

void Dragon::SetScaleColor(int color)
{
	switch (color) {
		case 1:
			dragon_scale_color = RED;
			break;
		case 2:
			dragon_scale_color = GREEN;
			break;
		case 3:
			dragon_scale_color = BLUE;
			break;
		case 4:
			dragon_scale_color = BLACK;
			break;
		case 5:
			dragon_scale_color = WHITE;
			break;
		default:
			break;
	};
}