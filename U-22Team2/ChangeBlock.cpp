#include "DxLib.h"
#include"Gimmick.h"
#include"LoadPic.h"
#include "Player.h"
#include "Color.h"
#include "LoadSound.h"

#define PI 3.141592654

extern image g_pic;
extern GimmickAll gim;
extern Player g_Player;
extern Sound g_Snd;

int playermove_changeblock(int x, int y);

int flg = 0;

int ChangeBlock() {



	int x = 0;
	int y = 0;
	int ani_end = 0;

	ColorReset();


	switch (gim.cheobj_flg % 3)
	{
	case 0:

		if (gim.cheobj_zeroflg == 0) {
			x += gim.cheobj_x + 150;
			y += gim.cheobj_y + gim.cheobj_ani;
			gim.cheobj_sirusi = 0;

		}
		else if (gim.cheobj_zeroflg == 1) {
			x += gim.cheobj_x + 150 - gim.cheobj_ani;
			y += gim.cheobj_y + 158 - 24;
			gim.cheobj_sirusi = 2;
			if (gim.cheobj_ani == 150) gim.cheobj_sirusi = 1;
		}
		break;


	case 1:
		x += gim.cheobj_x;
		y += gim.cheobj_y + 158 - gim.cheobj_ani;
		gim.cheobj_sirusi = 1;
		if (gim.cheobj_ani == 158) gim.cheobj_sirusi = 3;
		break;
	case 2:
		x += gim.cheobj_x + gim.cheobj_ani;
		y += gim.cheobj_y;
		gim.cheobj_sirusi = 3;
		if (gim.cheobj_ani == 150) gim.cheobj_sirusi = 0;
		break;
	default:
		break;
	}





	if (g_Player.NowColor != gim.cheobj_c) {
		gim.cheobj_flg++;
		gim.cheobj_ani = 0;
		gim.cheobj_zeroflg = 0;
	}




	if (gim.cheobj_flg % 3 == 0) {
		if (gim.cheobj_zeroflg == 0 && gim.cheobj_ani != 150 - 24) {
			gim.cheobj_ani += 2;
			PlaySoundMem(g_Snd.ChangeBlockPlay, DX_PLAYTYPE_BACK);


		}
		else if (gim.cheobj_zeroflg == 0) {
			gim.cheobj_zeroflg = 1;
			gim.cheobj_ani = 0;
		}

		if (gim.cheobj_zeroflg == 1 && gim.cheobj_ani != 150) {
			gim.cheobj_ani += 2;
			PlaySoundMem(g_Snd.ChangeBlockPlay, DX_PLAYTYPE_BACK);

		}

	}





	if (gim.cheobj_flg % 3 == 1 && 158 != gim.cheobj_ani) {
		gim.cheobj_ani++;
		PlaySoundMem(g_Snd.ChangeBlockPlay, DX_PLAYTYPE_BACK);
	}
	else if ((gim.cheobj_flg % 3 == 2 && 150 != gim.cheobj_ani) && (flg == 0)) {
		gim.cheobj_ani += 2;
		PlaySoundMem(g_Snd.ChangeBlockPlay, DX_PLAYTYPE_BACK);
	}
	else {
		ani_end = 1;
	}


	DrawGraph(x, y, g_pic.ChengObject[1], TRUE);
	DrawGraph(gim.cheobj_x, gim.cheobj_y, g_pic.ChengObject[0], TRUE);
	DrawGraph(x, y + 20, g_pic.ChengObjectmark[gim.cheobj_sirusi], TRUE);
	gim.cheobj_c = g_Player.NowColor;

	playermove_changeblock(x, y);

	return 0;
}



int playermove_changeblock(int x, int y) {

	if ((gim.cheobj_flg % 3 == 1) && (gim.cheobj_ani != 158) && (g_Player.PLAYER_JUMP != TRUE) &&
		(x <= g_Player.x + 5 && x + 75 >= g_Player.x + 5) &&
		(y >= g_Player.y - 55) && (y <= g_Player.y + 50))
	{
		g_Player.y = y - 50;

	}


	if ((gim.cheobj_flg % 3 == 2) && (gim.cheobj_ani != 150) &&
		(x + 75 < g_Player.x && x + 95 >= g_Player.x) &&
		(y - 80 <= g_Player.y) && (y + 150 >= g_Player.y))
	{
		flg = 1;
	}
	else {
		flg = 0;
	}

	if ((gim.cheobj_flg % 3 == 0) && (gim.cheobj_ani != 158) && (g_Player.PLAYER_JUMP != TRUE) &&
		(x <= g_Player.x + 5 && x + 75 >= g_Player.x + 5) &&
		(y >= g_Player.y - 55) && (y <= g_Player.y + 50))
	{
		g_Player.y = y - 50;

	}
	return 0;

}