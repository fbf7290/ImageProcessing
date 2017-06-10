
// ImageCalculatorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ImageCalculator.h"
#include "ImageCalculatorDlg.h"
#include "afxdialogex.h"
#include "CMyImage\LoadImageFileDialog.h"
#include "CMyImage\MyImageFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CImageCalculatorDlg ��ȭ ����



CImageCalculatorDlg::CImageCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_IMAGECALCULATOR_DIALOG, pParent)
	, m_bImgOperand(FALSE)
	, m_nOperator(0)
	, m_dOperandVal(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_IMAGE, m_bImgOperand);
	DDX_Radio(pDX, IDC_RADIO_PLUS, m_nOperator);
	DDX_Text(pDX, IDC_EDIT_CONST, m_dOperandVal);
}

BEGIN_MESSAGE_MAP(CImageCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOAD1, &CImageCalculatorDlg::OnBnClickedButtonLoad1)
	ON_BN_CLICKED(IDC_BUTTON_LOAD2, &CImageCalculatorDlg::OnBnClickedButtonLoad2)
	ON_BN_CLICKED(IDC_RADIO_IMAGE, &CImageCalculatorDlg::OnBnClickedRadioImage)
	ON_BN_CLICKED(IDC_RADIO_CONST, &CImageCalculatorDlg::OnBnClickedRadioConst)
	ON_BN_CLICKED(IDC_RADIO_NOT, &CImageCalculatorDlg::OnBnClickedRadioNot)
	ON_BN_CLICKED(IDC_BUTTON_CAL, &CImageCalculatorDlg::OnBnClickedButtonCal)
END_MESSAGE_MAP()


// CImageCalculatorDlg �޽��� ó����

BOOL CImageCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CImageCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CImageCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CImageCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CImageCalculatorDlg::OnBnClickedButtonLoad1()
{
	m_imageIn1 = LoadImageFromDialog();
	if (!m_imageIn1.IsEmpty())
		ShowImage(m_imageIn1, "�Է� ���� 1");
}


void CImageCalculatorDlg::OnBnClickedButtonLoad2()
{
	m_imageIn2 = LoadImageFromDialog();
	if (!m_imageIn2.IsEmpty())
		ShowImage(m_imageIn2, "�Է� ���� 2");
}


void CImageCalculatorDlg::OnBnClickedRadioImage()
{
	GetDlgItem(IDC_BUTTON_LOAD2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_CONST)->EnableWindow(FALSE);
	if (!m_imageIn2.IsEmpty())
		ShowImage(m_imageIn2, "�Է� ���� 2");
}


void CImageCalculatorDlg::OnBnClickedRadioConst()
{
	GetDlgItem(IDC_BUTTON_LOAD2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_CONST)->EnableWindow(TRUE);
	CloseImage("�Է� ���� 2");
}


void CImageCalculatorDlg::OnBnClickedRadioNot()
{
	GetDlgItem(IDC_BUTTON_LOAD2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_CONST)->EnableWindow(FALSE); 
}


bool CImageCalculatorDlg::_ImageOpImage()
{
	int nWidth = m_imageIn1.GetWidth();
	int nHeight = m_imageIn1.GetHeight();
	int nCh = m_imageIn1.GetChannel();

	if (m_nOperator != 6 &&
		(nWidth != m_imageIn2.GetWidth() ||
			nHeight != m_imageIn2.GetHeight() ||
			nCh != m_imageIn2.GetChannel()))
	{
		AfxMessageBox(_T("�Է� ������ �԰��� �ٸ��ϴ�."));
		return false;
	}

	switch (m_nOperator)
	{
	case 0: // +
		m_imageOut = m_imageIn1 + m_imageIn2;
		break;
	case 1: // -
		m_imageOut = m_imageIn1 - m_imageIn2;
		break;
	case 2: // *
		m_imageOut = m_imageIn1 * m_imageIn2;
		break;
	case 3: // /
		m_imageOut = m_imageIn1 / m_imageIn2;
		break;
	case 4: // &
		m_imageOut = m_imageIn1 & m_imageIn2;
		break;
	case 5: // |
		m_imageOut = m_imageIn1 | m_imageIn2;
		break;
	case 6: // ~
		m_imageOut = ~m_imageIn1;
		break;
	case 7: // ^
		m_imageOut = m_imageIn1 ^ m_imageIn2;
		break;
	default:
		break;
	}

	return true;
}

bool CImageCalculatorDlg::_ImageOpConst()
{
	switch (m_nOperator)
	{
	case 0: // +
		m_imageOut = m_imageIn1 + m_dOperandVal;
		break;
	case 1: // -
		m_imageOut = m_imageIn1 - m_dOperandVal;
		break;
	case 2: // *
		m_imageOut = m_imageIn1 * m_dOperandVal;
		break;
	case 3: // /
		m_imageOut = m_imageIn1 / m_dOperandVal;
		break;
	case 4: // &
		m_imageOut = m_imageIn1 & m_dOperandVal;
		break;
	case 5: // |
		m_imageOut = m_imageIn1 | m_dOperandVal;
		break;
	case 6: // ~
		m_imageOut = ~m_imageIn1;
		break;
	case 7: // ^
		m_imageOut = m_imageIn1 ^ m_dOperandVal;
		break;
	default:
		break;
	}

	return true;
}


void CImageCalculatorDlg::OnBnClickedButtonCal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);

	if (m_imageIn1.IsEmpty())
	{
		AfxMessageBox(_T("�Է� ���� 1�� �����ϴ�."));
		return;
	}
	
	bool bRet;
	if (!m_bImgOperand)
	{
		if (m_imageIn2.IsEmpty() && m_nOperator != 6)
		{
			AfxMessageBox(_T("�Է� ���� 2�� �����ϴ�."));
			return;
		}
		bRet = _ImageOpImage();
	}
	else
	{
		bRet = _ImageOpConst();
	}

	if (bRet)
	{
		ShowImage(m_imageOut, "��� ����");
		m_imageOut.SaveImage("Result.bmp");
	}
}
