#include "DxLib.h"
#include "Map.h"
#include "Controller.h"
#include "Stage_All.h"
#include "Lock.h"
#include"Player.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;
extern Controller g_Pad;
extern LockALL g_Lock;
extern Player g_Player;

int Map(void) {			//マップ画像の描画___________________________________________________________________________________________________________________

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画


	switch (g_MapC.StageNumber) {
	case 1:
		Stage1();
		break;
	case 2:
		Stage2();
		break;
	case 3:
		Stage3();
		break;
	case 4:
		Stage4();
		break;
	case 5:
		Stage5();
		break;
	case 6:
		Stage6();
		break;
	case 7:
		Stage7();
		break;
	case 8:
		Stage8();
		break;
	case 9:
		Stage9();
		break;
	case 10:
		Stage10();
		break;
	case 11:
		Stage11();
		break;
	case 12:
		Stage12();
		break;
	case 13:
		Stage13();
		break;
	case 14:
		Stage14();
		break;
	case 15:
		Stage15();
		break;
	case 16:
		Stage16();
		break;
	default:
		break;
	}

	//残り回数の表示
	DrawFormatString(g_Player.x - 30, g_Player.y - 150, g_Player.NowColor, "残り%d", g_Player.Interact);


	if ((g_Lock.clearflg == TRUE) & (g_Pad.KEY_B == FALSE)) {
		GameState = GAME_CLEAR;
	}

	////テスト用虹色のブロック
	//DrawBox(100, 0, 200, 668, GetColor(255, 0, 0), TRUE);//赤
	//DrawBox(200, 0, 300, 668, GetColor(255, 165, 0), TRUE);//オレンジ
	//DrawBox(300, 0, 400, 668, GetColor(255, 255, 0), TRUE);//黄色
	//DrawBox(400, 0, 500, 668, GetColor(0, 128, 0), TRUE);//緑
	//DrawBox(500, 0, 600, 668, GetColor(0, 255, 254), TRUE);//水色
	//DrawBox(600, 0, 700, 668, GetColor(0, 0, 254), TRUE);//青
	//DrawBox(700, 0, 800, 668, GetColor(128, 0, 128), TRUE);//紫


	return 0;
}
