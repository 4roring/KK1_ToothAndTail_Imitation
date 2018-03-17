#include "stdafx.h"
#include "DSubject.h"
#include "DObserver.h"

DSubject::DSubject()
{
}


DSubject::~DSubject()
{
}

void DSubject::Subscribe(DObserver * pObserver)
{
	if (nullptr == pObserver)
		return;

	m_Observerlist.push_back(pObserver);
}

void DSubject::UnSubscribe(DObserver * pObserver)
{
	auto iter = find(m_Observerlist.begin(), m_Observerlist.end(), pObserver);
	if (iter == m_Observerlist.end())
		return;

	m_Observerlist.erase(iter);
}

void DSubject::Notify(float fOrder, UNITID eUnitID, VECCOLLTILE vecPath)
{
	for (auto& pObserver : m_Observerlist)
		pObserver->UpdateOrder(fOrder, eUnitID, vecPath);
}

void DSubject::Release()
{
	m_Observerlist.clear();
}
