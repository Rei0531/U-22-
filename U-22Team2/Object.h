#pragma once
#include "DxLib.h"
#include "Player.h"

extern Player g_Player;

int GetObjectColor();
int GetPointColor(int Point_x,int Point_y);

int GetPointColor(int Point_x, int Point_y) {	//渡された座標の色を取得して返す
	int color, r, g, b;
	color = GetPixel(Point_x, Point_y);		//スポイトする/引数はスポイトする場所
	GetColor2(color, &r, &g, &b);							//スポイトした色をR,G,B値に直す
	switch (r + g + b) {		//R,G,Bの合計で区別する/スポイトした色をreturnで返す
	case 255:
		return  RED;
		break;
	case 420:
		return ORENGE;
		break;
	case 510:
		return YELLOW;
		break;
	case 128:
		return GREEN;
		break;
	case 509:
		return LIGHTBLUE;
		break;
	case 254:
		return BLUE;
		break;
	case 256:
		return PURPLE;
		break;
	default:
		return 99;
		break;
	}
}

int GetObjectColor() {
	g_Player.PLAYER_PICKUP = FALSE;			//TRUEになってこの関数に入るから一度だけの処理にするためにスポイトフラグをFALSEにする
	//プレイヤーの向いている方向より+-50したところか色を取得する
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 50 : g_Player.x + 50;//スポイトする場所

	return GetPointColor(g_Player.PickUpPixel, g_Player.y);
}
