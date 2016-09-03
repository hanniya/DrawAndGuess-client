// CreatDlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "Draw.h"
#include "CreatDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"
#include "WaitDlg.h"
#include "json\json.h"
#include "BeginDlg.h"


// CCreatDlg �Ի���

IMPLEMENT_DYNAMIC(CCreatDlg, CDialog)

CCreatDlg::CCreatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreatDlg::IDD, pParent)
	, m_Name(_T(""))
{
	SC_onReceive = OnRecieveMessage;
}

CCreatDlg::~CCreatDlg()
{
}

int CCreatDlg::room = 0;
bool CCreatDlg::success = FALSE;

void CCreatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ID_TEXT, m_IdText);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
}


BEGIN_MESSAGE_MAP(CCreatDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN1_BUTTON, &CCreatDlg::OnBnClickedReturn1Button)
	ON_BN_CLICKED(IDC_CREAT_NEXT_BUTTON, &CCreatDlg::OnBnClickedNextButton)
END_MESSAGE_MAP()


// CCreatDlg ��Ϣ�������


BOOL CCreatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//m_Font.CreatePointFont(110, (LPCTSTR)"Arial", NULL);
	//m_IdText.SetFont(&m_Font, true);
	//m_IdText.SetWindowText((LPCTSTR)"Enter Your Name");

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CCreatDlg::OnBnClickedReturn1Button()
{
	SC_endThreads();
	SC_onReceive = NULL;
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

 void CCreatDlg::OnRecieveMessage(char* ch)
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(ch, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{
		CCreatDlg::success = root["success"].asBool();  // ���ʽڵ�
		CCreatDlg::room = root["room"].asInt();
	}
}


void CCreatDlg::OnBnClickedNextButton()
{	
	UpdateData(TRUE);
	CString userName = "{\"method\": \"create_room\", \"nick\": \"";
	userName = userName + m_Name + "\"}";
	char * ch = (LPSTR)(LPCTSTR)userName;
	SC_sendMessage(ch);
	AfxMessageBox("������������");
	if (success){
		WaitDlg wait;
		wait.m_room_number = room;
		wait.m_play1 = m_Name;
		wait.DoModal();
	}
	else AfxMessageBox("���ӷ�����ʧ��");

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
