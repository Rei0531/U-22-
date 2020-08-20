#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "Gimmick.h"
#include "SlaidBlock.h"

extern image g_pic;
extern Player g_Player;
//extern SlideFunction g_SlaF;
extern GimmickAll gim;


int SlideBlock(int SlaColor)
{
	Change(SlaColor);
	if ((((g_Player.x + 20 != gim.SliObjx1 + gim.move_x) && gim.Speed > 0) ||
		((g_Player.x - 20 != gim.SliObjx2 + gim.move_x) && gim.Speed < 0))) {
		//gim.move_x -= gim.Speed * 2;
		gim.SliObjx1 -= gim.Speed * 2;
		gim.SliObjx2 -= gim.Speed * 2;
		if (gim.move_cnt++ > gim.move_max) {
			gim.move_cnt = 0;
			gim.Speed = gim.Speed * (-1);
		}
	}
	DrawExtendGraph(gim.SliObjx1, gim.SliObjy1, gim.SliObjx2, gim.SliObjy2, g_pic.Box[0], TRUE);//動く床
	if ((g_Player.x + 20 >= gim.SliObjx1) && (g_Player.x - 20 <= gim.SliObjx2) &&
		(g_Player.y < gim.SliObjy1) && (g_Player.y > gim.SliObjy1 - 200) &&
		(g_Player.Hit_Under == g_Player.NowColor || g_Player.Hit_Under2 == g_Player.NowColor) &&
		(g_Player.Hit_Under == SlaColor || g_Player.Hit_Under2 == SlaColor)) {
		g_Player.x -= gim.Speed * 2;		//プレイヤーを自動で動かす
	}
	DrawExtendGraph(gim.GetObjx1, gim.GetObjy1, gim.GetObjx2, gim.GetObjy2, g_pic.Box[0], TRUE);//色取り用のブロック

	ColorReset();
	

	return SlaColor;
}
