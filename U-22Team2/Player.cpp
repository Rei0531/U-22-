#include "DxLib.h"

//プログラムはWinMainから始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)  return -1;		//DXライブラリ初期化処理

	DrawPixel(320, 240, 0xffffff);  //点を打つ

	WaitKey();					//キー入力待ち

	DxLib_End();				//DXライブラリ使用の終了処理

	return 0;					//ソフトの終了

	//バグ多すぎ！！！！！！！！！！！！１
	//Why!?
	//kkk
}