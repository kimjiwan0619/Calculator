﻿
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
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 폰트 설정
	/*static CFont font;
	LOGFONT LogFont;
	GetDlgItem(IDC_EDIT_RESULT)->GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight = 20;

	font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_EDIT_RESULT)->SetFont(&font);*/
	CRect r;

	((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->GetRect(r);

	// 상/하는 6만큼씩 여백을 부여합니다.
	r.top += 50;
	r.bottom -= 50;

	// 변경된 정보를 해당 에디트 컨트롤에 적용합니다.
	((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->SetRect(r);
	


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

BOOL CCalculatorDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString str, num_str, op_str;
	GetDlgItemText(IDC_EDIT_RESULT, str);
	if (IDC_BUTTON0 <= wParam && wParam <= IDC_BUTTON9 )
	{
		if (m_bCalcIsOver)
			OnBnClickedButtonC();
		GetDlgItemText(IDC_EDIT_RESULT, str);
		num_str.Format(_T("%d"), int(wParam - IDC_BUTTON0));
		if (str == "" || str == '0')
		{
			SetDlgItemText(IDC_EDIT_RESULT, num_str);
			m_bIsNewNum = false;
		}		
		else if (m_bIsNewNum && m_strLastChar() == '0')
		{
			str.Delete(str.GetLength() - 1, 1);
			SetDlgItemText(IDC_EDIT_RESULT, str + num_str);
			if (num_str != '0')
				m_bIsNewNum = false;
		}
		else
		{
			SetDlgItemText(IDC_EDIT_RESULT, str + num_str);
			if (m_bIsNewNum && num_str == '0')
				m_bIsNewNum = true;
			else
				m_bIsNewNum = false;
		}
			
		if (!m_bIsOverDot)
			m_bDotEnable = true;
		m_bLastIsOp = false;
		m_bLastIsNum = true;
	}
	else if (IDC_BUTTON_PLUS <= wParam && wParam <= IDC_BUTTON_DIVIDE)
	{
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
		case _T('2'):
		case _T('3'):
		case _T('4'):
		case _T('5'):
		case _T('6'):
		case _T('7'):
		case _T('8'):
		case _T('9'):
		case _T('0'):
		{
			int nInputNum = pMsg->wParam - '0';

			int nSendIDC = nInputNum + IDC_BUTTON0;

			OnCommand(nSendIDC, 0);
		}
		break;
		case _T('.'):
			OnBnClickedButtonDot();
			break;
		case _T('+'):
			OnCommand(IDC_BUTTON_PLUS, 0);
			break;
		case _T('-'):
			OnCommand(IDC_BUTTON_MINUS, 0);
			break;
		case _T('/'):
			OnCommand(IDC_BUTTON_DIVIDE, 0);
			break;
		case _T('*'):
			OnCommand(IDC_BUTTON_MULTIPLY, 0);
			break;
		case _T('='):
			OnBnClickedButtonEqual();
			break;
		case _T('c'):
		case _T('C'):
			OnBnClickedButtonC();
			break;
		case _T('('):
			OnBnClickedButtonLeftBracket();
			break;
		case _T(')'):
			OnBnClickedButtonRightBracket();
		}
		return TRUE;
	}

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedButtonEqual();
			return TRUE;
		}
		else if(pMsg->wParam == VK_BACK)
		{
			OnBnClickedButtonBackspace();
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
