// DialogExLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "DialogExLogin.h"
#include "afxdialogex.h"
#include "DlgSetting.h"


// CDialogExLogin 对话框

IMPLEMENT_DYNAMIC(CDialogExLogin, CDialogEx)

CDialogExLogin::CDialogExLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogExLogin::IDD, pParent)
{

}

CDialogExLogin::~CDialogExLogin()
{
}

void CDialogExLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_CEditPassword);
	DDX_Control(pDX, IDC_EDIT_NEW_PW, m_CEditNewPw);
	DDX_Control(pDX, IDC_EDIT_NEW_PW2, m_CEditPw2);
	DDX_Control(pDX, IDC_CHECK_CHANGE_PW, m_CCheckChangePw);
}


BEGIN_MESSAGE_MAP(CDialogExLogin, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CDialogExLogin::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CDialogExLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogExLogin 消息处理程序


void CDialogExLogin::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDialogExLogin::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	// test
	CDlgSetting m_DlgSetting;
	m_DlgSetting.DoModal(); 
}


BOOL CDialogExLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
