// win_dlg2.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "win_dlg2.h"


// win_dlg2 对话框

IMPLEMENT_DYNAMIC(win_dlg2, CDialogEx)

win_dlg2::win_dlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

win_dlg2::~win_dlg2()
{
}

void win_dlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(win_dlg2, CDialogEx)
	ON_BN_CLICKED(IDOK, &win_dlg2::OnBnClickedOk)
END_MESSAGE_MAP()


// win_dlg2 消息处理程序


void win_dlg2::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
