#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Object.h"
#include "Gimmick.h"
#include "Draw_Door_Rotation.h"

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
obj1x1 = 600,
obj1x2 = obj1x1 + 150,
obj2x1 = 750,
obj2x2 = obj2x1 + 150,
obj3x1 = 900,
obj3x2 = obj3x1 + 150,
obj4x1 = 1050,
obj4x2 = obj4x1 + 150,
objALLy1 = 518,
objALLy2 = 668;





void Stage7Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 60;//プレイヤーがインタラクトできる回数設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 6;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化


	gim.SwitchFlag = 0;			//スイッチ初期化


	gim.shower_C = PURPLE2;			//シャワーの塗りつぶしの色を初期化
	gim.shower_X = 70;				//シャワーの座標
	
	
	gim.SwitchColor = BLUE2;		//レバーの色の初期化

	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 100;
	g_Door.y = 170;
	g_Door.w = 200;
	g_Door.h = 370;

	//箱の位置リセット
	obj1x1 = 500;
	obj1x2 = obj1x1 + 100;
	obj2x1 = 750;
	obj2x2 = obj2x1 + 100;
	obj3x1 = 350;
	obj3x2 = obj3x1 + 100;
	obj4x1 = 900;
	obj4x2 = obj4x1 + 100;
	objALLy1 = 568;
	objALLy2 = 668;

	g_Object.Init();//オブジェクトの移動量リセット
}

int Stage7(void) {			//マップ画像の描画

	if ((InitFlag == TRUE) || (g_Player.PLAYER_MENU == TRUE)) {//InitフラグがTRUEの時に初期化できる,または、Yボタンを押されたとき初期化できる
		Stage7Init();
		g_Player.PLAYER_MENU = FALSE;
	}

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//マップの描画
	//色ブロック描画
	Change(YELLOW);
	DrawExtendGraph(obj4x1, objALLy1, obj4x2, objALLy2, g_pic.Box, TRUE);
	DrawExtendGraph(obj1x1 + g_Object.YELLOW_x, objALLy1, obj1x2 + g_Object.YELLOW_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj1x1 + g_Object.YELLOW_x, objALLy1 - 100, obj1x2 + g_Object.YELLOW_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
	Change(BLUE);
	DrawExtendGraph(obj3x1, objALLy1, obj3x2, objALLy2, g_pic.Box, TRUE);
	DrawExtendGraph(obj2x1 + g_Object.BLUE_x, objALLy1, obj2x2 + g_Object.BLUE_x, objALLy2, g_pic.Box_Move, TRUE);
	DrawExtendGraph(obj2x1 + g_Object.BLUE_x, objALLy1 - 100, obj2x2 + g_Object.BLUE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);

	//動く床処理___________________________________________________________________________________________________
	SlideBlock();

	//シャワー処理___________________________________________________________________________________________________
	Shower();

	//レバー処理___________________________________________________________________________________________________
	if(g_Lock.Release == 2)
	Lever();

	//触っている色のオブジェが画面の一番手前に来るようにする処理、いつかZ軸設定してやりたい
	switch (g_Player.NowColor) {
	case BLUE:
		Change(BLUE);
		DrawExtendGraph(obj2x1 + g_Object.BLUE_x, objALLy1, obj2x2 + g_Object.BLUE_x, objALLy2, g_pic.Box_Move, TRUE);
		DrawExtendGraph(obj2x1 + g_Object.BLUE_x, objALLy1 - 100, obj2x2 + g_Object.BLUE_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
		break;
	case YELLOW:
		Change(YELLOW);
		DrawExtendGraph(obj1x1 + g_Object.YELLOW_x, objALLy1, obj1x2 + g_Object.YELLOW_x, objALLy2, g_pic.Box_Move, TRUE);
		DrawExtendGraph(obj1x1 + g_Object.YELLOW_x, objALLy1 - 100, obj1x2 + g_Object.YELLOW_x, objALLy2 - 100, g_pic.Box_Move, TRUE);
		break;
	}

	//世界の壁（黒いブロック）
	Change(NONCOLOR);
	DrawBox(0,370,300,420,GetColor(255,255,255),TRUE);
	DrawBox(1080, 370, 1280, 420, GetColor(255, 255, 255), TRUE);
	Door();			//ステージゴール処理
	Lock();


	DoorRotation(4);

	//static int
	//	RotationNum = 4,//ローテーションする数
	//	X_Size = 100 / RotationNum;//ローテーションのボックスの横のサイズ

	//Change(g_Door.Rotation[g_MapC.StageNumber - 1][0]);
	//DrawBox(g_Door.x, g_Door.y-30, g_Door.x + X_Size, g_Door.y, GetColor(255, 255, 255), TRUE);
	//Change(g_Door.Rotation[g_MapC.StageNumber - 1][1]);
	//DrawBox(g_Door.x + X_Size, g_Door.y - 30, g_Door.x + X_Size*2, g_Door.y, GetColor(255, 255, 255), TRUE);
	//Change(g_Door.Rotation[g_MapC.StageNumber - 1][2]);
	//DrawBox(g_Door.x + X_Size * 2, g_Door.y - 30, g_Door.x + X_Size * 3, g_Door.y, GetColor(255, 255, 255), TRUE);
	//Change(g_Door.Rotation[g_MapC.StageNumber - 1][3]);
	//DrawBox(g_Door.x + X_Size * 3, g_Door.y - 30, g_Door.x + X_Size * 4, g_Door.y, GetColor(255, 255, 255), TRUE);

	ColorReset();

	return 0;
}