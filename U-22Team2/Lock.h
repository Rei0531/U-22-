#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//ノブも含めた鍵穴に必要な変数
public:
	int color[2][3]{		//ノブと鍵の穴		//0：ノブ　１～鍵穴

		{BLUE},		//ステージ１
		{LIGHTBLUE,BLUE, RED}

	};
	int colorback[2][3]{		//鍵穴のバックアップバックアップ

		{BLUE},
		{LIGHTBLUE,BLUE, RED}


	};

	int n[2]{ 1,3 };	//ノブと鍵穴の数
	int Release = 0; //鍵穴の解除数

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);