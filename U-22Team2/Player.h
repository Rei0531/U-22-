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

	int Anime_Num = 0;//0～3地上歩き、4～8ジャンプ、10～14、押す15～19引く

	//当たり判定用の色を格納する変数
	int Hit_Up = 0,						// ___。__
		Hit_RightUp = 0,				// 。     。
		Hit_LeftUp = 0,					// |      |
		Hit_RightUnder = 0,				// 。     。
		Hit_LeftUnder = 0,				// L_。_。_l
		Hit_Under = 0,					//四角形の７点で当たり判定を取得
		Hit_Under2 = 0,					//足の当たり判定二個目
		Hit_Rght_High = 0,				//頭の高さの右当たり判定
		Hit_Left_High = 0;				//頭の高さの左当たり判定

	int Move_Hit1,
		Move_Hit2;					//動かせるボックスの当たり判定色を取得

	bool PLAYER_DIRECTION = FALSE,	//プレイヤーの向き//TRUE左向き/FALSE右向き
		PLAYER_JUMP = FALSE,		//プレイヤーがジャンプしたか
		PLAYER_PICKUP = FALSE,		//スポイト
		PLAYER_ACTION = FALSE,		//アクションボタン
		PLAYER_MENU = FALSE,		//メニュー
		PLAYER_GROUND,				//地面にいる
		PLAYER_RESET = FALSE,		//リセット処理したか
		PLAYER_MOVEBOX_PUSH = FALSE,//動くブロックを押しているか
		PLAYER_MOVEBOX_PULL = FALSE;//動くブロックを引いているか
}; 

int PlayerDraw(void);	//関数の定義
