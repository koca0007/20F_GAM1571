#pragma once

#include "../Math/Vector.h"

namespace fw {

	class Mesh;
	class ShaderProgram;
	class GameCore;
	class FWCore;

	class GameObject
	{
	public:
		GameObject();
		GameObject(std::string name, Vector2 pos, Mesh* pMesh, ShaderProgram* pShader, Vector4 color, GameCore* pGameCore);
		virtual ~GameObject();

		virtual void Update(float DeltaTime);
		virtual void Draw();

		std::string GetName();
		Vector2 m_Position;
		Vector4 m_Color = Vector4(1, 1, 1, 1);

		Vector2 GetPosition() { return m_Position; }
		void SetPosition(Vector2 newPos) { m_Position = newPos; }
		

	protected:
		

		std::string m_Name;

		Mesh* m_pMesh = nullptr;
		ShaderProgram* m_pShader = nullptr;
		GameCore* m_GameCore;
	};

} // namespace fw