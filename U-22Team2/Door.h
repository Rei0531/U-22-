#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"

struct DoorAll {			//ドアに必要な変数
public:

	//ドアの座標
	int x = 1150;		//横座標
	int y = 400;		//縦座標
	int w = 1250;		//横幅座標
	int h = 668;		//縦幅座標

	int Rotation[1][4]{			//ステージごとのドアのローテーション

		{BLUE,LIGHTBLUE,RED}		//ステージ１のドアのローテーションの順番

	};		//ローテーションの配列

	int ColorNumber[1]{ 3 };			//ステージごとのドアのローテーションの数

	int RotationNumber = 0;			//現在のローテーション位置
	

	bool
		Picupflg = FALSE;			//スポイトフラグ
};



int Door(void);					//ドアに関するすべての関数をまとめる関数(定義）
int DoorRotation(void);			//ドアの色のローテーションの処理(定義）
