
// WeightDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Weight.h"
#include "WeightDlg.h"
#include "afxdialogex.h"
#include "DialogExLogin.h"
#include "DlgQuery.h"
#include "DlgAnalysis.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeightDlg 对话框
#define WM_SHOWTASK				(WM_USER+100)



CWeightDlg::CWeightDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWeightDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWeightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRODUCT_BATCH, m_CEditProductBatch);
	DDX_Control(pDX, IDC_PRODUCT_SUM, m_CEditProductSum);
	DDX_Control(pDX, IDC_GOOD_PRODUCT_SUM, m_CEditGoodProductSum);
	DDX_Control(pDX, IDC_DEFECTIVE_PRODUCT_SUM, m_CEditDefectiveProductSum);
	DDX_Control(pDX, IDC_YIELD_RATE, m_CEditYieldRate);
	DDX_Control(pDX, IDC_LIST_PRE_WEIGHT, m_CSkinListCtrlPreWeight);
	DDX_Control(pDX, IDC_LIST_TRAYS, m_CSkinListCtrlTrays);
	DDX_Control(pDX, IDC_LIST_PRE_WEIGHT_INTIME, m_CSkinListCtrlPreWeightIntime);
	DDX_Control(pDX, IDC_LIST_BACK_WEIGHT_INTIME, m_CSkinListCtrlBackWeightIntime);
	DDX_Control(pDX, IDC_LIST_BACK_WEIGHT, m_CSkinListCtrlBackWeight);
	DDX_Control(pDX, IDC_LIST_DEFECTIVE_PRODUCT, m_CSkinListCtrlDefectiveProduct);
}

BEGIN_MESSAGE_MAP(CWeightDlg, CDialogEx)
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SHOWTASK, onShowTask)
	ON_BN_CLICKED(ID_EXIT, &CWeightDlg::OnBnClickedExit)
	ON_BN_CLICKED(ID_SETTING, &CWeightDlg::OnBnClickedSetting)
	ON_BN_CLICKED(ID_QUERY, &CWeightDlg::OnBnClickedQuery)
	ON_BN_CLICKED(ID_ANALYSIS, &CWeightDlg::OnBnClickedAnalysis)
	ON_BN_CLICKED(ID_START, &CWeightDlg::OnClickedStart)
END_MESSAGE_MAP()


// CWeightDlg 消息处理程序

BOOL CWeightDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWeightDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_MINIMIZE)
	{
		ToTray();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CWeightDlg::ToTray()
{
	NOTIFYICONDATA nid;

	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称 
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	strcpy_s(nid.szTip, _T("注夜称重系统"));//信息提示条为"计划任务提醒" 
	Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标 
	ShowWindow(SW_HIDE);//隐藏主窗口
}

//wParam接收的是图标的ID，而lParam接收的是鼠标的行为 
LRESULT CWeightDlg::onShowTask(WPARAM wParam, LPARAM lParam)
{
	//	if(wParam!=IDR_MAINFRAME) 
	//		return 1; 
	switch (lParam)
	{
	case WM_RBUTTONUP:
	{
		LPPOINT lpoint = new tagPOINT;
		::GetCursorPos(lpoint);
		CMenu menu;
		menu.CreatePopupMenu();
		//menu.AppendMenu(MF_STRING, WM_SHOWWINDOW, _T("显示主窗口"));
		menu.AppendMenu(MF_STRING, WM_DESTROY, _T("退出"));
		//确定弹出式菜单的位置 
		menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x, lpoint->y, this);
		//资源回收 
		HMENU hmenu = menu.Detach();
		menu.DestroyMenu();
		delete lpoint;
	}
	break;
	case WM_LBUTTONDOWN:
	{
		this->ShowWindow(SW_SHOW);
	}
	break;
	}
	return 0;
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWeightDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

// 		CRect rect;
// 		CPaintDC dc(this);
// 		GetClientRect(rect);
// 		dc.FillSolidRect(rect, RGB(200, 200, 200)); //设置为绿色背景

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWeightDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CWeightDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类

	//屏蔽ESC关闭窗体/
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;
	//屏蔽回车关闭窗体,但会导致回车在窗体上失效.
	//if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN && pMsg->wParam) return TRUE;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}


void CWeightDlg::OnBnClickedExit()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CWeightDlg::OnBnClickedSetting()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogExLogin m_Login;
	//m_Login.DoModal();

	//
	m_strSendData = "Donyj_ljj@163.com";
	if (m_Port.m_hComm == NULL)
	{
		AfxMessageBox("串口没有打开，请打开串口");
		return;
	}
	else
	{
		UpdateData(TRUE);

		m_Port.WriteToPort((LPCTSTR)m_strSendData);	//发送数据
		long TX_count = m_strSendData.GetLength();
		CString strTemp;
		strTemp.Format("TX:%d", TX_count);
		AfxMessageBox(strTemp + m_strSendData);
	}
}


void CWeightDlg::OnBnClickedQuery()
{
	// TODO:  在此添加控件通知处理程序代码
	CDlgQuery m_DlgQuery;
	m_DlgQuery.DoModal();
}


void CWeightDlg::OnBnClickedAnalysis()
{
	// TODO:  在此添加控件通知处理程序代码
	CDlgAnalysis m_DlgAnalysis;
	m_DlgAnalysis.DoModal();
}


void CWeightDlg::OnClickedStart()
{
	// TODO:  在此添加控件通知处理程序代码
	m_dwCommEvents = EV_RXFLAG | EV_RXCHAR;
	CString strStatus;
	if (m_Port.InitPort(this, 1, 115200, 'N', 8, 1, m_dwCommEvents, 512))
	{
		m_Port.StartMonitoring();
		strStatus.Format("STATUS：COM%d OPENED，%d,%c,%d,%d", 1, 115200, 'N', 8, 1);
		AfxMessageBox(strStatus);
		//m_ctrlIconOpenoff.SetIcon(m_hIconOff);

		//"当前状态：串口打开，无奇偶校验，8数据位，1停止位");
	}
	else
	{
		AfxMessageBox("没有发现此串口");
	}
}


LONG CWeightDlg::OnCommunication(WPARAM ch, LPARAM port)
{
	CString str;
	str.Format("%c", ch);
	m_ReceiveData += str;
	if (m_ReceiveData.GetLength() > 18)
	{
		AfxMessageBox(m_ReceiveData);
		m_ReceiveData = "";
	}
	return 0;
}
