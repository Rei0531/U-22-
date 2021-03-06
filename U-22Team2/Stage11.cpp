#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Gimmick.h"
#include "Bomb.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage11Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 4;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.g_Bombflg = 0;				//爆弾フラグの初期化
	gim.BombX1 = 400;				//爆弾のX軸初期化
	gim.BombX2 = gim.BombX1 + 50;
	gim.BombY1 = 618;				//爆弾のY軸初期化
	gim.BombY2 = gim.BombY1 + 50;

	gim.B_EffectCount = 30;	//爆風の画像の描画時間
	gim.B_WallX1 = 650;			//壊せる壁のX軸
	gim.B_WallY1 = 0;
	gim.B_WallX2 = 700;			//壊せる壁のY軸
	gim.B_WallY2 = 669;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1100;				//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage11(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage11Init();
	}

	//色ブロック描画
	Change(BLUE);
	DrawExtendGraph(250, 568, 350, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(250, 468, 350, 568, g_pic.Box[0], TRUE);
	Change(RED);
	DrawExtendGraph(350, 568, 450, 668, g_pic.Box[0], TRUE);
	DrawExtendGraph(350, 468, 450, 568, g_pic.Box[0], TRUE);

	//ギミック説明描画
	DrawRotaGraph(1024, 74, 1.0, 0, g_pic.All_text[7], TRUE, FALSE);

	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(1);

	Bomb();

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