#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Gimmick.h"
#include "Menu.h"


extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

void Stage7Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 0;		//プレイヤーの色初期化//0:RED 1:ORENGE 2:YELLOW 3:GREEN 4:LIGHTBLUE 5:BLUE 6:PURPLE

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 540;				//扉の左上のx座標
	g_Door.y = 170;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

	gim.CC_SwitchColor = 9;//スイッチから―の初期化

}

int Stage7(void) {			//マップ画像の描画

	//色反映スイッチ_____________________
	gim.CC_SwitchColor = CC_Switch(g_Player.NowColor, 140, 578);//一時変数に関数からの戻り値を格納する
	Change(gim.CC_SwitchColor);
	//色反映する箱________________________________________________
	DrawExtendGraph(340, 568, 440, 668, g_pic.Box[3], TRUE);
	DrawExtendGraph(340, 468, 440, 568, g_pic.Box[3], TRUE);
	DrawExtendGraph(740, 568, 840, 668, g_pic.Box[3], TRUE);
	DrawExtendGraph(740, 468, 840, 568, g_pic.Box[3], TRUE);

	//色ブロック描画
	Change(RED);
	DrawExtendGraph(240, 568, 340, 668, g_pic.Box[0], TRUE);
	Change(GREEN);
	DrawExtendGraph(840, 568, 940, 668, g_pic.Box[0], TRUE);

	//世界の壁_________________________________________
	Change(NONCOLOR);
	DrawBox(440, 370, 740, 420, GetColor(255, 255, 255), TRUE);

	//ギミック説明描画
	DrawRotaGraph(1024, 74, 1.0, 0, g_pic.All_text[10], TRUE, FALSE);

	Door();			//ステージゴール処理
	Lock();

	DoorRotationBox(2);

	//ステージクリアした時、タイトル画面に戻ったとき
	if (g_Lock.clearflg == TRUE || g_Player.InitFlag == TRUE) {
		InitFlag = TRUE;
		g_Player.InitFlag = FALSE;
	}

	//Init処理___________________________________
	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage7Init();
	}
	if (g_Player.PLAYER_MENU == TRUE) {
		InitFlag = Menu_Update();
	}

	return 0;
}