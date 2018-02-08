// DialogExLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Weight.h"
#include "DialogExLogin.h"
#include "afxdialogex.h"
#include "DlgSetting.h"


// CDialogExLogin �Ի���

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


// CDialogExLogin ��Ϣ�������


void CDialogExLogin::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CDialogExLogin::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// test
	CDlgSetting m_DlgSetting;
	m_DlgSetting.DoModal(); 
}


BOOL CDialogExLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
