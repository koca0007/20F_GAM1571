#pragma once


class RemoveFromGameEvent : public fw::Event
{
public:
	RemoveFromGameEvent(fw::GameObject* pObject)
	{
		m_pObject = pObject;
	}
	virtual ~RemoveFromGameEvent() {}

	static const char* GetStaticEventType() { return "RemoveFromGameEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	fw::GameObject* GetGameObject() { return m_pObject; }

protected:
	fw::GameObject* m_pObject = nullptr;
};

class SpawnEnemiesEvent : public fw::Event
{
public:
	SpawnEnemiesEvent(fw::GameObject* pObject)
	{
		m_pObject = pObject;
	}
	virtual ~SpawnEnemiesEvent() {}

	static const char* GetStaticEventType() { return "SpawnEnemiesEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	fw::GameObject* GetGameObject() { return m_pObject; }

protected:
	fw::GameObject* m_pObject = nullptr;
};

class DeleteEnemiesEvent : public fw::Event
{
public:
	DeleteEnemiesEvent(fw::GameObject* pObject)
	{
		m_pObject = pObject;
	}
	virtual ~DeleteEnemiesEvent() {}

	static const char* GetStaticEventType() { return "DeleteEnemiesEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	fw::GameObject* GetGameObject() { return m_pObject; }

protected:
	fw::GameObject* m_pObject = nullptr;
};