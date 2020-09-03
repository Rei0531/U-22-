#include "Player.h"
#include "Color.h"
#include"Door.h"
#include"Interact.h"
#include "Object.h"
#include "Controller.h"
#include "LoadSound.h"

extern Player g_Player;
extern DoorAll g_Door;
extern Object g_Object;
extern Controller g_Pad;
extern Sound g_Snd;

static int SaveColor = 99;		//一時変数に現在の色を格納する

/************************************************************************
*渡された座標の色を取得して返す
*************************************************************************/
int GetPointColor(int Point_x, int Point_y) {
	int color, r, g, b;
	int getcolor = 9;		//今取得する色格納変数

	//当たり判定の場所の色を取得******************************************************************************
	color = GetPixel(Point_x, Point_y);		//スポイトする/引数はスポイトする場所
	GetColor2(color, &r, &g, &b);							//スポイトした色をR,G,B値に直す
	int colorsum = r + g + b;
	//********************************************************************************************************

	switch (colorsum) {		//R,G,Bの合計で区別する/スポイトした色をreturnで返す
	case 255:
		getcolor = RED;
		break;
	case 420:
		getcolor = ORENGE;
		break;
	case 510:
		getcolor = YELLOW;
		break;
	case 128:
		getcolor = GREEN;
		break;
	case 509:
		getcolor = LIGHTBLUE;
		break;
	case 254:
		getcolor = BLUE;
		break;
	case 256:
		getcolor = PURPLE;
		break;
	case 0:
		getcolor = BLACK;
		break;
	case 765:
		getcolor = WHITE;
		break;
	//MOVEの値をとるためにRGB値が６以下の時の条件にしたいけど、やり方考えるの面倒だからいつか直す
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		getcolor = MOVE;
		break;
	default:
		//getcolor = SaveColor;
		break;
	}

	//スポイトされたとき********************************************************************************************************
	if (g_Player.PLAYER_PICKUP == TRUE) {
		g_Player.PLAYER_PICKUP = FALSE;			//TRUEになってこの関数に入るから一度だけの処理にするためにスポイトフラグをFALSEにする
		//if (g_Object.PixelColor1 != WHITE)g_Object.PixelColor = g_Object.PixelColor1;
		//if (g_Object.PixelColor4 != WHITE)g_Object.PixelColor = g_Object.PixelColor4;
		//if (g_Object.PixelColor2 != WHITE)g_Object.PixelColor = g_Object.PixelColor2;
		//if (g_Object.PixelColor3 != WHITE)g_Object.PixelColor = g_Object.PixelColor3;

		if ((g_Player.Hit_Up == getcolor) || (SaveColor == getcolor) || (getcolor == WHITE) || (getcolor == BLACK)) {
			g_Door.Picupflg = FALSE;	//スポイトした色がプレイヤーと同色ならFALSEにする
		}
		//プレイヤーが重なっている位置の色と取得した色が同じだった時、取得した色が白色の時,黒色の時、ドアの位置の時
		if (getcolor == WHITE || getcolor == BLACK || getcolor == MOVE || g_Player.Interact <= 0 || 
			(g_Door.x <= g_Player.PickUpPixel && g_Door.w >= g_Player.PickUpPixel &&
				g_Door.y <= g_Player.PickUpPixely && g_Door.h >= g_Player.PickUpPixely)) {
			Interact(FALSE);//スポイト失敗
			g_Door.Picupflg = FALSE;	//スポイトした色がプレイヤーと同色ならFALSEにする
			return SaveColor; //現在の色を返す
		}
		if (SaveColor != getcolor) {//取得した色が現在持っている自身の色と違う時
			g_Door.Picupflg = TRUE;				//ドアのローテーションためのスポイトのフラグをTRUEにする
			Interact(TRUE);//スポイト成功
			//g_Player.NowColor = g_Object.PixelColor;//変数にスポイトした色を格納する
		}
		else {
			Interact(FALSE);
		}
	}
	//********************************************************************************************************

	if (SaveColor != getcolor) {//現在の色と取得した色が違うとき
		//インタラクトした処理を描く
		return getcolor;		//取得した色を返す
	}
	else {
		//インタラクトしていない処理を描く
		return SaveColor;//同じ色の場合は元の色を返す
	}
}
/************************************************************************
*スポイト処理
*************************************************************************/
int GetObjectColor(void) {
	//プレイヤーの向いている方向より+-50したところか色を取得する
	//g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 40 : g_Player.x + 40;//スポイトする場所
	//g_Player.PickUpPixely = g_Player.y - 27;//初期値33もし白色が取れるようになってしまったら戻す
	SaveColor = g_Player.NowColor;		//一時変数に現在の色を格納する

	return GetPointColor(g_Player.PickUpPixel, g_Player.PickUpPixely);
}

