// DlgBasciSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Weight.h"
#include "DlgBasciSetting.h"
#include "afxdialogex.h"


// CDlgBasciSetting �Ի���

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


// CDlgBasciSetting ��Ϣ�������


BOOL CDlgBasciSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
