#pragma once


// CDlgBasciSetting �Ի���

class CDlgBasciSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBasciSetting)

public:
	CDlgBasciSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgBasciSetting();

// �Ի�������
	enum { IDD = IDD_DIALOG_BASIC_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
