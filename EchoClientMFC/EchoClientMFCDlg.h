
// EchoClientMFCDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CEchoClientMFCDlg �Ի���
class CEchoClientMFCDlg : public CDialogEx
{
// ����
public:
	CEchoClientMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ECHOCLIENTMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit2();
	CEdit edit_ip;
	CEdit edit_port;
	CEdit edit_content;
	CEdit edit_count;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
};
