#pragma once
#include "afxdialogex.h"

// D1 对话框
static int k = 1;
class numbercom {
	int max;
	char number[5][5];
	int score;
	int x;
	int next;
	int scorelevel;
	int combinednums;
public:
	void changenum(int queue);
	int level(int queue);
	char getnum(int line, int queue);
	void changenum2(int queue); 
	numbercom() {
		srand((int)time(0));
		max = 1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				number[i][j] = ' ';
			}
		}
		x = 1;
		next = 1;
		scorelevel = 1;
		combinednums = 0;
	}
	void cleanall();
	int return_rand_num() { return this->x; }
	int set_rand_seed();
	int get_score();
	void changescore(int s) { this->score = s; return; }
};

class D1 : public CDialogEx
{
	DECLARE_DYNAMIC(D1)

public:
	CTime t1;//实例化一个时间类，用于保存获取的系统时间。
	virtual void ShowtimeNow();//定时器调用的刷新函数，将实时获取的系统时间反复写入。
	void InitStatus();//初始化状态栏，此函数中将状态栏的显示进行初始化。

	//CStatic m_time;//这是一个Static控件，也是显示的实时时间。此处注释掉了。
	CStatusBar m_bar;//创建一个状态栏实例。
	CRect rect; //实例一个Rect，这个东西后面对状态栏进行等分宽度用。
	D1(CWnd* pParent = nullptr);   // 标准构造函数
	friend class CMFCApplication2Dlg;
	virtual ~D1();
	int difficulty;
	bool cheated;
	bool endlessness;
	bool pourdown;
	bool change;
	friend class CMFCApplication2Dlg;
	bool cheater;
	bool eggon;
	int hit;
	int* seq;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton2();
	CEdit m_editshow;
private:

	CListCtrl m_list;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton5();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CMFCButton BUTTON_1;
	CMFCButton BUTTON_2;
	CMFCButton BUTTON_3;
	CMFCButton BUTTON_4;
	CMFCButton BUTTON_5;

	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit nextnum_edit;
	afx_msg void OnEnChangeEdit3();
	CEdit score_edit;
};