
// VisualDataInDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VisualDataIn.h"
#include "VisualDataInDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVisualDataInDlg 对话框



CVisualDataInDlg::CVisualDataInDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVisualDataInDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_SN = _T("");
}

void CVisualDataInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Com);
	DDX_Control(pDX, IDC_COMBO2, m_Com2);
	DDX_Control(pDX, IDC_EDIT1, txt_ctrlSN);
}

BEGIN_MESSAGE_MAP(CVisualDataInDlg, CDialogEx)
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELENDOK(IDC_COMBO1, &CVisualDataInDlg::OnSelendokComboComselect)
	ON_CBN_SELENDOK(IDC_COMBO2, &CVisualDataInDlg::OnSelendokComboComselect2)
	ON_BN_CLICKED(IDC_BUTTON1, &CVisualDataInDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CVisualDataInDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CVisualDataInDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CVisualDataInDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CVisualDataInDlg 消息处理程序

BOOL CVisualDataInDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CVisualDataInDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CVisualDataInDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVisualDataInDlg::OnSelendokComboComselect()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_PortSN.m_hComm != NULL)
	{
		m_PortSN.ClosePort();
	}
	int m_nCom = m_Com.GetCurSel() + 1;
	m_dwCommEvents = EV_RXFLAG | EV_RXCHAR;
	CString strStatus;
	if (m_PortSN.InitPort(this, m_nCom, 115200, 'N', 8, 1, m_dwCommEvents, 512))
	{
		m_PortSN.StartMonitoring();
		//strStatus.Format("STATUS：COM%d OPENED，%d,%c,%d,%d", 1, 115200, 'N', 8, 1);
		//AfxMessageBox(strStatus);
		//m_ctrlIconOpenoff.SetIcon(m_hIconOff);

		//"当前状态：串口打开，无奇偶校验，8数据位，1停止位");
	}
	else
	{
		AfxMessageBox("没有发现此串口");
	}
}

void CVisualDataInDlg::OnSelendokComboComselect2()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_PortW.m_hComm != NULL)
	{
		m_PortW.ClosePort();
	}
	int m_nCom2 = m_Com2.GetCurSel() + 1;
	m_dwCommEvents = EV_RXFLAG | EV_RXCHAR;
	CString strStatus;
	if (m_PortW.InitPort(this, m_nCom2, 115200, 'N', 8, 1, m_dwCommEvents, 512))
	{
		m_PortW.StartMonitoring();
		//strStatus.Format("STATUS：COM%d OPENED，%d,%c,%d,%d", 1, 115200, 'N', 8, 1);
		//AfxMessageBox(strStatus);
		//m_ctrlIconOpenoff.SetIcon(m_hIconOff);

		//"当前状态：串口打开，无奇偶校验，8数据位，1停止位");
	}
	else
	{
		AfxMessageBox("没有发现此串口");
	}
}

static long rxdatacount = 0;  //该变量用于接收字符计数
LONG CVisualDataInDlg::OnCommunication(WPARAM ch, LPARAM port)
{
	if (port <= 0 || port > 4)
		return -1;
	rxdatacount++;   //接收的字节计数
	CString strTemp;
	strTemp.Format("%ld", rxdatacount);
	strTemp = "RX:" + strTemp;


	//如果选择了"十六进制显示"，则显示十六进制值
	CString str;
	str.Format("%c", ch);
	
	if (str == "#")
	{
		AfxMessageBox(m_ReceiveData);
		m_ReceiveData = "";
	}
	else
	{
		m_ReceiveData += str;
	}

	return 0;
}

static long g_CurSN = 0;
static CString g_CurSNStr = "";
static float g_CurW = 0;
void CVisualDataInDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PortSN.WriteToPort("123123123#");
}

void CVisualDataInDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PortW.WriteToPort("159.98#");
}

void CVisualDataInDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_PortW.WriteToPort("159.26#");
}

UINT ThreadFunc(LPVOID lpParam)
{
	CVisualDataInDlg* dlg = (CVisualDataInDlg*)lpParam;
	while (1)
	{
		g_CurSN++;
		CString str = "";
		str.Format(_T("%.10d#"), g_CurSN);
		g_CurSNStr = str;
		//AfxMessageBox(str);
		//发送SN
		Sleep(500);
		dlg->m_PortSN.WriteToPort(str);

		float max = RAND_MAX;//rand()函数随机数的最大值
		srand((unsigned)time(0));
		g_CurW = (float)((float)((rand() % 2) + 5) / ((rand() % 5) + 1));
		str.Format(_T("%f#"), g_CurW);
		
		//发送称前
		Sleep(500);
		dlg->m_PortW.WriteToPort(str);

		//发送SN
		Sleep(500);
		dlg->m_PortSN.WriteToPort(g_CurSNStr);

		//发送称后
		Sleep(500);
		g_CurW = g_CurW + 0.54f;
		str.Format(_T("%f#"), g_CurW);
		dlg->m_PortW.WriteToPort(str);

		Sleep(500);
	}
}

void CVisualDataInDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	CWinThread* pThread = AfxBeginThread(ThreadFunc, this);    //创建MFC线程
}
