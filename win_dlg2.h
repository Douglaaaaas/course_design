#pragma once
#include "afxdialogex.h"


// win_dlg2 对话框

class win_dlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(win_dlg2)

public:
	win_dlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~win_dlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
