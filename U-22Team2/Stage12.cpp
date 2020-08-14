#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage12Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 1;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする


	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = BLUE;		//プレイヤーの色初期化

	//回復アイテム用_________
	gim.item_x = 520;
	gim.item_y;
	gim.item_flg = 1;

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化




	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1150;				//扉の左上のx座標
	g_Door.y = 670 - 200;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅


}

int Stage12(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage12Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画


	Change(LIGHTBLUE);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box, TRUE);	//1

	Change(LIGHTBLUE);
	DrawExtendGraph(400, 568, 500, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(400, 468, 500, 568, g_pic.Box, TRUE);	//2


	Change(BLUE);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box, TRUE);	//2
	Change(LIGHTBLUE);
	DrawExtendGraph(500, 368, 600, 468, g_pic.Box, TRUE);	//3

	Change(BLUE);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box, TRUE);	//2


	kaihuku(gim.item_x, gim.item_y);

	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(1);

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