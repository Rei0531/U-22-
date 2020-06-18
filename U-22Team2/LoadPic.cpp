#include "LoadPic.h"
#include "Map.h"
#include"Enemy.h"

int LoadPictue(void) {		//‰æ‘œ‚Ì“Ç‚İ‚İ
	if ((g_pic.Map = LoadGraph("image/map.png")) == -1) return -1;
	if (LoadDivGraph("image/mouse.png", 3, 3, 1, 200, 100, g_pic.Player) == -1) return -1;

	if ((g_pic.Enemy[0] = LoadGraph("image/Enemy(‰¼).jpg")) == -1)return -1;
	if ((g_pic.Enemy[1] = LoadGraph("image/Enemy(‰¼).jpg")) == -1)return -1;
	if ((g_pic.Enemy[2] = LoadGraph("image/Enemy(‰¼).jpg")) == -1)return -1;
	if ((g_pic.Enemy[3] = LoadGraph("image/Enemy(‰¼).jpg")) == -1)return -1;
	if ((g_pic.Enemy[4] = LoadGraph("image/Enemy(‰¼).jpg")) == -1)return -1;
	return 0;
}