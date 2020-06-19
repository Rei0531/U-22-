#include "DxLib.h"
#include "Enemy.h"
#include "Map.h"

extern MapCoordinate g_MapC;

int Enemy(void) {
	//テスト用コメント
	DrawRotaGraph(2700 + g_MapC.X1, 370, 1.0, 0, g_pic.Enemy[0], TRUE, FALSE);

	return 0;
}