#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"

struct DoorAll {			//�h�A�ɕK�v�ȕϐ�
public:

	int x = 1150;		//�����W
	int y = 400;		//�c���W
	int w = 1250;		//�������W
	int h = 668;		//�c�����W

	int Rotation[1][3]{			//�h�A�̃��[�e�[�V����

		{RED,BLUE,PURPLE}		//�X�e�[�W�P�̃h�A�̃��[�e�[�V�����̏���

	};		//���[�e�[�V�����̔z��
	int RotationNumber = 0;			//���[�e�[�V�����ʒu

	bool
		Picupflg = FALSE;			//�X�|�C�g�t���O
};


int Door(void);					//�h�A�Ɋւ��邷�ׂĂ̊֐����܂Ƃ߂�֐�(��`�j
int DoorRotation(void);			//�h�A�̐F�̃��[�e�[�V�����̏���(��`�j
