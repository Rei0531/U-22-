#include "LoadPic.h"
#include "Map.h"

int LoadPictue(void) {		//�摜�̓ǂݍ���

	if ((g_pic.Map = LoadGraph("image/�}�b�v(���j.png")) == -1) return -1;

	return 0;
}