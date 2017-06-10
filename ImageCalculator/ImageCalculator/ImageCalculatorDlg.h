
// ImageCalculatorDlg.h : 헤더 파일
//

#pragma once
#include "CMyImage\ImageFrameWndManager.h"
#include "CMyImage\MyImage.h"
// CImageCalculatorDlg 대화 상자
class CImageCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CImageCalculatorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGECALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
