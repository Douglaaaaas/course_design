// D1.cpp: 实现文件
//

#include <iostream>
#include <time.h>
#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "D1.h"
#include "lose_dlg.h"
#include "win_dlg.h"
#include "win_dlg2.h"

 int times = 0;
 int times2 = 0;
 int times3 = 0;
 int times4 = 0;
 int times5 = 0;// 放置次数
 numbercom num1;
// D1 对话框



IMPLEMENT_DYNAMIC(D1, CDialogEx)
D1::D1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	this->cheated = false;
	this->cheater = false;
	this->eggon = false;
	this->hit = 0;
	this->seq = new int[7];
}

int numbercom::get_score()
{
	return this->score;
}

D1::~D1()
{

}

int numbercom::set_rand_seed()
{
	if (k == 1) {
		x = rand() % max + 1;
		next = rand() % max + 1;
		k++;
	}
	else {
		x = next;
		next = rand() % max + 1;
		k++;
	}
	return this->x;
}

void D1::DoDataExchange(CDataExchange* pDX)
{// 在这里进行edit control 的修改
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_editshow);
	//	m_editshow.SetWindowTextW(TEXT("1111"));

	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BUTTON1, BUTTON_1);
	DDX_Control(pDX, IDC_BUTTON5, BUTTON_2);
	DDX_Control(pDX, IDC_BUTTON6, BUTTON_3);
	DDX_Control(pDX, IDC_BUTTON7, BUTTON_4);
	DDX_Control(pDX, IDC_BUTTON8, BUTTON_5);
	DDX_Control(pDX, IDC_EDIT3, nextnum_edit);
	DDX_Control(pDX, IDC_EDIT1, score_edit);
}


BEGIN_MESSAGE_MAP(D1, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_EN_CHANGE(IDC_EDIT1, &D1::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &D1::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &D1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &D1::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &D1::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON5, &D1::OnBnClickedButton5)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON6, &D1::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &D1::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &D1::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT3, &D1::OnEnChangeEdit3)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// D1 消息处理程序


BOOL D1::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(&rect);
	//加载背景位图
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP4); //图片ID

	BITMAP bitmap;

	bmpBackground.GetBitmap(&bitmap);
	//选择位图
	//创建内存DC
	CDC dc;
	dc.CreateCompatibleDC(pDC);

	CBitmap* pOldBitmap = dc.SelectObject(&bmpBackground);
	//绘制位图
	SetStretchBltMode(pDC->m_hDC, STRETCH_HALFTONE);//设置指定设备环境中的位图拉伸模式。
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	//恢复原有位图
	dc.SelectObject(pOldBitmap);
	return TRUE;
}

void D1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码	

}


