#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "LoadSound.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"
#include "Lever.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern Sound g_Snd;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ


void Stage5Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 0;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.g_LeverX = 500;		//レバーのX座標
	gim.g_LeverY = 633;		//レバーのY座標
	
	gim.g_L_BoxX1 = 700;		//レバーで反応する箱X/Y座標
	gim.g_L_BoxY1 = 558;
	gim.g_L_BoxX2 = 800;
	gim.g_L_BoxY2 = 668;
	gim.g_L2_BoxX1 = 0;
	gim.g_L2_BoxY1 = 0;
	gim.g_L2_BoxX2 = 0;
	gim.g_L2_BoxY2 = 0;
	gim.g_L3_BoxX1 = 0;
	gim.g_L3_BoxY1 = 0;
	gim.g_L3_BoxX2 = 0;
	gim.g_L3_BoxY2 = 0;
	

	gim.SwitchFlag = 0;		//レバーのON、OFF
	gim.SwitchColor = 0;		//レバーの色

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅


}

int Stage5(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage5Init();
	}

	//色ブロック描画

	DrawExtendGraph(700, 558, 800, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(700, 458, 800, 568, g_pic.Box[0], TRUE);

	//DrawFormatString(0, 400, 0x000000, "g_SwitchFlag = %d", g_SwitchFlag);
	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(1);

	ColorReset();

	Lever();


	//ステージクリアした時、タイトル画面に戻ったとき
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE) {
		InitFlag = TRUE;
		g_Player.InitFlag = FALSE;
	}

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	return 0;
}