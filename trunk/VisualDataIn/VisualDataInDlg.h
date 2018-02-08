
// VisualDataInDlg.h : ͷ�ļ�
//

#pragma once
#include "SerialPort.h"
#include "afxwin.h"

// CVisualDataInDlg �Ի���
class CVisualDataInDlg : public CDialogEx
{
// ����
public:
	CVisualDataInDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VISUALDATAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LONG OnCommunication(WPARAM ch, LPARAM port);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnSelendokComboComselect();

public:
	CSerialPort m_PortSN;
	CSerialPort m_PortW;
	CString	m_ReceiveData;
	CString	m_strSendData;
	DWORD m_dwCommEvents;
	afx_msg void OnSelendokComboComselect2();
	CComboBox m_Com;
	CComboBox m_Com2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	CEdit txt_ctrlSN;
	CString m_SN;
};
