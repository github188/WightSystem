// DlgComSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgComSetting.h"
#include "afxdialogex.h"


// CDlgComSetting �Ի���

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


// CDlgComSetting ��Ϣ�������


BOOL CDlgComSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
