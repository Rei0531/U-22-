#pragma once
#include "DxLib.h"
//ŠÖ”‚ÌéŒ¾

enum Color {
	RED,			//0
	GREEN,			//1
	BLUE			//2
};

class ChangeColor {
public:
	void ColorReset() { SetDrawBright(255, 255, 255); }
	void Change(int Color) {
		switch (Color) {
		case RED:
			SetDrawBright(255, 0, 0);
			break;
		case GREEN:
			SetDrawBright(0, 255, 0);
			break;
		case BLUE:
			SetDrawBright(0, 0, 255);
			break;
		default:
			break;
		}
	}
}; ChangeColor CC;


//ŠÖ”‚Ì’è‹`

