// DlgBasciSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgBasciSetting.h"
#include "afxdialogex.h"


// CDlgBasciSetting 对话框

IMPLEMENT_DYNAMIC(CDlgBasciSetting, CDialogEx)

CDlgBasciSetting::CDlgBasciSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgBasciSetting::IDD, pParent)
{

}

CDlgBasciSetting::~CDlgBasciSetting()
{
}

void CDlgBasciSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgBasciSetting, CDialogEx)
END_MESSAGE_MAP()


// CDlgBasciSetting 消息处理程序


BOOL CDlgBasciSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
