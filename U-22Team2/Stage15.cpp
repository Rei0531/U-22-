#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage15Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 20;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 5;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	//レバー******************************************************
	gim.g_LeverX = 880;		//レバーのX座標
	gim.g_LeverY = 638;		//レバーのY座標
	//一個目
	gim.g_L_BoxX1 = 280;		//レバーで反応する箱X/Y座標
	gim.g_L_BoxY1 = 468;
	gim.g_L_BoxX2 = gim.g_L_BoxX1 + 100;
	gim.g_L_BoxY2 = gim.g_L_BoxY1 + 100;
	//二個目
	gim.g_L2_BoxX1 = 380;
	gim.g_L2_BoxY1 = 468;
	gim.g_L2_BoxX2 = gim.g_L2_BoxX1 + 100;
	gim.g_L2_BoxY2 = gim.g_L2_BoxY1 + 100;
	//三個目
	gim.g_L3_BoxX1 = 680;
	gim.g_L3_BoxY1 = 468;
	gim.g_L3_BoxX2 = gim.g_L3_BoxX1 + 100;
	gim.g_L3_BoxY2 = gim.g_L3_BoxY1 + 100;
	//四個目
	gim.g_L4_BoxX1 = 1080;
	gim.g_L4_BoxY1 = 568;
	gim.g_L4_BoxX2 = gim.g_L4_BoxX1 + 100;
	gim.g_L4_BoxY2 = gim.g_L4_BoxY1 + 100;
	//ボックスの色
	gim.OTSBox_Color = RED;
	gim.OTSBox_Color2 = BLUE;
	gim.OTSBox_Color3 = BLUE;
	gim.OTSBox_Color4 = BLUE;
	gim.OTSBox_Color5 = WHITE;

	gim.SwitchFlag = 0;		//レバーのON、OFF
	gim.SwitchColor = 0;		//レバーの色
	//********************************************************

	//動く箱******************************************
	gim.SliObjx1 = 880,
	gim.SliObjx2 = gim.SliObjx1 + 100,
	gim.SliObjy1 = 368,
	gim.SliObjy2 = gim.SliObjy1 + 50,

	gim.GetObjx1 = 0,
	gim.GetObjx2 = gim.GetObjx1 + 0,
	gim.GetObjy1 = 0,
	gim.GetObjy2 = gim.GetObjy1 + 0;

	gim.move_max = 75;//25ごとにひとブロック分(100x座標)

	//SlideColor = RED;//スイッチから―の初期化
	//****************************************************



	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1180;			//扉の左上のx座標
	g_Door.y = 168;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage15(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage15Init();
	}


	//色ブロック描画
	Change(BLUE);
	DrawExtendGraph(980, 568, 1080, 668, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(980, 468, 1080, 568, g_pic.Box[0], TRUE);	//

	Change(RED);
	DrawExtendGraph(980, 368, 1080, 468, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(480, 468, 580, 568, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(480, 368, 580, 468, g_pic.Box[0], TRUE);	//
	DrawExtendGraph(380, 568, 480, 668, g_pic.Box[0], TRUE);	//

	//動く床処理___________________________________________________________________________________________________
	SlideBlock(RED);

	ColorReset();
	Lever();


	//世界の壁（黒いブロック）
	Change(NONCOLOR);
	DrawBox(680, 568, 780, 668, GetColor(255, 255, 255), TRUE);
	DrawBox(480, 568, 580, 668, GetColor(255, 255, 255), TRUE);
	DrawBox(280, 568, 380, 668, GetColor(255, 255, 255), TRUE);
	DrawBox(1180, 368, 1280, 668, GetColor(255, 255, 255), TRUE);

	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(2);

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