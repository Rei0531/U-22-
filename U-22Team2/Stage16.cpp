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


void Stage16Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 20;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 3;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1180;				//扉の左上のx座標
	g_Door.y = 168;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

	gim.CC_SwitchColor = 9;//スイッチから―の初期化

}

int Stage16(void) {			//マップ画像の描画


	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage16Init();
	}

	//色ブロック描画
	Change(BLUE);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(300, 468, 400, 568, g_pic.Box[0], TRUE);
	Change(GREEN);
	DrawExtendGraph(500, 568, 600, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box[0], TRUE);
	Change(YELLOW);
	DrawExtendGraph(700, 568, 800, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(700, 468, 800, 568, g_pic.Box[0], TRUE);

	//変色箱描画________________________________
	Change(Rotation_Box(2));
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box[2], TRUE);

	//色反映スイッチ____________________________				
	gim.CC_SwitchColor = CC_Switch(g_Player.NowColor, 140, 578);//一時変数に関数からの戻り値を格納する
	Change(gim.CC_SwitchColor);
	//色反映する箱________________________________________________
	DrawExtendGraph(1000, 568, 1100, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(1000, 468, 1100, 568, g_pic.Box[0], TRUE);
	//箱の枠線__________________________________________
	ColorReset();
	DrawBox(1000, 568, 1100, 668, GetColor(3, 3, 3), FALSE);
	DrawBox(1000, 468, 1100, 568, GetColor(3, 3, 3), FALSE);

	//世界の壁_______________________
	DrawBox(1130, 368, 1280, 418, GetColor(0, 0, 0), TRUE);


	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(3);


	//ステージクリアした時、タイトル画面に戻ったとき
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE) {
		InitFlag = TRUE;
		g_Player.InitFlag = FALSE;
	}

	if (g_Player.PLAYER_MENU == TRUE) {
		InitFlag = Menu_Update();
	}

	return 0;
}