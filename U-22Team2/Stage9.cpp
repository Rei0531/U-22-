#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Menu.h"
#include "Warp.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Controller g_Pad;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数
//オブジェクトの初期位置
static int obj2x1 = 550,
obj2x2 = obj2x1 + 100,
objALLy1 = 568,
objALLy2 = 668;

void Stage9Init() {
	//移動方向のフラグ
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = YELLOW;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	obj2x1 = 550,
		obj2x2 = obj2x1 + 150,
		objALLy1 = 518,
		objALLy2 = 668;

	gim.move_cnt = 0;
	gim.move_max = 160;

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅
}

int Stage9(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage9Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	Change(NONCOLOR);
	DrawBox(0, 268, 1300, 368, GetColor(255, 255, 255), TRUE);
	ColorReset();
	DrawExtendGraph(168, 168, 268, 268, g_pic.Warp_Area, TRUE);//ワープ用画像
	DrawExtendGraph(368, 568, 468, 668, g_pic.Warp_Area, TRUE);//ワープ用画像
	DrawExtendGraph(868, 168, 968, 268, g_pic.Warp_Area, TRUE);//ワープ用画像

	Change(RED);
	/*DrawExtendGraph(150, 568, 250, 668, g_pic.Box, TRUE);
	DrawExtendGraph(150, 468, 250, 568, g_pic.Box, TRUE);*/
	DrawExtendGraph(500, 68, 600, 168, g_pic.Box, TRUE);
	DrawExtendGraph(500, 168, 600, 268, g_pic.Box, TRUE);

	Change(BLUE);
	DrawExtendGraph(700, 68, 800, 168, g_pic.Box, TRUE);
	DrawExtendGraph(700, 168, 800, 268, g_pic.Box, TRUE);
	/*DrawExtendGraph(500, 468, 600, 568, g_pic.Box, TRUE);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box, TRUE);*/

	Change(LIGHTBLUE);
	DrawExtendGraph(300, 68, 400, 168, g_pic.Box, TRUE);
	DrawExtendGraph(300, 168, 400, 268, g_pic.Box, TRUE);

	Warp();

	//DrawFormatString(g_Player.x - 30, g_Player.y - 200, g_Player.NowColor, "%d", gim.move_cnt);

	DoorRotationBox(3);

	Door();			//ステージゴール処理
	Lock();

	ColorReset();

	if (g_Lock.clearflg == TRUE)InitFlag = TRUE;

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}

	return 0;
}