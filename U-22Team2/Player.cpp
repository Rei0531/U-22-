#include "DxLib.h"

//�v���O������WinMain����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)  return -1;		//DX���C�u��������������

	DrawPixel(320, 240, 0xffffff);  //�_��ł�

	WaitKey();					//�L�[���͑҂�

	DxLib_End();				//DX���C�u�����g�p�̏I������

	return 0;					//�\�t�g�̏I��

	//�o�O�������I�I�I�I�I�I�I�I�I�I�I�I�P
	//Why!?
	//kkk
}