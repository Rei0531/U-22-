#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"
#include "Draw_Door_Rotation.h"
#include "Rotation_Box.h"
#include "Menu.h"
#include"Gimmick.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern LockALL g_Lock;
extern GimmickAll gim;
static bool InitFlag = TRUE;//Init関数を通っていいか判定変数/TRUEがいい/FALSEがダメ

int SlideColor = BLUE;

void Stage25Init() {
	//プレイヤーの初期位置
	//オブジェクトの初期位置を描く
	g_Player.Interact = 10;//プレイヤーがインタラクトできる回数を10回に設定
	InitFlag = FALSE;	//FALSEにして次TRUEになるまで通らないようにする

	g_Player.x = 110;			//プレイヤー座標初期化
	g_Player.y = 571;			//プレイヤー座標初期化
	g_Player.NowColor = 5;		//プレイヤーの色初期化

	g_Door.RotationNumber = 0;	//ローテーション初期化
	g_Lock.Release = 0;			//鍵穴解除数初期化

	gim.shower_C2[0] = BLUE2;            //シャワーの塗りつぶしの色を初期化
	gim.shower_X2[0] = 530;                //シャワーの座標
	gim.shower_Y2[0] = 670 - 256;

	gim.shower_C2[1] = RED2;            //シャワーの塗りつぶしの色を初期化
	gim.shower_X2[1] = 1000;                //シャワーの座標
	gim.shower_Y2[1] = 280 - 256;


	//スライドする床2の用の変数_______＿＿＿＿

	gim.flg[0] = 0;
	gim.flg[1] = 0;

	gim.q2_color[0] = BLUE2;
	gim.q2_x[0] = 150;
	gim.q2_y[0] = 310;

	gim.q2_color[1] = RED2;
	gim.q2_x[1] = 900;
	gim.q2_y[1] = 200;

	gim.q2_move_x[0] = 1100;
	gim.q2_move_x[1] = 150;

	//回復アイテム用_________
	gim.item_x = 25;
	gim.item_y = 400 - 50;
	gim.item_y;
	gim.item_flg = 1;

	DrawExtendGraph(0, 300, 100, 400, g_pic.Box[0], TRUE);
	for (int i = 0; g_Lock.n[g_MapC.StageNumber - 1] > i; i++) {
		g_Lock.color[g_MapC.StageNumber - 1][i] = g_Lock.colorback[g_MapC.StageNumber - 1][i];
	}

	//ドアの位置
	g_Door.x = 1150;				//扉の左上のx座標
	g_Door.y = 468;				//扉の左上のy座標
	g_Door.w = g_Door.x + 100;	//横幅
	g_Door.h = g_Door.y + 200;	//縦幅

}

int Stage25(void) {			//マップ画像の描画

	if ((InitFlag == TRUE)) {//InitフラグがTRUEの時に初期化できる
		Stage25Init();
	}

	Change(NONCOLOR);
	DrawBox(1100, 280, 1280, 320, GetColor(255, 255, 255), TRUE);





	Change(BLUE);
	DrawExtendGraph(990, 569, 1090, 669, g_pic.Box[0], TRUE);
	DrawExtendGraph(940, 468, 1040, 568, g_pic.Box[0], TRUE);

	Change(Rotation_Box(0));
	DrawExtendGraph(890, 569, 990, 669, g_pic.Box[2], TRUE);
	DrawExtendGraph(840, 468, 940, 568, g_pic.Box[2], TRUE);

	Change(BLUE);
	DrawExtendGraph(790, 569, 890, 669, g_pic.Box[0], TRUE);
	DrawExtendGraph(740, 468, 840, 568, g_pic.Box[0], TRUE);



	Change(Rotation_Box(0));

	DrawExtendGraph(270, 569, 370, 669, g_pic.Box[2], TRUE);

	DrawExtendGraph(170, 569, 270, 669, g_pic.Box[2], TRUE);
	DrawExtendGraph(170, 468, 270, 568, g_pic.Box[2], TRUE);



	Change(NONCOLOR);
	DrawBox(0, 400, 150, 450, GetColor(255, 255, 255), TRUE);

	Change(BLUE);
	DrawExtendGraph(0, 300, 100, 400, g_pic.Box[0], TRUE);


	Door();			//ステージゴール処理
	Lock();

	Shower2(2);
	SlideBlock2(2);
	kaihuku(gim.item_x, gim.item_y);		//回復アイテム

	DoorRotationBox(4);


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



int SlideBlock2(int k)
{




	for (int i = 0; i < k; i++) {


		//________________________________描画処理
		gim.q2_w[i] = gim.q2_x[i] + 200;
		gim.q2_h[i] = gim.q2_y[i] + 50;

		Change(gim.q2_color[i]);
		DrawExtendGraph(gim.q2_x[i], gim.q2_y[i], gim.q2_w[i], gim.q2_h[i], g_pic.Box[0], TRUE);//動く床	


		//________________________________移動処理

		if (gim.flg[i] != 3 && gim.flg[i] != 4) {

			if ((gim.q2_w[i] < gim.q2_move_x[0]) && (gim.flg[i] == 0)) {

				gim.q2_x[i] += 5;
			}
			else {
				gim.flg[i] = 1;
			}

			if ((gim.q2_x[i] > gim.q2_move_x[1]) && (gim.flg[i] == 1)) {
				gim.q2_x[i] -= 5;
			}
			else {
				gim.flg[i] = 0;
			}
		}
		//________________________________プレイヤーとの当たり判定
		if (g_Player.NowColor == gim.q2_color[i]) {

			if (gim.flg[i] == 1 || gim.flg[i] == 3) { //左で止まる処理

				if ((gim.q2_x[i] - 35 < g_Player.x) && (gim.q2_w[i] > g_Player.x + 30) &&
					(gim.q2_y[i] - 30 < g_Player.y) && (gim.q2_h[i] + 72 > g_Player.y)) {

					gim.flg[i] = 3;


				}
				else if (gim.flg[i] == 3) {

					gim.flg[i] = 1;
				}
			}

			if (gim.flg[i] == 0 || gim.flg[i] == 4) {			//右で止まる処理

				if ((gim.q2_x[i] < g_Player.x + 30) && (gim.q2_w[i] + 30 > g_Player.x) &&
					(gim.q2_y[i] - 30 < g_Player.y) && (gim.q2_h[i] + 72 > g_Player.y)) {

					gim.flg[i] = 4;

				}
				else if (gim.flg[i] == 4) {

					gim.flg[i] = 0;
				}
			}

			//プレイヤーが箱の上に載っているときの処理
			if ((gim.q2_x[i] < g_Player.x) && (gim.q2_w[i] > g_Player.x) &&
				(gim.q2_y[i] > g_Player.y) && (gim.q2_y[i] - 5 <= g_Player.y + 72) &&
				(gim.flg[i] == 0)) {

				g_Player.x += 5;

			}
			else if ((gim.q2_x[i] < g_Player.x) && (gim.q2_w[i] > g_Player.x) &&
				(gim.q2_y[i] > g_Player.y) && (gim.q2_y[i] - 5 <= g_Player.y + 72) &&
				(gim.flg[i] == 1)) {

				g_Player.x -= 5;

			}

			if ((gim.q2_x[i] < g_Player.x) && (gim.q2_w[i] > g_Player.x) &&
				(gim.q2_h[i] < g_Player.y) && (gim.q2_h[i] + 50 > g_Player.y)) {

				g_Player.y = gim.q2_h[i] + 55;
			}

		}
	}







	ColorReset();

	return 0;
}