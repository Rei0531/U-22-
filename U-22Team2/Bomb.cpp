#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

int Bomb(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > 700 && g_Player.x < 730 && gim.g_Bomb == 0) {		//爆弾の周辺でインタラクトを押すと爆弾を拾う
		gim.g_Bomb = 1;
		Change(WHITE);
		DrawBox(700, 638, 730, 668, 0xffffff, TRUE);
	}
	
	if (gim.g_Bomb == 1 && g_Pad.KEY_B == TRUE &&
		g_Player.x > 770 && g_Player.x < 799) {							//壁の周辺で使うと消費
		gim.g_Bomb = 2;
	}

	if (gim.g_Bomb == 0) {
		Change(RED);
		DrawBox(700, 638, 730, 668, 0xffffff, TRUE);					//拾ったので爆弾を消す
	}
	if (gim.g_Bomb != 2) {
		Change(NONCOLOR);
		DrawBox(800, 0, 850, 669, 0xffffff, TRUE);						//壁を破壊
	}


	Change(NONCOLOR);
	DrawFormatString(50, 100, 0xffffff, "Bomb = %d", gim.g_Bomb);

	return 0;
}