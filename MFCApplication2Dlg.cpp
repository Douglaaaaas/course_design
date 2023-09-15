// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "D1.h"
#include "help.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

int CMFCApplication2Dlg::times = 0;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	this->cheated1 = false;
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, BUTTON_help);
	DDX_Control(pDX, IDC_BUTTON7, BUTTON_A);
	DDX_Control(pDX, IDC_BUTTON5, BUTTON_B);
	DDX_Control(pDX, IDC_BUTTON6, BUTTON_C);
	DDX_Control(pDX, IDC_BUTTON4, BUTTON_D);
	DDX_Control(pDX, IDC_BUTTON8, BUTTON_E);
	DDX_Control(pDX, IDOK, BUTTON_OK);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	m_static.SubclassDlgItem(IDC_STATIC, this);
	m_font.CreatePointFont(300, _T("隶书"));
	m_static.SetFont(&m_font);
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	BUTTON_help.m_bTransparent = FALSE;
	BUTTON_help.m_bDontUseWinXPTheme = TRUE;
	BUTTON_help.SetFaceColor(RGB(0, 255, 0), true);
	BUTTON_A.m_bTransparent = FALSE;
	BUTTON_A.m_bDontUseWinXPTheme = TRUE;
	BUTTON_A.SetFaceColor(RGB(188, 143, 143), true);
	BUTTON_B.m_bTransparent = FALSE;
	BUTTON_B.m_bDontUseWinXPTheme = TRUE;
	BUTTON_B.SetFaceColor(RGB(205, 92, 92), true);
	BUTTON_C.m_bTransparent = FALSE;
	BUTTON_C.m_bDontUseWinXPTheme = TRUE;
	BUTTON_C.SetFaceColor(RGB(139, 69, 19), true);
	BUTTON_D.m_bTransparent = FALSE;
	BUTTON_D.m_bDontUseWinXPTheme = TRUE;
	BUTTON_D.SetFaceColor(RGB(210, 105, 30), true);
	BUTTON_E.m_bTransparent = FALSE;
	BUTTON_E.m_bDontUseWinXPTheme = TRUE;
	BUTTON_E.SetFaceColor(RGB(255, 0, 0), true);
	BUTTON_OK.m_bTransparent = FALSE;
	BUTTON_OK.m_bDontUseWinXPTheme = TRUE;
	BUTTON_OK.SetFaceColor(RGB(238 ,130 ,238), true);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication2Dlg::OnBnClickedButton1()
{
	help help1;
	help1.DoModal();
	// TODO: 在此添加控件通知处理程序代码
	// 下边为作弊码实现代码
	times++;
	if (this->times >= 5)
	{
		this->times = 0;
		this->cheated1 = true;
	}
	return;
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	D1 d1;
	d1.difficulty = 2;
	d1.endlessness = FALSE;
	d1.pourdown = FALSE;
	d1.change = FALSE;
	if (this->cheated1)
	{
		d1.cheated = true;
	}
	else
	{
		this->times = 0;
		this->cheated1 = false;
		d1.cheated = false;
	}
	d1.DoModal();

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	D1 d2;
	d2.difficulty = 0;
	d2.endlessness = FALSE;
	d2.pourdown = FALSE;
	d2.change = FALSE;
	if (this->cheated1)
	{
		d2.cheated = true;
		this->cheated1 = false;
	}
	else
	{
		this->times = 0;
		this->cheated1 = false;
		d2.cheated = false;
	}
	d2.DoModal();
}


void CMFCApplication2Dlg::OnBnClickedButton6()
{
	D1 d3;
	d3.difficulty = 1;
	d3.pourdown = FALSE;
	d3.endlessness = FALSE;
	d3.change = FALSE;
	if (this->cheated1)
	{
		d3.cheated = true;
	}
	else
	{
		this->times = 0;
		this->cheated1 = false;
		d3.cheated = false;
	}
	d3.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CMFCApplication2Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//背景图片
	//获得客户区尺寸
	CRect rect;
	GetClientRect(&rect);
	//加载背景位图
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP1); //图片ID

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


HBRUSH CMFCApplication2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CMFCApplication2Dlg::OnBnClickedButton7()
{
	D1 d4;
	d4.difficulty = -1;
	d4.endlessness = TRUE;;
	d4.pourdown = FALSE;
	d4.change = FALSE;
	d4.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedButton8()
{
	D1 d5;
	d5.difficulty = -1;
	d5.endlessness = TRUE;
	d5.pourdown = TRUE;
	d5.DoModal();
	d5.change = FALSE;
	// TODO: 在此添加控件通知处理程序代码
}

	// TODO: 在此添加控件通知处理程序代码
