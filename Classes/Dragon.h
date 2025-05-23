#pragma once
#include "MagicCreature.h"

class Dragon : public MagicCreature
{
public:
	eType GetType() override { return eType::DRAGON; }
	void Read(ostream& osstream, istream& istream) override;
	void Write(ostream& osstream) override;

	enum scale_color {
		RED = 1,
		GREEN = 2,
		BLUE = 3,
		BLACK = 4,
		WHITE = 5,
		UNKNOWN_COLOR
	};

	int GetFirePower() { return fire_power; }
	float GetWingSpan() { return wing_span; }
	int GetHoardValue() { return hoard_value; }
	scale_color GetScaleColor() { return dragon_scale_color; }
	void SetScaleColor(int color);

protected:
	int fire_power = 0;
	float wing_span = 0.0f;
	int hoard_value = 0;
	scale_color dragon_scale_color = UNKNOWN_COLOR;
};

