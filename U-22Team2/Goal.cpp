#include "Stage_All.h"
#include "Map.h"
#include "Color.h"
#include "Player.h"
#include "LoadPic.h"

extern Player g_Player;
extern MapCoordinate g_MapC;
extern Player g_Player;

int Goal(void) {

	Change(RED);
	DrawBox(1150, 400, 1250, 668, GetColor(255, 255, 255), TRUE);//��

	if ((1150 < g_Player.x && 1250 > g_Player.x - 20) && (400 < g_Player.y && 668 > g_Player.y)) {
		g_MapC.StageNumber += 1;
		g_Player.x = 110;			//�Q�[���J�n���W
		g_Player.y = 581;			//�Q�[���J�n���W
	}

	return 0;
}