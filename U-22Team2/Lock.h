#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//�m�u���܂߂������ɕK�v�ȕϐ�
public:
	//�E��[]���X�e�[�W���A����[]���m�u�A�����̐�
	int color[4][3]{		//�m�u�ƌ��̌�		//0�F�m�u�@�P�`����

		{BLUE},							//�X�e�[�W�P
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W�Q
		{BLUE,YELLOW,PURPLE},			//�X�e�[�W�R
		{RED}							//�X�e�[�W�S
	};
	int colorback[4][3]{		//�����̃o�b�N�A�b�v�o�b�N�A�b�v

		{BLUE},							//�X�e�[�W�P
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W�Q
		{ORENGE,YELLOW,PURPLE},			//�X�e�[�W�R
		{RED}							//�X�e�[�W4
	};
	//�X�e�[�W��/�m�u�A�����̍��v
	//	�@��	��
	int n[4]{ 1,3,3,1 };	//�m�u�ƌ����̐�	//�X�e�[�W���ƁA�m�u�A�����̍��v������̐��ɍ��킹��
	int Release = 0; //�����̉�����

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);