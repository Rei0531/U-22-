#include "LoadPic.h"
#include "Map.h"

int LoadPictue(void) {		//画像の読み込み

	if ((g_pic.Map = LoadGraph("image/マップ(仮）.png")) == -1) return -1;

	return 0;
}