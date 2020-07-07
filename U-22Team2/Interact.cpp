#include "Interact.h"
#include "DxLib.h"
#include "Player.h"

extern Player g_Player;

void Interact(int OK) {
	if (OK == TRUE) {		//インタラクト成功
		DrawBox(g_Player.x - 5, g_Player.y - 125, g_Player.x + 5, g_Player.y - 115, GetColor(100, 100, 255), TRUE);
	}
	else {		//インタラクト失敗
		DrawBox(g_Player.x - 25, g_Player.y - 125, g_Player.x - 15, g_Player.y - 115, GetColor(255, 50, 50), TRUE);
	}
}