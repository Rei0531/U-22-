#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ


void Stage3Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 6;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//箱の位置リセット
	g_Object.Init();//オブジェクトの移動量リセット

	//ドアの位置
	g_Door.x = 1100;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage3(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる,または、Yボタンを押されたとき初期化できる
		Stage3Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画

	//色ブロック描画_____________________________________________________
	MoveBox(ORENGE,400,568);
	MoveBox(ORENGE, 400, 468);

	MoveBox(YELLOW, 550, 568);
	MoveBox(YELLOW, 550, 468);

	MoveBox(PURPLE, 700, 568);
	MoveBox(PURPLE, 700, 468);
	//プレイヤーの色と同じブロックを手前に出す_______________________________________________________________
	frontMoveBox(ORENGE, 400, 568);
	frontMoveBox(ORENGE, 400, 468);

	frontMoveBox(YELLOW, 550, 568);
	frontMoveBox(YELLOW, 550, 468);

	frontMoveBox(PURPLE, 700, 568);
	frontMoveBox(PURPLE, 700, 468);

	Door();			//ステージゴール処理
	Lock();


	//ドアローテーション_________________________________________________________
	DoorRotationBox(3);

	ColorReset();

	if (g_Lock.clearflg == TRUE)InitFlag = TRUE;

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	return 0;
}