#pragma once

class Tilemap
{
public:
	enum class TileType
	{
		TT_Floor,
		TT_Wall ,
		TT_Grass,
		TT_NumTypes,
	};

	struct TileProperties
	{
		bool bWalkable = true;
		Vector2 UVOffset;
		Vector2 UVScale;

		TileProperties(fw::SpriteInfo pSprite, bool pWalkable)
		{
			UVOffset = pSprite.UVOffset;
			UVScale = pSprite.UVScale;
			bWalkable = pWalkable;
		}

		TileProperties() {}
	};

	Tilemap(const TileType* pLayout, int pWidth, int pHeight, fw::Texture* pTexture, fw::SpriteSheet* pSpriteSheet, fw::Mesh* pMesh);
	~Tilemap();

	void Draw();

protected:
	fw::Mesh* m_pMesh = nullptr;
	fw::SpriteSheet* m_pSpriteSheet = nullptr;
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Texture* m_pTexture = nullptr;

	Vector2 m_TileSize = Vector2(2, 2); // How big in world units is the tile
	iVector2 m_MapSize; // How many tiles big is our map.

	TileType* m_Layout = nullptr;
	
	std::vector<TileProperties> m_Properties;

private:
	void FlipIt(const TileType* pLayout);
};

