#pragma once
#include "Object.h"
#include "Ball.h"
class DiveCollider : public Object
{
private:
	float m_xSize; 
	bool m_isCollision; 
	Ball* m_target; 
public:
	DiveCollider(float size); 
	~DiveCollider(); 
public:
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	void Render(HDC _dc) override;
	CLONE(DiveCollider); 
	void EnterCollision(Collider* collider) override; 
	void ExitCollision(Collider* collider) override; 
public:
	bool GetIsCollision() { return m_isCollision; } // ���� �浹�ߴ°� 
	Ball* GetTarget() { return m_target; }
};

