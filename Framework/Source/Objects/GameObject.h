#pragma once

#include "Math/Vector.h"

namespace fw {

	class Mesh;
	class ShaderProgram;
	class GameCore;
	class FWCore;

	class GameObject
	{
	public:
		GameObject(Vector2 vec2, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore);
		virtual ~GameObject();

		virtual void Update();
		virtual void Draw();

	protected:
		Vector2 position;

		Mesh* m_pMesh = nullptr;
		ShaderProgram* m_pShader = nullptr;
		GameCore* m_GameCore;
	};

} // namespace fw