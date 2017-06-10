#include "../stdafx.h"
#include "LoadImageFileDialog.h"
CByteImage LoadImageFromDialog()
{
	CByteImage image;	// 반환할 영상

						// 파일 대화상자에서 BMP 형식의 파일만 보이도록 하는 필터의 정의
	TCHAR szFilter[] = _T("BMP File (*.BMP) | *.BMP; | All Files(*.*)|*.*||");

	// 입력 영상 읽기
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK != dlg.DoModal()) // 대화 상자 열기
	{
		return image;
	}

	char * strPathName = _strdup(CT2A(dlg.GetPathName())); // 영상 파일 경로 획득
	image.LoadImage(strPathName); // 영상 읽기

	return image;
}