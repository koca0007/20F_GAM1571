#include "GamePCH.h"

#include "PlayerController.h"

PlayerController::PlayerController()
{
}

PlayerController::~PlayerController()
{
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
				if (pInputEvent->GetKeyCode() == 'W') { m_Flags |= Up;	  }
				if (pInputEvent->GetKeyCode() == 'S') { m_Flags |= Down;  }
				if (pInputEvent->GetKeyCode() == 'A') { m_Flags |= Left;  }
				if (pInputEvent->GetKeyCode() == 'D') { m_Flags |= Right; }
			}

			if (pInputEvent->GetDeviceState() == fw::InputEvent::DeviceState::Released)
			{
				if (pInputEvent->GetKeyCode() == 'W') { m_Flags &= ~Up; }
				if (pInputEvent->GetKeyCode() == 'S') { m_Flags &= ~Down; }
				if (pInputEvent->GetKeyCode() == 'A') { m_Flags &= ~Left; }
				if (pInputEvent->GetKeyCode() == 'D') { m_Flags &= ~Right; }
			}
		}
	}
}