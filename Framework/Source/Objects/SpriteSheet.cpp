#include "FrameworkPCH.h"
#include "SpriteSheet.h"
#include "Utility/Helpers.h"

namespace fw
{
	SpriteSheet::SpriteSheet(std::string pName, int pX, int pY, int pWidth, int pHeight)
	{
		name = pName;
		x = pX;
		y = pX;
		width = pWidth;
		height = pHeight;
	}

	SpriteSheet::~SpriteSheet()
	{

	}
}

