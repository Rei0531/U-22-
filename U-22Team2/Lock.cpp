#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"
#include"Lock.h"
#include"LoadSound.h"
#include "Door.h"



extern Player g_Player;
extern MapCoordinate g_MapC;
extern Controller g_Pad;
LockALL g_Lock;
extern Sound g_Snd;
extern DoorAll g_Door;
extern image g_pic;

static bool B = FALSE;//Bƒ{ƒ^ƒ“


int Lock(void) {

	//g_Player.PLAYER_ACTION = FALSE;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {

		if (i == 0) {
			Change2(g_Lock.color[g_MapC.StageNumber - 1][0]);
			DrawExtendGraph(g_Door.x, g_Door.y + 100, g_Door.x + 100, g_Door.y + 150,g_pic.Door_Nobu,TRUE);
			//DrawBox(g_Door.x+50, g_Door.y+140, g_Door.x + 75, g_Door.y + 170, GetColor(255, 255, 255), TRUE);	//Œ®ŒŠ•`‰æ(‰¼j
			//Change(NONCOLOR);
			//ColorReset();
			//DrawBox(g_Door.x + 50, g_Door.y + 140, g_Door.x + 75, g_Door.y + 170, GetColor(1,1,1), FALSE);	//Œ®ŒŠ•`‰æ(‰¼j˜gü

		}
		else {

			Change2(g_Lock.color[g_MapC.StageNumber - 1][i]);
			DrawExtendGraph(g_Door.x + 15 + i * 20, g_Door.y + 105, g_Door.x + 35 + i * 20, g_Door.y + 145,g_pic.Door_keyhole,TRUE);
			//DrawBox(g_Door.x +15 + i * 10, g_Door.y + 140, g_Door.x + 25 + i * 10, g_Door.y + 170, GetColor(255, 255, 255), TRUE);	//Œ®ŒŠ•`‰æ(‰¼j
			//Change(NONCOLOR);
			//ColorReset();
			//DrawBox(g_Door.x + 15 + i * 10, g_Door.y + 140, g_Door.x + 25 + i * 10, g_Door.y + 170, GetColor(1, 1, 1), FALSE);	//Œ®ŒŠ•`‰æ(‰¼j˜gü
		}
	}

	return 0;
}


int UnLock(void) {
	static bool Key_Open = TRUE;
	
	int pa = g_Lock.Release;


	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {

		if (i == 0) {

			if ((g_Lock.n[g_MapC.StageNumber - 1] - 1 == g_Lock.Release) & (g_Lock.color[g_MapC.StageNumber - 1][i] == g_Player.NowColor)) {//ƒmƒu‚Ì‰ğœˆ—
				g_Lock.color[g_MapC.StageNumber - 1][i] = 8;
				g_Lock.clearflg = TRUE;
				g_Lock.Release += 1;
				PlaySoundMem(g_Snd.Key_Success, DX_PLAYTYPE_BACK);
			}
		}
		else if (g_Lock.color[g_MapC.StageNumber - 1][i] == g_Player.NowColor) {		//Œ®ŒŠ‰ğœˆ—

			g_Lock.color[g_MapC.StageNumber - 1][i] = 8;
			g_Lock.Release += 1;
		
			PlaySoundMem(g_Snd.Key_Success, DX_PLAYTYPE_BACK);
		}
	}

	if (pa == g_Lock.Release) {
		
		PlaySoundMem(g_Snd.Key_Miss, DX_PLAYTYPE_BACK);


	}

	return 0;
}