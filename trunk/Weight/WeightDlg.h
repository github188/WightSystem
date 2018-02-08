
// WeightDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "SkinListCtrl.h"
#include "SerialPort.h"

// CWeightDlg 对话框
class CWeightDlg : public CDialogEx
{
// 构造
public:
	CWeightDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WEIGHT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
