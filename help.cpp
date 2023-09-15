// help.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "help.h"


// help 对话框

IMPLEMENT_DYNAMIC(help, CDialogEx)

help::help(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

help::~help()
{
}

void help::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(help, CDialogEx)
END_MESSAGE_MAP()


// help 消息处理程序
