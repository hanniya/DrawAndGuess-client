#pragma once
#include "afxwin.h"
#include "SocketContext.h"


// WaitDlg �Ի���

class WaitDlg : public CDialog,private SocketContext
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
	CButton m_btn;
	void handleMessage(char*);
};
