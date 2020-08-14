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

void Stage18Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 1;//プレイヤーがインタラクトできる回数を2回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 0;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.cheobj_flg = 1;			//変形するオブジェクトのフラグ
	gim.cheobj_zeroflg = 1;
	gim.cheobj_x = 650;
	gim.cheobj_c = g_Player.NowColor;
	gim.cheobj_ani = 158;

	//回復アイテム用_________
	gim.item_x = 300 + 10;
	gim.item_y;
	gim.item_flg = 1;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage18(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage18Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画

	Change(BLUE);
	DrawExtendGraph(200, 568, 300, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(200, 468, 300, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(200, 368, 300, 468, g_pic.Box, TRUE);	//3

	Change(RED);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box, TRUE);	//1


	Change(RED);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box, TRUE);	//1
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box, TRUE);	//2	
	Change(BLUE);
	DrawExtendGraph(900, 368, 1000, 468, g_pic.Box, TRUE);	//3	
	DrawExtendGraph(900, 268, 1000, 368, g_pic.Box, TRUE);	//4
	DrawExtendGraph(900, 168, 1000, 268, g_pic.Box, TRUE);	//5


	ChangeBlock();	//変形するオブジェクトの関数
	kaihuku(gim.item_x, gim.item_y);		//回復アイテム

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