// C:\Users\user\Documents\Visual Studio 2017\Projects\DialogViewer\DialogViewer\CMyImage\ImageView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DialogViewer.h"
#include "C:\Users\user\Documents\Visual Studio 2017\Projects\DialogViewer\DialogViewer\CMyImage\ImageView.h"


// CImageView

IMPLEMENT_DYNCREATE(CImageView, CView)

CImageView::CImageView()
{

}

CImageView::~CImageView()
{
}

BEGIN_MESSAGE_MAP(CImageView, CView)
END_MESSAGE_MAP()


// CImageView �׸����Դϴ�.

void CImageView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CImageView �����Դϴ�.

#ifdef _DEBUG
void CImageView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CImageView �޽��� ó�����Դϴ�.
