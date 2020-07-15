#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//メインとなるマップ画像
	int Player[5];		//主人公のネズミの画像
	int Object[10];		//オブジェクト画像
	int Title;			//タイトル画像
	int StageClear;		//ステージのクリア画像

	int Box;//オブジェクトの木の箱
	int Pin;//色取った場所のピン
	int Box_Move;//動く箱

	int shower;//シャワーの画像
	int shower_m; //シャワーの水画像

	int Reba;//レバー
};

int LoadPictue(void);	//関数の定義
