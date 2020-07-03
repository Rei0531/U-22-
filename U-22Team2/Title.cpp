#include "DxLib.h"
#include "Controller.h"
#include "LoadPic.h"
#include "constant.h"

extern image g_pic;
extern Controller g_Pad;

int GameTitle(void) {
	DrawRotaGraph(SCREEN_WIDHT / 2, SCREEN_HEIGHT / 2, 1.2, 0,g_pic.Title, TRUE, FALSE); //ƒ^ƒCƒgƒ‹‰æ‘œ•`‰æ
	
	if (g_Pad.KEY_B == TRUE) {
		GameState = 4 ;
	}
	return 0;
}