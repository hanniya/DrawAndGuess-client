// CreatDlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "Draw.h"
#include "CreatDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"
#include "WaitDlg.h"
#include "json\json.h"


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
//	DDX_Control(pDX, IDC_ROOM_TEXT, m_RoomText);
}


BEGIN_MESSAGE_MAP(CCreatDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN1_BUTTON, &CCreatDlg::OnBnClickedReturn1Button)
	ON_BN_CLICKED(IDC_NEXT_BUTTON, &CCreatDlg::OnBnClickedNextButton)
END_MESSAGE_MAP()


// CCreatDlg ��Ϣ�������


BOOL CCreatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SC_onReceive = OnRecieveMessage;

	//m_Font.CreatePointFont(110, (LPCTSTR)"Arial", NULL);
	//m_IdText.SetFont(&m_Font, true);
	//m_IdText.SetWindowText((LPCTSTR)"Enter Your Name");
	SkinH_Attach();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CCreatDlg::OnBnClickedReturn1Button()
{
	SC_endThreads();
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

 void CCreatDlg::OnRecieveMessage(char* ch)
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(ch, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{
		bool success = root["success"].asBool();  // ���ʽڵ�
		if (success)
		{
			int room = root["room"].asInt();
			WaitDlg wait;
			wait.m_room_number = room;
			wait.DoModal();
		}
		else
		{
			MessageBoxW(NULL, (LPCWSTR)"������δ��Ӧ", (LPCWSTR)"����", MB_OK);
		}
	}
}


void CCreatDlg::OnBnClickedNextButton()
{
	UpdateData(TRUE);
	CString userName = "{\"method\": \"create_room\", \"nick\": \"";
	userName = userName + m_Name + "\"}";
	char * ch = (LPSTR)(LPCTSTR)userName;
	SC_sendMessage(ch);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
