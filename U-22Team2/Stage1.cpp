#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;

int Stage1(void) {			//マップ画像の描画

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画
	Change(BLUE);
	DrawBox(800, 0, 1000, 668, GetColor(255, 255, 255), TRUE);//青
	Change(RED);
	DrawBox(700, 550, 750, 668, GetColor(255, 255, 255), TRUE);//赤
	Door();			//ステージゴール処理
	ColorReset();

	return 0;
}