#pragma once

#include "../Math/Vector.h"

namespace fw {

	class Mesh;
	class ShaderProgram;
	class GameCore;
	class FWCore;
	class Texture;

	class GameObject
	{
	public:
		GameObject();
		GameObject(std::string name, Vector2 pos, Mesh* pMesh, ShaderProgram* pShader, Texture* pTexture, Vector4 color, GameCore* pGameCore);
		virtual ~GameObject();

		virtual void Update(float DeltaTime);
		virtual void Draw();

		std::string GetName();
		Vector2 m_Position;
		
		void SetColor(Vector4 newColor) { m_Color = newColor; }
		Vector4 GetColor() { return m_Color; }
		void SetAlpha(float newAlpha) { m_Color.a = newAlpha; }

		Vector2 GetPosition() { return m_Position; }
		void SetPosition(Vector2 newPos) { m_Position = newPos; }

		void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }
		Texture* GetTexture() { return m_pTexture; }

	protected:
		std::string m_Name;
		Mesh* m_pMesh = nullptr;
		ShaderProgram* m_pShader = nullptr;
		Texture* m_pTexture = nullptr;
		GameCore* m_GameCore;
		Vector4 m_Color = Vector4(1, 1, 1, 1);

		Vector2 m_UVScale  = Vector2(1, 1);
		Vector2 m_UVOffset = Vector2(0, 0);
	};

} // namespace fw