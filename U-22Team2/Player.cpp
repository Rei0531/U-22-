#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;

int PlayerDraw(void) {
	static int cnt = 0;	//スポイントマンアニメーション用カウント変数
	static int Jumpcnt;			//ジャンプ処理のカウント
	static int JumpMax = 36;	//ジャンプ処理全体にかかる最大時間


	//プレイヤーの移動処理_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//右か左に入力されていたら
	{
		if (g_Player.x < g_MapC.X1) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、左端に到達
			g_Player.x = g_MapC.X1;
		}
		if (g_Player.x > g_MapC.X2) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、右端に到達
			g_Player.x = g_MapC.X2;
		}

		g_Player.x += (g_Pad.KEY_RIGHT) ? PLAYERX : -PLAYERX;		//プレイヤー自身のX軸を加減算

		cnt++;//アニメーション用のカウントプラス
	}
	CC.Change(2);//引数に色の名前/数字を入れて値を変更
	DrawRotaGraph(g_Player.x, g_Player.y, 1.0, 0, g_pic.Player[cnt / 10 % 5], TRUE, g_Player.PLAYER_DIRECTION);//プレイヤー画像の描画
	CC.ColorReset();//画面全体の変色を元に戻す

	//プレイヤーのジャンプ処理_____________________________________________________________________________________________________________________
	if (g_Player.PLAYER_JUMP == TRUE) {	//ジャンプボタンが押されたら

		Jumpcnt++;		//ジャンプアニメーションのカウント開始

		g_Player.y += (Jumpcnt <= JumpMax / 2) ? -Jumpcnt : Jumpcnt - JumpMax / 2;

		if (Jumpcnt >= JumpMax) {		//ジャンプアニメーションが決められた時間になったとき
			g_Player.PLAYER_JUMP = FALSE;//ジャンプ処理の終了
			Jumpcnt = 0;				//ジャンプアニメーションのカウントを0にする
		}
	}
	//_____________________________________________________________________________________________________________________
	return 0;
}