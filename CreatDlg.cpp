// CreatDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "Draw.h"
#include "CreatDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"
#include "WaitDlg.h"
#include "json\json.h"
#include "BeginDlg.h"


// CCreatDlg 对话框

IMPLEMENT_DYNAMIC(CCreatDlg, CDialog)

CCreatDlg::CCreatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreatDlg::IDD, pParent)
	, m_Name(_T(""))
{
}

CCreatDlg::~CCreatDlg()
{
}


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


// CCreatDlg 消息处理程序


BOOL CCreatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//m_Font.CreatePointFont(110, (LPCTSTR)"Arial", NULL);
	//m_IdText.SetFont(&m_Font, true);
	//m_IdText.SetWindowText((LPCTSTR)"Enter Your Name");
	SkinH_Attach();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CCreatDlg::OnBnClickedReturn1Button()
{
	SC_endThreads();
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}

void CCreatDlg::handleMessage(char* ch)
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(ch, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		bool success = root["success"].asBool();  // 访问节点
		if (success)
		{
			int room = root["room"].asInt();
			WaitDlg wait;
			wait.m_room_number = room;
			wait.m_play1 = m_Name;
			wait.DoModal();
		}
		else
		{
			CString reason = root["reason"].asCString();
			AfxMessageBox(reason);
		}
	}
}


void CCreatDlg::OnBnClickedNextButton()
{
	PULL;
	CString userName = "{\"method\": \"create_room\", \"nick\": \"";
	userName = userName + m_Name + "\"}";
	char * ch = (LPSTR)(LPCTSTR)userName;
	SC_sendMessage(ch);
	// TODO:  在此添加控件通知处理程序代码
}
