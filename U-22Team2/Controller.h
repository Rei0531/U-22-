#pragma once
#include "DxLib.h"

struct Controller {
public:
	int NowKey  = GetJoypadInputState(DX_INPUT_KEY_PAD1);;		//現在のキー情報
	int OldKey = NowKey;		//前のキーの情報
	int KeyFlg = NowKey & ~OldKey;	//キーフラグ
};
void ControllerVlue(void);