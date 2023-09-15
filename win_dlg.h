#pragma once
#include "afxdialogex.h"


// win_dlg 对话框

class win_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(win_dlg)

public:
	win_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~win_dlg();
	bool eggon1;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit win_score;
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
