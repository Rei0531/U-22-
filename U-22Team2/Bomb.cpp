#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern GimmickAll gim;

int Bomb(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > 700 && g_Player.x < 730 && gim.g_Bomb == 0) {		//”š’e‚ÌŽü•Ó‚ÅƒCƒ“ƒ^ƒ‰ƒNƒg‚ð‰Ÿ‚·‚Æ”š’e‚ðE‚¤
		gim.g_Bomb = 1;
		Change(WHITE);
		DrawBox(700, 638, 730, 668, 0xffffff, TRUE);
	}
	
	if (gim.g_Bomb == 1 && g_Pad.KEY_B == TRUE &&
		g_Player.x > 770 && g_Player.x < 799) {							//•Ç‚ÌŽü•Ó‚ÅŽg‚¤‚ÆÁ”ï
		gim.g_Bomb = 2;
	}

	if (gim.g_Bomb == 0) {
		Change(RED);
		DrawBox(700, 638, 730, 668, 0xffffff, TRUE);					//E‚Á‚½‚Ì‚Å”š’e‚ðÁ‚·
	}
	if (gim.g_Bomb != 2) {
		Change(NONCOLOR);
		DrawBox(800, 0, 850, 669, 0xffffff, TRUE);						//•Ç‚ð”j‰ó
	}


	Change(NONCOLOR);
	DrawFormatString(50, 100, 0xffffff, "Bomb = %d", gim.g_Bomb);

	return 0;
}