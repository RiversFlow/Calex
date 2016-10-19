
// CalcexDlg.h : header file
//

#pragma once

// CCalcexDlg dialog
class CCalcexDlg : public CDialogEx
{
// Construction
public:
	CCalcexDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CALCEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	BOOL m_hasproc;
	CString m_num1;
	CString m_num2;
	int m_operator;
	afx_msg void OnEnChangeEdit1();
	CString m_show;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton10();
	void Algrithm(int operta);
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton22();
	int m_opertatemp;
	void Clear(void);
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedMfclink1();
};
