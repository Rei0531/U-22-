#pragma once
#include"LoadPic.h"
#include"constant.h"

extern image g_pic;

struct EnemyCoordinate {			//�G�̃f�t�H���g�̍��W
public:
	int X1 = MAP_WIDHT - 50;		//�G�摜��x���W�̍��[ -50�͉摜�̉��̕�
	int X2 = MAP_WIDHT;				//�G�摜��x���W�̉E�[
	int Y1 = 0;						//�G�摜��y���W�̏�[
	int Y2 = SCREEN_HEIGHT;			//�G�摜��y���W�̉��[
}; extern EnemyCoordinate g_EnmC;
int Enemy(void);		//�֐��̒�`