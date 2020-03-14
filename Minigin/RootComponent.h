#pragma once
class Transform;
class GameObject;
class RootComponent
{
public:
	RootComponent();
	virtual  ~RootComponent() = default;
	GameObject* GetGameObject() const { return m_GameObject; }
	//Transform* GetTransform() const;
	
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	
protected:
	GameObject* m_GameObject;
};

