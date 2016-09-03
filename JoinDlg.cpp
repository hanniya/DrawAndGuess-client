// JoinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "JoinDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"
#include "WaitDlg.h"
#include "json\json.h"
// CJoinDlg �Ի���

IMPLEMENT_DYNAMIC(CJoinDlg, CDialog)

CJoinDlg::CJoinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJoinDlg::IDD, pParent)
	, m_join_name(_T(""))
	, m_room_number(_T(""))
{
}

CJoinDlg::~CJoinDlg()
{
}


void CJoinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROOM_TEXT, m_RoomText);
	//  DDX_Control(pDX, IDC_ROOM_EDIT, m_RoomEdit);
	DDX_Control(pDX, IDC_ID_TEXT, m_IdText);
	//  DDX_Control(pDX, IDC_ID_EDIT, m_IdEdit);
	DDX_Text(pDX, IDC_ID_EDIT, m_join_name);
	DDX_Text(pDX, IDC_ROOM_EDIT, m_room_number);
}


BEGIN_MESSAGE_MAP(CJoinDlg, CDialog)
	ON_BN_CLICKED(IDC_RETURN_BUTTON, &CJoinDlg::OnBnClickedReturnButton)
	ON_BN_CLICKED(IDC_JOIN_NEXT_BUTTON, &CJoinDlg::OnBnClickedNextButton)
END_MESSAGE_MAP()


// CJoinDlg ��Ϣ�������


void CJoinDlg::OnBnClickedReturnButton()
{
	SC_endThreads();
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CJoinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	/*m_Font.CreatePointFont(110, _T("Arial"), NULL);
	m_IdText.SetFont(&m_Font, true);
	m_IdText.SetWindowText("Enter Your Name");


	m_RoomText.SetFont(&m_Font, true);
	m_RoomText.SetWindowText("Your  RoomID  is");*/
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	SkinH_Attach();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CJoinDlg::handleMessage(char*ch)
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(ch, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{
		CString event = root["event"].asCString();
		if (event == "user_join")  return;
		bool success = root["success"].asBool();  // ���ʽڵ�
		AfxMessageBox(ch);
		if (success)
		{
			WaitDlg wait;
			wait.DoModal();
		}
		else
		{
			CString reason = root["reason"].asCString();
			AfxMessageBox(ch);
		}
	}
}


void CJoinDlg::OnBnClickedNextButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	WaitDlg wait;
	wait.DoModal();
	PULL;
	CString str = "{\"method\": \"join_room\", \"room\": ";
	str = str + m_room_number + ", \"nick\": \"" + m_join_name + "\"}";
	SC_sendMessage((LPSTR)(LPCTSTR)str);	
}
