#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;

int Stage2(void) {			//�}�b�v�摜�̕`��

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��
	//Change(BLUE);
	//DrawBox(400, 0, 500, 668, GetColor(255, 255, 255), TRUE);//��
	//Change(RED);
	//DrawBox(500,0,600,668,GetColor(255,255,255),TRUE);//��
	//Change(GREEN);
	//DrawBox(600, 0, 700, 668, GetColor(255, 255, 255), TRUE);//��
	Door();
	ColorReset();

	return 0;
}