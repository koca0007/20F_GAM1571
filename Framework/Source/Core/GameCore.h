#pragma once

namespace fw {

	class FWCore;
	class Event;

class GameCore
{
public:
	GameCore(FWCore* pFramework);
	virtual ~GameCore();

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

	virtual void OnEvent(Event* pEvent) = 0;

	FWCore* GetFramework() { return m_pFramework; }

	FWCore* m_pFramework;
};

}

