#include "Phoenix.h"

void Phoenix::Read(ostream& ostream, istream& istream) {
	MagicCreature::Read(ostream, istream);

	ostream << "Enter the amount of rebirths for the Phoenix: ";
	istream >> rebirth_count;

	ostream << "Enter the numerical value of intensity of flame for the Phoenix: ";
	istream >> flame_intensity;

	int color;
	ostream << "Choose the color for the feathers of the Phoenix: " << endl;
	ostream << "1. Red" << endl;
	ostream << "2. Orange" << endl;
	ostream << "3. Yellow" << endl;
	ostream << "4. Green" << endl;	
	ostream << "5. Blue" << endl;	
	ostream << "6. Purple" << endl;
	istream >> color;

}

void Phoenix::Write(ostream& ostream) {
	MagicCreature::Write(ostream);

	ostream << "Rebirth Count: " << GetRebirthCount() << endl;
	ostream << "Flame Intensity: " << GetFlameIntensity() << endl;
	ostream << "Phoenix Feather Color: " << GetFeatherColor() << endl;
	ostream << "Phoenix Feather Glow: " << GetFeatherGlow() << endl;
}

void Phoenix::SetFeatherColor(int color) {
	switch (color) {
		case 1:
			phoenix_feather_color = RED;
			break;
		case 2:
			phoenix_feather_color = ORANGE;
			break;
		case 3:
			phoenix_feather_color = YELLOW;
			break;
		case 4:
			phoenix_feather_color = GREEN;
			break;
		case 5:
			phoenix_feather_color = BLUE;
			break;
		case 6:
			phoenix_feather_color = PURPLE;
			break;
		default:
			break;
	}
}

void Phoenix::SetFeatherGlow(int glow) {
	switch (glow) {
		case 1:
			phoenix_feather_glow = LOW;
			break;
		case 2:
			phoenix_feather_glow = MEDIUM;
			break;
		case 3:
			phoenix_feather_glow = HIGH;
			break;
		default:
			break;
	}
}