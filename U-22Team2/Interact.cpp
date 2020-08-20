#include "Interact.h"
#include "DxLib.h"
#include "Player.h"
#include "LoadSound.h"

extern Player g_Player;
extern Sound g_Snd;

void Interact(int OK) {
	if (OK == TRUE) {		//インタラクト成功
		g_Player.Interact--;
		PlaySoundMem(g_Snd.Suc,DX_PLAYTYPE_BACK);
	}
	else {		//インタラクト失敗
		PlaySoundMem(g_Snd.Mis, DX_PLAYTYPE_BACK);
	}
}