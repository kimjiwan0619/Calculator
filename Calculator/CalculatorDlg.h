
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
	afx_msg void OnBnClickedButtonBackspace();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	BOOL PreTranslateMessage(MSG* pMsg);
	CString m_strLastChar(); // 마지막 문자
	bool m_bCheckBracket(); // '('괄호개수가 ')'개수보다 많거나 같은지
	bool m_bIsOverDot = false; // 소수점 전후 구분
	bool m_bCalcIsOver = false; // 연산식이 끝났는지
	bool m_bLastIsNum = false; // 마지막 문자가 숫자인지
	bool m_bLastIsOp = false; // 마지막 문자가 operator인지
	bool m_bDotEnable = false; // dot 쓸수 있는지
	bool m_bIsNewNum = true; // 처음 or 연산자 or 괄호 이후 숫자인지
	int m_iOpToInt(CString); // operator에 값 할당 
	int m_nCntLeftBracket = 0; //'('개수
	int m_nCntRightBracket = 0; //')'개수
};
