#include "pch.h"
#include "ResMgr.h"
#include "PathMgr.h"
#include "Image.h"
ResMgr::ResMgr()
{
}

ResMgr::~ResMgr()
{
	/*map<wstring, Image*>::iterator iter;
	for (iter = m_mapImg.begin(); iter != m_mapImg.end(); ++iter)
	{
		delete iter->second;
	}*/
	Safe_Delete_Map(m_mapImg);
}

Image* ResMgr::ImgLoad(const wstring& _strKey, const wstring& _strRelativePath)
{
	Image* pImg = ImgFind(_strKey); 
	if (nullptr != pImg) // 맵에 키가 있으면 그대로 반환 ( 한 번 불러왔던 상태 ) 
	{
		return pImg;
	}
	
	// 없으면 경로 거쳐서 찾아와서 맵에 저장 
	wstring strFilePath = PathMgr::GetInst()->GetRsrcPath(); // 리소스 폴더 위치 
	strFilePath += _strRelativePath;
	pImg = new Image;
	pImg->Load(strFilePath);
	pImg->SetKey(_strKey);
	pImg->SetRelativePath(_strRelativePath);
	m_mapImg.insert(make_pair(_strKey , pImg));
//	m_mapImg.insert({ _strKey , pImg });
	return pImg;
}

Image* ResMgr::ImgFind(const wstring& _strKey)
{
	map<wstring, Res*>::iterator iter = m_mapImg.find(_strKey);
	if (iter == m_mapImg.end())
	{
		return nullptr;
	}
	return (Image*)iter->second;
}
