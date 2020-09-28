#pragma once

namespace fw {

	class FWCore;

class GameCore
{
public:
	GameCore(FWCore* pFramework);
	virtual ~GameCore();

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

	FWCore* GetFramework();

	FWCore* m_pFramework;
};

}

