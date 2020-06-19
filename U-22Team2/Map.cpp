#include "DxLib.h"
#include "Map.h"
#include "Controller.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;
extern Controller g_Pad;

int Map(void) {			//マップ画像の描画

	//プレイヤーの移動に合わせたスクロール処理_____________________________________________________________________________________________________________________
	if (g_Pad.KEY_RIGHT == TRUE) {		//プレイヤーが右に移動。マップは左にスクロール
		if (g_MapC.X2 > SCREEN_WIDHT && g_MapC.MAP_MAX == FALSE) {
			g_MapC.X1 -= PLAYERX;
			g_MapC.X2 -= PLAYERX;
		}
		else {
			g_MapC.MAP_MAX = TRUE;		//マップ端に到着
		}
	}
	if (g_Pad.KEY_LEFT == TRUE) {		//プレイヤーが左に移動。マップは右にスクロール
		if (g_MapC.X1 < 0 && g_MapC.MAP_MAX == FALSE) {
			g_MapC.X1 += PLAYERX;
			g_MapC.X2 += PLAYERX;
		}
		else{
			g_MapC.MAP_MAX = TRUE;		//マップ端に到着
		}
	}
	//_____________________________________________________________________________________________________________________
	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	return 0;
}