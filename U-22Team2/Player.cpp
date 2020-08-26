#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"
#include"Door.h"
#include "Object.h"
#include "LoadSound.h"
#include <stdlib.h>

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern Sound g_Snd;
extern Object g_Object;

int anicnt = 0,	//アニメ動かす変数
anicntMax = 20,	//アニメ全体の時間
aniy = 0,		//指の上下アニメ用変数
anix = 0,		//プレイヤーの向きによって変わるX座標用変数


const PicChangeFream = 8;
static int animecnt = 0;	//スポイントマンアニメーション用カウント変数
static int Jumpcnt = 20;	//ジャンプ処理のカウント
static int JumpMax = 0;		//ジャンプ処理全体にかかる最大時間
static int Sndcnt = 0;		//足音のフレームカウント変数
static int Gravity = 5;		//毎フレーム下に落とす
static int NoMove = 0;		//0の時動いていない1の時動いている/プレイヤーの歩くモーション待機モーション切り替えよう変数
static int JumpOkflag = 0;	//空中ジャンプ防止変数/0がジャンプしていない/1がジャンプ中
static int Move_Hitx1 = 0,	//動く箱に触れているかの取得する場所
		   Move_Hitx2 = 0;	//動く箱に触れているかの取得する場所

static bool Move_B = FALSE,//動かせる箱の動かせるかの変数
B = FALSE;//Bボタン二度おし防止

