#include "Interact.h"
#include "DxLib.h"
#include "Player.h"
#include "LoadSound.h"

extern Player g_Player;
extern Sound g_Snd;

void Interact(int OK) {
	if (OK == TRUE) {		//インタラクト成功
		g_Player.Interact--;
		DrawBox(g_Player.x - 5, g_Player.y - 125, g_Player.x + 5, g_Player.y - 115, GetColor(100, 100, 255), TRUE);
		PlaySoundMem(g_Snd.Suc,DX_PLAYTYPE_BACK);
	}
	else {		//インタラクト失敗
		DrawBox(g_Player.x - 25, g_Player.y - 125, g_Player.x - 15, g_Player.y - 115, GetColor(255, 50, 50), TRUE);
		PlaySoundMem(g_Snd.Mis, DX_PLAYTYPE_BACK);
	}
}