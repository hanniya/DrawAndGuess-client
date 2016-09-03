
// DrawDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "DrawDlg.h"
#include "afxdialogex.h"
#include "Utils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDrawDlg 对话框



CDrawDlg::CDrawDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDrawDlg::IDD, pParent)
	, m_MessageEdit(_T(""))
	, m_SendEdit(_T(""))
	, m_PlayerMes(_T(""))
	, m_TimeWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MESSAGE_EDIT, m_MessageEdit);
	DDX_Text(pDX, IDC_SEND_EDIT, m_SendEdit);
	DDX_Control(pDX, IDC_SEND_BUTTON, m_SendButton);
	DDX_Text(pDX, IDC_PLAYERMES_EDIT, m_PlayerMes);
	DDX_Text(pDX, IDC_TIMEWORD_EDIT, m_TimeWord);
	DDX_Control(pDX, IDC_RETURN_BUTTON, m_ReturnButton);
	DDX_Control(pDX, IDC_DELETE_BUTTON, m_DeleteButton);
}

BEGIN_MESSAGE_MAP(CDrawDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CDrawDlg::OnBnClickedSendButton)

	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CDrawDlg::OnBnClickedExitButton)
END_MESSAGE_MAP()


// CDrawDlg 消息处理程序

BOOL CDrawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	SkinH_Attach();

	m_brush.CreateSolidBrush(RGB(255, 255, 255));//设置白色背景
	isleftdown = false;//初始化鼠标左键松开

	//初始化画板区域使其与白色区域重合
	pdc = GetDC();
	//定义画笔:实心 2像素 黑色
	CPen st(PS_SOLID, 2, RGB(0, 0, 0));
	//将画笔应用至画板
	pdc->SelectObject(&st);



	//初始化图标
	HICON hIcon1 = (HICON)::LoadImage(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_Return), IMAGE_ICON, 20, 20, LR_DEFAULTCOLOR);
	m_ReturnButton.SetIcon(hIcon1);

	HICON hIcon2 = (HICON)::LoadImage(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_Delete), IMAGE_ICON, 35, 35, LR_DEFAULTCOLOR);
	m_DeleteButton.SetIcon(hIcon2);



	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDrawDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawDlg::OnPaint()
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
HCURSOR CDrawDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CDrawDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_color);
		return   (HBRUSH)m_brush.GetSafeHandle();
	}

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDrawDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd *p;
	p = GetDlgItem(IDC_DRAWPANEL);   
	CRect dRect;
	p->GetWindowRect(&dRect);
	ScreenToClient(&dRect);

	
	if (isleftdown && isPointInRect(point, dRect))
	{
		pdc->MoveTo(last);
		pdc->LineTo(point);
	}

	//更新last
	last = point;
	// TODO:  在此添加消息处理程序代码和/或调用默认值


	CDialogEx::OnMouseMove(nFlags, point);
}


void CDrawDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd *p;
	p = GetDlgItem(IDC_DRAWPANEL);
	CRect dRect;
	p->GetWindowRect(&dRect);
	ScreenToClient(&dRect);

	isleftdown = isPointInRect(point, dRect);
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDrawDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isleftdown = false;
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CDrawDlg::OnBnClickedSendButton()
{
	// TODO:  在此添加控件通知处理程序代码
}





void CDrawDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}
