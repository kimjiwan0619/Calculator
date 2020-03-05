
// CalculatorDlg.h: 헤더 파일
//

#pragma once
#include "resource.h"

// CCalculatorDlg 대화 상자
class CCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonLeftBracket();
	afx_msg void OnBnClickedButtonRightBracket();
	afx_msg void OnBnClickedButtonEqual();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	BOOL PreTranslateMessage(MSG* pMsg);
	CString lastStr(); // 마지막 문자
	bool overDotNum = false; // 소수점 전후 구분
	bool calcOver = false; // 연산식이 끝났는지
	bool checkNum = false; // 마지막 문자가 숫자인지
	bool checkOp = false; // 마지막 문자가 operator인지
	bool checkDot = false; // dot 쓸수 있는지
	bool checkBracket(); // '('괄호개수가 ')'개수보다 많거나 같은지
	int cntLeftBracket = 0; //'('개수
	int cntRightBracket = 0; //')'개수
};
