#pragma once

class LevelSelectEvent : public fw::Event
{
public:
	LevelSelectEvent()
	{
		
	}
	virtual ~LevelSelectEvent() {}

	static const char* GetStaticEventType() { return "LevelSelectEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }
};

class HandleWinEvent : public fw::Event
{
public:
	HandleWinEvent()
	{

	}
	virtual ~HandleWinEvent() {}

	static const char* GetStaticEventType() { return "HandleWinEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }
};

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

class SpawnBombsEvent : public fw::Event
{
public:
	SpawnBombsEvent()
	{
		
	}
	virtual ~SpawnBombsEvent() {}

	static const char* GetStaticEventType() { return "SpawnBombsEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }
};

class ExplodeEvent : public fw::Event
{
public:
	ExplodeEvent(Bomb* bomb)
	{
		m_Bomb = bomb;
	}
	virtual ~ExplodeEvent() {}

	static const char* GetStaticEventType() { return "ExplodeEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }
	
	Bomb* GetBomb() { return m_Bomb; }
	

protected:
	Bomb* m_Bomb = nullptr;
};

class PlayerDeathEvent : public fw::Event
{
public:
	PlayerDeathEvent(Player* player)
	{
		m_Player = player;
	}
	virtual ~PlayerDeathEvent() {}

	static const char* GetStaticEventType() { return "PlayerDeathEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	Player* GetPlayer() { return m_Player; }

protected:
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