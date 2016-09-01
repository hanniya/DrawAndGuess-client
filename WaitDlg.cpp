// WaitDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "WaitDlg.h"
#include "afxdialogex.h"
#include "DrawDlg.h"


// WaitDlg 对话框

IMPLEMENT_DYNAMIC(WaitDlg, CDialog)

WaitDlg::WaitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(WaitDlg::IDD, pParent)
{

}

WaitDlg::~WaitDlg()
{
}

void WaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WaitDlg, CDialog)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &WaitDlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_BEGIN_BUTTON, &WaitDlg::OnBnClickedBeginButton)
END_MESSAGE_MAP()


// WaitDlg 消息处理程序


void WaitDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}


void WaitDlg::OnBnClickedBeginButton()
{
	CDrawDlg draw;
	draw.DoModal();
	// TODO:  在此添加控件通知处理程序代码
}
