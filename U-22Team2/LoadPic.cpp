#include "LoadPic.h"
#include "Map.h"
#include"Enemy.h"

int LoadPictue(void) {		//画像の読み込み
	if ((g_pic.Map = LoadGraph("image/Stage_Deffault.jpg")) == -1) return -1;
	if (LoadDivGraph("image/Player.png", 5, 5, 1, 85, 179, g_pic.Player) == -1) return -1;

	if ((g_pic.Enemy[0] = LoadGraph("image/Enemy(仮).png")) == -1)return -1;
	//if ((g_pic.Enemy[1] = LoadGraph("image/Enemy(仮).jpg")) == -1)return -1;
	//if ((g_pic.Enemy[2] = LoadGraph("image/Enemy(仮).jpg")) == -1)return -1;
	//if ((g_pic.Enemy[3] = LoadGraph("image/Enemy(仮).jpg")) == -1)return -1;
	//if ((g_pic.Enemy[4] = LoadGraph("image/Enemy(仮).jpg")) == -1)return -1;
	return 0;
}