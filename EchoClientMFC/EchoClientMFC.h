
// EchoClientMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEchoClientMFCApp: 
// �йش����ʵ�֣������ EchoClientMFC.cpp
//

class CEchoClientMFCApp : public CWinApp
{
public:
	CEchoClientMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEchoClientMFCApp theApp;