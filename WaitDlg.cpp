// WaitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "WaitDlg.h"
#include "afxdialogex.h"
#include "DrawDlg.h"


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
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &WaitDlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_BEGIN_BUTTON, &WaitDlg::OnBnClickedBeginButton)
END_MESSAGE_MAP()


// WaitDlg ��Ϣ�������


void WaitDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void WaitDlg::OnBnClickedBeginButton()
{
	CDrawDlg draw;
	draw.DoModal();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
