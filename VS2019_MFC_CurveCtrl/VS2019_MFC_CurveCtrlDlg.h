
// VS2019_MFC_CurveCtrlDlg.h : header file
//

#pragma once


// CVS2019MFCCurveCtrlDlg dialog
class CVS2019MFCCurveCtrlDlg : public CDialogEx
{
// Construction
public:
	CVS2019MFCCurveCtrlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VS2019_MFC_CURVECTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
