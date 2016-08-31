#pragma once


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
};
