// BeginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "BeginDlg.h"
#include "afxdialogex.h"
#include "CreatDlg.h"
#include "JoinDlg.h"
#include "SocketClient.h"


// CBeginDlg 对话框

IMPLEMENT_DYNAMIC(CBeginDlg, CDialog)

CBeginDlg::CBeginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBeginDlg::IDD, pParent)
{

}

CBeginDlg::~CBeginDlg()
{
}

void CBeginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBeginDlg, CDialog)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CBeginDlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_CREAT_BUTTON, &CBeginDlg::OnBnClickedCreatButton)
	ON_BN_CLICKED(IDC_JOIN_ROOM, &CBeginDlg::OnBnClickedJoinRoom)
END_MESSAGE_MAP()


// CBeginDlg 消息处理程序



void CBeginDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}


void CBeginDlg::OnBnClickedCreatButton()
{	
	SC_beginThreads();
	CCreatDlg create;
	create.DoModal();
}


void CBeginDlg::OnBnClickedJoinRoom()
{
	SC_beginThreads();
	CJoinDlg join;
	join.DoModal();
	
	// TODO:  在此添加控件通知处理程序代码
}


BOOL CBeginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SkinH_Attach();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
