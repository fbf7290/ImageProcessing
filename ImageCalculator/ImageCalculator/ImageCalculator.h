
// ImageCalculator.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CImageCalculatorApp:
// �� Ŭ������ ������ ���ؼ��� ImageCalculator.cpp�� �����Ͻʽÿ�.
//

class CImageCalculatorApp : public CWinApp
{
public:
	CImageCalculatorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CImageCalculatorApp theApp;
