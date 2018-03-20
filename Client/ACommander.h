#pragma once
#include "Actor.h"

class DCommand;
class ACommander :
	public AActor
{
public:
	ACommander();
	virtual ~ACommander();

public:
	virtual HRESULT Initialize() override;
	virtual OBJSTATE Update(float deltaTime) override;
	virtual void LateUpdate() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	void AddFood(int iFood);
	void SetFarmReserve(bool bReserve) { m_bFarmReserve = bReserve; }

public:
	const int GetFood() const { return m_iFood; }

private:
	enum ANIMSTATE { Idle, Order, Run, Build, RunOrder, RunBuild, ReturnHome, Dead, End };
	ANIMSTATE m_eCurAnimState = ACommander::Idle;
	ANIMSTATE m_ePreAnimState = ACommander::End;
	
private:
	void InitCommander();
	void SetCommand();
	void UpdateState(float deltaTime);
	void Move(float deltaTime);
	void SetAnimState();
	void OrderToUnit();

private: // 건물 생산과 관련된 함수들
	void CheckTileObject();
	void CheckHQ();
	void CheckFarm();
	void CheckSlotUnit();
	bool CheckTile4x4(VECCOLLTILE& vecRange, int iDir);
	void CreateSlotUnitFactory(int iStart);
	bool CheckUnitFactoryPay();

private:
	bool CheckTileEmpty(COLLTILE* pTile);

private:
	bool CheckObjectID(CGameObject* pObject, OBJID eObjectID);
	bool CheckObjectTeam(CGameObject* pObject, TEAMID eTeam);
	bool CheckObjectNetual(CGameObject* pObject, OBJID eObjectID);

private:
	bool OffsetX();
	bool OffsetY();

private:
	DCommand* m_pCommand;
	friend class DPlayerCommand;
	friend class DAICommand;

private:
	int m_iFood = 0;
	bool m_bFarmReserve = false;
	float m_fReturn = 0.f;
	float m_fOrder = 0.f;
	bool m_bBuild = false;
	int m_iSelectSlot = 0;
	UNITID m_eUnit[SLOT_MAX];
	bool m_bAllOrder = false;
	VECCOLLTILE m_vecPath;
};

