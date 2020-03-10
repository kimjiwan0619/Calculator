
// CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <stack> 
#include <queue>

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
	m_btn0.SetStrText(L"0");
	m_btn0.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON0, m_btn0);
	m_btn1.SetStrText(L"1");
	m_btn1.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON1, m_btn1);
	m_btn2.SetStrText(L"2");
	m_btn2.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON2, m_btn2);
	m_btn3.SetStrText(L"3");
	m_btn3.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON3, m_btn3);
	m_btn4.SetStrText(L"4");
	m_btn4.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON4, m_btn4);
	m_btn5.SetStrText(L"5");
	m_btn5.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON5, m_btn5);
	m_btn6.SetStrText(L"6");
	m_btn6.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON6, m_btn6);
	m_btn7.SetStrText(L"7");
	m_btn7.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON7, m_btn7);
	m_btn8.SetStrText(L"8");
	m_btn8.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON8, m_btn8);
	m_btn9.SetStrText(L"9");
	m_btn9.SetColorBackground(255, 255, 255, 255);
	DDX_Control(pDX, IDC_BUTTON9, m_btn9);
	m_btnC.SetStrText(L"C");
	DDX_Control(pDX, IDC_BUTTON_C, m_btnC);
	m_btnPlus.SetStrText(L"+");
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_btnPlus);
	m_btnMinus.SetStrText(L"-");
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_btnMinus);
	m_btnMul.SetStrText(L"*");
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_btnMul);
	m_btnDivide.SetStrText(L"/");
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_btnDivide);
	m_btnLBracket.SetStrText(L"(");
	DDX_Control(pDX, IDC_BUTTON_LEFT_BRACKET, m_btnLBracket);
	m_btnRBracket.SetStrText(L")");
	DDX_Control(pDX, IDC_BUTTON_RIGHT_BRACKET, m_btnRBracket);
	m_btnDot.SetStrText(L".");
	DDX_Control(pDX, IDC_BUTTON_DOT, m_btnDot);
	m_btnBackSpace.SetStrText(L"←");
	DDX_Control(pDX, IDC_BUTTON_BACKSPACE, m_btnBackSpace);
	m_btnEqual.SetStrText(L"=");
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_btnEqual);
	m_btnCE.SetStrText(L"CE");
	DDX_Control(pDX, IDC_BUTTON_CE, m_btnCE);
	m_btn21.SetStrText(L"+/-");
	DDX_Control(pDX, IDC_BUTTON13, m_btn21);
	m_btn22.SetStrText(L"1/x");
	DDX_Control(pDX, IDC_BUTTON15, m_btn22);
	m_btn23.SetStrText(L"%");
	DDX_Control(pDX, IDC_BUTTON12, m_btn23);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_edit);
}
	

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_LEFT_BRACKET, &CCalculatorDlg::OnBnClickedButtonLeftBracket)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT_BRACKET, &CCalculatorDlg::OnBnClickedButtonRightBracket)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_BACKSPACE, &CCalculatorDlg::OnBnClickedButtonBackspace)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_KEYUP()
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	CRect r;
	CFont g_editFont;

	g_editFont.CreateFont(20, // nHeight
		10, // nWidth
		0, // nEscapement
		0, // nOrientation
		900, // nWeight
		0, // bItalic
		0, // bUnderline 
		0, // cStrikeOut 
		0, // nCharSet
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		0,                              // nClipPrecision 
		DEFAULT_QUALITY,       // nQuality
		DEFAULT_PITCH | FF_DONTCARE,  // nPitchAndFamily 
		TEXT("굴림"));

	GetDlgItem(IDC_EDIT_RESULT)->SetFont(&g_editFont);

	// 먼저 여백을 부여하고자 하는 에디트 컨트롤의 기본 여백정보를 읽어옵니다.
	m_edit.GetRect(r);

	r.top += 19;
	r.bottom -= 19;

	// 변경된 정보를 해당 에디트 컨트롤에 적용합니다.
	m_edit.SetRect(r);
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

