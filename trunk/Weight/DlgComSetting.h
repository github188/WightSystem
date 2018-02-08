#pragma once


// CDlgComSetting 对话框

class CDlgComSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgComSetting)

public:
	CDlgComSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgComSetting();

// 对话框数据
	enum { IDD = IDD_DIALOG_COM_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
