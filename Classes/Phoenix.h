#pragma once
#include "MagicCreature.h"
class Phoenix : public MagicCreature
{
public:
	eType GetType() override { return eType::PHOENIX; }
	void Read(ostream& osstream, istream& istream) override;
	void Write(ostream& osstream) override;

	enum feather_color {
		RED = 1,
		ORANGE = 2,
		YELLOW = 3,
		GREEN = 4,
		BLUE = 5,
		PURPLE = 6,
		UNKNOWN_COLOR
	};
	enum feather_glow {
		LOW = 1,
		MEDIUM = 2,
		HIGH = 3,
		UNKNOWN_GLOW
	};
	feather_color GetFeatherColor() { return phoenix_feather_color; }
	feather_glow GetFeatherGlow() { return phoenix_feather_glow; }
	int GetRebirthCount() { return rebirth_count; }
	int GetFlameIntensity() { return flame_intensity; }

	void SetFeatherColor(int color);
	void SetFeatherGlow(int glow);

protected:
	int rebirth_count = 0;
	int flame_intensity = 0;
	feather_glow phoenix_feather_glow = UNKNOWN_GLOW;
	feather_color phoenix_feather_color = UNKNOWN_COLOR;
};

