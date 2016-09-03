
// DrawDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "SocketContext.h"


// CDrawDlg 对话框
class CDrawDlg : public CDialogEx
{
// 构造
public:
	CDrawDlg(CWnd* pParent = NULL);	// 标准构造函数


// 对话框数据
	enum { IDD = IDD_DRAW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CBrush   m_brush;
	COLORREF   m_color;
	CPoint last;
	CDC *pdc; //画板


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
