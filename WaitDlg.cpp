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
	, m_room_number(0)
{

}

WaitDlg::~WaitDlg()
{
}

void WaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_RoomNumber_Edit, m_room_number);
	DDX_Text(pDX, IDC_ROOM_EDIT, m_room_number);
}


BEGIN_MESSAGE_MAP(WaitDlg, CDialog)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &WaitDlg::OnBnClickedExitButton)
	//ON_BN_CLICKED(IDC_BEGIN_BUTTON, &WaitDlg::OnBnClickedBeginButton)
	ON_BN_CLICKED(IDC_BEGIN_BUTTON, &WaitDlg::OnClickedBeginButton)
END_MESSAGE_MAP()


// WaitDlg 消息处理程序


void WaitDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}

   

void WaitDlg::OnClickedBeginButton()
{
	CDrawDlg draw;
	draw.DoModal();
	// TODO:  在此添加控件通知处理程序代码
}


BOOL WaitDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
