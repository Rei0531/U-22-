#include "DxLib.h"
#include "Player.h"
#include "Controller.h"

extern image g_pic;
extern Controller g_Pad;

int Player(void) {
	DrawRotaGraph(640, 645, 1.0, 0, g_pic.Player[0], TRUE, FALSE);//ƒlƒYƒ~‰æ‘œ‚Ì•`‰æ
	return 0;
}