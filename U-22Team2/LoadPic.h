#pragma once
#include "DxLib.h"
struct image {
public:
	int Map;		//���C���ƂȂ�}�b�v�摜
	int Player[20];		//�X�|�C�g�}���̉摜
	int Object[10];		//�I�u�W�F�N�g�摜
	int Title;			//�^�C�g���摜
	int StageClear;		//�X�e�[�W�̃N���A�摜
	int TitleChar[3];	//�^�C�g���̕���

	int Box;//�I�u�W�F�N�g�̖؂̔�
	int Pin;//�F������ꏊ�̃s��
	int Box_Move;//������

	int shower;//�V�����[�̉摜
	int shower_m; //�V�����[�̐��摜

	int Reba;//���o�[

	int C_Switch;//�F�𔽉f����X�C�b�`
	int Rot_Box;//���[�e�[�V��������{�b�N�X

	int OneTimeSwitch_ON;//��x����̃X�C�b�`ON�̉摜
	int OneTimeSwitch_OFF;//��x����̃X�C�b�`OFF�̉摜
	int Bomb;			//���e�̉摜

	int Warp_Area;

	int ChengObject[3];  //�ό`����I�u�W�F�N�g

	int item;	//�X�|�C�g�񕜃A�C�e��
};

int LoadPictue(void);	//�֐��̒�`
