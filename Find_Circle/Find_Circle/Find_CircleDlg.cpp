
// Find_CircleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Find_Circle.h"
#include "Find_CircleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFind_CircleDlg �Ի���



CFind_CircleDlg::CFind_CircleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FIND_CIRCLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFind_CircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFind_CircleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFind_CircleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CFind_CircleDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_SHOWDLG, &CFind_CircleDlg::OnBnClickedButtonShowdlg)
//	ON_BN_CLICKED(IDC_BUTTON1, &CFind_CircleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_SetParam, &CFind_CircleDlg::OnBnClickedSetparam)
	ON_BN_CLICKED(IDC_Execute, &CFind_CircleDlg::OnBnClickedExecute)
	ON_BN_CLICKED(IDC_FindCircle, &CFind_CircleDlg::OnBnClickedFindcircle)
	ON_BN_CLICKED(IDC_RADIO_Chinese, &CFind_CircleDlg::OnBnClickedRadioChinese)
	ON_BN_CLICKED(IDC_RADIO_English, &CFind_CircleDlg::OnBnClickedRadioEnglish)
	ON_STN_CLICKED(IDC_IMG_WND, &CFind_CircleDlg::OnStnClickedImgWnd)
END_MESSAGE_MAP()


// CFind_CircleDlg ��Ϣ�������

BOOL CFind_CircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	CStatic *pStaticWnd = (CStatic*)GetDlgItem(IDC_IMG_WND);     
	RECT rcParentWnd = { 0 }; pStaticWnd->GetWindowRect(&rcParentWnd);    
	ScreenToClient(&rcParentWnd);    
	int lret = SciCreateImageWnd((long)m_hWnd,  rcParentWnd.left, rcParentWnd.top, rcParentWnd.right, rcParentWnd.bottom, &m_lWndID);

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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFind_CircleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFind_CircleDlg::OnPaint()
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
HCURSOR CFind_CircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFind_CircleDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CFind_CircleDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CFind_CircleDlg::OnBnClickedButtonShowdlg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡͼ��  
	SciImage image;  
	SciGetCurrentImage(m_lWndID,&image);   
	//��ʾ���ܽ��� 
	int lret = m_findcircleDlg.ShowDialog(image);
}


/*void CFind_CircleDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}*/


void CFind_CircleDlg::OnBnClickedSetparam()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡͼ�� 
	SciImage image;                    
	SciGetCurrentImage(m_lWndID,&image); 

	//���ò���  
	SciROI ROI;  
	SciPoint centerPoint(100,100);  
	double radius = 100;  
	ROI.GenCircle(centerPoint,radius);  
	SciCircleEdgeDirection edgeDirection = SCI_FINDCIRCLE_INNER_TO_OUTER;  
	SciEdgePolarity edgePolarity = SCI_TYPE_DARK_TO_BRIGHT;
	SciEdgeType edgeType = SCI_TYPE_FIRST_EDGE;  
	int minEdgeStrength = 100, searchLineCount = 30,rejectRatio = 4;     
	int edgeWidth = 10, projectionWidth = 10; 
	bool displayLineFlag = 0; 

	//���� SetParam �Խ��������������  
	int lret=m_findcircleDlg.SetParam(ROI, edgeDirection, edgePolarity, edgeType,             
		minEdgeStrength, searchLineCount, rejectRatio, edgeWidth, projectionWidth,             
		displayLineFlag); 
	//�򿪽���  
	lret=m_findcircleDlg.ShowDialog(image); 
}


