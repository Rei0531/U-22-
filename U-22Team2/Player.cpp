#include "DxLib.h"
#include "Player.h"
#include "Controller.h"

image g_Play;
extern Controller g_Pad;
int Player(void) {
	/*g_Pad.MouseX = 800;
	g_Pad.MouseX = 1000;*/
	//DrawRotaGraph(640, 600, 2.0, 0, g_Play.Player[0], TRUE);//ネズミ画像の描画
	DrawRotaGraph(g_Pad.MouseX, g_Pad.MouseY, 2.0, 0, g_Play.Player[0], TRUE, FALSE);//ネズミ画像の描画
	return 0;
}