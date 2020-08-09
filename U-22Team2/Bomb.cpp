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
		g_Player.x >  gim.BombX1 && g_Player.x < gim.BombX2 && gim.g_Bombflg == 0) {		//���e�̎��ӂŃC���^���N�g�������Ɣ��e���E��
		gim.g_Bombflg = 1;
		Change(WHITE);
		//DrawExtendGraph(700, 638, 730, 668, g_pic.Bomb, TRUE);
	}
	
	if (gim.g_Bombflg == 1 && g_Pad.KEY_B == TRUE &&
		g_Player.x > gim.B_WallX1 - 50 && g_Player.x < gim.B_WallX1) {							//�ǂ̎��ӂŎg���Ə���
	 gim.g_Bombflg = 2;
	}

	if (gim.g_Bombflg == 1) {
		DrawExtendGraph(g_Player.x -25, g_Player.y - 125, g_Player.x + 25, g_Player.y - 75, g_pic.Bomb, TRUE);
	}
	if (gim.g_Bombflg == 0) {
		DrawExtendGraph(gim.BombX1, gim.BombY1, gim.BombX2, gim.BombY2, g_pic.Bomb, TRUE);					//���e�`��
	}
	if (gim.g_Bombflg == 2) {
		if (gim.B_EffectCount >= 0) gim.B_EffectCount--;
		if(gim.B_EffectCount > 20) DrawRotaGraph(gim.B_WallX1, gim.B_WallY2 - 150, 1, 0, g_pic.BombEffect, TRUE, TRUE);
		if(gim.B_EffectCount <= 20 && gim.B_EffectCount > 10) DrawRotaGraph(gim.B_WallX1, gim.B_WallY2 - 150, 1, 0, g_pic.BombEffect, TRUE, FALSE);
		if(gim.B_EffectCount <= 10) DrawRotaGraph(gim.B_WallX1, gim.B_WallY2 - 150, 1, 0, g_pic.BombEffect,TRUE, TRUE);
		if (gim.B_EffectCount < 0) gim.g_Bombflg = 3;
	}
	if (gim.g_Bombflg != 3) {
		Change(NONCOLOR);
		DrawBox(gim.B_WallX1, gim.B_WallY1, gim.B_WallX2, gim.B_WallY2, GetColor(255,255,255), TRUE);						//�󂹂�ǂ̕`��
	}

	DrawFormatString(50, 100, 0xffffff, "Bomb = %d", gim.B_EffectCount);
	Change(WHITE);

	return 0;
}