#pragma once
#include "LoadPic.h"
extern image g_pic;

struct MapCoordinate {			//�}�b�v�̃f�t�H���g�̍��W
public:
	int X1 = 0;	
	int X2 = 5120;
	int Y1 = -1536;
	int Y2 = 768;
}; extern MapCoordinate g_MapC;

int Map(void);		//�֐��̒�`
