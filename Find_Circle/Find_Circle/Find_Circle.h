
// Find_Circle.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFind_CircleApp: 
// �йش����ʵ�֣������ Find_Circle.cpp
//

class CFind_CircleApp : public CWinApp
{
public:
	CFind_CircleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFind_CircleApp theApp;