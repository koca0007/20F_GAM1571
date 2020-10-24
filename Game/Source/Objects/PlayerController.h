#pragma once

class PlayerController
{
public:
	enum Mask
	{
		Up		=	1,
		Down	=	2,
		Left	=	4,
		Right	=	8,
		Restart =	16,
		Start	=	32,
	};

	PlayerController();
	virtual ~PlayerController();

	void StartFrame();
	void OnEvent(fw::Event* pEvent);

	bool IsHeld(Mask mask);
	bool WasPressed(Mask mask);
	bool WasReleased(Mask mask);

protected:
	unsigned int m_Flags = 0;
	unsigned int m_OldFlags = 0;
};