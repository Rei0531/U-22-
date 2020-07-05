#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//ノブも含めた鍵穴に必要な変数
public:
	int color[1][3]{		//ノブと鍵の穴

		{GREEN,BLUE, RED}		//0：ノブ　１、２：鍵穴

	};
	int n[1]{ 3 };	//ノブと鍵穴の数
	int Release = 0; //鍵穴の解除数


};

int Lock(void);
int UnLock(void);
