// WaitDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "WaitDlg.h"
#include "afxdialogex.h"


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
	DDX_Text(pDX, IDC_RoomNumber_Edit, m_room_number);
}


BEGIN_MESSAGE_MAP(WaitDlg, CDialog)
END_MESSAGE_MAP()


// WaitDlg 消息处理程序
