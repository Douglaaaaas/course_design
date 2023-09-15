// lose_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "lose_dlg.h"
#include "D1.h"
extern numbercom num1;

// lose_dlg 对话框

IMPLEMENT_DYNAMIC(lose_dlg, CDialogEx)

lose_dlg::lose_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

lose_dlg::~lose_dlg()
{
}

void lose_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, lose_score);
	DDX_Control(pDX, IDOK, Button_return);
}


BEGIN_MESSAGE_MAP(lose_dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &lose_dlg::OnBnClickedOk)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// lose_dlg 消息处理程序


void lose_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL lose_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int score = num1.get_score();
	CString score1;
	score1.Format(_T("%d"), score);
	lose_score.SetWindowTextW(score1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL lose_dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect rect;
	GetClientRect(&rect);
	//加载背景位图
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP3); //图片ID

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


HBRUSH lose_dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if ((pWnd->GetDlgCtrlID() == IDC_STATIC))
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkMode(TRANSPARENT);
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
