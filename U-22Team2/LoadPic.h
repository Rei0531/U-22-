#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//メインとなるマップ画像
	int Player[3];		//主人公のネズミの画像
	int Enemy[5];		//家主
};

int LoadPictue(void);	//関数の定義
