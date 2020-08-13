#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include "Warp.h"
#include "Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;
extern Object g_Object;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage28Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 3;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 0;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ワープ***********************************************
	gim.SetNum = 2;//ワープの対の数
	//*****************************************************

	//インスタントスイッチ***********************************************
	gim.g_OTSwitchFlag = 0;		//一度限りのスイッチフラグ初期化

	gim.OTS_X1 = 1200;				//一度限りのスイッチのX/Y軸初期化
	gim.OTS_Y1 = 618;
	gim.OTS_X2 = gim.OTS_X1 + 50;
	gim.OTS_Y2 = gim.OTS_Y1 + 50;
	gim.OTS_WallX1 = 0;
	gim.OTS_WallY1 = 0;
	gim.OTS_WallX2 = 0;
	gim.OTS_WallY2 = 0;
	gim.OTS_C_WallX1 = 590;            //一度限りのスイッチで表れる壁のX/Y軸
	gim.OTS_C_WallY1 = 280;
	gim.OTS_C_WallX2 = 690;
	gim.OTS_C_WallY2 = 320;
	//*****************************************************

	//変形オブジェクト*******************************************
	gim.cheobj_flg = 1;			//変形するオブジェクトのフラグ
	gim.cheobj_x = 525;
	gim.cheobj_y = 425;
	gim.cheobj_c = g_Player.NowColor;
	gim.cheobj_ani = 158;
	//*****************************************************

	//箱の位置リセット
	g_Object.Init();//オブジェクトの移動量リセット


	//ドアの位置
	g_Door.x = 590;				//扉の左上のx座標
	g_Door.y = 80;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage28(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage28Init();
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画

	//色ブロック描画___________________________
	Change(PURPLE);
	DrawExtendGraph(0, 295, 100, 395, g_pic.Box, TRUE);
	DrawExtendGraph(1080, 195, 1180, 295, g_pic.Box, TRUE);
	DrawExtendGraph(1180, 195, 1280, 295, g_pic.Box, TRUE);
	Change(YELLOW);
	DrawExtendGraph(1180, 95, 1280, 195, g_pic.Box, TRUE);
	//動かせる箱の描画___________________________
	MoveBox(BLUE, 340, 568);
	MoveBox(RED, 840, 568);

	ColorReset();
	Warp(150, 270, 150, 568);

	OneTimeSwitch();

	ChangeBlock();	//変形するオブジェクトの関数

	//世界の壁_________________________________________
	Change(NONCOLOR);
	DrawBox(0, 395, 400, 420, GetColor(255, 255, 255), TRUE);//左の床
	DrawBox(525, 569, 750, 669, GetColor(255, 255, 255), TRUE);//中央の黒い壁
	DrawBox(880, 395, 1280, 420, GetColor(255, 255, 255), TRUE);//右の床
	DrawBox(290, 295, 340, 395, GetColor(255, 255, 255), TRUE);//左の障害物
	DrawBox(940, 295, 990, 395, GetColor(255, 255, 255), TRUE);//右の障害物

	//動かせる箱を一番前に出す
	frontMoveBox(BLUE, 340, 568);
	frontMoveBox(RED, 840, 568);

	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(4);

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