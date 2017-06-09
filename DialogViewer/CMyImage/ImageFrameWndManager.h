#pragma once

#include <vector>
#include "ImageFrameWnd.h"

class CImageFrameWndManager
{
public:
	CImageFrameWndManager(void);
	~CImageFrameWndManager(void);

	void Add(CImageFrameWnd* pImageWnd);
	CImageFrameWnd* FindWnd(const char* name);
	void Delete(CImageFrameWnd* pImageWnd);
	void CloseAll();

protected:
	std::vector <CImageFrameWnd* > m_vpImageWnd;
};

extern void ShowImage(const CByteImage& input, const char *name = NULL);
extern void CloseImage(const char* name);
extern void CloseAllImages();
