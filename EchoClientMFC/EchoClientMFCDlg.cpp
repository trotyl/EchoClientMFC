
// EchoClientMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EchoClientMFC.h"
#include "EchoClientMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ��¼������Ϣ
int _protocol = 0;
char* _address = (char *)(malloc(20 * sizeof(char)));
char* _port = (char *)(malloc(10 * sizeof(char)));
char* _content = (char *)(malloc(100 * sizeof(char)));
char* _count = (char *)(malloc(10 * sizeof(char)));

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEchoClientMFCDlg �Ի���



CEchoClientMFCDlg::CEchoClientMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEchoClientMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEchoClientMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT2, size_edit);
	DDX_Control(pDX, IDC_EDIT2, edit_ip);
	DDX_Control(pDX, IDC_EDIT3, edit_port);
	DDX_Control(pDX, IDC_EDIT4, edit_content);
	DDX_Control(pDX, IDC_EDIT5, edit_count);
	DDX_Control(pDX, IDC_EDIT1, edit_current);
	DDX_Control(pDX, IDC_EDIT6, edit_average);
	DDX_Control(pDX, IDC_EDIT7, edit_variance);
}

BEGIN_MESSAGE_MAP(CEchoClientMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CEchoClientMFCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CEchoClientMFCDlg::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT2, &CEchoClientMFCDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &CEchoClientMFCDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT3, &CEchoClientMFCDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CEchoClientMFCDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CEchoClientMFCDlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CEchoClientMFCDlg ��Ϣ�������

BOOL CEchoClientMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CEchoClientMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEchoClientMFCDlg::OnPaint()
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
HCURSOR CEchoClientMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEchoClientMFCDlg::OnBnClickedRadio1()
{
	_protocol = SOCK_STREAM;
}


void CEchoClientMFCDlg::OnBnClickedRadio2()
{
	_protocol = SOCK_DGRAM;
}


void CEchoClientMFCDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString str;
	edit_ip.GetWindowTextW(str);

	USES_CONVERSION;
	char *tmp = T2A(str);
	strcpy(_address, tmp);
}

void CEchoClientMFCDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();

	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[100];
	int strLen = 0;
	int idx = 0, readLen = 0;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		MessageBox(CString("1.WSAStartup() error!"));
		return;
	}
	
	hSocket = socket(AF_INET, _protocol, 0);
	if (hSocket == INVALID_SOCKET)
	{
		MessageBox(CString("2.socket() error!"));
		return;
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.S_un.S_addr = inet_addr(_address);
	servAddr.sin_port = htons(atoi(_port));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		MessageBox(CString("3.connect() error!"));
		return;
	}

	std::vector <clock_t> *vt = new std::vector<clock_t>;

	freopen("log.txt", "w+", stdout);
	std::cout << "Log at " << time(NULL) << std::endl;
	std::cout << "Message is " << _content << std::endl;
	std::cout << "Start Time\t" << "Stop Time\t" << "Duration\t" << "Average\t" << "Variance" << std::endl;

	for (int i = 0; i < atoi(_count); i++)
	{
		send(hSocket, _content, sizeof(_content), 0);
		auto t1 = clock();
		recv(hSocket, message, sizeof(message), 0);
		auto t2 = clock();
		
		vt->push_back((t2 - t1) / 2);

		long sum = 0, sum_square = 0;
		for each (clock_t t in *vt)
		{
			sum += t;
			sum_square += t * t;
		}
		long average = 0, average_square = 0;
		average = sum / vt->size();
		average_square = sum_square / vt->size();
		
		long variance = average_square - average * average;

		char tmp[10];
		_itoa(i + 1, tmp, 10);
		edit_current.SetWindowTextW(CString(tmp));
		_itoa(average, tmp, 10);
		edit_average.SetWindowTextW(CString(tmp));
		_itoa(variance, tmp, 10);
		edit_variance.SetWindowTextW(CString(tmp));

		std::cout << t1 << "\t" << t2 << "\t" << (t2 - t1) / 2 << "\t" << average << "\t" << variance << std::endl;
	}
	closesocket(hSocket);
	WSACleanup();
}


void CEchoClientMFCDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	edit_port.GetWindowTextW(str);
	USES_CONVERSION;
	char *tmp = T2A(str);
	strcpy(_port, tmp);
}


void CEchoClientMFCDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	edit_content.GetWindowTextW(str);
	USES_CONVERSION;
	char *tmp = T2A(str);
	strcpy(_content, tmp);
}


void CEchoClientMFCDlg::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	edit_count.GetWindowTextW(str);
	USES_CONVERSION;
	char *tmp = T2A(str);
	strcpy(_count, tmp);
}
