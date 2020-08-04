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
	int Walk;		//歩く
	int Reset;		//リセット時
	int MenuOpen;	//メニューオープン
	int MenuClose;	//メニュークローズ
	int Switch;		//スイッチ
	int Warp;		//ワープ
	int Landing;	//着地
	int MenuMove;	//メニュー内移動
	int Bomb;		//爆弾
	int StageBGM;	//ステージBGM
};

int LoadSound(void);	//関数の定義