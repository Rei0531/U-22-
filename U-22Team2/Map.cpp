#include "DxLib.h"
#include "Map.h"
#include "Controller.h"
#include "Stage_All.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;
extern Controller g_Pad;

int Map(void) {			//マップ画像の描画___________________________________________________________________________________________________________________

	//switch (g_MapC.StageNumber) {
	//case 1:
	//	Stage1();
	//	break;
	//default:
	//	break;
	//}


	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画

	//テスト用虹色のブロック
	DrawBox(100, 0, 200, 668, GetColor(255, 0, 0), TRUE);//赤
	DrawBox(200, 0, 300, 668, GetColor(255, 165, 0), TRUE);//オレンジ
	DrawBox(300, 0, 400, 668, GetColor(255, 255, 0), TRUE);//黄色
	DrawBox(400, 0, 500, 668, GetColor(0, 128, 0), TRUE);//緑
	DrawBox(500, 0, 600, 668, GetColor(0, 255, 254), TRUE);//水色
	DrawBox(600, 0, 700, 668, GetColor(0, 0, 254), TRUE);//青
	DrawBox(700, 0, 800, 668, GetColor(128, 0, 128), TRUE);//紫


	return 0;
}