#include "Gimmick.h"
#include "Color.h"
#include"Player.h"
#include "LoadPic.h"
#include "Controller.h"

extern image g_pic;
extern Player g_Player;
extern Controller g_Pad;
extern GimmickAll gim;



int Lever(void) {

	Change2(gim.SwitchColor);
	if ((g_Player.x > 0) & (g_Player.x < 100) & (g_Pad.KEY_B == TRUE)
		& (gim.SwitchFlag == 0) & (gim.SwitchWait == 0) & (g_Player.NowColor == gim.SwitchColor)) { //スイッチフラグがOFFであり待機時間が０でありスイッチと重なってあり
		gim.SwitchFlag = 1;														  //レバーの色と主人公が同じである状態でインタラクトを押すと箱が消える
		gim.SwitchWait = 10;
	}
	else if ((g_Player.x > 0) & (g_Player.x < 200) & (g_Pad.KEY_B == TRUE)	  //スイッチがONの場合はOFFに切り替える
		& (gim.SwitchFlag == 1) & (gim.SwitchWait == 0) & (g_Player.NowColor == gim.SwitchColor)) {  //レバーがONまたはOFFになった場合待機時間が加わる
		gim.SwitchFlag = 0;
		gim.SwitchWait = 10;
	}

	if (gim.SwitchFlag == 0) {			//オフ
		DrawRotaGraph(51, 337, 0.7, 0, g_pic.Reba, TRUE, FALSE);
	}
	else if (gim.SwitchFlag == 1) {		//オン
		DrawRotaGraph(51, 337, 0.7, 0, g_pic.Reba, TRUE, TRUE);
		//Change(WHITE);
		//DrawExtendGraph(200, 270, 300, 370, g_pic.Box, TRUE);
		Change(YELLOW);
		DrawExtendGraph(200, 265, 300, 370, g_pic.Box, TRUE);
	}
	
	if (gim.SwitchWait != 0) {													//待機時間がある場合減らし続ける
		gim.SwitchWait--;
	}

	return 0;
}


