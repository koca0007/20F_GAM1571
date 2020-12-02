#include "FrameworkPCH.h"
#include "SpriteSheet.h"
#include "Utility/Helpers.h"

namespace fw
{
	SpriteSheet::SpriteSheet(std::string fileName)
	{
		char* jsonString = fw::LoadCompleteFile(fileName.c_str(), nullptr);
		rapidjson::Document document;
		document.Parse(jsonString);
		delete[] jsonString;

		m_Texture = document["Texture"].GetString();
		m_Width = document["Width"].GetInt();
		m_Height = document["Height"].GetInt();

		for (auto& sprite : document["Sprites"].GetArray())
		{
			SpriteInfo spriteInfo;
			spriteInfo.name = sprite["Name"].GetString();
			spriteInfo.x = sprite["X"].GetInt();
			spriteInfo.y = sprite["Y"].GetInt();
			spriteInfo.w = sprite["W"].GetInt();
			spriteInfo.h = sprite["H"].GetInt();
			spriteInfo.UVScale = Vector2((float)spriteInfo.w / m_Width, (float)spriteInfo.h / m_Height);
			spriteInfo.UVOffset = Vector2((float)spriteInfo.x / m_Width, (float)spriteInfo.y / m_Height);
			m_Sprites.insert(std::pair<std::string, SpriteInfo>(spriteInfo.name, spriteInfo));
		}
	}

	SpriteSheet::~SpriteSheet()
	{

	}

	Vector2 SpriteSheet::GetUVScale(std::string spriteName)
	{
		return Vector2((float)m_Sprites.at(spriteName).w / m_Width, (float)m_Sprites.at(spriteName).h / m_Height);
	}

	// Return Sprite by name
	SpriteInfo SpriteSheet::GetSprite(std::string name)
	{
		return m_Sprites[name];
	}

	// Return Sprite name by animation
}

