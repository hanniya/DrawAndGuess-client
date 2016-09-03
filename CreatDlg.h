#pragma once
#include "afxwin.h"
#include "SocketContext.h"


// CCreatDlg 对话框

class CCreatDlg : public CDialog, private SocketContext
{
	DECLARE_DYNAMIC(CCreatDlg)

public:
	CCreatDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCreatDlg();

// 对话框数据
	enum { IDD = IDD_CREAT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_IdText;



private:
	CFont m_Font;
public:
	void handleMessage (char*);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedReturn1Button();
//	CStatic m_RoomText;
	afx_msg void OnBnClickedNextButton();
	afx_msg void OnStnClickedIdText();
	CString m_Name;
};
