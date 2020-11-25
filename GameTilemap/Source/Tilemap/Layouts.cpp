#include "GamePCH.h"

#include "Tilemap/Tilemap.h"
#include "Layouts.h"

using TT = Tilemap::TileType;

const int TileLayout_Width = 8;
const int TileLayout_Height = 8;

static const Tilemap::TileType TileLayout[] =
{
	TT::Wall, TT::Wall,  TT::Wall, 
	TT::Wall, TT::Floor, TT::Wall,
	TT::Wall, TT::Wall,  TT::Wall,
};


