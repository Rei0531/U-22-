#pragma once
#include "DxLib.h"
#include "Color.h"

struct LockALL {		//�m�u���܂߂������ɕK�v�ȕϐ�
public:
	int color[1][3]{		//�m�u�ƌ��̌�

		{LIGHTBLUE,BLUE, RED}		//0�F�m�u�@�P�A�Q�F����

	};
	int n[1]{ 3 };	//�m�u�ƌ����̐�
	int Release = 0; //�����̉�����

	bool
		clearflg = FALSE;

};

int Lock(void);
int UnLock(void);
int Goal(void);