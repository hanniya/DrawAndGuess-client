#pragma once


// WaitDlg 对话框

class WaitDlg : public CDialog
{
	DECLARE_DYNAMIC(WaitDlg)

public:
	WaitDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~WaitDlg();

// 对话框数据
	enum { IDD = IDD_WAIT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedBeginButton();
public:
//	int m_room_number;
	afx_msg void OnClickedBeginButton();
	virtual BOOL OnInitDialog();
	int m_room_number;
};
