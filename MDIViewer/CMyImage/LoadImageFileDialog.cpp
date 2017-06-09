#include "../stdafx.h"
#include "LoadImageFileDialog.h"
CByteImage LoadImageFromDialog()
{
	CByteImage image;	// ��ȯ�� ����

						// ���� ��ȭ���ڿ��� BMP ������ ���ϸ� ���̵��� �ϴ� ������ ����
	TCHAR szFilter[] = _T("BMP File (*.BMP) | *.BMP; | All Files(*.*)|*.*||");

	// �Է� ���� �б�
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK != dlg.DoModal()) // ��ȭ ���� ����
	{
		return image;
	}

	char * strPathName = _strdup(CT2A(dlg.GetPathName())); // ���� ���� ��� ȹ��
	image.LoadImage(strPathName); // ���� �б�

	return image;
}