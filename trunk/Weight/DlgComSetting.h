#pragma once


// CDlgComSetting �Ի���

class CDlgComSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgComSetting)

public:
	CDlgComSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgComSetting();

// �Ի�������
	enum { IDD = IDD_DIALOG_COM_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
