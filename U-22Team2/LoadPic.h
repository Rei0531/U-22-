#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//���C���ƂȂ�}�b�v�摜
	int Player[5];		//��l���̃l�Y�~�̉摜
	int Object[10];		//�I�u�W�F�N�g�摜
	int Title;			//�^�C�g���摜
	int StageClear;		//�X�e�[�W�̃N���A�摜

	int Box;//�I�u�W�F�N�g�̖؂̔�
	int Pin;//�F������ꏊ�̃s��
};

int LoadPictue(void);	//�֐��̒�`
