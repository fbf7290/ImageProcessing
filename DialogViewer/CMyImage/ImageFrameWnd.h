#pragma once


// ImageFrameWnd 프레임입니다.

class ImageFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(ImageFrameWnd)
protected:
	ImageFrameWnd();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~ImageFrameWnd();

protected:
	DECLARE_MESSAGE_MAP()
};


