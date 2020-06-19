#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
//来ていますか
extern image g_pic;
extern Controller g_Pad;

int Player(void) {
	static int cnt = 0;	//ネズミアニメーション用カウント変数
	static int RatX = 640;	//ネズミの座標X
	static int RatY = 645;	//ネズミの座標Y
	static int Jumpcnt;			//ジャンプ処理のカウント
	static int JumpMax = 40;	//ジャンプ処理全体にかかる最大時間//60フレームで1秒だからこの処理は1秒で合わる

	if (g_Pad.PLAYER_JUMP == TRUE) {	//ジャンプボタンが押されたら
		Jumpcnt++;

		if (Jumpcnt <= JumpMax /2) {	//処理の前半は上昇中
			RatY -= Jumpcnt;
		}
		else {
			RatY += Jumpcnt - JumpMax/2;
		}
	}
	else {
		Jumpcnt = 0;
	}

	if (Jumpcnt >= JumpMax)//ジャンプ処理の終了
		g_Pad.PLAYER_JUMP = FALSE;

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		//DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, FALSE);//ネズミ画像の描画
		DrawRotaGraph(RatX, RatY, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, g_Pad.PLAYER_DIRECTION);//ネズミ画像の描画
	}
	else
	{
		//DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[0], TRUE, FALSE);//ネズミ画像の描画
		DrawRotaGraph(RatX, RatY, 1.0, 0, g_pic.Player[0], TRUE, g_Pad.PLAYER_DIRECTION);//ネズミ画像の描画
	}
	return 0;
}