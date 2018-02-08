// Setting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Weight.h"
#include "MyTabCtrl.h"
#include "DlgBasciSetting.h"
#include "DlgComSetting.h"
#include "DlgSetting.h"
#include "afxdialogex.h"



// CSetting �Ի���

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


// CSetting ��Ϣ�������

BOOL CDlgSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitTabMain();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDlgSetting::InitTabMain()
{
	CRect tabRect;   // ��ǩ�ؼ��ͻ�����λ�úʹ�С
	m_TabSetting.InsertItem(0, _T("��������"));
	m_TabSetting.InsertItem(1, _T("ͨѶ����"));


	m_TabSetting.InsetPage(0, IDD_DIALOG_BASIC_SETTING, new CDlgBasciSetting);
	m_TabSetting.InsetPage(1, IDD_DIALOG_COM_SETTING, new CDlgComSetting);
	
	m_TabSetting.SetNumberOfPages(2);

	m_TabSetting.SetCurrentPage(0);
}

