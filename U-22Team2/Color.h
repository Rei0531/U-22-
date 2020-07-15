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
	PURPLE,			//6
	BLACK,			//7
	NONCOLOR,		//8
	WHITE,			//9
	MOVE			//10/動かせるボックスの判定カラー
};

void Change(int Color);
void ColorReset();




//関数の定義

