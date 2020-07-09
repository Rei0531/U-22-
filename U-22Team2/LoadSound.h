#pragma once
#include "DxLib.h"
struct Sound {
public:
	int Suc;		//インタラクト成功時のSE
	int Mis;		//インタラクト失敗時のSE
	int flg;		//音を鳴らすフラグ 0:鳴らせる 1:鳴らせない
};

int LoadSound(void);	//関数の定義