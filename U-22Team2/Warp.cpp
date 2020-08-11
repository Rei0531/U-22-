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

int Warp(int Setnum, int x1, int y1, int x2, int y2) {
	//この関数でワープ画像を描画・変数の初期化をし、さらに他の関数で処理を行うことも検討する
	int w1 = x1 + 100;
	int w2 = x2 + 100;
	int h1 = y1 + 100;
	int h2 = y1 + 100;
	if (Setnum == 1) {
		w2 = 0;
		h2 = 0;
	}else if (Setnum == 2) {
		DrawExtendGraph(x2, y2, w2, h2, g_pic.Warp_Area, TRUE);				//ワープ用画像
		DrawExtendGraph(x2, h2 + 300, w2, h2 + 400, g_pic.Warp_Area, TRUE);//ワープ用画像
	}
	DrawExtendGraph(x1, y1, w1, h1, g_pic.Warp_Area, TRUE);//ワープ用画像
	DrawExtendGraph(x1, h1 + 300, w1, h1 + 400, g_pic.Warp_Area, TRUE);//ワープ用画像
	//今は3つで1セットだが、2つで1対に変更する
	//最大2対までセットできるようにする
	if (g_Pad.KEY_B == TRUE) {
		if (Warp_Flg == FALSE) {
			Warp_Flg = TRUE;
			
			if (Setnum == 1) {
				if ((g_Player.x >= x1) && (g_Player.x <= w1) && (g_Player.y >= y1 - 100) && (g_Player.y <= h1)) {
					g_Player.x = x1 + 50;
					g_Player.y = h1 + 325;
				}
				else if ((g_Player.x >= x1) && (g_Player.x <= w1) && (g_Player.y >= h1 + 300) && (g_Player.y <= h1 + 400)) {
					g_Player.x = x1 + 50;
					g_Player.y = y1 + 25;
				}if (Setnum == 2) {
					if ((g_Player.x >= x1) && (g_Player.x <= w1) && (g_Player.y >= h1 + 300) && (g_Player.y <= h1 + 400)) {
						g_Player.x = x1 + 50;
						g_Player.y = y1 + 25;
					}
					else if ((g_Player.x >= x2) && (g_Player.x <= w2) && (g_Player.y >= y2 - 100) && (g_Player.y <= h2)) {
						g_Player.x = x2 + 50;
						g_Player.y = h2 + 325;
					}
				}
			}

			if ((g_Player.x >= x1) && (g_Player.x <= w1) && (g_Player.y >= y1 - 100) && (g_Player.y <= h1)) {
				g_Player.x = x1 + 50;
				g_Player.y = h1 + 325;
			}else if ((g_Player.x >= x1) && (g_Player.x <= w1) && (g_Player.y >= h1 + 300) && (g_Player.y <= h1 + 400)) {
				g_Player.x = x1 + 50;
				g_Player.y = y1 + 25;
			}else if ((g_Player.x >= x2) && (g_Player.x <= w2) && (g_Player.y >= y2 - 100) && (g_Player.y <= h2)) {
				g_Player.x = x2 + 50;
				g_Player.y = h2 + 325;
			}else if ((g_Player.x >= x2) && (g_Player.x <= w2) && (g_Player.y >= h2 + 300) && (g_Player.y <= h2 + 400)) {
				g_Player.x = x2 + 50;
				g_Player.y = y2 + 25;
			}
			/*if (gim.move_cnt == 0) {
				gim.move_cnt = 1;
			}
			else if (gim.move_cnt == 1) {
				gim.move_cnt = 0;
			}
			if ((g_Player.x >= x1) && (g_Player.x <= w1) && (g_Player.y <= y1 - 100) && (g_Player.y >= h1) && gim.move_cnt == 1) {
				g_Player.x = x1 + 50;
				g_Player.y = y1;
			}
			if ((g_Player.x >= x2) && (g_Player.x <= w2) && (g_Player.y <= y2) && (g_Player.y >= h2) && gim.move_cnt == 0) {
				g_Player.x = x2 + 50;
				g_Player.y = y2;
			}*/
		}
	}
	else if (g_Pad.KEY_B == FALSE)
	{
		Warp_Flg = FALSE;
	}
	/*if (g_Pad.KEY_B == TRUE) {
		if (Warp_Flg == FALSE) {
			Warp_Flg = TRUE;
			if (gim.move_cnt == 0) {
				gim.move_cnt = 1;
			}
			else if (gim.move_cnt == 1) {
				gim.move_cnt = 0;
			}
			if ((g_Player.x >= 368) && (g_Player.x <= 468) && (g_Player.y <= 668) && (g_Player.y >= 568) && gim.move_cnt == 1) {
				g_Player.x = 218;
				g_Player.y = 200;
			}
			if ((g_Player.x >= 868) && (g_Player.x <= 968) && (g_Player.y <= 268) && (g_Player.y >= 168) && gim.move_cnt == 0) {
				g_Player.x = 418;
				g_Player.y = 600;
			}
		}
	}
	else if (g_Pad.KEY_B == FALSE)
	{
		Warp_Flg = FALSE;
	}*/
	
	return 0;
}