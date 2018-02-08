// DlgComSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgComSetting.h"
#include "afxdialogex.h"


// CDlgComSetting 对话框

IMPLEMENT_DYNAMIC(CDlgComSetting, CDialogEx)

CDlgComSetting::CDlgComSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgComSetting::IDD, pParent)
{

}

CDlgComSetting::~CDlgComSetting()
{
}

void CDlgComSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgComSetting, CDialogEx)
END_MESSAGE_MAP()


// CDlgComSetting 消息处理程序


BOOL CDlgComSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
