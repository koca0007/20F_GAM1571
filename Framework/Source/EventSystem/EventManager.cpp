#include "FrameworkPCH.h"
#include "EventManager.h"
#include "Core/GameCore.h"
#include "Event.h"

namespace fw
{
	EventManager::EventManager()
	{
		
	}

	EventManager::~EventManager()
	{
		while (!m_EventQueue.empty())
		{
			delete m_EventQueue.front();
			m_EventQueue.pop();
		}
	}

	void EventManager::AddEvent(Event* pEvent)
	{
		m_EventQueue.push(pEvent);
	}

	void EventManager::DispatchAllEvents(GameCore* pGameCore)
	{
		while (!m_EventQueue.empty())
		{
			Event* pEvent = m_EventQueue.front();
			m_EventQueue.pop();

			pGameCore->OnEvent(pEvent);

			delete pEvent;
		}
	}

}


