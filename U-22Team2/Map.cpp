#include "DxLib.h"
#include "Map.h"

image g_pic;

int Map(void) {
	DrawRotaGraph(1280/2, 768/2,1.0,0,g_pic.Map,TRUE,FALSE);//マップ画像の描画
	DrawPixel(320, 240, 0xffffff);  //点を打つ
	DrawBox(100, 100, 300, 300, 0xffffff, TRUE);//白い四角
	return 0;
}