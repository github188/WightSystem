// DlgQuery.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgQuery.h"
#include "afxdialogex.h"


// CDlgQuery 对话框

IMPLEMENT_DYNAMIC(CDlgQuery, CDialogEx)

CDlgQuery::CDlgQuery(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgQuery::IDD, pParent)
{

}

CDlgQuery::~CDlgQuery()
{
}

void CDlgQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgQuery, CDialogEx)
END_MESSAGE_MAP()


// CDlgQuery 消息处理程序


BOOL CDlgQuery::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
