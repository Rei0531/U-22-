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
	int t = 500;		//�h�A�̈ړ�

	int Rotation[30][5]{			//�X�e�[�W���Ƃ̃h�A�̃��[�e�[�V����

		{BLUE,LIGHTBLUE,RED},		//�X�e�[�W�P�̃h�A�̃��[�e�[�V�����̏���
		{BLUE,LIGHTBLUE,RED},		//�X�e�[�W�Q�̃h�A�̃��[�e�[�V�����̏���
		{ORENGE,YELLOW,PURPLE},		//�X�e�[�W�R�̃h�A�̃��[�e�[�V�����̏���
		{BLUE},						//�X�e�[�W�S�̃h�A�̃��[�e�[�V�����̏���
		{BLUE},						//�X�e�[�W�T�̃h�A�̃��[�e�[�V�����̏���
		{RED,BLUE},					//�X�e�[�W�U�̃h�A�̃��[�e�[�V�����̏���
		{YELLOW,PURPLE,BLUE,RED},	//�X�e�[�W�V�̃h�A�̃��[�e�[�V�����̏���
		{GREEN,RED},				//�X�e�[�W8�̃h�A�̃��[�e�[�V�����̏���
		{RED,GREEN},				//�X�e�[�W9�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W10�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W11�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W12�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W13�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W14�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W15�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W16�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W17�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W18�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W19�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W20�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W21�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W22�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W23�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W24�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W25�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W26�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W27�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W28�̃h�A�̃��[�e�[�V�����̏���
		{RED},						//�X�e�[�W29�̃h�A�̃��[�e�[�V�����̏���
		{RED}						//�X�e�[�W30�̃h�A�̃��[�e�[�V�����̏���
	};		//���[�e�[�V�����̔z��

	int ColorNumber[30]{ 3,3,3,1,1,1,4 ,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};			//�X�e�[�W���Ƃ̃h�A�̃��[�e�[�V�����̐�

	int RotationNumber = 0;			//���݂̃��[�e�[�V�����ʒu


	bool
		Picupflg = FALSE;			//�X�|�C�g�t���O
};



int Door(void);					//�h�A�Ɋւ��邷�ׂĂ̊֐����܂Ƃ߂�֐�(��`�j
int DoorRotation(void);			//�h�A�̐F�̃��[�e�[�V�����̏���(��`�j
