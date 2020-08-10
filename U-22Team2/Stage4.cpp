#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ
//オブジェクトの初期位置
static int 
obj1x1 = 400,
obj1x2 = obj1x1 + 100,
obj2x1 = 550,
obj2x2 = obj2x1 + 100,
obj3x1 = 700,
obj3x2 = obj3x1 + 100,
objALLy1 = 568,
objALLy2 = 668;

void Stage4Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = RED;		//プレイヤーの色初期化

	gim.shower_C = BLUE2;			//シャワーの塗りつぶしの色を初期化
	gim.shower_X = 130;				//シャワーの座標


	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	//ドアの位置
	g_Door.x = 1100;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅
}

int Stage4(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage4Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画
	Change(RED);
	DrawExtendGraph(400, 558, 500, 668, g_pic.Box, TRUE);
	DrawExtendGraph(400, 458, 500, 568, g_pic.Box, TRUE);

	Door();			//ステージゴール処理
	Lock();

	Shower();		//塗りつぶしシャワーの処理

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