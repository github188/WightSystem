// DlgQuery.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgQuery.h"
#include "afxdialogex.h"


// CDlgQuery �Ի���

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


// CDlgQuery ��Ϣ�������


BOOL CDlgQuery::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
