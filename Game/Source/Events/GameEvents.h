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
	SpawnEnemiesEvent()
	{
		
	}
	virtual ~SpawnEnemiesEvent() {}

	static const char* GetStaticEventType() { return "DeleteEnemiesEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	fw::GameObject* GetGameObject() { return m_pObject; }

protected:
	fw::GameObject* m_pObject = nullptr;
};

class DeleteEnemiesEvent : public fw::Event
{
public:
	DeleteEnemiesEvent(Enemy* enemy)
	{
		m_Enemy = enemy;
	}
	virtual ~DeleteEnemiesEvent() {}

	static const char* GetStaticEventType() { return "SpawnEnemiesEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	fw::GameObject* GetGameObject() { return m_pObject; }
	Enemy* GetEnemy() { return m_Enemy; }

protected:
	fw::GameObject* m_pObject = nullptr;
	Enemy* m_Enemy = nullptr;
};

class PlayerDeathEvent : public fw::Event
{
public:
	PlayerDeathEvent(Player* player /*Enemy* enemy*/)
	{
		m_Player = player;
		/*m_Enemy = enemy;*/
	}
	virtual ~PlayerDeathEvent() {}

	static const char* GetStaticEventType() { return "PlayerDeathEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	Player* GetPlayer() { return m_Player; }

protected:
	fw::GameObject* m_pObject = nullptr;
	/*Enemy* m_Enemy = nullptr;*/
	Player* m_Player = nullptr;
};

class RestartGameEvent : public fw::Event
{
public:
	RestartGameEvent(Player* player)
	{
		m_Player = player;
	}
	virtual ~RestartGameEvent() {}

	static const char* GetStaticEventType() { return "RestartGameEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

protected:
	Player* m_Player = nullptr;
};