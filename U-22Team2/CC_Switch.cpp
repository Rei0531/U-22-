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
extern GimmickAll gim;

static bool //二度押し防止
B = FALSE;//Bボタン

int CC_Switch(int Color,int x,int y) {

	if (g_Pad.KEY_B == TRUE && B == FALSE &&
		g_Player.x > x && g_Player.x < x+100 && g_Player.y > y-100 && g_Player.y < y+100) {//スイッチが押されたら
		gim.CC_SwitchColor = Color;
		PlaySoundMem(g_Snd.Switch, DX_PLAYTYPE_BACK);
	}

	if (g_Player.PLAYER_RESET == TRUE || g_Player.InitFlag == TRUE || g_Player.PLAYER_RESET == TRUE) {	//Init処理が呼ばれたら色を初期化する
		gim.CC_SwitchColor = 9;
		//DrawRotagGraphでFALSEにしている
		//g_Player.PLAYER_RESET = FALSE;//リセットしたフラグをFALSEにし続ける
	}

	if (g_Lock.clearflg == TRUE || g_Player.PLAYER_RESET == TRUE)gim.CC_SwitchColor = 9;

	Change(gim.CC_SwitchColor);
	DrawExtendGraph(x, y, x+100, y+100, g_pic.C_Switch, TRUE);


	B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

	return gim.CC_SwitchColor;
}