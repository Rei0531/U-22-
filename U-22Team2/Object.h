#pragma once
#include "DxLib.h"

struct Object {//オブジェクトの変数
public:
	int Move_x = 0;//オブジェクトを動かすときのプラスするx座標

	//色ごとのオブジェクト移動量変数
	int RED_x = 0,
		ORENGE_x = 0,
		YELLOW_x = 0,
		GREEN_x = 0,
		LIGHTBLUE_x = 0,
		BLUE_x = 0,
		PURPLE_x = 0;

	void Init() {
		RED_x = 0;
		ORENGE_x = 0;
		YELLOW_x = 0;
		GREEN_x = 0;
		LIGHTBLUE_x = 0;
		BLUE_x = 0;
		PURPLE_x = 0;
	}
};

void MoveObjectValue(int P_Color);//オブジェクトごとの移動量を返す
int GetObjectColor(void);
int GetPointColor(int Point_x,int Point_y);
