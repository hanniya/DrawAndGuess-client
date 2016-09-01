#pragma once
#include "afxwin.h"


// CCreatDlg 对话框

class CCreatDlg : public CDialog
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
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedReturn1Button();
//	CStatic m_RoomText;
	afx_msg void OnBnClickedNextButton();
	afx_msg void OnStnClickedIdText();
	CString m_Name;
	void OnRecieveMessage(char *);
};
