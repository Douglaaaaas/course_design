
// MFCApplication2Dlg.h: 头文件
//

#pragma once


// CMFCApplication2Dlg 对话框
class CMFCApplication2Dlg : public CDialogEx
{
// 构造
private:
	CStatic m_static;
	CFont m_font;
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	bool cheated1;
	static int times;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	CMFCButton BUTTON_help;
	CMFCButton BUTTON_A;
	CMFCButton BUTTON_B;
	CMFCButton BUTTON_C;
	CMFCButton BUTTON_D;
	CMFCButton BUTTON_E;
	CMFCButton BUTTON_OK;
};
