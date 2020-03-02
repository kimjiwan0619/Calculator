
// CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 대화 상자



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonC)
	//ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalculatorDlg::OnBnClickedButtonDot)
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"0");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"0");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"0");
}


void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"1");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"1");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"1");
}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"2");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"2");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"2");
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"3");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"3");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"3");
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"4");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"4");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"4");
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"5");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"5");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"5");
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"6");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"6");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"6");
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"7");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"7");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"7");
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"8");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"8");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"8");
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (isNewNum)
	{
		SetDlgItemText(IDC_EDIT_RESULT, L"9");
		isNewNum = false;
	}
	else if (str == L"0")
		SetDlgItemText(IDC_EDIT_RESULT, L"9");
	else
		SetDlgItemText(IDC_EDIT_RESULT, str + L"9");
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	c_temp = GetDlgItemInt(IDC_EDIT_RESULT);
	SetDlgItemText(IDC_EDIT_RESULT, str);
	flag = 1;
	isNewNum = true;
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	c_temp = GetDlgItemInt(IDC_EDIT_RESULT);
	SetDlgItemText(IDC_EDIT_RESULT, str);
	flag = 2;
	isNewNum = true;
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	c_temp = GetDlgItemInt(IDC_EDIT_RESULT);
	SetDlgItemText(IDC_EDIT_RESULT, str);
	flag = 3;
	isNewNum = true;
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	c_temp = GetDlgItemInt(IDC_EDIT_RESULT);
	SetDlgItemText(IDC_EDIT_RESULT, str);
	flag = 4;
	isNewNum = true;
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	double c_value;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	c_value = _wtof(str);

	switch (flag)
	{
	case 1:
		c_temp = c_temp + c_value;
		flag = 0;
		break;

	case 2:
		c_temp = c_temp - c_value;
		flag = 0;
		break;

	case 3:
		c_temp = c_temp * c_value;
		flag = 0;
		break;

	case 4:
		if (c_value == 0)
			AfxMessageBox(L"잘못된 연산식 입니다.");
		else if (c_temp == 0)
			c_temp = 0;
		else
		{
			c_temp = c_temp / c_value;
			flag = 0;
		}
		break;
	}

	str.Format(L"%.2f", c_temp);
	str.TrimRight(L"0");
	str.TrimRight(L".");
	SetDlgItemText(IDC_EDIT_RESULT, str);
}

void CCalculatorDlg::OnBnClickedButtonC()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_RESULT, L"0");
	isNewNum = true;
	flag = 0;
	c_temp = 0;
}


//void CCalculatorDlg::OnBnClickedButtonDot()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CString str;
//	GetDlgItemText(IDC_EDIT_RESULT, str);
//	SetDlgItemText(IDC_EDIT_RESULT, str + ".");
//}
