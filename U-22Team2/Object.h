#pragma once
#include "DxLib.h"
#include "Player.h"

extern Player g_Player;

int GetObjectFlag();

int GetObjectFlag() {
	g_Player.PLAYER_PICKUP = FALSE;			//スポイトフラグをFALSEにする
	//プレイヤーの向いている方向より+-50したところか色を取得する
	g_Player.PickUpPixel = (g_Player.PLAYER_DIRECTION) ? g_Player.x - 50 : g_Player.x + 50;

	int color, r, g, b;
	int ret;

	DrawBox(g_Player.PickUpPixel-5, g_Player.y-5, g_Player.PickUpPixel+5, g_Player.y+5, 0xff00ff,FALSE);	//スポイトしている場所の四角表示

	color = GetPixel(g_Player.PickUpPixel, g_Player.y);		//スポイトする/引数はスポイトする場所
	GetColor2(color, &r, &g, &b);
	switch (r+g+b) {
	case 255:
		ret = 0;
		return  RED;
		break;
	case 420:
		ret = 1;
		return ORENGE;
		break;
	case 510:
		ret = 2;
		return YELLOW;
		break;
	case 128:
		ret = 3;
		return GREEN;
		break;
	case 509:
		ret = 4;
		return LIGHTBLUE;
		break;
	case 254:
		ret = 5;
		return BLUE;
		break;
	case 256:
		ret = 6;
		return PURPLE;
		break;
	default:
		ret = 99;
		return 99;
		break;
	}
	DrawFormatString(0, 40, 0xff0000, "色番号 %d ", ret);

	return -1;
}
