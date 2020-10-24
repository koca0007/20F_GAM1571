#include "GamePCH.h"

#include "PlayerController.h"

PlayerController::PlayerController()
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::StartFrame()
{
	m_OldFlags = m_Flags;
}

bool PlayerController::IsHeld(Mask mask)
{
	return (m_Flags & mask) > 0; 
}

bool PlayerController::WasPressed(Mask mask)
{
	return ((m_Flags & mask) != 0) && ((m_OldFlags & mask) == 0);
}

bool PlayerController::WasReleased(Mask mask)
{
	return ((m_Flags & mask) == 0) && ((m_OldFlags & mask) != 0);
}

void PlayerController::OnEvent(fw::Event* pEvent)
{
	if (pEvent->GetType() == fw::InputEvent::GetStaticEventType())
	{
		fw::InputEvent* pInputEvent = static_cast<fw::InputEvent*>(pEvent);

		if (pInputEvent->GetDeviceType() == fw::InputEvent::DeviceType::Keyboard)
		{
			if (pInputEvent->GetDeviceState() == fw::InputEvent::DeviceState::Pressed)
			{
				if (pInputEvent->GetKeyCode() == 'W') { m_Flags |= Mask::Up;	  }
				if (pInputEvent->GetKeyCode() == 'S') { m_Flags |= Mask::Down;    }
				if (pInputEvent->GetKeyCode() == 'A') { m_Flags |= Mask::Left;	  }
				if (pInputEvent->GetKeyCode() == 'D') { m_Flags |= Mask::Right;	  }
				if (pInputEvent->GetKeyCode() == 'R') { m_Flags |= Mask::Restart; }
				if (pInputEvent->GetKeyCode() == 'E') { m_Flags |= Mask::Start;   }
			}

			if (pInputEvent->GetDeviceState() == fw::InputEvent::DeviceState::Released)
			{
				if (pInputEvent->GetKeyCode() == 'W') { m_Flags &= ~Mask::Up;		}
				if (pInputEvent->GetKeyCode() == 'S') { m_Flags &= ~Mask::Down;		}
				if (pInputEvent->GetKeyCode() == 'A') { m_Flags &= ~Mask::Left;		}
				if (pInputEvent->GetKeyCode() == 'D') { m_Flags &= ~Mask::Right;	}
				if (pInputEvent->GetKeyCode() == 'R') { m_Flags &= ~Mask::Restart;	}
				if (pInputEvent->GetKeyCode() == 'E') { m_Flags &= ~Mask::Start;	}
			}
		}
	}
}