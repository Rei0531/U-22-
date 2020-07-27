#pragma once
#include "DxLib.h"
struct Sound {
public:
	int Suc;		//インタラクト成功時のSE
	int Mis;		//インタラクト失敗時のSE
	int flg;		//音を鳴らすフラグ 0:鳴らせる 1:鳴らせない
	int Key_Success;//鍵開け成功
	int Key_Miss;	//鍵開け失敗
	int leva;		//レバーのSE
	int BoxDrag;	//箱を引きずるSE
	int Shower;		//シャワーのSE
};

int LoadSound(void);	//関数の定義