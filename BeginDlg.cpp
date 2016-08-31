// BeginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "BeginDlg.h"
#include "afxdialogex.h"
#include "CreatDlg.h"
#include "JoinDlg.h"


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
	CCreatDlg creat;
	creat.DoModal();
}


void CBeginDlg::OnBnClickedJoinRoom()
{
	CJoinDlg join;
	join.DoModal();
	// TODO:  在此添加控件通知处理程序代码
}
