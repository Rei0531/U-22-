#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//�Q�[���J�n���W
	int y = 581;			//�Q�[���J�n���W
	bool PLAYER_DIRECTION,	//�v���C���[�̌���
		PLAYER_JUMP,		//�v���C���[���W�����v������
		PLAYER_SQUAT,		//���Ⴊ��
		PLAYER_ACTION,		//�A�N�V�����{�^��
		PLAYER_MENU;		//���j���[
};


int PlayerDraw(void);	//�֐��̒�`
