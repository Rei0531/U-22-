#include "LoadPic.h"
#include "Map.h"

int LoadPictue(void) {		//�摜�̓ǂݍ���

	if ((g_pic.Map = LoadGraph("image/�}�b�v.png")) == -1) return -1;

	if (LoadDivGraph("image/mouse.png", 3, 3, 1, 200,100 , g_pic.Player) == -1) return -1;
	
	return 0;
}