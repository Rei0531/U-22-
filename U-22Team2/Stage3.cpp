#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Menu.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ
//オブジェクトの初期位置
static int obj1x1 = 400,
obj1x2 = obj1x1 + 150,
obj2x1 = 550,
obj2x2 = obj2x1 + 150,
obj3x1 = 700,
obj3x2 = obj3x1 + 150,
objALLy1 = 518,
objALLy2 = 668;

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
	obj1x1 = 400;
	obj1x2 = obj1x1 + 100;
	obj2x1 = 550;
	obj2x2 = obj2x1 + 100;
	obj3x1 = 700;
	obj3x2 = obj3x1 + 100;
	objALLy1 = 568;
	objALLy2 = 668;
	g_Object.Init();//オブジェクトの移動量リセット
}

int Stage3(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる,または、Yボタンを押されたとき初期化できる
		Stage3Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画
	Change(ORENGE);
	DrawExtendGraph(obj1x1 + g_Object.ORENGE_x, objALLy1, obj1x2 + g_Object.ORENGE_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj1x1 + g_Object.ORENGE_x, objALLy1 - 100, obj1x2 + g_Object.ORENGE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
	Change(YELLOW);
	DrawExtendGraph(obj2x1 + g_Object.YELLOW_x, objALLy1, obj2x2 + g_Object.YELLOW_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj2x1 + g_Object.YELLOW_x, objALLy1 - 100, obj2x2 + g_Object.YELLOW_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
	Change(PURPLE);
	DrawExtendGraph(obj3x1 + g_Object.PURPLE_x, objALLy1, obj3x2 + g_Object.PURPLE_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj3x1 + g_Object.PURPLE_x, objALLy1 - 100, obj3x2 + g_Object.PURPLE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
	Door();			//ステージゴール処理
	Lock();

	//プレイヤーの色と同じブロックを手前に出す_______________________________________________________________
	switch (g_Player.NowColor) {
	case ORENGE:
		Change(ORENGE);
		DrawExtendGraph(obj1x1 + g_Object.ORENGE_x, objALLy1, obj1x2 + g_Object.ORENGE_x, objALLy2, g_pic.Box_Move, TRUE);
		DrawExtendGraph(obj1x1 + g_Object.ORENGE_x, objALLy1 - 100, obj1x2 + g_Object.ORENGE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
		break;
	case YELLOW:
		Change(YELLOW);
		DrawExtendGraph(obj2x1 + g_Object.YELLOW_x, objALLy1, obj2x2 + g_Object.YELLOW_x, objALLy2, g_pic.Box_Move, TRUE);
		DrawExtendGraph(obj2x1 + g_Object.YELLOW_x, objALLy1 - 100, obj2x2 + g_Object.YELLOW_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
		break;
	case PURPLE:
		Change(PURPLE);
		DrawExtendGraph(obj3x1 + g_Object.PURPLE_x, objALLy1, obj3x2 + g_Object.PURPLE_x, objALLy2, g_pic.Box_Move, TRUE);
		DrawExtendGraph(obj3x1 + g_Object.PURPLE_x, objALLy1 - 100, obj3x2 + g_Object.PURPLE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
		break;

	}


	//ドアローテーション_________________________________________________________
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	DrawBox(1150, 370, 1250, 400, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
	DrawBox(1186, 370, 1250, 400, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
	DrawBox(1216, 370, 1250, 400, GetColor(255, 255, 255), TRUE);

	ColorReset();

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}
	return 0;
}