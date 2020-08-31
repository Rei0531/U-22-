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
extern Object g_Object;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage14Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 20;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 2;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}


	//箱の位置リセット
	g_Object.Init();//オブジェクトの移動量リセット

	gim.shower_C = PURPLE2;			//シャワーの塗りつぶしの色を初期化
	gim.shower_X = 700;				//シャワーの座標

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

	int Lvtxtflg = 0;

}

int Stage14(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage14Init();
	}

	//色ブロック描画_____________________________________________________
	MoveBox(BLUE, 400, 568);
	MoveBox(BLUE, 400, 468);

	MoveBox(YELLOW, 550, 568);
	MoveBox(YELLOW, 550, 468);


	Shower();		//塗りつぶしシャワーの処理

	frontMoveBox(BLUE, 400, 568);
	frontMoveBox(BLUE, 400, 468);

	frontMoveBox(YELLOW, 550, 568);
	frontMoveBox(YELLOW, 550, 468);


	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(2);

	Change(NONCOLOR);
	DrawRotaGraph(400, 100, 1.0, 0, g_pic.LvUPtxt, TRUE);

	//ステージクリアした時、タイトル画面に戻ったとき
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE) {
		InitFlag = TRUE;
		g_Player.InitFlag = FALSE;
	}

	if (g_Player.PLAYER_MENU == TRUE) {
		InitFlag = Menu_Update();
	}

	return 0;
}