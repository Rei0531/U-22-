#pragma once
#include "MoveBox.h"



struct GimmickAll {			//�M�~�b�N�ɕK�v�ȕϐ�
public:

	//�V�����[�p�̕ϐ�_______�Q�Q�Q�Q
	int shower_X;					//�����W
	int shower_Y = 670 - 256;		//�c���W�i�n�ʂ̏c���W-�摜�̏c�̑傫���j
	int shower_C;					//�F
	int shower_x;	//�h��Ԃ�����̍��W
	int shower_y;	//
	int shower_w;	//
	int shower_h;	//

	//���o�[�p�̕ϐ�_______�Q�Q�Q�Q
	int g_LeverX = 0;		//���o�[��X���W
	int g_LeverY = 0;		//���o�[��Y���W
	int g_L_BoxX1 = 0;		//���o�[�Ŕ������锠
	int g_L_BoxY1 = 0;
	int g_L_BoxX2 = 0;
	int g_L_BoxY2 = 0;

	int SwitchFlag = 0;		//���o�[��ON�AOFF
	int SwitchWait = 0;		//���o�[�̑ҋ@����
	int SwitchColor = 0;		//���o�[�̐F

	//�X���C�h���鏰�̗p�̕ϐ�_______�Q�Q�Q�Q
	int Speed = 2;
	int move_x = 0;
	int move_cnt = 0;
	int move_max = 160;
	int SliObjx1 = 0;		//�X���C�h����u���b�N�̍��W
	int SliObjx2 = 0;		//�X���C�h����u���b�N�̍��W
	int SliObjy1 = 0;		//�X���C�h����u���b�N�̍��W
	int SliObjy2 = 0;		//�X���C�h����u���b�N�̍��W
	int GetObjx1 = 0;		//�F��邽�߂̃u���b�N�̍��W
	int GetObjx2 = 0;		//�F��邽�߂̃u���b�N�̍��W
	int GetObjy1 = 0;		//�F��邽�߂̃u���b�N�̍��W
	int GetObjy2 = 0;		//�F��邽�߂̃u���b�N�̍��W
	//��x����̃X�C�b�`�p�̕ϐ�_____________
	int g_OTSwitchFlag = 0;			//��x����̃X�C�b�`��ON/OFF�t���O

	int OTS_X1 = 0;					//��x����̃X�C�b�`X/Y��
	int OTS_Y1 = 0;
	int OTS_X2 = 0;
	int OTS_Y2 = 0;
	int OTS_WallX1 = 0;				//��x����̃X�C�b�`�ŏ�����ǂ�X/Y��
	int OTS_WallY1 = 0;
	int OTS_WallX2 = 0;
	int OTS_WallY2 = 0;
	int OTS_C_WallX1 = 0;			//��x����̃X�C�b�`�ŕ\���ǂ�X/Y��
	int OTS_C_WallY1 = 0;
	int OTS_C_WallX2 = 0;
	int OTS_C_WallY2 = 0;
	//���e�p�̕ϐ�___________________________
	int g_Bombflg = 0;				//�{���̐ݒu�A�����A�g�p�t���O

	int B_EffectCount = 0;
	int B_WallX1 = 0;				//|	
	int B_WallY1 = 0;				//|--�󂹂�ǂ̍��W
	int B_WallX2 = 0;				//|
	int B_WallY2 = 0;				//|
	int BombX1 = 0;			//|
	int BombX2 = 0;			//|--�{���̍��W
	int BombY1 = 0;			//|
	int BombY2 = 0;			//|

	//�ό`�I�u�W�F�N�g�p�̕ϐ��Q�Q�Q�Q
	int cheobj_flg;	 //�ό`����I�u�W�F�N�g�̃t���O
	int cheobj_x;
	int cheobj_y = 670 - 225;
	int cheobj_c;
	int cheobj_ani = 0;
	int cheobj_zeroflg = 0;
	int cheobj_sirusi;

	//�񕜃A�C�e���p�̕ϐ�_______
	int item_x;
	int item_y = 670 - 50;
	int item_flg;

	//���[�v�p�̕ϐ�_______
	int SetNum = 0;
};

int Shower(void);		//�h��Ԃ��V�����[�̏���
int Lever(void);		//���o�[�̏���
int SlideBlock(int SlaColor);	//�������̏���
int CC_Switch(int Color, int x,int y);	//�v���C���[�̉������F�𔽉f����X�C�b�`�̏���//�����F���������_�̃v���C���[�̐F��n��
int OneTimeSwitch(void); //��x����̃X�C�b�`
int Bomb(void);			//�{�b�N�X�j��̔��e
int ChangeBlock(void); //�ό`����I�u�W�F�N�g
int kaihuku(int x, int y);	//�X�|�C�g�񕜃A�C�e��
