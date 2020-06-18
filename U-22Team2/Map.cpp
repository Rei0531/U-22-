#include "DxLib.h"
#include "Map.h"
#include "Controller.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;

int Map(void) {			//ƒ}ƒbƒv‰æ‘œ‚Ì•`‰æ
	if (g_Pad.KEY_RIGHT == TRUE) {
		g_MapC.X1 -= PLAYERX;
		g_MapC.X2 -= PLAYERX;
	}
	if (g_Pad.KEY_LEFT == TRUE) {
		g_MapC.X1 += PLAYERX;
		g_MapC.X2 += PLAYERX;
	}
	DrawBox(0, 0, 1280, 768, 0xffffff, TRUE);//”’‚¢ŽlŠp(”wŒi)
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);
	return 0;
}