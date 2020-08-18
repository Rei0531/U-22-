#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Gimmick.h"
#include "OneTime_Switch.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static int SwitchColor = 9;
static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage23Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 5;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 0;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 100;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

	SwitchColor = 9;//白色で初期化

	gim.g_OTSwitchFlag = 0;		//一度限りのスイッチフラグ初期化

	gim.OTS_X1 = 800;				//一度限りのスイッチのX/Y軸初期化
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 900;
	gim.OTS_WallY1 = 300;
	gim.OTS_WallX2 = 1000;
	gim.OTS_WallY2 = 669;
	gim.OTS_C_WallX1 = 0;			//一度限りのスイッチで表れる壁のX/Y軸
	gim.OTS_C_WallY1 = 0;
	gim.OTS_C_WallX2 = 0;
	gim.OTS_C_WallY2 = 0;
	//gim.OTS_C_WallX1 = 440;			//一度限りのスイッチで表れる壁のX/Y軸
	//gim.OTS_C_WallY1 = 569;
	//gim.OTS_C_WallX2 = 550;
	//gim.OTS_C_WallY2 = 669;

	//回復アイテム用_
	gim.item_x = 200;   //横の座標
	gim.item_y = 300;   //縦の座標
	gim.item_flg = 1;   //アイテムを取ったか取ってないかのフラグのフラグ

}

int Stage23(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage23Init();
	}

	Change(NONCOLOR);
	DrawBox(0,300,300,325,GetColor(255,255,255),TRUE);
	DrawBox(1000,300,1300,325,GetColor(255,255,255),TRUE);
	Change(RED);
	DrawExtendGraph(340, 568, 440, 668, g_pic.Box[0], TRUE);
	Change(BLUE);
	DrawExtendGraph(640, 568, 740, 668, g_pic.Box[0], TRUE);
	//色反映スイッチ_
	SwitchColor = CC_Switch(g_Player.NowColor, 140, 593);//一時変数に関数からの戻り値を格納する
	Change(SwitchColor);
	//色反映する箱__
	DrawExtendGraph(540, 268, 640, 368, g_pic.Box[0], TRUE);
	ColorReset();
	DrawBox(540, 268, 640, 368, GetColor(1, 1, 1), FALSE);
	
	ColorReset();
	OneTimeSwitch();
	
	kaihuku(gim.item_x, gim.item_y);  //(x座標、y座標）

	ColorReset();
	Warp(50, 200, 1040, 568);


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