
// VisualDataIn.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVisualDataInApp: 
// �йش����ʵ�֣������ VisualDataIn.cpp
//

class CVisualDataInApp : public CWinApp
{
public:
	CVisualDataInApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVisualDataInApp theApp;