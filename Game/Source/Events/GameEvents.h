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

	static const char* GetStaticEventType() { return "SpawnEnemiesEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }
};

class DeleteEnemiesEvent : public fw::Event
{
public:
	DeleteEnemiesEvent(Enemy* enemy)
	{
		m_Enemy = enemy;
	}
	virtual ~DeleteEnemiesEvent() {}

	static const char* GetStaticEventType() { return "DeleteEnemiesEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	Enemy* GetEnemy() { return m_Enemy; }

protected:
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

class DeleteBombEvent : public fw::Event
{
public:
	DeleteBombEvent(Bomb* bomb)
	{
		m_Bomb = bomb;
	}
	virtual ~DeleteBombEvent() {}

	static const char* GetStaticEventType() { return "DeleteBombEvent"; }
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

class MakeExplosionEvent : public fw::Event
{
public:
	MakeExplosionEvent()
	{

	}
	virtual ~MakeExplosionEvent() {}

	static const char* GetStaticEventType() { return "MakeExplosionEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }
};

class DeleteExplosionEvent : public fw::Event
{
public:
	DeleteExplosionEvent(fw::GameObject* bomb)
	{
		m_Bomb = bomb;
	}
	virtual ~DeleteExplosionEvent() {}

	static const char* GetStaticEventType() { return "DeleteExplosionEvent"; }
	virtual const char* GetType() override { return GetStaticEventType(); }

	fw::GameObject* GetExplosion() { return m_Bomb; }


protected:
	fw::GameObject* m_Bomb = nullptr;
};