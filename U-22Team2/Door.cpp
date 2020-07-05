#include "Stage_All.h"
#include "Map.h"
#include "Color.h"
#include "Player.h"
#include "LoadPic.h"
#include "Door.h"
#include "Lock.h"

extern Player g_Player;
extern MapCoordinate g_MapC;
extern Player g_Player;
DoorAll g_Door;



int Door(void) {

	DoorRotation();

	Change(g_Door.Rotation[g_MapC.StageNumber - 1][g_Door.RotationNumber % 3]);
	DrawBox(g_Door.x, g_Door.y, g_Door.w, g_Door.h, GetColor(255, 255, 255), TRUE);//青

	if (((g_Door.x < g_Player.x && g_Door.w > g_Player.x - 20) &&
		(g_Door.y < g_Player.y && g_Door.h > g_Player.y))&&
		(g_Player.PLAYER_ACTION == TRUE))
	{
		UnLock();
	}

	return 0;
}

int DoorRotation(void) {		//ドアのローテーションの色変え

	if (g_Door.Picupflg == TRUE) {
		g_Door.RotationNumber += 1;
		g_Door.Picupflg = FALSE;
	}


	return 0;
}
