#pragma once
#include "LoadPic.h"
#include "constant.h"
extern image g_pic;

struct MapCoordinate {			//�}�b�v�̃f�t�H���g�̍��W
public:
	int X1 = 0;
	int X2 = MAP_WIDHT;
	int Y1 = 0;
	int Y2 = MAP_HEIGHT;

	int StageNumber = 3;
}; extern MapCoordinate g_MapC;

int Map(void);		//�֐��̒�`
//int GameInit(void);		//�֐��̒�`�@������