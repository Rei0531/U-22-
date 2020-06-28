#pragma once
#include "LoadPic.h"

struct Player {
public:
	int x = 110;			//�Q�[���J�n���W
	int y = 581;			//�Q�[���J�n���W
	int PickUpPixel;		//�X�|�C�g���Ă���ꏊ
	int NowColor = 99;		//�f�t�H�Ŕ��F

	//�����蔻��p�̐F���i�[����ϐ�
	int Hit_Up,						// ___�B__
		Hit_RightUp,				// �B     �B
		Hit_LeftUp,					// |      |
		Hit_RightUnder,				// �B     �B
		Hit_LeftUnder,				// L__�B__l
		Hit_Under;					//�l�p�`�̂U�_�œ����蔻����擾

	bool PLAYER_DIRECTION = FALSE,	//�v���C���[�̌���//TRUE������/FALSE�E����
		PLAYER_JUMP = FALSE,		//�v���C���[���W�����v������
		PLAYER_PICKUP = FALSE,		//�X�|�C�g
		PLAYER_ACTION = FALSE,		//�A�N�V�����{�^��
		PLAYER_MENU = FALSE;		//���j���[
}; 

int PlayerDraw(void);	//�֐��̒�`
