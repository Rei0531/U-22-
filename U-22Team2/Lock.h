#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//�m�u���܂߂������ɕK�v�ȕϐ�
public:
	int color[2][3]{		//�m�u�ƌ��̌�		//0�F�m�u�@�P�`����

		{BLUE},		//�X�e�[�W�P
		{LIGHTBLUE,BLUE, RED}

	};
	int colorback[2][3]{		//�����̃o�b�N�A�b�v�o�b�N�A�b�v

		{BLUE},
		{LIGHTBLUE,BLUE, RED}


	};

	int n[2]{ 1,3 };	//�m�u�ƌ����̐�
	int Release = 0; //�����̉�����

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);