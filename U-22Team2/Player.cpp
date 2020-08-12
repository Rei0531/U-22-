#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"
#include"Door.h"
#include "Object.h"
#include "LoadSound.h"

extern image g_pic;
extern Controller g_Pad;
extern MapCoordinate g_MapC;
extern Player g_Player;
extern DoorAll g_Door;
extern Sound g_Snd;


int PlayerDraw(void) {
	static int animecnt = 0;	//スポイントマンアニメーション用カウント変数
	static int Jumpcnt = 20;			//ジャンプ処理のカウント
	static int JumpMax = 0;	//ジャンプ処理全体にかかる最大時間
	static int Gravity = 5;		//毎フレーム下に落とす
	static int NoMove = 0;		//0の時動いていない1の時動いている/プレイヤーの歩くモーション待機モーション切り替えよう変数
	static int JumpOkflag = 0;	//空中ジャンプ防止変数/0がジャンプしていない/1がジャンプ中
	static int Move_Hitx1 = 0,
		Move_Hitx2 = 0;
/************************************************************************
**
**		スポイト処理
**
*************************************************************************/

	if (g_Player.PLAYER_PICKUP == TRUE && g_Player.Interact > 0) { //この関数呼び出しで色を取得
		g_Player.NowColor = GetObjectColor();//変数にスポイトした色を格納する
	}
	if (g_Player.Interact <= 0)g_Player.Interact = 0;

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

	Move_Hitx1 = g_Player.x + 40;//取得する座標
	Move_Hitx2 = g_Player.x - 40;//取得する座標

	//マジックナンバーの解説
	//Hit_Up_yの90はプレイヤー画像の真ん中から上下の端っこまでの距離
	//Hit_LR_xの40は画像の真ん中から左右の端っこまでの距離
	//Hit_UpLR_yは画像の真ん中から上か下までの距離の半分

	/*
	当たり判定のイメ―ジ

	   Left_High□	　　	□Rght_High
					　□Hit_Up
		  LeftUp□			□RightUp
	Move_Hit2□				   □Move_Hit1
	　 LeftUnder□			□RightUnder
			Under2□	　□Under

	*/

	/************************************************************************
	*当たり判定箇所の色を取得
	*************************************************************************/
	g_Player.Hit_Rght_High = GetPointColor(Hit_R_x, Hit_UpLR_y - 50);		//右頭
	g_Player.Hit_Left_High = GetPointColor(Hit_L_x, Hit_UpLR_y - 50);		//右頭
	g_Player.Hit_Up = GetPointColor(g_Player.x, Hit_Up_y);				//頭上
	g_Player.Hit_RightUp = GetPointColor(Hit_R_x, Hit_UpLR_y);			//右上
	g_Player.Hit_RightUnder = GetPointColor(Hit_R_x, Hit_UnderLR_y);	//右下
	g_Player.Hit_LeftUp = GetPointColor(Hit_L_x, Hit_UpLR_y);			//左上
	g_Player.Hit_LeftUnder = GetPointColor(Hit_L_x, Hit_UnderLR_y);		//左下
	g_Player.Hit_Under = GetPointColor(g_Player.x + Hit_Under_x, Hit_Under_y);		//右足元
	g_Player.Hit_Under2 = GetPointColor(g_Player.x - Hit_Under_x, Hit_Under_y);		//左足元
	//動かせるボックスかどうか知るための色を取得_________________________
	g_Player.Move_Hit1 = GetPointColor(Move_Hitx1, g_Player.y + 20);		//プレイヤーの中心座標からむいている方向の50加減算した値の色を取得
	g_Player.Move_Hit2 = GetPointColor(Move_Hitx2, g_Player.y + 20);		//プレイヤーの中心座標からむいている方向の50加減算した値の色を取得


	//当たり判定の可視化_____________________________________________________________________
	//DrawBox(g_Player.x - 5, Hit_Up_y - 5, g_Player.x + 5, Hit_Up_y + 5, 0xfe00fe, FALSE);	//頭上
	//DrawBox(Hit_R_x - 5, Hit_UpLR_y - 5, Hit_R_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//右上
	//DrawBox(Hit_R_x - 5, Hit_UnderLR_y - 5, Hit_R_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//右下
	//DrawBox(Hit_L_x - 5, Hit_UpLR_y - 5, Hit_L_x + 5, Hit_UpLR_y + 5, 0xfe00fe, FALSE);	//左上
	//DrawBox(Hit_L_x - 5, Hit_UnderLR_y - 5, Hit_L_x + 5, Hit_UnderLR_y + 5, 0xfe00fe, FALSE);	//左下
	//DrawBox(g_Player.x - 5 + Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 + Hit_Under_x, Hit_Under_y + 5, 0xfe00fe, FALSE);	//足元右
	//DrawBox(g_Player.x - 5 - Hit_Under_x, Hit_Under_y - 5, g_Player.x + 5 - Hit_Under_x, Hit_Under_y + 5, 0xfe00fe, FALSE);	//足元左
	//DrawBox(g_Player.PickUpPixel - 5, g_Player.PickUpPixely - 5, g_Player.PickUpPixel + 5, g_Player.PickUpPixely + 5, 0xff00ff, FALSE);
	//DrawBox(Move_Hitx1 - 5, g_Player.y + 20 - 5, Move_Hitx1 + 5, g_Player.y + 20 + 5, 0xfe00fe, FALSE);	//動くブロックの取得位置右
	//DrawBox(Move_Hitx2 - 5, g_Player.y + 20 - 5, Move_Hitx2 + 5, g_Player.y + 20 + 5, 0xfe00fe, FALSE);	//動くブロックの取得位置左

	//DrawBox(Hit_R_x - 5, Hit_UpLR_y - 50 - 5, Hit_R_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//右頭
	//DrawBox(Hit_L_x - 5, Hit_UpLR_y - 50 - 5, Hit_L_x + 5, Hit_UpLR_y - 50 + 5, 0xfe00fe, FALSE);	//右頭

	//当たり判定のフラグ管理_____________________________________
	//右行ってヨシ！
	bool RightOK = g_Player.NowColor != g_Player.Hit_RightUp && g_Player.NowColor != g_Player.Hit_RightUnder && g_Player.NowColor != g_Player.Hit_Rght_High
		&& g_Player.Hit_RightUp != BLACK && g_Player.Hit_RightUnder != BLACK && g_Player.Hit_Rght_High != BLACK;
	//左行ってヨシ！
	bool LeftOK = g_Player.NowColor != g_Player.Hit_LeftUp && g_Player.NowColor != g_Player.Hit_LeftUnder && g_Player.NowColor != g_Player.Hit_Left_High
		&& g_Player.Hit_LeftUp != BLACK && g_Player.Hit_LeftUnder != BLACK && g_Player.Hit_Left_High != BLACK;

	/************************************************************************
	**
	**		プレイヤーの動き
	**
	*************************************************************************/
	if (g_Player.PLAYER_MENU == FALSE && g_Player.Hit_Up != g_Player.NowColor) {//メニュー画面を閉じているとき,色が重なっていないとき
		/************************************************************************
		*プレイヤーの移動処理
		*************************************************************************/
		if (g_Pad.KEY_RIGHT == TRUE || g_Pad.KEY_LEFT == TRUE)	//右か左に入力されていたら
		{
			//歩く時の音、マップ端を超えないようにする処理_______________________________________
			if (CheckSoundMem(g_Snd.Walk) == 0 && g_Player.PLAYER_JUMP == FALSE) {//音を鳴らす
				PlaySoundMem(g_Snd.Walk, DX_PLAYTYPE_BACK);
			}
			if (g_Player.x < g_MapC.X1) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、左端に到達
				g_Player.x = g_MapC.X1;
			}
			if (g_Player.x > g_MapC.X2) {		//マップ端でプレイヤーが画面を少し超えてしまうのを防止、右端に到達
				g_Player.x = g_MapC.X2;
			}
			//_____________________________________________________________________________________

		/************************************************************************
		*当たり判定処理 & ボックスを動かす
		*************************************************************************/

		//右側の当たり判定処理______________________________________________________________
			if (RightOK == TRUE) {
				if (g_Pad.KEY_RIGHT)
					g_Player.x += PLAYERX;
				//ブロック動かす処理_____________________________________________________________
				if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit1 == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder
					&& g_Player.PLAYER_GROUND == TRUE) {//右側に動くブロックがあった時
					if (g_Pad.KEY_RIGHT == TRUE)
						MoveObjectValue(g_Player.NowColor);
				}
			}
			//ブロック動かす処理___________________________________________________________________
			else if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit1 == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder
				&& g_Player.PLAYER_GROUND == TRUE) {//右側に動くブロックがあった時
				if (g_Pad.KEY_LEFT == TRUE && g_Player.NowColor != g_Player.Hit_LeftUnder ||
					g_Pad.KEY_RIGHT == TRUE) {
					MoveObjectValue(g_Player.NowColor);
				}
			}


			//左側の当たり判定処理________________________________________________
			if (LeftOK == TRUE) {
				if (g_Pad.KEY_LEFT)
					g_Player.x -= PLAYERX;
				//ブロック動かす処理___________________________
				if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit2 == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder
					&& g_Player.PLAYER_GROUND == TRUE) {//左側に動くブロックがあった時
					if (g_Pad.KEY_LEFT == TRUE)
						MoveObjectValue(g_Player.NowColor);
				}
			}
			//ブロック動かす処理_________________________________________________
			else if (g_Pad.KEY_B == TRUE && g_Player.Move_Hit2 == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder
				&& g_Player.PLAYER_GROUND == TRUE) {//左側に動くブロックがあった時
				if (g_Pad.KEY_RIGHT == TRUE && g_Player.NowColor != g_Player.Hit_RightUnder ||
					g_Pad.KEY_LEFT == TRUE) {
					MoveObjectValue(g_Player.NowColor);
				}
			}
			//********************************************************************************************

			//箱を引きずる音を止める___________________________________________________
			if ((g_Pad.KEY_B == FALSE) && (CheckSoundMem(g_Snd.BoxDrag) == 1)) {
				StopSoundMem(g_Snd.BoxDrag);
			}
			//箱を動かしているフラグをリセットする____________________________________________
			if (CheckSoundMem(g_Snd.BoxDrag) == 0 
				&& (g_Player.PLAYER_MOVEBOX_PUSH == TRUE || g_Player.PLAYER_MOVEBOX_PULL == TRUE)) {
				g_Player.PLAYER_MOVEBOX_PUSH = FALSE;
				g_Player.PLAYER_MOVEBOX_PULL = FALSE;

			}
			//_________________________________________________________________________________________
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
		if (!((g_Player.Hit_Under == g_Player.NowColor || g_Player.Hit_Under2 == g_Player.NowColor) ||
			(g_Player.Hit_Under == BLACK || g_Player.Hit_Under2 == BLACK))) {
			g_Player.y += Gravity;		//プレイヤーに重力を追加
			g_Player.PLAYER_GROUND = FALSE;
		}
		else {
			JumpOkflag = 0;	//地面についているのでジャンプしていない
			g_Player.PLAYER_GROUND = TRUE;
		}
		DrawFormatString(0, 100, 0xff0fff, "Gravity %d ", Gravity);

	/************************************************************************
	*プレイヤーのジャンプ処理
	*************************************************************************/
		if ((g_Player.PLAYER_JUMP == TRUE && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) ||
			(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) || JumpOkflag == 1) {	//ジャンプボタンが押されたら
			Jumpcnt--;		//ジャンプアニメーションのカウント開始
			JumpOkflag = 1;	//一度ジャンプしたので終わるまでジャンプ処理
			if (Jumpcnt >= JumpMax) {//決められた時間までプレイヤーを上にあげる
				g_Player.y -= Jumpcnt;
			}
			if (Jumpcnt <= JumpMax && ((g_Player.Hit_Under == BLACK || g_Player.Hit_Under == g_Player.NowColor) ||
				(g_Player.Hit_Under2 == BLACK || g_Player.Hit_Under2 == g_Player.NowColor))) {		//ジャンプアニメーションが決められた時間になったとき
				g_Player.PLAYER_JUMP = FALSE;//ジャンプ処理の終了
				Jumpcnt = 20;				//ジャンプアニメーションのカウントを0にする
				PlaySoundMem(g_Snd.Landing, DX_PLAYTYPE_BACK);
			}
			if (g_Player.Hit_Up == BLACK) {	//プレイヤーが天井にぶつかった時,ジャンプ処理を終了する
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
	Change(g_Player.NowColor);//引数に色の名前/数字を入れて値を変更
	//														10フレームごとに、プレイヤーの動きに合わせて動かす
	DrawRotaGraph(g_Player.x, g_Player.y, 0.7, 0, g_pic.Player[animecnt / 9 % anime_motionMax + g_Player.Anime_Num + NoMove], TRUE, g_Player.PLAYER_DIRECTION);//プレイヤー画像の描画
	ColorReset();//画面全体の変色を元に戻す
	//_____________________________________________________________________________________________________________________
	return 0;
}