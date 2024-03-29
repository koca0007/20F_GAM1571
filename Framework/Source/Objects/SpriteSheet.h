#pragma once

#include <string>
#include "Math/Vector.h"

namespace fw
{
	

	struct SpriteInfo
	{
		std::string name = "";
		int x = 0;
		int y = 0;
		int w = 64;
		int h = 64;
		Vector2 UVOffset;
		Vector2 UVScale;
	};

	class SpriteSheet
	{
	public:
		SpriteSheet(std::string fileName);
		~SpriteSheet();

		SpriteInfo GetSprite(std::string name);

		Vector2 GetUVScale(std::string spriteName);

	private:
		std::map<std::string, SpriteInfo> m_Sprites;
		std::string m_Texture;
		int m_Width;
		int m_Height;
	};
}