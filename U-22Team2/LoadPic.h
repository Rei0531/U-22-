#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//メインとなるマップ画像
	int Player[20];		//スポイトマンの画像
	int Object[10];		//オブジェクト画像
	int Title;			//タイトル画像
	int StageClear;		//ステージのクリア画像
	int TitleChar[3];	//タイトルの文字

	int Box;//オブジェクトの木の箱
	int Pin;//色取った場所のピン
	int Box_Move;//動く箱

	int shower;//シャワーの画像
	int shower_m; //シャワーの水画像

	int Reba;//レバー

	int C_Switch;//色を反映するスイッチ
	int Rot_Box;//ローテーションするボックス

	int OneTimeSwitch_ON;//一度限りのスイッチONの画像
	int OneTimeSwitch_OFF;//一度限りのスイッチOFFの画像
	int Bomb;			//爆弾の画像

	int Warp_Area;

	int ChengObject[3];  //変形するオブジェクト

	int item;	//スポイト回復アイテム
};

int LoadPictue(void);	//関数の定義
