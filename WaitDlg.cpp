// WaitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "WaitDlg.h"
#include "afxdialogex.h"


// WaitDlg �Ի���

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
END_MESSAGE_MAP()


// WaitDlg ��Ϣ�������
