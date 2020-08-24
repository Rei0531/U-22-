#include "Stage_All.h"
#include "Map.h"
#include "Color.h"
#include "Player.h"
#include "LoadPic.h"
#include "Lock.h"
#include "Controller.h"
#include"Lock.h"

extern Player g_Player;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern Controller g_Pad;
extern LockALL g_Lock;

static bool
B = TRUE;//Bボタン

int Goal(void) {

	ControllerVlue();

	DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.4, 0, g_pic.StageClear, TRUE, FALSE); //タイトル画像描画

	if (g_MapC.StageNumber >= 25) {
		if (g_Pad.KEY_B == TRUE && B == FALSE) {
			g_MapC.StageNumber = 1;
			GameState = GAME_TITLE;
			g_Lock.clearflg = FALSE;
		}
	}
	else {
		if (g_Pad.KEY_B == TRUE && B == FALSE) {
			g_MapC.StageNumber += 1;
			GameState = GAME_MAIN;
			g_Lock.clearflg = FALSE;
		}
	}

	B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように


	return 0;

}