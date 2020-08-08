#include "Color.h"
#include "DxLib.h"

void ColorReset() {
	SetDrawBright(255, 255, 255);
}		//輝度をデフォルトの値に戻す

void Change(int Color) {								//渡された色の輝度に設定する
	switch (Color) {
	case RED:
		SetDrawBright(255, 0, 0);
		break;
	case ORENGE:
		SetDrawBright(255, 165, 0);
		break;
	case YELLOW:
		SetDrawBright(255, 255, 0);
		break;
	case GREEN:
		SetDrawBright(0, 128, 0);
		break;
	case LIGHTBLUE:
		SetDrawBright(0, 255, 254);
		break;
	case BLUE:
		SetDrawBright(0, 0, 254);
		break;
	case PURPLE:
		SetDrawBright(128, 0, 128);
		break;
	case NONCOLOR:
		SetDrawBright(0, 0, 0);
		break;
	case WHITE:
		SetDrawBright(255, 255, 255);
		break;
	default:
		break;
	}
}

void Change2(int Color2) {								//渡された色の輝度に設定する(スポイトされない色）
	switch (Color2) {
	case RED2:
		SetDrawBright(253, 0, 0);		//253
		break;
	case ORENGE2:
		SetDrawBright(254, 165, 0);		//419
		break;
	case YELLOW2:
		SetDrawBright(254, 254, 0);		//508
		break;
	case GREEN2:
		SetDrawBright(0, 127, 0);		//127
		break;
	case LIGHTBLUE2:
		SetDrawBright(0, 254, 253);		//507
		break;
	case BLUE2:
		SetDrawBright(0, 0, 252);		//252
		break;
	case PURPLE2:
		SetDrawBright(128, 0, 122);		//250
		break;
	case NONCOLOR2:
		SetDrawBright(3, 3, 3);
		break;
	default:
		break;
	}
}