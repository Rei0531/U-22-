#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "Gimmick.h"
#include "SlaidBlock.h"

extern image g_pic;
extern Player g_Player;
//extern SlideFunction g_SlaF;
extern GimmickAll gim;


	int SlideBlock(void)
	{
		Change(RED);
		gim.move_x -= gim.Speed;
		gim.move_x -= gim.Speed;
		if (gim.move_cnt++ > gim.move_max) {
			gim.move_cnt = 0;
			gim.Speed = gim.Speed * (-1);
		}
		//if (((g_Player.x - 30 >= g_SlaF.Sx1 + gim.move_x) && (g_Player.x + 30 <= g_SlaF.Sx2 + gim.move_x) &&
		//	((g_Player.y + 65 <= g_SlaF.Sy1) && (g_Player.y + 75 <= g_SlaF.Sy2))) &&
		//	((g_Player.Hit_Under == g_Player.NowColor) || (g_Player.Hit_Under2 == g_Player.NowColor))) {
		//	g_Player.x -= gim.Speed * 2;		//プレイヤーを自動で動かす
		//}
		if (((g_Player.x - 30 >= gim.SliObjx1 + gim.move_x) && (g_Player.x + 30 <= gim.SliObjx2 + gim.move_x) &&
			((g_Player.y + 65 <= gim.SliObjy1) && (g_Player.y + 75 <= gim.SliObjy2))) &&
			((g_Player.Hit_Under == g_Player.NowColor) || (g_Player.Hit_Under2 == g_Player.NowColor))) {
			g_Player.x -= gim.Speed * 2;		//プレイヤーを自動で動かす
		}
		//DrawExtendGraph(950 + gim.move_x, 320, 1100 + gim.move_x, 370, g_pic.Box, TRUE);//動く床
		DrawExtendGraph(gim.SliObjx1 + gim.move_x, gim.SliObjy1, gim.SliObjx2 + gim.move_x, gim.SliObjy2, g_pic.Box, TRUE);//動く床
		//DrawExtendGraph(1180, 265, 1280, 370, g_pic.Box, TRUE);//色取りようの赤
		DrawExtendGraph(gim.SliObjx1, gim.SliObjy1, gim.SliObjx2, gim.SliObjy2, g_pic.Box, TRUE);//色取りようの赤

		return 0;
	}