#include "Map.h"
#include"Stage_ALL.h"
#include "Color.h"
#include"Door.h"
#include "Lock.h"

//MapCoordinate g_MapC;
extern MapCoordinate g_MapC;

int Stage1(void) {			//�}�b�v�摜�̕`��

	DrawExtendGraph(g_MapC.X1, g_MapC.Y1, g_MapC.X2, g_MapC.Y2, g_pic.Map, TRUE);	//�}�b�v�̕`��
	//�F�u���b�N�`��
	//Change(BLUE);
	//DrawBox(800, 0, 1000, 668, GetColor(255, 255, 255), TRUE);//��
	//Change(RED);
	//DrawBox(700, 550, 750, 668, GetColor(255, 255, 255), TRUE);//��
	//Change(GREEN);
	//DrawBox(1000, 550, 1050, 668, GetColor(255, 255, 255), TRUE);//��
	Change(BLUE);
	DrawBox(400, 0, 500, 668, GetColor(255, 255, 255), TRUE);//��
	Change(RED);
	DrawBox(500, 0, 600, 668, GetColor(255, 255, 255), TRUE);//��
	Change(LIGHTBLUE);
	DrawBox(600, 0, 700, 668, GetColor(255, 255, 255), TRUE);//��
	Door();			//�X�e�[�W�S�[������
	Lock();
	ColorReset();

	return 0;
}