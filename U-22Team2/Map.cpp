#include "DxLib.h"
#include "Map.h"
#include "Controller.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;

int Map(void) {			//マップ画像の描画
	if (g_Pad.KEY_RIGHT == TRUE) {	//プレイヤーの移動に合わせたスクロール処理
		g_MapC.X1 -= PLAYERX;
		g_MapC.X2 -= PLAYERX;
	}
	if (g_Pad.KEY_LEFT == TRUE) {
		g_MapC.X1 += PLAYERX;
		g_MapC.X2 += PLAYERX;
	}
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	return 0;
}