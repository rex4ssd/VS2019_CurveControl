
// VS2019_MFC_CurveCtrlDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "VS2019_MFC_CurveCtrl.h"
#include "VS2019_MFC_CurveCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVS2019MFCCurveCtrlDlg dialog
typedef struct {
	COLORREF crColour;  // color 
	TCHAR* szName;   // color name
} ColourTableEntry;

// colors
static ColourTableEntry g_crColours[] =
{
	{ RGB(0xFF, 0x00, 0x00),    _T("RED")              },
	{ RGB(0x00, 0x93, 0x00),    _T("GREEN")				},
	{ RGB(0x8B, 0x8B, 0x00),    _T("Dark Yallow")				},
	{ RGB(0x80, 0x00, 0x80),    _T("Purple")				},
	{ RGB(0xFF, 0x68, 0x20),    _T("Orange")				},
	{ RGB(0x00, 0x00, 0x8B),    _T("Dark Blue")				},
	{ RGB(0x00, 0x40, 0x40),    _T("Olive Green")			},
	{ RGB(0xA5, 0x2A, 0x00),    _T("Brown")				},
	{ RGB(0x38, 0x8E, 0x8E),    _T("Cyan")              },
	{ RGB(0x00, 0xFF, 0x00),    _T("Bright Green")				},
	{ RGB(0x4B, 0x00, 0x82),    _T("Indigo")				},
	{ RGB(0xFF, 0xD7, 0x00),    _T("Gold")              },
	{ RGB(0x40, 0xE0, 0xD0),    _T("Cyan")				},
	{ RGB(0xD2, 0xB4, 0x8C),    _T("Brown Yellow")              },
	{ RGB(0x68, 0x83, 0x8B),    _T("Light Blue")				},
};


const int g_nColourCount = sizeof(g_crColours) / sizeof(ColourTableEntry);

#define ID_CURVE_CONTROL   0x9999



CVS2019MFCCurveCtrlDlg::CVS2019MFCCurveCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VS2019_MFC_CURVECTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVS2019MFCCurveCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STATIC_CURVE, m_StcCurve);
}

BEGIN_MESSAGE_MAP(CVS2019MFCCurveCtrlDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CVS2019MFCCurveCtrlDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CVS2019MFCCurveCtrlDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CVS2019MFCCurveCtrlDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVS2019MFCCurveCtrlDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CVS2019MFCCurveCtrlDlg message handlers

BOOL CVS2019MFCCurveCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CRect rect;
	m_StcCurve.GetWindowRect(rect);
	ScreenToClient(rect);

	if (NULL == m_pCurveCtrl)
	{
		m_pCurveCtrl = new CCurveCtrl;
		m_pCurveCtrl->Create(rect, this, ID_CURVE_CONTROL);
		m_pCurveCtrl->SetGridLineStyle(PS_DOT);
		m_pCurveCtrl->SetMargin(CRect(70, 50, 50, 50));
	}


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVS2019MFCCurveCtrlDlg::OnPaint()
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
HCURSOR CVS2019MFCCurveCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVS2019MFCCurveCtrlDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_nCurveCount++;

	float fX = 100;
	float fY = 0;
	CString strTitle;
	strTitle.Format("TestOneCurve%d", m_nCurveCount);
	int index = m_pCurveCtrl->AddCurve(strTitle, g_crColours[m_nCurveCount % g_nColourCount].crColour);
	m_pCurveCtrl->GetCurve(index)->ShowCurve();

	for (float f = 0.0f; f < 6.28f; f += 0.1f)
	{
		fX = f;
		fY = 100.0 * m_nCurveCount * (sin(f));
		m_pCurveCtrl->AddData(strTitle, (m_nCurveCount)* fX, fY);
	}
	fX = 6.28f;
	fY = 100 * m_nCurveCount * float(sin(6.28));
	m_pCurveCtrl->AddData(strTitle, (m_nCurveCount)* fX, fY);

	m_pCurveCtrl->Invalidate();
	//CDialogEx::OnOK();
}


void CVS2019MFCCurveCtrlDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CVS2019MFCCurveCtrlDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	m_nCurveCount = 0;
	m_pCurveCtrl->RemoveAll();
	m_pCurveCtrl->Invalidate();
}



void CVS2019MFCCurveCtrlDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_nCurveCount = 0;
	if ( m_pCurveCtrl) {
		delete m_pCurveCtrl;
		m_pCurveCtrl = NULL;

		CRect rect;
		m_StcCurve.GetWindowRect(rect);
		ScreenToClient(rect);
		if (NULL == m_pCurveCtrl)
		{
			m_pCurveCtrl = new CCurveCtrl;
			m_pCurveCtrl->Create(rect, this, ID_CURVE_CONTROL);
			m_pCurveCtrl->SetGridLineStyle(PS_DOT);
			m_pCurveCtrl->SetMargin(CRect(70, 50, 50, 50));
		}
	}

}
