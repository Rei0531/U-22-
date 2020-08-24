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

static int SwitchColor = 9;

void Stage20Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 2;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	SwitchColor = 9;//スイッチから―の初期化

	gim.cheobj_flg = 0;			//変形するオブジェクトのフラグ
	gim.cheobj_x = 800;
	gim.cheobj_y = 670 - 225;
	gim.cheobj_c = g_Player.NowColor;
	gim.cheobj_ani = 126;


	gim.g_OTSwitchFlag = 0;		//一度限りのスイッチフラグ初期化

	gim.OTS_X1 = 1135;				//一度限りのスイッチのX/Y軸初期化
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 250;
	gim.OTS_WallY1 = 0;
	gim.OTS_WallX2 = 300;
	gim.OTS_WallY2 = 370;
	gim.OTS_C_WallX1 = 0;			//一度限りのスイッチで表れる壁のX/Y軸
	gim.OTS_C_WallY1 = 0;
	gim.OTS_C_WallX2 = 0;
	gim.OTS_C_WallY2 = 669;


	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 370 - 200;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage20(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage20Init();
	}

	Change(NONCOLOR);
	DrawBox(0, 370, 350, 400, GetColor(255, 255, 255), TRUE);
	Change(RED);
	DrawExtendGraph(0, 270, 100, 370, g_pic.Box[0], TRUE);	//1




	Change(BLUE);
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box[0], TRUE);	//1
	DrawExtendGraph(300, 468, 400, 568, g_pic.Box[0], TRUE);	//2


		//色反映スイッチ_____________________
	SwitchColor = CC_Switch(g_Player.NowColor, 200, 578);//一時変数に関数からの戻り値を格納する
	Change(SwitchColor);
	//色反映する箱________________________________________________

	DrawExtendGraph(500, 568, 600, 668, g_pic.Box[0], TRUE);	//1
	DrawExtendGraph(500, 468, 600, 568, g_pic.Box[0], TRUE);	//2


	//箱の枠線__________________________________________
	ColorReset();
	DrawBox(500, 568, 600, 668, GetColor(1, 1, 1), FALSE);
	DrawBox(500, 468, 600, 568, GetColor(1, 1, 1), FALSE);

	Change(YELLOW);
	DrawExtendGraph(400, 568, 500, 668, g_pic.Box[0], TRUE);

	ChangeBlock();


	Change(NONCOLOR);
	DrawBox(1280 - 250, 370, 1280, 400, GetColor(255, 255, 255), TRUE);


	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(3);


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