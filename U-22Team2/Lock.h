#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//�m�u���܂߂������ɕK�v�ȕϐ�
public:
	//�E��[]���X�e�[�W���A����[]���m�u�A�����̐�
	int color[7][4]{		//�m�u�ƌ��̌�		//0�F�m�u�@�P�`����

		{BLUE},							//�X�e�[�W�P
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W�Q
		{BLUE,YELLOW,PURPLE},			//�X�e�[�W�R
		{RED},							//�X�e�[�W�S
		{LIGHTBLUE},					//�X�e�[�W�T
		{RED},							//�X�e�[�W�U
		{YELLOW,BLUE,RED}				//�X�e�[�W�V

	};
	int colorback[7][4]{		//�����̃o�b�N�A�b�v�o�b�N�A�b�v

		{BLUE},							//�X�e�[�W�P
		{LIGHTBLUE,BLUE, RED},			//�X�e�[�W�Q
		{ORENGE,YELLOW,PURPLE},			//�X�e�[�W�R
		{RED},							//�X�e�[�W�S
		{LIGHTBLUE},					//�X�e�[�W�T
		{RED},							//�X�e�[�W�U
		{YELLOW,BLUE,RED}				//�X�e�[�W�V
	};
	//�X�e�[�W��/�m�u�A�����̍��v
	//	�@��	��
	int n[7]{ 1,3,3,1,1,1,3 };	//�m�u�ƌ����̐�	//�X�e�[�W���ƁA�m�u�A�����̍��v������̐��ɍ��킹��
	int Release = 0; //�����̉�����

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);