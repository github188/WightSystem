#pragma once


// CDlgAnalysis �Ի���

class CDlgAnalysis : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAnalysis)

public:
	CDlgAnalysis(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAnalysis();

// �Ի�������
	enum { IDD = IDD_DIALOG_ANALYSIS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
