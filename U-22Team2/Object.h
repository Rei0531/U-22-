#pragma once
#include "DxLib.h"

struct Object {//�I�u�W�F�N�g�̕ϐ�
public:
	int Move_x = 0;//�I�u�W�F�N�g�𓮂����Ƃ��̃v���X����x���W

	//�F���Ƃ̃I�u�W�F�N�g�ړ��ʕϐ�
	int RED_x = 0,
		ORENGE_x = 0,
		YELLOW_x = 0,
		GREEN_x = 0,
		LIGHTBLUE_x = 0,
		BLUE_x = 0,
		PURPLE_x = 0;

	void Init() {
		RED_x = 0;
		ORENGE_x = 0;
		YELLOW_x = 0;
		GREEN_x = 0;
		LIGHTBLUE_x = 0;
		BLUE_x = 0;
		PURPLE_x = 0;
	}

	int PixelColor4,	//���S����	  _l	    4��	  _l
		PixelColor3,	//���S����	  l 3��			_l
		PixelColor2,	//�w�̒��S	  l   2 ��	�@_l
		PixelColor1,	//���S����	  l 	1��  _l
		PixelColor;		//�w��		  l��_______l
};

void MoveObjectValue(int P_Color);//�I�u�W�F�N�g���Ƃ̈ړ��ʂ�Ԃ�
int GetObjectColor(void);
int GetPointColor(int Point_x,int Point_y);
