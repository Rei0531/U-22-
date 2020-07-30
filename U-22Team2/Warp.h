#pragma once
#include "LoadPic.h"
#include "constant.h"

struct WarpFunction {			//マップのデフォルトの座標
public:
	int WarpX1 = 0;
	int WarpX2 = 100;
	int WarpY1 = 0;
	int WarpY2 = 100;

}; extern WarpFunction g_WarpF;
int Warp(void);