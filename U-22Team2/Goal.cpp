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

int Goal(void) {

	DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.4, 0, g_pic.StageClear, TRUE, FALSE); //ƒ^ƒCƒgƒ‹‰æ‘œ•`‰æ

	if (g_Player.PLAYER_ACTION == TRUE) {
		g_MapC.StageNumber += 1;
		g_Lock.clearflg = FALSE;
	}

	return 0;
}