#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"
#include"Lock.h"
#include"LoadSound.h"



extern Player g_Player;
extern MapCoordinate g_MapC;
extern Controller g_Pad;
LockALL g_Lock;
extern Sound g_Snd;


int Lock(void) {

	//g_Player.PLAYER_ACTION = FALSE;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {

		if (i == 0) {
			Change(g_Lock.color[g_MapC.StageNumber - 1][0]);
			DrawBox(1200, 580, 1230, 600, GetColor(255, 255, 255), TRUE);	//Œ®ŒŠ•`‰æ(‰¼j
			Change(NONCOLOR);
			DrawBox(1200, 580, 1230, 600, GetColor(255, 255, 255), FALSE);	//Œ®ŒŠ•`‰æ(‰¼j˜gü

		}
		else {

			Change(g_Lock.color[g_MapC.StageNumber - 1][i]);
			DrawBox(1165 + i * 10, 580, 1175 + i * 10, 600, GetColor(255, 255, 255), TRUE);	//Œ®ŒŠ•`‰æ(‰¼j
			Change(NONCOLOR);
			DrawBox(1165 + i * 10, 580, 1175 + i * 10, 600, GetColor(255, 255, 255), FALSE);	//Œ®ŒŠ•`‰æ(‰¼j˜gü
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