BOOL CCalculatorDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString str, num_str, op_str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (IDC_BUTTON0 <= wParam && wParam <= IDC_BUTTON9 )
	{
		m_bIsOverDot2 = m_bIsOverDot;
		if (m_bCalcIsOver)
			OnBnClickedButtonC();
		GetDlgItemText(IDC_EDIT_RESULT, str);
		num_str.Format(_T("%d"), int(wParam - IDC_BUTTON0));
		if (str == "" || str == '0')
		{
			SetDlgItemText(IDC_EDIT_RESULT, num_str);
			m_bIsNewNum = false;
			if (!m_bIsOverDot)
				m_bDotEnable = true;
			m_bLastIsOp = false;
			m_bLastIsNum = true;
		}
		else if (m_bIsNewNum && m_strLastChar() == '0')
		{
			str.Delete(str.GetLength() - 1, 1);
			SetDlgItemText(IDC_EDIT_RESULT, str + num_str);
			if (num_str != '0')
				m_bIsNewNum = false;
			if (!m_bIsOverDot)
				m_bDotEnable = true;
			m_bLastIsOp = false;
			m_bLastIsNum = true;
		}
		else if (m_strLastChar() != ')')
		{
			SetDlgItemText(IDC_EDIT_RESULT, str + num_str);
			if (m_bIsNewNum && num_str == '0')
				m_bIsNewNum = true;
			else
				m_bIsNewNum = false;
			if (!m_bIsOverDot)
				m_bDotEnable = true;
			m_bLastIsOp = false;
			m_bLastIsNum = true;
		}
	}
	else if (IDC_BUTTON_PLUS <= wParam && wParam <= IDC_BUTTON_DIVIDE)
	{
		m_bIsOverDot2 = m_bIsOverDot;
		GetDlgItemText(wParam, op_str);
		if (wParam == IDC_BUTTON_MINUS && str == "")
		{
			SetDlgItemText(IDC_EDIT_RESULT, op_str);
			m_bDotEnable = false;
			m_bLastIsNum = false;
			m_bLastIsOp = true;
			m_bIsOverDot = false;
		}
		else if (!m_bLastIsOp && (m_bLastIsNum || m_strLastChar() == ')'))
		{
			SetDlgItemText(IDC_EDIT_RESULT, str + op_str);
			m_bDotEnable = false;
			m_bLastIsNum = false;
			m_bLastIsOp = true;
			m_bIsOverDot = false;
		}
		else if (str == '-')
		{
			if (wParam == IDC_BUTTON_PLUS)
			{
				OnBnClickedButtonC();
			}
			else 
				return CDialogEx::OnCommand(wParam, lParam);
		}
		else if (m_bLastIsOp)
		{
			str.Delete(str.GetLength() -1 , 1);
			SetDlgItemText(IDC_EDIT_RESULT, str + op_str);
			m_bDotEnable = false;
			m_bLastIsNum = false;
			m_bLastIsOp = true;
			m_bIsOverDot = false;
		}
		m_bCalcIsOver = false;
		m_bIsNewNum = true;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

void CCalculatorDlg::OnBnClickedButtonLeftBracket()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bCalcIsOver)
		OnBnClickedButtonC();
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (m_bCheckBracket() && ! m_bLastIsNum && !m_bIsOverDot && m_strLastChar() != ')')
	{
		if (m_strLastChar() == '0')
			SetDlgItemText(IDC_EDIT_RESULT, L"(");
		else
			SetDlgItemText(IDC_EDIT_RESULT, str + "(");
		m_nCntLeftBracket++;
		m_bIsNewNum = true;
		m_bLastIsOp = false;
		m_bLastIsNum = false;
	}
}

void CCalculatorDlg::OnBnClickedButtonC()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_RESULT, L"");
	m_bIsOverDot = false;
	m_bLastIsNum = false;
	m_bLastIsOp = false;
	m_bDotEnable = false;
	m_bCalcIsOver = false;
	m_nCntLeftBracket = 0;
	m_nCntRightBracket = 0;
}

void CCalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bDotEnable &&  m_bLastIsNum && !m_bCalcIsOver)
	{
		CString str;
		GetDlgItemText(IDC_EDIT_RESULT, str);
		SetDlgItemText(IDC_EDIT_RESULT, str + ".");
		m_bDotEnable = false;
		m_bLastIsNum = false;
		m_bIsOverDot = true;
		m_bCalcIsOver = false;
	}
}

CString CCalculatorDlg::m_strLastChar()
{
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	return str.Right(1);
}

