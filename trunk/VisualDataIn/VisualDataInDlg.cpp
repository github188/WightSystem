
// VisualDataInDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VisualDataIn.h"
#include "VisualDataInDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVisualDataInDlg �Ի���



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


// CVisualDataInDlg ��Ϣ�������

BOOL CVisualDataInDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVisualDataInDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVisualDataInDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVisualDataInDlg::OnSelendokComboComselect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		//strStatus.Format("STATUS��COM%d OPENED��%d,%c,%d,%d", 1, 115200, 'N', 8, 1);
		//AfxMessageBox(strStatus);
		//m_ctrlIconOpenoff.SetIcon(m_hIconOff);

		//"��ǰ״̬�����ڴ򿪣�����żУ�飬8����λ��1ֹͣλ");
	}
	else
	{
		AfxMessageBox("û�з��ִ˴���");
	}
}

void CVisualDataInDlg::OnSelendokComboComselect2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		//strStatus.Format("STATUS��COM%d OPENED��%d,%c,%d,%d", 1, 115200, 'N', 8, 1);
		//AfxMessageBox(strStatus);
		//m_ctrlIconOpenoff.SetIcon(m_hIconOff);

		//"��ǰ״̬�����ڴ򿪣�����żУ�飬8����λ��1ֹͣλ");
	}
	else
	{
		AfxMessageBox("û�з��ִ˴���");
	}
}

static long rxdatacount = 0;  //�ñ������ڽ����ַ�����
LONG CVisualDataInDlg::OnCommunication(WPARAM ch, LPARAM port)
{
	if (port <= 0 || port > 4)
		return -1;
	rxdatacount++;   //���յ��ֽڼ���
	CString strTemp;
	strTemp.Format("%ld", rxdatacount);
	strTemp = "RX:" + strTemp;


	//���ѡ����"ʮ��������ʾ"������ʾʮ������ֵ
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PortSN.WriteToPort("123123123#");
}

void CVisualDataInDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PortW.WriteToPort("159.98#");
}

void CVisualDataInDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		//����SN
		Sleep(500);
		dlg->m_PortSN.WriteToPort(str);

		float max = RAND_MAX;//rand()��������������ֵ
		srand((unsigned)time(0));
		g_CurW = (float)((float)((rand() % 2) + 5) / ((rand() % 5) + 1));
		str.Format(_T("%f#"), g_CurW);
		
		//���ͳ�ǰ
		Sleep(500);
		dlg->m_PortW.WriteToPort(str);

		//����SN
		Sleep(500);
		dlg->m_PortSN.WriteToPort(g_CurSNStr);

		//���ͳƺ�
		Sleep(500);
		g_CurW = g_CurW + 0.54f;
		str.Format(_T("%f#"), g_CurW);
		dlg->m_PortW.WriteToPort(str);

		Sleep(500);
	}
}

void CVisualDataInDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CWinThread* pThread = AfxBeginThread(ThreadFunc, this);    //����MFC�߳�
}
