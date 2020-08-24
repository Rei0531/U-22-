#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Bomb.h"
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

void Stage21Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 3;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 5;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.g_Bombflg = 0;				//爆弾フラグの初期化
	gim.BombX1 = 25;				//爆弾のX軸初期化
	gim.BombX2 = gim.BombX1 + 50;
	gim.BombY1 = 240;				//爆弾のY軸初期化
	gim.BombY2 = gim.BombY1 + 50;

	gim.B_EffectCount = 30;	//爆風の画像の描画時間
	gim.B_WallX1 = 1000;			//壊せる壁のX軸
	gim.B_WallY1 = 0;
	gim.B_WallX2 = 1100;			//壊せる壁のY軸
	gim.B_WallY2 = 300;

	gim.item_x = 1200;
	gim.item_y = 250;
	gim.item_flg = 1;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage21(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage21Init();
	}


	Change(NONCOLOR);
	DrawBox(300, 280, 750, 300, 0xffffff, TRUE);
	DrawBox(0, 300, 100, 370, 0xffffff, TRUE);
	DrawBox(950, 300, 1000, 370, 0xffffff, TRUE);
	DrawBox(1100, 300, 1300, 370, 0xffffff, TRUE);

	Change(YELLOW);
	DrawExtendGraph(100, 370, 200, 470, g_pic.Box[0], TRUE);
	DrawExtendGraph(100, 470, 200, 570, g_pic.Box[0], TRUE);
	DrawExtendGraph(100, 570, 200, 670, g_pic.Box[0], TRUE);
	DrawExtendGraph(200, 470, 300, 570, g_pic.Box[0], TRUE);
	DrawExtendGraph(200, 570, 300, 670, g_pic.Box[0], TRUE);
	Change(RED);
	DrawExtendGraph(750, 470, 850, 570, g_pic.Box[0], TRUE);
	DrawExtendGraph(750, 570, 850, 670, g_pic.Box[0], TRUE);
	DrawExtendGraph(850, 370, 950, 470, g_pic.Box[0], TRUE);
	DrawExtendGraph(850, 470, 950, 570, g_pic.Box[0], TRUE);
	DrawExtendGraph(850, 570, 950, 670, g_pic.Box[0], TRUE);

	Change(Rotation_Box(0));
	DrawExtendGraph(300, 568, 400, 668, g_pic.Box[2], TRUE);
	Change(Rotation_Box(1));
	DrawExtendGraph(550, 568, 650, 668, g_pic.Box[2], TRUE);
	Change(Rotation_Box(2));
	DrawExtendGraph(650, 568, 750, 668, g_pic.Box[2], TRUE);

	kaihuku(gim.item_x, gim.item_y);

	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(3);


	Bomb();

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