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
	std::string SpriteSheet::GetSpriteName(std::string animName)
	{
			 if (animName == "WalkUp1")	{ return "Player/player_02"; }
		else if (animName == "WalkUp2") { return "Player/player_03"; }
		else if (animName == "WalkUp3") { return "Player/player_04"; }
				 
		else if (animName == "WalkDown1") { return "Player/player_05"; }
		else if (animName == "WalkDown2") { return "Player/player_06"; }
		else if (animName == "WalkDown3") { return "Player/player_07"; }

		else if (animName == "WalkRight1") { return "Player/player_11"; }
		else if (animName == "WalkRight2") { return "Player/player_12"; }
		else if (animName == "WalkRight3") { return "Player/player_13"; }

		else if (animName == "WalkLeft1") { return "Player/player_14"; }
		else if (animName == "WalkLeft2") { return "Player/player_15"; }
		else if (animName == "WalkLeft3") { return "Player/player_16"; }

		return "";
	}
}

