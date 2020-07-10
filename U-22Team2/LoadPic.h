#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//メインとなるマップ画像
	int Player[5];		//主人公のネズミの画像
	int Object[10];		//オブジェクト画像
	int Title;			//タイトル画像
	int StageClear;		//ステージのクリア画像

	int Box;//視覚
};

int LoadPictue(void);	//関数の定義
