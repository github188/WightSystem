
// WeightDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "SkinListCtrl.h"
#include "SerialPort.h"

// CWeightDlg �Ի���
class CWeightDlg : public CDialogEx
{
// ����
public:
	CWeightDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WEIGHT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	void ToTray();
	afx_msg void OnPaint();
	afx_msg LRESULT onShowTask(WPARAM wParam, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedExit();
	CEdit m_CEditProductBatch;
	CEdit m_CEditProductSum;
	CEdit m_CEditGoodProductSum;
	CEdit m_CEditDefectiveProductSum;
	CEdit m_CEditYieldRate;
	CSkinListCtrl m_CSkinListCtrlPreWeight;
	CSkinListCtrl m_CSkinListCtrlTrays;
	CSkinListCtrl m_CSkinListCtrlPreWeightIntime;
	CSkinListCtrl m_CSkinListCtrlBackWeightIntime;
	CSkinListCtrl m_CSkinListCtrlBackWeight;
	CSkinListCtrl m_CSkinListCtrlDefectiveProduct;
	afx_msg void OnBnClickedSetting();
	afx_msg void OnBnClickedQuery();
	afx_msg void OnBnClickedAnalysis();
	afx_msg void OnClickedStart();
	afx_msg LONG OnCommunication(WPARAM ch, LPARAM port);
public:
	CSerialPort m_Port;
	DWORD m_dwCommEvents;
	CString m_ReceiveData;
	CString m_strSendData;
};
