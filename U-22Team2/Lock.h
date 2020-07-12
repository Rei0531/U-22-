#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//ノブも含めた鍵穴に必要な変数
public:
	//右の[]がステージ数、左の[]がノブ、鍵穴の数
	int color[4][3]{		//ノブと鍵の穴		//0：ノブ　１～鍵穴

		{BLUE},							//ステージ１
		{LIGHTBLUE,BLUE, RED},			//ステージ２
		{BLUE,YELLOW,PURPLE},			//ステージ３
		{RED}							//ステージ４
	};
	int colorback[4][3]{		//鍵穴のバックアップバックアップ

		{BLUE},							//ステージ１
		{LIGHTBLUE,BLUE, RED},			//ステージ２
		{ORENGE,YELLOW,PURPLE},			//ステージ３
		{RED}							//ステージ4
	};
	//ステージ数/ノブ、鍵穴の合計
	//	　↓	↓
	int n[4]{ 1,3,3,1 };	//ノブと鍵穴の数	//ステージ数と、ノブ、鍵穴の合計数を上の数に合わせる
	int Release = 0; //鍵穴の解除数

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);