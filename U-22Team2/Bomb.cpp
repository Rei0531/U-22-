#include "Gimmick.h"
#include "Color.h"
#include "LoadPic.h"
#include "Controller.h"
#include "Player.h"

extern image g_pic;
extern Player g_Player;
extern Controller g_Pad;
extern GimmickAll gim;

int Bomb(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x >  gim.BombX1 && g_Player.x < gim.BombX2 && gim.g_Bombflg == 0) {		//”š’e‚ÌŽü•Ó‚ÅƒCƒ“ƒ^ƒ‰ƒNƒg‚ð‰Ÿ‚·‚Æ”š’e‚ðE‚¤
		gim.g_Bombflg = 1;
		Change(WHITE);
		//DrawExtendGraph(700, 638, 730, 668, g_pic.Bomb, TRUE);
	}
	
	if (gim.g_Bombflg == 1 && g_Pad.KEY_B == TRUE &&
		g_Player.x > gim.B_WallX1 - 50 && g_Player.x < gim.B_WallX1) {							//•Ç‚ÌŽü•Ó‚ÅŽg‚¤‚ÆÁ”ï
	 gim.g_Bombflg = 2;
	}

	if (gim.g_Bombflg == 1) {
		DrawExtendGraph(g_Player.x -25, g_Player.y - 125, g_Player.x + 25, g_Player.y - 75, g_pic.Bomb, TRUE);
	}
	if (gim.g_Bombflg == 0) {
		DrawExtendGraph(gim.BombX1, gim.BombY1, gim.BombX2, gim.BombY2, g_pic.Bomb, TRUE);					//”š’e•`‰æ
	}
	if (gim.g_Bombflg != 3) {
		Change(NONCOLOR);
		DrawExtendGraph(gim.B_WallX1, gim.B_WallY1, gim.B_WallX2, gim.B_WallY2,g_pic.Object_Wall, TRUE);						//‰ó‚¹‚é•Ç‚Ì•`‰æ
		DrawRotaGraph((gim.B_WallX1 + gim.B_WallX2) / 2, (gim.B_WallY1 + gim.B_WallY2) / 2, 0.2, 0, g_pic.Bomb, TRUE, FALSE);
	}
	ColorReset();
	if (gim.g_Bombflg == 2) {
		if (gim.B_EffectCount >= 0) gim.B_EffectCount--;
		if (gim.B_EffectCount > 20) DrawRotaGraph(gim.B_WallX1, gim.B_WallY2 - 150, 1, 0, g_pic.BombEffect, TRUE, TRUE);
		if (gim.B_EffectCount <= 20 && gim.B_EffectCount > 10) DrawRotaGraph(gim.B_WallX1, gim.B_WallY2 - 150, 1, 0, g_pic.BombEffect, TRUE, FALSE);
		if (gim.B_EffectCount <= 10) DrawRotaGraph(gim.B_WallX1, gim.B_WallY2 - 150, 1, 0, g_pic.BombEffect, TRUE, TRUE);
		if (gim.B_EffectCount < 0) gim.g_Bombflg = 3;
	}

	DrawFormatString(50, 100, 0xffffff, "Bomb = %d", gim.B_EffectCount);
	Change(WHITE);

	return 0;
}