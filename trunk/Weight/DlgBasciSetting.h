#pragma once


// CDlgBasciSetting 对话框

class CDlgBasciSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBasciSetting)

public:
	CDlgBasciSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgBasciSetting();

// 对话框数据
	enum { IDD = IDD_DIALOG_BASIC_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
