#pragma once
#include "Object.h"
class Image;
class GoalCircle :
	public Object
{
public:
	GoalCircle();
	~GoalCircle();
private:
	virtual void    Update() override;
	virtual void	Render(HDC _dc) override;
	CLONE(GoalCircle);
private:
	Image* originImg;
	Image* goalImg;
	Image* failImg;
	Image* curImg;
public:
	void ChangeGoal()
	{
		curImg = goalImg;
	}
	void ChangeFail()
	{
		curImg = failImg;
	}
};

