
// CalcexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calcex.h"
#include "CalcexDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalcexDlg dialog




CCalcexDlg::CCalcexDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalcexDlg::IDD, pParent)
	, m_hasproc(FALSE)
	, m_num1(_T(""))
	, m_num2(_T(""))
	, m_operator(0)
	, m_show(_T("0"))
	, m_opertatemp(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_show1);
	//  DDX_Text(pDX, IDC_EDIT1, show11);
	DDX_Text(pDX, IDC_EDIT1, m_show);
}

BEGIN_MESSAGE_MAP(CCalcexDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CCalcexDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT1, &CCalcexDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalcexDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalcexDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalcexDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalcexDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalcexDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalcexDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalcexDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalcexDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcexDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcexDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalcexDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcexDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalcexDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalcexDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalcexDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalcexDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalcexDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalcexDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalcexDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalcexDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalcexDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalcexDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalcexDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalcexDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_MFCLINK1, &CCalcexDlg::OnBnClickedMfclink1)
END_MESSAGE_MAP()


// CCalcexDlg message handlers

BOOL CCalcexDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalcexDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalcexDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalcexDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcexDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='8';
	else
		m_show='8';
	UpdateData(FALSE);
}


void CCalcexDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='1';
	else
		m_show='1';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='3';
	else
		m_show='3';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{   m_num2=m_show;
		Algrithm(m_opertatemp);
	}
	m_operator=2;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='4';
	else
		m_show='4';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='5';
	else
		m_show='5';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='6';
	else
		m_show='6';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
		Algrithm(m_opertatemp);
	}
	m_operator=3;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{   m_num2=m_show;
		Algrithm(m_opertatemp);
	}
	m_operator=4;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)   //check if has been proceeded
	{ 
		m_num2=m_show;  //store current data to m_num2 to procedure
	 Algrithm(m_opertatemp);   //Perform arithmetic
	}
	m_operator=1;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';	
}


void CCalcexDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='2';
	else
		m_show='2';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='7';
	else
		m_show='7';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	if (m_show!='0')
		m_show+='9';
	else
		m_show='9';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here

	if (m_show!='0')
		m_show+='0';
	else
		m_show='0';
	UpdateData(FALSE);
}


void CCalcexDlg::Algrithm(int operta)
{
	    m_hasproc=TRUE;  //if m_num1+m_num2 has been proceeded
		double temp1,temp2;
		double temp=0; 
		temp1=_tstof(m_num1);
		temp2=_tstof(m_num2);
	switch(operta)
	{
	  case 1:
		  temp=temp1+temp2;
	      break;
	  case 2:
		  temp=temp1-temp2;
		  break;
	  case 3:
		  temp=temp1*temp2;
		  break;
	  case 4:
		  temp=temp1/temp2;
		  break;
	  case 5:
		  temp=cos(temp1);
		  break;
	  case 6:
		  temp=sin(temp1);
		  break;
	  case 7:
		  temp=tan(temp1);
		  break;
	  case 8:
		  temp=log(temp1);        //log with e 
		  break;
	  case 9:
		  temp=log10(temp1);    //log with 10
		  break;
	  case 10:
		  temp=1.0;
		  for( ;temp2>0.0;--temp2)
		  {
			  temp*=temp1;
		  }
		  break;
	  case 11:
		  temp=1;
		  for (;temp1>0;--temp1)
		  {
              temp*=temp1;
		  }
	  default:break;
	}
	if(temp-(int)temp==0)
	    m_show.Format(_T("%.0f"),temp);
	else
		m_show.Format(_T("%.6f"),temp);	
	UpdateData(FALSE);
	m_opertatemp=0;     //reset the m_opertatemp for the next calculate
}


void CCalcexDlg::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	m_num2=m_show;
	Algrithm(m_operator);
}


void CCalcexDlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	if (m_show!='0')
		m_show+='.';
	UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
   Clear();
   UpdateData(FALSE);
}


void CCalcexDlg::OnBnClickedButton22()
{
	// TODO: Add your control notification handler code here
	m_show=m_show.Left(m_show.GetLength()-1); //提取左边的数值并将其长度减1
	if(m_show=="") 
	{
		m_show='0';
	}
	UpdateData(false);
}

//reset the calculate
void CCalcexDlg::Clear(void)
{
	m_hasproc=FALSE;
	m_show=m_num1=m_num2=_T('');
	m_operator=m_opertatemp=0;	
}


void CCalcexDlg::OnBnClickedButton19()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=5;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=6;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton20()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=7;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton21()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=8;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton24()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=9;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton23()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=10;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedButton25()
{
	// TODO: Add your control notification handler code here
	if (m_opertatemp)
	{ m_num2=m_show;
	Algrithm(m_opertatemp);
	}
	m_operator=11;
	m_opertatemp=m_operator;
	m_num1=m_show;
	m_show='0';
}


void CCalcexDlg::OnBnClickedMfclink1()
{
	// TODO: Add your control notification handler code here
}