void D1::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void D1::OnBnClickedButton2()
{

	// TODO: 在此添加控件通知处理程序代码
}
BOOL D1::OnInitDialog()               // 初始化窗口
{
	CDialogEx::OnInitDialog();
	BUTTON_1.m_bTransparent = FALSE;
	BUTTON_1.m_bDontUseWinXPTheme = TRUE;
	BUTTON_1.SetFaceColor(RGB(0, 255, 0), true);
	BUTTON_2.m_bTransparent = FALSE;
	BUTTON_2.m_bDontUseWinXPTheme = TRUE;
	BUTTON_2.SetFaceColor(RGB(0, 255, 0), true);
	BUTTON_3.m_bTransparent = FALSE;
	BUTTON_3.m_bDontUseWinXPTheme = TRUE;
	BUTTON_3.SetFaceColor(RGB(0, 255, 0), true);
	BUTTON_4.m_bTransparent = FALSE;
	BUTTON_4.m_bDontUseWinXPTheme = TRUE;
	BUTTON_4.SetFaceColor(RGB(0, 255, 0), true);
	BUTTON_5.m_bTransparent = FALSE;
	BUTTON_5.m_bDontUseWinXPTheme = TRUE;
	BUTTON_5.SetFaceColor(RGB(0, 255, 0), true);
	this->InitStatus();
	// TODO:  在此添加额外的初始化
	int rand_num = num1.set_rand_seed();
	CString str2;
	str2.Format(_T("%d"), rand_num);
	nextnum_edit.SetWindowTextW(str2);
	switch (this->difficulty)
	{
	case -1:m_editshow.SetWindowTextW(TEXT("endless")); break;
	case 0:m_editshow.SetWindowTextW(TEXT("100")); break;
	case 1:m_editshow.SetWindowTextW(TEXT("200")); break;
	case 2:m_editshow.SetWindowTextW(TEXT("300")); break;
	default:exit(1);
	}
	if (!this->cheated)
	{
		score_edit.SetWindowTextW(TEXT("0"));
	}
	else
	{
		this->cheater = true;
		this->cheated = false;
		num1.changescore(20);
		score_edit.SetWindowTextW(TEXT("20"));			//输入作弊码后初始分数+20
	}
	CString str[] = { TEXT("一"),TEXT("二"),TEXT("三"),TEXT("四"),TEXT("五")};
	for (int i = 0; i < 5; ++i)
	{
		m_list.InsertColumn(i, str[i], LVCFMT_LEFT, 95);
	}
	for (int i = 0; i < 5; ++i)
	{
		m_list.InsertItem(i, TEXT(" "));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE

}

void D1::OnBnClickedButton1()
{
	CString a[5][5];
	char str1;
	if (pourdown == FALSE) {
		num1.changenum(0);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 1;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.eggon1 = true;
				wins.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int level0 = num1.level(0);
		int score1 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score1);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	else {
		num1.changenum2(0);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 1;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.eggon1 = true;
				wins.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int level0 = num1.level(0);
		int score1 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score1);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
}

void D1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	num1.cleanall();
	this->hit = 0;
	if (this->seq != nullptr)
	{
		delete[] this->seq;
	}
	this->cheated = false;
	CDialogEx::OnOK();
}

void D1::OnBnClickedButton5()
{
	CString a[5][5];
	char str1;
	if (pourdown == FALSE) {
		num1.changenum(1);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		//设置随机数
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 2;
		}
		else 
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.eggon1 = true;
				wins.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		//设置分数
		int score2 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score2);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(1);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	else {
		num1.changenum2(1);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		//设置随机数
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 2;

		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.eggon1 = true;
				wins.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		//设置分数
		int score2 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score2);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(1);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	// TODO: 在此添加控件通知处理程序代码

}


