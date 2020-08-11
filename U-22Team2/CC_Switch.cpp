#include "Gimmick.h"
#include "LoadPic.h"
#include "Color.h"
#include "Controller.h"
#include "Player.h"
#include "LoadSound.h"
#include"Lock.h"

extern Controller g_Pad;
extern image g_pic;
extern Player g_Player;
extern Sound g_Snd;
extern LockALL g_Lock;

int PushColor = 9;//押された色を引数から格納する変数

static bool //二度押し防止
B = FALSE;//Bボタン

int CC_Switch(int Color,int x,int y) {

	if (g_Pad.KEY_B == TRUE && B == FALSE &&
		g_Player.x > x && g_Player.x < x+100 && g_Player.y > y-100 && g_Player.y < y+100) {//スイッチが押されたら
		PushColor = Color;
		PlaySoundMem(g_Snd.Switch, DX_PLAYTYPE_BACK);
	}

	if (g_Player.PLAYER_RESET == TRUE) {	//Init処理が呼ばれたら色を初期化する
		PushColor = 9;
		//DrawRotagGraphでFALSEにしている
		//g_Player.PLAYER_RESET = FALSE;//リセットしたフラグをFALSEにし続ける
	}

	if (g_Lock.clearflg == TRUE)PushColor = 9;

	Change(PushColor);
	DrawExtendGraph(x, y, x+100, y+100, g_pic.C_Switch, TRUE);


	B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

	return PushColor;
}