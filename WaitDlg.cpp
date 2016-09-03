// WaitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "WaitDlg.h"
#include "afxdialogex.h"
#include "DrawDlg.h"
#include "json\json.h"
#include <string>
#include "SocketClient.h"

using namespace std;
// WaitDlg �Ի���

IMPLEMENT_DYNAMIC(WaitDlg, CDialog)

WaitDlg::WaitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(WaitDlg::IDD, pParent)
	, m_room_number(0)
	, m_play1(_T(""))
	, m_play2(_T(""))
	, m_play3(_T(""))
	, m_play4(_T(""))
	, m_play5(_T(""))
	, m_play6(_T(""))
{
}

WaitDlg::~WaitDlg()
{
}

void WaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ROOM_EDIT, m_room_number);
	DDX_Text(pDX, IDC_PLAY1_EDIT, m_play1);
	DDX_Text(pDX, IDC_PLAY2_EDIT, m_play2);
	DDX_Text(pDX, IDC_PLAY3_EDIT, m_play3);
	DDX_Text(pDX, IDC_PLAY4_EDIT, m_play4);
	DDX_Text(pDX, IDC_PLAY5_EDIT, m_play5);
	DDX_Text(pDX, IDC_PLAY6_EDIT, m_play6);
	DDX_Control(pDX, IDC_BEGIN_BUTTON, m_btn);
}


BEGIN_MESSAGE_MAP(WaitDlg, CDialog)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &WaitDlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_BEGIN_BUTTON, &WaitDlg::OnClickedBeginButton)
END_MESSAGE_MAP()


// WaitDlg ��Ϣ�������



void WaitDlg::OnBnClickedExitButton()
{
	OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

   

void WaitDlg::OnClickedBeginButton()
{
	char begin[] = "{\"method\": \"start_game\"}";
	SC_sendMessage(begin);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void WaitDlg::handleMessage(char *ch)
{
	Json::Reader reader;
	Json::Value root;
	AfxMessageBox(ch);
	if (reader.parse(ch, root))  // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{
		string event = root["event"].asString();
		bool success = root["success"].asBool();
		if (event == "generate_word")
		{
			CString word = root["word"].asString().c_str();
	CDrawDlg draw;
			draw.m_word = word;
	draw.DoModal();
		}
		if (!success)
		{
			CString reason = root["reason"].asCString();
			AfxMessageBox(reason);
		}
	}
}



BOOL WaitDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SkinH_Attach();
	UpdateData(true);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
