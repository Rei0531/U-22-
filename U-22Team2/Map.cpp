#include "DxLib.h"
#include "Map.h"

image g_pic;

int Map(void) {
	DrawRotaGraph(1280/2, 768/2,1.0,0,g_pic.Map,TRUE,FALSE);//�}�b�v�摜�̕`��
	DrawPixel(320, 240, 0xffffff);  //�_��ł�
	DrawBox(100, 100, 300, 300, 0xffffff, TRUE);//�����l�p
	return 0;
}