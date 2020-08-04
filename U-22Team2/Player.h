#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//�Q�[���J�n���W
	int y = 571;			//�Q�[���J�n���W
	int PickUpPixel;		//�X�|�C�g���Ă���ꏊ
	int PickUpPixely;		//�X�|�C�g���Ă���ꏊ
	int NowColor = 4;		//�f�t�H�Ŕ��F
	int Interact = 0;		//�v���C���[�̃X�|�C�g�ł����/�X�e�[�W���Ƃɒl������

	int Anime_Num = 0;//0�`3�n������A4�`8�W�����v�A10�`14�A����15�`19����

	//�����蔻��p�̐F���i�[����ϐ�
	int Hit_Up = 0,						// ___�B__
		Hit_RightUp = 0,				// �B     �B
		Hit_LeftUp = 0,					// |      |
		Hit_RightUnder = 0,				// �B     �B
		Hit_LeftUnder = 0,				// L_�B_�B_l
		Hit_Under = 0,					//�l�p�`�̂V�_�œ����蔻����擾
		Hit_Under2 = 0,					//���̓����蔻����
		Hit_Rght_High = 0,				//���̍����̉E�����蔻��
		Hit_Left_High = 0;				//���̍����̍������蔻��

	int Move_Hit1,
		Move_Hit2;					//��������{�b�N�X�̓����蔻��F���擾

	bool PLAYER_DIRECTION = FALSE,	//�v���C���[�̌���//TRUE������/FALSE�E����
		PLAYER_JUMP = FALSE,		//�v���C���[���W�����v������
		PLAYER_PICKUP = FALSE,		//�X�|�C�g
		PLAYER_ACTION = FALSE,		//�A�N�V�����{�^��
		PLAYER_MENU = FALSE,		//���j���[
		PLAYER_GROUND,				//�n�ʂɂ���
		PLAYER_RESET = FALSE,		//���Z�b�g����������
		PLAYER_MOVEBOX_PUSH = FALSE,//�����u���b�N�������Ă��邩
		PLAYER_MOVEBOX_PULL = FALSE;//�����u���b�N�������Ă��邩
}; 

int PlayerDraw(void);	//�֐��̒�`
