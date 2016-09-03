// BeginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "BeginDlg.h"
#include "afxdialogex.h"
#include "CreatDlg.h"
#include "JoinDlg.h"
#include "SocketClient.h"


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
	SC_beginThreads();
	CCreatDlg creat;
	creat.DoModal();
}


void CBeginDlg::OnBnClickedJoinRoom()
{
	SC_beginThreads();
	CJoinDlg join;
	join.DoModal();
	
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CBeginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();



	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SkinH_Attach();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