void CCalculatorDlg::OnBnClickedButtonRightBracket()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	m_nCntRightBracket++;
	if (m_bCheckBracket() && ( m_bLastIsNum || m_strLastChar() == ")"))
	{
		SetDlgItemText(IDC_EDIT_RESULT, str + ")");
		m_bLastIsNum = false;
	}
	else
		m_nCntRightBracket--;
}

bool CCalculatorDlg::m_bCheckBracket()
{
	if (m_nCntLeftBracket >= m_nCntRightBracket)
		return true;
	else
		return false;
}

void CCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (str.Left(1) == '-')
		str = '0' + str;
	std::stack<CString> stack;
	std::queue<CString> queue;
	if (str == "")
		return;
	else if (m_nCntLeftBracket != m_nCntRightBracket)
	{
		AfxMessageBox(L"괄호 개수가 안맞습니다.");
		return;
	}
	else if (! m_bLastIsNum && m_strLastChar() != ')' && !m_bCalcIsOver)
	{
		AfxMessageBox(L"end error");
		return;
	}
	else
	{
		// 후위표기법으로 변환
		CString str2, num_str;
		for (int pos = 0; pos < str.GetLength(); pos++)
		{
			str2 = str[pos];
			if (str2 == "(")
				stack.push(str2);
			else if (isdigit(str[pos]) || str2 == ".")
			{
				num_str += str[pos];
				if (pos == str.GetLength() - 1)
					queue.push(num_str);
			}
			else if (str2 == ")")
			{
				if (num_str != "")
				{
					queue.push(num_str);
					num_str = "";
				}

				while (stack.top() != "(")
				{
					queue.push(stack.top());
					stack.pop();
				}
				stack.pop();
			}
			else
			{
				if (num_str != "")
				{
					queue.push(num_str);
					num_str = "";
				}
				while (!stack.empty() && m_iOpToInt(stack.top()) >= m_iOpToInt(str2))
				{
					queue.push(stack.top());
					stack.pop();
				}
				stack.push(str2);
			}
		}
		while (!stack.empty())
		{
			queue.push(stack.top());
			stack.pop();
		}

		//후위표기법 계산
		while (!queue.empty())
		{
			if (_wtof(queue.front()) || queue.front().Left(1) == "0")
				stack.push(queue.front());
			else
			{
				CString num1, num2;
				double num;
				num1 = stack.top();
				stack.pop();
				num2 = stack.top();
				stack.pop();
				if (queue.front() == "+")
				{
					num = _wtof(num2) + _wtof(num1);
					num1.Format(L"%.2f", num);
					stack.push(num1);
				}
				else if (queue.front() == "-")
				{
					num = _wtof(num2) - _wtof(num1);
					num1.Format(L"%.2f", num);
					stack.push(num1);
				}
				else if (queue.front() == "*")
				{
					num = _wtof(num2) * _wtof(num1);
					num1.Format(L"%.2f", num);
					stack.push(num1);
				}
				else if (queue.front() == "/")
				{
					if (_wtof(num1) == 0)
					{
						AfxMessageBox(L"잘못된 연산식 입니다.");
						OnBnClickedButtonC();
						return;
					}		
					else
					{
						num = _wtof(num2) / _wtof(num1);
						num1.Format(L"%.2f", num);
						stack.push(num1);
					}
				}
			}
			queue.pop();
		}

		if (!stack.empty())
		{
			double result = _wtof(stack.top());
			stack.top().Format(L"%.2f", result);
			stack.top().TrimRight(L"0");
			stack.top().TrimRight(L".");
			SetDlgItemText(IDC_EDIT_RESULT, stack.top());
			m_bCalcIsOver = true;
			m_bLastIsNum = true;
			/*if (stack.top() == '0')
				m_bCalcIsOver = false;*/
			if (stack.top().Find('.') != -1)
				m_bDotEnable = false;
		}
		//else
		//	OnBnClickedButtonC();
	}
}

