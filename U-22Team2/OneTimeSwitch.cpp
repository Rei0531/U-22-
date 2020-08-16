#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

int OneTimeSwitch(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > gim.OTS_X1 && g_Player.x < gim.OTS_X2 && g_Player.y > gim.OTS_Y1 - 30 && g_Player.y < gim.OTS_Y2 && gim.g_OTSwitchFlag == 0) {			//スイッチ周辺でインタラクトを押すと壁が消える
		gim.g_OTSwitchFlag = 99;
	}

	if (gim.g_OTSwitchFlag == 0) {
		DrawExtendGraph(gim.OTS_WallX1 + 35, gim.OTS_WallY1 + 140, gim.OTS_WallX2 - 35, gim.OTS_WallY2 - 199, g_pic.OneTimeSwitch_OFF, TRUE);
		DrawExtendGraph(gim.OTS_X1, gim.OTS_Y1, gim.OTS_X2, gim.OTS_Y2, g_pic.OneTimeSwitch_OFF, TRUE);
		Change(NONCOLOR);
		DrawExtendGraph(gim.OTS_WallX1, gim.OTS_WallY1, gim.OTS_WallX2, gim.OTS_WallY2,g_pic.Object_Wall, TRUE);					//スイッチが押されてないなら表示
	}																				
	else if (gim.g_OTSwitchFlag != 0) {												//押されたらON
		DrawExtendGraph(gim.OTS_X1, gim.OTS_Y1, gim.OTS_X2, gim.OTS_Y2, g_pic.OneTimeSwitch_ON, TRUE);
		//DrawExtendGraph(gim.OTS_WallX1, gim.OTS_WallY1, gim.OTS_WallX2, gim.OTS_WallY2 , GetColor(255, 255, 255), TRUE);
		Change(NONCOLOR);
		DrawBox(gim.OTS_C_WallX1, gim.OTS_C_WallY1, gim.OTS_C_WallX2, gim.OTS_C_WallY2, 0xffffff, TRUE);
		Change(RED);
	}

	//DrawFormatString(100, 300, 0xffffff,"WallY = %d", gim.OTS_WallY2);
	Change(WHITE);

	return 0;
}