// BeginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "BeginDlg.h"
#include "afxdialogex.h"
#include "CreatDlg.h"
#include "JoinDlg.h"


// CBeginDlg �Ի���

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


// CBeginDlg ��Ϣ�������


void CBeginDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
