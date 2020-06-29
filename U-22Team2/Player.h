#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//ゲーム開始座標
	int y = 581;			//ゲーム開始座標
	int PickUpPixel;		//スポイトしている場所
	int NowColor = 99;		//デフォで白色

	//当たり判定用の色を格納する変数
	int Hit_Up,						// ___。__
		Hit_RightUp,				// 。     。
		Hit_LeftUp,					// |      |
		Hit_RightUnder,				// 。     。
		Hit_LeftUnder,				// L__。__l
		Hit_Under;					//四角形の６点で当たり判定を取得

	bool PLAYER_DIRECTION = FALSE,	//プレイヤーの向き//TRUE左向き/FALSE右向き
		PLAYER_JUMP = FALSE,		//プレイヤーがジャンプしたか
		PLAYER_PICKUP = FALSE,		//スポイト
		PLAYER_ACTION = FALSE,		//アクションボタン
		PLAYER_MENU = FALSE;		//メニュー
}; 

int PlayerDraw(void);	//関数の定義
