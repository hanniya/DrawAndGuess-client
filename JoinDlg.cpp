// JoinDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "JoinDlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"
#include "WaitDlg.h"
#include "json\json.h"
// CJoinDlg 对话框

IMPLEMENT_DYNAMIC(CJoinDlg, CDialog)

CJoinDlg::CJoinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJoinDlg::IDD, pParent)
	, m_join_name(_T(""))
	, m_room_number(_T(""))
{
	SC_onReceive = OnRecieveMessage;
}

CJoinDlg::~CJoinDlg()
{
}

bool CJoinDlg::success = FALSE;
string players[6] = {};
int NumberOfPlayers = 0;

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


// CJoinDlg 消息处理程序


void CJoinDlg::OnBnClickedReturnButton()
{
	SC_endThreads();
	SC_onReceive = NULL;
	OnOK();
	// TODO:  在此添加控件通知处理程序代码
}


BOOL CJoinDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	/*m_Font.CreatePointFont(110, _T("Arial"), NULL);
	m_IdText.SetFont(&m_Font, true);
	m_IdText.SetWindowText("Enter Your Name");


	m_RoomText.SetFont(&m_Font, true);
	m_RoomText.SetWindowText("Your  RoomID  is");*/
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CJoinDlg::OnRecieveMessage(char*ch)
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(ch, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		success = root["success"].asBool();  // 访问节点
		for (int i = 0; i < 6; i++)
		{
			if (root["success"][i].asString() != "")
			{
				players[i] = root["success"][i].asString();
				NumberOfPlayers += 1;
			}
			else
			{
				break;
			}
		}
	}
}


void CJoinDlg::OnBnClickedNextButton()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str = "{\"method\": \"join_room\", \"room\": ";
	str = str + m_room_number + ", \"nick\": \"" + m_join_name + "\"}";
	SC_sendMessage((LPSTR)(LPCTSTR)str);
	AfxMessageBox("即将进入房间");
	if (success)
	{
		WaitDlg wait;
		wait.m_room_number = atoi(m_room_number);
		int a = 0;
		if (NumberOfPlayers>a)   wait.m_play1 = players[a].c_str(), a += 1;
		if (NumberOfPlayers>a)   wait.m_play2 = players[a].c_str(), a += 1;
		if (NumberOfPlayers>a)   wait.m_play3 = players[a].c_str(), a += 1;
		if (NumberOfPlayers>a)   wait.m_play4 = players[a].c_str(), a += 1;
		if (NumberOfPlayers>a)   wait.m_play5 = players[a].c_str(), a += 1;
		if (NumberOfPlayers>a)   wait.m_play6 = players[a].c_str();
		wait.DoModal();
	}
	else
	{
		MessageBoxW(NULL, (LPCWSTR)L"服务器未响应", (LPCWSTR)L"错误", MB_OK);
	}
}
