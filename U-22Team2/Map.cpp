#include "DxLib.h"
#include "Map.h"

extern MapCoordinate MapC;
MapCoordinate MapC;
image g_pic;

int Map(void) {
	DrawBox(0, 0, 1280, 768, 0xffffff, TRUE);//�����l�p
	//DrawRotaGraph(1280/2, 768/2,1.0,0,g_pic.Map,TRUE,FALSE);//�}�b�v�摜�̕`��
	DrawExtendGraph(MapC.X1, MapC.Y1, MapC.X2, MapC.Y2, g_pic.Map, TRUE);
	//DrawPixel(320, 240, 0xffffff);  //�_��ł�
	return 0;
}