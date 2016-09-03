
// DrawDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "DrawDlg.h"
#include "afxdialogex.h"
#include "Utils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDrawDlg �Ի���



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


// CDrawDlg ��Ϣ�������

BOOL CDrawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	SkinH_Attach();

	m_brush.CreateSolidBrush(RGB(255, 255, 255));//���ð�ɫ����
	isleftdown = false;//��ʼ���������ɿ�

	//��ʼ����������ʹ�����ɫ�����غ�
	pdc = GetDC();
	//���廭��:ʵ�� 2���� ��ɫ
	CPen st(PS_SOLID, 2, RGB(0, 0, 0));
	//������Ӧ��������
	pdc->SelectObject(&st);



	//��ʼ��ͼ��
	HICON hIcon1 = (HICON)::LoadImage(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_Return), IMAGE_ICON, 20, 20, LR_DEFAULTCOLOR);
	m_ReturnButton.SetIcon(hIcon1);

	HICON hIcon2 = (HICON)::LoadImage(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_Delete), IMAGE_ICON, 35, 35, LR_DEFAULTCOLOR);
	m_DeleteButton.SetIcon(hIcon2);



	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDrawDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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

	//����last
	last = point;
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ


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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDrawDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isleftdown = false;
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CDrawDlg::OnBnClickedSendButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CDrawDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
