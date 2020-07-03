#include "Player.h"
#include "Color.h"

extern Player g_Player;
static int SaveColor = 99;		//一時変数に現在の色を格納する

int GetPointColor(int Point_x, int Point_y) {	//渡された座標の色を取得して返す
	int color, r, g, b;
	int GetColor = 99;		//今取得する色格納変数

	color = GetPixel(Point_x, Point_y);		//スポイトする/引数はスポイトする場所
	GetColor2(color, &r, &g, &b);							//スポイトした色をR,G,B値に直す
	SaveColor;
	switch (r + g + b) {		//R,G,Bの合計で区別する/スポイトした色をreturnで返す
	case 255:
		GetColor = RED;
		break;
	case 420:
		GetColor = ORENGE;
		break;
	case 510:
		GetColor = YELLOW;
		break;
	case 128:
		GetColor = GREEN;
		break;
	case 509:
		GetColor = LIGHTBLUE;
		break;
	case 254:
		GetColor = BLUE;
		break;
	case 256:
		GetColor = PURPLE;
		break;
	case 0:
		GetColor = BLACK;
		break;
	default:
		break;
	}
	if (g_Player.PLAYER_PICKUP == TRUE) {//スポイトされたとき
		g_Player.PLAYER_PICKUP = FALSE;			//TRUEになってこの関数に入るから一度だけの処理にするためにスポイトフラグをFALSEにする
		if (g_Player.Hit_Up == GetColor)return SaveColor; //プレイヤーの頭の位置の色と取得した色が同じだった時//現在の色を返す
	}
	if (SaveColor != GetColor) {//現在の色と取得した色が違うとき
		//インタラクトした処理を描く
		return GetColor;		//取得した色を返す
	}
	else {
		//インタラクトしていない処理を描く
		return SaveColor;//同じ色の場合は元の色を返す
	}
}

int GetObjectColor(void) {
	//プレイヤーの向いている方向より+-50したところか色を取得する
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 50 : g_Player.x + 50;//スポイトする場所
	SaveColor = g_Player.NowColor;		//一時変数に現在の色を格納する

	return GetPointColor(g_Player.PickUpPixel, g_Player.y);
}