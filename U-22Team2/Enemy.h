#pragma once
#include"LoadPic.h"
#include"constant.h"

extern image g_pic;

struct EnemyCoordinate {			//敵のデフォルトの座標
public:
	int X1 = MAP_WIDHT - 50;		//敵画像のx座標の左端 -50は画像の仮の幅
	int X2 = MAP_WIDHT;				//敵画像のx座標の右端
	int Y1 = 0;						//敵画像のy座標の上端
	int Y2 = SCREEN_HEIGHT;			//敵画像のy座標の下端
}; extern EnemyCoordinate g_EnmC;
int Enemy(void);		//関数の定義