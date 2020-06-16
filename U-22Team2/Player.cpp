#include "DxLib.h"
#include "Player.h"
#include "Controller.h"

extern image g_pic;
extern Controller g_Pad;

int Player(void) {
	static int cnt = 0;	//アニメーション用カウント変数

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[cnt++ / 10 % 2 + 1], TRUE, FALSE);//ネズミ画像の描画
	}
	else
	{
		DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[0], TRUE, FALSE);//ネズミ画像の描画
	}
	return 0;
}