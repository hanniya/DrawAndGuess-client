#pragma once
#include "afxwin.h"


// CJoinDlg �Ի���

class CJoinDlg : public CDialog
{
	DECLARE_DYNAMIC(CJoinDlg)

public:
	CJoinDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJoinDlg();

// �Ի�������
	enum { IDD = IDD_CJOIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