/************************************************************************
*動くブロックの処理
*************************************************************************/
void MoveObjectValue(int P_Color) {
	
	int dir = 0;//向きによって*-1するからそのための変数

	//右に箱があった時______________________________________
	if (g_Player.Move_HitR == MOVE && g_Player.NowColor == g_Player.Hit_RightUnder) {
		//右に向かって動いていた時//押してるとき
		if (g_Player.PLAYER_DIRECTION == FALSE && g_Player.Move_BlackR != BLACK) {
			g_Player.PLAYER_MOVEBOX_PUSH = TRUE;//プレイヤーは押す動作をしている
			g_Player.PLAYER_MOVEBOX_PULL = FALSE;//引く動作のフラグをFALSEにする
			dir = 1;// (右向き)ならプラス
		}
		//左に向かって動いていた時//引いている時
		else if(g_Player.PLAYER_DIRECTION == TRUE && g_Player.Hit_LeftUnder != BLACK && g_Player.NowColor != g_Player.Hit_LeftUnder){
			g_Player.PLAYER_MOVEBOX_PULL = TRUE;//プレイヤーは引く動作をしている
			g_Player.PLAYER_MOVEBOX_PUSH = FALSE;//押す動作のフラグをFALSEにする
			dir = -1;//(左向き)ならマイナス
		}
	}

	//左に箱があった時______________________________________
	if (g_Player.Move_HitL == MOVE && g_Player.NowColor == g_Player.Hit_LeftUnder) {
		//左に向かって動いていた時//押してるとき
		if (g_Player.PLAYER_DIRECTION == TRUE&& g_Player.Move_BlackL != BLACK) {
			g_Player.PLAYER_MOVEBOX_PUSH = TRUE;//プレイヤーは押す動作をしている
			g_Player.PLAYER_MOVEBOX_PULL = FALSE;//引く動作のフラグをFALSEにする
			dir = -1;//(左向き)ならマイナス
		}
		//右に向かって動いていた時//引いてるとき
		else if(g_Player.PLAYER_DIRECTION == FALSE && g_Player.Hit_RightUnder != BLACK && g_Player.NowColor != g_Player.Hit_RightUnder){
			g_Player.PLAYER_MOVEBOX_PULL = TRUE;//プレイヤーは引く動作をしている
			g_Player.PLAYER_MOVEBOX_PUSH = FALSE;//押す動作のフラグをFALSEにする
			dir = 1;// (右向き)ならプラス
		}
	}

	if (g_Pad.KEY_LEFT || g_Pad.KEY_RIGHT) {
		switch (P_Color) {		//プレイヤーの色に合わせて動かすオブジェクトを決める
		case RED:
			g_Object.RED_x += PLAYERX * dir;
			break;
		case ORENGE:
			g_Object.ORENGE_x += PLAYERX * dir;
			break;
		case YELLOW:
			g_Object.YELLOW_x += PLAYERX * dir;
			break;
		case GREEN:
			g_Object.GREEN_x += PLAYERX * dir;
			break;
		case LIGHTBLUE:
			g_Object.LIGHTBLUE_x += PLAYERX * dir;
			break;
		case BLUE:
			g_Object.BLUE_x += PLAYERX * dir;
			break;
		case PURPLE:
			g_Object.PURPLE_x += PLAYERX * dir;
			break;
		default:
			break;
		}
	}
}