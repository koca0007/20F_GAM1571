#pragma once

namespace fw {

	class FWCore;
	class EventManager;
	class Event;

class GameCore
{
public:
	GameCore(FWCore* pFramework);
	virtual ~GameCore();

	virtual void StartFrame(float deltaTime) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
	virtual void OnEvent(Event* pEvent) = 0;

	FWCore* GetFramework() { return m_pFramework; }
	EventManager* GetEventManager() { return m_pEventManager; }

protected:
	FWCore* m_pFramework = nullptr;

	EventManager* m_pEventManager = nullptr;
};

}

