#include "pch.h"
#include "SkinButton.h"

CSkinButton::CSkinButton()
{
	m_clrBackground = Gdiplus::Color(255, 240, 240, 240);
	m_clrBorder = Gdiplus::Color(255, 128, 128, 128);
	m_clrText = Gdiplus::Color(255, 0, 0, 0);
	m_fSizeText = 15;
	m_clrOriginalBackground = m_clrBackground;
}

CSkinButton::~CSkinButton()
{
}

void CSkinButton::SetColorBackground(int a, int r, int g, int b)
{
	m_clrBackground = Gdiplus::Color(a, r, g, b);
	m_clrOriginalBackground = m_clrBackground;
}

void CSkinButton::ChangeColorBackground(int a, int r, int g, int b)
{
	m_clrBackground = Gdiplus::Color(a, r, g, b);
}

void CSkinButton::SetColorBorder(int a, int r, int g, int b)
{
	m_clrBorder = Gdiplus::Color(a, r, g, b);
}

void CSkinButton::SetColorText(int a, int r, int g, int b)
{
	m_clrText = Gdiplus::Color(a, r, g, b);
}

void CSkinButton::SetSizeText(float size)
{
	m_fSizeText = size;
}

void CSkinButton::SetStrText(CString str)
{
	m_strText = str;
}

void CSkinButton::DrawBackground(Graphics* pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::SolidBrush brush(m_clrBackground);

	pG->FillRectangle(&brush, rect.left, rect.top, rect.right, rect.bottom);
}

void CSkinButton::DrawBorder(Graphics* pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::Pen pen(m_clrBorder, 1);
	pG->DrawRectangle(&pen, rect.left, rect.top, rect.Width(), rect.Height());
}

void CSkinButton::DrawText(Graphics* pG)
{
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::FontFamily fontfam(_T("Arial"));
	Gdiplus::Font font(&fontfam, m_fSizeText, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);

	Gdiplus::StringFormat stringAlign;
	stringAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::SolidBrush brush(m_clrText);

	pG->DrawString(m_strText, m_strText.GetLength(), &font,
		Gdiplus::RectF((float)rect.left, (float)rect.top, (float)rect.Width(),(float)rect.Height()), &stringAlign, &brush);
}
BEGIN_MESSAGE_MAP(CSkinButton, CButton)
	ON_WM_PAINT()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()


void CSkinButton::OnPaint()
{
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	Graphics mainG(dc.GetSafeHdc());

	Bitmap bmp(rect.Width(), rect.Height());

	Graphics memG(&bmp);

	SolidBrush brush(m_clrBackground);
	memG.FillRectangle(&brush, 0, 0, rect.Width(), rect.Height());

	DrawBackground(&memG);
	DrawBorder(&memG);
	DrawText(&memG);

	mainG.DrawImage(&bmp, 0, 0);
}

void CSkinButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	RECT rt;
	GetWindowRect(&rt);
	
	CPoint ptInRect = point;
	ptInRect.x = rt.left + point.x;
	ptInRect.y = rt.top + point.y; 
	//TRACE(_T("%d-%d-%d-%d, %d:%d, %d\r\n"), rt.top, rt.left, rt.bottom, rt.right, rt.top, ptInRect.y, point.y);
	if (PtInRect(&rt, ptInRect) == TRUE)
	{
		if (m_strText == L'+' || m_strText == L'-' || m_strText == L'*' || m_strText == L'/' || m_strText == L'=')
			ChangeColorBackground(255, 0, 119, 200);
		else
			ChangeColorBackground(255, 214, 214, 214);
	}
	CButton::OnMouseMove(nFlags, point);
}


void CSkinButton::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	POINT mousePos;
	GetCursorPos(&mousePos);

	CRect clientRect;

	GetClientRect(&clientRect);

	if (mousePos.x >= clientRect.right)
	{
		m_clrBackground = m_clrOriginalBackground;
	}
	CButton::OnMouseLeave();
}
