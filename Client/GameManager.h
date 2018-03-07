#pragma once
#include "Function.h"
class CGameManager :
	public CSingleton<CGameManager>
{
public:
	CGameManager();
	virtual ~CGameManager();

public:
	const OBJLIST& GetObjectList(OBJID eObjID) { return m_ObjectList[eObjID]; }
	const D3DCOLOR* GetTeamColor(TEAMID eTeamID) { return &m_TeamColor[eTeamID]; }

public:
	void CreateObject(CGameObject* pObject, OBJID eID);

public:
	void Initialize();
	void Update(float deltaTime);
	void LateUpdate();
	void Render();

private:
	OBJLIST m_ObjectList[OBJ_END];
	D3DCOLOR m_TeamColor[TEAM_END];
	D3DXVECTOR3 m_vScroll;
};

