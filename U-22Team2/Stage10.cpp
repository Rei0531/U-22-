#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"
#include "OneTime_Switch.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"

extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage10Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 4;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.g_OTSwitchFlag = 0;		//一度限りのスイッチフラグ初期化

	gim.OTS_X1 = 800;				//一度限りのスイッチのX/Y軸初期化
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 900;
	gim.OTS_WallY1 = 300;
	gim.OTS_WallX2 = 1000;
	gim.OTS_WallY2 = 669;
	gim.OTS_C_WallX1 = 0;			//一度限りのスイッチで表れる壁のX/Y軸
	gim.OTS_C_WallY1 = 0;
	gim.OTS_C_WallX2 = 0;
	gim.OTS_C_WallY2 = 669;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage10(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage10Init();
	}

	//色ブロック描画
	Change(BLUE);
	DrawExtendGraph(400, 568, 500, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(400, 468, 500, 568, g_pic.Box[0], TRUE);
	Change(RED);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box[0], TRUE);
	Change(LIGHTBLUE);
	DrawExtendGraph(600, 568, 700, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(600, 468, 700, 568, g_pic.Box[0], TRUE);

	//ギミック説明描画
	DrawRotaGraph(1024, 74, 1.0, 0, g_pic.All_text[5], TRUE, FALSE);

	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(1);

	OneTimeSwitch();

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