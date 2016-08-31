// CreatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "CreatDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"

// CCreatDlg �Ի���

IMPLEMENT_DYNAMIC(CCreatDlg, CDialog)

CCreatDlg::CCreatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreatDlg::IDD, pParent)
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
}


BEGIN_MESSAGE_MAP(CCreatDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN1_BUTTON, &CCreatDlg::OnBnClickedReturn1Button)
	ON_BN_CLICKED(IDC_NEXT_BUTTON, &CCreatDlg::OnBnClickedNextButton)
END_MESSAGE_MAP()


// CCreatDlg ��Ϣ�������


BOOL CCreatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Font.CreatePointFont(110, (LPCTSTR)"Arial", NULL);
	m_IdText.SetFont(&m_Font, true);
	m_IdText.SetWindowText((LPCTSTR)"Enter Your Name");


	m_RoomText.SetFont(&m_Font, true);
	m_RoomText.SetWindowText((LPCTSTR)"Your  RoomID  is");
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CCreatDlg::OnBnClickedReturn1Button()
{

	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CCreatDlg::OnBnClickedNextButton()
{

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
