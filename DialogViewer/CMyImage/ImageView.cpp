// C:\Users\user\Documents\Visual Studio 2017\Projects\DialogViewer\DialogViewer\CMyImage\ImageView.cpp : 구현 파일입니다.
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


// CImageView 그리기입니다.

void CImageView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CImageView 진단입니다.

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


// CImageView 메시지 처리기입니다.
