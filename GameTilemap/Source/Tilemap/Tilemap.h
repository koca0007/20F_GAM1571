#pragma once

struct TileInfo
{
	bool isWalkable = true;
};

class Tilemap
{
public:
	enum class TileType
	{
		Floor,
		Wall ,
		Crate,
		Empty,
	};

	Tilemap(TileType* pLayout, int pWidth, int pHeight);
	~Tilemap();

	void Draw();

protected:
	TileType* m_Layout;
};


