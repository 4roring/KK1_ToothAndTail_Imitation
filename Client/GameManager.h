#pragma once
#include "Function.h"
class CGameManager :
	public CSingleton<CGameManager>
{
	friend CSingleton;

private :
	CGameManager();
	virtual ~CGameManager();

public:
	const OBJLIST& GetObjectList(OBJID eObjID) { return m_ObjectList[eObjID]; }
	const D3DCOLOR* GetTeamColor(TEAMID eTeamID) { return &m_TeamColor[eTeamID]; }

public:
	void CreateObject(CGameObject* pObject, OBJID eID);

public:
	void DestroyObject(int eObjID);

public:
	void Initialize();
	void Update(float deltaTime);
	void LateUpdate();
	void Render();
	void Release();

private:
	OBJLIST m_ObjectList[OBJ_END];
	D3DCOLOR m_TeamColor[TEAM_END];
	VECRENDER m_vecRender[LAYER_END];
};