HBRUSH D1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if ((pWnd->GetDlgCtrlID() == IDC_Stastic))
	{
		pDC->SetTextColor(RGB(0, 0, 139));
		pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if ((pWnd->GetDlgCtrlID() == IDC_Stastic2))
	{
		pDC->SetTextColor(RGB(0, 0, 139));
		pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	if ((pWnd->GetDlgCtrlID() == IDC_STATIC))
	{
		pDC->SetTextColor(RGB(0, 0, 139));
		pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void D1::OnBnClickedButton6()
{
	CString a[5][5];
	char str1;
	if (pourdown == FALSE) {
		num1.changenum(2);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 3;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.DoModal();
				wins.eggon1 = true;
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int score3 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score3);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(2);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	else  {
		num1.changenum2(2);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 3;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.DoModal();
				wins.eggon1 = true;
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int score3 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score3);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(2);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}


void D1::OnBnClickedButton7()
{
	CString a[5][5];
	char str1;
	if (pourdown == FALSE) {
		num1.changenum(3);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 4;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.DoModal();
				wins.eggon1 = true;
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int score3 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score3);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(3);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();;
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	else{
		num1.changenum2(3);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 4;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.DoModal();
				wins.eggon1 = true;
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int score3 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score3);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(3);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();;
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}
void D1::OnBnClickedButton8()
{
	CString a[5][5];
	char str1;
	if (pourdown == FALSE) {
		num1.changenum(4);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 5;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.eggon1 = true;
				wins.DoModal();
				wins.eggon1 = true;
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int score4 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score4);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(4);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();;
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	else {
		num1.changenum2(4);
		for (int m = 0; m <= 4; m++) {
			for (int n = 0; n <= 4; n++) {
				str1 = num1.getnum(m, n);
				a[m][n] = str1;
			}
		}
		if (this->hit < 7)
		{
			this->seq[this->hit++] = 5;
		}
		else
		{
			if (this->seq != nullptr && this->seq[0] == 1 && this->seq[1] == 3 && this->seq[2] == 1 && this->seq[3] == 4 && this->seq[4] == 5 && this->seq[5] == 2 && this->seq[6] == 1)
			{
				delete[] this->seq;
				win_dlg wins;
				wins.eggon1 = true;
				wins.DoModal();
				wins.eggon1 = true;
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int rand_num = num1.set_rand_seed();
		CString str;
		str.Format(_T("%d"), rand_num);
		nextnum_edit.SetWindowTextW(str);
		int score4 = num1.get_score();
		CString c_score;
		c_score.Format(_T("%d"), score4);
		score_edit.SetWindowTextW(c_score);
		if (num1.get_score() >= (this->difficulty + 1) * 100 && difficulty >= 0)
		{
			if (!this->cheater)
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg win;
				win.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
			else
			{
				this->hit = 0;
				if (this->seq != nullptr)
				{
					delete[] this->seq;
				}
				win_dlg2 win2;
				this->cheater = false;
				win2.DoModal();
				num1.cleanall();
				CDialogEx::OnOK();
				return;
			}
		}
		int level0 = num1.level(4);
		if (level0 >= 5)
		{
			this->hit = 0;
			if (this->seq != nullptr)
			{
				delete[] this->seq;
			}
			lose_dlg los;
			los.DoModal();
			CDialogEx::OnOK();;
			num1.cleanall();
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				m_list.SetItemText(4 - i, j, a[i][j]);
			}
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}
void numbercom::changenum(int queue) {
	srand(time(0));
	int i = 4;
	while (i > 0 && number[i][queue] != ' ') {
		i--;
	}
	number[i][queue] = x + '0';
	bool Combine = false;
	int k, m, n;
	bool combine = false;
	while (1) {
		while (1) {
			for (k = 4; k >= 0; k--) {
				if (number[k][0] == number[k][1] && number[k][1] == number[k][2] && number[k][2] == number[k][3] && number[k][3] == number[k][4] && number[k][0] != ' ') {
					combine = true;
					Combine = true;
					number[k][4] = number[k][4] + 4;
					score = score + (number[k][4] - '0');
					for (m = k - 1; m > 0; m--) {
						for (n = 3; n >= 0; n--) {
							number[m + 1][n] = number[m][n];
							number[0][n] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				if (number[0][k] == number[1][k] && number[1][k] == number[2][k] && number[2][k] == number[3][k] && number[3][k] == number[4][k] && number[4][k] != ' ') {
					combine = true;
					Combine = true;
					number[4][k] = number[4][k] + 4;
					score = score + (number[4][k] - '0');
					for (n = 3; n >= 0; n--) {
						number[n][k] = ' ';
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		int p;
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 1; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p + 2] == number[k][p + 3] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 3] = number[k][p + 3] + 3;
						score = score + (number[k][p + 3] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p + 2; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 1; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] == number[p + 3][k] && number[p + 3][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 3][k] = number[p + 3][k] + 3;
						score = score + (number[p + 3][k] - '0');
						for (n = p + 2; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 2; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 2] = number[k][p + 2] + 2;
						score = score + (number[k][p + 2] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p + 1; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 2; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 2][k] = number[p + 2][k] + 2;
						score = score + (number[p + 2][k] - '0');
						for (n = p + 1; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 3; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 1] = number[k][p + 1] + 1;
						score = score + (number[k][p + 1] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 3; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 1][k] = number[p + 1][k] + 1;
						score = score + (number[p + 1][k] - '0');
						for (n = p; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		if (Combine == false) break;
		Combine = false;
	}
	int h;
	int j;
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (number[j][i] == '9') {
				for (h = j; h > 0; h--) {
					number[h][i] = number[h - 1][i];
				}
				number[0][i] = ' ';
			}
		}
	}
	char temp = number[0][0];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (number[i][j] > temp) {
				temp = number[i][j];
			}
		}
	}
	if (temp == ' ') max = 1;
	else max = int(temp - '0');
}
int numbercom::level(int queue) {
	int i;
	for (i = 0; i < 5; i++) {
		if (number[4 - i][queue] != ' ') continue;
		else break;
	}
	return i;
}
void numbercom::changenum2(int queue) {
	srand(time(0));
	int i = 4;
	while (i > 0 && number[i][queue] != ' ') {
		i--;
	}
	number[i][queue] = x + '0';
	bool Combine = false;
	int k, m, n;
	bool combine = false;
	while (1) {
		while (1) {
			for (k = 4; k >= 0; k--) {
				if (number[k][0] == number[k][1] && number[k][1] == number[k][2] && number[k][2] == number[k][3] && number[k][3] == number[k][4] && number[k][0] != ' ') {
					combine = true;
					Combine = true;
					number[k][4] = number[k][4] + 4;
					score = score + (number[k][4] - '0');
					for (m = k - 1; m > 0; m--) {
						for (n = 3; n >= 0; n--) {
							number[m + 1][n] = number[m][n];
							number[0][n] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				if (number[0][k] == number[1][k] && number[1][k] == number[2][k] && number[2][k] == number[3][k] && number[3][k] == number[4][k] && number[4][k] != ' ') {
					combine = true;
					Combine = true;
					number[4][k] = number[4][k] + 4;
					score = score + (number[4][k] - '0');
					for (n = 3; n >= 0; n--) {
						number[n][k] = ' ';
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		int p;
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 1; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p + 2] == number[k][p + 3] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 3] = number[k][p + 3] + 3;
						score = score + (number[k][p + 3] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p + 2; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 1; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] == number[p + 3][k] && number[p + 3][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 3][k] = number[p + 3][k] + 3;
						score = score + (number[p + 3][k] - '0');
						for (n = p + 2; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 2; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 2] = number[k][p + 2] + 2;
						score = score + (number[k][p + 2] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p + 1; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 2; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 2][k] = number[p + 2][k] + 2;
						score = score + (number[p + 2][k] - '0');
						for (n = p + 1; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 3; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 1] = number[k][p + 1] + 1;
						score = score + (number[k][p + 1] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 3; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 1][k] = number[p + 1][k] + 1;
						score = score + (number[p + 1][k] - '0');
						for (n = p; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		if (Combine == false) break;
		Combine = false;
	}
	int h;
	int j;
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (number[j][i] == '9') {
				for (h = j; h > 0; h--) {
					number[h][i] = number[h - 1][i];
				}
				number[0][i] = ' ';
			}
		}
	}
	if (score - scorelevel * 25 >= 0) {
		srand(time(0));
		for (int i = 0; i < 5; i++) {
			j = 4;
			while (j >= 0 && number[j][i] != ' ') {
				j--;
			}
			number[j][i] = '0' + rand() % max + 1;
			scorelevel++;
		}
	}
	while (1) {
		while (1) {
			for (k = 4; k >= 0; k--) {
				if (number[k][0] == number[k][1] && number[k][1] == number[k][2] && number[k][2] == number[k][3] && number[k][3] == number[k][4] && number[k][0] != ' ') {
					combine = true;
					Combine = true;
					number[k][4] = number[k][4] + 4;
					score = score + (number[k][4] - '0');
					for (m = k - 1; m > 0; m--) {
						for (n = 3; n >= 0; n--) {
							number[m + 1][n] = number[m][n];
							number[0][n] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				if (number[0][k] == number[1][k] && number[1][k] == number[2][k] && number[2][k] == number[3][k] && number[3][k] == number[4][k] && number[4][k] != ' ') {
					combine = true;
					Combine = true;
					number[4][k] = number[4][k] + 4;
					score = score + (number[4][k] - '0');
					for (n = 3; n >= 0; n--) {
						number[n][k] = ' ';
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		int p;
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 1; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p + 2] == number[k][p + 3] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 3] = number[k][p + 3] + 3;
						score = score + (number[k][p + 3] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p + 2; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 1; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] == number[p + 3][k] && number[p + 3][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 3][k] = number[p + 3][k] + 3;
						score = score + (number[p + 3][k] - '0');
						for (n = p + 2; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 2; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 2] = number[k][p + 2] + 2;
						score = score + (number[k][p + 2] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p + 1; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 2; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 2][k] = number[p + 2][k] + 2;
						score = score + (number[p + 2][k] - '0');
						for (n = p + 1; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 3; p++) {
					if (number[k][p] == number[k][p + 1] && number[k][p] != ' ') {
						combine = true;
						Combine = true;
						number[k][p + 1] = number[k][p + 1] + 1;
						score = score + (number[k][p + 1] - '0');
						for (m = k - 1; m > 0; m--) {
							for (n = p; n >= p; n--) {
								number[m + 1][n] = number[m][n];
								number[0][n] = ' ';
							}
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		while (1) {
			for (k = 4; k >= 0; k--) {
				for (p = 0; p <= 3; p++) {
					if (number[p][k] == number[p + 1][k] && number[p + 1][k] != ' ') {
						combine = true;
						Combine = true;
						number[p + 1][k] = number[p + 1][k] + 1;
						score = score + (number[p + 1][k] - '0');
						for (n = p; n >= p; n--) {
							number[n][k] = ' ';
						}
					}
				}
			}
			if (combine == false) break;
			combine = false;
		}
		if (Combine == false) break;
		Combine = false;
	}
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (number[j][i] == '9') {  
				for (h = j; h > 0; h--) {
					number[h][i] = number[h - 1][i];
				}
				number[0][i] = ' ';
			}
		}
	}
	char temp = number[0][0];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (number[i][j] > temp) {
				temp = number[i][j];
			}
		}
	}
	if (temp == ' ') max = 1;
	else max = int(temp - '0');
}

char numbercom::getnum(int line, int queue) {
	return number[4- line][queue];
}

void numbercom::cleanall() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			number[i][j] = ' ';
		}
	}
	max = 1;
	x = 1;
	next = 1;
	score = 0;
	scorelevel = 1;
}

void D1::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
//start
void D1::InitStatus()
{
	//初始化状态栏，将状态栏设置为三列，前两列固定显示内容，第三列实时显示时间
	static UINT BASED_CODE indicators[] = {
		ID_STATUSBAR_0,
		ID_STATUSBAR_1
	};
	m_bar.Create(this);
	m_bar.SetIndicators(indicators, 3);
	GetClientRect(&rect);            //获取当前对话框的宽度
	CString str1;
	t1 = CTime::GetCurrentTime();
	str1 = t1.Format("%Y年%m月%d日 %H:%M:%S");
	//m_time.SetWindowTextA(str1);    

	//设置状态栏前两列显示内容。使用函数为SetPaneInfo（第几列，手工添加的StringTable（相当于字符串常量，等同于宏定义一个ID 代表某一字符串），显示风格，显示宽度）
	m_bar.SetPaneInfo(0, ID_STATUSBAR_0, SBPS_POPOUT, rect.Width() / 3);
	m_bar.SetPaneInfo(1, ID_STATUSBAR_1, SBPS_POPOUT, rect.Width() / 3);
	//第三列显示时间
	m_bar.SetPaneText(2, str1, 1);
	//设置状态栏填充颜色
	m_bar.GetStatusBarCtrl().SetBkColor(RGB(255, 255, 255));
	//启动定时器，SetTimer（ID，间隔时间，窗口句柄（NULL时为默认））
	SetTimer(1, 1000, NULL);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, AFX_IDW_CONTROLBAR_FIRST);

}

void D1::ShowtimeNow()
{
	CString str1;
	//获取系统时间，并进行显示
	t1 = CTime::GetCurrentTime();
	str1 = t1.Format("%Y年%m月%d日 %H:%M:%S");
	//m_time.SetWindowTextA(str1);
	//在状态栏的第三个列上显示时间
	m_bar.SetPaneText(2, str1, 1);
}

void D1::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		ShowtimeNow();       //反复调用这个函数，进行时间显示刷新
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
//end
