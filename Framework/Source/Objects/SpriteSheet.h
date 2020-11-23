#pragma once

#include <string>
#include "Math/Vector.h"

namespace fw
{
	

	struct SpriteInfo
	{
		std::string name = "";
		float x = 0;
		float y = 0;
		float w = 64;
		float h = 64;
		Vector2 UVOffset;
	};

	class SpriteSheet
	{
	public:
		SpriteSheet(std::string fileName);
		~SpriteSheet();

		SpriteInfo GetSprite(std::string name);

		std::string GetSpriteName(std::string animName);

		Vector2 GetUVScale(std::string spriteName);

	private:
		std::map<std::string, SpriteInfo> m_Sprites;
		std::string m_Texture;
		int m_Width;
		int m_Height;
	};
}