#include "GamePCH.h"

#include "Layouts.h"
#include "Tilemap.h"


Tilemap::Tilemap(const TileType* pLayout, int pWidth, int pHeight, fw::Texture* pTexture, fw::SpriteSheet* pSpriteSheet, fw::Mesh* pMesh)
{
	assert(pLayout != nullptr);
	assert(pWidth > 0);
	assert(pHeight > 0);

	m_Layout = new TileType[pWidth * pHeight];
	FlipIt(pLayout);

	m_pTexture = pTexture;
	m_pSpriteSheet = pSpriteSheet;
	m_pMesh = pMesh;
	m_MapSize = iVector2(pWidth, pHeight);

	m_Properties.resize((int)TileType::TT_NumTypes);
	m_Properties[(int)TileType::TT_Wall] = TileProperties(m_pSpriteSheet->GetSprite("Blocks/block_07"), false);
	m_Properties[(int)TileType::TT_Floor] = TileProperties(m_pSpriteSheet->GetSprite("Ground/ground_06"), true);
	m_Properties[(int)TileType::TT_Grass] = TileProperties(m_pSpriteSheet->GetSprite("Ground/ground_05"), true);

	m_pShader = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");
}

Tilemap::~Tilemap()
{
	delete m_pShader;
	delete[] m_Layout;
}

void Tilemap::FlipIt(const TileType* pLayout)
{
	int y = Level1Layout_Height * Level1Layout_Width + Level1Layout_Width;
	for (int x = 0; x < Level1Layout_Height * Level1Layout_Width; x++) {

		if (y % Level1Layout_Width == 0)
		{
			y -= Level1Layout_Width * 2;
		}
		m_Layout[x] = pLayout[y];
		y++;
	}
}

void Tilemap::Draw()
{

	for (int y = 0; y < Level1Layout_Height; y++)
	{
		for (int x = 0; x < Level1Layout_Width; x++)
		{
			int tileIndex = y * m_MapSize.x + x;
			worldPos = Vector2((float)x, (float)y) * m_TileSize;

			//To flip the layout horizontally, y axis can be adjusted without needing to change the layout array
			//Vector2 worldPos = Vector2(x, m_MapSize.y - y - 1);

			m_pMesh->Draw(worldPos, m_pShader, m_pTexture, Vector4::White(),
				m_Properties[(int)m_Layout[tileIndex]].UVScale,
				m_Properties[(int)m_Layout[tileIndex]].UVOffset, m_TileSize);
		}
	}
}