#pragma once


// CDlgQuery �Ի���

class CDlgQuery : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgQuery)

public:
	CDlgQuery(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgQuery();

// �Ի�������
	enum { IDD = IDD_DIALOG_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
