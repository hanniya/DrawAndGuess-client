#pragma once
#include "afxwin.h"


// CJoinDlg 对话框

class CJoinDlg : public CDialog
{
	DECLARE_DYNAMIC(CJoinDlg)

public:
	CJoinDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJoinDlg();

// 对话框数据
	enum { IDD = IDD_CJOIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedReturnButton();
	CStatic m_RoomText;
	CEdit m_RoomEdit;
	CStatic m_IdText;
	CEdit m_IdEdit;
	virtual BOOL OnInitDialog();

private:
	CFont m_Font;
};
