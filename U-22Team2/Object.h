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
};

void MoveObjectValue(int P_Color);//�I�u�W�F�N�g���Ƃ̈ړ��ʂ�Ԃ�
int GetObjectColor(void);
int GetPointColor(int Point_x,int Point_y);
