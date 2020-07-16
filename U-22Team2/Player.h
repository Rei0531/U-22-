#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//ゲーム開始座標
	int y = 571;			//ゲーム開始座標
	int PickUpPixel;		//スポイトしている場所
	int PickUpPixely;		//スポイトしている場所
	int NowColor = 4;		//デフォで白色
	int Interact = 0;		//プレイヤーのスポイトできる回数/ステージごとに値を入れる

	//当たり判定用の色を格納する変数
	int Hit_Up,						// ___。__
		Hit_RightUp,				// 。     。
		Hit_LeftUp,					// |      |
		Hit_RightUnder,				// 。     。
		Hit_LeftUnder,				// L_。_。_l
		Hit_Under,					//四角形の７点で当たり判定を取得
		Hit_Under2;					//

	int Move_Hit1,
		Move_Hit2;					//動かせるボックスの当たり判定色を取得

	bool PLAYER_DIRECTION = FALSE,	//プレイヤーの向き//TRUE左向き/FALSE右向き
		PLAYER_JUMP = FALSE,		//プレイヤーがジャンプしたか
		PLAYER_PICKUP = FALSE,		//スポイト
		PLAYER_ACTION = FALSE,		//アクションボタン
		PLAYER_MENU = FALSE,		//メニュー
		PLAYER_GROUND;				//地面にいる
}; 

int PlayerDraw(void);	//関数の定義
