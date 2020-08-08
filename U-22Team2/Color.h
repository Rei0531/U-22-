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

enum Color2 {		//プレイヤーにスポイトされない色
	RED2,			//0
	ORENGE2,		//1
	YELLOW2,		//2
	GREEN2,			//3
	LIGHTBLUE2,		//4
	BLUE2,			//5
	PURPLE2,		//6
	BLACK2,			//7
	NONCOLOR2,		//8
};

void Change(int Color);
void Change2(int Color2); //プレイヤーにスポイトされない色
void ColorReset();




//関数の定義

