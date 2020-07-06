#include "Player.h"
#include "Color.h"
#include"Door.h"
#include"Interact.h"

extern Player g_Player;
extern DoorAll g_Door;
static int SaveColor = 99;		//一時変数に現在の色を格納する

int GetPointColor(int Point_x, int Point_y) {	//渡された座標の色を取得して返す
	int color, r, g, b;
	int getcolor = 99;		//今取得する色格納変数

	color = GetPixel(Point_x, Point_y);		//スポイトする/引数はスポイトする場所
	GetColor2(color, &r, &g, &b);							//スポイトした色をR,G,B値に直す
	SaveColor;
	switch (r + g + b) {		//R,G,Bの合計で区別する/スポイトした色をreturnで返す
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
	case WHITE:
		getcolor = WHITE;
		break;
	default:
		break;
	}
	if (g_Player.PLAYER_PICKUP == TRUE) {//スポイトされたとき
		g_Player.PLAYER_PICKUP = FALSE;			//TRUEになってこの関数に入るから一度だけの処理にするためにスポイトフラグをFALSEにする
		if ((g_Player.Hit_Up == getcolor) | (SaveColor == getcolor)) {
			g_Door.Picupflg = FALSE;	//スポイトした色がプレイヤーと同色ならFALSEにする
		}
		if (g_Player.Hit_Up == getcolor) {
			Interact(FALSE);
			return SaveColor; //プレイヤーが重なっている置の色と取得した色が同じだった時//現在の色を返す
		}
		if (SaveColor != getcolor) {
			Interact(TRUE);
		}
		else {
			Interact(FALSE);
		}
	}

	if (SaveColor != getcolor) {//現在の色と取得した色が違うとき
		//インタラクトした処理を描く
		return getcolor;		//取得した色を返す
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