void CCalculatorDlg::OnBnClickedButtonBackspace()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bCalcIsOver)
		return;
	CString str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (str != "")
	{
		int lastOp = m_iOpToInt(m_strLastChar());
		if (lastOp == 3)
		{
			m_bIsOverDot = false;
		}
		else if (lastOp == 0)
		{
			m_nCntLeftBracket--;
		}
		else if (lastOp == 1 || lastOp == 2)
		{
			m_bIsNewNum = false;
		}
		else if (lastOp == -1)
		{
			m_nCntRightBracket--;
		}
		str.Delete(str.GetLength() - 1, 1);
		SetDlgItemText(IDC_EDIT_RESULT, str);
		lastOp = m_iOpToInt(m_strLastChar());
		if (lastOp == 4)
		{
			m_bLastIsNum = true;
			m_bLastIsOp = false;
			m_bIsOverDot = m_bIsOverDot2;
			if (!m_bIsOverDot)
				m_bDotEnable = true;
		}
		else if (lastOp == 1 || lastOp == 2)
		{
			m_bLastIsOp = true;
			m_bLastIsNum = false;
		}
		else if (lastOp == 3)
		{
			m_bLastIsOp = false;
			m_bLastIsNum = false;
		}
		else if (lastOp == 0)
		{
			m_bLastIsOp = false;
			m_bLastIsNum = false;
			m_bDotEnable = false;
			m_bIsNewNum = true;
		}
		else if (lastOp == -1)
		{
			m_bLastIsOp = false;
			m_bLastIsNum = false;
			m_bDotEnable = false;
			m_bIsNewNum = true;
		}
		if (str == "")
		OnBnClickedButtonC();
	}
}

int CCalculatorDlg::m_iOpToInt(CString str)
{
	if (str == '+' || str == '-')
		return 1;
	else if (str == '*' || str == '/')
		return 2;
	else if (str == '.')
		return 3;
	else if (str == '(')
		return 0;
	else if (str == ')')
		return -1;
	else
		return 4;
}

