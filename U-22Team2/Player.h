#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//ゲーム開始座標
	int y = 581;			//ゲーム開始座標
	int PickUpPixel;		//スポイトしている場所

	bool PLAYER_DIRECTION,	//プレイヤーの向き//TRUE左向き/FALSE右向き
		PLAYER_JUMP,		//プレイヤーがジャンプしたか
		PLAYER_PICKUP,		//スポイト
		PLAYER_ACTION,		//アクションボタン
		PLAYER_MENU;		//メニュー
};


int PlayerDraw(void);	//関数の定義
