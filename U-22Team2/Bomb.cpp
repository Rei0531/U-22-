#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;

int g_Bomb = 0;

int Bomb(void) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > 800 && g_Player.x < 850 && g_Bomb == 0) {
		g_Bomb = 1;
	}

	if (g_Bomb == 0) {
	}
	else if (g_Bomb != 0) {
	}

	return 0;
}