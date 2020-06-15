#include "DxLib.h"
#include "Map.h"

extern MapCoordinate g_MapC;
MapCoordinate g_MapC;
image g_pic;

int Map(void) {			//ƒ}ƒbƒv‰æ‘œ‚Ì•`‰æ
	DrawBox(0, 0, 1280, 768, 0xffffff, TRUE);//”’‚¢ŽlŠp(”wŒi)
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);
	return 0;
}