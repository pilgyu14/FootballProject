#include "pch.h"
#include "StartSceneText.h"

StartSceneText::StartSceneText()
   :m_subtitleText(L"Dribble"),
    m_subtitleText2(L"One"),
	m_explanationText(L"Press Enter to start.")
{
}

StartSceneText::~StartSceneText()
{
}

void StartSceneText::Update()
{
}

void StartSceneText::Render(HDC _dc)
{
	Component_Render(_dc);

	HFONT hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("±Ã¼­"));

	HFONT hFont2 = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("±Ã¼­"));

	HFONT oldFont = (HFONT)SelectObject(_dc, hFont);
	SetBkMode(_dc, TRANSPARENT);

	SetTextColor(_dc, RGB(0, 0, 0));

	TextOut(_dc, 430, 100, m_subtitleText.c_str(), m_subtitleText.length());

	SetTextColor(_dc, RGB(255, 215, 0));

	TextOut(_dc, 480, 150, m_subtitleText2.c_str(), m_subtitleText2.length());

	SelectObject(_dc, hFont2);
	SetTextColor(_dc, RGB(255, 255, 255));

	TextOut(_dc, 360, 450, m_explanationText.c_str(), m_explanationText.length());

	SelectObject(_dc, oldFont);
	SetBkMode(_dc, OPAQUE);
	DeleteObject(hFont);
	DeleteObject(hFont2);
}