int PlayerDraw(void) {

	/************************************************************************
	**
	**		スポイト処理
	**
	*************************************************************************/

	if (g_Player.PLAYER_PICKUP == TRUE && g_Player.Interact > 0) { //この関数呼び出しで色を取得
		g_Player.NowColor = GetObjectColor();//変数にスポイトした色を格納する
	}
	if (g_Player.Interact <= 0)g_Player.Interact = 0;

	/*********************************************************************************************************
	*スポイトする場所の描画
	********************************************************************************************************/
	//スポイトする場所の描画___________________________________________________________________
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 40 : g_Player.x + 40;//
	g_Player.PickUpPixely = g_Player.y - 27;//初期値33もし白色が取れるようになってしまったら戻す

	//PixelColorに色を格納
	g_Object.PixelColor = GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely);
	//取得した色が白色だった時
	if (g_Object.PixelColor == WHITE) {
		//左向きの座標を取得する___________________________
		int Px1 = 5,
			Px2 = 3;

		//左用の座標を反転させ右向きようにする_______________________________________
		if (g_Player.PLAYER_DIRECTION == FALSE) {//右むいている時
			Px1 *= -1;
			Px2 *= -1;
		}
		//PixelColorの周りから色を取得する
		g_Object.PixelColor1 = GetPointColor(g_Player.PickUpPixel + Px1, g_Player.PickUpPixely);
		g_Object.PixelColor2 = GetPointColor(g_Player.PickUpPixel + Px2, g_Player.PickUpPixely - 3);
		g_Object.PixelColor3 = GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely - 5);
		g_Object.PixelColor4 = GetPointColor(g_Player.PickUpPixel + Px1, g_Player.PickUpPixely - 5);
		//指先の取得した色で優先順位で色を取る
		if (g_Object.PixelColor1 != WHITE)g_Object.PixelColor = g_Object.PixelColor1;
		if (g_Object.PixelColor4 != WHITE)g_Object.PixelColor = g_Object.PixelColor4;
		if (g_Object.PixelColor2 != WHITE)g_Object.PixelColor = g_Object.PixelColor2;
		if (g_Object.PixelColor3 != WHITE)g_Object.PixelColor = g_Object.PixelColor3;
	}


	//スポイトの手を表示させるかの判断式
	if (g_Object.PixelColor != WHITE && g_Object.PixelColor != NONCOLOR && g_Object.PixelColor != BLACK && g_Player.Interact > 0 &&
		g_Object.PixelColor != g_Player.NowColor && g_Object.PixelColor != MOVE && g_Player.PLAYER_MOVEBOX_PUSH == FALSE && g_Player.PLAYER_MOVEBOX_PULL == FALSE &&
		(!((g_Door.x - 5 < g_Player.PickUpPixel && g_Door.w + 5 > g_Player.PickUpPixel) &&
			(g_Door.y < g_Player.PickUpPixely && g_Door.h > g_Player.PickUpPixely)))) {//取得する場所の色が白じゃないとき描画

			//スポイトの手が上下するアニメーション処理______________
		anicnt++;

		if (anicnt > anicntMax / 2) {
			aniy += 2;
		}
		if (anicnt <= anicntMax / 2) {
			aniy -= 2;
		}
		if (anicnt >= anicntMax)anicnt = 0;
		g_Player.PLAYER_DIRECTION ? anix = 54 : anix = 10;
		//_____________________________________________________________

		//スポイトの手
		Change2(g_Object.PixelColor);
		DrawRotaGraph2(g_Player.PickUpPixel, g_Player.PickUpPixely + aniy, anix, 46, 1.0, 0, g_pic.Hand, TRUE, g_Player.PLAYER_DIRECTION);
		if (g_Pad.KEY_X == TRUE && g_Player.Interact > 0) {
			g_Player.NowColor = g_Object.PixelColor;
		}
	}

	//*********************************************************************************************************

	/************************************************************************
	**
	**		当たり判定取得処理
	**
	*************************************************************************/
	int Hit_Up_y = g_Player.y - 33,			//プレイヤーの頭上
		Hit_L_x = g_Player.x - 30,		//左の中心からのx座標
		Hit_R_x = g_Player.x + 30,		//右の中心からのx座標
		Hit_UpLR_y = g_Player.y,		//上側左右の中心からのy座標
		Hit_Under_y = g_Player.y + 72,		//プレイヤーの足元	y軸
		Hit_Under_x = 20,		//プレイヤーの足元  x軸
		Hit_UnderLR_y = g_Player.y + 60;		//下側左右の中心からのy座標

	Move_Hitx1 = g_Player.x + 50;//取得する座標
	Move_Hitx2 = g_Player.x - 50;//取得する座標

	/*
	//   Left_High□	　　	□Rght_High
	当たり判定のイメ―ジ

					　□Hit_Up
		  LeftUp□			□RightUp
	Move_Hit2□				   □Move_Hit1
	　 LeftUnder□			□RightUnder
			Under2□	　□Under

	*/

	/************************************************************************
	*当たり判定箇所の色を取得
	*************************************************************************/
	g_Player.Hit_Up = GetPointColor(g_Player.x, Hit_Up_y);				//頭上
	if (g_Pad.KEY_RIGHT == TRUE) {
		//g_Player.Hit_Rght_High = GetPointColor(Hit_R_x, Hit_UpLR_y - 50);	//右頭
		g_Player.Hit_RightUp = GetPointColor(Hit_R_x, Hit_UpLR_y);			//右上
		g_Player.Hit_RightUnder = GetPointColor(Hit_R_x, Hit_UnderLR_y);	//右下
	}
	if (g_Pad.KEY_LEFT == TRUE) {
		//g_Player.Hit_Left_High = GetPointColor(Hit_L_x, Hit_UpLR_y - 50);	//左頭
		g_Player.Hit_LeftUp = GetPointColor(Hit_L_x, Hit_UpLR_y);			//左上
		g_Player.Hit_LeftUnder = GetPointColor(Hit_L_x, Hit_UnderLR_y);		//左下
	}
	g_Player.Move_HitR = GetPointColor(Move_Hitx1, g_Player.y + 25);		//プレイヤーの中心座標からむいている方向の50加減算した値の色を取得
	g_Player.Move_HitL = GetPointColor(Move_Hitx2, g_Player.y + 25);		//プレイヤーの中心座標からむいている方向の50加減算した値の色を取得
	g_Player.Hit_Under = GetPointColor(g_Player.x, Hit_Under_y);		//右足元
	//g_Player.Hit_Under2 = GetPointColor(g_Player.x - Hit_Under_x, Hit_Under_y);		//左足元
	//動かせるボックスかどうか知るための色を取得_________________________


	//当たり判定のフラグ管理_____________________________________
	//右行ってヨシ！
	//bool RightOK = g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder && g_Player.NowColor != g_Player.Hit_Rght_High
	//	&& g_Player.Hit_RightUp != BLACK && g_Player.Hit_RightUnder != BLACK && g_Player.Hit_Rght_High != BLACK;
	////左行ってヨシ！
	//bool LeftOK = g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder && g_Player.NowColor != g_Player.Hit_Left_High
	//	&& g_Player.Hit_LeftUp != BLACK && g_Player.Hit_LeftUnder != BLACK && g_Player.Hit_Left_High != BLACK;

	//当たり判定一時上の当たりを削除、心配だから処理はまだコメントで残す
	bool RightOK = g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder
		&& g_Player.Hit_RightUp != BLACK && g_Player.Hit_RightUnder != BLACK && g_Player.Hit_RightUp != MOVE;
	//左行ってヨシ！
	bool LeftOK = g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder
		&& g_Player.Hit_LeftUp != BLACK && g_Player.Hit_LeftUnder != BLACK && g_Player.Hit_LeftUp != MOVE;

	/************************************************************************
	**
	**		プレイヤーの動き
	**
	*************************************************************************/
	if (g_Player.PLAYER_MENU == FALSE && g_Player.Hit_Up != g_Player.NowColor) {//メニュー画面を閉じているとき,色が重なっていないとき
		/************************************************************************
		*当たり判定処理 & ボックスを動かす
		*************************************************************************/
		//Bボタンの切り替え条件の隣に動かせる箱があるか
		bool MOVEOK = (g_Player.Move_HitL == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder)
			|| (g_Player.Move_HitR == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder);

		//動く箱に触れている判定になっているのに、動く箱が近くにない時
		if (Move_B == TRUE && g_Player.Move_HitL != MOVE && g_Player.Move_HitR != MOVE) {
			Move_B = FALSE;
		}

		if (g_Pad.KEY_B == TRUE && Move_B == TRUE && B == FALSE && MOVEOK == TRUE) {
			Move_B = FALSE;
			B = TRUE;
		}
		if (g_Pad.KEY_B == TRUE && Move_B == FALSE && B == FALSE && MOVEOK == TRUE) {
			Move_B = TRUE;
			B = TRUE;
		}

		//Init処理が呼ばれたら、オブジェクト持ってる判定をやめる
		if (g_Player.InitFlag == TRUE) {
			Move_B = FALSE;
		}

		B = (g_Pad.KEY_B == TRUE) ? TRUE : FALSE;//Bボタンが押されていたら/再度Bボタンが押せるように

		if (Move_B == TRUE && g_Player.PLAYER_GROUND == TRUE) {
			if (g_Pad.KEY_RIGHT == TRUE)g_Player.Move_BlackR = GetPointColor(Hit_R_x + 110, Hit_UnderLR_y);		//動かせる箱が黒い壁にめり込まないようにむいてる方向にオブジェクトの箱の横幅100を加算した値
			if (g_Pad.KEY_LEFT == TRUE)g_Player.Move_BlackL = GetPointColor(Hit_L_x - 110, Hit_UnderLR_y);		//動かせる箱が黒い壁にめり込まないようにむいてる方向にオブジェクトの箱の横幅100を加算した値
			MoveObjectValue(g_Player.NowColor);
		}
		//箱を引きずる音___________________________________________________
		if (Move_B == TRUE && CheckSoundMem(g_Snd.BoxDrag) == 0 &&
			(g_Player.PLAYER_MOVEBOX_PUSH == TRUE || g_Player.PLAYER_MOVEBOX_PULL == TRUE)
			&& (g_Pad.KEY_LEFT == TRUE || g_Pad.KEY_RIGHT == TRUE)) {
			PlaySoundMem(g_Snd.BoxDrag, DX_PLAYTYPE_BACK);
		}
		if ((g_Pad.KEY_LEFT == FALSE && g_Pad.KEY_RIGHT == FALSE) ||
			(Move_B == FALSE) && (CheckSoundMem(g_Snd.BoxDrag) == 1)) {
			StopSoundMem(g_Snd.BoxDrag);
		}
		//箱を動かしているフラグをリセットする____________________________________________
		if (CheckSoundMem(g_Snd.BoxDrag) == 0
			&& (g_Player.PLAYER_MOVEBOX_PUSH == TRUE || g_Player.PLAYER_MOVEBOX_PULL == TRUE)) {
			g_Player.PLAYER_MOVEBOX_PUSH = FALSE;
			g_Player.PLAYER_MOVEBOX_PULL = FALSE;
		}
		//_________________________________________________________________________________________

		//********************************************************************************************
		/************************************************************************
		*プレイヤーの移動処理
		*************************************************************************/
		if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//右か左に入力されていたら
		{
			//歩く時の音、マップ端を超えないようにする処理_______________________________________
			if ((Sndcnt++ % (PicChangeFream + 6)) == 0) {
				if (g_Player.PLAYER_JUMP == FALSE && g_Player.PLAYER_GROUND == TRUE && Move_B == FALSE
					&& !((RightOK == FALSE && g_Pad.KEY_RIGHT == TRUE) || (g_Pad.KEY_LEFT == TRUE && LeftOK == FALSE))) {//音を鳴らす
					PlaySoundMem(g_Snd.Walk, DX_PLAYTYPE_BACK);
				}
			}
			if (g_Player.x < g_MapC.X1 + 20) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、左端に到達
				g_Player.x = g_MapC.X1 + 20;
			}
			if (g_Player.x > g_MapC.X2 - 20) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、右端に到達
				g_Player.x = g_MapC.X2 - 20;
			}
			//_____________________________________________________________________________________

			//右側の当たり判定処理______________________________________________________________
			if (g_Pad.KEY_RIGHT == TRUE && RightOK == TRUE) {
				g_Player.x += PLAYERX;
			}

			//左側の当たり判定処理________________________________________________
			if (g_Pad.KEY_LEFT == TRUE && LeftOK == TRUE) {
				g_Player.x -= PLAYERX;
			}
			animecnt++;//アニメーション用のカウントプラス
			NoMove = 1;//動いているときのフラグ
		}
		/************************************************************************
		*動いていない処理
		*************************************************************************/
		else {
			NoMove = 0;//動いていない
			animecnt = 0;//アニメーションを止める
			if (CheckSoundMem(g_Snd.Walk) == 1) {//音を止める
				StopSoundMem(g_Snd.Walk);
			}
		}
		/************************************************************************
		*重力の処理
		*************************************************************************/
		//プレイヤーが地面についていないとき
		if (!((g_Player.Hit_Under == g_Player.NowColor) ||
			(g_Player.Hit_Under == BLACK))) {
			g_Player.y += Gravity;		//プレイヤーに重力を追加
			g_Player.PLAYER_GROUND = FALSE;
		}
		else {
			JumpOkflag = 0;	//地面についているのでジャンプしていない
			g_Player.PLAYER_GROUND = TRUE;
		}

		/************************************************************************
		*プレイヤーのジャンプ処理
		*************************************************************************/
		if ((g_Player.PLAYER_JUMP == TRUE && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor))) || JumpOkflag == 1) {	//ジャンプボタンが押されたら
			Jumpcnt--;		//ジャンプアニメーションのカウント開始
			JumpOkflag = 1;	//一度ジャンプしたので終わるまでジャンプ処理
			if (Jumpcnt >= JumpMax) {//決められた時間までプレイヤーを上にあげる
				g_Player.y -= Jumpcnt;
			}
			if (Jumpcnt <= JumpMax && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor))) {		//ジャンプアニメーションが決められた時間になったとき
				g_Player.PLAYER_JUMP = FALSE;//ジャンプ処理の終了
				Jumpcnt = 20;				//ジャンプアニメーションのカウントを0にする
				PlaySoundMem(g_Snd.Landing, DX_PLAYTYPE_BACK);
			}
			if (g_Player.Hit_Up == BLACK || g_Player.Hit_Up == g_Player.NowColor) {	//プレイヤーが天井にぶつかった時,ジャンプ処理を終了する
				g_Player.PLAYER_JUMP = FALSE;//ジャンプ処理の終了
				Jumpcnt = 20;				//ジャンプアニメーションのカウントを0にする
				JumpOkflag = 0;	//一度ジャンプしたので終わるまでジャンプ処理
			}
		}
	}

	/************************************************************************
	**
	**		プレイヤーの描画
	**
	*************************************************************************/

	static int
		anime_motionMax = 0,//プレイヤーの描画に合わせて画像のどの列のプレイヤーを描画するかの変数
		anime_JumpMax = 9,//ジャンプアニメーションのどこまでを画像から描画するかの最大値の変数
		anime_PushMax = 14,//押すモーション
		anime_PullMax = 16;//引くモーション

	//ジャンプしているとき_________________________________________
	if (g_Player.PLAYER_JUMP == TRUE) {
		g_Player.Anime_Num = 5;		//画像の描画の開始位置の設定
		anime_motionMax = 1;		//画像の分割の最大値の設定(4枚の画像)
		NoMove = 0;
	}
	//通常の歩いているとき_______________________________________________________
	else {
		anime_motionMax = 4;		//画像の分割の最大値の設定(3枚の画像)
		g_Player.Anime_Num = 0;		//画像の描画の開始位置の設定

		if (Move_B == FALSE && ((RightOK == FALSE && g_Pad.KEY_RIGHT == TRUE) || (g_Pad.KEY_LEFT == TRUE && LeftOK == FALSE))) {
			NoMove = 0;
			animecnt = 0;
		}

		//動く箱を触っている時____________________________________________
		if (Move_B == TRUE && g_Pad.KEY_LEFT == FALSE && g_Pad.KEY_RIGHT == FALSE) {
			g_Player.Anime_Num = 10;		//画像の描画の開始位置の設定
			anime_motionMax = 4;			//画像の分割の最大値の設定(3枚の画像)
			NoMove = 0;

			//動く箱があった時
			//g_Player.PLAYER_DIRECTION = g_Player.Move_HitL == MOVE ? TRUE : FALSE;
			if (g_Player.Move_HitL == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder)g_Player.PLAYER_DIRECTION = TRUE;
			if (g_Player.Move_HitR == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder)g_Player.PLAYER_DIRECTION = FALSE;

		}
		//箱を押している時___________________________________________________________
		if (g_Player.PLAYER_MOVEBOX_PUSH == TRUE) {
			g_Player.Anime_Num = 10;		//画像の描画の開始位置の設定
			anime_motionMax = 4;			//画像の分割の最大値の設定(3枚の画像)
			NoMove = 0;
		}
		//箱を引いている時___________________________________________________________
		if (g_Player.PLAYER_MOVEBOX_PULL == TRUE) {
			g_Player.Anime_Num = 15;		//画像の描画の開始位置の設定
			anime_motionMax = 4;			//画像の分割の最大値の設定(3枚の画像)
			NoMove = 0;
		}
	}
	Change(g_Player.NowColor);//引数に色の名前/数字を入れて値を変更
	//														8フレームごとに、プレイヤーの動きに合わせて動かす
	DrawRotaGraph(g_Player.x, g_Player.y, 0.7, 0.0, g_pic.Player[animecnt / 8 % anime_motionMax + g_Player.Anime_Num + NoMove], TRUE, g_Player.PLAYER_DIRECTION);//プレイヤー画像の描画
	//_____________________________________________________________________________________________________________________
	ColorReset();
	//重なった場合の注意表示
	if (g_Player.Hit_Up == g_Player.NowColor) {
		g_Player.PLAYER_MOVEOK = FALSE;//動けない状態のフラグにする
		DrawString(450, 698, "大変だ！オブジェクトと重なってしまった！", 0xff0000);
		DrawString(470, 718, "STARTボタンを押してRESETしよう", 0xffffff);
	}
	else {
		g_Player.PLAYER_MOVEOK = TRUE;//動けない状態のフラグにする
	}
	//当たり判定の可視化_____________________________________________________________________
	//DrawBox(g_Player.x - 5, Hit_Up_y - 5, g_Player.x + 5, Hit_Up_y + 5, 0xfe00fe, FALSE);	//頭上
	//DrawBox(Hit_R_x - 5, Hit_UpLR_y - 5, Hit_R_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//右上
	//DrawBox(Hit_R_x - 5, Hit_UnderLR_y - 5, Hit_R_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//右下
	//DrawBox(Hit_L_x - 5, Hit_UpLR_y - 5, Hit_L_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//左上
	//DrawBox(Hit_L_x - 5, Hit_UnderLR_y - 5, Hit_L_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//左下
	//DrawBox(g_Player.x - 5, Hit_Under_y - 5, g_Player.x + 5, Hit_Under_y + 5, 0xfe00fe, FALSE);	//足元右
	////DrawBox(g_Player.x - 5 - Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 - Hit_Under_x, Hit_Under_y + 5, 0xfe00fe, FALSE);	//足元左
	//DrawBox(g_Player.PickUpPixel - 5, g_Player.PickUpPixely - 5, g_Player.PickUpPixel + 5, g_Player.PickUpPixely + 5, 0xff00ff, FALSE);
	//DrawBox(Move_Hitx1 - 5, g_Player.y + 25 - 5, Move_Hitx1 + 5, g_Player.y + 25 + 5, 0xfe00fe, FALSE);	//動くブロックの取得位置右
	//DrawBox(Move_Hitx2 - 5, g_Player.y + 25 - 5, Move_Hitx2 + 5, g_Player.y + 25 + 5, 0xfe00fe, FALSE);	//動くブロックの取得位置左

	////DrawBox(Hit_R_x - 5, Hit_UpLR_y - 50 - 5, Hit_R_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//右頭
	////DrawBox(Hit_L_x - 5, Hit_UpLR_y - 50 - 5, Hit_L_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//右頭

	//DrawBox(Hit_R_x + 110 - 5, Hit_UnderLR_y - 5, Hit_R_x + 110 + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//動かせる箱の黒い壁判定
	//DrawBox(Hit_L_x - 110 - 5, Hit_UnderLR_y - 5, Hit_L_x - 110 + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//動かせる箱の黒い壁判定

	return 0;
}