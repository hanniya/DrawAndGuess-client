#pragma once
#include "afxwin.h"


// WaitDlg �Ի���

class WaitDlg : public CDialog
{
	DECLARE_DYNAMIC(WaitDlg)

public:
	WaitDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~WaitDlg();

// �Ի�������
	enum { IDD = IDD_WAIT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedBeginButton();
public:
	afx_msg void OnClickedBeginButton();
	virtual BOOL OnInitDialog();
	int m_room_number;
	CString m_play1;
	CString m_play2;
	CString m_play3;
	CString m_play4;
	CString m_play5;
	CString m_play6;
	static void OnReceiveMessage(char*);
	static CString word;
	CButton m_btn;
};
