#pragma once
#include "afxwin.h"


// CDialogExLogin 对话框

class CDialogExLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogExLogin)

public:
	CDialogExLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogExLogin();

// 对话框数据
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CEdit m_CEditPassword;
	CEdit m_CEditNewPw;
	CEdit m_CEditPw2;
	CButton m_CCheckChangePw;
	virtual BOOL OnInitDialog();
};
