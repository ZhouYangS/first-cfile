
// Find_CircleDlg.h : ͷ�ļ�
//

#pragma once
#include"SciData.h"
#include"SciVision.h"
#include"SciDef.h"
#include"afxwin.h"
using namespace SCIVISION;

// CFind_CircleDlg �Ի���
class CFind_CircleDlg : public CDialogEx
{
// ����
public:
	CFind_CircleDlg(CWnd* pParent = NULL);	// ��׼���캯��



// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_CIRCLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	long long m_lWndID;
	//�������������
	SciFindCircleDlg m_findcircleDlg;


	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonShowdlg();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedSetparam();
	afx_msg void OnBnClickedExecute();
	afx_msg void OnBnClickedFindcircle();
	afx_msg void OnBnClickedRadioChinese();
	afx_msg void OnBnClickedRadioEnglish();
	afx_msg void OnStnClickedImgWnd();
};