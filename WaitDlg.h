#pragma once


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
};
