#pragma once

#include <string>

namespace fw
{
	/*struct SpriteInfo
	{
		const char* pName = nullptr;
		int pX = 0;
		int pY = 0;
		int pWidth = 0;
		int pHeight = 0;
	};*/

	class SpriteSheet
	{
	public:
		SpriteSheet(std::string pName, int pX, int pY, int pWidth, int pHeight);
		~SpriteSheet();

		/*SpriteInfo GetSpriteInfo();*/

	private:
		/*SpriteInfo m_SpriteInfo;*/
		std::string name;
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
	};
}