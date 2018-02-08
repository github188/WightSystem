// Setting.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "MyTabCtrl.h"
#include "DlgBasciSetting.h"
#include "DlgComSetting.h"
#include "DlgSetting.h"
#include "afxdialogex.h"



// CSetting 对话框

IMPLEMENT_DYNAMIC(CDlgSetting, CDialogEx)

CDlgSetting::CDlgSetting(CWnd* pParent /*=NULL*/)
: CDialogEx(CDlgSetting::IDD, pParent)
{

}

CDlgSetting::~CDlgSetting()
{
}

void CDlgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SETTING, m_TabSetting);
}


BEGIN_MESSAGE_MAP(CDlgSetting, CDialogEx)
END_MESSAGE_MAP()


// CSetting 消息处理程序

BOOL CDlgSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitTabMain();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDlgSetting::InitTabMain()
{
	CRect tabRect;   // 标签控件客户区的位置和大小
	m_TabSetting.InsertItem(0, _T("基本设置"));
	m_TabSetting.InsertItem(1, _T("通讯设置"));


	m_TabSetting.InsetPage(0, IDD_DIALOG_BASIC_SETTING, new CDlgBasciSetting);
	m_TabSetting.InsetPage(1, IDD_DIALOG_COM_SETTING, new CDlgComSetting);
	
	m_TabSetting.SetNumberOfPages(2);

	m_TabSetting.SetCurrentPage(0);
}

