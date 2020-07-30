#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;

static int PushColor = 9;//押された色を引数から格納する変数

int CC_Switch(int Color,int x,int y) {

	if (g_Pad.KEY_B == TRUE &&
		g_Player.x > x && g_Player.x < x+100 && g_Player.y > y-100 && g_Player.y < y+100) {
		PushColor = Color;
	}

	if (g_Player.PLAYER_RESET == TRUE) {	//Init処理が呼ばれたら色を初期化する
		PushColor = 9;
		g_Player.PLAYER_RESET = FALSE;//リセットしたフラグをFALSEにし続ける
	}

	Change(PushColor);
	DrawExtendGraph(x, y, x+100, y+100, g_pic.C_Switch, TRUE);

	return PushColor;
}