#include "Map.h"
#include "Color.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;

int Stage1(void) {			//�}�b�v�摜�̕`��

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��
	Change(BLUE);
	DrawBox(800, 0, 1000, 668, GetColor(255, 255, 255), TRUE);//��
	Change(RED);
	DrawBox(700, 550, 750, 668, GetColor(255, 255, 255), TRUE);//��
	ColorReset();

	return 0;
}