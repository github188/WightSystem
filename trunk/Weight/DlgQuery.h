#pragma once


// CDlgQuery 对话框

class CDlgQuery : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgQuery)

public:
	CDlgQuery(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgQuery();

// 对话框数据
	enum { IDD = IDD_DIALOG_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
