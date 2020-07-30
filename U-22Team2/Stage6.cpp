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

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数
//オブジェクトの初期位置
static int obj2x1 = 550,
obj2x2 = obj2x1 + 100,
objALLy1 = 568,
objALLy2 = 668;

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

	//ドアの位置
	g_Door.x = 1180;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage6(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage6Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//DrawBox((obj2x1 + 200) + gim.move_x, g_Player.y + 65, (obj2x2 + 200) + gim.move_x, g_Player.y + 75, GetColor(1, 1, 1), TRUE);//デバッグ用
	DrawBox(g_Player.x - 20, g_Player.y + 65, g_Player.x, g_Player.y + 75, GetColor(1, 1, 1), TRUE);//デバッグ用
	Change(BLUE);//色ブロック描画
	DrawExtendGraph(980, 460, 1080, 565, g_pic.Box, TRUE);//障害ブロック
	DrawExtendGraph(980, 565, 1080, 670, g_pic.Box, TRUE);//障害ブロック
	//DrawExtendGraph(g_Player.x - 30, g_Player.y - 30, g_Player.x + 30, g_Player.y + 30, GetColor(255, 255, 255), TRUE);
	Change(RED);//色ブロック描画
	gim.move_x -= gim.Speed;
	gim.move_x -= gim.Speed;
	if (gim.move_cnt++ > gim.move_max - 100) {
		gim.move_cnt = 0;
		gim.Speed = gim.Speed * (-1);
	}
	DrawExtendGraph(380, 565, 480, 670, g_pic.Box, TRUE);//障害ブロック
	DrawExtendGraph(880, 565, 980, 670, g_pic.Box, TRUE);//障害ブロック
	DrawExtendGraph(880, 460, 980, 565, g_pic.Box, TRUE);//障害ブロック
	DrawExtendGraph((obj2x1 + 200) + gim.move_x, objALLy1, (obj2x2 + 200) + gim.move_x, objALLy2, g_pic.Box, TRUE);//動く床
	if (((g_Player.x - 20 >= (obj2x1 + 200) + gim.move_x) && (g_Player.x - 20 <= (obj2x2 + 200) + gim.move_x) &&
		((g_Player.y + 65 <= objALLy1) && (g_Player.y + 75 >= objALLy1))) &&
		((g_Player.Hit_Under == g_Player.NowColor) || (g_Player.Hit_Under2 == g_Player.NowColor))) {
		g_Player.x -= gim.Speed * 2;		//プレイヤーを自動で動かす
	}
	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(2);

	ColorReset();

	if (g_Player.PLAYER_MENU == TRUE) {
		Menu_Draw();
		InitFlag = Menu_Update();
	}

	return 0;
}