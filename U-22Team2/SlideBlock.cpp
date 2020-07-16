#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "Gimmick.h"

extern image g_pic;
extern Player g_Player;
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
		DrawExtendGraph(950 + gim.move_x, 320, 1100 + gim.move_x, 370, g_pic.Box, TRUE);//ìÆÇ≠è∞
		DrawExtendGraph(1180, 265, 1280, 370, g_pic.Box, TRUE);//êFéÊÇËÇÊÇ§ÇÃê‘

		return 0;
	}