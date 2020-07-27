#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage14Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = RED;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.cheobj_flg = 1;			//変形するオブジェクトのフラグ
	gim.cheobj_x = 800 - 225;
	gim.cheobj_c = g_Player.NowColor;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}


}

int Stage14(void) {			//マップ画像の描画

	if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//InitフラグがTRUEの時に初期化できる,または、Yボタンを押されたとき初期化できる
		Stage14Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画

	Change(YELLOW);
	DrawExtendGraph(200, 568, 300, 668, g_pic.Box, TRUE);	//3
	DrawExtendGraph(200, 468, 300, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(200, 368, 300, 468, g_pic.Box, TRUE);	//1

	Change(YELLOW);
	DrawExtendGraph(800, 568, 900, 668, g_pic.Box, TRUE);	//3
	DrawExtendGraph(800, 468, 900, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(800, 368, 900, 468, g_pic.Box, TRUE);	//1

	Change(RED);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box, TRUE);	//3
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box, TRUE);	//2
	DrawExtendGraph(900, 368, 1000, 468, g_pic.Box, TRUE);	//2


	ChangeBlock();	//変形するオブジェクトの関数

	Door();			//ステージゴール処理
	Lock();

	Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	DrawBox(1150, 370, 1250, 400, GetColor(255, 255, 255), TRUE);



	ColorReset();



	return 0;
}