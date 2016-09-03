
// DrawDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "SocketContext.h"


// CDrawDlg �Ի���
class CDrawDlg : public CDialogEx
{
// ����
public:
	CDrawDlg(CWnd* pParent = NULL);	// ��׼���캯��


// �Ի�������
	enum { IDD = IDD_DRAW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CBrush   m_brush;
	COLORREF   m_color;
	CPoint last;
	CDC *pdc; //����


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CString m_MessageEdit;
	CString m_SendEdit;
	CButton m_SendButton;
	CString m_PlayerMes;
	CString m_TimeWord;
	afx_msg void OnBnClickedSendButton();
	CButton m_ReturnButton;
	CButton m_DeleteButton;
	afx_msg void OnBnClickedExitButton();
	CString m_word;
};
