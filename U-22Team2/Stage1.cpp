//#include "Map.h"
//#include "Controller.h"
//
////MapCoordinate g_MapC;
//extern MapCoordinate g_MapC;
//
//int Stage1(void) {			//マップ画像の描画
//
//	////プレイヤーの移動に合わせたスクロール処理_____________________________________________________________________________________________________________________
//	//if (g_Pad.KEY_RIGHT == TRUE) {		//プレイヤーが右に移動。マップは左にスクロール
//	//	if (g_MapC.X2 > SCREEN_WIDHT) {
//	//		g_MapC.X1 -= PLAYERX;
//	//		g_MapC.X2 -= PLAYERX;
//	//	}
//	//}
//	//if (g_Pad.KEY_LEFT == TRUE) {		//プレイヤーが左に移動。マップは右にスクロール
//	//	if (g_MapC.X1 < 0) {
//	//		g_MapC.X1 += PLAYERX;
//	//		g_MapC.X2 += PLAYERX;
//	//	}
//	//}
//	////_____________________________________________________________________________________________________________________
//
//	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
//	//色ブロック描画
//	DrawBox(800, 0, 900, 668, GetColor(0, 0, 255), TRUE);//青
//	DrawBox(700, 600, 750, 668, GetColor(255, 0, 0), TRUE);//赤
//
//	return 0;
//}