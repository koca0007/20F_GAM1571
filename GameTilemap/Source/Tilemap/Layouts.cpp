#include "GamePCH.h"

#include "Layouts.h"

using TT = Tilemap::TileType;


const int Level1Layout_Width = 10;
const int Level1Layout_Height = 10;
static const Tilemap::TileType Level1Layout[] =
{
	TT::TT_Wall, TT::TT_Wall,  TT::TT_Wall,  TT::TT_Wall,	TT::TT_Wall,   TT::TT_Wall,	  TT::TT_Wall,  TT::TT_Wall, TT::TT_Wall,  TT::TT_Wall,
	TT::TT_Wall, TT::TT_Floor, TT::TT_Wall,  TT::TT_Wall,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Floor, TT::TT_Floor, TT::TT_Wall,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Floor, TT::TT_Floor, TT::TT_Floor,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Floor, TT::TT_Floor, TT::TT_Floor,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Floor, TT::TT_Floor, TT::TT_Floor,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Grass, TT::TT_Grass, TT::TT_Floor,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Grass, TT::TT_Grass, TT::TT_Floor,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Floor, TT::TT_Wall,
	TT::TT_Wall, TT::TT_Grass, TT::TT_Grass, TT::TT_Floor,	TT::TT_Floor,  TT::TT_Floor,  TT::TT_Floor, TT::TT_Floor,TT::TT_Wall,  TT::TT_Wall,
	TT::TT_Wall, TT::TT_Wall,  TT::TT_Wall,  TT::TT_Wall,	TT::TT_Wall,   TT::TT_Wall,	  TT::TT_Wall,  TT::TT_Wall, TT::TT_Wall,  TT::TT_Wall,
};
