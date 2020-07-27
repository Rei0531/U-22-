#include "DxLib.h"
#include"Gimmick.h"
#include"LoadPic.h"
#include "Player.h"


extern image g_pic;
extern GimmickAll gim;
extern Player g_Player;



int ChangeBlock() {

	if (g_Player.NowColor != gim.cheobj_c)gim.cheobj_flg++;

	DrawGraph(gim.cheobj_x, gim.cheobj_y, g_pic.ChengObject[gim.cheobj_flg % 3], TRUE);

	DrawGraph(gim.cheobj_x, gim.cheobj_y, g_pic.ChengObject[0], TRUE);

	gim.cheobj_c = g_Player.NowColor;


	return 0;
}