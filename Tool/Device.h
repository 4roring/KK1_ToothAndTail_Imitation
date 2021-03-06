#pragma once
class CDevice
	: public CSingleton<CDevice>
{
private:
	friend CSingleton;
	CDevice();
	virtual ~CDevice();
	CDevice(const CDevice&) = delete;
	CDevice& operator=(CDevice&) = delete;
public:
	HRESULT InitDevice();

public:
	void Begin();
	void End(HWND hWnd);

public:
	LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
	LPD3DXSPRITE GetSprite() { return m_pSprite; }
	LPD3DXFONT GetFont() { return m_pFont; }



private:
	void SetParameters(D3DPRESENT_PARAMETERS& d3dpp);
	HRESULT FontInit();
	void Release();

private:
	LPDIRECT3D9 m_pD3D9 = nullptr;
	LPDIRECT3DDEVICE9 m_pDevice = nullptr;

	LPD3DXSPRITE m_pSprite = nullptr;
	LPD3DXFONT m_pFont = nullptr;
};

