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

int Map(void) {			//�}�b�v�摜�̕`��___________________________________________________________________________________________________________________

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��


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
	case 26:
		Stage26();
		break;
	case 27:
		Stage27();
		break;
	case 28:
		Stage28();
		break;
	case 29:
		Stage29();
		break;
	case 30:
		Stage30();
		break;
	default:
		break;
	}

	//�c��񐔂̕\��
	for (int i = 0; i < 6; i++) {
		DrawRotaGraph(20 +i*28, 20, 0.2, 0, g_pic.Nokori[i], TRUE, FALSE);
	}
	Change(g_Player.Interact%7);
	DrawRotaGraph(200, 20, 0.2, 0, g_pic.Nokori_Num[g_Player.Interact / 10 % 10], TRUE, FALSE);
	DrawRotaGraph(230, 20, 0.2, 0, g_pic.Nokori_Num[g_Player.Interact % 10], TRUE, FALSE);
	ColorReset();


	if ((g_Lock.clearflg == TRUE) & (g_Pad.KEY_B == FALSE)) {
		GameState = GAME_CLEAR;
	}

	////�e�X�g�p���F�̃u���b�N
	//DrawBox(100, 0, 200, 668, GetColor(255, 0, 0), TRUE);//��
	//DrawBox(200, 0, 300, 668, GetColor(255, 165, 0), TRUE);//�I�����W
	//DrawBox(300, 0, 400, 668, GetColor(255, 255, 0), TRUE);//���F
	//DrawBox(400, 0, 500, 668, GetColor(0, 128, 0), TRUE);//��
	//DrawBox(500, 0, 600, 668, GetColor(0, 255, 254), TRUE);//���F
	//DrawBox(600, 0, 700, 668, GetColor(0, 0, 254), TRUE);//��
	//DrawBox(700, 0, 800, 668, GetColor(128, 0, 128), TRUE);//��


	return 0;
}
