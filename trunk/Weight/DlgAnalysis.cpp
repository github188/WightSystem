// DlgAnalysis.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgAnalysis.h"
#include "afxdialogex.h"


// CDlgAnalysis �Ի���

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


// CDlgAnalysis ��Ϣ�������


BOOL CDlgAnalysis::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
