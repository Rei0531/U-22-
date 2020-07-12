#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Controller.h"
#include "Map.h"
#include "Color.h"
#include "Object.h"

struct DoorAll {			//�h�A�ɕK�v�ȕϐ�
public:

	//�h�A�̍��W
	int x = 1150;		//�����W
	int y = 400;		//�c���W
	int w = 1250;		//�������W
	int h = 668;		//�c�����W

	int Rotation[4][4]{			//�X�e�[�W���Ƃ̃h�A�̃��[�e�[�V����

		{BLUE,LIGHTBLUE,RED},		//�X�e�[�W�P�̃h�A�̃��[�e�[�V�����̏���
		{BLUE,LIGHTBLUE,RED},		//�X�e�[�W2�̃h�A�̃��[�e�[�V�����̏���
		{ORENGE,YELLOW,PURPLE},		//�X�e�[�W3�̃h�A�̃��[�e�[�V�����̏���
		{BLUE}
	};		//���[�e�[�V�����̔z��

	int ColorNumber[4]{ 3,3,3,1 };			//�X�e�[�W���Ƃ̃h�A�̃��[�e�[�V�����̐�

	int RotationNumber = 0;			//���݂̃��[�e�[�V�����ʒu
	

	bool
		Picupflg = FALSE;			//�X�|�C�g�t���O
};



int Door(void);					//�h�A�Ɋւ��邷�ׂĂ̊֐����܂Ƃ߂�֐�(��`�j
int DoorRotation(void);			//�h�A�̐F�̃��[�e�[�V�����̏���(��`�j