#pragma once

class PlayerController
{
public:
	enum MyEnum
	{
		Up =	1,
		Down =	2,
		Left =	4,
		Right = 8,
	};

	PlayerController();
	virtual ~PlayerController();

	void OnEvent(fw::Event* pEvent);

	bool IsUpHeld()		{ return (m_Flags & Up) > 0; }
	bool IsDownHeld()	{ return (m_Flags & Down) > 0; }
	bool IsLeftHeld()	{ return (m_Flags & Left) > 0; }
	bool IsRightHeld()	{ return (m_Flags & Right) > 0; }

protected:
	unsigned int m_Flags = 0;
};