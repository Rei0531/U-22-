#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"
#include "Menu.h"
#include "SlaidBlock.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern Object g_Object;
extern Controller g_Pad;
extern GimmickAll gim;

static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ
//オブジェクトの初期位置
static int
SliObjx1 = 750 + 200,
SliObjx2 = 750 + 200,
SliObjy1 = 568,
SliObjy2 = 668;
static int SlideColor = 9;//スライド用の色

void Stage22Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 60;//プレイヤーがインタラクトできる回数設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 6;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.SliObjx1 = 950,
	gim.SliObjy1 = 320,
	gim.SliObjx2 = gim.SliObjx1 + 100,
	gim.SliObjy2 = gim.SliObjy1 + 50,

	gim.GetObjx1 = 1180,
	gim.GetObjx2 = gim.GetObjx1 + 100,
	gim.GetObjy1 = 270,
	gim.GetObjy2 = gim.GetObjy1 + 100,

	gim.move_max = 160;

	gim.shower_C = PURPLE2;			//シャワーの塗りつぶしの色を初期化
	gim.shower_X = 70;				//シャワーの座標

	gim.g_LeverX = 50;		//レバーのX座標
	gim.g_LeverY = 330;		//レバーのY座標

	gim.g_L_BoxX1 = 200;		//レバーで反応する箱X/Y座標
	gim.g_L_BoxY1 = 270;
	gim.g_L_BoxX2 = gim.g_L_BoxX1 + 100;
	gim.g_L_BoxY2 = gim.g_L_BoxY1 + 100;
	gim.g_L2_BoxX1 = 200;
	gim.g_L2_BoxY1 = 170;
	gim.g_L2_BoxX2 = gim.g_L2_BoxX1 + 100;
	gim.g_L2_BoxY2 = gim.g_L2_BoxY1 + 100;
	
	gim.OTSBox_Color = YELLOW;
	gim.OTSBox_Color2 = YELLOW;
	gim.OTSBox_Color3 = WHITE;
	gim.OTSBox_Color4 = WHITE;
	gim.OTSBox_Color5 = WHITE;

	gim.SwitchFlag = 0;		//レバーのON、OFF
	gim.SwitchColor = 0;		//レバーの色

	gim.SwitchColor = BLUE2;		//レバーの色の初期化

	//スライドする床2の用の変数_______＿＿＿＿

	gim.flg[0] = 0;
	gim.flg[1] = 0;

	gim.q2_color[0] = RED2;
	gim.q2_x[0] = 750;
	gim.q2_y[0] = 320;

	gim.q2_color[1] = RED2;
	gim.q2_x[1] = 900;
	gim.q2_y[1] = 200;

	gim.q2_move_x[0] = 1080;
	gim.q2_move_x[1] = 300;

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 100;
	g_Door.y = 170;
	g_Door.w = 200;
	g_Door.h = 370;

	SlideColor = RED;//スイッチから―の初期化

	g_Object.Init();//オブジェクトの移動量リセット
}

int Stage22(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage22Init();
	}


	//色ブロック描画
	Change(YELLOW);
	DrawExtendGraph(900, 568, 1000, 668, g_pic.Box[0], TRUE);
	MoveBox(YELLOW, 500, 568);
	MoveBox(YELLOW, 500, 468);
	Change(BLUE);
	DrawExtendGraph(350, 568, 450, 668, g_pic.Box[0], TRUE);
	MoveBox(BLUE, 750, 568);
	MoveBox(BLUE, 750, 468);
	Change(RED);
	DrawExtendGraph(1180, 270, 1280, 370, g_pic.Box[0], TRUE);

	//動く床処理___________________________________________________________________________________________________
	//SlideBlock(SlideColor);

	SlideBlock2(1, 150, 50);

	//シャワー処理___________________________________________________________________________________________________
	Shower();

	//レバー処理___________________________________________________________________________________________________
	if (g_Lock.Release == 2)
		Lever();

	//触っている色のオブジェが画面の一番手前に来るようにする処理、いつかZ軸設定してやりたい
	frontMoveBox(YELLOW, 500, 568);
	frontMoveBox(YELLOW, 500, 468);
	frontMoveBox(BLUE, 750, 568);
	frontMoveBox(BLUE, 750, 468);

	//世界の壁（黒いブロック）
	Change(NONCOLOR);
	DrawBox(0, 370, 300, 420, GetColor(255, 255, 255), TRUE);
	DrawBox(1080, 370, 1280, 420, GetColor(255, 255, 255), TRUE);
	Door();			//ステージゴール処理
	Lock();


	DoorRotationBox(4);//ドアの上のローテ―ションするボックスの描画


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