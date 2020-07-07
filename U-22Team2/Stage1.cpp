#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;

int Stage1(void) {			//マップ画像の描画

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画
	//Change(BLUE);
	//DrawBox(800, 0, 1000, 668, GetColor(255, 255, 255), TRUE);//青
	//Change(RED);
	//DrawBox(700, 550, 750, 668, GetColor(255, 255, 255), TRUE);//赤
	//Change(GREEN);
	//DrawBox(1000, 550, 1050, 668, GetColor(255, 255, 255), TRUE);//緑
	Change(BLUE);
	DrawBox(400, 0, 500, 668, GetColor(255, 255, 255), TRUE);//青
	Change(RED);
	DrawBox(500, 0, 600, 668, GetColor(255, 255, 255), TRUE);//赤
	Change(LIGHTBLUE);
	DrawBox(600, 0, 700, 668, GetColor(255, 255, 255), TRUE);//緑
	Door();			//ステージゴール処理
	Lock();
	ColorReset();

	return 0;
}