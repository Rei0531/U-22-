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

	//�����蔻��p�̐F���i�[����ϐ�
	int Hit_Up,						// ___�B__
		Hit_RightUp,				// �B     �B
		Hit_LeftUp,					// |      |
		Hit_RightUnder,				// �B     �B
		Hit_LeftUnder,				// L_�B_�B_l
		Hit_Under,					//�l�p�`�̂V�_�œ����蔻����擾
		Hit_Under2;					//

	int Move_Hit1,
		Move_Hit2;					//��������{�b�N�X�̓����蔻��F���擾

	bool PLAYER_DIRECTION = FALSE,	//�v���C���[�̌���//TRUE������/FALSE�E����
		PLAYER_JUMP = FALSE,		//�v���C���[���W�����v������
		PLAYER_PICKUP = FALSE,		//�X�|�C�g
		PLAYER_ACTION = FALSE,		//�A�N�V�����{�^��
		PLAYER_MENU = FALSE,		//���j���[
		PLAYER_GROUND;				//�n�ʂɂ���
}; 

int PlayerDraw(void);	//�֐��̒�`
