
// Find_CircleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Find_Circle.h"
#include "Find_CircleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CFind_CircleDlg 对话框



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


// CFind_CircleDlg 消息处理程序

BOOL CFind_CircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	CStatic *pStaticWnd = (CStatic*)GetDlgItem(IDC_IMG_WND);     
	RECT rcParentWnd = { 0 }; pStaticWnd->GetWindowRect(&rcParentWnd);    
	ScreenToClient(&rcParentWnd);    
	int lret = SciCreateImageWnd((long)m_hWnd,  rcParentWnd.left, rcParentWnd.top, rcParentWnd.right, rcParentWnd.bottom, &m_lWndID);

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFind_CircleDlg::OnPaint()
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
HCURSOR CFind_CircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFind_CircleDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CFind_CircleDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CFind_CircleDlg::OnBnClickedButtonShowdlg()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取图像  
	SciImage image;  
	SciGetCurrentImage(m_lWndID,&image);   
	//显示功能界面 
	int lret = m_findcircleDlg.ShowDialog(image);
}


/*void CFind_CircleDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}*/


void CFind_CircleDlg::OnBnClickedSetparam()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取图像 
	SciImage image;                    
	SciGetCurrentImage(m_lWndID,&image); 

	//设置参数  
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

	//调用 SetParam 对界面参数进行设置  
	int lret=m_findcircleDlg.SetParam(ROI, edgeDirection, edgePolarity, edgeType,             
		minEdgeStrength, searchLineCount, rejectRatio, edgeWidth, projectionWidth,             
		displayLineFlag); 
	//打开界面  
	lret=m_findcircleDlg.ShowDialog(image); 
}


void CFind_CircleDlg::OnBnClickedExecute()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取图像  
	SciImage image;                     
	SciGetCurrentImage(m_lWndID,&image);   
	//声明界面变量  
	SciROI ROI;  
	SciCircleEdgeDirection edgeDirection ; 
	SciEdgePolarity edgePolarity ;  
	SciEdgeType edgeType ;  
	int minEdgeStrength , searchLineCount ,rejectRatio , edgeWidth , projectionWidth ; 
	bool displayLineFlag;  
	//声明结果变量  
	SciPointArray pointArray;   
	SciPoint circleCenter;   
	float circleRadius;    
	SciPointArray effectivePoints; 
	//调用 Execute 函数，Execute 需配合 SetParam 进行使用  
	int lret=m_findcircleDlg.GetParam(&ROI, &edgeDirection, &edgePolarity, &edgeType,
		&minEdgeStrength, &searchLineCount, &rejectRatio, &edgeWidth,             
		&projectionWidth, &displayLineFlag);  
	lret=m_findcircleDlg.SetParam(ROI, edgeDirection, edgePolarity, edgeType,            
		minEdgeStrength, searchLineCount, rejectRatio, edgeWidth, projectionWidth,            
		displayLineFlag); 
	lret=m_findcircleDlg.Execute(image,&pointArray,&effectivePoints, &circleCenter,
		&circleRadius);   
	//清理图像控件上的 Overlay  
	SciClearAllOverlay(m_lWndID); 
	//显示找到的结果，生成一个圆 Overlay 并显示在图像控件上  
	SciOverlay m_overlay;  
	m_overlay.GenCircle(circleCenter,circleRadius);  
	SciDrawOverlay(m_lWndID,m_overlay);  SciRefresh(m_lWndID); 
}


void CFind_CircleDlg::OnBnClickedFindcircle()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取图像  
	SciImage image;                     
	image.ReadImage("D:\\SciVision_Project\\FindCircle\\FindCircle\\1.bmp");            
	//设置参数  
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
	//声明结果变量  
	SciPointArray pointArray;   
	SciPoint circleCenter;    
	float circleRadius;     
	SciPointArray effectivePoints;  
	//声明算法类对象  
	SciFindCircle m_findcircle;  
	//调用算法 FindCircle  
	/*int lret = m_findcircleDlg.GetParam(&ROI, &edgeDirection, &edgePolarity, &edgeType,
		&minEdgeStrength, &searchLineCount, &rejectRatio, &edgeWidth,
		&projectionWidth, &displayLineFlag);*/
	long lret = m_findcircle.FindCircle(image,ROI, edgeDirection, edgePolarity, edgeType,               
		minEdgeStrength, searchLineCount, rejectRatio, edgeWidth,             
		projectionWidth,&pointArray,&effectivePoints, &circleCenter, &circleRadius);  
	//利用图像控件显示所处理图像  
	SciDisplayImage(m_lWndID,image);  
	//清理图像控件上的 Overlay  

	SciClearAllOverlay(m_lWndID);  
	//显示找到的结果，生成一个圆 Overlay 并显示在图像控件上  
	SciOverlay m_overlay;  
	m_overlay.GenCircle(circleCenter,circleRadius);  
	SciDrawOverlay(m_lWndID,m_overlay);  
	SciRefresh(m_lWndID); 

}


void CFind_CircleDlg::OnBnClickedRadioChinese()
{
	// TODO: 在此添加控件通知处理程序代码

	// 设置语言为中文  
	int LanguageType;  
	SciMultiLanguage m_MultipleLanguage;
	LanguageType = 2052;  
	m_MultipleLanguage.SelectLanguage(LanguageType); 
}


void CFind_CircleDlg::OnBnClickedRadioEnglish()
{
	// TODO: 在此添加控件通知处理程序代码

	// 设置语言为英语  
	int LanguageType;
	SciMultiLanguage m_MultipleLanguage;
	LanguageType = 1033;
	m_MultipleLanguage.SelectLanguage(LanguageType);
}


void CFind_CircleDlg::OnStnClickedImgWnd()
{
	// TODO: 在此添加控件通知处理程序代码
}
