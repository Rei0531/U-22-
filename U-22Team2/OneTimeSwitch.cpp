#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;

int OTSwitchFlag = 0;//0‚ÅOFF‚»‚êˆÈŠO‚ÅON

int OneTimeSwitch(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > 800 && g_Player.x < 850 && OTSwitchFlag == 0) {
		OTSwitchFlag = 99;
	}

	if (OTSwitchFlag == 0) {
		Change(NONCOLOR);
		DrawBox(900, 0, 1000, 669, GetColor(255, 255, 255), TRUE);
	}
	else if (OTSwitchFlag != 0) {
		DrawBox(900, 0, 1000, 669, GetColor(255, 255, 255), TRUE);
		Change(NONCOLOR);
		DrawBox(720, 0, 770, 669, GetColor(255, 255, 255), TRUE);
	}

	if (g_Player.PLAYER_MENU == TRUE){	//Initˆ—‚ªŒÄ‚Î‚ê‚½‚ç‰Šú‰»
		OTSwitchFlag = 0;
}

	DrawFormatString(100, 300, 0xffffff,"OTS = %d", OTSwitchFlag);

	return 0;
}