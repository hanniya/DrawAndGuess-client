#pragma once


// CBeginDlg �Ի���

class CBeginDlg : public CDialog
{
	DECLARE_DYNAMIC(CBeginDlg)

public:
	CBeginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBeginDlg();

// �Ի�������
	enum { IDD = IDD_BEGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedCreatButton();
	afx_msg void OnBnClickedJoinRoom();
	virtual BOOL OnInitDialog();

private:
	CFont m_Font;
};
