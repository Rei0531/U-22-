#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Menu.h"
#include "SlaidBlock.h"
#include "Draw_Door_Rotation.h"

extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern GimmickAll gim;
//extern SlideFunction g_SlaF;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数
//オブジェクトの初期位置
static int obj2x1 = 550,
obj2x2 = obj2x1 + 100,
objALLy1 = 568,
objALLy2 = 668;
static int SlideColor = 9;//スライド用の色
void Stage6Init() {
	//移動方向のフラグ
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 5;	//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}
	//ドアの位置
	g_Door.x = 1150;			//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

	//ブロックの初期化
	obj2x1 = 550,
	obj2x2 = obj2x1 + 100,
	objALLy1 = 568,
	objALLy2 = objALLy1 + 100,
	gim.SliObjx1 = 750,
	gim.SliObjx2 = gim.SliObjx1 + 150,
	gim.SliObjy1 = 518,
	gim.SliObjy2 = gim.SliObjy1 + 150,
	gim.GetObjx1 = 260,
	gim.GetObjx2 = gim.GetObjx1 + 100,
	gim.GetObjy1 = 568,
	gim.GetObjy2 = gim.GetObjy1 + 100,
	gim.move_max = 100;

	SlideColor = RED;//スイッチから―の初期化
}

int Stage6(void) {			//マップ画像の描画
	if (InitFlag == TRUE) {//InitフラグがTRUEの時に初期化できる,または、Yボタンを押されたとき初期化できる
		Stage6Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	Change(BLUE);//色ブロック描画
	DrawExtendGraph(980, 468, 1080, 568, g_pic.Box[0], TRUE);//障害ブロック
	DrawExtendGraph(980, 568, 1080, 668, g_pic.Box[0], TRUE);//障害ブロック
	//DrawExtendGraph(g_Player.x - 30, g_Player.y - 30, g_Player.x + 30, g_Player.y + 30, GetColor(255, 255, 255), TRUE);
	Change(RED);//色ブロック描画
	
	//DrawExtendGraph(380, 568, 480, 668, g_pic.Box, TRUE);//障害ブロック
	DrawExtendGraph(880, 568, 980, 668, g_pic.Box[0], TRUE);//障害ブロック
	DrawExtendGraph(880, 468, 980, 568, g_pic.Box[0], TRUE);//障害ブロック

	//ギミック説明描画
	DrawRotaGraph(900, 110, 1.5, 0, g_pic.All_text[8], TRUE, FALSE);


	SlideBlock(SlideColor);//動くブロックの方向と、乗ったプレイヤーを動かす処理
	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(2);


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