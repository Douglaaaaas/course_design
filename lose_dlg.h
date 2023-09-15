#pragma once
#include "afxdialogex.h"


// lose_dlg 对话框

class lose_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(lose_dlg)

public:
	lose_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~lose_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit lose_score;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CMFCButton Button_return;
};