//키보드 입력
BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_CHAR)
	{
		switch ((TCHAR)pMsg->wParam)
		{	
		case _T('1'):
		{
			m_btn1.ChangeColorBackground(255, 214, 214, 214);
			m_btn1.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('2'):
		{
			m_btn2.ChangeColorBackground(255, 214, 214, 214);
			m_btn2.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('3'):
		{
			m_btn3.ChangeColorBackground(255, 214, 214, 214);
			m_btn3.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('4'):
		{
			m_btn4.ChangeColorBackground(255, 214, 214, 214);
			m_btn4.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('5'):
		{
			m_btn5.ChangeColorBackground(255, 214, 214, 214);
			m_btn5.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('6'):
		{
			m_btn6.ChangeColorBackground(255, 214, 214, 214);
			m_btn6.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('7'):
		{
			m_btn7.ChangeColorBackground(255, 214, 214, 214);
			m_btn7.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('8'):
		{
			m_btn8.ChangeColorBackground(255, 214, 214, 214);
			m_btn8.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('9'):
		{
			m_btn9.ChangeColorBackground(255, 214, 214, 214);
			m_btn9.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		case _T('0'):
		{
			m_btn0.ChangeColorBackground(255, 214, 214, 214);
			m_btn0.Invalidate();
			int nInputNum = pMsg->wParam - '0';
			int nSendIDC = nInputNum + IDC_BUTTON0;
			OnCommand(nSendIDC, 0);
			break;
		}
		
		case _T('.'):
			m_btnDot.ChangeColorBackground(255, 214, 214, 214);
			m_btnDot.Invalidate();
			OnBnClickedButtonDot();
			break;
		case _T('+'):
			m_btnPlus.ChangeColorBackground(255, 0, 119, 200);
			m_btnPlus.Invalidate();
			OnCommand(IDC_BUTTON_PLUS, 0);
			break;
		case _T('-'):
			m_btnMinus.ChangeColorBackground(255, 0, 119, 200);
			m_btnMinus.Invalidate();
			OnCommand(IDC_BUTTON_MINUS, 0);
			break;
		case _T('/'):
			m_btnDivide.ChangeColorBackground(255, 0, 119, 200);
			m_btnDivide.Invalidate();
			OnCommand(IDC_BUTTON_DIVIDE, 0);
			break;
		case _T('*'):
			m_btnMul.ChangeColorBackground(255, 0, 119, 200);
			m_btnMul.Invalidate();
			OnCommand(IDC_BUTTON_MULTIPLY, 0);
			break;
		case _T('='):
			m_btnEqual.ChangeColorBackground(255, 0, 119, 200);
			m_btnEqual.Invalidate();
			OnBnClickedButtonEqual();
			break;
		case _T('c'):
		case _T('C'):
			m_btnC.ChangeColorBackground(255, 214, 214, 214);
			m_btnC.Invalidate();
			OnBnClickedButtonC();
			break;
		case _T('('):
			m_btnLBracket.ChangeColorBackground(255, 214, 214, 214);
			m_btnLBracket.Invalidate();
			OnBnClickedButtonLeftBracket();
			break;
		case _T(')'):
			m_btnRBracket.ChangeColorBackground(255, 214, 214, 214);
			m_btnRBracket.Invalidate();
			OnBnClickedButtonRightBracket();
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			m_btnEqual.ChangeColorBackground(255, 0, 119, 200);
			m_btnEqual.Invalidate();
			OnBnClickedButtonEqual();
			return TRUE;
		}
		else if(pMsg->wParam == VK_BACK)
		{
			m_btnBackSpace.ChangeColorBackground(255, 214, 214, 214);
			m_btnBackSpace.Invalidate();
			OnBnClickedButtonBackspace();
			return TRUE;
		}
		else if (pMsg->wParam == VK_ESCAPE)
		{
			m_btnC.ChangeColorBackground(255, 214, 214, 214);
			m_btnC.Invalidate();
			OnBnClickedButtonC();
			return TRUE;
		}
	}
	else if (pMsg->message == WM_KEYUP)
	{
		m_btn0.ChangeColorBackground(255, 255, 255, 255);
		m_btn1.ChangeColorBackground(255, 255, 255, 255);
		m_btn2.ChangeColorBackground(255, 255, 255, 255);
		m_btn3.ChangeColorBackground(255, 255, 255, 255);
		m_btn4.ChangeColorBackground(255, 255, 255, 255);
		m_btn5.ChangeColorBackground(255, 255, 255, 255);
		m_btn6.ChangeColorBackground(255, 255, 255, 255);
		m_btn7.ChangeColorBackground(255, 255, 255, 255);
		m_btn8.ChangeColorBackground(255, 255, 255, 255);
		m_btn9.ChangeColorBackground(255, 255, 255, 255);
		m_btnC.ChangeColorBackground(255, 240, 240, 240);
		m_btnPlus.ChangeColorBackground(255, 240, 240, 240);
		m_btnMinus.ChangeColorBackground(255, 240, 240, 240);
		m_btnMul.ChangeColorBackground(255, 240, 240, 240);
		m_btnDivide.ChangeColorBackground(255, 240, 240, 240);
		m_btnLBracket.ChangeColorBackground(255, 240, 240, 240);
		m_btnRBracket.ChangeColorBackground(255, 240, 240, 240);
		m_btnDot.ChangeColorBackground(255, 240, 240, 240);
		m_btnBackSpace.ChangeColorBackground(255, 240, 240, 240);
		m_btnEqual.ChangeColorBackground(255, 240, 240, 240);
		m_btn0.Invalidate();
		m_btn1.Invalidate();
		m_btn2.Invalidate();
		m_btn3.Invalidate();
		m_btn4.Invalidate();
		m_btn5.Invalidate();
		m_btn6.Invalidate();
		m_btn7.Invalidate();
		m_btn8.Invalidate();
		m_btn9.Invalidate();
		m_btnC.Invalidate();
		m_btnPlus.Invalidate();
		m_btnMinus.Invalidate();
		m_btnMul.Invalidate();
		m_btnDivide.Invalidate();
		m_btnLBracket.Invalidate();
		m_btnRBracket.Invalidate();
		m_btnDot.Invalidate();
		m_btnBackSpace.Invalidate();
		m_btnEqual.Invalidate();
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}


HBRUSH CCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	switch (nCtlColor) {
	case CTLCOLOR_DLG:   /// 다이얼로그 배경색을 white로.
	{
		return (HBRUSH)GetStockObject(GRAY_BRUSH);
		break;
	}
	//case CTLCOLOR_BTN:    // 버튼의 배경색을 투명으로...
	//{
	//	pDC->SetBkMode(TRANSPARENT);
	//	return (HBRUSH)::GetStockObject(NULL_BRUSH);
	//}
	case CTLCOLOR_STATIC:
	{
		pDC->SetTextColor(RGB(0, 255, 255));  // static text 글자색 변경
		pDC->SetBkMode(TRANSPARENT);   // static text 배경색 투명
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}