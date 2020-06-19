#pragma once
#include "LoadPic.h"

struct Rat {
public:
	int x = 110;			//ゲーム開始座標
	int y = 645;			//ゲーム開始座標
	bool PLAYER_DIRECTION,	//プレイヤーの向き
		PLAYER_JUMP,		//プレイヤーがジャンプしたか
		PLAYER_SQUAT,		//しゃがみ
		PLAYER_ACTION,		//アクションボタン
		PLAYER_MENU;		//メニュー
};

int Player(void);	//関数の定義
