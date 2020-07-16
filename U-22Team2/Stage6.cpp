#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数
//オブジェクトの初期位置
static int obj2x1 = 550,
obj2x2 = obj2x1 + 100,
objALLy1 = 568,
objALLy2 = 668;

static int Speed = 10;

void Stage6Init() {
	//移動方向のフラグ
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = BLUE;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	obj2x1 = 550,
	obj2x2 = obj2x1 + 150,
	objALLy1 = 518,
	objALLy2 = 668;

}

int Stage6(void) {			//マップ画像の描画

	if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//InitフラグがTRUEの時に初期化できる,または、Yボタンを押されたとき初期化できる
		Stage6Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画
	Change(RED);
	objALLy1 -= Speed;
	objALLy2 -= Speed;
	if ((objALLy1 <= 318) || (objALLy2 >= 668)) {
		Speed = Speed * (-1);
	}
	DrawExtendGraph(obj2x1, objALLy1, obj2x2, objALLy2, g_pic.Box, TRUE);
	Change(BLUE);
	DrawExtendGraph(550, 518, 700, 668, g_pic.Box, TRUE);
	Door();			//ステージゴール処理
	Lock();

	Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	DrawBox(1150, 370, 1250, 400, GetColor(255, 255, 255), TRUE);
	Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
	DrawBox(1186, 370, 1250, 400, GetColor(255, 255, 255), TRUE);

	ColorReset();

	return 0;
}