#pragma once


// CImageView ���Դϴ�.

class CImageView : public CView
{
	DECLARE_DYNCREATE(CImageView)

protected:
	CImageView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CImageView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


