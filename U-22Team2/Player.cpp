#include "DxLib.h"
#include "Player.h"

image g_Play;

int Player(void) {
	DrawRotaGraph(0, 100, 1.0, 0, g_Play.Player[0], TRUE, FALSE);//ネズミ画像の描画
	return 0;
}