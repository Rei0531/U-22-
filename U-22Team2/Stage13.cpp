#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"
#include "Menu.h"
#include "Draw_Door_Rotation.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage13Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 0;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.cheobj_flg = 1;			//変形するオブジェクトのフラグ
	gim.cheobj_x = 800 - 225;
	gim.cheobj_y = 670 - 225;
	gim.cheobj_c = g_Player.NowColor;
	gim.cheobj_ani = 158;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1150;				//扉の左上のx座標
	g_Door.y = 670 - 200;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅


}

int Stage13(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage13Init();
	}

	//色ブロック描画

	Change(YELLOW);
	DrawExtendGraph(200, 568, 300, 668, g_pic.Box[0], TRUE);	//3
	DrawExtendGraph(200, 468, 300, 568, g_pic.Box[0], TRUE);	//2
	DrawExtendGraph(200, 368, 300, 468, g_pic.Box[0], TRUE);	//1

	Change(YELLOW);
	DrawExtendGraph(800, 568, 900, 668, g_pic.Box[0], TRUE);	//3
	DrawExtendGraph(800, 468, 900, 568, g_pic.Box[0], TRUE);	//2
	DrawExtendGraph(800, 368, 900, 468, g_pic.Box[0], TRUE);	//1

	Change(RED);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box[0], TRUE);	//3
	DrawExtendGraph(900, 468, 1000, 568, g_pic.Box[0], TRUE);	//2
	DrawExtendGraph(900, 368, 1000, 468, g_pic.Box[0], TRUE);	//2


	ChangeBlock();	//変形するオブジェクトの関数

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