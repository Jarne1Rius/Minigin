#pragma once
#include "Transform.h"
#include "SceneObject.h"

class RootComponent;
namespace dae
{
	class Texture2D;
	class GameObject : public SceneObject
	{
	public:
		void Update() override;
		void Render() const override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		template <typename T>
		T* GetComponentOfType()
		{
			const type_info& infoComp = typeid(T);
			for (RootComponent* Component : m_pComponents)
			{
				if (Component && typeid(*Component) == infoComp) return Component;
			}
			return nullptr;
		}

		template <typename T>
		std::vector<T*> GetComponentsOfType()
		{
			const type_info& infoComp = typeid(T);
			std::vector<T*> components;
			for (RootComponent* Component : m_pComponents)
			{
				if (Component && typeid(*Component) == infoComp) components.push_back(components);
			}
			return nullptr;
		}

	private:
		Transform m_Transform;
		std::shared_ptr<Texture2D> m_Texture{};
		std::vector<RootComponent*> m_pComponents{};
	};
}
