#pragma once
#include "DxLib.h"
//関数の宣言

enum Color {
	RED,			//0
	ORENGE,			//1
	YELLOW,			//2
	GREEN,			//3
	LIGHTBLUE,		//4
	BLUE,			//5
	PURPLE			//6
};

class ChangeColor {
public:
	void ColorReset() { SetDrawBright(255, 255, 255); }		//輝度をデフォルトの値に戻す
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
		default:
			break;
		}
	}
}; ChangeColor CC;


//関数の定義

