
// ImageCalculatorDlg.h : ��� ����
//

#pragma once
#include "CMyImage\ImageFrameWndManager.h"
#include "CMyImage\MyImage.h"
// CImageCalculatorDlg ��ȭ ����
class CImageCalculatorDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CImageCalculatorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGECALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


	bool _ImageOpImage();
	bool _ImageOpConst();
public:
	BOOL m_bImgOperand;
	int m_nOperator;
	double m_dOperandVal;
protected:
	CByteImage m_imageIn1;
	CByteImage m_imageIn2;
	CByteImage m_imageOut;
public:
	afx_msg void OnBnClickedButtonLoad1();
	afx_msg void OnBnClickedButtonLoad2();
	afx_msg void OnBnClickedRadioImage();
	afx_msg void OnBnClickedRadioConst();
	afx_msg void OnBnClickedRadioNot();
	afx_msg void OnBnClickedButtonCal();
};
