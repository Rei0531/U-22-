#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Gimmick.h"
#include "Warp.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

int Warpy = 50;

void Stage22Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 20;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 6;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ワープ***********************************************
	gim.SetNum = 2;//ワープの対の数
	//*****************************************************

	//シャワー***********************************************
	gim.shower_C = LIGHTBLUE2;			//シャワーの塗りつぶしの色を初期化
	gim.shower_X = 1000;				//シャワーの座標
	//*****************************************************

	//レバー***********************************************
	gim.g_LeverX = 1180;		//レバーのX座標
	gim.g_LeverY = 340;		//レバーのY座標

	gim.g_L_BoxX1 = 780;		//レバーで反応する箱X/Y座標
	gim.g_L_BoxY1 = 569;
	gim.g_L_BoxX2 = gim.g_L_BoxX1 + 100;
	gim.g_L_BoxY2 = gim.g_L_BoxY1 + 100;
	gim.SwitchFlag = 1;		//レバーのON、OFF
	gim.SwitchColor = 6;		//レバーの色
	//*****************************************************


	//ドアの位置
	g_Door.x = 50;				//扉の左上のx座標
	g_Door.y = 170;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage22(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage22Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画

	Warp(gim.SetNum, 200, 175, 200, 175);

	Lever();

	Shower();		//塗りつぶしシャワーの処理

	//色ブロック描画
	Change(GREEN);
	DrawExtendGraph(400, 569, 500, 669, g_pic.Box, TRUE);
	DrawExtendGraph(400, 468, 500, 568, g_pic.Box, TRUE);
	DrawExtendGraph(400, 368, 500, 468, g_pic.Box, TRUE);

	//レバー用_________________________________________________
	Change(PURPLE);
	DrawExtendGraph(680, 569, 780, 669, g_pic.Box, TRUE);
	DrawExtendGraph(780, 569, 880, 669, g_pic.Box, TRUE);
	DrawExtendGraph(780, 468, 880, 568, g_pic.Box, TRUE);


	//世界の壁_________________________________________
	Change(NONCOLOR);
	DrawBox(0, 370, 400, 420, GetColor(255, 255, 255), TRUE);
	DrawBox(880, 370, 1280, 420, GetColor(255, 255, 255), TRUE);


	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(3);

	ColorReset();

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