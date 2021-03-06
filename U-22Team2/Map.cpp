#include "DxLib.h"
#include "Map.h"
#include "Controller.h"
#include "Stage_All.h"
#include "Lock.h"
#include"Player.h"
#include "Menu.h"
#include "LoadSound.h"

extern MapCoordinate g_MapC;
extern Controller g_Pad;
MapCoordinate g_MapC;
image g_pic;
extern Controller g_Pad;
extern LockALL g_Lock;
extern Player g_Player;
extern Sound g_Snd;

int Map(void) {			//マップ画像の描画___________________________________________________________________________________________________________________

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画

	if (g_Lock.clearflg == FALSE) {
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
		case 17:
			Stage17();
			break;
		case 18:
			Stage18();
			break;
		case 19:
			Stage19();
			break;
		case 20:
			Stage20();
			break;
		case 21:
			Stage21();
			break;
		case 22:
			Stage22();
			break;
		case 23:
			Stage23();
			break;
		case 24:
			Stage24();
			break;
		case 25:
			Stage25();
			break;
			//case 26:
			//	Stage26();
			//	break;
			//case 27:
			//	Stage27();
			//	break;
			//case 28:
			//	Stage28();
			//	break;
			//case 29:
			//	Stage29();
			//	break;
			//case 30:
			//	Stage30();
			//	break;
		default:
			break;
		}
		if (g_Lock.clearflg == TRUE) {
			GameState = GAME_CLEAR;
		}


		//残り回数の表示*****************************************************
		static int ColorMove = 0;//スポイトするたび色が変わる変数

		if (g_Player.PLAYER_PICKUP == TRUE)ColorMove++;
		Change(WHITE);
		DrawRotaGraph(25,720,1.3,0,g_pic.Pin2,TRUE,FALSE);
		//残り回数の表示
		for (int i = 0; i < 6; i++) {
			Change((i + ColorMove) % 7);//スポイトするたびに色が変わる
			DrawRotaGraph(75 + i * 45, 720, 0.3, 0, g_pic.Nokori[i], TRUE, FALSE);
		}
		//残り回数の数字
		Change(g_Player.Interact % 7);
		DrawRotaGraph(360, 720, 0.3, 0, g_pic.Nokori_Num[g_Player.Interact / 10 % 10], TRUE, FALSE);
		DrawRotaGraph(405, 720, 0.3, 0, g_pic.Nokori_Num[g_Player.Interact % 10], TRUE, FALSE);
		ColorReset();
		//**********************************************
		//現在のステージ表示***********************************************************
		DrawRotaGraph(1050, 720, 0.2, 0, g_pic.Stage, TRUE, FALSE);//現在のステージ表示
		DrawRotaGraph(1210, 720, 0.3, 0, g_pic.Nokori_Num[g_MapC.StageNumber / 10 % 10], TRUE, FALSE);
		DrawRotaGraph(1250, 720, 0.3, 0, g_pic.Nokori_Num[g_MapC.StageNumber % 10], TRUE, FALSE);
		//**********************************************************************
	}
	if (g_Player.InitFlag == TRUE || g_Player.PLAYER_RESET == TRUE) {
		StopSoundMem(g_Snd.Shower);
		StopSoundMem(g_Snd.ChangeBlockPlay);
	}


	return 0;

}
