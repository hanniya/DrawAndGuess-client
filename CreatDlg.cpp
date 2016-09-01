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
	, m_Name(_T(""))
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
	DDX_Text(pDX, IDC_EDIT1, m_Name);
}


BEGIN_MESSAGE_MAP(CCreatDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN1_BUTTON, &CCreatDlg::OnBnClickedReturn1Button)
	ON_BN_CLICKED(IDC_NEXT_BUTTON, &CCreatDlg::OnBnClickedNextButton)
	ON_STN_CLICKED(IDC_ID_TEXT, &CCreatDlg::OnStnClickedIdText)
END_MESSAGE_MAP()


// CCreatDlg 消息处理程序


BOOL CCreatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_Font.CreatePointFont(110, _T("Arial"), NULL);
	m_IdText.SetFont(&m_Font, true);
	m_IdText.SetWindowText(_T("Enter Your Name"));


	m_RoomText.SetFont(&m_Font, true);
	m_RoomText.SetWindowText(_T("Your  RoomID  is"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CCreatDlg::OnBnClickedReturn1Button()
{
	SC_endThreads();
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}


void CCreatDlg::OnBnClickedNextButton()
{
	UpdateData(TRUE);
	CString userName = "{\"method\": \"create_room\", \"nick\": \"";
	userName = userName + m_Name +"\"}";
	char * ch = (LPSTR)(LPCTSTR)userName;
	SC_sendMessage(ch);
	// TODO:  在此添加控件通知处理程序代码
}


void CCreatDlg::OnStnClickedIdText()
{
	// TODO:  在此添加控件通知处理程序代码
}
