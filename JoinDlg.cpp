// JoinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "JoinDlg.h"
#include "afxdialogex.h"


// CJoinDlg �Ի���

IMPLEMENT_DYNAMIC(CJoinDlg, CDialog)

CJoinDlg::CJoinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJoinDlg::IDD, pParent)
{

}

CJoinDlg::~CJoinDlg()
{
}

void CJoinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROOM_TEXT, m_RoomText);
	DDX_Control(pDX, IDC_ROOM_EDIT, m_RoomEdit);
	DDX_Control(pDX, IDC_ID_TEXT, m_IdText);
	DDX_Control(pDX, IDC_ID_EDIT, m_IdEdit);
}


BEGIN_MESSAGE_MAP(CJoinDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN_BUTTON, &CJoinDlg::OnBnClickedReturnButton)
END_MESSAGE_MAP()


// CJoinDlg ��Ϣ�������


void CJoinDlg::OnBnClickedReturnButton()
{
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CJoinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//m_Font.CreatePointFont(110, (LPCTSTR)"Arial", NULL);
	//m_IdText.SetFont(&m_Font, true);
	//m_IdText.SetWindowText((LPCTSTR)"Enter Your Name");


	//m_RoomText.SetFont(&m_Font, true);
	//m_RoomText.SetWindowText((LPCTSTR)"Your  RoomID  is");
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
