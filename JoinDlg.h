#pragma once


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
};