void CFind_CircleDlg::OnBnClickedExecute()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡͼ��  
	SciImage image;                     
	SciGetCurrentImage(m_lWndID,&image);   
	//�����������  
	SciROI ROI;  
	SciCircleEdgeDirection edgeDirection ; 
	SciEdgePolarity edgePolarity ;  
	SciEdgeType edgeType ;  
	int minEdgeStrength , searchLineCount ,rejectRatio , edgeWidth , projectionWidth ; 
	bool displayLineFlag;  
	//�����������  
	SciPointArray pointArray;   
	SciPoint circleCenter;   
	float circleRadius;    
	SciPointArray effectivePoints; 
	//���� Execute ������Execute ����� SetParam ����ʹ��  
	int lret=m_findcircleDlg.GetParam(&ROI, &edgeDirection, &edgePolarity, &edgeType,
		&minEdgeStrength, &searchLineCount, &rejectRatio, &edgeWidth,             
		&projectionWidth, &displayLineFlag);  
	lret=m_findcircleDlg.SetParam(ROI, edgeDirection, edgePolarity, edgeType,            
		minEdgeStrength, searchLineCount, rejectRatio, edgeWidth, projectionWidth,            
		displayLineFlag); 
	lret=m_findcircleDlg.Execute(image,&pointArray,&effectivePoints, &circleCenter,
		&circleRadius);   
	//����ͼ��ؼ��ϵ� Overlay  
	SciClearAllOverlay(m_lWndID); 
	//��ʾ�ҵ��Ľ��������һ��Բ Overlay ����ʾ��ͼ��ؼ���  
	SciOverlay m_overlay;  
	m_overlay.GenCircle(circleCenter,circleRadius);  
	SciDrawOverlay(m_lWndID,m_overlay);  SciRefresh(m_lWndID); 
}


void CFind_CircleDlg::OnBnClickedFindcircle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡͼ��  
	SciImage image;                     
	image.ReadImage("D:\\SciVision_Project\\FindCircle\\FindCircle\\1.bmp");            
	//���ò���  
	SciROI ROI;  
	SciPoint centerPoint(240,220);  
	double radius = 100; 
	ROI.GenCircle(centerPoint,radius);  
	SciCircleEdgeDirection edgeDirection = SCI_FINDCIRCLE_INNER_TO_OUTER;  
	SciEdgePolarity edgePolarity = SCI_TYPE_DARK_TO_BRIGHT;
	SciEdgeType edgeType = SCI_TYPE_FIRST_EDGE;  
	int minEdgeStrength = 20, searchLineCount = 40,rejectRatio = 1,edgeWidth = 1, 
		projectionWidth = 20; 
	bool displayLineFlag=0;
	//�����������  
	SciPointArray pointArray;   
	SciPoint circleCenter;    
	float circleRadius;     
	SciPointArray effectivePoints;  
	//�����㷨�����  
	SciFindCircle m_findcircle;  
	//�����㷨 FindCircle  
	/*int lret = m_findcircleDlg.GetParam(&ROI, &edgeDirection, &edgePolarity, &edgeType,
		&minEdgeStrength, &searchLineCount, &rejectRatio, &edgeWidth,
		&projectionWidth, &displayLineFlag);*/
	long lret = m_findcircle.FindCircle(image,ROI, edgeDirection, edgePolarity, edgeType,               
		minEdgeStrength, searchLineCount, rejectRatio, edgeWidth,             
		projectionWidth,&pointArray,&effectivePoints, &circleCenter, &circleRadius);  
	//����ͼ��ؼ���ʾ������ͼ��  
	SciDisplayImage(m_lWndID,image);  
	//����ͼ��ؼ��ϵ� Overlay  

	SciClearAllOverlay(m_lWndID);  
	//��ʾ�ҵ��Ľ��������һ��Բ Overlay ����ʾ��ͼ��ؼ���  
	SciOverlay m_overlay;  
	m_overlay.GenCircle(circleCenter,circleRadius);  
	SciDrawOverlay(m_lWndID,m_overlay);  
	SciRefresh(m_lWndID); 

}


void CFind_CircleDlg::OnBnClickedRadioChinese()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ��������Ϊ����  
	int LanguageType;  
	SciMultiLanguage m_MultipleLanguage;
	LanguageType = 2052;  
	m_MultipleLanguage.SelectLanguage(LanguageType); 
}


void CFind_CircleDlg::OnBnClickedRadioEnglish()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ��������ΪӢ��  
	int LanguageType;
	SciMultiLanguage m_MultipleLanguage;
	LanguageType = 1033;
	m_MultipleLanguage.SelectLanguage(LanguageType);
}


void CFind_CircleDlg::OnStnClickedImgWnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
