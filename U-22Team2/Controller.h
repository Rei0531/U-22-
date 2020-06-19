#pragma once
#include "DxLib.h"

struct Controller {
public:
	int NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);;		//現在のキー情報
	int OldKey = NowKey;		//前のキーの情報
	int KeyFlg = NowKey & ~OldKey;	//キーフラグ
	int MouseX = 0;;
	int MouseY = 0;

	bool		//キーフラグ,TRUE,FALSEで返す。デフォルトはFALSE
		KEY_LEFT = FALSE,	//左入力
		KEY_RIGHT = FALSE, //右入力
		KEY_DOWN = FALSE,	//下入力
		KEY_UP = FALSE,		//上入力
		KEY_A = FALSE,		//Aボタン入力
		KEY_B = FALSE,		//Bボタン入力
		KEY_X = FALSE,		//Xボタン入力
		KEY_Y = FALSE,		//Yボタン入力
		KEY_LR = FALSE;	//L1,R1ボタン入力

	void KEY_Init() {			//キー入力状態をすべてリセットする
			KEY_LEFT = FALSE,	//左入力
			KEY_RIGHT = FALSE, //右入力
			KEY_DOWN = FALSE,	//下入力
			KEY_A = FALSE,		//Aボタン入力
			KEY_B = FALSE,		//Bボタン入力
			KEY_X = FALSE,		//Xボタン入力
			KEY_Y = FALSE,		//Yボタン入力
			KEY_LR = FALSE;	//L1,R1ボタン入力
	}
};
void ControllerVlue(void);