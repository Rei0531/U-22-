#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//�Q�[���J�n���W
	int y = 581;			//�Q�[���J�n���W
	int PickUpPixel;		//�X�|�C�g���Ă���ꏊ

	bool PLAYER_DIRECTION,	//�v���C���[�̌���//TRUE������/FALSE�E����
		PLAYER_JUMP,		//�v���C���[���W�����v������
		PLAYER_PICKUP,		//�X�|�C�g
		PLAYER_ACTION,		//�A�N�V�����{�^��
		PLAYER_MENU;		//���j���[
};


int PlayerDraw(void);	//�֐��̒�`
