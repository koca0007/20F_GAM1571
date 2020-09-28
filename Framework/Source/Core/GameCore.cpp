#include "FrameworkPCH.h"


#include "GameCore.h"
#include "FWCore.h"

namespace fw {

	GameCore::GameCore(FWCore* pFramework)
	{
		m_pFramework = pFramework;
	}

	GameCore::~GameCore()
	{
	
	}

	FWCore* GameCore::GetFramework()
	{
		return m_pFramework;
	}

} // namespace 
