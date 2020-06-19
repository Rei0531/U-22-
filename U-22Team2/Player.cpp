#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Rat g_Rat;

int Player(void) {
	static int cnt = 0;	//ネズミアニメーション用カウント変数
	static int Jumpcnt;			//ジャンプ処理のカウント
	static int JumpMax = 46;	//ジャンプ処理全体にかかる最大時間//60フレームで1秒だからこの処理は1秒で合わる



	//プレイヤーの移動処理_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//右か左に入力されていたら
	{
		if (g_Rat.x < g_MapC.X1) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、左端に到達
			g_Rat.x = g_MapC.X1;
		}
		if (g_Rat.x > g_MapC.X2) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、右端に到達
			g_Rat.x = g_MapC.X2;
		}

		if (g_MapC.MAP_MAX == TRUE && g_MapC.X1 <= g_Rat.x && g_MapC.X2 >= g_Rat.x) {		//マップ端かつプレイヤーが画面内にいる時
			g_Rat.x += (g_Pad.KEY_RIGHT) ? PLAYERX : -PLAYERX;		//プレイヤー自身のX軸を加減算
		}
		DrawRotaGraph(g_Rat.x, g_Rat.y, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, g_Rat.PLAYER_DIRECTION);//ネズミ画像の描画

		g_MapC.MAP_MAX = (g_Rat.x == 640) ? FALSE : TRUE;
	}
	else {													//何も入力されていないとき待機モーション
		DrawRotaGraph(g_Rat.x, g_Rat.y, 1.0, 0, g_pic.Player[0], TRUE, g_Rat.PLAYER_DIRECTION);//ネズミ画像の描画
	}
	//プレイヤーのジャンプ処理_____________________________________________________________________________________________________________________
	if (g_Rat.PLAYER_JUMP == TRUE) {	//ジャンプボタンが押されたら

		Jumpcnt++;		//ジャンプアニメーションのカウント開始

		g_Rat.y += (Jumpcnt <= JumpMax / 2) ? -Jumpcnt : Jumpcnt - JumpMax / 2;

		if (Jumpcnt >= JumpMax) {		//ジャンプアニメーションが決められた時間になったとき
			g_Rat.PLAYER_JUMP = FALSE;//ジャンプ処理の終了
			Jumpcnt = 0;				//ジャンプアニメーションのカウントを0にする
		}
	}
	//_____________________________________________________________________________________________________________________
	return 0;
}