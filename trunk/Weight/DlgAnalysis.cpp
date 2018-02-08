// DlgAnalysis.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgAnalysis.h"
#include "afxdialogex.h"


// CDlgAnalysis 对话框

IMPLEMENT_DYNAMIC(CDlgAnalysis, CDialogEx)

CDlgAnalysis::CDlgAnalysis(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAnalysis::IDD, pParent)
{

}

CDlgAnalysis::~CDlgAnalysis()
{
}

void CDlgAnalysis::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAnalysis, CDialogEx)
END_MESSAGE_MAP()


// CDlgAnalysis 消息处理程序


BOOL CDlgAnalysis::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
