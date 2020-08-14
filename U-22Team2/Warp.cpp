#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

bool Warp_Flg = FALSE;
bool Warp_Flg2 = FALSE;
int Warp(int x1, int y1, int x2, int y2) {
	//この関数でワープ画像を描画・変数の初期化をし、さらに他の関数で処理を行うことも検討する
	int w1 = x1 + 100;
	int w2 = x2 + 100;
	int h1 = y1 + 100;
	int h2 = y2 + 100;
	DrawExtendGraph(x1, y1, w1, h1, g_pic.Warp_Area, TRUE);//ワープ用画像
	DrawExtendGraph(x2, y2, w2, h2, g_pic.Warp_Area, TRUE);//ワープ用画像
	//今は3つで1セットだが、2つで1対に変更する
	//最大2対までセットできるようにする
	if (g_Pad.KEY_B == TRUE) {
		if (Warp_Flg == FALSE) {
			Warp_Flg = TRUE;
			if (((g_Player.x >= x1) && (g_Player.x <= w1)) && ((g_Player.y >= y1) && (g_Player.y <= h1))) {
				g_Player.x = x2 + 50;
				g_Player.y = y2;
			}
			else if (((g_Player.x >= x2) && (g_Player.x <= w2)) && ((g_Player.y >= y2) && (g_Player.y <= h2))) {
				g_Player.x = x1 + 50;
				g_Player.y = y1;
			}
		}
	}
	else if (g_Pad.KEY_B == FALSE)
	{
		Warp_Flg = FALSE;
	}
	return 0;
}

int Warp2(int x_1, int y_1, int x_2, int y_2) {

	int w_1 = x_1 + 100;
	int w_2 = x_2 + 100;
	int h_1 = y_1 + 100;
	int h_2 = y_2 + 100;
	DrawExtendGraph(x_1, y_1, w_1, h_1, g_pic.Warp_Area2, TRUE);//ワープ用画像
	DrawExtendGraph(x_2, y_2, w_2, h_2, g_pic.Warp_Area2, TRUE);//ワープ用画像
	if (g_Pad.KEY_B == TRUE) {
		if (Warp_Flg2 == FALSE) {
			Warp_Flg2 = TRUE;
			if (((g_Player.x >= x_1) && (g_Player.x <= w_1)) && ((g_Player.y >= y_1) && (g_Player.y <= h_1))) {
				g_Player.x = x_2 + 50;
				g_Player.y = y_2;
			}
			else if (((g_Player.x >= x_2) && (g_Player.x <= w_2)) && ((g_Player.y >= y_2) && (g_Player.y <= h_2))) {
				g_Player.x = x_1 + 50;
				g_Player.y = y_1;
			}
		}
	}
	else if (g_Pad.KEY_B == FALSE)
	{
		Warp_Flg2 = FALSE;
	}
	return 0;
}