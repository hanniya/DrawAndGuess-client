#pragma once


// CBeginDlg 对话框

class CBeginDlg : public CDialog
{
	DECLARE_DYNAMIC(CBeginDlg)

public:
	CBeginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBeginDlg();

// 对话框数据
	enum { IDD = IDD_BEGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedCreatButton();
	afx_msg void OnBnClickedJoinRoom();
	virtual BOOL OnInitDialog();

private:
	CFont m_Font;
};
