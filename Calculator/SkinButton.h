#pragma once

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

class CSkinButton : public CButton
{
public:
	CSkinButton();
	~CSkinButton();

public:
	void SetColorBackground(int a, int r, int g, int b);
	void SetColorBorder(int a, int r, int g, int b);
	void SetColorText(int a, int r, int g, int b);
	void SetSizeText(float size);
	void SetStrText(CString str);
private:
	Gdiplus::Color m_clrBackground;
	Gdiplus::Color m_clrBorder;
	Gdiplus::Color m_clrText;
	float m_fSizeText;
	CString m_strText;
	void DrawBackground(Gdiplus::Graphics* pG); // ��� �׸���.
	void DrawBorder(Gdiplus::Graphics* pG); // �ܰ��� �׸���.
	void DrawText(Gdiplus::Graphics* pG); // �ؽ�Ʈ �׸���.
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};