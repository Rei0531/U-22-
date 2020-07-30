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

int Warp(void) {
	if (g_Pad.KEY_B == TRUE) {
		if (Warp_Flg == FALSE) {
			Warp_Flg = TRUE;
			if (gim.move_cnt == 0) {
				gim.move_cnt = 1;
			}
			else if (gim.move_cnt == 1) {
				gim.move_cnt = 0;
			}
			gim.move_cnt++;
			if ((g_Player.x >= 368) && (g_Player.x <= 468) && (g_Player.y <= 668) && (g_Player.y >= 568) && gim.move_cnt % 2 == 1) {
				g_Player.x = 218;
				g_Player.y = 200;
			}
			if ((g_Player.x >= 868) && (g_Player.x <= 968) && (g_Player.y <= 268) && (g_Player.y >= 168) && gim.move_cnt % 2 == 0) {
				g_Player.x = 418;
				g_Player.y = 600;
			}
		}
	}
	else if (g_Pad.KEY_B == FALSE)
	{
		Warp_Flg = FALSE;
	}
	/*if (g_Player.x >= 100 && g_Player.x <= 200) {
		Warp_No = 1;
	}
	else if (g_Player.x >= 200 && g_Player.x <= 300)
	{
		Warp_No = 2;
	}

	if (g_Pad.KEY_B == TRUE)
	{
		switch (Warp_No)
		{
		case 1:
			break;
		case 2:
			break;
		}
	}*/
	
	return 0;
}