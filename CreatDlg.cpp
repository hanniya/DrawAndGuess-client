// CreatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "CreatDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"

// CCreatDlg 对话框

IMPLEMENT_DYNAMIC(CCreatDlg, CDialog)

CCreatDlg::CCreatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreatDlg::IDD, pParent)
{

}

CCreatDlg::~CCreatDlg()
{
}

void CCreatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ID_TEXT, m_IdText);
	DDX_Control(pDX, IDC_ROOM_TEXT, m_RoomText);
}


BEGIN_MESSAGE_MAP(CCreatDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN1_BUTTON, &CCreatDlg::OnBnClickedReturn1Button)
	ON_BN_CLICKED(IDC_NEXT_BUTTON, &CCreatDlg::OnBnClickedNextButton)
END_MESSAGE_MAP()


// CCreatDlg 消息处理程序


BOOL CCreatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Font.CreatePointFont(110, (LPCTSTR)"Arial", NULL);
	m_IdText.SetFont(&m_Font, true);
	m_IdText.SetWindowText((LPCTSTR)"Enter Your Name");


	m_RoomText.SetFont(&m_Font, true);
	m_RoomText.SetWindowText((LPCTSTR)"Your  RoomID  is");
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CCreatDlg::OnBnClickedReturn1Button()
{

	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}


void CCreatDlg::OnBnClickedNextButton()
{

	// TODO:  在此添加控件通知处理程序代码
}
