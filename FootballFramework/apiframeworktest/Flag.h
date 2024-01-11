#pragma once
#include "Object.h"
class Image;
class Arrow;
class Flag :
    public Object
{
public:
	Flag();
	~Flag();
private:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	CLONE(Flag);
private:
	Image* f_curImg;
	wstring flags[6];
	int curIndex;
	bool check;
	Arrow* arrowUP;
	Arrow* arrowDown;
	wstring rule;
	wstring rule2;
public:
	void SetcurIndex(int index)
	{
		curIndex = index;
	}
	void SetCheck(bool _check);
	void SetIndexImage();
};

