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
	int Menu;			//���j���[
	int MenuChar[3];	//���j���[�̕���
	int StageNum[30];	//�X�e�[�W�ԍ��̕���
	int Nokori[6];		//�c��񐔂̕���
	int Nokori_Num[10];	//�c��񐔂̐���
	int MenuBotan;		//���j���[�̃{�^������

	int Hand;			//�X�|�C�g�\��
	int Door_keyhole;	//����
	int Door_Nobu;		//�m�u
	int Door_Rotation[4];	//�h�A�̃��[�e�[�V����
	int Door_Rot_Yajirusi;	//�h�A�̃��[�e�[�V�������

	int Pin;//�F������ꏊ�̃s��

	int Select_Back;	//�Z���N�g��ʂ̑I�𒆂̂��


	int Box[3];//�F�X�ȃ{�b�N�X
	//int Box;//�I�u�W�F�N�g�̖؂̔�
	//int Box_Move;//������
	//int Box_Rot;//���[�e�[�V��������{�b�N�X

	int shower;//�V�����[�̉摜
	int shower_m; //�V�����[�̐��摜

	int Reba;//���o�[

	int C_Switch;//�F�𔽉f����X�C�b�`

	int OneTimeSwitch_ON;//��x����̃X�C�b�`ON�̉摜
	int OneTimeSwitch_OFF;//��x����̃X�C�b�`OFF�̉摜
	int Bomb;			//���e�̉摜
	int BombEffect;		//�����̉摜

	int Object_Wall;

	int Warp_Area;		//���[�v�p
	int Warp_Area2;		//���[�v�p

	int ChengObject[3];  //�ό`����I�u�W�F�N�g
	int ChengObjectmark[4]; //

	int item;	//�X�|�C�g�񕜃A�C�e��
};

int LoadPictue(void);	//�֐��̒�`
